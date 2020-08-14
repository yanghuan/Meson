#include "ContinueWithTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ContinueWithTaskContinuationNamespace {
void ContinueWithTaskContinuation___::ctor(Task<> task, TaskContinuationOptions options, TaskScheduler scheduler) {
  m_task = task;
  m_options = options;
  m_taskScheduler = scheduler;
  _ = AsyncCausalityTracer::get_LoggingOn();
  if (Task::in::s_asyncDebuggingEnabled) {
    Task::in::AddToActiveTasks(m_task);
  }
}

void ContinueWithTaskContinuation___::Run(Task<> completedTask, Boolean canInlineContinuationTask) {
  Task task = m_task;
  m_task = nullptr;
  TaskContinuationOptions options = m_options;
}

Array<Delegate> ContinueWithTaskContinuation___::GetDelegateContinuationsForDebugger() {
  if (m_task != nullptr) {
    if ((Object)m_task->m_action != nullptr) {
      return rt::newarr<Array<Delegate>>(1);
    }
    return m_task->GetDelegateContinuationsForDebugger();
  }
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ContinueWithTaskContinuationNamespace
