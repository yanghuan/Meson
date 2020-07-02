#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace TimeoutHelperNamespace {
class TimeoutHelper {
  public: static UInt32 GetTime();
  public: static Int32 UpdateTimeOut(UInt32 startTime, Int32 originalWaitMillisecondsTimeout);
};
} // namespace TimeoutHelperNamespace
using TimeoutHelper = TimeoutHelperNamespace::TimeoutHelper;
} // namespace System::Private::CoreLib::System::Threading
