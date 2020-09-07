#include "TaskSchedulerAwaitTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskSchedulerAwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskSchedulerException-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerAwaitTaskContinuationNamespace {
void TaskSchedulerAwaitTaskContinuation___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void TaskSchedulerAwaitTaskContinuation___::__c___::ctor() {
}

void TaskSchedulerAwaitTaskContinuation___::__c___::_Run_b__2_0(Object state) {
  try {
    ((Action<>)state)();
  } catch (Exception exception) {
    Task<>::in::ThrowAsync(exception, nullptr);
  }
}

void TaskSchedulerAwaitTaskContinuation___::ctor(TaskScheduler scheduler, Action<> action, Boolean flowExecutionContext) {
  m_scheduler = scheduler;
}

void TaskSchedulerAwaitTaskContinuation___::Run(Task<> ignored, Boolean canInlineContinuationTask) {
  if (m_scheduler == TaskScheduler::in::get_Default()) {
    AwaitTaskContinuation::in::Run(ignored, canInlineContinuationTask);
    return;
  }
  Boolean flag = canInlineContinuationTask && (TaskScheduler::in::get_InternalCurrent() == m_scheduler || Thread::in::get_CurrentThread()->get_IsThreadPoolThread());
  Action<Object> as = __c::in::__9__2_0;
  Task<> task = CreateTask(as != nullptr ? as : (__c::in::__9__2_0 = &__c::in::__9->_Run_b__2_0), m_action, m_scheduler);
  if (flag) {
    TaskContinuation::in::InlineIfPossibleOrElseQueue(task, false);
    return;
  }
  try {
    task->ScheduleAndStart(false);
  } catch (TaskSchedulerException) {
  }
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerAwaitTaskContinuationNamespace
