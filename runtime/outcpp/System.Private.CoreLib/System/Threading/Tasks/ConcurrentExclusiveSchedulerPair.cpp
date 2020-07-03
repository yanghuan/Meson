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
};
void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::ExecuteTask(Task<> task) {
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
};
ConcurrentExclusiveSchedulerPair::in::CompletionState ConcurrentExclusiveSchedulerPair___::EnsureCompletionStateInitialized() {
  return nullptr;
};
void ConcurrentExclusiveSchedulerPair___::RequestCompletion() {
};
void ConcurrentExclusiveSchedulerPair___::CleanupStateIfCompletingAndQuiesced() {
};
void ConcurrentExclusiveSchedulerPair___::CompleteTaskAsync() {
};
void ConcurrentExclusiveSchedulerPair___::FaultWithTask(Task<> faultedTask) {
};
void ConcurrentExclusiveSchedulerPair___::ProcessAsyncIfNecessary(Boolean fairly) {
};
Boolean ConcurrentExclusiveSchedulerPair___::TryQueueThreadPoolWorkItem(Boolean fairly) {
  return Boolean();
};
void ConcurrentExclusiveSchedulerPair___::ProcessExclusiveTasks() {
};
void ConcurrentExclusiveSchedulerPair___::ProcessConcurrentTasks() {
};
TaskCreationOptions ConcurrentExclusiveSchedulerPair___::GetCreationOptionsForTask(Boolean isReplacementReplica) {
  return TaskCreationOptions();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::ConcurrentExclusiveSchedulerPairNamespace
