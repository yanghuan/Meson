#include "RegistryKey-dep.h"

#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/Security/SecurityException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::Internal::Win32::RegistryKeyNamespace {
using namespace System;
using namespace System::Buffers;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Security;

void RegistryKey___::ctor(SafeRegistryHandle hkey) {
  _hkey = hkey;
}

void RegistryKey___::DeleteValue(String name, Boolean throwOnMissingValue) {
  Int32 num = Interop::Advapi32::RegDeleteValue(_hkey, name);
  if (num == 2 || num == 206) {
    if (throwOnMissingValue) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_RegSubKeyValueAbsent());
    }
    num = 0;
  }
}

RegistryKey RegistryKey___::OpenBaseKey(IntPtr hKey) {
  return rt::newobj<RegistryKey>(rt::newobj<SafeRegistryHandle>(hKey, false));
}

RegistryKey RegistryKey___::OpenSubKey(String name) {
  return OpenSubKey(name, false);
}

RegistryKey RegistryKey___::OpenSubKey(String name, Boolean writable) {
  SafeRegistryHandle hkResult;
  Int32 num = Interop::Advapi32::RegOpenKeyEx(_hkey, name, 0, writable ? 131103 : 131097, hkResult);
  if (num == 0 && !hkResult->get_IsInvalid()) {
    return rt::newobj<RegistryKey>(hkResult);
  }
  if (num == 5 || num == 1346) {
    rt::throw_exception<SecurityException>(SR::get_Security_RegistryPermission());
  }
  return nullptr;
}

Array<String> RegistryKey___::GetSubKeyNames() {
  List<String> list = rt::newobj<List<String>>();
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(256);
  try{
    Int32 lpcbName = array->get_Length();
    Int32 num;
    while ((num = Interop::Advapi32::RegEnumKeyEx(_hkey, list->get_Count(), array, lpcbName, nullptr, nullptr, nullptr, nullptr)) != 259) {
      if (num == 0) {
        list->Add(rt::newobj<String>(array, 0, lpcbName));
        lpcbName = array->get_Length();
      } else {
        Win32Error(num, nullptr);
      }
    }
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
  return list->ToArray();
}

Array<String> RegistryKey___::GetValueNames() {
  List<String> list = rt::newobj<List<String>>();
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(100);
  try{
    Int32 lpcbValueName = array->get_Length();
    Int32 num;
    while ((num = Interop::Advapi32::RegEnumValue(_hkey, list->get_Count(), array, lpcbValueName, IntPtr::Zero, nullptr, nullptr, nullptr)) != 259) {
      switch (num.get()) {
        case 0:
          list->Add(rt::newobj<String>(array, 0, lpcbValueName));
          break;
        case 234:
          {
            Array<Char> array2 = array;
            Int32 num2 = array2->get_Length();
            array = nullptr;
            ArrayPool<Char>::in::get_Shared()->Return(array2);
            array = ArrayPool<Char>::in::get_Shared()->Rent(num2 * 2);
            break;
          }default:
          Win32Error(num, nullptr);
          break;
      }
      lpcbValueName = array->get_Length();
    }
  } catch (...) {
  } finally: {
    if (array != nullptr) {
      ArrayPool<Char>::in::get_Shared()->Return(array);
    }
  }
  return list->ToArray();
}

Object RegistryKey___::GetValue(String name) {
  return GetValue(name, nullptr);
}

Object RegistryKey___::GetValue(String name, Object defaultValue) {
  Object result = defaultValue;
  Int32 lpType = 0;
  Int32 lpcbData = 0;
  Int32 num = Interop::Advapi32::RegQueryValueEx(_hkey, name, (Array<Int32>)nullptr, lpType, (Array<Byte>)nullptr, lpcbData);
  if (num != 0 && num != 234) {
    return result;
  }
  if (lpcbData < 0) {
    lpcbData = 0;
  }
}

void RegistryKey___::SetValue(String name, String value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (name != nullptr && name->get_Length() > 16383) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_RegValStrLenBug(), "name");
  }
  Int32 num = Interop::Advapi32::RegSetValueEx(_hkey, name, 0, 1, value, value->get_Length() * 2 + 2);
  if (num != 0) {
    Win32Error(num, nullptr);
  }
}

void RegistryKey___::Win32Error(Int32 errorCode, String str) {
  switch (errorCode.get()) {
    case 5:
      if (str != nullptr) {
        rt::throw_exception<UnauthorizedAccessException>(SR::Format(SR::get_UnauthorizedAccess_RegistryKeyGeneric_Key(), str));
      }
      rt::throw_exception<UnauthorizedAccessException>();
    case 2:
      rt::throw_exception<IOException>(SR::get_Arg_RegKeyNotFound(), errorCode);
    default:
      rt::throw_exception<IOException>(Interop::Kernel32::GetMessage(errorCode), errorCode);
  }
}

} // namespace System::Private::CoreLib::Internal::Win32::RegistryKeyNamespace
