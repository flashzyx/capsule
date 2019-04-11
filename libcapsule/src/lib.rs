#![allow(non_upper_case_globals, non_snake_case)]

#[macro_use]
extern crate cstr_macro;
#[macro_use]
extern crate ctor;
#[macro_use]
extern crate lazy_static;
#[macro_use]
extern crate libc_print;
extern crate detour;

use libc::c_char;

#[macro_use]
mod hook;
mod gl;
mod linux_gl_hooks;
use detour::RawDetour;

#[cfg(target_os = "macos")]
static CURRENT_PLATFORM: &str = "macOS";
#[cfg(target_os = "linux")]
static CURRENT_PLATFORM: &str = "Linux";
#[cfg(target_os = "windows")]
static CURRENT_PLATFORM: &str = "Windows";

#[ctor]
fn ctor() {
    match std::env::var("CAPSULE_TEST") {
        Ok(_) => {
            lazy_static::initialize(&puts__hook);
        }
        Err(_) => {
            libc_println!("thanks for flying capsule on {}", CURRENT_PLATFORM);
            #[cfg(target_os = "linux")]
            {
                linux_gl_hooks::initialize()
            }
        }
    }
}

hook_extern! {
    fn puts(ptr: *const c_char) -> () {
        if ptr == 0xDEADBEEF as *const c_char {
            libc_println!("caught dead beef");
            return;
        }
        puts__next(ptr)
    }
}