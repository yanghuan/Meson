#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
FORWARD(ICriticalNotifyCompletion)
FORWARD(INotifyCompletion)
FORWARD(ITaskAwaiter)
namespace TaskAwaiterNamespace {
using namespace System::Threading::Tasks;
template <class ...T>
struct TaskAwaiter {
};
template <>
struct TaskAwaiter<> : public valueType<TaskAwaiter<>> {
  public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, ITaskAwaiter>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _OutputWaitEtwEvents_b__12_0(Action<> innerContinuation, Task<> innerTask);
    public: static __c __9;
    public: static Action<Action<>, Task<>> __9__12_0;
  };
  public: Boolean get_IsCompleted();
  public: explicit TaskAwaiter(Task<> task);
  public: void OnCompleted(Action<> continuation);
  public: void UnsafeOnCompleted(Action<> continuation);
  public: void GetResult();
  public: static void ValidateEnd(Task<> task);
  private: static void HandleNonSuccessAndDebuggerNotification(Task<> task);
  private: static void ThrowForNonSuccess(Task<> task);
  public: static void OnCompletedInternal(Task<> task, Action<> continuation, Boolean continueOnCapturedContext, Boolean flowExecutionContext);
  public: static void UnsafeOnCompletedInternal(Task<> task, IAsyncStateMachineBox stateMachineBox, Boolean continueOnCapturedContext);
  private: static Action<> OutputWaitEtwEvents(Task<> task, Action<> continuation);
  public: explicit TaskAwaiter() {}
  public: Task<> m_task;
};
template <class TResult>
struct TaskAwaiter<TResult> : public valueType<TaskAwaiter<TResult>> {
  public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, ITaskAwaiter>;
  public: Boolean get_IsCompleted();
  public: explicit TaskAwaiter(Task<TResult> task);
  public: void OnCompleted(Action<> continuation);
  public: void UnsafeOnCompleted(Action<> continuation);
  public: TResult GetResult();
  public: explicit TaskAwaiter() {}
  private: Task<TResult> m_task;
};
} // namespace TaskAwaiterNamespace
template <class ...T>
using TaskAwaiter = TaskAwaiterNamespace::TaskAwaiter<T...>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
