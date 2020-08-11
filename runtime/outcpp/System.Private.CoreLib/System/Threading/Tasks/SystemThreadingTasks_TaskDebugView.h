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
FORWARD_(Task, T1, T2)
namespace SystemThreadingTasks_TaskDebugViewNamespace {
CLASS(SystemThreadingTasks_TaskDebugView) : public Object::in {
  public: Object get_AsyncState();
  public: TaskCreationOptions get_CreationOptions();
  public: Exception get_Exception();
  public: Int32 get_Id();
  public: Boolean get_CancellationPending();
  public: TaskStatus get_Status();
  public: void ctor(Task<> task);
  private: Task<> m_task;
};
} // namespace SystemThreadingTasks_TaskDebugViewNamespace
using SystemThreadingTasks_TaskDebugView = SystemThreadingTasks_TaskDebugViewNamespace::SystemThreadingTasks_TaskDebugView;
} // namespace System::Private::CoreLib::System::Threading::Tasks
