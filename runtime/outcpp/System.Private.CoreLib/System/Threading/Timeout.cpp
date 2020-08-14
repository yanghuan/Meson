#include "Timeout-dep.h"

#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::Threading::TimeoutNamespace {
void Timeout::cctor() {
  InfiniteTimeSpan = TimeSpan(0, 0, 0, 0, -1);
}

} // namespace System::Private::CoreLib::System::Threading::TimeoutNamespace
