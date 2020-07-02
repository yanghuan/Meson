#pragma once

#include <rt/GCObject.h>

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
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(SynchronizationContextTaskScheduler) {
  public: Int32 get_MaximumConcurrencyLevel();
  public: void QueueTask(Task<> task);
  protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
  protected: IEnumerable<Task<>> GetScheduledTasks();
  private: SynchronizationContext m_synchronizationContext;
  private: static SendOrPostCallback s_postCallback;
};
} // namespace SynchronizationContextTaskSchedulerNamespace
using SynchronizationContextTaskScheduler = SynchronizationContextTaskSchedulerNamespace::SynchronizationContextTaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
