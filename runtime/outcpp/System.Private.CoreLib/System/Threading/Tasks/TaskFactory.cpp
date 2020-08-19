#include "TaskFactory-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/InternalTaskOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskFactory-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace {
Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_InvokeMayRunArbitraryCode() {
  return true;
}

Boolean TaskFactory___<>::CompleteOnCountdownPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  if (Task<>::in::get_ShouldNotifyDebuggerOfWaitCompletion()) {
    return Task<>::in::AnyTaskRequiresNotifyDebuggerOfWaitCompletion(_tasks);
  }
  return false;
}

void TaskFactory___<>::CompleteOnCountdownPromise___<>::ctor(Array<Task<>> tasksCopy) {
  _tasks = tasksCopy;
  _count = tasksCopy->get_Length();
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (Task<>::in::s_asyncDebuggingEnabled) {
    Task<>::in::AddToActiveTasks((CompleteOnCountdownPromise<>)this);
  }
}

void TaskFactory___<>::CompleteOnCountdownPromise___<>::Invoke(Task<> completingTask) {
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (completingTask->get_IsWaitNotificationEnabled()) {
    SetNotificationForWaitCompletion(true);
  }
  if (Interlocked::Decrement(_count) == 0) {
    Boolean loggingOn2 = AsyncCausalityTracer::get_LoggingOn();
    if (Task<>::in::s_asyncDebuggingEnabled) {
      Task<>::in::RemoveFromActiveTasks((CompleteOnCountdownPromise<>)this);
    }
    TrySetResult(_tasks);
  }
}

Boolean TaskFactory___<>::CompleteOnInvokePromise___::get_InvokeMayRunArbitraryCode() {
  return (_stateFlags & 2) == 0;
}

void TaskFactory___<>::CompleteOnInvokePromise___::ctor(IList<Task<>> tasks, Boolean isSyncBlocking) {
  _tasks = tasks;
  if (isSyncBlocking) {
    _stateFlags = 2;
  }
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (Task<>::in::s_asyncDebuggingEnabled) {
    Task<>::in::AddToActiveTasks((CompleteOnInvokePromise)this);
  }
}

void TaskFactory___<>::CompleteOnInvokePromise___::Invoke(Task<> completingTask) {
  Int32 stateFlags = _stateFlags;
  Int32 num = stateFlags & 2;
  if ((stateFlags & 1) != 0 || Interlocked::Exchange(_stateFlags, num | 1) != num) {
    return;
  }
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (Task<>::in::s_asyncDebuggingEnabled) {
    Task<>::in::RemoveFromActiveTasks((CompleteOnInvokePromise)this);
  }
  Boolean flag = TrySetResult(completingTask);
  IList<Task<>> tasks = _tasks;
  Int32 count = tasks->get_Count();
  for (Int32 i = 0; i < count; i++) {
    Task<> task = tasks[i];
    if (task != nullptr && !task->get_IsCompleted()) {
      task->RemoveContinuation((CompleteOnInvokePromise)this);
    }
  }
  _tasks = nullptr;
}

TaskScheduler TaskFactory___<>::get_DefaultScheduler() {
  auto& default = m_defaultScheduler;
  return default != nullptr ? default : TaskScheduler::in::get_Current();
}

CancellationToken TaskFactory___<>::get_CancellationToken() {
  return m_defaultCancellationToken;
}

TaskScheduler TaskFactory___<>::get_Scheduler() {
  return m_defaultScheduler;
}

TaskCreationOptions TaskFactory___<>::get_CreationOptions() {
  return m_defaultCreationOptions;
}

TaskContinuationOptions TaskFactory___<>::get_ContinuationOptions() {
  return m_defaultContinuationOptions;
}

TaskScheduler TaskFactory___<>::GetDefaultScheduler(Task<> currTask) {
  TaskScheduler taskScheduler = m_defaultScheduler;
  if (taskScheduler == nullptr) {
    if (currTask == nullptr || (currTask->get_CreationOptions() & TaskCreationOptions::HideScheduler) != 0) {
      return TaskScheduler::in::get_Default();
    }
    taskScheduler = currTask->get_ExecutingTaskScheduler();
  }
  return taskScheduler;
}

void TaskFactory___<>::ctor() {
}

void TaskFactory___<>::ctor(CancellationToken cancellationToken) {
}

void TaskFactory___<>::ctor(TaskScheduler scheduler) {
}

void TaskFactory___<>::ctor(TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions) {
}

void TaskFactory___<>::ctor(CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskContinuationOptions continuationOptions, TaskScheduler scheduler) {
  CheckMultiTaskContinuationOptions(continuationOptions);
  CheckCreationOptions(creationOptions);
  m_defaultCancellationToken = cancellationToken;
  m_defaultScheduler = scheduler;
  m_defaultCreationOptions = creationOptions;
  m_defaultContinuationOptions = continuationOptions;
}

void TaskFactory___<>::CheckCreationOptions(TaskCreationOptions creationOptions) {
  if ((creationOptions & ~(TaskCreationOptions::PreferFairness | TaskCreationOptions::LongRunning | TaskCreationOptions::AttachedToParent | TaskCreationOptions::DenyChildAttach | TaskCreationOptions::HideScheduler | TaskCreationOptions::RunContinuationsAsynchronously)) != 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::creationOptions);
  }
}

Task<> TaskFactory___<>::StartNew(Action<> action) {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  return Task<>::in::InternalStartNew(internalCurrent, action, nullptr, m_defaultCancellationToken, GetDefaultScheduler(internalCurrent), m_defaultCreationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<> action, CancellationToken cancellationToken) {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  return Task<>::in::InternalStartNew(internalCurrent, action, nullptr, cancellationToken, GetDefaultScheduler(internalCurrent), m_defaultCreationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<> action, TaskCreationOptions creationOptions) {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  return Task<>::in::InternalStartNew(internalCurrent, action, nullptr, m_defaultCancellationToken, GetDefaultScheduler(internalCurrent), creationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<> action, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler) {
  return Task<>::in::InternalStartNew(Task<>::in::InternalCurrentIfAttached(creationOptions), action, nullptr, cancellationToken, scheduler, creationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<Object> action, Object state) {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  return Task<>::in::InternalStartNew(internalCurrent, action, state, m_defaultCancellationToken, GetDefaultScheduler(internalCurrent), m_defaultCreationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<Object> action, Object state, CancellationToken cancellationToken) {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  return Task<>::in::InternalStartNew(internalCurrent, action, state, cancellationToken, GetDefaultScheduler(internalCurrent), m_defaultCreationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<Object> action, Object state, TaskCreationOptions creationOptions) {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  return Task<>::in::InternalStartNew(internalCurrent, action, state, m_defaultCancellationToken, GetDefaultScheduler(internalCurrent), creationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::StartNew(Action<Object> action, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, TaskScheduler scheduler) {
  return Task<>::in::InternalStartNew(Task<>::in::InternalCurrentIfAttached(creationOptions), action, state, cancellationToken, scheduler, creationOptions, InternalTaskOptions::None);
}

Task<> TaskFactory___<>::FromAsync(IAsyncResult asyncResult, Action<IAsyncResult> endMethod) {
  return FromAsync(asyncResult, endMethod, m_defaultCreationOptions, get_DefaultScheduler());
}

Task<> TaskFactory___<>::FromAsync(IAsyncResult asyncResult, Action<IAsyncResult> endMethod, TaskCreationOptions creationOptions) {
  return FromAsync(asyncResult, endMethod, creationOptions, get_DefaultScheduler());
}

Task<> TaskFactory___<>::FromAsync(IAsyncResult asyncResult, Action<IAsyncResult> endMethod, TaskCreationOptions creationOptions, TaskScheduler scheduler) {
  return TaskFactory<VoidTaskResult>::in::FromAsyncImpl(asyncResult, nullptr, endMethod, creationOptions, scheduler);
}

Task<> TaskFactory___<>::FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, Object state) {
  return FromAsync(beginMethod, endMethod, state, m_defaultCreationOptions);
}

Task<> TaskFactory___<>::FromAsync(Func<AsyncCallback, Object, IAsyncResult> beginMethod, Action<IAsyncResult> endMethod, Object state, TaskCreationOptions creationOptions) {
  return TaskFactory<VoidTaskResult>::in::FromAsyncImpl(beginMethod, nullptr, endMethod, state, creationOptions);
}

void TaskFactory___<>::CheckFromAsyncOptions(TaskCreationOptions creationOptions, Boolean hasBeginMethod) {
  if (hasBeginMethod) {
    if ((creationOptions & TaskCreationOptions::LongRunning) != 0) {
      rt::throw_exception<ArgumentOutOfRangeException>("creationOptions", SR::get_Task_FromAsync_LongRunning());
    }
    if ((creationOptions & TaskCreationOptions::PreferFairness) != 0) {
      rt::throw_exception<ArgumentOutOfRangeException>("creationOptions", SR::get_Task_FromAsync_PreferFairness());
    }
  }
  if ((creationOptions & ~(TaskCreationOptions::PreferFairness | TaskCreationOptions::LongRunning | TaskCreationOptions::AttachedToParent | TaskCreationOptions::DenyChildAttach | TaskCreationOptions::HideScheduler)) != 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::creationOptions);
  }
}

Task<Array<Task<>>> TaskFactory___<>::CommonCWAllLogic(Array<Task<>> tasksCopy) {
  CompleteOnCountdownPromise<> completeOnCountdownPromise = rt::newobj<CompleteOnCountdownPromise<>>(tasksCopy);
  for (Int32 i = 0; i < tasksCopy->get_Length(); i++) {
    if (tasksCopy[i]->get_IsCompleted()) {
      completeOnCountdownPromise->Invoke(tasksCopy[i]);
    } else {
      tasksCopy[i]->AddCompletionAction(completeOnCountdownPromise);
    }
  }
  return completeOnCountdownPromise;
}

Task<> TaskFactory___<>::ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAllImpl(tasks, nullptr, continuationAction, m_defaultContinuationOptions, m_defaultCancellationToken, get_DefaultScheduler());
}

Task<> TaskFactory___<>::ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction, CancellationToken cancellationToken) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAllImpl(tasks, nullptr, continuationAction, m_defaultContinuationOptions, cancellationToken, get_DefaultScheduler());
}

Task<> TaskFactory___<>::ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction, TaskContinuationOptions continuationOptions) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAllImpl(tasks, nullptr, continuationAction, continuationOptions, m_defaultCancellationToken, get_DefaultScheduler());
}

Task<> TaskFactory___<>::ContinueWhenAll(Array<Task<>> tasks, Action<Array<Task<>>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAllImpl(tasks, nullptr, continuationAction, continuationOptions, cancellationToken, scheduler);
}

Task<Task<>> TaskFactory___<>::CommonCWAnyLogic(IList<Task<>> tasks, Boolean isSyncBlocking) {
  CompleteOnInvokePromise completeOnInvokePromise = rt::newobj<CompleteOnInvokePromise>(tasks, isSyncBlocking);
  Boolean flag = false;
  Int32 count = tasks->get_Count();
  for (Int32 i = 0; i < count; i++) {
    Task<> task = tasks[i];
    if (task == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Task_MultiTaskContinuation_NullTask(), "tasks");
    }
    if (flag) {
      continue;
    }
    if (completeOnInvokePromise->get_IsCompleted()) {
      flag = true;
      continue;
    }
    if (task->get_IsCompleted()) {
      completeOnInvokePromise->Invoke(task);
      flag = true;
      continue;
    }
    task->AddCompletionAction(completeOnInvokePromise, isSyncBlocking);
    if (completeOnInvokePromise->get_IsCompleted()) {
      task->RemoveContinuation(completeOnInvokePromise);
    }
  }
  return completeOnInvokePromise;
}

void TaskFactory___<>::CommonCWAnyLogicCleanup(Task<Task<>> continuation) {
  ((CompleteOnInvokePromise)continuation)->Invoke(nullptr);
}

Task<> TaskFactory___<>::ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAnyImpl(tasks, nullptr, continuationAction, m_defaultContinuationOptions, m_defaultCancellationToken, get_DefaultScheduler());
}

Task<> TaskFactory___<>::ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction, CancellationToken cancellationToken) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAnyImpl(tasks, nullptr, continuationAction, m_defaultContinuationOptions, cancellationToken, get_DefaultScheduler());
}

Task<> TaskFactory___<>::ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction, TaskContinuationOptions continuationOptions) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAnyImpl(tasks, nullptr, continuationAction, continuationOptions, m_defaultCancellationToken, get_DefaultScheduler());
}

Task<> TaskFactory___<>::ContinueWhenAny(Array<Task<>> tasks, Action<Task<>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler) {
  if (continuationAction == nullptr) {
    rt::throw_exception<ArgumentNullException>("continuationAction");
  }
  return TaskFactory<VoidTaskResult>::in::ContinueWhenAnyImpl(tasks, nullptr, continuationAction, continuationOptions, cancellationToken, scheduler);
}

Array<Task<>> TaskFactory___<>::CheckMultiContinuationTasksAndCopy(Array<Task<>> tasks) {
  if (tasks == nullptr) {
    rt::throw_exception<ArgumentNullException>("tasks");
  }
  if (tasks->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Task_MultiTaskContinuation_EmptyTaskList(), "tasks");
  }
  Array<Task<>> array = rt::newarr<Array<Task<>>>(tasks->get_Length());
  for (Int32 i = 0; i < tasks->get_Length(); i++) {
    array[i] = tasks[i];
    if (array[i] == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Task_MultiTaskContinuation_NullTask(), "tasks");
    }
  }
  return array;
}

void TaskFactory___<>::CheckMultiTaskContinuationOptions(TaskContinuationOptions continuationOptions) {
  if ((continuationOptions & (TaskContinuationOptions::LongRunning | TaskContinuationOptions::ExecuteSynchronously)) == (TaskContinuationOptions::LongRunning | TaskContinuationOptions::ExecuteSynchronously)) {
    rt::throw_exception<ArgumentOutOfRangeException>("continuationOptions", SR::get_Task_ContinueWith_ESandLR());
  }
  if ((continuationOptions & ~(TaskContinuationOptions::PreferFairness | TaskContinuationOptions::LongRunning | TaskContinuationOptions::AttachedToParent | TaskContinuationOptions::DenyChildAttach | TaskContinuationOptions::HideScheduler | TaskContinuationOptions::LazyCancellation | TaskContinuationOptions::NotOnRanToCompletion | TaskContinuationOptions::NotOnFaulted | TaskContinuationOptions::NotOnCanceled | TaskContinuationOptions::ExecuteSynchronously)) != 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("continuationOptions");
  }
  if ((continuationOptions & (TaskContinuationOptions::NotOnRanToCompletion | TaskContinuationOptions::NotOnFaulted | TaskContinuationOptions::NotOnCanceled)) != 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("continuationOptions", SR::get_Task_MultiTaskContinuation_FireOptions());
  }
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskFactoryNamespace
