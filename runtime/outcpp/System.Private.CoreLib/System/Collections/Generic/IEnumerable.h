#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
namespace IEnumerableNamespace {
using Generic::IEnumerator;
CLASS(IEnumerable, T) {
  public: IEnumerator<T> GetEnumerator();
};
} // namespace IEnumerableNamespace
template <class T>
using IEnumerable = IEnumerableNamespace::IEnumerable<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
