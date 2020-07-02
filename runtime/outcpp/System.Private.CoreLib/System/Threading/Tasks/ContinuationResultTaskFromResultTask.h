#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ContinuationResultTaskFromResultTaskNamespace {
CLASS(ContinuationResultTaskFromResultTask, TAntecedentResult, TResult) {
  public: void InnerInvoke();
  private: Task<TAntecedentResult> m_antecedent;
};
} // namespace ContinuationResultTaskFromResultTaskNamespace
template <class TAntecedentResult, class TResult>
using ContinuationResultTaskFromResultTask = ContinuationResultTaskFromResultTaskNamespace::ContinuationResultTaskFromResultTask<TAntecedentResult, TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
