#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/FastRandom.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(Thread)
namespace ThreadPoolWorkQueueThreadLocalsNamespace {
CLASS(ThreadPoolWorkQueueThreadLocals) : public object {
  public: void ctor(ThreadPoolWorkQueue tpq);
  protected: void Finalize();
  public: static ThreadPoolWorkQueueThreadLocals threadLocals;
  public: ThreadPoolWorkQueue workQueue;
  public: ThreadPoolWorkQueue::in::WorkStealingQueue workStealingQueue;
  public: Thread currentThread;
  public: FastRandom random;
};
} // namespace ThreadPoolWorkQueueThreadLocalsNamespace
using ThreadPoolWorkQueueThreadLocals = ThreadPoolWorkQueueThreadLocalsNamespace::ThreadPoolWorkQueueThreadLocals;
} // namespace System::Private::CoreLib::System::Threading
