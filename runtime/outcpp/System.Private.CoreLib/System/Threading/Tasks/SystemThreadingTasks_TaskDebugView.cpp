#include "SystemThreadingTasks_TaskDebugView-dep.h"

#include <System.Private.CoreLib/System/Threading/Tasks/TaskStatus.h>

namespace System::Private::CoreLib::System::Threading::Tasks::SystemThreadingTasks_TaskDebugViewNamespace {
Object SystemThreadingTasks_TaskDebugView___::get_AsyncState() {
  return m_task->get_AsyncState();
}

TaskCreationOptions SystemThreadingTasks_TaskDebugView___::get_CreationOptions() {
  return m_task->get_CreationOptions();
}

Exception SystemThreadingTasks_TaskDebugView___::get_Exception() {
  return m_task->get_Exception();
}

Int32 SystemThreadingTasks_TaskDebugView___::get_Id() {
  return m_task->get_Id();
}

Boolean SystemThreadingTasks_TaskDebugView___::get_CancellationPending() {
  if (m_task->get_Status() == TaskStatus::WaitingToRun) {
    return m_task->get_CancellationToken().get_IsCancellationRequested();
  }
  return false;
}

TaskStatus SystemThreadingTasks_TaskDebugView___::get_Status() {
  return m_task->get_Status();
}

void SystemThreadingTasks_TaskDebugView___::ctor(Task<> task) {
  m_task = task;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::SystemThreadingTasks_TaskDebugViewNamespace
