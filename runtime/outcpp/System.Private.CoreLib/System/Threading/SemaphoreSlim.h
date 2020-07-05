#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(StrongBox, T)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(ManualResetEvent)
FORWARD(WaitHandle)
namespace SemaphoreSlimNamespace {
using namespace Runtime::CompilerServices;
using namespace Tasks;
CLASS(SemaphoreSlim) {
  private: CLASS(TaskNode) {
    public: TaskNode Prev;
    public: TaskNode Next;
  };
  public: Int32 get_CurrentCount();
  public: WaitHandle get_AvailableWaitHandle();
  public: void Wait();
  public: void Wait(CancellationToken cancellationToken);
  public: Boolean Wait(TimeSpan timeout);
  public: Boolean Wait(TimeSpan timeout, CancellationToken cancellationToken);
  public: Boolean Wait(Int32 millisecondsTimeout);
  public: Boolean Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: Boolean WaitUntilCountOrTimeout(Int32 millisecondsTimeout, UInt32 startTime, CancellationToken cancellationToken);
  public: Task<> WaitAsync();
  public: Task<> WaitAsync(CancellationToken cancellationToken);
  public: Task<Boolean> WaitAsync(Int32 millisecondsTimeout);
  public: Task<Boolean> WaitAsync(TimeSpan timeout);
  public: Task<Boolean> WaitAsync(TimeSpan timeout, CancellationToken cancellationToken);
  public: Task<Boolean> WaitAsync(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: TaskNode CreateAndAddAsyncWaiter();
  private: Boolean RemoveAsyncWaiter(TaskNode task);
  private: Task<Boolean> WaitUntilCountOrTimeoutAsync(TaskNode asyncWaiter, Int32 millisecondsTimeout, CancellationToken cancellationToken);
  public: Int32 Release();
  public: Int32 Release(Int32 releaseCount);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  private: static void CancellationTokenCanceledEventHandler(Object obj);
  private: void CheckDispose();
  private: Int32 m_currentCount;
  private: Int32 m_maxCount;
  private: Int32 m_waitCount;
  private: Int32 m_countOfWaitersPulsedToWake;
  private: StrongBox<Boolean> m_lockObjAndDisposed;
  private: ManualResetEvent m_waitHandle;
  private: TaskNode m_asyncHead;
  private: TaskNode m_asyncTail;
  private: static Task<Boolean> s_trueTask;
  private: static Task<Boolean> s_falseTask;
  private: static Action<Object> s_cancellationTokenCanceledEventHandler;
};
} // namespace SemaphoreSlimNamespace
using SemaphoreSlim = SemaphoreSlimNamespace::SemaphoreSlim;
} // namespace System::Private::CoreLib::System::Threading
