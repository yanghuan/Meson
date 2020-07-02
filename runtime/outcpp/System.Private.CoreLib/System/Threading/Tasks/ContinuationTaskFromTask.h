#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ContinuationTaskFromTaskNamespace {
CLASS(ContinuationTaskFromTask) {
  public: void InnerInvoke();
  private: Task<> m_antecedent;
};
} // namespace ContinuationTaskFromTaskNamespace
using ContinuationTaskFromTask = ContinuationTaskFromTaskNamespace::ContinuationTaskFromTask;
} // namespace System::Private::CoreLib::System::Threading::Tasks
