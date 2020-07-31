#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARD_(Task, T1, T2)
namespace TaskExtensionsNamespace {
class TaskExtensions : public Object::in {
  public: static Task<> Unwrap(Task<Task<>> task);
  public: template <class TResult>
  static Task<TResult> Unwrap(Task<Task<TResult>> task);
};
} // namespace TaskExtensionsNamespace
using TaskExtensions = TaskExtensionsNamespace::TaskExtensions;
} // namespace System::Private::CoreLib::System::Threading::Tasks
