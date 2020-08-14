#include "DriveInfoInternal-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/Win32Marshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::DriveInfoInternalNamespace {
Array<String> DriveInfoInternal::GetLogicalDrives() {
  Int32 logicalDrives = Interop::Kernel32::GetLogicalDrives();
  if (logicalDrives == 0) {
    rt::throw_exception(Win32Marshal::GetExceptionForLastWin32Error());
  }
  UInt32 num = (UInt32)logicalDrives;
  Int32 num2 = 0;
  while (num != 0) {
  }
  Array<String> array = rt::newarr<Array<String>>(num2);
  Char default[3] = {};
  Span<Char> span = default;
  num = (UInt32)logicalDrives;
  num2 = 0;
  while (num != 0) {
  }
  return array;
}

} // namespace System::Private::CoreLib::System::IO::DriveInfoInternalNamespace
