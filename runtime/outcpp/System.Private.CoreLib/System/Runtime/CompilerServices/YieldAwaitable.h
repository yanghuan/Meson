#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitCallback)
FORWARD(SendOrPostCallback)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace YieldAwaitableNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
struct YieldAwaitable {
  public: struct YieldAwaiter {
    public: Boolean get_IsCompleted();
    public: void OnCompleted(Action<> continuation);
    public: void UnsafeOnCompleted(Action<> continuation);
    private: static void QueueContinuation(Action<> continuation, Boolean flowContext);
    private: static Action<> OutputCorrelationEtwEvent(Action<> continuation);
    private: static void RunAction(Object state);
    public: void GetResult();
    private: static WaitCallback s_waitCallbackRunAction;
    private: static SendOrPostCallback s_sendOrPostCallbackRunAction;
  };
  public: YieldAwaiter GetAwaiter();
};
} // namespace YieldAwaitableNamespace
using YieldAwaitable = YieldAwaitableNamespace::YieldAwaitable;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
