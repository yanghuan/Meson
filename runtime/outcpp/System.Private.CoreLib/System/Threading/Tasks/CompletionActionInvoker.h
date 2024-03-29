#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(IThreadPoolWorkItem)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD(ITaskCompletionAction)
FORWARD_(Task)
namespace CompletionActionInvokerNamespace {
CLASS(CompletionActionInvoker) : public object {
  public: using interface = rt::TypeList<IThreadPoolWorkItem>;
  public: void ctor(ITaskCompletionAction action, Task<> completingTask);
  private: void ExecuteOfIThreadPoolWorkItem();
  private: ITaskCompletionAction m_action;
  private: Task<> m_completingTask;
};
} // namespace CompletionActionInvokerNamespace
using CompletionActionInvoker = CompletionActionInvokerNamespace::CompletionActionInvoker;
} // namespace System::Private::CoreLib::System::Threading::Tasks
