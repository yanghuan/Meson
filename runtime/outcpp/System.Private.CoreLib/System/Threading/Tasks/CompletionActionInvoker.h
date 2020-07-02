#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
FORWARD_(Task, T1, T2)
namespace CompletionActionInvokerNamespace {
CLASS(CompletionActionInvoker) {
  private: ITaskCompletionAction m_action;
  private: Task<> m_completingTask;
};
} // namespace CompletionActionInvokerNamespace
using CompletionActionInvoker = CompletionActionInvokerNamespace::CompletionActionInvoker;
} // namespace System::Private::CoreLib::System::Threading::Tasks
