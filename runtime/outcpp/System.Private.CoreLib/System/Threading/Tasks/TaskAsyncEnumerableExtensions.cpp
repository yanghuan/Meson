#include "TaskAsyncEnumerableExtensions-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::TaskAsyncEnumerableExtensionsNamespace {
ConfiguredAsyncDisposable TaskAsyncEnumerableExtensions::ConfigureAwait(IAsyncDisposable source, Boolean continueOnCapturedContext) {
  return ConfiguredAsyncDisposable(source, continueOnCapturedContext);
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::TaskAsyncEnumerableExtensionsNamespace
