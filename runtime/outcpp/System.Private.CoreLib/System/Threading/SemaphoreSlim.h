#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD(IDisposable)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
FORWARD(StrongBox, T)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading {
FORWARD(CancellationTokenSource)
FORWARD(ManualResetEvent)
FORWARD(WaitHandle)
namespace SemaphoreSlimNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks;
CLASS(SemaphoreSlim) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  private: CLASS(TaskNode) : public Task<Boolean>::in {
    public: void ctor();
    public: TaskNode Prev;
    public: TaskNode Next;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _WaitUntilCountOrTimeoutAsync_b__33_0(Object s);
    public: static __c __9;
    public: static Action<Object> __9__33_0;
  };
  private: struct _WaitUntilCountOrTimeoutAsync_d__33 : public valueType<_WaitUntilCountOrTimeoutAsync_d__33> {
    public: using interface = rt::TypeList<IAsyncStateMachine>;
    private: void MoveNext();
    private: void SetStateMachine(IAsyncStateMachine stateMachine);
    public: Int32 __1__state;
    public: AsyncTaskMethodBuilder<Boolean> __t__builder;
    public: Int32 millisecondsTimeout;
    public: CancellationToken cancellationToken;
    public: TaskNode asyncWaiter;
    public: SemaphoreSlim __4__this;
    private: CancellationTokenSource _cts_5__2;
    private: Object __7__wrap2;
    private: ConfiguredTaskAwaitable<Task<>>::ConfiguredTaskAwaiter __u__1;
    private: CancellationTokenRegistration __7__wrap3;
    private: ConfiguredTaskAwaitable<Boolean>::ConfiguredTaskAwaiter __u__2;
  };
  public: Int32 get_CurrentCount();
  public: WaitHandle get_AvailableWaitHandle();
  public: void ctor(Int32 initialCount);
  public: void ctor(Int32 initialCount, Int32 maxCount);
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
  public: static void cctor();
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
