#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskCanceledExceptionNamespace {
CLASS(TaskCanceledException) {
  public: Task<> get_Task();
  private: Task<> _canceledTask;
};
} // namespace TaskCanceledExceptionNamespace
using TaskCanceledException = TaskCanceledExceptionNamespace::TaskCanceledException;
} // namespace System::Private::CoreLib::System::Threading::Tasks
