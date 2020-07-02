#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(Object)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadLocal, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARD(IProducerConsumerQueue, T)
FORWARD(TaskScheduler)
enum class TaskCreationOptions;
namespace ConcurrentExclusiveSchedulerPairNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(ConcurrentExclusiveSchedulerPair) {
  private: enum class ProcessingMode : uint8_t {
    NotCurrentlyProcessing = 0,
    ProcessingExclusiveTask = 1,
    ProcessingConcurrentTasks = 2,
    Completing = 4,
    Completed = 8,
  };
  private: CLASS(CompletionState) {
    public: Boolean m_completionRequested;
    public: Boolean m_completionQueued;
    public: List<Exception> m_exceptions;
  };
  private: CLASS(SchedulerWorkItem) {
    private: ConcurrentExclusiveSchedulerPair _pair;
  };
  private: CLASS(ConcurrentExclusiveTaskScheduler) {
    private: CLASS(DebugView) {
      public: Int32 get_MaximumConcurrencyLevel();
      public: IEnumerable<Task<>> get_ScheduledTasks();
      public: ConcurrentExclusiveSchedulerPair get_SchedulerPair();
      private: ConcurrentExclusiveTaskScheduler m_taskScheduler;
    };
    public: Int32 get_MaximumConcurrencyLevel();
    private: Int32 get_CountForDebugger();
    public: void QueueTask(Task<> task);
    public: void ExecuteTask(Task<> task);
    protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
    private: Boolean TryExecuteTaskInlineOnTargetScheduler(Task<> task);
    private: static Boolean TryExecuteTaskShim(Object state);
    protected: IEnumerable<Task<>> GetScheduledTasks();
    private: static Func<Object, Boolean> s_tryExecuteTaskShim;
    private: ConcurrentExclusiveSchedulerPair m_pair;
    private: Int32 m_maxConcurrencyLevel;
    private: ProcessingMode m_processingMode;
    public: IProducerConsumerQueue<Task<>> m_tasks;
  };
  private: CLASS(DebugView) {
    public: ProcessingMode get_Mode();
    public: IEnumerable<Task<>> get_ScheduledExclusive();
    public: IEnumerable<Task<>> get_ScheduledConcurrent();
    public: Int32 get_CurrentlyExecutingTaskCount();
    public: TaskScheduler get_TargetScheduler();
    private: ConcurrentExclusiveSchedulerPair m_pair;
  };
  private: static Int32 get_DefaultMaxConcurrencyLevel();
  private: Object get_ValueLock();
  public: Task<> get_Completion();
  private: Boolean get_CompletionRequested();
  private: Boolean get_ReadyToComplete();
  public: TaskScheduler get_ConcurrentScheduler();
  public: TaskScheduler get_ExclusiveScheduler();
  private: Int32 get_ConcurrentTaskCountForDebugger();
  private: Int32 get_ExclusiveTaskCountForDebugger();
  private: ProcessingMode get_ModeForDebugger();
  public: void Complete();
  private: CompletionState EnsureCompletionStateInitialized();
  private: void RequestCompletion();
  private: void CleanupStateIfCompletingAndQuiesced();
  private: void CompleteTaskAsync();
  private: void FaultWithTask(Task<> faultedTask);
  private: void ProcessAsyncIfNecessary(Boolean fairly);
  private: Boolean TryQueueThreadPoolWorkItem(Boolean fairly);
  private: void ProcessExclusiveTasks();
  private: void ProcessConcurrentTasks();
  public: static TaskCreationOptions GetCreationOptionsForTask(Boolean isReplacementReplica);
  private: ThreadLocal<ProcessingMode> m_threadProcessingMode;
  private: ConcurrentExclusiveTaskScheduler m_concurrentTaskScheduler;
  private: ConcurrentExclusiveTaskScheduler m_exclusiveTaskScheduler;
  private: TaskScheduler m_underlyingTaskScheduler;
  private: Int32 m_maxConcurrencyLevel;
  private: Int32 m_maxItemsPerTask;
  private: Int32 m_processingCount;
  private: CompletionState m_completionState;
  private: SchedulerWorkItem m_threadPoolWorkItem;
};
} // namespace ConcurrentExclusiveSchedulerPairNamespace
using ConcurrentExclusiveSchedulerPair = ConcurrentExclusiveSchedulerPairNamespace::ConcurrentExclusiveSchedulerPair;
} // namespace System::Private::CoreLib::System::Threading::Tasks
