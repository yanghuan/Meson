#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(SendOrPostCallback)
FORWARD(WaitCallback)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
FORWARD(ICriticalNotifyCompletion)
FORWARD(INotifyCompletion)
FORWARD(IStateMachineBoxAwareAwaiter)
namespace YieldAwaitableNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;
struct YieldAwaitable : public valueType<YieldAwaitable> {
  public: struct YieldAwaiter : public valueType<YieldAwaiter> {
    public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, IStateMachineBoxAwareAwaiter>;
    private: CLASS(__c) : public object {
      public: static void cctor();
      public: void ctor();
      public: void _SystemRuntimeCompilerServicesIStateMachineBoxAwareAwaiterAwaitUnsafeOnCompleted_b__5_0(Object s);
      public: void _SystemRuntimeCompilerServicesIStateMachineBoxAwareAwaiterAwaitUnsafeOnCompleted_b__5_1(Object s);
      public: void _OutputCorrelationEtwEvent_b__6_0(Action<> innerContinuation, Task<> continuationIdTask);
      public: static __c __9;
      public: static SendOrPostCallback __9__5_0;
      public: static Action<Object> __9__5_1;
      public: static Action<Action<>, Task<>> __9__6_0;
    };
    public: Boolean get_IsCompleted();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: static void QueueContinuation(Action<> continuation, Boolean flowContext);
    private: void AwaitUnsafeOnCompletedOfIStateMachineBoxAwareAwaiter(IAsyncStateMachineBox box);
    private: static Action<> OutputCorrelationEtwEvent(Action<> continuation);
    private: static void RunAction(Object state);
    public: void GetResult();
    public: static void cctor();
    private: static WaitCallback s_waitCallbackRunAction;
    private: static SendOrPostCallback s_sendOrPostCallbackRunAction;
  };
  public: YieldAwaiter GetAwaiter();
};
} // namespace YieldAwaitableNamespace
using YieldAwaitable = YieldAwaitableNamespace::YieldAwaitable;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
