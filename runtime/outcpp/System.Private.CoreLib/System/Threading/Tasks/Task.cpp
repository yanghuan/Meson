#include "Task-dep.h"

#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AsyncCausalityTracer-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerQueueTimer-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

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
}

void Task___<>::ContingentProperties___::SetCompleted() {
}

void Task___<>::ContingentProperties___::UnregisterCancellationCallback() {
  if (m_cancellationRegistration != nullptr) {
    try{
      m_cancellationRegistration->Value.Dispose();
    } catch (ObjectDisposedException) {
    }
    m_cancellationRegistration = nullptr;
  }
}

void Task___<>::ContingentProperties___::ctor() {
  m_completionCountdown = 1;
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
}

Boolean WhenAllPromise___<>::get_InvokeMayRunArbitraryCode() {
  return true;
}

Boolean WhenAllPromise___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
}

Task<> Task___<>::get_ParentForDebugger() {
}

Int32 Task___<>::get_StateFlagsForDebugger() {
  return m_stateFlags;
}

String Task___<>::get_DebuggerDisplayMethodDescription() {
}

TaskCreationOptions Task___<>::get_Options() {
  return OptionsMethod(m_stateFlags);
}

Boolean Task___<>::get_IsWaitNotificationEnabledOrNotRanToCompletion() {
}

Boolean Task___<>::get_ShouldNotifyDebuggerOfWaitCompletion() {
  return get_IsWaitNotificationEnabled();
}

Boolean Task___<>::get_IsWaitNotificationEnabled() {
}

Int32 Task___<>::get_Id() {
  if (m_taskId == 0) {
    Int32 value = NewId();
    Interlocked::CompareExchange(m_taskId, value, 0);
  }
  return m_taskId;
}

Nullable<Int32> Task___<>::get_CurrentId() {
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
}

Boolean Task___<>::get_IsCanceled() {
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
}

Boolean Task___<>::get_IsCancellationAcknowledged() {
}

Boolean Task___<>::get_IsCompleted() {
  Int32 stateFlags = m_stateFlags;
  return IsCompletedMethod(stateFlags);
}

Boolean Task___<>::get_IsCompletedSuccessfully() {
}

TaskCreationOptions Task___<>::get_CreationOptions() {
}

WaitHandle Task___<>::get_AsyncWaitHandleOfIAsyncResult() {
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
}

ExecutionContext Task___<>::get_CapturedContext() {
}

void Task___<>::set_CapturedContext(ExecutionContext value) {
  if (value == nullptr) {
    m_stateFlags |= 536870912;
  } else if (value != ExecutionContext::in::Default) {
    EnsureContingentPropertiesInitializedUnsafe()->m_capturedContext = value;
  }

}

Boolean Task___<>::get_IsExceptionObservedByParent() {
}

Boolean Task___<>::get_IsDelegateInvoked() {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskNamespace
