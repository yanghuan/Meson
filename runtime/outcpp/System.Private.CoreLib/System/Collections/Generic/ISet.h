#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
namespace ISetNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
CLASS(ISet, T) : public object {
  public: using interface = rt::TypeList<ICollection<T>, IEnumerable<T>, IEnumerable_>;
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: IEnumerator<T> GetEnumerator();
  public: void Add(T item);
  public: void Clear();
  public: Boolean Contains(T item);
  public: void CopyTo(Array<T> array, Int32 arrayIndex);
  public: Boolean Remove(T item);
  public: Boolean Add(T item);
  public: void UnionWith(IEnumerable<T> other);
  public: void IntersectWith(IEnumerable<T> other);
  public: void ExceptWith(IEnumerable<T> other);
  public: void SymmetricExceptWith(IEnumerable<T> other);
  public: Boolean IsSubsetOf(IEnumerable<T> other);
  public: Boolean IsSupersetOf(IEnumerable<T> other);
  public: Boolean IsProperSupersetOf(IEnumerable<T> other);
  public: Boolean IsProperSubsetOf(IEnumerable<T> other);
  public: Boolean Overlaps(IEnumerable<T> other);
  public: Boolean SetEquals(IEnumerable<T> other);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ISetNamespace
template <class T>
using ISet = ISetNamespace::ISet<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
