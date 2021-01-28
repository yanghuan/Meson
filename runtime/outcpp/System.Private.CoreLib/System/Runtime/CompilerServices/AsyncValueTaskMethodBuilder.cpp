#include "AsyncValueTaskMethodBuilder-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskCache-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncValueTaskMethodBuilderNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Threading::Tasks;

ValueTask<> AsyncValueTaskMethodBuilder<>::get_Task() {
  if (m_task == s_syncSuccessSentinel) {
    return rt::default__;
  }
  if (AsyncTaskCache::s_valueTaskPoolingEnabled) {
    StateMachineBox<> stateMachineBox = Unsafe::As<StateMachineBox<>>(m_task);
    if (stateMachineBox == nullptr) {
      stateMachineBox = (StateMachineBox<>)(m_task = AsyncValueTaskMethodBuilder<VoidTaskResult>::CreateWeaklyTypedStateMachineBox());
    }
    return ValueTask<>(stateMachineBox, stateMachineBox->get_Version());
  }
  Task<VoidTaskResult> task = Unsafe::As<Task<VoidTaskResult>>(m_task);
  if (task == nullptr) {
    task = (Task<VoidTaskResult>)(m_task = rt::newobj<Task<VoidTaskResult>>());
  }
  return ValueTask<>(task);
}

AsyncValueTaskMethodBuilder<> AsyncValueTaskMethodBuilder<>::Create() {
  return rt::default__;
}

void AsyncValueTaskMethodBuilder<>::SetStateMachine(IAsyncStateMachine stateMachine) {
  AsyncMethodBuilderCore::SetStateMachine(stateMachine, nullptr);
}

void AsyncValueTaskMethodBuilder<>::SetResult() {
  if (m_task == nullptr) {
    m_task = s_syncSuccessSentinel;
  } else if (AsyncTaskCache::s_valueTaskPoolingEnabled) {
    Unsafe::As<StateMachineBox<>>(m_task)->SetResult(rt::default__);
  } else {
    AsyncTaskMethodBuilder<VoidTaskResult>::SetExistingTaskResult(Unsafe::As<Task<VoidTaskResult>>(m_task), rt::default__);
  }

}

void AsyncValueTaskMethodBuilder<>::SetException(Exception exception) {
  if (AsyncTaskCache::s_valueTaskPoolingEnabled) {
    AsyncValueTaskMethodBuilder<VoidTaskResult>::SetException(exception, Unsafe::As<Object, StateMachineBox<>>(m_task));
  } else {
    AsyncTaskMethodBuilder<VoidTaskResult>::SetException(exception, Unsafe::As<Object, Task<VoidTaskResult>>(m_task));
  }
}

void AsyncValueTaskMethodBuilder<>::cctor() {
  s_syncSuccessSentinel = AsyncValueTaskMethodBuilder<VoidTaskResult>::s_syncSuccessSentinel;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncValueTaskMethodBuilderNamespace
