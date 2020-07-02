#include "TaskScheduler-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerNamespace {
Int32 TaskScheduler___::SystemThreadingTasks_TaskSchedulerDebugView___::get_Id() {
  return Int32();
};
IEnumerable<Task<>> TaskScheduler___::SystemThreadingTasks_TaskSchedulerDebugView___::get_ScheduledTasks() {
  return nullptr;
};
Int32 TaskScheduler___::get_MaximumConcurrencyLevel() {
  return Int32();
};
Boolean TaskScheduler___::get_RequiresAtomicStartTransition() {
  return Boolean();
};
TaskScheduler TaskScheduler___::get_Default() {
  return nullptr;
};
TaskScheduler TaskScheduler___::get_Current() {
  return nullptr;
};
TaskScheduler TaskScheduler___::get_InternalCurrent() {
  return nullptr;
};
Int32 TaskScheduler___::get_Id() {
  return Int32();
};
Boolean TaskScheduler___::TryRunInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  return Boolean();
};
Boolean TaskScheduler___::TryDequeue(Task<> task) {
  return Boolean();
};
void TaskScheduler___::NotifyWorkItemProgress() {
  return void();
};
void TaskScheduler___::InternalQueueTask(Task<> task) {
  return void();
};
void TaskScheduler___::AddToActiveTaskSchedulers() {
  return void();
};
TaskScheduler TaskScheduler___::FromCurrentSynchronizationContext() {
  return nullptr;
};
Boolean TaskScheduler___::TryExecuteTask(Task<> task) {
  return Boolean();
};
void TaskScheduler___::PublishUnobservedTaskException(Object sender, UnobservedTaskExceptionEventArgs ueea) {
  return void();
};
Array<Task<>> TaskScheduler___::GetScheduledTasksForDebugger() {
  return Array<Task<>>();
};
Array<TaskScheduler> TaskScheduler___::GetTaskSchedulersForDebugger() {
  return Array<TaskScheduler>();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerNamespace
