#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class InternalTaskOptions;
enum class TaskCreationOptions;
namespace ContinuationTaskFromTaskNamespace {
CLASS(ContinuationTaskFromTask) : public Task<>::in {
  public: void ctor(Task<> antecedent, Delegate action, Object state, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions);
  public: void InnerInvoke();
  private: Task<> m_antecedent;
};
} // namespace ContinuationTaskFromTaskNamespace
using ContinuationTaskFromTask = ContinuationTaskFromTaskNamespace::ContinuationTaskFromTask;
} // namespace System::Private::CoreLib::System::Threading::Tasks
