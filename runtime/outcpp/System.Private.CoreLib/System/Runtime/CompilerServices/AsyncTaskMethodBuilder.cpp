#include "AsyncTaskMethodBuilder-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncTaskMethodBuilderNamespace {
using namespace System::Threading::Tasks;

Task<> AsyncTaskMethodBuilder<>::get_Task() {
  Task<VoidTaskResult> as = m_task;
  return as != nullptr ? as : InitializeTaskAsPromise();
}

Object AsyncTaskMethodBuilder<>::get_ObjectIdForDebugger() {
  Task<VoidTaskResult> as = m_task;
  return as != nullptr ? as : (m_task = AsyncTaskMethodBuilder<VoidTaskResult>::CreateWeaklyTypedStateMachineBox());
}

AsyncTaskMethodBuilder<> AsyncTaskMethodBuilder<>::Create() {
  return AsyncTaskMethodBuilder<>();
}

void AsyncTaskMethodBuilder<>::SetStateMachine(IAsyncStateMachine stateMachine) {
  AsyncMethodBuilderCore::SetStateMachine(stateMachine, nullptr);
}

Task<VoidTaskResult> AsyncTaskMethodBuilder<>::InitializeTaskAsPromise() {
  return m_task = rt::newobj<Task<VoidTaskResult>>();
}

void AsyncTaskMethodBuilder<>::SetResult() {
  if (m_task == nullptr) {
    m_task = Task<>::in::s_cachedCompleted;
  } else {
    AsyncTaskMethodBuilder<VoidTaskResult>::SetExistingTaskResult(m_task, VoidTaskResult());
  }
}

void AsyncTaskMethodBuilder<>::SetException(Exception exception) {
  AsyncTaskMethodBuilder<VoidTaskResult>::SetException(exception, m_task);
}

void AsyncTaskMethodBuilder<>::SetNotificationForWaitCompletion(Boolean enabled) {
  AsyncTaskMethodBuilder<VoidTaskResult>::SetNotificationForWaitCompletion(enabled, m_task);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncTaskMethodBuilderNamespace
