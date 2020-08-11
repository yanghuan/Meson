#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class InternalTaskOptions : int32_t;
enum class TaskCreationOptions : int32_t;
FORWARD_(Task, T1, T2)
namespace ContinuationResultTaskFromTaskNamespace {
CLASS(ContinuationResultTaskFromTask, TResult) : public Task<TResult>::in {
  public: void ctor(Task<> antecedent, Delegate function, Object state, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions);
  public: void InnerInvoke();
  private: Task<> m_antecedent;
};
} // namespace ContinuationResultTaskFromTaskNamespace
template <class TResult>
using ContinuationResultTaskFromTask = ContinuationResultTaskFromTaskNamespace::ContinuationResultTaskFromTask<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
