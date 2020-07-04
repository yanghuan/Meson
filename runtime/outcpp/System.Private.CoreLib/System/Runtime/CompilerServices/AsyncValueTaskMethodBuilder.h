#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Sources/ManualResetValueTaskSourceCore.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncValueTaskMethodBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
using namespace ::System::Private::CoreLib::System::Threading::Tasks::Sources;
template <class T1 = void, class T2 = void>
struct AsyncValueTaskMethodBuilder {
};
template <>
struct AsyncValueTaskMethodBuilder<> {
  public: ValueTask<> get_Task();
  private: static Object s_syncSuccessSentinel;
  private: Object m_task;
};
template <class TResult>
struct AsyncValueTaskMethodBuilder<TResult> {
  CLASS_FORWARD(StateMachineBox, T1, T2, T3)
  public: CLASS_(StateMachineBox) {
    public: Int16 get_Version();
    protected: Action<> _moveNextAction;
    public: ExecutionContext Context;
    protected: ManualResetValueTaskSourceCore<TResult> _valueTaskSource;
  };
  private: CLASS_(StateMachineBox, TStateMachine) {
    public: Action<> get_MoveNextAction();
    private: static ContextCallback<> s_callback;
    private: static Int32 s_cacheLock;
    private: static StateMachineBox<TStateMachine> s_cache;
    private: static Int32 s_cacheSize;
    private: StateMachineBox<TStateMachine> _next;
    public: TStateMachine StateMachine;
  };
  private: CLASS(SyncSuccessSentinelStateMachineBox) {
  };
  public: ValueTask<TResult> get_Task();
  public: static Object s_syncSuccessSentinel;
  private: Object m_task;
  private: TResult _result;
};
} // namespace AsyncValueTaskMethodBuilderNamespace
template <class T1 = void, class T2 = void>
using AsyncValueTaskMethodBuilder = AsyncValueTaskMethodBuilderNamespace::AsyncValueTaskMethodBuilder<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
