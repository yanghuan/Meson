#include "AwaitTaskContinuation-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::AwaitTaskContinuationNamespace {
Boolean AwaitTaskContinuation___::get_IsValidLocationForInlining() {
  return Boolean();
};
Task<> AwaitTaskContinuation___::CreateTask(Action<Object> action, Object state, TaskScheduler scheduler) {
  return nullptr;
};
void AwaitTaskContinuation___::Run(Task<> task, Boolean canInlineContinuationTask) {
};
ContextCallback<> AwaitTaskContinuation___::GetInvokeActionCallback() {
  return nullptr;
};
void AwaitTaskContinuation___::RunCallback(ContextCallback<> callback, Object state, Task<>& currentTask) {
};
void AwaitTaskContinuation___::RunOrScheduleAction(Action<> action, Boolean allowInlining) {
};
void AwaitTaskContinuation___::RunOrScheduleAction(IAsyncStateMachineBox box, Boolean allowInlining) {
};
void AwaitTaskContinuation___::UnsafeScheduleAction(Action<> action, Task<> task) {
};
Array<Delegate> AwaitTaskContinuation___::GetDelegateContinuationsForDebugger() {
  return Array<Delegate>();
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::AwaitTaskContinuationNamespace
