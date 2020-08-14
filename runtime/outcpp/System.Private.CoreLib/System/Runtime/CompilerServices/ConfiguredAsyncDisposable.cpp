#include "ConfiguredAsyncDisposable-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredAsyncDisposableNamespace {
ConfiguredAsyncDisposable::ConfiguredAsyncDisposable(IAsyncDisposable source, Boolean continueOnCapturedContext) {
  _source = source;
  _continueOnCapturedContext = continueOnCapturedContext;
}

ConfiguredValueTaskAwaitable<> ConfiguredAsyncDisposable::DisposeAsync() {
  return _source->DisposeAsync().ConfigureAwait(_continueOnCapturedContext);
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredAsyncDisposableNamespace
