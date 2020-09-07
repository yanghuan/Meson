#include "ThreadPoolTaskScheduler-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ThreadPoolTaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ThreadPoolTaskSchedulerNamespace {
Task<> ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::get_CurrentOfTask() {
  return <>2__current;
}

Object ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::get_CurrentOfIEnumerator() {
  return <>2__current;
}

void ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  <>l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::DisposeOfIDisposable() {
  Int32 num = <>1__state;
  if (num == -3 || num == 1) {
    try {
    } catch (...) {
    } finally: {
      __m__Finally1();
    }
  }
}

Boolean ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::MoveNext() {
  try {
    switch (<>1__state.get()) {
      default:
        return false;
      case 0:
        <>1__state = -1;
        <>7__wrap1 = tpwItems->GetEnumerator();
        <>1__state = -3;
        break;
      case 1:
        <>1__state = -3;
        break;
    }
    while (<>7__wrap1->MoveNext()) {
      Object current = <>7__wrap1->get_Current();
      Task<> task = rt::as<Task<>>(current);
      if (task != nullptr) {
        <>2__current = task;
        <>1__state = 1;
        return true;
      }
    }
    __m__Finally1();
    <>7__wrap1 = nullptr;
    return false;
  } catch (...) {
    ((IDisposable)(_FilterTasksFromWorkItems_d__6)this)->Dispose();
    throw;
  }
}

void ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::__m__Finally1() {
  <>1__state = -1;
  if (<>7__wrap1 != nullptr) {
    <>7__wrap1->Dispose();
  }
}

void ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<Task<>> ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::GetEnumeratorOfTask() {
  _FilterTasksFromWorkItems_d__6 _FilterTasksFromWorkItems_d__;
  if (<>1__state == -2 && <>l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    <>1__state = 0;
    _FilterTasksFromWorkItems_d__ = (_FilterTasksFromWorkItems_d__6)this;
  } else {
    _FilterTasksFromWorkItems_d__ = rt::newobj<_FilterTasksFromWorkItems_d__6>(0);
  }
  _FilterTasksFromWorkItems_d__->tpwItems = <>3__tpwItems;
  return _FilterTasksFromWorkItems_d__;
}

IEnumerator_ ThreadPoolTaskScheduler___::_FilterTasksFromWorkItems_d__6___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<Task<>>)(_FilterTasksFromWorkItems_d__6)this)->GetEnumerator();
}

void ThreadPoolTaskScheduler___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void ThreadPoolTaskScheduler___::__c___::ctor() {
}

void ThreadPoolTaskScheduler___::__c___::_cctor_b__10_0(Object s) {
  ((Task<>)s)->ExecuteEntryUnsafe(nullptr);
}

void ThreadPoolTaskScheduler___::ctor() {
  Int32 id = TaskScheduler::in::get_Id();
}

void ThreadPoolTaskScheduler___::QueueTask(Task<> task) {
  TaskCreationOptions options = task->get_Options();
  if ((options & TaskCreationOptions::LongRunning) != 0) {
    Thread thread = rt::newobj<Thread>(s_longRunningThreadWork);
    thread->set_IsBackground(true);
    thread->Start(task);
  } else {
    Boolean preferLocal = (options & TaskCreationOptions::PreferFairness) == 0;
    ThreadPool::UnsafeQueueUserWorkItemInternal(task, preferLocal);
  }
}

Boolean ThreadPoolTaskScheduler___::TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  if (taskWasPreviouslyQueued && !ThreadPool::TryPopCustomWorkItem(task)) {
    return false;
  }
  try {
    task->ExecuteEntryUnsafe(nullptr);
  } catch (...) {
  } finally: {
    if (taskWasPreviouslyQueued) {
      NotifyWorkItemProgress();
    }
  }
  return true;
}

Boolean ThreadPoolTaskScheduler___::TryDequeue(Task<> task) {
  return ThreadPool::TryPopCustomWorkItem(task);
}

IEnumerable<Task<>> ThreadPoolTaskScheduler___::GetScheduledTasks() {
  return FilterTasksFromWorkItems(ThreadPool::GetQueuedWorkItems());
}

IEnumerable<Task<>> ThreadPoolTaskScheduler___::FilterTasksFromWorkItems(IEnumerable<Object> tpwItems) {
  for (Object&& tpwItem : *tpwItems) {
    Task<> task = rt::as<Task<>>(tpwItem);
    if (task != nullptr) {
    }
  }
}

void ThreadPoolTaskScheduler___::NotifyWorkItemProgress() {
  ThreadPool::NotifyWorkItemProgress();
}

void ThreadPoolTaskScheduler___::cctor() {
  s_longRunningThreadWork = {__c::in::__9, &__c::in::_cctor_b__10_0};
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ThreadPoolTaskSchedulerNamespace
