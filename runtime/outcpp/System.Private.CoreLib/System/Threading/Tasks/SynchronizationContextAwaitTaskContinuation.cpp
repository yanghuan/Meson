#include "SynchronizationContextAwaitTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/SynchronizationContextAwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextAwaitTaskContinuationNamespace {
using namespace System::Diagnostics::Tracing;

void SynchronizationContextAwaitTaskContinuation___::__c__DisplayClass6_0___::ctor() {
}

void SynchronizationContextAwaitTaskContinuation___::__c__DisplayClass6_0___::_GetActionLogDelegate_b__0() {
  Guid activityId = TplEventSource::in::CreateGuidForTaskID(continuationId);
  Guid oldActivityThatWillContinue;
  EventSource::in::SetCurrentThreadActivityId(activityId, oldActivityThatWillContinue);
  try {
    action();
  } catch (...) {
  } finally: {
    EventSource::in::SetCurrentThreadActivityId(oldActivityThatWillContinue);
  }
}

void SynchronizationContextAwaitTaskContinuation___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void SynchronizationContextAwaitTaskContinuation___::__c___::ctor() {
}

void SynchronizationContextAwaitTaskContinuation___::__c___::_cctor_b__8_0(Object state) {
  ((Action<>)state)();
}

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
  __c__DisplayClass6_0 __c__DisplayClass6_ = rt::newobj<__c__DisplayClass6_0>();
  __c__DisplayClass6_->continuationId = continuationId;
  __c__DisplayClass6_->action = action;
  return {__c__DisplayClass6_, &__c__DisplayClass6_0::in::_GetActionLogDelegate_b__0};
}

ContextCallback<> SynchronizationContextAwaitTaskContinuation___::GetPostActionCallback() {
  ContextCallback<> as = s_postActionCallback;
  return as != nullptr ? as : (s_postActionCallback = &PostAction);
}

void SynchronizationContextAwaitTaskContinuation___::cctor() {
  s_postCallback = {__c::in::__9, &__c::in::_cctor_b__8_0};
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextAwaitTaskContinuationNamespace
