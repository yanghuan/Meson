#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IAsyncEnumerator, T)
namespace IAsyncEnumerableNamespace {
using namespace System::Threading;
CLASS(IAsyncEnumerable, T) : public Object::in {
  public: template <class T0 = CancellationToken>
  IAsyncEnumerator<T> GetAsyncEnumerator(T0 cancellationToken = rt::default__);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IAsyncEnumerableNamespace
template <class T>
using IAsyncEnumerable = IAsyncEnumerableNamespace::IAsyncEnumerable<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
