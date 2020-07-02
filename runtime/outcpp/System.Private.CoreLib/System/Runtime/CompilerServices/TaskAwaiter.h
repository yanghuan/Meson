#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TaskAwaiterNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
template <class T1 = void, class T2 = void>
struct TaskAwaiter {
};
template <>
struct TaskAwaiter<> {
  public: Boolean get_IsCompleted();
  public: Task<> m_task;
};
template <class TResult>
struct TaskAwaiter<TResult> {
  public: Boolean get_IsCompleted();
  private: Task<TResult> m_task;
};
} // namespace TaskAwaiterNamespace
template <class T1 = void, class T2 = void>
using TaskAwaiter = TaskAwaiterNamespace::TaskAwaiter<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
