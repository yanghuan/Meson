#include "TaskFactory-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskFactory-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace {
Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_InvokeMayRunArbitraryCode() {
  return true;
}

Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
}

Boolean TaskFactory___<>::CompleteOnInvokePromise___::get_InvokeMayRunArbitraryCode() {
}

void TaskFactory___<>::CompleteOnInvokePromise___::ctor(IList<Task<>> tasks, Boolean isSyncBlocking) {
  _tasks = tasks;
  if (isSyncBlocking) {
    _stateFlags = 2;
  }
  _ = AsyncCausalityTracer::get_LoggingOn();
  if (Task::in::s_asyncDebuggingEnabled) {
    Task::in::AddToActiveTasks((CompleteOnInvokePromise)this);
  }
}

void TaskFactory___<>::CompleteOnInvokePromise___::Invoke(Task<> completingTask) {
  Int32 stateFlags = _stateFlags;
}

TaskScheduler TaskFactory___<>::get_DefaultScheduler() {
}

CancellationToken TaskFactory___<>::get_CancellationToken() {
  return m_defaultCancellationToken;
}

TaskScheduler TaskFactory___<>::get_Scheduler() {
  return m_defaultScheduler;
}

TaskCreationOptions TaskFactory___<>::get_CreationOptions() {
  return m_defaultCreationOptions;
}

TaskContinuationOptions TaskFactory___<>::get_ContinuationOptions() {
  return m_defaultContinuationOptions;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace
