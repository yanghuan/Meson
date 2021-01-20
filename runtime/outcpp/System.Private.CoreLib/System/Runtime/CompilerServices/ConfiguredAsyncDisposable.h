#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS_(ConfiguredValueTaskAwaitable)
namespace ConfiguredAsyncDisposableNamespace {
struct ConfiguredAsyncDisposable : public valueType<ConfiguredAsyncDisposable> {
  public: explicit ConfiguredAsyncDisposable(IAsyncDisposable source, Boolean continueOnCapturedContext);
  public: ConfiguredValueTaskAwaitable<> DisposeAsync();
  public: explicit ConfiguredAsyncDisposable() {}
  private: IAsyncDisposable _source;
  private: Boolean _continueOnCapturedContext;
};
} // namespace ConfiguredAsyncDisposableNamespace
using ConfiguredAsyncDisposable = ConfiguredAsyncDisposableNamespace::ConfiguredAsyncDisposable;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
