#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS_(Nullable, T1, T2)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace NullableEqualityComparerNamespace {
CLASS(NullableEqualityComparer, T) {
  public: Int32 IndexOf(Array<Nullable<T>> array, Nullable<T> value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<Nullable<T>> array, Nullable<T> value, Int32 startIndex, Int32 count);
  public: Boolean Equals(Nullable<T> x, Nullable<T> y);
  public: Int32 GetHashCode(Nullable<T> obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace NullableEqualityComparerNamespace
template <class T>
using NullableEqualityComparer = NullableEqualityComparerNamespace::NullableEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
