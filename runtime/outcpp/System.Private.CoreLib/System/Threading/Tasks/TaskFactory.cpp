#include "TaskFactory-dep.h"

#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskFactory-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace {
Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_InvokeMayRunArbitraryCode() {
  return true;
}

Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  if (Task::in::get_ShouldNotifyDebuggerOfWaitCompletion()) {
    return Task::in::AnyTaskRequiresNotifyDebuggerOfWaitCompletion(_tasks);
  }
  return false;
}

Boolean TaskFactory___<>::CompleteOnInvokePromise___::get_InvokeMayRunArbitraryCode() {
  return (_stateFlags & 2) == 0;
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
  Int32 num = stateFlags & 2;
  if ((stateFlags & 1) != 0 || Interlocked::Exchange(_stateFlags, num | 1) != num) {
    return;
  }
  _ = AsyncCausalityTracer::get_LoggingOn();
  if (Task::in::s_asyncDebuggingEnabled) {
    Task::in::RemoveFromActiveTasks((CompleteOnInvokePromise)this);
  }
  Boolean flag = TrySetResult(completingTask);
  IList<Task> tasks = _tasks;
  Int32 count = tasks->get_Count();
  for (Int32 i = 0; i < count; i++) {
    Task task = tasks[i];
    if (task != nullptr && !task->get_IsCompleted()) {
      task->RemoveContinuation((CompleteOnInvokePromise)this);
    }
  }
  _tasks = nullptr;
}

TaskScheduler TaskFactory___<>::get_DefaultScheduler() {
  auto& default = m_defaultScheduler;
  return default != nullptr ? default : TaskScheduler::in::get_Current();
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
