#include "AsyncValueTaskMethodBuilder-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskCache-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncValueTaskMethodBuilderNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Threading::Tasks;

ValueTask<> AsyncValueTaskMethodBuilder<>::get_Task() {
  if (m_task == s_syncSuccessSentinel) {
    return ValueTask();
  }
  if (AsyncTaskCache::s_valueTaskPoolingEnabled) {
    StateMachineBox stateMachineBox = Unsafe::As<StateMachineBox>(m_task);
    if (stateMachineBox == nullptr) {
      stateMachineBox = (StateMachineBox)(m_task = AsyncValueTaskMethodBuilder<VoidTaskResult>::CreateWeaklyTypedStateMachineBox());
    }
    return ValueTask(stateMachineBox, stateMachineBox->get_Version());
  }
  Task<VoidTaskResult> task = Unsafe::As<Task<VoidTaskResult>>(m_task);
  if (task == nullptr) {
    task = (Task<VoidTaskResult>)(m_task = rt::newobj<Task<VoidTaskResult>>());
  }
  return ValueTask(task);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncValueTaskMethodBuilderNamespace
