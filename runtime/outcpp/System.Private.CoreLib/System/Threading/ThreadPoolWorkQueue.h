#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Internal/PaddingFor32.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Threading/SpinLock.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Array, T1, T2)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Concurrent {
FORWARD(ConcurrentQueue, T)
} // namespace System::Private::CoreLib::System::Collections::Concurrent
namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadPoolWorkQueueThreadLocals)
namespace ThreadPoolWorkQueueNamespace {
using namespace ::System::Private::CoreLib::Internal;
using namespace ::System::Private::CoreLib::System::Collections::Concurrent;
CLASS(ThreadPoolWorkQueue) {
  public: CLASS(WorkStealingQueue) {
    public: Boolean get_CanSteal();
    public: Int32 get_Count();
    public: void LocalPush(Object obj);
    public: Boolean LocalFindAndPop(Object obj);
    public: Object LocalPop();
    private: Object LocalPopCore();
    public: Object TrySteal(Boolean& missedSteal);
    public: Array<Object> m_array;
    private: Int32 m_mask;
    private: Int32 m_headIndex;
    private: Int32 m_tailIndex;
    private: SpinLock m_foreignLock;
  };
  public: class WorkStealingQueueList {
    public: static Array<WorkStealingQueue> get_Queues();
    public: static void Add(WorkStealingQueue queue);
    public: static void Remove(WorkStealingQueue queue);
    private: static Array<WorkStealingQueue> _queues;
  };
  public: Int64 get_LocalCount();
  public: Int64 get_GlobalCount();
  public: ThreadPoolWorkQueueThreadLocals GetOrCreateThreadLocals();
  private: ThreadPoolWorkQueueThreadLocals CreateThreadLocals();
  public: void EnsureThreadRequested();
  public: void MarkThreadRequestSatisfied();
  public: void Enqueue(Object callback, Boolean forceGlobal);
  public: Boolean LocalFindAndPop(Object callback);
  public: Object Dequeue(ThreadPoolWorkQueueThreadLocals tl, Boolean& missedSteal);
  public: static Boolean Dispatch();
  public: Boolean loggingEnabled;
  public: ConcurrentQueue<Object> workItems;
  private: PaddingFor32 pad1;
  private: Int32 numOutstandingThreadRequests;
  private: PaddingFor32 pad2;
};
} // namespace ThreadPoolWorkQueueNamespace
using ThreadPoolWorkQueue = ThreadPoolWorkQueueNamespace::ThreadPoolWorkQueue;
} // namespace System::Private::CoreLib::System::Threading
