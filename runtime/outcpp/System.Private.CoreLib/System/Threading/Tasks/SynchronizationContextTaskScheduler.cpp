#include "SynchronizationContextTaskScheduler-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/SynchronizationContextTaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextTaskSchedulerNamespace {
void SynchronizationContextTaskScheduler___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void SynchronizationContextTaskScheduler___::__c___::ctor() {
}

void SynchronizationContextTaskScheduler___::__c___::_cctor_b__8_0(Object s) {
  ((Task<>)s)->ExecuteEntry();
}

Int32 SynchronizationContextTaskScheduler___::get_MaximumConcurrencyLevel() {
  return 1;
}

void SynchronizationContextTaskScheduler___::ctor() {
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  if (current == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_TaskScheduler_FromCurrentSynchronizationContext_NoCurrent());
  }
  m_synchronizationContext = current;
}

void SynchronizationContextTaskScheduler___::QueueTask(Task<> task) {
  m_synchronizationContext->Post(s_postCallback, task);
}

Boolean SynchronizationContextTaskScheduler___::TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  if (SynchronizationContext::in::get_Current() == m_synchronizationContext) {
    return TryExecuteTask(task);
  }
  return false;
}

IEnumerable<Task<>> SynchronizationContextTaskScheduler___::GetScheduledTasks() {
  return nullptr;
}

void SynchronizationContextTaskScheduler___::cctor() {
  s_postCallback = {__c::in::__9, &__c::in::_cctor_b__8_0};
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextTaskSchedulerNamespace
