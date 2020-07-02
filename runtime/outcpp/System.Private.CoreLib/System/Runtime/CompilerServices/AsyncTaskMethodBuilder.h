#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(Thread)
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace AsyncTaskMethodBuilderNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
template <class T1 = void, class T2 = void>
struct AsyncTaskMethodBuilder {
};
template <>
struct AsyncTaskMethodBuilder<> {
  public: Task<> get_Task();
  public: Object get_ObjectIdForDebugger();
  private: static Task<VoidTaskResult> s_cachedCompleted;
  private: AsyncTaskMethodBuilder<VoidTaskResult> m_builder;
};
template <class TResult>
struct AsyncTaskMethodBuilder<TResult> {
  private: CLASS(DebugFinalizableAsyncStateMachineBox, TStateMachine) {
    protected: void Finalize();
  };
  private: CLASS(AsyncStateMachineBox, TStateMachine) {
    public: Action<> get_MoveNextAction();
    private: static void ExecutionContextCallback(Object s);
    public: void ExecuteFromThreadPool(Thread threadPoolThread);
    public: void MoveNext();
    private: void MoveNext(Thread threadPoolThread);
    private: static ContextCallback<> s_callback;
    private: Action<> _moveNextAction;
    public: TStateMachine StateMachine;
    public: ExecutionContext Context;
  };
  public: Task<TResult> get_Task();
  public: Object get_ObjectIdForDebugger();
  public: static Task<TResult> s_defaultResultTask;
  private: Task<TResult> m_task;
};
} // namespace AsyncTaskMethodBuilderNamespace
template <class T1 = void, class T2 = void>
using AsyncTaskMethodBuilder = AsyncTaskMethodBuilderNamespace::AsyncTaskMethodBuilder<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
