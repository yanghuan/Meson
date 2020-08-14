#include "SynchronizationContextTaskScheduler-dep.h"

#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextTaskSchedulerNamespace {
Int32 SynchronizationContextTaskScheduler___::get_MaximumConcurrencyLevel() {
  return 1;
}

void SynchronizationContextTaskScheduler___::ctor() {
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
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::SynchronizationContextTaskSchedulerNamespace
