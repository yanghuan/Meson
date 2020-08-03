#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IAsyncEnumerator, T)
namespace IAsyncEnumerableNamespace {
using namespace Threading;
CLASS(IAsyncEnumerable, T) : public Object::in {
  public: IAsyncEnumerator<T> GetAsyncEnumerator(CancellationToken cancellationToken);
};
} // namespace IAsyncEnumerableNamespace
template <class T>
using IAsyncEnumerable = IAsyncEnumerableNamespace::IAsyncEnumerable<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
