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
namespace ContinuationResultTaskFromTaskNamespace {
CLASS(ContinuationResultTaskFromTask, TResult) {
  public: void Ctor(Task<> antecedent, Delegate function, Object state, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions);
  public: void InnerInvoke();
  private: Task<> m_antecedent;
};
} // namespace ContinuationResultTaskFromTaskNamespace
template <class TResult>
using ContinuationResultTaskFromTask = ContinuationResultTaskFromTaskNamespace::ContinuationResultTaskFromTask<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
