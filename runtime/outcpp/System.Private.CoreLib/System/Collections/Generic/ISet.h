#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
namespace ISetNamespace {
CLASS(ISet, T) : public Object::in {
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
};
} // namespace ISetNamespace
template <class T>
using ISet = ISetNamespace::ISet<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
