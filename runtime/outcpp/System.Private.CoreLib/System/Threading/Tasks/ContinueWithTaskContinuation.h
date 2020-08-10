#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/TaskContinuation.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskContinuationOptions;
FORWARD_(Task, T1, T2)
FORWARD(TaskScheduler)
namespace ContinueWithTaskContinuationNamespace {
CLASS(ContinueWithTaskContinuation) : public TaskContinuation::in {
  public: void ctor(Task<> task, TaskContinuationOptions options, TaskScheduler scheduler);
  public: void Run(Task<> completedTask, Boolean canInlineContinuationTask);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  public: Task<> m_task;
  public: TaskContinuationOptions m_options;
  private: TaskScheduler m_taskScheduler;
};
} // namespace ContinueWithTaskContinuationNamespace
using ContinueWithTaskContinuation = ContinueWithTaskContinuationNamespace::ContinueWithTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
