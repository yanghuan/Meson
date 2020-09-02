#include "TaskScheduler-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Debugger-dep.h>
#include <System.Private.CoreLib/System/EventHandler-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConditionalWeakTable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/SynchronizationContextTaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ThreadPoolTaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TplEventSource-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerNamespace {
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
using namespace System::Runtime::CompilerServices;

Int32 TaskScheduler___::SystemThreadingTasks_TaskSchedulerDebugView___::get_Id() {
  return m_taskScheduler->get_Id();
}

IEnumerable<Task<>> TaskScheduler___::SystemThreadingTasks_TaskSchedulerDebugView___::get_ScheduledTasks() {
  return m_taskScheduler->GetScheduledTasks();
}

void TaskScheduler___::SystemThreadingTasks_TaskSchedulerDebugView___::ctor(TaskScheduler scheduler) {
  m_taskScheduler = scheduler;
}

Int32 TaskScheduler___::get_MaximumConcurrencyLevel() {
  return Int32::MaxValue;
}

TaskScheduler TaskScheduler___::get_Default() {
  return s_defaultTaskScheduler;
}

TaskScheduler TaskScheduler___::get_Current() {
  TaskScheduler as = get_InternalCurrent();
  return as != nullptr ? as : get_Default();
}

TaskScheduler TaskScheduler___::get_InternalCurrent() {
  Task<> internalCurrent = Task<>::in::get_InternalCurrent();
  if (internalCurrent == nullptr || (internalCurrent->get_CreationOptions() & TaskCreationOptions::HideScheduler) != 0) {
    return nullptr;
  }
  return internalCurrent->get_ExecutingTaskScheduler();
}

Int32 TaskScheduler___::get_Id() {
  if (m_taskSchedulerId == 0) {
    Int32 num;
    do {
      num = Interlocked::Increment(s_taskSchedulerIdCounter);
    } while (num == 0)
    Interlocked::CompareExchange(m_taskSchedulerId, num, 0);
  }
  return m_taskSchedulerId;
}

Boolean TaskScheduler___::TryRunInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  TaskScheduler executingTaskScheduler = task->get_ExecutingTaskScheduler();
  if (executingTaskScheduler != (TaskScheduler)this && executingTaskScheduler != nullptr) {
    return executingTaskScheduler->TryRunInline(task, taskWasPreviouslyQueued);
  }
  if (executingTaskScheduler == nullptr || (Object)task->m_action == nullptr || task->get_IsDelegateInvoked() || task->get_IsCanceled() || !RuntimeHelpers::TryEnsureSufficientExecutionStack()) {
    return false;
  }
  if (TplEventSource::in::Log->IsEnabled()) {
    task->FireTaskScheduledIfNeeded((TaskScheduler)this);
  }
  Boolean flag = TryExecuteTaskInline(task, taskWasPreviouslyQueued);
  if (flag && !task->get_IsDelegateInvoked() && !task->get_IsCanceled()) {
    rt::throw_exception<InvalidOperationException>(SR::get_TaskScheduler_InconsistentStateAfterTryExecuteTaskInline());
  }
  return flag;
}

Boolean TaskScheduler___::TryDequeue(Task<> task) {
  return false;
}

void TaskScheduler___::NotifyWorkItemProgress() {
}

void TaskScheduler___::InternalQueueTask(Task<> task) {
  if (TplEventSource::in::Log->IsEnabled()) {
    task->FireTaskScheduledIfNeeded((TaskScheduler)this);
  }
  QueueTask(task);
}

void TaskScheduler___::ctor() {
  if (Debugger::get_IsAttached()) {
    AddToActiveTaskSchedulers();
  }
}

void TaskScheduler___::AddToActiveTaskSchedulers() {
  ConditionalWeakTable<TaskScheduler, Object> conditionalWeakTable = s_activeTaskSchedulers;
  if (conditionalWeakTable == nullptr) {
    Interlocked::CompareExchange(s_activeTaskSchedulers, rt::newobj<ConditionalWeakTable<TaskScheduler, Object>>(), (ConditionalWeakTable<TaskScheduler, Object>)nullptr);
    conditionalWeakTable = s_activeTaskSchedulers;
  }
  conditionalWeakTable->Add((TaskScheduler)this, nullptr);
}

TaskScheduler TaskScheduler___::FromCurrentSynchronizationContext() {
  return rt::newobj<SynchronizationContextTaskScheduler>();
}

Boolean TaskScheduler___::TryExecuteTask(Task<> task) {
  if (task->get_ExecutingTaskScheduler() != (TaskScheduler)this) {
    rt::throw_exception<InvalidOperationException>(SR::get_TaskScheduler_ExecuteTask_WrongTaskScheduler());
  }
  return task->ExecuteEntry();
}

void TaskScheduler___::PublishUnobservedTaskException(Object sender, UnobservedTaskExceptionEventArgs ueea) {
}

Array<Task<>> TaskScheduler___::GetScheduledTasksForDebugger() {
  IEnumerable<Task<>> scheduledTasks = GetScheduledTasks();
  if (scheduledTasks == nullptr) {
    return nullptr;
  }
  Array<Task<>> array = rt::as<Array<Task<>>>(scheduledTasks);
  if (array == nullptr) {
    array = rt::newobj<List<Task<>>>(scheduledTasks)->ToArray();
  }
  Array<Task<>> array2 = array;
  for (Task<>&& task : *array2) {
    Int32 id = task->get_Id();
  }
  return array;
}

Array<TaskScheduler> TaskScheduler___::GetTaskSchedulersForDebugger() {
  if (s_activeTaskSchedulers == nullptr) {
    return rt::newarr<Array<TaskScheduler>>(1);
  }
  List<TaskScheduler> list = rt::newobj<List<TaskScheduler>>();
  for (KeyValuePair<TaskScheduler, Object>&& item : *(IEnumerable<KeyValuePair<TaskScheduler, Object>>)s_activeTaskSchedulers) {
    list->Add(item.get_Key());
  }
  if (!list->Contains(s_defaultTaskScheduler)) {
    list->Add(s_defaultTaskScheduler);
  }
  Array<TaskScheduler> array = list->ToArray();
  Array<TaskScheduler> array2 = array;
  for (TaskScheduler&& taskScheduler : *array2) {
    Int32 id = taskScheduler->get_Id();
  }
  return array;
}

void TaskScheduler___::cctor() {
  s_defaultTaskScheduler = rt::newobj<ThreadPoolTaskScheduler>();
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskSchedulerNamespace
