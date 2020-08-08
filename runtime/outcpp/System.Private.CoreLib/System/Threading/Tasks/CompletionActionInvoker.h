#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(IThreadPoolWorkItem)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
FORWARD_(Task, T1, T2)
namespace CompletionActionInvokerNamespace {
CLASS(CompletionActionInvoker) : public Object::in {
  using interface = rt::TypeList<IThreadPoolWorkItem>;
  public: void Ctor(ITaskCompletionAction action, Task<> completingTask);
  private: ITaskCompletionAction m_action;
  private: Task<> m_completingTask;
};
} // namespace CompletionActionInvokerNamespace
using CompletionActionInvoker = CompletionActionInvokerNamespace::CompletionActionInvoker;
} // namespace System::Private::CoreLib::System::Threading::Tasks
