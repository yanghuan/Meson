#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskContinuation.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
FORWARD(IThreadPoolWorkItem)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARD(TaskScheduler)
namespace AwaitTaskContinuationNamespace {
using namespace Runtime::CompilerServices;
CLASS(AwaitTaskContinuation) : public TaskContinuation::in {
  using interface = rt::TypeList<IThreadPoolWorkItem>;
  public: static Boolean get_IsValidLocationForInlining();
  public: void Ctor(Action<> action, Boolean flowExecutionContext);
  protected: Task<> CreateTask(Action<Object> action, Object state, TaskScheduler scheduler);
  public: void Run(Task<> task, Boolean canInlineContinuationTask);
  protected: static ContextCallback<> GetInvokeActionCallback();
  protected: void RunCallback(ContextCallback<> callback, Object state, Task<>& currentTask);
  public: static void RunOrScheduleAction(Action<> action, Boolean allowInlining);
  public: static void RunOrScheduleAction(IAsyncStateMachineBox box, Boolean allowInlining);
  public: static void UnsafeScheduleAction(Action<> action, Task<> task);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  private: static void SCtor();
  private: ExecutionContext m_capturedContext;
  protected: Action<> m_action;
  protected: Int32 m_continuationId;
  private: static ContextCallback<> s_invokeContextCallback;
  private: static Action<Action<>> s_invokeAction;
};
} // namespace AwaitTaskContinuationNamespace
using AwaitTaskContinuation = AwaitTaskContinuationNamespace::AwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
