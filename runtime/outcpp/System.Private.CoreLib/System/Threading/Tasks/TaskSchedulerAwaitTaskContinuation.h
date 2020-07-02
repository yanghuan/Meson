#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARD(TaskScheduler)
namespace TaskSchedulerAwaitTaskContinuationNamespace {
CLASS(TaskSchedulerAwaitTaskContinuation) {
  public: void Run(Task<> ignored, Boolean canInlineContinuationTask);
  private: TaskScheduler m_scheduler;
};
} // namespace TaskSchedulerAwaitTaskContinuationNamespace
using TaskSchedulerAwaitTaskContinuation = TaskSchedulerAwaitTaskContinuationNamespace::TaskSchedulerAwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
