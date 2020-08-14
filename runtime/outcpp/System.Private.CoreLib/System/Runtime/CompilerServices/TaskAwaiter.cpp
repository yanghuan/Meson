#include "TaskAwaiter-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::TaskAwaiterNamespace {
Boolean TaskAwaiter<>::get_IsCompleted() {
  return m_task->get_IsCompleted();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::TaskAwaiterNamespace
