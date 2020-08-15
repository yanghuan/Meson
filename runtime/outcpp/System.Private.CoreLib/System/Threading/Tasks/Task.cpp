#include "Task-dep.h"

#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace {
void DelayPromise___::ctor(Int32 millisecondsDelay) {
  _ = AsyncCausalityTracer::get_LoggingOn();
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
    _ = AsyncCausalityTracer::get_LoggingOn();
  }
}

void DelayPromise___::Cleanup() {
  auto& default = _timer;
  default == nullptr ? nullptr : default->Close();
}

void Task___<>::ContingentProperties___::SetCompleted() {
  auto& default = m_completionEvent;
  default == nullptr ? nullptr : default->Set();
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
  Task::in::DelayPromise::in::Cleanup();
}

Boolean WhenAllPromise___<>::get_InvokeMayRunArbitraryCode() {
  return true;
}

Boolean WhenAllPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  if (Task::in::get_ShouldNotifyDebuggerOfWaitCompletion()) {
    return AnyTaskRequiresNotifyDebuggerOfWaitCompletion(m_tasks);
  }
  return false;
}

Task<> Task___<>::get_ParentForDebugger() {
  auto& default = m_contingentProperties;
  return default == nullptr ? nullptr : default->m_parent;
}

Int32 Task___<>::get_StateFlagsForDebugger() {
  return m_stateFlags;
}

String Task___<>::get_DebuggerDisplayMethodDescription() {
  auto& default = m_action;
  auto& extern = default == nullptr ? nullptr : default->get_Method()->ToString();
  return extern != nullptr ? extern : "{null}";
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
  auto& default = get_InternalCurrent();
  return default == nullptr ? nullptr : default->get_Id();
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
  auto& default = Volatile::Read(m_contingentProperties);
  auto& extern = default == nullptr ? nullptr : default->m_cancellationToken;
  return extern != nullptr ? extern : CancellationToken();
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
    if (Interlocked::CompareExchange(contingentProperties->m_completionEvent, manualResetEventSlim, nullptr) != nullptr) {
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
  auto& default = m_contingentProperties;
  auto& extern = default == nullptr ? nullptr : default->m_capturedContext;
  return extern != nullptr ? extern : ExecutionContext::in::Default;
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

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace
