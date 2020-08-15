#include "ConcurrentExclusiveSchedulerPair-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/ConcurrentExclusiveSchedulerPair-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/IProducerConsumerQueue.h>
#include <System.Private.CoreLib/System/Threading/Tasks/MultiProducerMultiConsumerQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/SingleProducerSingleConsumerQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/Tuple-dep.h>

namespace System::Private::CoreLib::System::Threading::Tasks::ConcurrentExclusiveSchedulerPairNamespace {
void ConcurrentExclusiveSchedulerPair___::CompletionState___::ctor() {
}

void ConcurrentExclusiveSchedulerPair___::SchedulerWorkItem___::ctor(ConcurrentExclusiveSchedulerPair pair) {
  _pair = pair;
}

Int32 ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::get_MaximumConcurrencyLevel() {
  return m_taskScheduler->m_maxConcurrencyLevel;
}

IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::get_ScheduledTasks() {
  return m_taskScheduler->m_tasks;
}

ConcurrentExclusiveSchedulerPair ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::get_SchedulerPair() {
  return m_taskScheduler->m_pair;
}

void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::DebugView___::ctor(ConcurrentExclusiveTaskScheduler scheduler) {
  m_taskScheduler = scheduler;
}

Int32 ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::get_MaximumConcurrencyLevel() {
  return m_maxConcurrencyLevel;
}

Int32 ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::get_CountForDebugger() {
  return m_tasks->get_Count();
}

void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::ctor(ConcurrentExclusiveSchedulerPair pair, Int32 maxConcurrencyLevel, ProcessingMode processingMode) {
  m_pair = pair;
  m_maxConcurrencyLevel = maxConcurrencyLevel;
  m_processingMode = processingMode;
  IProducerConsumerQueue<Task> tasks;
  if (processingMode != ProcessingMode::ProcessingExclusiveTask) {
    IProducerConsumerQueue<Task> producerConsumerQueue = rt::newobj<MultiProducerMultiConsumerQueue<Task>>();
    tasks = producerConsumerQueue;
  } else {
    IProducerConsumerQueue<Task> producerConsumerQueue = rt::newobj<SingleProducerSingleConsumerQueue<Task>>();
    tasks = producerConsumerQueue;
  }
  m_tasks = tasks;
}

void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::QueueTask(Task<> task) {
  {
    rt::lock(m_pair->get_ValueLock());
    if (m_pair->get_CompletionRequested()) {
      rt::throw_exception<InvalidOperationException>(GetType()->ToString());
    }
    m_tasks->Enqueue(task);
    m_pair->ProcessAsyncIfNecessary();
  }
}

void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::ExecuteTask(Task<> task) {
  TryExecuteTask(task);
}

Boolean ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued) {
  if (!taskWasPreviouslyQueued && m_pair->get_CompletionRequested()) {
    return false;
  }
  Boolean flag = m_pair->m_underlyingTaskScheduler == TaskScheduler::in::get_Default();
  if (flag && taskWasPreviouslyQueued && !Thread::in::get_CurrentThread()->get_IsThreadPoolThread()) {
    return false;
  }
  if (m_pair->m_threadProcessingMode->get_Value() == m_processingMode) {
    if (!flag || taskWasPreviouslyQueued) {
      return TryExecuteTaskInlineOnTargetScheduler(task);
    }
    return TryExecuteTask(task);
  }
  return false;
}

Boolean ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::TryExecuteTaskInlineOnTargetScheduler(Task<> task) {
  Task<Boolean> task2 = rt::newobj<Task<Boolean>>(s_tryExecuteTaskShim, Tuple::Create((ConcurrentExclusiveTaskScheduler)this, task));
  try {
    task2->RunSynchronously(m_pair->m_underlyingTaskScheduler);
    return task2->get_Result();
  } catch (...) {
  } finally: {
    task2->Dispose();
  }
}

Boolean ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::TryExecuteTaskShim(Object state) {
  Tuple<ConcurrentExclusiveTaskScheduler, Task> tuple = (Tuple<ConcurrentExclusiveTaskScheduler, Task>)state;
  return tuple->get_Item1()->TryExecuteTask(tuple->get_Item2());
}

IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::GetScheduledTasks() {
  return m_tasks;
}

void ConcurrentExclusiveSchedulerPair___::ConcurrentExclusiveTaskScheduler___::cctor() {
  s_tryExecuteTaskShim = TryExecuteTaskShim;
}

ConcurrentExclusiveSchedulerPair::in::ProcessingMode ConcurrentExclusiveSchedulerPair___::DebugView___::get_Mode() {
  return m_pair->get_ModeForDebugger();
}

IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::DebugView___::get_ScheduledExclusive() {
  return m_pair->m_exclusiveTaskScheduler->m_tasks;
}

IEnumerable<Task<>> ConcurrentExclusiveSchedulerPair___::DebugView___::get_ScheduledConcurrent() {
  return m_pair->m_concurrentTaskScheduler->m_tasks;
}

Int32 ConcurrentExclusiveSchedulerPair___::DebugView___::get_CurrentlyExecutingTaskCount() {
  if (m_pair->m_processingCount != -1) {
    return m_pair->m_processingCount;
  }
  return 1;
}

TaskScheduler ConcurrentExclusiveSchedulerPair___::DebugView___::get_TargetScheduler() {
  return m_pair->m_underlyingTaskScheduler;
}

void ConcurrentExclusiveSchedulerPair___::DebugView___::ctor(ConcurrentExclusiveSchedulerPair pair) {
  m_pair = pair;
}

Int32 ConcurrentExclusiveSchedulerPair___::get_DefaultMaxConcurrencyLevel() {
  return Environment::get_ProcessorCount();
}

Object ConcurrentExclusiveSchedulerPair___::get_ValueLock() {
  return m_threadProcessingMode;
}

Task<> ConcurrentExclusiveSchedulerPair___::get_Completion() {
  return EnsureCompletionStateInitialized();
}

Boolean ConcurrentExclusiveSchedulerPair___::get_CompletionRequested() {
  if (m_completionState != nullptr) {
    return Volatile::Read(m_completionState->m_completionRequested);
  }
  return false;
}

Boolean ConcurrentExclusiveSchedulerPair___::get_ReadyToComplete() {
  if (!get_CompletionRequested() || m_processingCount != 0) {
    return false;
  }
  CompletionState completionState = EnsureCompletionStateInitialized();
  if (completionState->m_exceptions == nullptr || completionState->m_exceptions->get_Count() <= 0) {
    if (m_concurrentTaskScheduler->m_tasks->get_IsEmpty()) {
      return m_exclusiveTaskScheduler->m_tasks->get_IsEmpty();
    }
    return false;
  }
  return true;
}

TaskScheduler ConcurrentExclusiveSchedulerPair___::get_ConcurrentScheduler() {
  return m_concurrentTaskScheduler;
}

TaskScheduler ConcurrentExclusiveSchedulerPair___::get_ExclusiveScheduler() {
  return m_exclusiveTaskScheduler;
}

Int32 ConcurrentExclusiveSchedulerPair___::get_ConcurrentTaskCountForDebugger() {
  return m_concurrentTaskScheduler->m_tasks->get_Count();
}

Int32 ConcurrentExclusiveSchedulerPair___::get_ExclusiveTaskCountForDebugger() {
  return m_exclusiveTaskScheduler->m_tasks->get_Count();
}

ConcurrentExclusiveSchedulerPair::in::ProcessingMode ConcurrentExclusiveSchedulerPair___::get_ModeForDebugger() {
  if (m_completionState != nullptr && m_completionState->get_IsCompleted()) {
    return ProcessingMode::Completed;
  }
  ProcessingMode processingMode = ProcessingMode::NotCurrentlyProcessing;
  if (m_processingCount == -1) {
    processingMode |= ProcessingMode::ProcessingExclusiveTask;
  }
  if (m_processingCount >= 1) {
    processingMode |= ProcessingMode::ProcessingConcurrentTasks;
  }
  if (get_CompletionRequested()) {
    processingMode |= ProcessingMode::Completing;
  }
  return processingMode;
}

void ConcurrentExclusiveSchedulerPair___::ctor() {
}

void ConcurrentExclusiveSchedulerPair___::ctor(TaskScheduler taskScheduler) {
}

void ConcurrentExclusiveSchedulerPair___::ctor(TaskScheduler taskScheduler, Int32 maxConcurrencyLevel) {
}

void ConcurrentExclusiveSchedulerPair___::ctor(TaskScheduler taskScheduler, Int32 maxConcurrencyLevel, Int32 maxItemsPerTask) {
  m_threadProcessingMode = rt::newobj<ThreadLocal<ProcessingMode>>();
  Object::in::ctor();
  if (taskScheduler == nullptr) {
    rt::throw_exception<ArgumentNullException>("taskScheduler");
  }
  if (maxConcurrencyLevel == 0 || maxConcurrencyLevel < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxConcurrencyLevel");
  }
  if (maxItemsPerTask == 0 || maxItemsPerTask < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxItemsPerTask");
  }
  m_underlyingTaskScheduler = taskScheduler;
  m_maxConcurrencyLevel = maxConcurrencyLevel;
  m_maxItemsPerTask = maxItemsPerTask;
  Int32 maximumConcurrencyLevel = taskScheduler->get_MaximumConcurrencyLevel();
  if (maximumConcurrencyLevel > 0 && maximumConcurrencyLevel < m_maxConcurrencyLevel) {
    m_maxConcurrencyLevel = maximumConcurrencyLevel;
  }
  if (m_maxConcurrencyLevel == -1) {
    m_maxConcurrencyLevel = Int32::MaxValue;
  }
  if (m_maxItemsPerTask == -1) {
    m_maxItemsPerTask = Int32::MaxValue;
  }
  m_exclusiveTaskScheduler = rt::newobj<ConcurrentExclusiveTaskScheduler>((ConcurrentExclusiveSchedulerPair)this, 1, ProcessingMode::ProcessingExclusiveTask);
  m_concurrentTaskScheduler = rt::newobj<ConcurrentExclusiveTaskScheduler>((ConcurrentExclusiveSchedulerPair)this, m_maxConcurrencyLevel, ProcessingMode::ProcessingConcurrentTasks);
}

void ConcurrentExclusiveSchedulerPair___::Complete() {
  {
    rt::lock(get_ValueLock());
    if (!get_CompletionRequested()) {
      RequestCompletion();
      CleanupStateIfCompletingAndQuiesced();
    }
  }
}

ConcurrentExclusiveSchedulerPair::in::CompletionState ConcurrentExclusiveSchedulerPair___::EnsureCompletionStateInitialized() {
}

void ConcurrentExclusiveSchedulerPair___::RequestCompletion() {
  EnsureCompletionStateInitialized()->m_completionRequested = true;
}

void ConcurrentExclusiveSchedulerPair___::CleanupStateIfCompletingAndQuiesced() {
  if (get_ReadyToComplete()) {
    CompleteTaskAsync();
  }
}

void ConcurrentExclusiveSchedulerPair___::CompleteTaskAsync() {
  CompletionState completionState = EnsureCompletionStateInitialized();
  if (!completionState->m_completionQueued) {
    completionState->m_completionQueued = true;
  }
}

void ConcurrentExclusiveSchedulerPair___::FaultWithTask(Task<> faultedTask) {
  CompletionState completionState = EnsureCompletionStateInitialized();
  CompletionState completionState2 = completionState;
  if (completionState2->m_exceptions == nullptr) {
    completionState2->m_exceptions = rt::newobj<List<Exception>>();
  }
  completionState->m_exceptions->AddRange(faultedTask->get_Exception()->get_InnerExceptions());
  RequestCompletion();
}

void ConcurrentExclusiveSchedulerPair___::ProcessAsyncIfNecessary(Boolean fairly) {
  if (m_processingCount < 0) {
    return;
  }
  Boolean flag = !m_exclusiveTaskScheduler->m_tasks->get_IsEmpty();
  Task task = nullptr;
  if (m_processingCount == 0 && flag) {
    m_processingCount = -1;
    if (!TryQueueThreadPoolWorkItem(fairly)) {
      try {
      } catch (Exception exception) {
      }
    }
  } else {
    Int32 count = m_concurrentTaskScheduler->m_tasks->get_Count();
    if (count > 0 && !flag && m_processingCount < m_maxConcurrencyLevel) {
      for (Int32 i = 0; i < count; i++) {
        if (m_processingCount >= m_maxConcurrencyLevel) {
          break;
        }
        m_processingCount++;
        if (TryQueueThreadPoolWorkItem(fairly)) {
          continue;
        }
        try {
        } catch (Exception exception2) {
        }
      }
    }
  }
  CleanupStateIfCompletingAndQuiesced();
}

Boolean ConcurrentExclusiveSchedulerPair___::TryQueueThreadPoolWorkItem(Boolean fairly) {
  if (TaskScheduler::in::get_Default() == m_underlyingTaskScheduler) {
    auto& default = m_threadPoolWorkItem;
    IThreadPoolWorkItem callBack = default != nullptr ? default : (m_threadPoolWorkItem = rt::newobj<SchedulerWorkItem>((ConcurrentExclusiveSchedulerPair)this));
    ThreadPool::UnsafeQueueUserWorkItemInternal(callBack, !fairly);
    return true;
  }
  return false;
}

void ConcurrentExclusiveSchedulerPair___::ProcessExclusiveTasks() {
  try {
    m_threadProcessingMode->set_Value = ProcessingMode::ProcessingExclusiveTask;
    for (Int32 i = 0; i < m_maxItemsPerTask; i++) {
      Task result;
      if (!m_exclusiveTaskScheduler->m_tasks->TryDequeue(result)) {
        break;
      }
      if (!result->get_IsFaulted()) {
        m_exclusiveTaskScheduler->ExecuteTask(result);
      }
    }
  } catch (...) {
  } finally: {
    m_threadProcessingMode->set_Value = ProcessingMode::NotCurrentlyProcessing;
    {
      rt::lock(get_ValueLock());
      m_processingCount = 0;
      ProcessAsyncIfNecessary(true);
    }
  }
}

void ConcurrentExclusiveSchedulerPair___::ProcessConcurrentTasks() {
  try {
    m_threadProcessingMode->set_Value = ProcessingMode::ProcessingConcurrentTasks;
    for (Int32 i = 0; i < m_maxItemsPerTask; i++) {
      Task result;
      if (!m_concurrentTaskScheduler->m_tasks->TryDequeue(result)) {
        break;
      }
      if (!result->get_IsFaulted()) {
        m_concurrentTaskScheduler->ExecuteTask(result);
      }
      if (!m_exclusiveTaskScheduler->m_tasks->get_IsEmpty()) {
        break;
      }
    }
  } catch (...) {
  } finally: {
    m_threadProcessingMode->set_Value = ProcessingMode::NotCurrentlyProcessing;
    {
      rt::lock(get_ValueLock());
      if (m_processingCount > 0) {
        m_processingCount--;
      }
      ProcessAsyncIfNecessary(true);
    }
  }
}

TaskCreationOptions ConcurrentExclusiveSchedulerPair___::GetCreationOptionsForTask(Boolean isReplacementReplica) {
  TaskCreationOptions taskCreationOptions = TaskCreationOptions::DenyChildAttach;
  if (isReplacementReplica) {
    taskCreationOptions |= TaskCreationOptions::PreferFairness;
  }
  return taskCreationOptions;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::ConcurrentExclusiveSchedulerPairNamespace
