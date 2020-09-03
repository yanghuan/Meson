#include "AwaitTaskContinuation-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/AwaitTaskContinuation-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/InternalTaskOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::AwaitTaskContinuationNamespace {
Boolean AwaitTaskContinuation___::get_IsValidLocationForInlining() {
  SynchronizationContext current = SynchronizationContext::in::get_Current();
  if (current != nullptr && current->GetType() != typeof<SynchronizationContext>()) {
    return false;
  }
  TaskScheduler internalCurrent = TaskScheduler::in::get_InternalCurrent();
  if (internalCurrent != nullptr) {
    return internalCurrent == TaskScheduler::in::get_Default();
  }
  return true;
}

void AwaitTaskContinuation___::ctor(Action<> action, Boolean flowExecutionContext) {
  m_action = action;
  if (flowExecutionContext) {
    m_capturedContext = ExecutionContext::in::Capture();
  }
}

Task<> AwaitTaskContinuation___::CreateTask(Action<Object> action, Object state, TaskScheduler scheduler) {
  return rt::newobj<Task<>>(action, state, nullptr, rt::default__, TaskCreationOptions::None, InternalTaskOptions::QueuedByRuntime, scheduler);
}

void AwaitTaskContinuation___::Run(Task<> task, Boolean canInlineContinuationTask) {
  if (canInlineContinuationTask && get_IsValidLocationForInlining()) {
    RunCallback(GetInvokeActionCallback(), m_action, Task<>::in::t_currentTask);
    return;
  }
  TplEventSource log = TplEventSource::in::Log;
  if (log->IsEnabled()) {
    m_continuationId = Task<>::in::NewId();
    TaskScheduler as = task->get_ExecutingTaskScheduler();
    log->AwaitTaskContinuationScheduled((as != nullptr ? as : TaskScheduler::in::get_Default())->get_Id(), task->get_Id(), m_continuationId);
  }
  ThreadPool::UnsafeQueueUserWorkItemInternal((AwaitTaskContinuation)this, true);
}

ContextCallback<> AwaitTaskContinuation___::GetInvokeActionCallback() {
  return s_invokeContextCallback;
}

void AwaitTaskContinuation___::RunCallback(ContextCallback<> callback, Object state, Task<>& currentTask) {
  Task<> task = currentTask;
  try {
    if (task != nullptr) {
      currentTask = nullptr;
    }
    ExecutionContext capturedContext = m_capturedContext;
    if (capturedContext == nullptr) {
      callback(state);
    } else {
      ExecutionContext::in::RunInternal(capturedContext, callback, state);
    }
  } catch (Exception exception) {
    Task<>::in::ThrowAsync(exception, nullptr);
  } finally: {
    if (task != nullptr) {
      currentTask = task;
    }
  }
}

void AwaitTaskContinuation___::RunOrScheduleAction(Action<> action, Boolean allowInlining) {
  Task<> t_currentTask = Task<>::in::t_currentTask;
  if (!allowInlining || !get_IsValidLocationForInlining()) {
    UnsafeScheduleAction(action, t_currentTask);
    return;
  }
  try {
    if (t_currentTask != nullptr) {
      Task<>::in::t_currentTask = nullptr;
    }
    action();
  } catch (Exception exception) {
    Task<>::in::ThrowAsync(exception, nullptr);
  } finally: {
    if (t_currentTask != nullptr) {
      Task<>::in::t_currentTask = t_currentTask;
    }
  }
}

void AwaitTaskContinuation___::RunOrScheduleAction(IAsyncStateMachineBox box, Boolean allowInlining) {
  Task<> t_currentTask = Task<>::in::t_currentTask;
  if (!allowInlining || !get_IsValidLocationForInlining()) {
    if (TplEventSource::in::Log->IsEnabled()) {
      UnsafeScheduleAction(box->get_MoveNextAction(), t_currentTask);
    } else {
      ThreadPool::UnsafeQueueUserWorkItemInternal(box, true);
    }
    return;
  }
  try {
    if (t_currentTask != nullptr) {
      Task<>::in::t_currentTask = nullptr;
    }
    box->MoveNext();
  } catch (Exception exception) {
    Task<>::in::ThrowAsync(exception, nullptr);
  } finally: {
    if (t_currentTask != nullptr) {
      Task<>::in::t_currentTask = t_currentTask;
    }
  }
}

void AwaitTaskContinuation___::UnsafeScheduleAction(Action<> action, Task<> task) {
  AwaitTaskContinuation awaitTaskContinuation = rt::newobj<AwaitTaskContinuation>(action, false);
  TplEventSource log = TplEventSource::in::Log;
  if (log->IsEnabled() && task != nullptr) {
    awaitTaskContinuation->m_continuationId = Task<>::in::NewId();
    TaskScheduler as = task->get_ExecutingTaskScheduler();
    log->AwaitTaskContinuationScheduled((as != nullptr ? as : TaskScheduler::in::get_Default())->get_Id(), task->get_Id(), awaitTaskContinuation->m_continuationId);
  }
  ThreadPool::UnsafeQueueUserWorkItemInternal(awaitTaskContinuation, true);
}

Array<Delegate> AwaitTaskContinuation___::GetDelegateContinuationsForDebugger() {
  return rt::newarr<Array<Delegate>>(1);
}

void AwaitTaskContinuation___::cctor() {
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::AwaitTaskContinuationNamespace
