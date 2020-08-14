#include "InternalGlobalizationHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::InternalGlobalizationHelperNamespace {
Int64 InternalGlobalizationHelper::TimeToTicks(Int32 hour, Int32 minute, Int32 second) {
  Int64 num = (Int64)hour * 3600 + (Int64)minute * 60 + second;
  if (num > 922337203685 || num < -922337203685) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_Overflow_TimeSpanTooLong());
  }
  return num * 10000000;
}

} // namespace System::Private::CoreLib::System::Globalization::InternalGlobalizationHelperNamespace
