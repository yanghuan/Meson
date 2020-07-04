#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>
#include <System.Private.CoreLib/System/Threading/SpinLock.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARD(Object)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
FORWARD(SynchronizationContext)
FORWARDS(CancellationToken)
FORWARD(WaitHandle)
FORWARD(TimerCallback)
FORWARD(TimerQueueTimer)
FORWARD(ManualResetEvent)
namespace CancellationTokenSourceNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(CancellationTokenSource) {
  public: FORWARDN(CallbackPartition)
  public: CLASS(CallbackNode) {
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
  private: CLASS(Linked1CancellationTokenSource) {
    protected: void Dispose(Boolean disposing);
    private: CancellationTokenRegistration _reg1;
  };
  private: CLASS(Linked2CancellationTokenSource) {
    protected: void Dispose(Boolean disposing);
    private: CancellationTokenRegistration _reg1;
    private: CancellationTokenRegistration _reg2;
  };
  private: CLASS(LinkedNCancellationTokenSource) {
    protected: void Dispose(Boolean disposing);
    public: static Action<Object> s_linkedTokenCancelDelegate;
    private: Array<CancellationTokenRegistration> _linkingRegistrations;
  };
  public: CLASS(CallbackPartition) {
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
} // namespace CancellationTokenSourceNamespace
using CancellationTokenSource = CancellationTokenSourceNamespace::CancellationTokenSource;
} // namespace System::Private::CoreLib::System::Threading
