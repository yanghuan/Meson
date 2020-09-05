#pragma once

#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace TimeoutNamespace {
class Timeout {
  public: static void cctor();
  public: static TimeSpan InfiniteTimeSpan;
  public: static constexpr Int32 Infinite = -1;
};
} // namespace TimeoutNamespace
using Timeout = TimeoutNamespace::Timeout;
} // namespace System::Private::CoreLib::System::Threading
