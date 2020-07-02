#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskExtensionsNamespace {
class TaskExtensions {
  public: static Task<> Unwrap(Task<Task<>> task);
};
} // namespace TaskExtensionsNamespace
using TaskExtensions = TaskExtensionsNamespace::TaskExtensions;
} // namespace System::Private::CoreLib::System::Threading::Tasks
