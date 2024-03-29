#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/Task.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class InternalTaskOptions : int32_t;
enum class TaskCreationOptions : int32_t;
namespace ContinuationResultTaskFromResultTaskNamespace {
CLASS(ContinuationResultTaskFromResultTask, TAntecedentResult, TResult) : public Task<TResult>::in {
  public: void ctor(Task<TAntecedentResult> antecedent, Delegate function, Object state, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions);
  public: void InnerInvoke();
  private: Task<TAntecedentResult> m_antecedent;
};
} // namespace ContinuationResultTaskFromResultTaskNamespace
template <class TAntecedentResult, class TResult>
using ContinuationResultTaskFromResultTask = ContinuationResultTaskFromResultTaskNamespace::ContinuationResultTaskFromResultTask<TAntecedentResult, TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
