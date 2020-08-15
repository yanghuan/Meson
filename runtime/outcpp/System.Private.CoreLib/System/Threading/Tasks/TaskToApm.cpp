#include "TaskToApm-dep.h"

#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskToApm-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskToApmNamespace {
Boolean TaskToApm::TaskAsyncResult___::get_IsCompleted() {
  return _task->get_IsCompleted();
}

WaitHandle TaskToApm::TaskAsyncResult___::get_AsyncWaitHandle() {
  return ((IAsyncResult)_task)->get_AsyncWaitHandle();
}

void TaskToApm::TaskAsyncResult___::ctor(Task<> task, Object state, AsyncCallback callback) {
  _task = task;
  AsyncState = state;
  if (task->get_IsCompleted()) {
    CompletedSynchronously = true;
    auto& default = callback;
    default == nullptr ? nullptr : default->Invoke((TaskAsyncResult)this);
  } else if (callback != nullptr) {
    _callback = callback;
    _task->ConfigureAwait(false).GetAwaiter().OnCompleted(rt::newobj<Action>(&InvokeCallback));
  }

}

void TaskToApm::TaskAsyncResult___::InvokeCallback() {
  _callback((TaskAsyncResult)this);
}

IAsyncResult TaskToApm::Begin(Task<> task, AsyncCallback callback, Object state) {
  return rt::newobj<TaskAsyncResult>(task, state, callback);
}

void TaskToApm::End(IAsyncResult asyncResult) {
  TaskAsyncResult taskAsyncResult = rt::as<TaskAsyncResult>(asyncResult);
  if (taskAsyncResult != nullptr) {
    taskAsyncResult->_task->GetAwaiter().GetResult();
  } else {
    ThrowArgumentException(asyncResult);
  }
}

void TaskToApm::ThrowArgumentException(IAsyncResult asyncResult) {
  rt::throw_exception((asyncResult == nullptr) ? rt::newobj<ArgumentNullException>("asyncResult") : rt::newobj<ArgumentException>(nullptr, "asyncResult"));
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskToApmNamespace
