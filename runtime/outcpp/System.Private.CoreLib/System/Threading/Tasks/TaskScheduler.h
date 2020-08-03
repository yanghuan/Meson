#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD_(EventHandler, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ConditionalWeakTable, TKey, TValue)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
FORWARD(UnobservedTaskExceptionEventArgs)
namespace TaskSchedulerNamespace {
using namespace Collections::Generic;
using namespace Runtime::CompilerServices;
CLASS(TaskScheduler) : public Object::in {
  public: CLASS(SystemThreadingTasks_TaskSchedulerDebugView) : public Object::in {
    public: Int32 get_Id();
    public: IEnumerable<Task<>> get_ScheduledTasks();
    public: void Ctor(TaskScheduler scheduler);
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
  protected: void Ctor();
  private: void AddToActiveTaskSchedulers();
  public: static TaskScheduler FromCurrentSynchronizationContext();
  protected: Boolean TryExecuteTask(Task<> task);
  public: static void PublishUnobservedTaskException(Object sender, UnobservedTaskExceptionEventArgs ueea);
  public: Array<Task<>> GetScheduledTasksForDebugger();
  public: static Array<TaskScheduler> GetTaskSchedulersForDebugger();
  private: static void SCtor();
  private: static ConditionalWeakTable<TaskScheduler, Object> s_activeTaskSchedulers;
  private: static TaskScheduler s_defaultTaskScheduler;
  public: static Int32 s_taskSchedulerIdCounter;
  private: Int32 m_taskSchedulerId;
  private: static EventHandler<UnobservedTaskExceptionEventArgs> UnobservedTaskException;
};
} // namespace TaskSchedulerNamespace
using TaskScheduler = TaskSchedulerNamespace::TaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
