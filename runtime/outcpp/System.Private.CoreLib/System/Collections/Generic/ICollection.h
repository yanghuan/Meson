#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ICollectionNamespace {
CLASS(ICollection, T) {
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: void Add(T item);
  public: void Clear();
  public: Boolean Contains(T item);
  public: void CopyTo(Array<T> array, Int32 arrayIndex);
  public: Boolean Remove(T item);
};
} // namespace ICollectionNamespace
template <class T>
using ICollection = ICollectionNamespace::ICollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
