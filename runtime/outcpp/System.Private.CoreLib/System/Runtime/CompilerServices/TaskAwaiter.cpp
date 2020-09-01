#include "TaskAwaiter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/ObjectModel/ReadOnlyCollection-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCanceledException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::TaskAwaiterNamespace {
using namespace System::Collections::ObjectModel;
using namespace System::Runtime::ExceptionServices;
using namespace System::Threading::Tasks;

Boolean TaskAwaiter<>::get_IsCompleted() {
  return m_task->get_IsCompleted();
}

TaskAwaiter<>::TaskAwaiter(Task<> task) {
  m_task = task;
}

void TaskAwaiter<>::OnCompleted(Action<> continuation) {
  OnCompletedInternal(m_task, continuation, true, true);
}

void TaskAwaiter<>::UnsafeOnCompleted(Action<> continuation) {
  OnCompletedInternal(m_task, continuation, true, false);
}

void TaskAwaiter<>::GetResult() {
  ValidateEnd(m_task);
}

void TaskAwaiter<>::ValidateEnd(Task<> task) {
  if (task->get_IsWaitNotificationEnabledOrNotRanToCompletion()) {
    HandleNonSuccessAndDebuggerNotification(task);
  }
}

void TaskAwaiter<>::HandleNonSuccessAndDebuggerNotification(Task<> task) {
  if (!task->get_IsCompleted()) {
    Boolean flag = task->InternalWait(-1, rt::default__);
  }
  task->NotifyDebuggerOfWaitCompletionIfNecessary();
  if (!task->get_IsCompletedSuccessfully()) {
    ThrowForNonSuccess(task);
  }
}

void TaskAwaiter<>::ThrowForNonSuccess(Task<> task) {
  switch (task->get_Status()) {
    case TaskStatus::Canceled:
      {
        ExceptionDispatchInfo cancellationExceptionDispatchInfo = task->GetCancellationExceptionDispatchInfo();
        if (cancellationExceptionDispatchInfo != nullptr) {
          cancellationExceptionDispatchInfo->Throw();
        }
        rt::throw_exception<TaskCanceledException>(task);
      }case TaskStatus::Faulted:
      {
        ReadOnlyCollection<ExceptionDispatchInfo> exceptionDispatchInfos = task->GetExceptionDispatchInfos();
        if (exceptionDispatchInfos->get_Count() > 0) {
          exceptionDispatchInfos[0]->Throw();
          break;
        }
        rt::throw_exception(task->get_Exception());
      }}
}

void TaskAwaiter<>::OnCompletedInternal(Task<> task, Action<> continuation, Boolean continueOnCapturedContext, Boolean flowExecutionContext) {
  if (continuation == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuation");
  }
  if (TplEventSource::in::Log->IsEnabled() || Task<>::in::s_asyncDebuggingEnabled) {
    continuation = OutputWaitEtwEvents(task, continuation);
  }
  task->SetContinuationForAwait(continuation, continueOnCapturedContext, flowExecutionContext);
}

void TaskAwaiter<>::UnsafeOnCompletedInternal(Task<> task, IAsyncStateMachineBox stateMachineBox, Boolean continueOnCapturedContext) {
  if (TplEventSource::in::Log->IsEnabled() || Task<>::in::s_asyncDebuggingEnabled) {
    task->SetContinuationForAwait(OutputWaitEtwEvents(task, stateMachineBox->get_MoveNextAction()), continueOnCapturedContext, false);
  } else {
    task->UnsafeSetContinuationForAwait(stateMachineBox, continueOnCapturedContext);
  }
}

Action<> TaskAwaiter<>::OutputWaitEtwEvents(Task<> task, Action<> continuation) {
  if (Task<>::in::s_asyncDebuggingEnabled) {
    Task<>::in::AddToActiveTasks(task);
  }
  TplEventSource log = TplEventSource::in::Log;
  if (log->IsEnabled()) {
    Task<> internalCurrent = Task<>::in::get_InternalCurrent();
    Task<> task2 = AsyncMethodBuilderCore::TryGetContinuationTask(continuation);
    log->TaskWaitBegin((internalCurrent != nullptr) ? internalCurrent->m_taskScheduler->get_Id() : TaskScheduler::in::get_Default()->get_Id(), (internalCurrent != nullptr) ? internalCurrent->get_Id() : 0, task->get_Id(), TplEventSource::in::TaskWaitBehavior::Asynchronous, (task2 != nullptr) ? task2->get_Id() : 0);
  }
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::TaskAwaiterNamespace
