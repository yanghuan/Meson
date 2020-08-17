#include "TaskAwaiter-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/ObjectModel/ReadOnlyCollection-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncMethodBuilderCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCanceledException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskStatus.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::TaskAwaiterNamespace {
using namespace System::Collections::ObjectModel;
using namespace System::Runtime::ExceptionServices;
using namespace System::Threading;
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
    Boolean flag = task->InternalWait(-1, CancellationToken());
  }
  task->NotifyDebuggerOfWaitCompletionIfNecessary();
  if (!task->get_IsCompletedSuccessfully()) {
    ThrowForNonSuccess(task);
  }
}

void TaskAwaiter<>::ThrowForNonSuccess(Task<> task) {
  auto& default = task->GetCancellationExceptionDispatchInfo();
  switch (task->get_Status()) {
    case TaskStatus::Canceled:
      default == nullptr ? nullptr : default->Throw();
      rt::throw_exception<TaskCanceledException>(task);
    case TaskStatus::Faulted:
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
    auto& default = internalCurrent;
    auto& extern = default == nullptr ? nullptr : default->m_taskScheduler->get_Id();
    auto& ref = internalCurrent;
    auto& out = ref == nullptr ? nullptr : ref->get_Id();
    auto& byte = task2;
    auto& uint = byte == nullptr ? nullptr : byte->get_Id();
    log->TaskWaitBegin(extern != nullptr ? extern : TaskScheduler::in::get_Default()->get_Id(), out != nullptr ? out : 0, task->get_Id(), TplEventSource::in::TaskWaitBehavior::Asynchronous, uint != nullptr ? uint : 0);
  }
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::TaskAwaiterNamespace
