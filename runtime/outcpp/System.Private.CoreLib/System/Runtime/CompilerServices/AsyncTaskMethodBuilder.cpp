#include "AsyncTaskMethodBuilder-dep.h"

#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncTaskMethodBuilderNamespace {
using namespace System::Threading::Tasks;

Task<> AsyncTaskMethodBuilder<>::get_Task() {
  auto& default = m_task;
  return default != nullptr ? default : InitializeTaskAsPromise();
}

Object AsyncTaskMethodBuilder<>::get_ObjectIdForDebugger() {
  auto& default = m_task;
  return default != nullptr ? default : (m_task = AsyncTaskMethodBuilder<VoidTaskResult>::CreateWeaklyTypedStateMachineBox());
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::AsyncTaskMethodBuilderNamespace
