#include "TimeoutHelper-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>

namespace System::Private::CoreLib::System::Threading::TimeoutHelperNamespace {
UInt32 TimeoutHelper::GetTime() {
  return (UInt32)Environment::get_TickCount();
}

Int32 TimeoutHelper::UpdateTimeOut(UInt32 startTime, Int32 originalWaitMillisecondsTimeout) {
  UInt32 num = GetTime() - startTime;
  if (num > Int32::MaxValue()) {
    return 0;
  }
  Int32 num2 = originalWaitMillisecondsTimeout - (Int32)num;
  if (num2 <= 0) {
    return 0;
  }
  return num2;
}

} // namespace System::Private::CoreLib::System::Threading::TimeoutHelperNamespace
