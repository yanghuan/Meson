#include "ContinuationTaskFromTask-dep.h"

#include <System.Private.CoreLib/System/Action-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ContinuationTaskFromTaskNamespace {
void ContinuationTaskFromTask___::ctor(Task<> antecedent, Delegate action, Object state, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions) {
  m_antecedent = antecedent;
}

void ContinuationTaskFromTask___::InnerInvoke() {
  Task<> antecedent = m_antecedent;
  m_antecedent = nullptr;
  antecedent->NotifyDebuggerOfWaitCompletionIfNecessary();
  Action<Task<>> action = rt::as<Action<Task<>>>(m_action);
  if (action != nullptr) {
    action(antecedent);
  } else {
    auto& as = (rt::as<Action<Task<>, Object>>(m_action));
    as == nullptr ? nullptr : as->Invoke(antecedent, m_stateObject);
  }
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ContinuationTaskFromTaskNamespace
