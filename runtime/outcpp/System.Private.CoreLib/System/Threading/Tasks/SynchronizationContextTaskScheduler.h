#pragma once

#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace SynchronizationContextTaskSchedulerNamespace {
using namespace Collections::Generic;
CLASS(SynchronizationContextTaskScheduler) : public TaskScheduler::in {
  public: Int32 get_MaximumConcurrencyLevel();
  public: void Ctor();
  public: void QueueTask(Task<> task);
  protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
  protected: IEnumerable<Task<>> GetScheduledTasks();
  private: static void SCtor();
  private: SynchronizationContext m_synchronizationContext;
  private: static SendOrPostCallback s_postCallback;
};
} // namespace SynchronizationContextTaskSchedulerNamespace
using SynchronizationContextTaskScheduler = SynchronizationContextTaskSchedulerNamespace::SynchronizationContextTaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
