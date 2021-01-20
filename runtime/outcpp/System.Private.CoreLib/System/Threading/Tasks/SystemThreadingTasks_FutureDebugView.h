#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskCreationOptions : int32_t;
enum class TaskStatus : int32_t;
FORWARD_(Task)
namespace SystemThreadingTasks_FutureDebugViewNamespace {
CLASS(SystemThreadingTasks_FutureDebugView, TResult) : public object {
  public: TResult get_Result();
  public: Object get_AsyncState();
  public: TaskCreationOptions get_CreationOptions();
  public: Exception get_Exception();
  public: Int32 get_Id();
  public: Boolean get_CancellationPending();
  public: TaskStatus get_Status();
  public: void ctor(Task<TResult> task);
  private: Task<TResult> m_task;
};
} // namespace SystemThreadingTasks_FutureDebugViewNamespace
template <class TResult>
using SystemThreadingTasks_FutureDebugView = SystemThreadingTasks_FutureDebugViewNamespace::SystemThreadingTasks_FutureDebugView<TResult>;
} // namespace System::Private::CoreLib::System::Threading::Tasks
