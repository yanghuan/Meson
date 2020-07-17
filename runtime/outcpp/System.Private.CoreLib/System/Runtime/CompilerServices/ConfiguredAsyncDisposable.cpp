#include "ConfiguredAsyncDisposable-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredAsyncDisposableNamespace {
void ConfiguredAsyncDisposable::Ctor(IAsyncDisposable source, Boolean continueOnCapturedContext) {
};

ConfiguredValueTaskAwaitable<> ConfiguredAsyncDisposable::DisposeAsync() {
  return ConfiguredValueTaskAwaitable<>();
};

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ConfiguredAsyncDisposableNamespace
