#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IReadOnlyCollection, T)
namespace IReadOnlySetNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
CLASS(IReadOnlySet, T) : public Object::in {
  public: using interface = rt::TypeList<IReadOnlyCollection<T>, IEnumerable<T>, IEnumerable_>;
  public: Boolean Contains(T item);
  public: Boolean IsProperSubsetOf(IEnumerable<T> other);
  public: Boolean IsProperSupersetOf(IEnumerable<T> other);
  public: Boolean IsSubsetOf(IEnumerable<T> other);
  public: Boolean IsSupersetOf(IEnumerable<T> other);
  public: Boolean Overlaps(IEnumerable<T> other);
  public: Boolean SetEquals(IEnumerable<T> other);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlySetNamespace
template <class T>
using IReadOnlySet = IReadOnlySetNamespace::IReadOnlySet<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
