#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/EqualityComparer.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace NullableEqualityComparerNamespace {
CLASS(NullableEqualityComparer, T) : public EqualityComparer<Nullable<T>>::in {
  public: Int32 IndexOf(Array<Nullable<T>> array, Nullable<T> value, Int32 startIndex, Int32 count);
  public: Int32 LastIndexOf(Array<Nullable<T>> array, Nullable<T> value, Int32 startIndex, Int32 count);
  public: Boolean Equals(Nullable<T> x, Nullable<T> y);
  public: Int32 GetHashCode(Nullable<T> obj);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void Ctor();
};
} // namespace NullableEqualityComparerNamespace
template <class T>
using NullableEqualityComparer = NullableEqualityComparerNamespace::NullableEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
