#include "TaskSchedulerAwaitTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerAwaitTaskContinuationNamespace {
void TaskSchedulerAwaitTaskContinuation___::ctor(TaskScheduler scheduler, Action<> action, Boolean flowExecutionContext) {
  m_scheduler = scheduler;
}

void TaskSchedulerAwaitTaskContinuation___::Run(Task<> ignored, Boolean canInlineContinuationTask) {
  if (m_scheduler == TaskScheduler::in::get_Default()) {
  }
  Boolean flag = canInlineContinuationTask && (TaskScheduler::in::get_InternalCurrent() == m_scheduler || Thread::in::get_CurrentThread()->get_IsThreadPoolThread());
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerAwaitTaskContinuationNamespace
