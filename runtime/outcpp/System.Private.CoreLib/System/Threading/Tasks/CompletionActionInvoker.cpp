#include "CompletionActionInvoker-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::CompletionActionInvokerNamespace {
void CompletionActionInvoker___::ctor(ITaskCompletionAction action, Task<> completingTask) {
  m_action = action;
  m_completingTask = completingTask;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::CompletionActionInvokerNamespace
