#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskCreationOptions;
enum class TaskStatus;
FORWARD_(Task, T1, T2)
namespace SystemThreadingTasks_FutureDebugViewNamespace {
CLASS(SystemThreadingTasks_FutureDebugView, TResult) {
  public: TResult get_Result();
  public: Object get_AsyncState();
  public: TaskCreationOptions get_CreationOptions();
  public: Exception get_Exception();
  public: Int32 get_Id();
  public: Boolean get_CancellationPending();
  public: TaskStatus get_Status();
  private: Task<TResult> m_task;
};
} // namespace SystemThreadingTasks_FutureDebugViewNamespace
template <class TResult>
using SystemThreadingTasks_FutureDebugView = SystemThreadingTasks_FutureDebugViewNamespace::SystemThreadingTasks_FutureDebugView<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
