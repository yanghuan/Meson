#include "TaskCanceledException-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::TaskCanceledExceptionNamespace {
Task<> TaskCanceledException___::get_Task() {
  return _canceledTask;
}

void TaskCanceledException___::ctor() {
}

void TaskCanceledException___::ctor(String message) {
}

void TaskCanceledException___::ctor(String message, Exception innerException) {
}

void TaskCanceledException___::ctor(String message, Exception innerException, CancellationToken token) {
}

void TaskCanceledException___::ctor(Task<> task) {
  _canceledTask = task;
}

void TaskCanceledException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskCanceledExceptionNamespace
