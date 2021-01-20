#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Win32::SafeHandles {
FORWARD(SafeRegistryHandle)
} // namespace System::Private::CoreLib::Internal::Win32::SafeHandles
namespace System::Private::CoreLib::Internal::Win32 {
namespace RegistryKeyNamespace {
using namespace Internal::Win32::SafeHandles;
using namespace System;
CLASS(RegistryKey) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  public: void ctor(SafeRegistryHandle hkey);
  private: void DisposeOfIDisposable();
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
