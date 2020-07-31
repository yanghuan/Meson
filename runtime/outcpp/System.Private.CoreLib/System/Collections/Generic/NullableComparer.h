#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Collections/Generic/Comparer.h>
#include <System.Private.CoreLib/System/Nullable.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace NullableComparerNamespace {
CLASS(NullableComparer, T) : public Comparer<Nullable<T>>::in {
  public: Int32 Compare(Nullable<T> x, Nullable<T> y);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: void Ctor();
};
} // namespace NullableComparerNamespace
template <class T>
using NullableComparer = NullableComparerNamespace::NullableComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
