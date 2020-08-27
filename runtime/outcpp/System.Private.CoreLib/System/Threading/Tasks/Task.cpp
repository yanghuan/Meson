#include "Task-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/ICollection.h>
#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Debugger-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEventSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/CompletionActionInvoker-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ContinuationTaskFromTask-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ContinueWithTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/InternalTaskOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/SynchronizationContextAwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCanceledException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskContinuationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskSchedulerAwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskSchedulerException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/UnwrapPromise-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/VoidTaskResult-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace {
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Diagnostics::Tracing;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::ExceptionServices;

void DelayPromise___::ctor(Int32 millisecondsDelay) {
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (s_asyncDebuggingEnabled) {
    AddToActiveTasks((DelayPromise)this);
  }
  if (millisecondsDelay != -1) {
  }
}

void DelayPromise___::CompleteTimedOut() {
  if (TrySetResult()) {
    Cleanup();
    if (s_asyncDebuggingEnabled) {
      RemoveFromActiveTasks((DelayPromise)this);
    }
    Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  }
}

void DelayPromise___::Cleanup() {
  TimerQueueTimer timer = _timer;
  if (timer != nullptr) {
    timer->Close();
  }
}

void Task___<>::ContingentProperties___::SetCompleted() {
  ManualResetEventSlim completionEvent = m_completionEvent;
  if (completionEvent != nullptr) {
    completionEvent->Set();
  }
}

void Task___<>::ContingentProperties___::UnregisterCancellationCallback() {
  if (m_cancellationRegistration != nullptr) {
    try {
      m_cancellationRegistration->Value.Dispose();
    } catch (ObjectDisposedException) {
    }
    m_cancellationRegistration = nullptr;
  }
}

void Task___<>::ContingentProperties___::ctor() {
  m_completionCountdown = 1;
  Object::in::ctor();
}

Boolean Task___<>::SetOnInvokeMres___::get_InvokeMayRunArbitraryCode() {
  return false;
}

void Task___<>::SetOnInvokeMres___::ctor() {
}

void Task___<>::SetOnInvokeMres___::Invoke(Task<> completingTask) {
  Set();
}

Boolean Task___<>::SetOnCountdownMres___::get_InvokeMayRunArbitraryCode() {
  return false;
}

void Task___<>::SetOnCountdownMres___::ctor(Int32 count) {
  _count = count;
}

void Task___<>::SetOnCountdownMres___::Invoke(Task<> completingTask) {
  if (Interlocked::Decrement(_count) == 0) {
    Set();
  }
}

void DelayPromiseWithCancellation___::ctor(Int32 millisecondsDelay, CancellationToken token) {
  _token = token;
}

void DelayPromiseWithCancellation___::CompleteCanceled() {
  if (TrySetCanceled(_token)) {
    Cleanup();
  }
}

void DelayPromiseWithCancellation___::Cleanup() {
  _registration.Dispose();
  Task<>::in::DelayPromise::in::Cleanup();
}

Boolean WhenAllPromise___<>::get_InvokeMayRunArbitraryCode() {
  return true;
}

Boolean WhenAllPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  if (Task<>::in::get_ShouldNotifyDebuggerOfWaitCompletion()) {
    return AnyTaskRequiresNotifyDebuggerOfWaitCompletion(m_tasks);
  }
  return false;
}

void WhenAllPromise___<>::ctor(Array<Task<>> tasks) {
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (s_asyncDebuggingEnabled) {
    AddToActiveTasks((WhenAllPromise<>)this);
  }
  m_tasks = tasks;
  m_count = tasks->get_Length();
  for (Task<>& task : tasks) {
    if (task->get_IsCompleted()) {
      Invoke(task);
    } else {
      task->AddCompletionAction((WhenAllPromise<>)this);
    }
  }
}

void WhenAllPromise___<>::Invoke(Task<> completedTask) {
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (Interlocked::Decrement(m_count) != 0) {
    return;
  }
  List<ExceptionDispatchInfo> list = nullptr;
  Task<> task = nullptr;
  for (Int32 i = 0; i < m_tasks->get_Length(); i++) {
    Task<> task2 = m_tasks[i];
    if (task2->get_IsFaulted()) {
      if (list == nullptr) {
        list = rt::newobj<List<ExceptionDispatchInfo>>();
      }
      list->AddRange(task2->GetExceptionDispatchInfos());
    } else if (task2->get_IsCanceled() && task == nullptr) {
      task = task2;
    }

    if (task2->get_IsWaitNotificationEnabled()) {
      SetNotificationForWaitCompletion(true);
    } else {
      m_tasks[i] = nullptr;
    }
  }
  if (list != nullptr) {
    TrySetException(list);
    return;
  }
  if (task != nullptr) {
    TrySetCanceled(task->get_CancellationToken(), task->GetCancellationExceptionDispatchInfo());
    return;
  }
  Boolean loggingOn2 = AsyncCausalityTracer::get_LoggingOn();
  if (s_asyncDebuggingEnabled) {
    RemoveFromActiveTasks((WhenAllPromise<>)this);
  }
  TrySetResult();
}

Task<> Task___<>::get_ParentForDebugger() {
  ContingentProperties contingentProperties = m_contingentProperties;
  if (contingentProperties == nullptr) {
    return nullptr;
  }
  return contingentProperties->m_parent;
}

Int32 Task___<>::get_StateFlagsForDebugger() {
  return m_stateFlags;
}

String Task___<>::get_DebuggerDisplayMethodDescription() {
  Delegate action = m_action;
  String as = (((Object)action != nullptr) ? action->get_Method()->ToString() : nullptr);
  return as != nullptr ? as : "{null}";
}

TaskCreationOptions Task___<>::get_Options() {
  return OptionsMethod(m_stateFlags);
}

Boolean Task___<>::get_IsWaitNotificationEnabledOrNotRanToCompletion() {
  return (m_stateFlags & 285212672) != 16777216;
}

Boolean Task___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  return get_IsWaitNotificationEnabled();
}

Boolean Task___<>::get_IsWaitNotificationEnabled() {
  return (m_stateFlags & 268435456) != 0;
}

Int32 Task___<>::get_Id() {
  if (m_taskId == 0) {
    Int32 value = NewId();
    Interlocked::CompareExchange(m_taskId, value, 0);
  }
  return m_taskId;
}

Nullable<Int32> Task___<>::get_CurrentId() {
  Task<> internalCurrent = get_InternalCurrent();
  if (internalCurrent != nullptr) {
    return internalCurrent->get_Id();
  }
  return nullptr;
}

Task<> Task___<>::get_InternalCurrent() {
  return t_currentTask;
}

AggregateException Task___<>::get_Exception() {
  AggregateException result = nullptr;
  if (get_IsFaulted()) {
    result = GetExceptions(false);
  }
  return result;
}

TaskStatus Task___<>::get_Status() {
  Int32 stateFlags = m_stateFlags;
  if ((stateFlags & 2097152) != 0) {
    return TaskStatus::Faulted;
  }
  if ((stateFlags & 4194304) != 0) {
    return TaskStatus::Canceled;
  }
  if ((stateFlags & 16777216) != 0) {
    return TaskStatus::RanToCompletion;
  }
  if ((stateFlags & 8388608) != 0) {
    return TaskStatus::WaitingForChildrenToComplete;
  }
  if ((stateFlags & 131072) != 0) {
    return TaskStatus::Running;
  }
  if ((stateFlags & 65536) != 0) {
    return TaskStatus::WaitingToRun;
  }
  if ((stateFlags & 33554432) != 0) {
    return TaskStatus::WaitingForActivation;
  }
  return TaskStatus::Created;
}

Boolean Task___<>::get_IsCanceled() {
  return (m_stateFlags & 6291456) == 4194304;
}

Boolean Task___<>::get_IsCancellationRequested() {
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties != nullptr) {
    if (contingentProperties->m_internalCancellationRequested != 1) {
      return contingentProperties->m_cancellationToken.get_IsCancellationRequested();
    }
    return true;
  }
  return false;
}

CancellationToken Task___<>::get_CancellationToken() {
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties != nullptr) {
    return contingentProperties->m_cancellationToken;
  }
  return CancellationToken();
}

Boolean Task___<>::get_IsCancellationAcknowledged() {
  return (m_stateFlags & 1048576) != 0;
}

Boolean Task___<>::get_IsCompleted() {
  Int32 stateFlags = m_stateFlags;
  return IsCompletedMethod(stateFlags);
}

Boolean Task___<>::get_IsCompletedSuccessfully() {
  return (m_stateFlags & 23068672) == 16777216;
}

TaskCreationOptions Task___<>::get_CreationOptions() {
  return get_Options() & (TaskCreationOptions)(-65281);
}

WaitHandle Task___<>::get_AsyncWaitHandleOfIAsyncResult() {
  if ((m_stateFlags & 262144) != 0) {
    ThrowHelper::ThrowObjectDisposedException(ExceptionResource::Task_ThrowIfDisposed);
  }
  return get_CompletedEvent()->get_WaitHandle();
}

Object Task___<>::get_AsyncState() {
  return m_stateObject;
}

Boolean Task___<>::get_CompletedSynchronouslyOfIAsyncResult() {
  return false;
}

TaskScheduler Task___<>::get_ExecutingTaskScheduler() {
  return m_taskScheduler;
}

Task<> Task___<>::get_CompletedTask() {
  return s_cachedCompleted;
}

ManualResetEventSlim Task___<>::get_CompletedEvent() {
  ContingentProperties contingentProperties = EnsureContingentPropertiesInitialized();
  if (contingentProperties->m_completionEvent == nullptr) {
    Boolean isCompleted = get_IsCompleted();
    ManualResetEventSlim manualResetEventSlim = rt::newobj<ManualResetEventSlim>(isCompleted);
    if (Interlocked::CompareExchange(contingentProperties->m_completionEvent, manualResetEventSlim, (ManualResetEventSlim)nullptr) != nullptr) {
      manualResetEventSlim->Dispose();
    } else if (!isCompleted && get_IsCompleted()) {
      manualResetEventSlim->Set();
    }

  }
  return contingentProperties->m_completionEvent;
}

Boolean Task___<>::get_ExceptionRecorded() {
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties != nullptr && contingentProperties->m_exceptionsHolder != nullptr) {
    return contingentProperties->m_exceptionsHolder->get_ContainsFaultList();
  }
  return false;
}

Boolean Task___<>::get_IsFaulted() {
  return (m_stateFlags & 2097152) != 0;
}

ExecutionContext Task___<>::get_CapturedContext() {
  if ((m_stateFlags & 536870912) == 536870912) {
    return nullptr;
  }
  ContingentProperties contingentProperties = m_contingentProperties;
  ExecutionContext as = ((contingentProperties != nullptr) ? contingentProperties->m_capturedContext : nullptr);
  return as != nullptr ? as : ExecutionContext::in::Default;
}

void Task___<>::set_CapturedContext(ExecutionContext value) {
  if (value == nullptr) {
    m_stateFlags |= 536870912;
  } else if (value != ExecutionContext::in::Default) {
    EnsureContingentPropertiesInitializedUnsafe()->m_capturedContext = value;
  }

}

Boolean Task___<>::get_IsExceptionObservedByParent() {
  return (m_stateFlags & 524288) != 0;
}

Boolean Task___<>::get_IsDelegateInvoked() {
  return (m_stateFlags & 131072) != 0;
}

Boolean Task___<>::AddToActiveTasks(Task<> task) {
}

void Task___<>::RemoveFromActiveTasks(Task<> task) {
  if (s_currentActiveTasks != nullptr) {
    Int32 id = task->get_Id();
    {
      rt::lock(s_currentActiveTasks);
      s_currentActiveTasks->Remove(id);
    }
  }
}

void Task___<>::ctor(Boolean canceled, TaskCreationOptions creationOptions, CancellationToken ct) {
  if (canceled) {
    m_stateFlags = (Int32)((TaskCreationOptions)5242880 | creationOptions);
    m_contingentProperties = rt::newobj<ContingentProperties>();
  } else {
    m_stateFlags = (Int32)((TaskCreationOptions)16777216 | creationOptions);
  }
}

void Task___<>::ctor() {
  m_stateFlags = 33555456;
}

void Task___<>::ctor(Object state, TaskCreationOptions creationOptions, Boolean promiseStyle) {
  if ((creationOptions & ~(TaskCreationOptions::AttachedToParent | TaskCreationOptions::RunContinuationsAsynchronously)) != 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::creationOptions);
  }
  if ((creationOptions & TaskCreationOptions::AttachedToParent) != 0) {
    Task<> internalCurrent = get_InternalCurrent();
    if (internalCurrent != nullptr) {
      EnsureContingentPropertiesInitializedUnsafe()->m_parent = internalCurrent;
    }
  }
  TaskConstructorCore(nullptr, state, CancellationToken(), creationOptions, InternalTaskOptions::PromiseTask, nullptr);
}

void Task___<>::ctor(Action<> action) {
}

void Task___<>::ctor(Action<> action, CancellationToken cancellationToken) {
}

void Task___<>::ctor(Action<> action, TaskCreationOptions creationOptions) {
}

void Task___<>::ctor(Action<> action, CancellationToken cancellationToken, TaskCreationOptions creationOptions) {
}

void Task___<>::ctor(Action<Object> action, Object state) {
}

void Task___<>::ctor(Action<Object> action, Object state, CancellationToken cancellationToken) {
}

void Task___<>::ctor(Action<Object> action, Object state, TaskCreationOptions creationOptions) {
}

void Task___<>::ctor(Action<Object> action, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions) {
}

void Task___<>::ctor(Delegate action, Object state, Task<> parent, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler) {
  if ((Object)action == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::action);
  }
  if (parent != nullptr && (creationOptions & TaskCreationOptions::AttachedToParent) != 0) {
    EnsureContingentPropertiesInitializedUnsafe()->m_parent = parent;
  }
  TaskConstructorCore(action, state, cancellationToken, creationOptions, internalOptions, scheduler);
  get_CapturedContext(ExecutionContext::in::Capture());
}

void Task___<>::TaskConstructorCore(Delegate action, Object state, CancellationToken cancellationToken, TaskCreationOptions creationOptions, InternalTaskOptions internalOptions, TaskScheduler scheduler) {
  m_action = action;
  m_stateObject = state;
  m_taskScheduler = scheduler;
  if ((creationOptions & ~(TaskCreationOptions::PreferFairness | TaskCreationOptions::LongRunning | TaskCreationOptions::AttachedToParent | TaskCreationOptions::DenyChildAttach | TaskCreationOptions::HideScheduler | TaskCreationOptions::RunContinuationsAsynchronously)) != 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::creationOptions);
  }
  Int32 num = (Int32)creationOptions | (Int32)internalOptions;
  m_stateFlags = (((Object)m_action == nullptr || (internalOptions & InternalTaskOptions::ContinuationTask) != 0) ? (num | 33554432) : num);
  ContingentProperties contingentProperties = m_contingentProperties;
  if (contingentProperties != nullptr) {
    Task<> parent = contingentProperties->m_parent;
    if (parent != nullptr && (creationOptions & TaskCreationOptions::AttachedToParent) != 0 && (parent->get_CreationOptions() & TaskCreationOptions::DenyChildAttach) == 0) {
      parent->AddNewChild();
    }
  }
  if (cancellationToken.get_CanBeCanceled()) {
    AssignCancellationToken(cancellationToken, nullptr, nullptr);
  }
}

void Task___<>::AssignCancellationToken(CancellationToken cancellationToken, Task<> antecedent, TaskContinuation continuation) {
  ContingentProperties contingentProperties = EnsureContingentPropertiesInitializedUnsafe();
  contingentProperties->m_cancellationToken = cancellationToken;
  try {
    if ((get_Options() & (TaskCreationOptions)13312) != 0) {
      return;
    }
    if (cancellationToken.get_IsCancellationRequested()) {
      InternalCancel();
      return;
    }
  } catch (...) {
  }
}

TaskCreationOptions Task___<>::OptionsMethod(Int32 flags) {
  return (TaskCreationOptions)(flags & 65535);
}

Boolean Task___<>::AtomicStateUpdate(Int32 newBits, Int32 illegalBits) {
  Int32 stateFlags = m_stateFlags;
  if ((stateFlags & illegalBits) == 0) {
    if (Interlocked::CompareExchange(m_stateFlags, stateFlags | newBits, stateFlags) != stateFlags) {
      return AtomicStateUpdateSlow(newBits, illegalBits);
    }
    return true;
  }
  return false;
}

Boolean Task___<>::AtomicStateUpdateSlow(Int32 newBits, Int32 illegalBits) {
  Int32 num = m_stateFlags;
  while (true) {
    if ((num & illegalBits) != 0) {
      return false;
    }
    Int32 num2 = Interlocked::CompareExchange(m_stateFlags, num | newBits, num);
    if (num2 == num) {
      break;
    }
    num = num2;
  }
  return true;
}

Boolean Task___<>::AtomicStateUpdate(Int32 newBits, Int32 illegalBits, Int32& oldFlags) {
  Int32 num = oldFlags = m_stateFlags;
  while (true) {
    if ((num & illegalBits) != 0) {
      return false;
    }
    oldFlags = Interlocked::CompareExchange(m_stateFlags, num | newBits, num);
    if (oldFlags == num) {
      break;
    }
    num = oldFlags;
  }
  return true;
}

void Task___<>::SetNotificationForWaitCompletion(Boolean enabled) {
  if (enabled) {
    Boolean flag = AtomicStateUpdate(268435456, 90177536);
  } else {
    Interlocked::And(m_stateFlags, -268435457);
  }
}

Boolean Task___<>::NotifyDebuggerOfWaitCompletionIfNecessary() {
  if (get_IsWaitNotificationEnabled() && get_ShouldNotifyDebuggerOfWaitCompletion()) {
    NotifyDebuggerOfWaitCompletion();
    return true;
  }
  return false;
}

Boolean Task___<>::AnyTaskRequiresNotifyDebuggerOfWaitCompletion(Array<Task<>> tasks) {
  for (Task<>& task : tasks) {
    if (task != nullptr && task->get_IsWaitNotificationEnabled() && task->get_ShouldNotifyDebuggerOfWaitCompletion()) {
      return true;
    }
  }
  return false;
}

void Task___<>::NotifyDebuggerOfWaitCompletion() {
  SetNotificationForWaitCompletion(false);
}

Boolean Task___<>::MarkStarted() {
  return AtomicStateUpdate(65536, 4259840);
}

void Task___<>::FireTaskScheduledIfNeeded(TaskScheduler ts) {
  if ((m_stateFlags & 1073741824) == 0) {
    m_stateFlags |= 1073741824;
    Task<> internalCurrent = get_InternalCurrent();
    ContingentProperties contingentProperties = m_contingentProperties;
    Task<> task = (contingentProperties != nullptr) ? contingentProperties->m_parent : nullptr;
    TplEventSource::in::Log->TaskScheduled(ts->get_Id(), (internalCurrent != nullptr) ? internalCurrent->get_Id() : 0, get_Id(), (task != nullptr) ? task->get_Id() : 0, (Int32)get_Options());
  }
}

void Task___<>::AddNewChild() {
  ContingentProperties contingentProperties = EnsureContingentPropertiesInitialized();
  if (contingentProperties->m_completionCountdown == 1) {
    contingentProperties->m_completionCountdown++;
  } else {
    Interlocked::Increment(contingentProperties->m_completionCountdown);
  }
}

void Task___<>::DisregardChild() {
  ContingentProperties contingentProperties = EnsureContingentPropertiesInitialized();
  Interlocked::Decrement(contingentProperties->m_completionCountdown);
}

void Task___<>::Start() {
  Start(TaskScheduler::in::get_Current());
}

void Task___<>::Start(TaskScheduler scheduler) {
  Int32 stateFlags = m_stateFlags;
  if (IsCompletedMethod(stateFlags)) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_Start_TaskCompleted);
  }
  if (scheduler == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::scheduler);
  }
  TaskCreationOptions taskCreationOptions = OptionsMethod(stateFlags);
  if ((taskCreationOptions & (TaskCreationOptions)1024) != 0) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_Start_Promise);
  }
  if ((taskCreationOptions & (TaskCreationOptions)512) != 0) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_Start_ContinuationTask);
  }
  if (Interlocked::CompareExchange(m_taskScheduler, scheduler, (TaskScheduler)nullptr) != nullptr) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_Start_AlreadyStarted);
  }
  ScheduleAndStart(true);
}

void Task___<>::RunSynchronously() {
  InternalRunSynchronously(TaskScheduler::in::get_Current(), true);
}

void Task___<>::RunSynchronously(TaskScheduler scheduler) {
  if (scheduler == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::scheduler);
  }
  InternalRunSynchronously(scheduler, true);
}

void Task___<>::InternalRunSynchronously(TaskScheduler scheduler, Boolean waitForCompletion) {
  Int32 stateFlags = m_stateFlags;
  TaskCreationOptions taskCreationOptions = OptionsMethod(stateFlags);
  if ((taskCreationOptions & (TaskCreationOptions)512) != 0) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_RunSynchronously_Continuation);
  }
  if ((taskCreationOptions & (TaskCreationOptions)1024) != 0) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_RunSynchronously_Promise);
  }
  if (IsCompletedMethod(stateFlags)) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_RunSynchronously_TaskCompleted);
  }
  if (Interlocked::CompareExchange(m_taskScheduler, scheduler, (TaskScheduler)nullptr) != nullptr) {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_RunSynchronously_AlreadyStarted);
  }
  if (MarkStarted()) {
    Boolean flag = false;
    try {
      if (!scheduler->TryRunInline((Task<>)this, false)) {
        scheduler->InternalQueueTask((Task<>)this);
        flag = true;
      }
      if (waitForCompletion && !get_IsCompleted()) {
        SpinThenBlockingWait(-1, CancellationToken());
      }
    } catch (Exception innerException) {
    }
  } else {
    ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_RunSynchronously_TaskCompleted);
  }
}

Task<> Task___<>::InternalStartNew(Task<> creatingTask, Delegate action, Object state, CancellationToken cancellationToken, TaskScheduler scheduler, TaskCreationOptions options, InternalTaskOptions internalOptions) {
  if (scheduler == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::scheduler);
  }
  Task<> task = rt::newobj<Task<>>(action, state, creatingTask, cancellationToken, options, internalOptions | InternalTaskOptions::QueuedByRuntime, scheduler);
  task->ScheduleAndStart(false);
  return task;
}

Int32 Task___<>::NewId() {
  Int32 num;
  do {
    num = Interlocked::Increment(s_taskIdCounter);
  } while (num == 0)
  if (TplEventSource::in::Log->IsEnabled()) {
    TplEventSource::in::Log->NewID(num);
  }
  return num;
}

Task<> Task___<>::InternalCurrentIfAttached(TaskCreationOptions creationOptions) {
  if ((creationOptions & TaskCreationOptions::AttachedToParent) == 0) {
    return nullptr;
  }
  return get_InternalCurrent();
}

Task<>::in::ContingentProperties Task___<>::EnsureContingentPropertiesInitialized() {
}

Task<>::in::ContingentProperties Task___<>::EnsureContingentPropertiesInitializedUnsafe() {
  ContingentProperties as = m_contingentProperties;
  return as != nullptr ? as : (m_contingentProperties = rt::newobj<ContingentProperties>());
}

Boolean Task___<>::IsCompletedMethod(Int32 flags) {
  return (flags & 23068672) != 0;
}

void Task___<>::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((Task<>)this);
}

void Task___<>::Dispose(Boolean disposing) {
  if (disposing) {
    if ((get_Options() & (TaskCreationOptions)16384) != 0) {
      return;
    }
    if (!get_IsCompleted()) {
      ThrowHelper::ThrowInvalidOperationException(ExceptionResource::Task_Dispose_NotCompleted);
    }
    ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
    if (contingentProperties != nullptr) {
      ManualResetEventSlim completionEvent = contingentProperties->m_completionEvent;
      if (completionEvent != nullptr) {
        contingentProperties->m_completionEvent = nullptr;
        if (!completionEvent->get_IsSet()) {
          completionEvent->Set();
        }
        completionEvent->Dispose();
      }
    }
  }
  m_stateFlags |= 262144;
}

void Task___<>::ScheduleAndStart(Boolean needsProtection) {
  if (needsProtection) {
    if (!MarkStarted()) {
      return;
    }
  } else {
    m_stateFlags |= 65536;
  }
  if (s_asyncDebuggingEnabled) {
    AddToActiveTasks((Task<>)this);
  }
  if (AsyncCausalityTracer::get_LoggingOn()) {
  }
  try {
    m_taskScheduler->InternalQueueTask((Task<>)this);
  } catch (Exception innerException) {
  }
}

void Task___<>::AddException(Object exceptionObject) {
  AddException(exceptionObject, false);
}

void Task___<>::AddException(Object exceptionObject, Boolean representsCancellation) {
  ContingentProperties contingentProperties = EnsureContingentPropertiesInitialized();
  if (contingentProperties->m_exceptionsHolder == nullptr) {
    TaskExceptionHolder taskExceptionHolder = rt::newobj<TaskExceptionHolder>((Task<>)this);
    if (Interlocked::CompareExchange(contingentProperties->m_exceptionsHolder, taskExceptionHolder, (TaskExceptionHolder)nullptr) != nullptr) {
      taskExceptionHolder->MarkAsHandled(false);
    }
  }
  {
    rt::lock(contingentProperties);
    contingentProperties->m_exceptionsHolder->Add(exceptionObject, representsCancellation);
  }
}

AggregateException Task___<>::GetExceptions(Boolean includeTaskCanceledExceptions) {
  Exception ex = nullptr;
  if (includeTaskCanceledExceptions && get_IsCanceled()) {
    ex = rt::newobj<TaskCanceledException>((Task<>)this);
    ex->SetCurrentStackTrace();
  }
  if (get_ExceptionRecorded()) {
    return m_contingentProperties->m_exceptionsHolder->CreateExceptionObject(false, ex);
  }
  if (ex != nullptr) {
    return rt::newobj<AggregateException>(ex);
  }
  return nullptr;
}

ReadOnlyCollection<ExceptionDispatchInfo> Task___<>::GetExceptionDispatchInfos() {
  return m_contingentProperties->m_exceptionsHolder->GetExceptionDispatchInfos();
}

ExceptionDispatchInfo Task___<>::GetCancellationExceptionDispatchInfo() {
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties == nullptr) {
    return nullptr;
  }
  TaskExceptionHolder exceptionsHolder = contingentProperties->m_exceptionsHolder;
  if (exceptionsHolder == nullptr) {
    return nullptr;
  }
  return exceptionsHolder->GetCancellationExceptionDispatchInfo();
}

void Task___<>::ThrowIfExceptional(Boolean includeTaskCanceledExceptions) {
  Exception exceptions = GetExceptions(includeTaskCanceledExceptions);
  if (exceptions != nullptr) {
    UpdateExceptionObservedStatus();
    rt::throw_exception(exceptions);
  }
}

void Task___<>::ThrowAsync(Exception exception, SynchronizationContext targetContext) {
  ExceptionDispatchInfo state2 = ExceptionDispatchInfo::in::Capture(exception);
  if (targetContext != nullptr) {
    try {
    } catch (Exception ex) {
    }
  }
}

void Task___<>::UpdateExceptionObservedStatus() {
  ContingentProperties contingentProperties = m_contingentProperties;
  Task<> task = (contingentProperties != nullptr) ? contingentProperties->m_parent : nullptr;
  if (task != nullptr && (get_Options() & TaskCreationOptions::AttachedToParent) != 0 && (task->get_CreationOptions() & TaskCreationOptions::DenyChildAttach) == 0 && get_InternalCurrent() == task) {
    m_stateFlags |= 524288;
  }
}

void Task___<>::Finish(Boolean userDelegateExecute) {
  if (m_contingentProperties == nullptr) {
    FinishStageTwo();
  } else {
    FinishSlow(userDelegateExecute);
  }
}

void Task___<>::FinishSlow(Boolean userDelegateExecute) {
  if (!userDelegateExecute) {
    FinishStageTwo();
    return;
  }
  ContingentProperties contingentProperties = m_contingentProperties;
  if (contingentProperties->m_completionCountdown == 1 || Interlocked::Decrement(contingentProperties->m_completionCountdown) == 0) {
    FinishStageTwo();
  } else {
    AtomicStateUpdate(8388608, 23068672);
  }
  List<Task<>> exceptionalChildren = contingentProperties->m_exceptionalChildren;
  if (exceptionalChildren == nullptr) {
    return;
  }
  {
    rt::lock(exceptionalChildren);
  }
}

void Task___<>::FinishStageTwo() {
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties != nullptr) {
    AddExceptionsFromChildren(contingentProperties);
  }
  Int32 num;
  if (get_ExceptionRecorded()) {
    num = 2097152;
    Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
    if (s_asyncDebuggingEnabled) {
      RemoveFromActiveTasks((Task<>)this);
    }
  } else if (get_IsCancellationRequested() && get_IsCancellationAcknowledged()) {
    num = 4194304;
    Boolean loggingOn2 = AsyncCausalityTracer::get_LoggingOn();
    if (s_asyncDebuggingEnabled) {
      RemoveFromActiveTasks((Task<>)this);
    }
  } else {
    num = 16777216;
    Boolean loggingOn3 = AsyncCausalityTracer::get_LoggingOn();
    if (s_asyncDebuggingEnabled) {
      RemoveFromActiveTasks((Task<>)this);
    }
  }

  Interlocked::Exchange(m_stateFlags, m_stateFlags | num);
  contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties != nullptr) {
    contingentProperties->SetCompleted();
    contingentProperties->UnregisterCancellationCallback();
  }
  FinishStageThree();
}

void Task___<>::FinishStageThree() {
  m_action = nullptr;
  ContingentProperties contingentProperties = m_contingentProperties;
  if (contingentProperties != nullptr) {
    contingentProperties->m_capturedContext = nullptr;
    NotifyParentIfPotentiallyAttachedTask();
  }
  FinishContinuations();
}

void Task___<>::NotifyParentIfPotentiallyAttachedTask() {
  ContingentProperties contingentProperties = m_contingentProperties;
  Task<> task = (contingentProperties != nullptr) ? contingentProperties->m_parent : nullptr;
  if (task != nullptr && (task->get_CreationOptions() & TaskCreationOptions::DenyChildAttach) == 0 && (m_stateFlags & 65535 & 4) != 0) {
    task->ProcessChildCompletion((Task<>)this);
  }
}

void Task___<>::ProcessChildCompletion(Task<> childTask) {
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (childTask->get_IsFaulted() && !childTask->get_IsExceptionObservedByParent()) {
    if (contingentProperties->m_exceptionalChildren == nullptr) {
      Interlocked::CompareExchange(contingentProperties->m_exceptionalChildren, rt::newobj<List<Task<>>>(), (List<Task<>>)nullptr);
    }
    List<Task<>> exceptionalChildren = contingentProperties->m_exceptionalChildren;
    if (exceptionalChildren != nullptr) {
      {
        rt::lock(exceptionalChildren);
        exceptionalChildren->Add(childTask);
      }
    }
  }
  if (Interlocked::Decrement(contingentProperties->m_completionCountdown) == 0) {
    FinishStageTwo();
  }
}

void Task___<>::AddExceptionsFromChildren(ContingentProperties props) {
  List<Task<>> exceptionalChildren = props->m_exceptionalChildren;
  if (exceptionalChildren == nullptr) {
    return;
  }
  {
    rt::lock(exceptionalChildren);
    for (Task<>& item : exceptionalChildren) {
      if (item->get_IsFaulted() && !item->get_IsExceptionObservedByParent()) {
        TaskExceptionHolder exceptionsHolder = Volatile::Read(item->m_contingentProperties)->m_exceptionsHolder;
        AddException(exceptionsHolder->CreateExceptionObject(false, nullptr));
      }
    }
  }
  props->m_exceptionalChildren = nullptr;
}

Boolean Task___<>::ExecuteEntry() {
  Int32 oldFlags = 0;
  if (!AtomicStateUpdate(131072, 23199744, oldFlags) && (oldFlags & 4194304) == 0) {
    return false;
  }
  if (!get_IsCancellationRequested() & !get_IsCanceled()) {
    ExecuteWithThreadLocal(t_currentTask);
  } else {
    ExecuteEntryCancellationRequestedOrCanceled();
  }
  return true;
}

void Task___<>::ExecuteFromThreadPool(Thread threadPoolThread) {
  ExecuteEntryUnsafe(threadPoolThread);
}

void Task___<>::ExecuteEntryUnsafe(Thread threadPoolThread) {
  m_stateFlags |= 131072;
  if (!get_IsCancellationRequested() & !get_IsCanceled()) {
    ExecuteWithThreadLocal(t_currentTask, threadPoolThread);
  } else {
    ExecuteEntryCancellationRequestedOrCanceled();
  }
}

void Task___<>::ExecuteEntryCancellationRequestedOrCanceled() {
  if (!get_IsCanceled()) {
    Int32 num = Interlocked::Exchange(m_stateFlags, m_stateFlags | 4194304);
    if ((num & 4194304) == 0) {
      CancellationCleanupLogic();
    }
  }
}

void Task___<>::ExecuteWithThreadLocal(Task<>& currentTaskSlot, Thread threadPoolThread) {
  Task<> task = currentTaskSlot;
  TplEventSource log = TplEventSource::in::Log;
  Guid oldActivityThatWillContinue = Guid();
  Boolean flag = log->IsEnabled();
  if (flag) {
    if (log->TasksSetActivityIds) {
      EventSource::in::SetCurrentThreadActivityId(TplEventSource::in::CreateGuidForTaskID(get_Id()), oldActivityThatWillContinue);
    }
    if (task != nullptr) {
      log->TaskStarted(task->m_taskScheduler->get_Id(), task->get_Id(), get_Id());
    } else {
      log->TaskStarted(TaskScheduler::in::get_Current()->get_Id(), 0, get_Id());
    }
  }
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  try {
    currentTaskSlot = (Task<>)this;
    try {
      ExecutionContext capturedContext = get_CapturedContext();
      if (capturedContext == nullptr) {
        InnerInvoke();
      } else if (threadPoolThread == nullptr) {
        ExecutionContext::in::RunInternal(capturedContext, s_ecCallback, (Task<>)this);
      } else {
        ExecutionContext::in::RunFromThreadPoolDispatchLoop(threadPoolThread, capturedContext, s_ecCallback, (Task<>)this);
      }

    } catch (Exception unhandledException) {
    }
    Finish(true);
  } catch (...) {
  } finally: {
    currentTaskSlot = task;
    if (flag) {
      if (task != nullptr) {
        log->TaskCompleted(task->m_taskScheduler->get_Id(), task->get_Id(), get_Id(), get_IsFaulted());
      } else {
        log->TaskCompleted(TaskScheduler::in::get_Current()->get_Id(), 0, get_Id(), get_IsFaulted());
      }
      if (log->TasksSetActivityIds) {
        EventSource::in::SetCurrentThreadActivityId(oldActivityThatWillContinue);
      }
    }
  }
}

void Task___<>::InnerInvoke() {
  Action<> action = rt::as<Action<>>(m_action);
  if (action != nullptr) {
    action();
    return;
  }
  Action<Object> action2 = rt::as<Action<Object>>(m_action);
  if (action2 != nullptr) {
    action2(m_stateObject);
  }
}

void Task___<>::HandleException(Exception unhandledException) {
  OperationCanceledException ex = rt::as<OperationCanceledException>(unhandledException);
  if (ex != nullptr && get_IsCancellationRequested() && m_contingentProperties->m_cancellationToken == ex->get_CancellationToken()) {
    SetCancellationAcknowledged();
    AddException(ex, true);
  } else {
    AddException(unhandledException);
  }
}

TaskAwaiter<> Task___<>::GetAwaiter() {
  return TaskAwaiter<>((Task<>)this);
}

ConfiguredTaskAwaitable<> Task___<>::ConfigureAwait(Boolean continueOnCapturedContext) {
  return ConfiguredTaskAwaitable<>((Task<>)this, continueOnCapturedContext);
}

void Task___<>::SetContinuationForAwait(Action<> continuationAction, Boolean continueOnCapturedContext, Boolean flowExecutionContext) {
  TaskContinuation taskContinuation = nullptr;
  if (continueOnCapturedContext) {
    SynchronizationContext current = SynchronizationContext::in::get_Current();
    if (current != nullptr && current->GetType() != typeof<SynchronizationContext>()) {
      taskContinuation = rt::newobj<SynchronizationContextAwaitTaskContinuation>(current, continuationAction, flowExecutionContext);
    } else {
      TaskScheduler internalCurrent = TaskScheduler::in::get_InternalCurrent();
      if (internalCurrent != nullptr && internalCurrent != TaskScheduler::in::get_Default()) {
        taskContinuation = rt::newobj<TaskSchedulerAwaitTaskContinuation>(internalCurrent, continuationAction, flowExecutionContext);
      }
    }
  }
  if (taskContinuation == nullptr && flowExecutionContext) {
    taskContinuation = rt::newobj<AwaitTaskContinuation>(continuationAction, true);
  }
  if (taskContinuation != nullptr) {
    if (!AddTaskContinuation(taskContinuation, false)) {
      taskContinuation->Run((Task<>)this, false);
    }
  } else if (!AddTaskContinuation(continuationAction, false)) {
    AwaitTaskContinuation::in::UnsafeScheduleAction(continuationAction, (Task<>)this);
  }

}

void Task___<>::UnsafeSetContinuationForAwait(IAsyncStateMachineBox stateMachineBox, Boolean continueOnCapturedContext) {
  if (continueOnCapturedContext) {
    SynchronizationContext current = SynchronizationContext::in::get_Current();
    if (current != nullptr && current->GetType() != typeof<SynchronizationContext>()) {
      SynchronizationContextAwaitTaskContinuation synchronizationContextAwaitTaskContinuation = rt::newobj<SynchronizationContextAwaitTaskContinuation>(current, stateMachineBox->get_MoveNextAction(), false);
      if (!AddTaskContinuation(synchronizationContextAwaitTaskContinuation, false)) {
        synchronizationContextAwaitTaskContinuation->Run((Task<>)this, false);
      }
      return;
    }
    TaskScheduler internalCurrent = TaskScheduler::in::get_InternalCurrent();
    if (internalCurrent != nullptr && internalCurrent != TaskScheduler::in::get_Default()) {
      TaskSchedulerAwaitTaskContinuation taskSchedulerAwaitTaskContinuation = rt::newobj<TaskSchedulerAwaitTaskContinuation>(internalCurrent, stateMachineBox->get_MoveNextAction(), false);
      if (!AddTaskContinuation(taskSchedulerAwaitTaskContinuation, false)) {
        taskSchedulerAwaitTaskContinuation->Run((Task<>)this, false);
      }
      return;
    }
  }
  if (!AddTaskContinuation(stateMachineBox, false)) {
    ThreadPool::UnsafeQueueUserWorkItemInternal(stateMachineBox, true);
  }
}

YieldAwaitable Task___<>::Yield() {
  return YieldAwaitable();
}

void Task___<>::Wait() {
  Wait(-1, CancellationToken());
}

Boolean Task___<>::Wait(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::timeout);
  }
  return Wait((Int32)num, CancellationToken());
}

void Task___<>::Wait(CancellationToken cancellationToken) {
  Wait(-1, cancellationToken);
}

Boolean Task___<>::Wait(Int32 millisecondsTimeout) {
  return Wait(millisecondsTimeout, CancellationToken());
}

Boolean Task___<>::Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  if (millisecondsTimeout < -1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::millisecondsTimeout);
  }
  if (!get_IsWaitNotificationEnabledOrNotRanToCompletion()) {
    return true;
  }
  if (!InternalWait(millisecondsTimeout, cancellationToken)) {
    return false;
  }
  if (get_IsWaitNotificationEnabledOrNotRanToCompletion()) {
    NotifyDebuggerOfWaitCompletionIfNecessary();
    if (get_IsCanceled()) {
      cancellationToken.ThrowIfCancellationRequested();
    }
    ThrowIfExceptional(true);
  }
  return true;
}

Boolean Task___<>::WrappedTryRunInline() {
  if (m_taskScheduler == nullptr) {
    return false;
  }
  try {
    return m_taskScheduler->TryRunInline((Task<>)this, true);
  } catch (Exception innerException) {
  }
}

Boolean Task___<>::InternalWait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return InternalWaitCore(millisecondsTimeout, cancellationToken);
}

Boolean Task___<>::InternalWaitCore(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  if (get_IsCompleted()) {
    return true;
  }
  TplEventSource log = TplEventSource::in::Log;
  Boolean flag = log->IsEnabled();
  if (flag) {
    Task<> internalCurrent = get_InternalCurrent();
    log->TaskWaitBegin((internalCurrent != nullptr) ? internalCurrent->m_taskScheduler->get_Id() : TaskScheduler::in::get_Default()->get_Id(), (internalCurrent != nullptr) ? internalCurrent->get_Id() : 0, get_Id(), TplEventSource::in::TaskWaitBehavior::Synchronous, 0);
  }
  Debugger::NotifyOfCrossThreadDependency();
  Boolean result = (millisecondsTimeout == -1 && !cancellationToken.get_CanBeCanceled() && WrappedTryRunInline() && get_IsCompleted()) || SpinThenBlockingWait(millisecondsTimeout, cancellationToken);
  if (flag) {
    Task<> internalCurrent2 = get_InternalCurrent();
    if (internalCurrent2 != nullptr) {
      log->TaskWaitEnd(internalCurrent2->m_taskScheduler->get_Id(), internalCurrent2->get_Id(), get_Id());
    } else {
      log->TaskWaitEnd(TaskScheduler::in::get_Default()->get_Id(), 0, get_Id());
    }
    log->TaskWaitContinuationComplete(get_Id());
  }
  return result;
}

Boolean Task___<>::SpinThenBlockingWait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  Boolean flag = millisecondsTimeout == -1;
  UInt32 num = (UInt32)((!flag) ? Environment::get_TickCount() : 0);
  Boolean flag2 = SpinWait(millisecondsTimeout);
  if (!flag2) {
    SetOnInvokeMres setOnInvokeMres = rt::newobj<SetOnInvokeMres>();
    try {
      AddCompletionAction(setOnInvokeMres, true);
      if (flag) {
        return setOnInvokeMres->Wait(-1, cancellationToken);
      }
      UInt32 num2 = (UInt32)Environment::get_TickCount() - num;
      if (num2 < millisecondsTimeout) {
        return setOnInvokeMres->Wait((Int32)(millisecondsTimeout - num2), cancellationToken);
      }
      return flag2;
    } catch (...) {
    } finally: {
      if (!get_IsCompleted()) {
        RemoveContinuation(setOnInvokeMres);
      }
    }
  }
  return flag2;
}

Boolean Task___<>::SpinWait(Int32 millisecondsTimeout) {
  if (get_IsCompleted()) {
    return true;
  }
  if (millisecondsTimeout == 0) {
    return false;
  }
  Int32 spinCountforSpinBeforeWait = SpinWait::SpinCountforSpinBeforeWait;
  SpinWait spinWait = SpinWait();
  while (spinWait.get_Count() < spinCountforSpinBeforeWait) {
    spinWait.SpinOnce(-1);
    if (get_IsCompleted()) {
      return true;
    }
  }
  return false;
}

void Task___<>::InternalCancel() {
  TaskSchedulerException ex = nullptr;
  Boolean flag = false;
  if ((m_stateFlags & 65536) != 0) {
    TaskScheduler taskScheduler = m_taskScheduler;
    try {
      flag = (taskScheduler != nullptr && taskScheduler->TryDequeue((Task<>)this));
    } catch (Exception innerException) {
    }
  }
  RecordInternalCancellationRequest();
  Boolean flag2 = false;
  if (flag) {
    flag2 = AtomicStateUpdate(4194304, 4325376);
  } else if ((m_stateFlags & 65536) == 0) {
    flag2 = AtomicStateUpdate(4194304, 23265280);
  }

  if (flag2) {
    CancellationCleanupLogic();
  }
  if (ex != nullptr) {
    rt::throw_exception(ex);
  }
}

void Task___<>::InternalCancelContinueWithInitialState() {
  m_stateFlags |= 4194304;
  CancellationCleanupLogic();
}

void Task___<>::RecordInternalCancellationRequest() {
  EnsureContingentPropertiesInitialized()->m_internalCancellationRequested = 1;
}

void Task___<>::RecordInternalCancellationRequest(CancellationToken tokenToRecord, Object cancellationException) {
  RecordInternalCancellationRequest();
  if (tokenToRecord != CancellationToken()) {
    m_contingentProperties->m_cancellationToken = tokenToRecord;
  }
  if (cancellationException != nullptr) {
    AddException(cancellationException, true);
  }
}

void Task___<>::CancellationCleanupLogic() {
  Interlocked::Exchange(m_stateFlags, m_stateFlags | 4194304);
  ContingentProperties contingentProperties = Volatile::Read(m_contingentProperties);
  if (contingentProperties != nullptr) {
    contingentProperties->SetCompleted();
    contingentProperties->UnregisterCancellationCallback();
  }
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  if (s_asyncDebuggingEnabled) {
    RemoveFromActiveTasks((Task<>)this);
  }
  FinishStageThree();
}

void Task___<>::SetCancellationAcknowledged() {
  m_stateFlags |= 1048576;
}

Boolean Task___<>::TrySetResult() {
  if (AtomicStateUpdate(83886080, 90177536)) {
    ContingentProperties contingentProperties = m_contingentProperties;
    if (contingentProperties != nullptr) {
      NotifyParentIfPotentiallyAttachedTask();
      contingentProperties->SetCompleted();
    }
    FinishContinuations();
    return true;
  }
  return false;
}

Boolean Task___<>::TrySetException(Object exceptionObject) {
  Boolean result = false;
  EnsureContingentPropertiesInitialized();
  if (AtomicStateUpdate(67108864, 90177536)) {
    AddException(exceptionObject);
    Finish(false);
    result = true;
  }
  return result;
}

Boolean Task___<>::TrySetCanceled(CancellationToken tokenToRecord) {
  return TrySetCanceled(tokenToRecord, nullptr);
}

Boolean Task___<>::TrySetCanceled(CancellationToken tokenToRecord, Object cancellationException) {
  Boolean result = false;
  if (AtomicStateUpdate(67108864, 90177536)) {
    RecordInternalCancellationRequest(tokenToRecord, cancellationException);
    CancellationCleanupLogic();
    result = true;
  }
  return result;
}

void Task___<>::FinishContinuations() {
  Object obj = Interlocked::Exchange(m_continuationObject, s_taskCompletionSentinel);
  if (obj != nullptr) {
    RunContinuations(obj);
  }
}

void Task___<>::RunContinuations(Object continuationObject) {
  TplEventSource tplEventSource = TplEventSource::in::Log;
  if (!tplEventSource->IsEnabled()) {
    tplEventSource = nullptr;
  }
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
  Boolean flag = (m_stateFlags & 64) == 0 && RuntimeHelpers::TryEnsureSufficientExecutionStack();
  IAsyncStateMachineBox asyncStateMachineBox = rt::as<IAsyncStateMachineBox>(continuationObject);
  if (asyncStateMachineBox == nullptr) {
    Action<> action = rt::as<Action<>>(continuationObject);
    if (action == nullptr) {
      TaskContinuation taskContinuation = rt::as<TaskContinuation>(continuationObject);
      if (taskContinuation == nullptr) {
        ITaskCompletionAction taskCompletionAction = rt::as<ITaskCompletionAction>(continuationObject);
        if (taskCompletionAction != nullptr) {
          RunOrQueueCompletionAction(taskCompletionAction, flag);
          LogFinishCompletionNotification();
          return;
        }
        List<Object> list = (List<Object>)continuationObject;
        {
          rt::lock(list);
        }
        Int32 count = list->get_Count();
        if (flag) {
          Boolean flag2 = false;
          for (Int32 i = 0; i < count; i++) {
            Object obj = list[i];
            if (obj == nullptr) {
              continue;
            }
            ContinueWithTaskContinuation continueWithTaskContinuation = rt::as<ContinueWithTaskContinuation>(obj);
            if (continueWithTaskContinuation != nullptr) {
              if ((continueWithTaskContinuation->m_options & TaskContinuationOptions::ExecuteSynchronously) == 0) {
                list[i] = nullptr;
                if (tplEventSource != nullptr) {
                  tplEventSource->RunningContinuationList(get_Id(), i, continueWithTaskContinuation);
                }
                continueWithTaskContinuation->Run((Task<>)this, false);
              }
            } else {
              if (rt::is<ITaskCompletionAction>(obj)) {
                continue;
              }
              if (flag2) {
                list[i] = nullptr;
                if (tplEventSource != nullptr) {
                  tplEventSource->RunningContinuationList(get_Id(), i, obj);
                }
                IAsyncStateMachineBox asyncStateMachineBox2 = rt::as<IAsyncStateMachineBox>(obj);
                if (asyncStateMachineBox2 == nullptr) {
                  Action<> action2 = rt::as<Action<>>(obj);
                  if (action2 != nullptr) {
                    AwaitTaskContinuation::in::RunOrScheduleAction(action2, false);
                  } else {
                    ((TaskContinuation)obj)->Run((Task<>)this, false);
                  }
                } else {
                  AwaitTaskContinuation::in::RunOrScheduleAction(asyncStateMachineBox2, false);
                }
              }
              flag2 = true;
            }
          }
        }
        for (Int32 j = 0; j < count; j++) {
          Object obj2 = list[j];
          if (obj2 == nullptr) {
            continue;
          }
          list[j] = nullptr;
          if (tplEventSource != nullptr) {
            tplEventSource->RunningContinuationList(get_Id(), j, obj2);
          }
          IAsyncStateMachineBox asyncStateMachineBox3 = rt::as<IAsyncStateMachineBox>(obj2);
          if (asyncStateMachineBox3 == nullptr) {
            Action<> action3 = rt::as<Action<>>(obj2);
            if (action3 == nullptr) {
              TaskContinuation taskContinuation2 = rt::as<TaskContinuation>(obj2);
              if (taskContinuation2 != nullptr) {
                taskContinuation2->Run((Task<>)this, flag);
              } else {
                RunOrQueueCompletionAction((ITaskCompletionAction)obj2, flag);
              }
            } else {
              AwaitTaskContinuation::in::RunOrScheduleAction(action3, flag);
            }
          } else {
            AwaitTaskContinuation::in::RunOrScheduleAction(asyncStateMachineBox3, flag);
          }
        }
        LogFinishCompletionNotification();
      } else {
        taskContinuation->Run((Task<>)this, flag);
        LogFinishCompletionNotification();
      }
    } else {
      AwaitTaskContinuation::in::RunOrScheduleAction(action, flag);
      LogFinishCompletionNotification();
    }
  } else {
    AwaitTaskContinuation::in::RunOrScheduleAction(asyncStateMachineBox, flag);
    LogFinishCompletionNotification();
  }
}

void Task___<>::RunOrQueueCompletionAction(ITaskCompletionAction completionAction, Boolean allowInlining) {
  if (allowInlining || !completionAction->get_InvokeMayRunArbitraryCode()) {
    completionAction->Invoke((Task<>)this);
  } else {
    ThreadPool::UnsafeQueueUserWorkItemInternal(rt::newobj<CompletionActionInvoker>(completionAction, (Task<>)this), true);
  }
}

void Task___<>::LogFinishCompletionNotification() {
  Boolean loggingOn = AsyncCausalityTracer::get_LoggingOn();
}

Task<> Task___<>::ContinueWith(Action<Task<>> continuationAction) {
  return ContinueWith(continuationAction, TaskScheduler::in::get_Current(), CancellationToken(), TaskContinuationOptions::None);
}

Task<> Task___<>::ContinueWith(Action<Task<>> continuationAction, CancellationToken cancellationToken) {
  return ContinueWith(continuationAction, TaskScheduler::in::get_Current(), cancellationToken, TaskContinuationOptions::None);
}

Task<> Task___<>::ContinueWith(Action<Task<>> continuationAction, TaskScheduler scheduler) {
  return ContinueWith(continuationAction, scheduler, CancellationToken(), TaskContinuationOptions::None);
}

Task<> Task___<>::ContinueWith(Action<Task<>> continuationAction, TaskContinuationOptions continuationOptions) {
  return ContinueWith(continuationAction, TaskScheduler::in::get_Current(), CancellationToken(), continuationOptions);
}

Task<> Task___<>::ContinueWith(Action<Task<>> continuationAction, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler) {
  return ContinueWith(continuationAction, scheduler, cancellationToken, continuationOptions);
}

Task<> Task___<>::ContinueWith(Action<Task<>> continuationAction, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions) {
  if (continuationAction == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::continuationAction);
  }
  if (scheduler == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::scheduler);
  }
  TaskCreationOptions creationOptions;
  InternalTaskOptions internalOptions;
  CreationOptionsFromContinuationOptions(continuationOptions, creationOptions, internalOptions);
  Task<> task = rt::newobj<ContinuationTaskFromTask>((Task<>)this, continuationAction, nullptr, creationOptions, internalOptions);
  ContinueWithCore(task, scheduler, cancellationToken, continuationOptions);
  return task;
}

Task<> Task___<>::ContinueWith(Action<Task<>, Object> continuationAction, Object state) {
  return ContinueWith(continuationAction, state, TaskScheduler::in::get_Current(), CancellationToken(), TaskContinuationOptions::None);
}

Task<> Task___<>::ContinueWith(Action<Task<>, Object> continuationAction, Object state, CancellationToken cancellationToken) {
  return ContinueWith(continuationAction, state, TaskScheduler::in::get_Current(), cancellationToken, TaskContinuationOptions::None);
}

Task<> Task___<>::ContinueWith(Action<Task<>, Object> continuationAction, Object state, TaskScheduler scheduler) {
  return ContinueWith(continuationAction, state, scheduler, CancellationToken(), TaskContinuationOptions::None);
}

Task<> Task___<>::ContinueWith(Action<Task<>, Object> continuationAction, Object state, TaskContinuationOptions continuationOptions) {
  return ContinueWith(continuationAction, state, TaskScheduler::in::get_Current(), CancellationToken(), continuationOptions);
}

Task<> Task___<>::ContinueWith(Action<Task<>, Object> continuationAction, Object state, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions, TaskScheduler scheduler) {
  return ContinueWith(continuationAction, state, scheduler, cancellationToken, continuationOptions);
}

Task<> Task___<>::ContinueWith(Action<Task<>, Object> continuationAction, Object state, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions continuationOptions) {
  if (continuationAction == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::continuationAction);
  }
  if (scheduler == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::scheduler);
  }
  TaskCreationOptions creationOptions;
  InternalTaskOptions internalOptions;
  CreationOptionsFromContinuationOptions(continuationOptions, creationOptions, internalOptions);
  Task<> task = rt::newobj<ContinuationTaskFromTask>((Task<>)this, continuationAction, state, creationOptions, internalOptions);
  ContinueWithCore(task, scheduler, cancellationToken, continuationOptions);
  return task;
}

void Task___<>::CreationOptionsFromContinuationOptions(TaskContinuationOptions continuationOptions, TaskCreationOptions& creationOptions, InternalTaskOptions& internalOptions) {
  if ((continuationOptions & (TaskContinuationOptions::LongRunning | TaskContinuationOptions::ExecuteSynchronously)) == (TaskContinuationOptions::LongRunning | TaskContinuationOptions::ExecuteSynchronously)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::continuationOptions, ExceptionResource::Task_ContinueWith_ESandLR);
  }
  if ((continuationOptions & ~(TaskContinuationOptions::PreferFairness | TaskContinuationOptions::LongRunning | TaskContinuationOptions::AttachedToParent | TaskContinuationOptions::DenyChildAttach | TaskContinuationOptions::HideScheduler | TaskContinuationOptions::LazyCancellation | TaskContinuationOptions::RunContinuationsAsynchronously | TaskContinuationOptions::NotOnRanToCompletion | TaskContinuationOptions::NotOnFaulted | TaskContinuationOptions::NotOnCanceled | TaskContinuationOptions::ExecuteSynchronously)) != 0) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::continuationOptions);
  }
  if ((continuationOptions & (TaskContinuationOptions::NotOnRanToCompletion | TaskContinuationOptions::NotOnFaulted | TaskContinuationOptions::NotOnCanceled)) == (TaskContinuationOptions::NotOnRanToCompletion | TaskContinuationOptions::NotOnFaulted | TaskContinuationOptions::NotOnCanceled)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::continuationOptions, ExceptionResource::Task_ContinueWith_NotOnAnything);
  }
  creationOptions = (TaskCreationOptions)(continuationOptions & (TaskContinuationOptions::PreferFairness | TaskContinuationOptions::LongRunning | TaskContinuationOptions::AttachedToParent | TaskContinuationOptions::DenyChildAttach | TaskContinuationOptions::HideScheduler | TaskContinuationOptions::RunContinuationsAsynchronously));
  internalOptions = (((continuationOptions & TaskContinuationOptions::LazyCancellation) != 0) ? (InternalTaskOptions::ContinuationTask | InternalTaskOptions::LazyCancellation) : InternalTaskOptions::ContinuationTask);
}

void Task___<>::ContinueWithCore(Task<> continuationTask, TaskScheduler scheduler, CancellationToken cancellationToken, TaskContinuationOptions options) {
  TaskContinuation taskContinuation = rt::newobj<ContinueWithTaskContinuation>(continuationTask, options, scheduler);
  if (cancellationToken.get_CanBeCanceled()) {
    if (get_IsCompleted() || cancellationToken.get_IsCancellationRequested()) {
      continuationTask->AssignCancellationToken(cancellationToken, nullptr, nullptr);
    } else {
      continuationTask->AssignCancellationToken(cancellationToken, (Task<>)this, taskContinuation);
    }
  }
  if (continuationTask->get_IsCompleted()) {
    return;
  }
  if ((get_Options() & (TaskCreationOptions)1024) != 0 && !rt::is<ITaskCompletionAction>((Task<>)this)) {
    TplEventSource log = TplEventSource::in::Log;
    if (log->IsEnabled()) {
      log->AwaitTaskContinuationScheduled(TaskScheduler::in::get_Current()->get_Id(), get_CurrentId().GetValueOrDefault(), continuationTask->get_Id());
    }
  }
  if (!AddTaskContinuation(taskContinuation, false)) {
    taskContinuation->Run((Task<>)this, true);
  }
}

void Task___<>::AddCompletionAction(ITaskCompletionAction action, Boolean addBeforeOthers) {
  if (!AddTaskContinuation(action, addBeforeOthers)) {
    action->Invoke((Task<>)this);
  }
}

Boolean Task___<>::AddTaskContinuationComplex(Object tc, Boolean addBeforeOthers) {
  Object continuationObject = m_continuationObject;
  if (continuationObject != s_taskCompletionSentinel && !rt::is<List<Object>>(continuationObject)) {
    Interlocked::CompareExchange(m_continuationObject, rt::newobj<List<Object>>(), continuationObject);
  }
  List<Object> list = rt::as<List<Object>>(m_continuationObject);
  if (list != nullptr) {
    {
      rt::lock(list);
      if (m_continuationObject != s_taskCompletionSentinel) {
        if (list->get_Count() == list->get_Capacity()) {
        }
        if (addBeforeOthers) {
          list->Insert(0, tc);
        } else {
          list->Add(tc);
        }
        return true;
      }
    }
  }
  return false;
}

Boolean Task___<>::AddTaskContinuation(Object tc, Boolean addBeforeOthers) {
  if (get_IsCompleted()) {
    return false;
  }
  if (m_continuationObject != nullptr || Interlocked::CompareExchange(m_continuationObject, tc, nullptr) != nullptr) {
    return AddTaskContinuationComplex(tc, addBeforeOthers);
  }
  return true;
}

void Task___<>::RemoveContinuation(Object continuationObject) {
  Object continuationObject2 = m_continuationObject;
  if (continuationObject2 == s_taskCompletionSentinel) {
    return;
  }
  List<Object> list = rt::as<List<Object>>(continuationObject2);
  if (list == nullptr) {
    if (Interlocked::CompareExchange(m_continuationObject, rt::newobj<List<Object>>(), continuationObject) == continuationObject) {
      return;
    }
    list = (rt::as<List<Object>>(m_continuationObject));
  }
  if (list == nullptr) {
    return;
  }
  {
    rt::lock(list);
    if (m_continuationObject != s_taskCompletionSentinel) {
      Int32 num = list->IndexOf(continuationObject);
      if (num != -1) {
        list[num] = nullptr;
      }
    }
  }
}

void Task___<>::WaitAll(Array<Task<>> tasks) {
  WaitAllCore(tasks, -1, CancellationToken());
}

Boolean Task___<>::WaitAll(Array<Task<>> tasks, TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::timeout);
  }
  return WaitAllCore(tasks, (Int32)num, CancellationToken());
}

Boolean Task___<>::WaitAll(Array<Task<>> tasks, Int32 millisecondsTimeout) {
  return WaitAllCore(tasks, millisecondsTimeout, CancellationToken());
}

void Task___<>::WaitAll(Array<Task<>> tasks, CancellationToken cancellationToken) {
  WaitAllCore(tasks, -1, cancellationToken);
}

Boolean Task___<>::WaitAll(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return WaitAllCore(tasks, millisecondsTimeout, cancellationToken);
}

Boolean Task___<>::WaitAllCore(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  if (tasks == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::tasks);
  }
  if (millisecondsTimeout < -1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::millisecondsTimeout);
  }
  cancellationToken.ThrowIfCancellationRequested();
  List<Exception> exceptions = nullptr;
  List<Task<>> list = nullptr;
  List<Task<>> list2 = nullptr;
  Boolean flag = false;
  Boolean flag2 = false;
  Boolean flag3 = true;
  for (Int32 num = tasks->get_Length() - 1; num >= 0; num--) {
    Task<> task = tasks[num];
    if (task == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::Task_WaitMulti_NullTask, ExceptionArgument::tasks);
    }
    Boolean flag4 = task->get_IsCompleted();
    if (!flag4) {
      if (millisecondsTimeout != -1 || cancellationToken.get_CanBeCanceled()) {
        AddToList(task, list, tasks->get_Length());
      } else {
        flag4 = (task->WrappedTryRunInline() && task->get_IsCompleted());
        if (!flag4) {
          AddToList(task, list, tasks->get_Length());
        }
      }
    }
    if (flag4) {
      if (task->get_IsFaulted()) {
        flag = true;
      } else if (task->get_IsCanceled()) {
        flag2 = true;
      }

      if (task->get_IsWaitNotificationEnabled()) {
        AddToList(task, list2, 1);
      }
    }
  }
  if (list != nullptr) {
    flag3 = WaitAllBlockingCore(list, millisecondsTimeout, cancellationToken);
    if (flag3) {
      for (Task<>& item : list) {
        if (item->get_IsFaulted()) {
          flag = true;
        } else if (item->get_IsCanceled()) {
          flag2 = true;
        }

        if (item->get_IsWaitNotificationEnabled()) {
          AddToList(item, list2, 1);
        }
      }
    }
    GC::KeepAlive(tasks);
  }
  if (flag3 && list2 != nullptr) {
    for (Task<>& item2 : list2) {
      if (item2->NotifyDebuggerOfWaitCompletionIfNecessary()) {
        break;
      }
    }
  }
  if (flag3 && (flag || flag2)) {
    if (!flag) {
      cancellationToken.ThrowIfCancellationRequested();
    }
    for (Task<>& t : tasks) {
      AddExceptionsForCompletedTask(exceptions, t);
    }
    ThrowHelper::ThrowAggregateException(exceptions);
  }
  return flag3;
}

Boolean Task___<>::WaitAllBlockingCore(List<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  Boolean flag = false;
  SetOnCountdownMres setOnCountdownMres = rt::newobj<SetOnCountdownMres>(tasks->get_Count());
  try {
    for (Task<>& task : tasks) {
      task->AddCompletionAction(setOnCountdownMres, true);
    }
    flag = setOnCountdownMres->Wait(millisecondsTimeout, cancellationToken);
  } catch (...) {
  } finally: {
    if (!flag) {
      for (Task<>& task2 : tasks) {
        if (!task2->get_IsCompleted()) {
          task2->RemoveContinuation(setOnCountdownMres);
        }
      }
    }
  }
  return flag;
}

void Task___<>::AddExceptionsForCompletedTask(List<Exception>& exceptions, Task<> t) {
  AggregateException exceptions2 = t->GetExceptions(true);
  if (exceptions2 != nullptr) {
    t->UpdateExceptionObservedStatus();
    if (exceptions == nullptr) {
      exceptions = rt::newobj<List<Exception>>(exceptions2->get_InnerExceptions()->get_Count());
    }
    exceptions->AddRange(exceptions2->get_InnerExceptions());
  }
}

Int32 Task___<>::WaitAny(Array<Task<>> tasks) {
  return WaitAnyCore(tasks, -1, CancellationToken());
}

Int32 Task___<>::WaitAny(Array<Task<>> tasks, TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::timeout);
  }
  return WaitAnyCore(tasks, (Int32)num, CancellationToken());
}

Int32 Task___<>::WaitAny(Array<Task<>> tasks, CancellationToken cancellationToken) {
  return WaitAnyCore(tasks, -1, cancellationToken);
}

Int32 Task___<>::WaitAny(Array<Task<>> tasks, Int32 millisecondsTimeout) {
  return WaitAnyCore(tasks, millisecondsTimeout, CancellationToken());
}

Int32 Task___<>::WaitAny(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  return WaitAnyCore(tasks, millisecondsTimeout, cancellationToken);
}

Int32 Task___<>::WaitAnyCore(Array<Task<>> tasks, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  if (tasks == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::tasks);
  }
  if (millisecondsTimeout < -1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::millisecondsTimeout);
  }
  cancellationToken.ThrowIfCancellationRequested();
  Int32 num = -1;
  for (Int32 i = 0; i < tasks->get_Length(); i++) {
    Task<> task = tasks[i];
    if (task == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::Task_WaitMulti_NullTask, ExceptionArgument::tasks);
    }
    if (num == -1 && task->get_IsCompleted()) {
      num = i;
    }
  }
  if (num == -1 && tasks->get_Length() != 0) {
    Task<Task<>> task2 = TaskFactory<>::in::CommonCWAnyLogic(tasks, true);
    if (task2->Wait(millisecondsTimeout, cancellationToken)) {
      num = Array<>::in::IndexOf(tasks, task2->get_Result());
    } else {
      TaskFactory<>::in::CommonCWAnyLogicCleanup(task2);
    }
  }
  GC::KeepAlive(tasks);
  return num;
}

Task<> Task___<>::FromException(Exception exception) {
  if (exception == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::exception);
  }
  Task<> task = rt::newobj<Task<>>();
  Boolean flag = task->TrySetException(exception);
  return task;
}

Task<> Task___<>::FromCanceled(CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::cancellationToken);
  }
  return rt::newobj<Task<>>(true, TaskCreationOptions::None, cancellationToken);
}

Task<> Task___<>::FromCanceled(OperationCanceledException exception) {
  Task<> task = rt::newobj<Task<>>();
  Boolean flag = task->TrySetCanceled(exception->get_CancellationToken(), exception);
  return task;
}

Task<> Task___<>::Run(Action<> action) {
  return InternalStartNew(nullptr, action, nullptr, CancellationToken(), TaskScheduler::in::get_Default(), TaskCreationOptions::DenyChildAttach, InternalTaskOptions::None);
}

Task<> Task___<>::Run(Action<> action, CancellationToken cancellationToken) {
  return InternalStartNew(nullptr, action, nullptr, cancellationToken, TaskScheduler::in::get_Default(), TaskCreationOptions::DenyChildAttach, InternalTaskOptions::None);
}

Task<> Task___<>::Run(Func<Task<>> function) {
  return Run(function, CancellationToken());
}

Task<> Task___<>::Run(Func<Task<>> function, CancellationToken cancellationToken) {
  if (function == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::function);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return FromCanceled(cancellationToken);
  }
  Task<Task<>> outerTask = Task<Task<>>::in::get_Factory()->StartNew(function, cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
  return rt::newobj<UnwrapPromise<VoidTaskResult>>(outerTask, true);
}

Task<> Task___<>::Delay(TimeSpan delay) {
  return Delay(delay, CancellationToken());
}

Task<> Task___<>::Delay(TimeSpan delay, CancellationToken cancellationToken) {
  Int64 num = (Int64)delay.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::delay, ExceptionResource::Task_Delay_InvalidDelay);
  }
  return Delay((Int32)num, cancellationToken);
}

Task<> Task___<>::Delay(Int32 millisecondsDelay) {
  return Delay(millisecondsDelay, CancellationToken());
}

Task<> Task___<>::Delay(Int32 millisecondsDelay, CancellationToken cancellationToken) {
  if (millisecondsDelay < -1) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::millisecondsDelay, ExceptionResource::Task_Delay_InvalidMillisecondsDelay);
  }
  if (!cancellationToken.get_IsCancellationRequested()) {
    if (millisecondsDelay != 0) {
      if (!cancellationToken.get_CanBeCanceled()) {
        return rt::newobj<DelayPromise>(millisecondsDelay);
      }
      return rt::newobj<DelayPromiseWithCancellation>(millisecondsDelay, cancellationToken);
    }
    return get_CompletedTask();
  }
  return FromCanceled(cancellationToken);
}

Task<> Task___<>::WhenAll(IEnumerable<Task<>> tasks) {
  Array<Task<>> array = rt::as<Array<Task<>>>(tasks);
  if (array != nullptr) {
    return WhenAll(array);
  }
  ICollection<Task<>> collection = rt::as<ICollection<Task<>>>(tasks);
  if (collection != nullptr) {
    Int32 num = 0;
    array = rt::newarr<Array<Task<>>>(collection->get_Count());
    for (Task<>& task : tasks) {
      if (task == nullptr) {
        ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_NullTask, ExceptionArgument::tasks);
      }
      array[num++] = task;
    }
    return InternalWhenAll(array);
  }
  if (tasks == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::tasks);
  }
  List<Task<>> list = rt::newobj<List<Task<>>>();
  for (Task<>& task2 : tasks) {
    if (task2 == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_NullTask, ExceptionArgument::tasks);
    }
    list->Add(task2);
  }
  return InternalWhenAll(list->ToArray());
}

Task<> Task___<>::WhenAll(Array<Task<>> tasks) {
  if (tasks == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::tasks);
  }
  Int32 num = tasks->get_Length();
  if (num == 0) {
    return InternalWhenAll(tasks);
  }
  Array<Task<>> array = rt::newarr<Array<Task<>>>(num);
  for (Int32 i = 0; i < num; i++) {
    Task<> task = tasks[i];
    if (task == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_NullTask, ExceptionArgument::tasks);
    }
    array[i] = task;
  }
  return InternalWhenAll(array);
}

Task<> Task___<>::InternalWhenAll(Array<Task<>> tasks) {
  if (tasks->get_Length() != 0) {
    return rt::newobj<WhenAllPromise<>>(tasks);
  }
  return get_CompletedTask();
}

Task<Task<>> Task___<>::WhenAny(Array<Task<>> tasks) {
  if (tasks == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::tasks);
  }
  if (tasks->get_Length() == 2) {
    return WhenAny(tasks[0], tasks[1]);
  }
  if (tasks->get_Length() == 0) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_EmptyTaskList, ExceptionArgument::tasks);
  }
  Int32 num = tasks->get_Length();
  Array<Task<>> array = rt::newarr<Array<Task<>>>(num);
  for (Int32 i = 0; i < num; i++) {
    Task<> task = tasks[i];
    if (task == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_NullTask, ExceptionArgument::tasks);
    }
    array[i] = task;
  }
  return TaskFactory<>::in::CommonCWAnyLogic(array);
}

Task<Task<>> Task___<>::WhenAny(Task<> task1, Task<> task2) {
  if (task1 != nullptr && task2 != nullptr) {
    if (!task1->get_IsCompleted()) {
      if (!task2->get_IsCompleted()) {
        return rt::newobj<TwoTaskWhenAnyPromise<Task<>>>(task1, task2);
      }
      return FromResult(task2);
    }
    return FromResult(task1);
  }
  rt::throw_exception<ArgumentNullException>((task1 == nullptr) ? "task1" : "task2");
}

Task<Task<>> Task___<>::WhenAny(IEnumerable<Task<>> tasks) {
  if (tasks == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::tasks);
  }
  List<Task<>> list = rt::newobj<List<Task<>>>();
  for (Task<>& task : tasks) {
    if (task == nullptr) {
      ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_NullTask, ExceptionArgument::tasks);
    }
    list->Add(task);
  }
  if (list->get_Count() == 0) {
    ThrowHelper::ThrowArgumentException(ExceptionResource::Task_MultiTaskContinuation_EmptyTaskList, ExceptionArgument::tasks);
  }
  return TaskFactory<>::in::CommonCWAnyLogic(list);
}

Array<Delegate> Task___<>::GetDelegateContinuationsForDebugger() {
  if (m_continuationObject != (Task<>)this) {
    return GetDelegatesFromContinuationObject(m_continuationObject);
  }
  return nullptr;
}

Array<Delegate> Task___<>::GetDelegatesFromContinuationObject(Object continuationObject) {
  if (continuationObject != nullptr) {
    Action<> action = rt::as<Action<>>(continuationObject);
    if (action != nullptr) {
      return rt::newarr<Array<Delegate>>(1);
    }
    TaskContinuation taskContinuation = rt::as<TaskContinuation>(continuationObject);
    if (taskContinuation != nullptr) {
      return taskContinuation->GetDelegateContinuationsForDebugger();
    }
    Task<> task = rt::as<Task<>>(continuationObject);
    if (task != nullptr) {
      Array<Delegate> delegateContinuationsForDebugger = task->GetDelegateContinuationsForDebugger();
      if (delegateContinuationsForDebugger != nullptr) {
        return delegateContinuationsForDebugger;
      }
    }
    ITaskCompletionAction taskCompletionAction = rt::as<ITaskCompletionAction>(continuationObject);
    if (taskCompletionAction != nullptr) {
      return rt::newarr<Array<Delegate>>(1);
    }
    List<Object> list = rt::as<List<Object>>(continuationObject);
    if (list != nullptr) {
      List<Delegate> list2 = rt::newobj<List<Delegate>>();
      for (Object& item : list) {
        Array<Delegate> delegatesFromContinuationObject = GetDelegatesFromContinuationObject(item);
        if (delegatesFromContinuationObject == nullptr) {
          continue;
        }
        Array<Delegate> array = delegatesFromContinuationObject;
        for (Delegate& delegate : array) {
          if ((Object)delegate != nullptr) {
            list2->Add(delegate);
          }
        }
      }
      return list2->ToArray();
    }
  }
  return nullptr;
}

Task<> Task___<>::GetActiveTaskFromId(Int32 taskId) {
  Task<> value = nullptr;
  Dictionary<Int32, Task<>> dictionary = s_currentActiveTasks;
  if (dictionary != nullptr) {
    dictionary->TryGetValue(taskId, value);
  }
  return value;
}

void Task___<>::cctor() {
  s_taskCompletionSentinel = rt::newobj<Object>();
  Factory = rt::newobj<TaskFactory<>>();
  s_cachedCompleted = rt::newobj<Task<VoidTaskResult>>(false, VoidTaskResult(), (TaskCreationOptions)16384, CancellationToken());
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace
