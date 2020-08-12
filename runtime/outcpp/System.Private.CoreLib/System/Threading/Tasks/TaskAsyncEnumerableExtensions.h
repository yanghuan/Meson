#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IAsyncDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS(ConfiguredAsyncDisposable)
FORWARDS(ConfiguredCancelableAsyncEnumerable, T)
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IAsyncEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace TaskAsyncEnumerableExtensionsNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::CompilerServices;
class TaskAsyncEnumerableExtensions {
  public: static ConfiguredAsyncDisposable ConfigureAwait(IAsyncDisposable source, Boolean continueOnCapturedContext);
  public: template <class T>
  static ConfiguredCancelableAsyncEnumerable<T> ConfigureAwait(IAsyncEnumerable<T> source, Boolean continueOnCapturedContext);
  public: template <class T>
  static ConfiguredCancelableAsyncEnumerable<T> WithCancellation(IAsyncEnumerable<T> source, CancellationToken cancellationToken);
};
} // namespace TaskAsyncEnumerableExtensionsNamespace
using TaskAsyncEnumerableExtensions = TaskAsyncEnumerableExtensionsNamespace::TaskAsyncEnumerableExtensions;
} // namespace System::Private::CoreLib::System::Threading::Tasks
