#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
namespace IReadOnlySetNamespace {
CLASS(IReadOnlySet, T) {
  public: Boolean Contains(T item);
  public: Boolean IsProperSubsetOf(IEnumerable<T> other);
  public: Boolean IsProperSupersetOf(IEnumerable<T> other);
  public: Boolean IsSubsetOf(IEnumerable<T> other);
  public: Boolean IsSupersetOf(IEnumerable<T> other);
  public: Boolean Overlaps(IEnumerable<T> other);
  public: Boolean SetEquals(IEnumerable<T> other);
};
} // namespace IReadOnlySetNamespace
template <class T>
using IReadOnlySet = IReadOnlySetNamespace::IReadOnlySet<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
