#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace GenericComparerNamespace {
CLASS(GenericComparer, T) {
  public: Int32 Compare(T x, T y);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
};
} // namespace GenericComparerNamespace
template <class T>
using GenericComparer = GenericComparerNamespace::GenericComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
