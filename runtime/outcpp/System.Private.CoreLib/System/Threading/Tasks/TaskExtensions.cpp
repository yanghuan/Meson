#include "TaskExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskExtensionsNamespace {
Task<> TaskExtensions::Unwrap(Task<Task<>> task) {
  if (task == nullptr) {
    rt::throw_exception<ArgumentNullException>("task");
  }
  Object task2;
  if (task->get_IsCompletedSuccessfully()) {
    task2 = task->get_Result();
    if (task2 == nullptr) {
      return Task::in::FromCanceled(CancellationToken(true));
    }
  } else {
    task2 = Task::in::CreateUnwrapPromise<VoidTaskResult>(task, false);
  }
  return (Task)task2;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskExtensionsNamespace
