#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS_(Nullable, T1, T2)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace NullableComparerNamespace {
CLASS(NullableComparer, T) {
  public: Int32 Compare(Nullable<T> x, Nullable<T> y);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace NullableComparerNamespace
template <class T>
using NullableComparer = NullableComparerNamespace::NullableComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
