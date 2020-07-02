#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ObjectEqualityComparerNamespace {
CLASS(ObjectEqualityComparer, T) {
  public: Int32 IndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace ObjectEqualityComparerNamespace
template <class T>
using ObjectEqualityComparer = ObjectEqualityComparerNamespace::ObjectEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
