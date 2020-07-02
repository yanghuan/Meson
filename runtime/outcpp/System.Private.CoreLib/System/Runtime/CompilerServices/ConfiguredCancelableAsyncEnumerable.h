#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IAsyncEnumerable, T)
FORWARD(IAsyncEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS_(ConfiguredValueTaskAwaitable, T1, T2)
namespace ConfiguredCancelableAsyncEnumerableNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Threading;
template <class T>
struct ConfiguredCancelableAsyncEnumerable {
  public: struct Enumerator {
    public: T get_Current();
    public: ConfiguredValueTaskAwaitable<Boolean> MoveNextAsync();
    public: ConfiguredValueTaskAwaitable<> DisposeAsync();
    private: IAsyncEnumerator<T> _enumerator;
    private: Boolean _continueOnCapturedContext;
  };
  public: ConfiguredCancelableAsyncEnumerable<T> ConfigureAwait(Boolean continueOnCapturedContext);
  public: ConfiguredCancelableAsyncEnumerable<T> WithCancellation(CancellationToken cancellationToken);
  public: Enumerator GetAsyncEnumerator();
  private: IAsyncEnumerable<T> _enumerable;
  private: CancellationToken _cancellationToken;
  private: Boolean _continueOnCapturedContext;
};
} // namespace ConfiguredCancelableAsyncEnumerableNamespace
template <class T>
using ConfiguredCancelableAsyncEnumerable = ConfiguredCancelableAsyncEnumerableNamespace::ConfiguredCancelableAsyncEnumerable<T>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
