#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(ParameterizedThreadStart)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace ThreadPoolTaskSchedulerNamespace {
using namespace System::Collections::Generic;
CLASS(ThreadPoolTaskScheduler) : public TaskScheduler::in {
  public: void ctor();
  public: void QueueTask(Task<> task);
  protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
  public: Boolean TryDequeue(Task<> task);
  protected: IEnumerable<Task<>> GetScheduledTasks();
  private: IEnumerable<Task<>> FilterTasksFromWorkItems(IEnumerable<Object> tpwItems);
  public: void NotifyWorkItemProgress();
  public: static void cctor();
  private: static ParameterizedThreadStart s_longRunningThreadWork;
};
} // namespace ThreadPoolTaskSchedulerNamespace
using ThreadPoolTaskScheduler = ThreadPoolTaskSchedulerNamespace::ThreadPoolTaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
