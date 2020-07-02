#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ContinuationTaskFromResultTaskNamespace {
CLASS(ContinuationTaskFromResultTask, TAntecedentResult) {
  public: void InnerInvoke();
  private: Task<TAntecedentResult> m_antecedent;
};
} // namespace ContinuationTaskFromResultTaskNamespace
template <class TAntecedentResult>
using ContinuationTaskFromResultTask = ContinuationTaskFromResultTaskNamespace::ContinuationTaskFromResultTask<TAntecedentResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
