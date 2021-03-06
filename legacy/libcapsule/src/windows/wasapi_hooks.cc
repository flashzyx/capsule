
/*
 *  capsule - the game recording and overlay toolkit
 *  Copyright (C) 2017, Amos Wenger
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details:
 * https://github.com/itchio/capsule/blob/master/LICENSE
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "win_capture.h"

#include "../logging.h"
#include "../capture.h"
#include "../io.h"
#include "wasapi_vtable_helpers.h"

#include "../capsule/messages_generated.h"
#include "../capsule/windows/wasapi_formats.h"

// IMMDeviceEnumerator, IMMDevice
#include <mmDeviceapi.h>
// IAudioClient, IAudioCaptureClient
#include <audioclient.h>

// #define DebugLog(...) Log(__VA_ARGS__)
#define DebugLog(...)

namespace capsule {
namespace wasapi {

static struct WasapiState {
  bool seen;
  BYTE *data;
} state = {0};

void Saw(WAVEFORMATEX *pwfx) {
  if (!state.seen) {
    Log("Wasapi: saw!");
    state.seen = true;
    
    auto channels = pwfx->nChannels;
    auto rate = pwfx->nSamplesPerSec;
    auto format = ToCapsuleSampleFmt(pwfx);

    if (format == messages::SampleFmt_UNKNOWN) {
      Log("Wasapi: format isn't supported by capsule, bailing out");
    } else {
      Log("Wasapi: audio intercept ready with %d channels, %d rate and %s format",
        channels, rate, messages::EnumNameSampleFmt(format));
      capture::HasAudioIntercept(format, rate, channels);
    }
  }
}

/**
 * Release a COM resource, if it's non-null
 */
static inline void SafeRelease(IUnknown *p) {
  if (p) {
    p->Release();
  }
}

///////////////////////////////////////////////
// IAudioClient::Initialize
///////////////////////////////////////////////
typedef HRESULT (LAB_STDCALL *Initialize_t) (
  IAudioClient *client,
  AUDCLNT_SHAREMODE ShareMode,
  DWORD             StreamFlags,
  REFERENCE_TIME    hnsBufferDuration,
  REFERENCE_TIME    hnsPeriodicity,
  WAVEFORMATEX      *pFormat,
  LPCGUID           AudioSessionGuid
);
static Initialize_t Initialize_real;
static SIZE_T Initialize_hookId = 0;

HRESULT LAB_STDCALL Initialize_hook (
  IAudioClient *client,
  AUDCLNT_SHAREMODE ShareMode,
  DWORD             StreamFlags,
  REFERENCE_TIME    hnsBufferDuration,
  REFERENCE_TIME    hnsPeriodicity,
  WAVEFORMATEX      *pFormat,
  LPCGUID           AudioSessionGuid
) {
  DebugLog("Wasapi: %p hooked Initialize called", client);
  Saw(pFormat);

  auto ret = Initialize_real(
    client,
    ShareMode,
    StreamFlags,
    hnsBufferDuration,
    hnsPeriodicity,
    pFormat,
    AudioSessionGuid
   );
  return ret;
}

///////////////////////////////////////////////
// IAudioClient::GetCurrentPadding
///////////////////////////////////////////////
typedef HRESULT (LAB_STDCALL *GetCurrentPadding_t) (
  IAudioClient *client,
  UINT32 **pNumPaddingFrames
);
static GetCurrentPadding_t GetCurrentPadding_real;
static SIZE_T GetCurrentPadding_hookId = 0;

HRESULT LAB_STDCALL GetCurrentPadding_hook (
  IAudioClient *client,
  UINT32 **pNumPaddingFrames
) {
  DebugLog("Wasapi: %p hooked GetCurrentPadding called", client);
  auto ret = GetCurrentPadding_real(client, pNumPaddingFrames);
  return ret;
}

///////////////////////////////////////////////
// IAudioRenderClient::GetBuffer
///////////////////////////////////////////////
typedef HRESULT (LAB_STDCALL *GetBuffer_t) (
  IAudioRenderClient *client,
  UINT32 NumFramesRequested,
  BYTE   **ppData
);
static GetBuffer_t GetBuffer_real;
static SIZE_T GetBuffer_hookId = 0;

HRESULT LAB_STDCALL GetBuffer_hook (
  IAudioRenderClient *client,
  UINT32 NumFramesRequested,
  BYTE   **ppData
) {
  DebugLog("Wasapi: %p hooked GetBuffer called, %d frames requested", client, (int) NumFramesRequested);
  auto ret = GetBuffer_real(
    client,
    NumFramesRequested,
    ppData
  );

  if (SUCCEEDED(ret)) {
    state.data = *ppData;
  } else {
    state.data = nullptr;
  }

  return ret;
}

///////////////////////////////////////////////
// IAudioRenderClient::ReleaseBuffer
///////////////////////////////////////////////
typedef HRESULT (LAB_STDCALL *ReleaseBuffer_t) (
  IAudioRenderClient *client,
  UINT32 NumFramesWritten,
  DWORD dwFlags
);
static ReleaseBuffer_t ReleaseBuffer_real;
static SIZE_T ReleaseBuffer_hookId = 0;

HRESULT LAB_STDCALL ReleaseBuffer_hook (
  IAudioRenderClient *client,
  UINT32 NumFramesWritten,
  DWORD dwFlags
) {
  DebugLog("Wasapi: %p hooked ReleaseBuffer called, %d frames written", client, (int) NumFramesWritten);

  if (state.data) {
    if (capture::Active()) {
      io::WriteAudioFrames((char*) state.data, (size_t) NumFramesWritten);
    }
  }

  auto ret = ReleaseBuffer_real(
    client,
    NumFramesWritten,
    dwFlags
  );
  return ret;
}

///////////////////////////////////////////////
// CoCreateInstance (ole32)
///////////////////////////////////////////////
typedef HRESULT (LAB_STDCALL *CoCreateInstance_t) (
  REFCLSID  rclsid,
  LPUNKNOWN pUnkOuter,
  DWORD     dwClsContext,
  REFIID    riid,
  LPVOID    *ppv
);
static CoCreateInstance_t CoCreateInstance_real;
static SIZE_T CoCreateInstance_hookId = 0;

HRESULT LAB_STDCALL CoCreateInstance_hook (
  REFCLSID  rclsid,
  LPUNKNOWN pUnkOuter,
  DWORD     dwClsContext,
  REFIID    riid,
  LPVOID    *ppv
) {
  static bool hooking = false;

  auto guid = riid;
  Log("Wasapi: CoCreate instance called with riid {%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX}", 
    guid.Data1, guid.Data2, guid.Data3, 
    guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
    guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);

  HRESULT ret = CoCreateInstance_real(
    rclsid,
    pUnkOuter,
    dwClsContext,
    riid,
    ppv
  );

  if (hooking) {
    return ret;
  }

  if (riid == __uuidof(IMMDeviceEnumerator) && !GetBuffer_hookId) {
    hooking = true;

    Log("Found the IMMDeviceEnumerator!");

    IMMDevice *pDevice = nullptr;
    IAudioClient *pAudioClient = nullptr;
    IAudioRenderClient *pRenderClient = nullptr;
    WAVEFORMATEX *pwfx = nullptr;

    do {
      HRESULT hr;
      auto pEnumerator = reinterpret_cast<IMMDeviceEnumerator *>(*ppv);
      hr = pEnumerator->GetDefaultAudioEndpoint(
        eRender, eConsole, &pDevice
      );
      if (FAILED(hr)) {
        Log("Wasapi: GetDefaultAudioEndpoint failed");
        break;
      }

      hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr, (void**) &pAudioClient);
      if (FAILED(hr)) {
        Log("Wasapi: Activate failed");
        break;
      }

      hr = pAudioClient->GetMixFormat(&pwfx);
      if (FAILED(hr)) {
        Log("Wasapi: GetMixFormat failed");
        break;
      }

      int hnsRequestedDuration = 10000000;
      hr = pAudioClient->Initialize(
        AUDCLNT_SHAREMODE_SHARED,
        0,
        hnsRequestedDuration,
        0,
        pwfx,
        nullptr
      );
      if (FAILED(hr)) {
        Log("Wasapi: Initialize failed");
        break;
      }

      pAudioClient->GetService(
        __uuidof(IAudioRenderClient),
        (void**) &pRenderClient
      );
      if (FAILED(hr)) {
        Log("Wasapi: GetService failed");
        break;
      }

      Log("Wasapi: Installing vtable hooks...");
      void *Initialize_addr = capsule_get_IAudioClient_Initialize(pAudioClient);
      void *GetCurrentPadding_addr = capsule_get_IAudioClient_GetCurrentPadding(pAudioClient);
      void *GetBuffer_addr = capsule_get_IAudioRenderClient_GetBuffer(pRenderClient);
      void *ReleaseBuffer_addr = capsule_get_IAudioRenderClient_ReleaseBuffer(pRenderClient);

      Log("Wasapi: GetCurrentPadding address: %p", GetCurrentPadding_addr);
      Log("Wasapi: GetBuffer address: %p", GetBuffer_addr);
      Log("Wasapi: ReleaseBuffer address: %p", ReleaseBuffer_addr);

      DWORD err;

      err = cHookMgr.Hook(
        &Initialize_hookId,
        (LPVOID *) &Initialize_real,
        Initialize_addr,
        Initialize_hook
      );
      if (err != ERROR_SUCCESS) {
        Log("Hooking Initialize derped with error %d (%x)", err, err);
        break;
      }

      err = cHookMgr.Hook(
        &GetCurrentPadding_hookId,
        (LPVOID *) &GetCurrentPadding_real,
        GetCurrentPadding_addr,
        GetCurrentPadding_hook
      );
      if (err != ERROR_SUCCESS) {
        Log("Hooking GetCurrentPadding derped with error %d (%x)", err, err);
        break;
      }

      err = cHookMgr.Hook(
        &GetBuffer_hookId,
        (LPVOID *) &GetBuffer_real,
        GetBuffer_addr,
        GetBuffer_hook
      );
      if (err != ERROR_SUCCESS) {
        Log("Hooking GetBuffer derped with error %d (%x)", err, err);
        break;
      }

      err = cHookMgr.Hook(
        &ReleaseBuffer_hookId,
        (LPVOID *) &ReleaseBuffer_real,
        ReleaseBuffer_addr,
        ReleaseBuffer_hook
      );
      if (err != ERROR_SUCCESS) {
        Log("Hooking ReleaseBuffer derped with error %d (%x)", err, err);
        break;
      }
    } while(false);

    SafeRelease(pRenderClient);
    SafeRelease(pAudioClient);
    SafeRelease(pDevice);
    if (pwfx) {
      CoTaskMemFree(pwfx);
    }

    Log("Wasapi: Installed vtable hooks");
    hooking = false;
  }

  return ret;
}

void InstallHooks() {
  DWORD err;

  HMODULE ole = LoadLibrary(L"ole32.dll");
  if (!ole) {
    Log("Could not load ole32.dll, disabling Wasapi hooking");
    return;
  }

  // CoCreateInstance
  if (!CoCreateInstance_hookId) {
    LPVOID CoCreateInstance_addr = GetProcAddress(ole, "CoCreateInstance");
    if (!CoCreateInstance_addr) {
      Log("Could not find CoCreateInstance");
      return;
    }

    err = cHookMgr.Hook(
      &CoCreateInstance_hookId,
      (LPVOID *) &CoCreateInstance_real,
      CoCreateInstance_addr,
      CoCreateInstance_hook,
      0
    );
    if (err != ERROR_SUCCESS) {
      Log("Hooking CoCreateInstance derped with error %d (%x)", err, err);
      return;
    }
    Log("Installed CoCreateInstance hook");
  }
}

}
} // namespace capsule
