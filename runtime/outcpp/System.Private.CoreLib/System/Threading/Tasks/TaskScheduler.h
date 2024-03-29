#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD_(EventHandler)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task)
FORWARD(UnobservedTaskExceptionEventArgs)
namespace TaskSchedulerNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::CompilerServices;
CLASS(TaskScheduler) : public object {
  public: CLASS(SystemThreadingTasks_TaskSchedulerDebugView) : public object {
    public: Int32 get_Id();
    public: IEnumerable<Task<>> get_ScheduledTasks();
    public: void ctor(TaskScheduler scheduler);
    private: TaskScheduler m_taskScheduler;
  };
  public: Int32 get_MaximumConcurrencyLevel();
  public: static TaskScheduler get_Default();
  public: static TaskScheduler get_Current();
  public: static TaskScheduler get_InternalCurrent();
  public: Int32 get_Id();
  public: void QueueTask(Task<> task);
  protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
  protected: IEnumerable<Task<>> GetScheduledTasks();
  public: Boolean TryRunInline(Task<> task, Boolean taskWasPreviouslyQueued);
  public: Boolean TryDequeue(Task<> task);
  public: void NotifyWorkItemProgress();
  public: void InternalQueueTask(Task<> task);
  public: void ctor();
  private: void AddToActiveTaskSchedulers();
  public: static TaskScheduler FromCurrentSynchronizationContext();
  protected: Boolean TryExecuteTask(Task<> task);
  public: static void PublishUnobservedTaskException(Object sender, UnobservedTaskExceptionEventArgs ueea);
  public: Array<Task<>> GetScheduledTasksForDebugger();
  public: static Array<TaskScheduler> GetTaskSchedulersForDebugger();
  public: static void cctor();
  private: static ConditionalWeakTable<TaskScheduler, Object> s_activeTaskSchedulers;
  private: static TaskScheduler s_defaultTaskScheduler;
  public: static Int32 s_taskSchedulerIdCounter;
  private: Int32 m_taskSchedulerId;
  private: static EventHandler<UnobservedTaskExceptionEventArgs> UnobservedTaskException;
};
} // namespace TaskSchedulerNamespace
using TaskScheduler = TaskSchedulerNamespace::TaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
