
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#include <lab/platform.h>

#include "win_capture.h"
#include "../logging.h"

namespace capsule {
namespace process {

///////////////////////////////////////////////
// CreateProcessA
///////////////////////////////////////////////

typedef BOOL (LAB_STDCALL *CreateProcessA_t)(
  LPCSTR                lpApplicationName,
  LPSTR                 lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCSTR                lpCurrentDirectory,
  LPSTARTUPINFO         lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);
CreateProcessA_t CreateProcessA_real;
SIZE_T CreateProcessA_hookId = 0;

BOOL LAB_STDCALL CreateProcessA_hook (
  LPCSTR                lpApplicationName,
  LPSTR                 lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCSTR                lpCurrentDirectory,
  LPSTARTUPINFO         lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
) {
  Log("CreateProcessA_hook called with %s %s", lpApplicationName, lpCommandLine);
  return CreateProcessA_real(
      lpApplicationName,
      lpCommandLine,
      lpProcessAttributes,
      lpThreadAttributes,
      bInheritHandles,
      dwCreationFlags,
      lpEnvironment,
      lpCurrentDirectory,
      lpStartupInfo,
      lpProcessInformation
  );
}

///////////////////////////////////////////////
// CreateProcessW
///////////////////////////////////////////////

typedef BOOL (LAB_STDCALL *CreateProcessW_t)(
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFO         lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);
CreateProcessW_t CreateProcessW_real;
SIZE_T CreateProcessW_hookId = 0;

BOOL LAB_STDCALL CreateProcessW_hook (
  LPCWSTR               lpApplicationName,
  LPWSTR                lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCWSTR               lpCurrentDirectory,
  LPSTARTUPINFO         lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
) {
  Log("CreateProcessW_hook called with %S %S", lpApplicationName, lpCommandLine);
  
  BOOL success;
  wchar_t libcapsule_path_w[MAX_PATH];
  libcapsule_path_w[0] = '\0';

  DWORD envErr = GetEnvironmentVariableW(L"CAPSULE_LIBRARY_PATH", libcapsule_path_w, MAX_PATH);
  if (envErr != 0) {
    // Deviare uses CreateProcessW internally, so we need to temporarily disable our hook
    cHookMgr.EnableHook(CreateProcessW_hookId, FALSE);
    DWORD err = NktHookLibHelpers::CreateProcessWithDllW(
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        (LPCWSTR) lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation,
        libcapsule_path_w,     /* DLL to inject */
        NULL,                  /* signal completed */
        "capsule_windows_init" /* init function name */
    );
    cHookMgr.EnableHook(CreateProcessW_hookId, TRUE);
    success = SUCCEEDED(err) ? 1 : 0;
    Log("CreateProcessWithDllW succeeded? %d", success);
  } else {
    // environment variable was missing, just do a regular process creation
    Log("Missing CAPSULE_LIBRARY_PATH, can't inject self in child process'");
    success = CreateProcessW_real(
        lpApplicationName,
        lpCommandLine,
        lpProcessAttributes,
        lpThreadAttributes,
        bInheritHandles,
        dwCreationFlags,
        lpEnvironment,
        lpCurrentDirectory,
        lpStartupInfo,
        lpProcessInformation
    );
    Log("CreateProcessW succeeded? %d", success);
  }

  return success;
}

void InstallHooks () {
  DWORD err;

  HMODULE kernel = LoadLibrary(L"kernel32.dll");
  if (!kernel) {
    Log("Could not load kernel32.dll");
    return;
  }

  // CreateProcessA
  {
    LPVOID CreateProcessA_addr = NktHookLibHelpers::GetProcedureAddress(kernel, "CreateProcessA");
    if (!CreateProcessA_addr) {
      Log("Could not find CreateProcessA");
      return;
    }

    err = cHookMgr.Hook(
      &CreateProcessA_hookId,
      (LPVOID *) &CreateProcessA_real,
      CreateProcessA_addr,
      CreateProcessA_hook,
      0
    );
    if (err != ERROR_SUCCESS) {
      Log("Hooking CreateProcessA derped with error %d (%x)", err, err);
      return;
    }
    Log("Installed CreateProcessA hook");
  }

  // CreateProcessW
  {
    LPVOID CreateProcessW_addr = NktHookLibHelpers::GetProcedureAddress(kernel, "CreateProcessW");
    if (!CreateProcessW_addr) {
      Log("Could not find CreateProcessW");
      return;
    }

    err = cHookMgr.Hook(
      &CreateProcessW_hookId,
      (LPVOID *) &CreateProcessW_real,
      CreateProcessW_addr,
      CreateProcessW_hook,
      0
    );
    if (err != ERROR_SUCCESS) {
      Log("Hooking CreateProcessW derped with error %d (%x)", err, err);
      return;
    }
    Log("Installed CreateProcessW hook");
  }
}

} // namespace process
} // namespace capsule
