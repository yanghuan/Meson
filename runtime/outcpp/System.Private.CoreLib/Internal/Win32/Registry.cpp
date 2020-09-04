#include "Registry-dep.h"

#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::Internal::Win32::RegistryNamespace {
using namespace System;

void Registry::cctor() {
  CurrentUser = RegistryKey::in::OpenBaseKey((IntPtr)(Int32)(-2147483647));
  LocalMachine = RegistryKey::in::OpenBaseKey((IntPtr)(Int32)(-2147483646));
}

} // namespace System::Private::CoreLib::Internal::Win32::RegistryNamespace
