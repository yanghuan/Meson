#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(TaskScheduler)
FORWARD_(Task, T1, T2)
namespace AwaitTaskContinuationNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::CompilerServices;
CLASS(AwaitTaskContinuation) {
  public: static Boolean get_IsValidLocationForInlining();
  protected: Task<> CreateTask(Action<Object> action, Object state, TaskScheduler scheduler);
  public: void Run(Task<> task, Boolean canInlineContinuationTask);
  protected: static ContextCallback<> GetInvokeActionCallback();
  protected: void RunCallback(ContextCallback<> callback, Object state, Task<>& currentTask);
  public: static void RunOrScheduleAction(Action<> action, Boolean allowInlining);
  public: static void RunOrScheduleAction(IAsyncStateMachineBox box, Boolean allowInlining);
  public: static void UnsafeScheduleAction(Action<> action, Task<> task);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  private: ExecutionContext m_capturedContext;
  protected: Action<> m_action;
  protected: Int32 m_continuationId;
  private: static ContextCallback<> s_invokeContextCallback;
  private: static Action<Action<>> s_invokeAction;
};
} // namespace AwaitTaskContinuationNamespace
using AwaitTaskContinuation = AwaitTaskContinuationNamespace::AwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
