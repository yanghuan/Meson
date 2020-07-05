#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IAsyncDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ConfiguredAsyncDisposable)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace TaskAsyncEnumerableExtensionsNamespace {
using namespace Runtime::CompilerServices;
class TaskAsyncEnumerableExtensions {
  public: static ConfiguredAsyncDisposable ConfigureAwait(IAsyncDisposable source, Boolean continueOnCapturedContext);
};
} // namespace TaskAsyncEnumerableExtensionsNamespace
using TaskAsyncEnumerableExtensions = TaskAsyncEnumerableExtensionsNamespace::TaskAsyncEnumerableExtensions;
} // namespace System::Private::CoreLib::System::Threading::Tasks
