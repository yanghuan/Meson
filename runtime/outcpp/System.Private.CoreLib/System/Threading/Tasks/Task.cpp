#include "Task-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace {
void Task___<>::ContingentProperties___::SetCompleted() {
  return void();
};
void Task___<>::ContingentProperties___::UnregisterCancellationCallback() {
  return void();
};
Boolean Task___<>::SetOnInvokeMres___::get_InvokeMayRunArbitraryCode() {
  return Boolean();
};
void Task___<>::SetOnInvokeMres___::Invoke(Task<> completingTask) {
  return void();
};
Boolean Task___<>::SetOnCountdownMres___::get_InvokeMayRunArbitraryCode() {
  return Boolean();
};
void Task___<>::SetOnCountdownMres___::Invoke(Task<> completingTask) {
  return void();
};
void Task___<>::DelayPromise___::CompleteTimedOut() {
  return void();
};
void Task___<>::DelayPromise___::Cleanup() {
  return void();
};
void Task___<>::DelayPromiseWithCancellation___::CompleteCanceled() {
  return void();
};
void Task___<>::DelayPromiseWithCancellation___::Cleanup() {
  return void();
};
Boolean Task___<>::WhenAllPromise___::get_InvokeMayRunArbitraryCode() {
  return Boolean();
};
Boolean Task___<>::WhenAllPromise___::get_ShouldNotifyDebuggerOfWaitCompletion() {
  return Boolean();
};
Task<> Task___<>::get_ParentForDebugger() {
  return nullptr;
};
Int32 Task___<>::get_StateFlagsForDebugger() {
  return Int32();
};
String Task___<>::get_DebuggerDisplayMethodDescription() {
  return nullptr;
};
TaskCreationOptions Task___<>::get_Options() {
  return TaskCreationOptions();
};
Boolean Task___<>::get_IsWaitNotificationEnabledOrNotRanToCompletion() {
  return Boolean();
};
Boolean Task___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  return Boolean();
};
Boolean Task___<>::get_IsWaitNotificationEnabled() {
  return Boolean();
};
Int32 Task___<>::get_Id() {
  return Int32();
};
Nullable<Int32> Task___<>::get_CurrentId() {
  return Nullable<Int32>();
};
Task<> Task___<>::get_InternalCurrent() {
  return nullptr;
};
AggregateException Task___<>::get_Exception() {
  return nullptr;
};
TaskStatus Task___<>::get_Status() {
  return TaskStatus();
};
Boolean Task___<>::get_IsCanceled() {
  return Boolean();
};
Boolean Task___<>::get_IsCancellationRequested() {
  return Boolean();
};
CancellationToken Task___<>::get_CancellationToken() {
  return CancellationToken();
};
Boolean Task___<>::get_IsCancellationAcknowledged() {
  return Boolean();
};
Boolean Task___<>::get_IsCompleted() {
  return Boolean();
};
Boolean Task___<>::get_IsCompletedSuccessfully() {
  return Boolean();
};
TaskCreationOptions Task___<>::get_CreationOptions() {
  return TaskCreationOptions();
};
WaitHandle Task___<>::get_AsyncWaitHandleOfIAsyncResult() {
  return nullptr;
};
Object Task___<>::get_AsyncState() {
  return nullptr;
};
Boolean Task___<>::get_CompletedSynchronouslyOfIAsyncResult() {
  return Boolean();
};
TaskScheduler Task___<>::get_ExecutingTaskScheduler() {
  return nullptr;
};
ManualResetEventSlim Task___<>::get_CompletedEvent() {
  return nullptr;
};
Boolean Task___<>::get_ExceptionRecorded() {
  return Boolean();
};
Boolean Task___<>::get_IsFaulted() {
  return Boolean();
};
ExecutionContext Task___<>::get_CapturedContext() {
  return nullptr;
};
void Task___<>::set_CapturedContext(ExecutionContext value) {
  return void();
};
Boolean Task___<>::get_IsExceptionObservedByParent() {
  return Boolean();
};
Boolean Task___<>::get_IsDelegateInvoked() {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace