#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskContinuation.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD_(ContextCallback)
FORWARD(ExecutionContext)
FORWARD(IThreadPoolWorkItem)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD(Delegate)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(IAsyncStateMachineBox)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARD(TaskScheduler)
namespace AwaitTaskContinuationNamespace {
using namespace System::Runtime::CompilerServices;
CLASS(AwaitTaskContinuation) : public TaskContinuation::in {
  public: using interface = rt::TypeList<IThreadPoolWorkItem>;
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__17_0(Object state);
    public: void _cctor_b__17_1(Action<> action);
    public: static __c __9;
  };
  public: static Boolean get_IsValidLocationForInlining();
  public: void ctor(Action<> action, Boolean flowExecutionContext);
  protected: Task<> CreateTask(Action<Object> action, Object state, TaskScheduler scheduler);
  public: void Run(Task<> task, Boolean canInlineContinuationTask);
  private: void ExecuteOfIThreadPoolWorkItem();
  protected: static ContextCallback<> GetInvokeActionCallback();
  protected: void RunCallback(ContextCallback<> callback, Object state, Task<>& currentTask);
  public: static void RunOrScheduleAction(Action<> action, Boolean allowInlining);
  public: static void RunOrScheduleAction(IAsyncStateMachineBox box, Boolean allowInlining);
  public: static void UnsafeScheduleAction(Action<> action, Task<> task);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  public: static void cctor();
  private: ExecutionContext m_capturedContext;
  protected: Action<> m_action;
  protected: Int32 m_continuationId;
  private: static ContextCallback<> s_invokeContextCallback;
  private: static Action<Action<>> s_invokeAction;
};
} // namespace AwaitTaskContinuationNamespace
using AwaitTaskContinuation = AwaitTaskContinuationNamespace::AwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
