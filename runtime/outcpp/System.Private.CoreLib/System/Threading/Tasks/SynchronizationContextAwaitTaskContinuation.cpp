#include "SynchronizationContextAwaitTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/SynchronizationContextAwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextAwaitTaskContinuationNamespace {
void SynchronizationContextAwaitTaskContinuation___::ctor(SynchronizationContext context, Action<> action, Boolean flowExecutionContext) {
  m_syncContext = context;
}

void SynchronizationContextAwaitTaskContinuation___::Run(Task<> task, Boolean canInlineContinuationTask) {
  if (canInlineContinuationTask && m_syncContext == SynchronizationContext::in::get_Current()) {
    RunCallback(AwaitTaskContinuation::in::GetInvokeActionCallback(), m_action, Task<>::in::t_currentTask);
    return;
  }
  TplEventSource log = TplEventSource::in::Log;
  if (log->IsEnabled()) {
    m_continuationId = Task<>::in::NewId();
    TaskScheduler as = task->get_ExecutingTaskScheduler();
    log->AwaitTaskContinuationScheduled((as != nullptr ? as : TaskScheduler::in::get_Default())->get_Id(), task->get_Id(), m_continuationId);
  }
  RunCallback(GetPostActionCallback(), (SynchronizationContextAwaitTaskContinuation)this, Task<>::in::t_currentTask);
}

void SynchronizationContextAwaitTaskContinuation___::PostAction(Object state) {
  SynchronizationContextAwaitTaskContinuation synchronizationContextAwaitTaskContinuation = (SynchronizationContextAwaitTaskContinuation)state;
  TplEventSource log = TplEventSource::in::Log;
  if (log->TasksSetActivityIds && synchronizationContextAwaitTaskContinuation->m_continuationId != 0) {
    synchronizationContextAwaitTaskContinuation->m_syncContext->Post(s_postCallback, GetActionLogDelegate(synchronizationContextAwaitTaskContinuation->m_continuationId, synchronizationContextAwaitTaskContinuation->m_action));
  } else {
    synchronizationContextAwaitTaskContinuation->m_syncContext->Post(s_postCallback, synchronizationContextAwaitTaskContinuation->m_action);
  }
}

Action<> SynchronizationContextAwaitTaskContinuation___::GetActionLogDelegate(Int32 continuationId, Action<> action) {
}

ContextCallback<> SynchronizationContextAwaitTaskContinuation___::GetPostActionCallback() {
  return PostAction;
}

void SynchronizationContextAwaitTaskContinuation___::cctor() {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextAwaitTaskContinuationNamespace
