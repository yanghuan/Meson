#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration.h>
#include <System.Private.CoreLib/System/Threading/SpinLock.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(Array)
FORWARD(IDisposable)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(ManualResetEvent)
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
FORWARD(TimerCallback)
FORWARD(TimerQueueTimer)
FORWARD(WaitHandle)
namespace CancellationTokenSourceNamespace {
using namespace System::Threading::Tasks;
CLASS(CancellationTokenSource) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  public: FORWARDN(CallbackPartition)
  public: CLASS(CallbackNode) : public object {
    private: CLASS(__c) : public object {
      public: static void cctor();
      public: void ctor();
      public: void _ExecuteCallback_b__9_0(Object s);
      public: static __c __9;
      public: static ContextCallback __9__9_0;
    };
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
  public: CLASS(CallbackPartition) : public object {
    public: void ctor(CancellationTokenSource source);
    public: Boolean Unregister(Int64 id, CallbackNode node);
    public: CancellationTokenSource Source;
    public: SpinLock Lock;
    public: CallbackNode Callbacks;
    public: CallbackNode FreeNodeList;
    public: Int64 NextAvailableId;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _ExecuteCallbackHandlers_b__44_0(Object s);
    public: void _WaitForCallbackToCompleteAsync_b__50_0(Object s);
    public: void _cctor_b__56_0(Object obj);
    public: static __c __9;
    public: static SendOrPostCallback __9__44_0;
    public: static Action<Object> __9__50_0;
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
  public: static void cctor();
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
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__4_0(Object s);
    public: static __c __9;
  };
  public: void ctor(Array<CancellationToken> tokens);
  protected: void Dispose(Boolean disposing);
  public: static void cctor();
  public: static Action<Object> s_linkedTokenCancelDelegate;
  private: Array<CancellationTokenRegistration> _linkingRegistrations;
};
} // namespace CancellationTokenSourceNamespace
using CancellationTokenSource = CancellationTokenSourceNamespace::CancellationTokenSource;
} // namespace System::Private::CoreLib::System::Threading
