#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace TimeoutNamespace {
class Timeout {
  public: static TimeSpan InfiniteTimeSpan;
  public: static constexpr Int32 Infinite = -1;
};
} // namespace TimeoutNamespace
using Timeout = TimeoutNamespace::Timeout;
} // namespace System::Private::CoreLib::System::Threading
