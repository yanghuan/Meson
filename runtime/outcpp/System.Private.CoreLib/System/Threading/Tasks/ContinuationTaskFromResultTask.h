#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class InternalTaskOptions;
enum class TaskCreationOptions;
FORWARD_(Task, T1, T2)
namespace ContinuationTaskFromResultTaskNamespace {
CLASS(ContinuationTaskFromResultTask, TAntecedentResult) {
  public: void Ctor(Task<TAntecedentResult> antecedent, Delegate action, Object state, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions);
  public: void InnerInvoke();
  private: Task<TAntecedentResult> m_antecedent;
};
} // namespace ContinuationTaskFromResultTaskNamespace
template <class TAntecedentResult>
using ContinuationTaskFromResultTask = ContinuationTaskFromResultTaskNamespace::ContinuationTaskFromResultTask<TAntecedentResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
