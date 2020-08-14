#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>
#include <System.Private.CoreLib/System/Threading/SpinLock.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(IDisposable)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(ExecutionContext)
FORWARD(ManualResetEvent)
FORWARD(SynchronizationContext)
FORWARD(TimerCallback)
FORWARD(TimerQueueTimer)
FORWARD(WaitHandle)
namespace CancellationTokenSourceNamespace {
using namespace System::Threading::Tasks;
CLASS(CancellationTokenSource) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: FORWARDN(CallbackPartition)
  public: CLASS(CallbackNode) : public Object::in {
    public: void ctor(CallbackPartition partition);
    public: void ExecuteCallback();
    public: CallbackPartition Partition;
    public: CallbackNode Prev;
    public: CallbackNode Next;
    public: Int64 Id;
    public: Action<Object> Callback;
    public: Object CallbackState;
    public: ExecutionContext ExecutionContext;
    public: SynchronizationContext SynchronizationContext;
  };
  private: FRIENDN(Linked1CancellationTokenSource)
  private: FRIENDN(Linked2CancellationTokenSource)
  private: FRIENDN(LinkedNCancellationTokenSource)
  public: CLASS(CallbackPartition) : public Object::in {
    public: void ctor(CancellationTokenSource source);
    public: Boolean Unregister(Int64 id, CallbackNode node);
    public: CancellationTokenSource Source;
    public: SpinLock Lock;
    public: CallbackNode Callbacks;
    public: CallbackNode FreeNodeList;
    public: Int64 NextAvailableId;
  };
  public: Boolean get_IsCancellationRequested();
  public: Boolean get_IsCancellationCompleted();
  public: Int32 get_ThreadIDExecutingCallbacks();
  public: void set_ThreadIDExecutingCallbacks(Int32 value);
  public: CancellationToken get_Token();
  public: WaitHandle get_WaitHandle();
  public: Int64 get_ExecutingCallback();
  public: void ctor();
  public: void ctor(TimeSpan delay);
  public: void ctor(Int32 millisecondsDelay);
  private: void InitializeWithTimer(Int32 millisecondsDelay);
  public: void Cancel();
  public: void Cancel(Boolean throwOnFirstException);
  public: void CancelAfter(TimeSpan delay);
  public: void CancelAfter(Int32 millisecondsDelay);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  private: void ThrowIfDisposed();
  private: static void ThrowObjectDisposedException();
  public: CancellationTokenRegistration InternalRegister(Action<Object> callback, Object stateForCallback, SynchronizationContext syncContext, ExecutionContext executionContext);
  private: void NotifyCancellation(Boolean throwOnFirstException);
  private: void ExecuteCallbackHandlers(Boolean throwOnFirstException);
  private: static Int32 GetPartitionCount();
  public: static CancellationTokenSource CreateLinkedTokenSource(CancellationToken token1, CancellationToken token2);
  public: static CancellationTokenSource CreateLinkedTokenSource(CancellationToken token);
  public: static CancellationTokenSource CreateLinkedTokenSource(Array<CancellationToken> tokens);
  public: void WaitForCallbackToComplete(Int64 id);
  public: ValueTask<> WaitForCallbackToCompleteAsync(Int64 id);
  private: static void cctor();
  public: static CancellationTokenSource s_canceledSource;
  public: static CancellationTokenSource s_neverCanceledSource;
  private: static TimerCallback s_timerCallback;
  private: static Int32 s_numPartitions;
  private: static Int32 s_numPartitionsMask;
  private: Int32 _state;
  private: Int32 _threadIDExecutingCallbacks;
  private: Int64 _executingCallbackId;
  private: Array<CallbackPartition> _callbackPartitions;
  private: TimerQueueTimer _timer;
  private: ManualResetEvent _kernelEvent;
  private: Boolean _disposed;
};
CLASS(Linked1CancellationTokenSource) : public CancellationTokenSource::in {
  public: void ctor(CancellationToken token1);
  protected: void Dispose(Boolean disposing);
  private: CancellationTokenRegistration _reg1;
};
CLASS(Linked2CancellationTokenSource) : public CancellationTokenSource::in {
  public: void ctor(CancellationToken token1, CancellationToken token2);
  protected: void Dispose(Boolean disposing);
  private: CancellationTokenRegistration _reg1;
  private: CancellationTokenRegistration _reg2;
};
CLASS(LinkedNCancellationTokenSource) : public CancellationTokenSource::in {
  public: void ctor(Array<CancellationToken> tokens);
  protected: void Dispose(Boolean disposing);
  private: static void cctor();
  public: static Action<Object> s_linkedTokenCancelDelegate;
  private: Array<CancellationTokenRegistration> _linkingRegistrations;
};
} // namespace CancellationTokenSourceNamespace
using CancellationTokenSource = CancellationTokenSourceNamespace::CancellationTokenSource;
} // namespace System::Private::CoreLib::System::Threading
