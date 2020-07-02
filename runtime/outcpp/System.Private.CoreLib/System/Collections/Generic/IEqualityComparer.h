#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEqualityComparerNamespace {
CLASS(IEqualityComparer, T) {
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
};
} // namespace IEqualityComparerNamespace
template <class T>
using IEqualityComparer = IEqualityComparerNamespace::IEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
