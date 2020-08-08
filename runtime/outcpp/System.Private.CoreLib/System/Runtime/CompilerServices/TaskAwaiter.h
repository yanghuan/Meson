#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARD(ICriticalNotifyCompletion)
FORWARD(INotifyCompletion)
FORWARD(ITaskAwaiter)
namespace TaskAwaiterNamespace {
using namespace Threading::Tasks;
template <class T1 = void, class T2 = void>
struct TaskAwaiter {
};
template <>
struct TaskAwaiter<> : public valueType<TaskAwaiter<>> {
  public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, ITaskAwaiter>;
  public: Boolean get_IsCompleted();
  public: Task<> m_task;
};
template <class TResult>
struct TaskAwaiter<TResult> : public valueType<TaskAwaiter<TResult>> {
  public: using interface = rt::TypeList<ICriticalNotifyCompletion, INotifyCompletion, ITaskAwaiter>;
  public: Boolean get_IsCompleted();
  private: Task<TResult> m_task;
};
} // namespace TaskAwaiterNamespace
template <class T1 = void, class T2 = void>
using TaskAwaiter = TaskAwaiterNamespace::TaskAwaiter<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
