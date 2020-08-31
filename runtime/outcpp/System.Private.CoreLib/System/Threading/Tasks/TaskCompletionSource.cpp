#include "TaskCompletionSource-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskCompletionSourceNamespace {
using namespace System::Collections::Generic;

Task<> TaskCompletionSource___<>::get_Task() {
  return _task;
}

void TaskCompletionSource___<>::ctor() {
  _task = rt::newobj<Task<>>();
}

void TaskCompletionSource___<>::ctor(TaskCreationOptions creationOptions) {
}

void TaskCompletionSource___<>::ctor(Object state) {
}

void TaskCompletionSource___<>::ctor(Object state, TaskCreationOptions creationOptions) {
  _task = rt::newobj<Task<>>(state, creationOptions, true);
}

void TaskCompletionSource___<>::SetException(Exception exception) {
  if (!TrySetException(exception)) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::TaskT_TransitionToFinal_AlreadyCompleted);
  }
}

void TaskCompletionSource___<>::SetException(IEnumerable<Exception> exceptions) {
  if (!TrySetException(exceptions)) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::TaskT_TransitionToFinal_AlreadyCompleted);
  }
}

Boolean TaskCompletionSource___<>::TrySetException(Exception exception) {
  if (exception == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::exception);
  }
  Boolean flag = _task->TrySetException(exception);
  if (!flag && !_task->get_IsCompleted()) {
    _task->SpinUntilCompleted();
  }
  return flag;
}

Boolean TaskCompletionSource___<>::TrySetException(IEnumerable<Exception> exceptions) {
  if (exceptions == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::exceptions);
  }
  List<Exception> list = rt::newobj<List<Exception>>();
  for (Exception& exception : exceptions) {
    if (exception == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::TaskCompletionSourceT_TrySetException_NullException, ExceptionArgument::exceptions);
    }
    list->Add(exception);
  }
  if (list->get_Count() == 0) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::TaskCompletionSourceT_TrySetException_NoExceptions, ExceptionArgument::exceptions);
  }
  Boolean flag = _task->TrySetException(list);
  if (!flag && !_task->get_IsCompleted()) {
    _task->SpinUntilCompleted();
  }
  return flag;
}

void TaskCompletionSource___<>::SetResult() {
  if (!TrySetResult()) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::TaskT_TransitionToFinal_AlreadyCompleted);
  }
}

Boolean TaskCompletionSource___<>::TrySetResult() {
  Boolean flag = _task->TrySetResult();
  if (!flag) {
    _task->SpinUntilCompleted();
  }
  return flag;
}

void TaskCompletionSource___<>::SetCanceled() {
  SetCanceled(CancellationToken());
}

void TaskCompletionSource___<>::SetCanceled(CancellationToken cancellationToken) {
  if (!TrySetCanceled(cancellationToken)) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::TaskT_TransitionToFinal_AlreadyCompleted);
  }
}

Boolean TaskCompletionSource___<>::TrySetCanceled() {
  return TrySetCanceled(CancellationToken());
}

Boolean TaskCompletionSource___<>::TrySetCanceled(CancellationToken cancellationToken) {
  Boolean flag = _task->TrySetCanceled(cancellationToken);
  if (!flag && !_task->get_IsCompleted()) {
    _task->SpinUntilCompleted();
  }
  return flag;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskCompletionSourceNamespace
