#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(TimeSpan)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace TimeoutNamespace {
class Timeout {
  public: static TimeSpan InfiniteTimeSpan;
  public: static Int32 Infinite;
};
} // namespace TimeoutNamespace
using Timeout = TimeoutNamespace::Timeout;
} // namespace System::Private::CoreLib::System::Threading
