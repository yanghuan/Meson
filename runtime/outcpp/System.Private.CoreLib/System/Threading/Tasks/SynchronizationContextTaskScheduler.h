#pragma once

#include <System.Private.CoreLib/System/Object.h>
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
FORWARD_(Task)
namespace SynchronizationContextTaskSchedulerNamespace {
using namespace System::Collections::Generic;
CLASS(SynchronizationContextTaskScheduler) : public TaskScheduler::in {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__8_0(Object s);
    public: static __c __9;
  };
  public: Int32 get_MaximumConcurrencyLevel();
  public: void ctor();
  public: void QueueTask(Task<> task);
  protected: Boolean TryExecuteTaskInline(Task<> task, Boolean taskWasPreviouslyQueued);
  protected: IEnumerable<Task<>> GetScheduledTasks();
  public: static void cctor();
  private: SynchronizationContext m_synchronizationContext;
  private: static SendOrPostCallback s_postCallback;
};
} // namespace SynchronizationContextTaskSchedulerNamespace
using SynchronizationContextTaskScheduler = SynchronizationContextTaskSchedulerNamespace::SynchronizationContextTaskScheduler;
} // namespace System::Private::CoreLib::System::Threading::Tasks
