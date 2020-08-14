#include "ThreadPoolTaskScheduler-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ThreadPoolTaskSchedulerNamespace {
void ThreadPoolTaskScheduler___::ctor() {
}

void ThreadPoolTaskScheduler___::QueueTask(Task<> task) {
  TaskCreationOptions options = task->get_Options();
}

Boolean ThreadPoolTaskScheduler___::TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  if (taskWasPreviouslyQueued && !ThreadPool::TryPopCustomWorkItem(task)) {
    return false;
  }
  try{
    task->ExecuteEntryUnsafe(nullptr);
  } finally: {
    if (taskWasPreviouslyQueued) {
      NotifyWorkItemProgress();
    }
  }
  return true;
}

Boolean ThreadPoolTaskScheduler___::TryDequeue(Task<> task) {
  return ThreadPool::TryPopCustomWorkItem(task);
}

IEnumerable<Task<>> ThreadPoolTaskScheduler___::GetScheduledTasks() {
  return FilterTasksFromWorkItems(ThreadPool::GetQueuedWorkItems());
}

IEnumerable<Task<>> ThreadPoolTaskScheduler___::FilterTasksFromWorkItems(IEnumerable<Object> tpwItems) {
}

void ThreadPoolTaskScheduler___::NotifyWorkItemProgress() {
  ThreadPool::NotifyWorkItemProgress();
}

void ThreadPoolTaskScheduler___::cctor() {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ThreadPoolTaskSchedulerNamespace
