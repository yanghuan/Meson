#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
FORWARD(SafeRegistryHandle)
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
namespace System::Private::CoreLib::Internal::Win32 {
namespace RegistryKeyNamespace {
using namespace ::System::Private::CoreLib::Internal::Win32::SafeHandles;
using namespace ::System::Private::CoreLib::System;
CLASS(RegistryKey) {
  public: void DeleteValue(String name, Boolean throwOnMissingValue);
  public: static RegistryKey OpenBaseKey(IntPtr hKey);
  public: RegistryKey OpenSubKey(String name);
  public: RegistryKey OpenSubKey(String name, Boolean writable);
  public: Array<String> GetSubKeyNames();
  public: Array<String> GetValueNames();
  public: Object GetValue(String name);
  public: Object GetValue(String name, Object defaultValue);
  public: void SetValue(String name, String value);
  public: static void Win32Error(Int32 errorCode, String str);
  private: SafeRegistryHandle _hkey;
};
} // namespace RegistryKeyNamespace
using RegistryKey = RegistryKeyNamespace::RegistryKey;
} // namespace System::Private::CoreLib::Internal::Win32
