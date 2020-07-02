#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ContinuationResultTaskFromTaskNamespace {
CLASS(ContinuationResultTaskFromTask, TResult) {
  public: void InnerInvoke();
  private: Task<> m_antecedent;
};
} // namespace ContinuationResultTaskFromTaskNamespace
template <class TResult>
using ContinuationResultTaskFromTask = ContinuationResultTaskFromTaskNamespace::ContinuationResultTaskFromTask<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
