#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Delegate)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
enum class TaskContinuationOptions;
FORWARD(TaskScheduler)
namespace StandardTaskContinuationNamespace {
CLASS(StandardTaskContinuation) {
  public: void Run(Task<> completedTask, Boolean canInlineContinuationTask);
  public: Array<Delegate> GetDelegateContinuationsForDebugger();
  public: Task<> m_task;
  public: TaskContinuationOptions m_options;
  private: TaskScheduler m_taskScheduler;
};
} // namespace StandardTaskContinuationNamespace
using StandardTaskContinuation = StandardTaskContinuationNamespace::StandardTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
