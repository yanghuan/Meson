#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IAsyncEnumerable, T)
FORWARD(IAsyncEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
FORWARDS_(ConfiguredValueTaskAwaitable)
namespace ConfiguredCancelableAsyncEnumerableNamespace {
using namespace System::Collections::Generic;
using namespace System::Threading;
template <class T>
struct ConfiguredCancelableAsyncEnumerable : public valueType<ConfiguredCancelableAsyncEnumerable<T>> {
  public: struct Enumerator : public valueType<Enumerator> {
    public: T get_Current();
    public: explicit Enumerator(IAsyncEnumerator<T> enumerator, Boolean continueOnCapturedContext);
    public: ConfiguredValueTaskAwaitable<Boolean> MoveNextAsync();
    public: ConfiguredValueTaskAwaitable<> DisposeAsync();
    public: explicit Enumerator() {}
    private: IAsyncEnumerator<T> _enumerator;
    private: Boolean _continueOnCapturedContext;
  };
  public: explicit ConfiguredCancelableAsyncEnumerable(IAsyncEnumerable<T> enumerable, Boolean continueOnCapturedContext, CancellationToken cancellationToken);
  public: ConfiguredCancelableAsyncEnumerable<T> ConfigureAwait(Boolean continueOnCapturedContext);
  public: ConfiguredCancelableAsyncEnumerable<T> WithCancellation(CancellationToken cancellationToken);
  public: Enumerator GetAsyncEnumerator();
  public: explicit ConfiguredCancelableAsyncEnumerable() {}
  private: IAsyncEnumerable<T> _enumerable;
  private: CancellationToken _cancellationToken;
  private: Boolean _continueOnCapturedContext;
};
} // namespace ConfiguredCancelableAsyncEnumerableNamespace
template <class T>
using ConfiguredCancelableAsyncEnumerable = ConfiguredCancelableAsyncEnumerableNamespace::ConfiguredCancelableAsyncEnumerable<T>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
