#include "ThreadPoolWorkQueueThreadLocals-dep.h"

#include <System.Private.CoreLib/System/Threading/FastRandom-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolWorkQueueThreadLocalsNamespace {
void ThreadPoolWorkQueueThreadLocals___::ctor(ThreadPoolWorkQueue tpq) {
  random = FastRandom(Thread::in::get_CurrentThread()->get_ManagedThreadId());
}

void ThreadPoolWorkQueueThreadLocals___::Finalize() {
  if (workStealingQueue == nullptr) {
    return;
  }
  if (workQueue != nullptr) {
    Object callback;
    while ((callback = workStealingQueue->LocalPop()) != nullptr) {
      workQueue->Enqueue(callback, true);
    }
  }
  ThreadPoolWorkQueue::in::WorkStealingQueueList::Remove(workStealingQueue);
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolWorkQueueThreadLocalsNamespace
