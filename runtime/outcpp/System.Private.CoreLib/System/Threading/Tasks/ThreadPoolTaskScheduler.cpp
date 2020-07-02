#include "ThreadPoolTaskScheduler-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::ThreadPoolTaskSchedulerNamespace {
Boolean ThreadPoolTaskScheduler___::get_RequiresAtomicStartTransition() {
  return Boolean();
};
void ThreadPoolTaskScheduler___::QueueTask(Task<> task) {
  return void();
};
Boolean ThreadPoolTaskScheduler___::TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  return Boolean();
};
Boolean ThreadPoolTaskScheduler___::TryDequeue(Task<> task) {
  return Boolean();
};
IEnumerable<Task<>> ThreadPoolTaskScheduler___::GetScheduledTasks() {
  return nullptr;
};
IEnumerable<Task<>> ThreadPoolTaskScheduler___::FilterTasksFromWorkItems(IEnumerable<Object> tpwItems) {
  return nullptr;
};
void ThreadPoolTaskScheduler___::NotifyWorkItemProgress() {
  return void();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::ThreadPoolTaskSchedulerNamespace
