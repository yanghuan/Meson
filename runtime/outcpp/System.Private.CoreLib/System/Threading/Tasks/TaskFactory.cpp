#include "TaskFactory-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace {
Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_InvokeMayRunArbitraryCode() {
  return Boolean();
}

Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  return Boolean();
}

Boolean TaskFactory___<>::CompleteOnInvokePromise___::get_InvokeMayRunArbitraryCode() {
  return Boolean();
}

void TaskFactory___<>::CompleteOnInvokePromise___::ctor(IList<Task<>> tasks, Boolean isSyncBlocking) {
}

void TaskFactory___<>::CompleteOnInvokePromise___::Invoke(Task<> completingTask) {
}

TaskScheduler TaskFactory___<>::get_DefaultScheduler() {
  return nullptr;
}

CancellationToken TaskFactory___<>::get_CancellationToken() {
  return CancellationToken();
}

TaskScheduler TaskFactory___<>::get_Scheduler() {
  return nullptr;
}

TaskCreationOptions TaskFactory___<>::get_CreationOptions() {
  return TaskCreationOptions::RunContinuationsAsynchronously;
}

TaskContinuationOptions TaskFactory___<>::get_ContinuationOptions() {
  return TaskContinuationOptions::ExecuteSynchronously;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace
