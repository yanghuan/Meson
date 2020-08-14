#include "_ThreadPoolWaitCallback-dep.h"

#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue-dep.h>

namespace System::Private::CoreLib::System::Threading::_ThreadPoolWaitCallbackNamespace {
Boolean _ThreadPoolWaitCallback::PerformWaitCallback() {
  return ThreadPoolWorkQueue::in::Dispatch();
}

} // namespace System::Private::CoreLib::System::Threading::_ThreadPoolWaitCallbackNamespace
