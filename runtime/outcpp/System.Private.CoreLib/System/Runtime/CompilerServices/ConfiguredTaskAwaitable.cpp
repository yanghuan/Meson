#include "ConfiguredTaskAwaitable-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/TaskAwaiter-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredTaskAwaitableNamespace {
Boolean ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter::get_IsCompleted() {
  return m_task->get_IsCompleted();
}

ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter::ConfiguredTaskAwaiter(Task<> task, Boolean continueOnCapturedContext) {
  m_task = task;
  m_continueOnCapturedContext = continueOnCapturedContext;
}

void ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter::OnCompleted(Action<> continuation) {
  TaskAwaiter<>::OnCompletedInternal(m_task, continuation, m_continueOnCapturedContext, true);
}

void ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter::UnsafeOnCompleted(Action<> continuation) {
  TaskAwaiter<>::OnCompletedInternal(m_task, continuation, m_continueOnCapturedContext, false);
}

void ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter::GetResult() {
  TaskAwaiter<>::ValidateEnd(m_task);
}

ConfiguredTaskAwaitable<>::ConfiguredTaskAwaitable(Task<> task, Boolean continueOnCapturedContext) {
  m_configuredTaskAwaiter = ConfiguredTaskAwaiter(task, continueOnCapturedContext);
}

ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter ConfiguredTaskAwaitable<>::GetAwaiter() {
  return m_configuredTaskAwaiter;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredTaskAwaitableNamespace
