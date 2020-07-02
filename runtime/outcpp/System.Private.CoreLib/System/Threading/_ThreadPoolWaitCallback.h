#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace _ThreadPoolWaitCallbackNamespace {
class _ThreadPoolWaitCallback {
  public: static Boolean PerformWaitCallback();
};
} // namespace _ThreadPoolWaitCallbackNamespace
using _ThreadPoolWaitCallback = _ThreadPoolWaitCallbackNamespace::_ThreadPoolWaitCallback;
} // namespace System::Private::CoreLib::System::Threading
