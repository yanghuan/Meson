#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(IAsyncDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS_(ConfiguredValueTaskAwaitable, T1, T2)
namespace ConfiguredAsyncDisposableNamespace {
struct ConfiguredAsyncDisposable {
  public: ConfiguredValueTaskAwaitable<> DisposeAsync();
  private: IAsyncDisposable _source;
  private: Boolean _continueOnCapturedContext;
};
} // namespace ConfiguredAsyncDisposableNamespace
using ConfiguredAsyncDisposable = ConfiguredAsyncDisposableNamespace::ConfiguredAsyncDisposable;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
