#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AwaitTaskContinuation.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARD(TaskScheduler)
namespace TaskSchedulerAwaitTaskContinuationNamespace {
CLASS(TaskSchedulerAwaitTaskContinuation) : public AwaitTaskContinuation::in {
  public: void Ctor(TaskScheduler scheduler, Action<> action, Boolean flowExecutionContext);
  public: void Run(Task<> ignored, Boolean canInlineContinuationTask);
  private: TaskScheduler m_scheduler;
};
} // namespace TaskSchedulerAwaitTaskContinuationNamespace
using TaskSchedulerAwaitTaskContinuation = TaskSchedulerAwaitTaskContinuationNamespace::TaskSchedulerAwaitTaskContinuation;
} // namespace System::Private::CoreLib::System::Threading::Tasks
