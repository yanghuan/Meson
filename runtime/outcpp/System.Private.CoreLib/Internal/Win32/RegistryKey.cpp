#include "RegistryKey-dep.h"

#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>

namespace System::Private::CoreLib::Internal::Win32::RegistryKeyNamespace {
void RegistryKey___::ctor(SafeRegistryHandle hkey) {
}

void RegistryKey___::DeleteValue(String name, Boolean throwOnMissingValue) {
}

RegistryKey RegistryKey___::OpenBaseKey(IntPtr hKey) {
  return nullptr;
}

RegistryKey RegistryKey___::OpenSubKey(String name) {
  return nullptr;
}

RegistryKey RegistryKey___::OpenSubKey(String name, Boolean writable) {
  return nullptr;
}

Array<String> RegistryKey___::GetSubKeyNames() {
  return Array<String>();
}

Array<String> RegistryKey___::GetValueNames() {
  return Array<String>();
}

Object RegistryKey___::GetValue(String name) {
  return nullptr;
}

Object RegistryKey___::GetValue(String name, Object defaultValue) {
  return nullptr;
}

void RegistryKey___::SetValue(String name, String value) {
}

void RegistryKey___::Win32Error(Int32 errorCode, String str) {
}

} // namespace System::Private::CoreLib::Internal::Win32::RegistryKeyNamespace
