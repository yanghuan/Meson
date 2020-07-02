#include "ConcurrentExclusiveSchedulerPair-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/ConcurrentExclusiveSchedulerPair-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ConcurrentExclusiveSchedulerPairNamespace {
Int32 ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::get_MaximumConcurrencyLevel() {
  return Int32();
};
IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::get_ScheduledTasks() {
  return nullptr;
};
ConcurrentExclusiveSchedulerPair ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::get_SchedulerPair() {
  return nullptr;
};
Int32 ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::get_MaximumConcurrencyLevel() {
  return Int32();
};
Int32 ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::get_CountForDebugger() {
  return Int32();
};
void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::QueueTask(Task<> task) {
  return void();
};
void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::ExecuteTask(Task<> task) {
  return void();
};
Boolean ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  return Boolean();
};
Boolean ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::TryExecuteTaskInlineOnTargetScheduler(Task<> task) {
  return Boolean();
};
Boolean ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::TryExecuteTaskShim(Object state) {
  return Boolean();
};
IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::GetScheduledTasks() {
  return nullptr;
};
ConcurrentExclusiveSchedulerPair::in::ProcessingMode ConcurrentExclusiveSchedulerPair___::DebugView___::get_Mode() {
  return ConcurrentExclusiveSchedulerPair::in::ProcessingMode();
};
IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::DebugView___::get_ScheduledExclusive() {
  return nullptr;
};
IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::DebugView___::get_ScheduledConcurrent() {
  return nullptr;
};
Int32 ConcurrentExclusiveSchedulerPair___::DebugView___::get_CurrentlyExecutingTaskCount() {
  return Int32();
};
TaskScheduler ConcurrentExclusiveSchedulerPair___::DebugView___::get_TargetScheduler() {
  return nullptr;
};
Int32 ConcurrentExclusiveSchedulerPair___::get_DefaultMaxConcurrencyLevel() {
  return Int32();
};
Object ConcurrentExclusiveSchedulerPair___::get_ValueLock() {
  return nullptr;
};
Task<> ConcurrentExclusiveSchedulerPair___::get_Completion() {
  return nullptr;
};
Boolean ConcurrentExclusiveSchedulerPair___::get_CompletionRequested() {
  return Boolean();
};
Boolean ConcurrentExclusiveSchedulerPair___::get_ReadyToComplete() {
  return Boolean();
};
TaskScheduler ConcurrentExclusiveSchedulerPair___::get_ConcurrentScheduler() {
  return nullptr;
};
TaskScheduler ConcurrentExclusiveSchedulerPair___::get_ExclusiveScheduler() {
  return nullptr;
};
Int32 ConcurrentExclusiveSchedulerPair___::get_ConcurrentTaskCountForDebugger() {
  return Int32();
};
Int32 ConcurrentExclusiveSchedulerPair___::get_ExclusiveTaskCountForDebugger() {
  return Int32();
};
ConcurrentExclusiveSchedulerPair::in::ProcessingMode ConcurrentExclusiveSchedulerPair___::get_ModeForDebugger() {
  return ConcurrentExclusiveSchedulerPair::in::ProcessingMode();
};
void ConcurrentExclusiveSchedulerPair___::Complete() {
  return void();
};
ConcurrentExclusiveSchedulerPair::in::CompletionState ConcurrentExclusiveSchedulerPair___::EnsureCompletionStateInitialized() {
  return nullptr;
};
void ConcurrentExclusiveSchedulerPair___::RequestCompletion() {
  return void();
};
void ConcurrentExclusiveSchedulerPair___::CleanupStateIfCompletingAndQuiesced() {
  return void();
};
void ConcurrentExclusiveSchedulerPair___::CompleteTaskAsync() {
  return void();
};
void ConcurrentExclusiveSchedulerPair___::FaultWithTask(Task<> faultedTask) {
  return void();
};
void ConcurrentExclusiveSchedulerPair___::ProcessAsyncIfNecessary(Boolean fairly) {
  return void();
};
Boolean ConcurrentExclusiveSchedulerPair___::TryQueueThreadPoolWorkItem(Boolean fairly) {
  return Boolean();
};
void ConcurrentExclusiveSchedulerPair___::ProcessExclusiveTasks() {
  return void();
};
void ConcurrentExclusiveSchedulerPair___::ProcessConcurrentTasks() {
  return void();
};
TaskCreationOptions ConcurrentExclusiveSchedulerPair___::GetCreationOptionsForTask(Boolean isReplacementReplica) {
  return TaskCreationOptions();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::ConcurrentExclusiveSchedulerPairNamespace
