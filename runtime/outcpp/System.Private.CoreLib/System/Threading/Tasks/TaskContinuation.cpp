#include "TaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskContinuationNamespace {
void TaskContinuation___::InlineIfPossibleOrElseQueue(Task<> task, Boolean needsProtection) {
  if (needsProtection) {
    if (!task->MarkStarted()) {
      return;
    }
  } else {
    task->m_stateFlags |= 65536;
  }
  try {
    if (!task->m_taskScheduler->TryRunInline(task, false)) {
      task->m_taskScheduler->InternalQueueTask(task);
    }
  } catch (Exception innerException) {
  }
}

void TaskContinuation___::ctor() {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskContinuationNamespace
