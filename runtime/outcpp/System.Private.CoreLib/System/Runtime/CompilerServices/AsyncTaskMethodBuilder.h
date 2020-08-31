#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
FORWARD(Exception)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS(VoidTaskResult)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(Thread)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachine)
FORWARD(IAsyncStateMachineBox)
namespace AsyncTaskMethodBuilderNamespace {
using namespace System::Threading;
using namespace System::Threading::Tasks;
template <class T1 = void, class T2 = void>
struct AsyncTaskMethodBuilder {
};
template <>
struct AsyncTaskMethodBuilder<> : public valueType<AsyncTaskMethodBuilder<>> {
  public: Task<> get_Task();
  public: Object get_ObjectIdForDebugger();
  public: static AsyncTaskMethodBuilder<> Create();
  public: template <class TStateMachine>
  void Start(TStateMachine& stateMachine);
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  private: Task<VoidTaskResult> InitializeTaskAsPromise();
  public: void SetResult();
  public: void SetException(Exception exception);
  public: void SetNotificationForWaitCompletion(Boolean enabled);
  private: Task<VoidTaskResult> m_task;
};
template <class TResult>
struct AsyncTaskMethodBuilder<TResult> : public valueType<AsyncTaskMethodBuilder<TResult>> {
  private: CLASS(AsyncStateMachineBox, TStateMachine) : public Task<TResult>::in {
    public: using interface = rt::TypeList<IAsyncStateMachineBox>;
    public: Action<> get_MoveNextAction();
    private: static void ExecutionContextCallback(Object s);
    public: void ExecuteFromThreadPool(Thread threadPoolThread);
    public: void MoveNext();
    private: void MoveNext(Thread threadPoolThread);
    public: void ctor();
    private: static void cctor();
    private: static ContextCallback s_callback;
    private: Action<> _moveNextAction;
    public: TStateMachine StateMachine;
    public: ExecutionContext Context;
  };
  private: CLASS(DebugFinalizableAsyncStateMachineBox, TStateMachine) : public AsyncStateMachineBox<TStateMachine>::in {
    protected: void Finalize();
    public: void ctor();
  };
  public: Task<TResult> get_Task();
  public: Object get_ObjectIdForDebugger();
  public: static AsyncTaskMethodBuilder<TResult> Create();
  public: template <class TStateMachine>
  void Start(TStateMachine& stateMachine);
  public: void SetStateMachine(IAsyncStateMachine stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  static void AwaitOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine, Task<TResult>& taskField);
  public: template <class TAwaiter, class TStateMachine>
  void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine);
  public: template <class TAwaiter, class TStateMachine>
  static void AwaitUnsafeOnCompleted(TAwaiter& awaiter, TStateMachine& stateMachine, Task<TResult>& taskField);
  public: template <class TAwaiter>
  static void AwaitUnsafeOnCompleted(TAwaiter& awaiter, IAsyncStateMachineBox box);
  private: template <class TStateMachine>
  static IAsyncStateMachineBox GetStateMachineBox(TStateMachine& stateMachine, Task<TResult>& taskField);
  private: template <class TStateMachine>
  static AsyncStateMachineBox<TStateMachine> CreateDebugFinalizableAsyncStateMachineBox();
  private: Task<TResult> InitializeTaskAsPromise();
  public: static Task<TResult> CreateWeaklyTypedStateMachineBox();
  public: void SetResult(TResult result);
  public: static void SetExistingTaskResult(Task<TResult> task, TResult result);
  public: void SetException(Exception exception);
  public: static void SetException(Exception exception, Task<TResult>& taskField);
  public: void SetNotificationForWaitCompletion(Boolean enabled);
  public: static void SetNotificationForWaitCompletion(Boolean enabled, Task<TResult>& taskField);
  public: static Task<TResult> GetTaskForResult(TResult result);
  private: static void cctor();
  public: static Task<TResult> s_defaultResultTask;
  private: Task<TResult> m_task;
};
} // namespace AsyncTaskMethodBuilderNamespace
template <class T1 = void, class T2 = void>
using AsyncTaskMethodBuilder = AsyncTaskMethodBuilderNamespace::AsyncTaskMethodBuilder<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
