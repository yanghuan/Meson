#include "SystemThreadingTasks_TaskDebugView-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::SystemThreadingTasks_TaskDebugViewNamespace {
Object SystemThreadingTasks_TaskDebugView___::get_AsyncState() {
  return nullptr;
}

TaskCreationOptions SystemThreadingTasks_TaskDebugView___::get_CreationOptions() {
  return TaskCreationOptions::RunContinuationsAsynchronously;
}

Exception SystemThreadingTasks_TaskDebugView___::get_Exception() {
  return nullptr;
}

Int32 SystemThreadingTasks_TaskDebugView___::get_Id() {
  return Int32();
}

Boolean SystemThreadingTasks_TaskDebugView___::get_CancellationPending() {
  return Boolean();
}

TaskStatus SystemThreadingTasks_TaskDebugView___::get_Status() {
  return TaskStatus::Faulted;
}

void SystemThreadingTasks_TaskDebugView___::ctor(Task<> task) {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::SystemThreadingTasks_TaskDebugViewNamespace
