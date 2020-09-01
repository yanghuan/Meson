#include "ContinueWithTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/CausalityRelation.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskSchedulerException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ContinueWithTaskContinuationNamespace {
void ContinueWithTaskContinuation___::ctor(Task<> task, TaskContinuationOptions options, TaskScheduler scheduler) {
  m_task = task;
  m_options = options;
  m_taskScheduler = scheduler;
  if (TplEventSource::in::Log->IsEnabled()) {
    TplEventSource::in::Log->TraceOperationBegin(m_task->get_Id(), "Task.ContinueWith: " + task->m_action->get_Method()->get_Name(), 0);
  }
  if (Task<>::in::s_asyncDebuggingEnabled) {
    Task<>::in::AddToActiveTasks(m_task);
  }
}

void ContinueWithTaskContinuation___::Run(Task<> completedTask, Boolean canInlineContinuationTask) {
  Task<> task = m_task;
  m_task = nullptr;
  TaskContinuationOptions options = m_options;
  if (completedTask->get_IsCompletedSuccessfully() ? (Boolean)((options & TaskContinuationOptions::NotOnRanToCompletion) == 0) : (completedTask->get_IsCanceled() ? (Boolean)((options & TaskContinuationOptions::NotOnCanceled) == 0) : (Boolean)((options & TaskContinuationOptions::NotOnFaulted) == 0))) {
    if (!task->get_IsCanceled() && TplEventSource::in::Log->IsEnabled()) {
      TplEventSource::in::Log->TraceOperationRelation(task->get_Id(), CausalityRelation::AssignDelegate);
    }
    task->m_taskScheduler = m_taskScheduler;
    if (canInlineContinuationTask && (options & TaskContinuationOptions::ExecuteSynchronously) != 0) {
      TaskContinuation::in::InlineIfPossibleOrElseQueue(task, true);
      return;
    }
    try {
      task->ScheduleAndStart(true);
    } catch (TaskSchedulerException) {
    }
  } else {
    Task<>::in::ContingentProperties contingentProperties = task->m_contingentProperties;
    if (contingentProperties == nullptr || contingentProperties->m_cancellationToken == rt::default__) {
      task->InternalCancelContinueWithInitialState();
    } else {
      task->InternalCancel();
    }
  }
}

Array<Delegate> ContinueWithTaskContinuation___::GetDelegateContinuationsForDebugger() {
  if (m_task != nullptr) {
    if ((Object)m_task->m_action != nullptr) {
      return rt::newarr<Array<Delegate>>(1);
    }
    return m_task->GetDelegateContinuationsForDebugger();
  }
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ContinueWithTaskContinuationNamespace
