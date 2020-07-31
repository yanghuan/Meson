#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IEqualityComparerNamespace {
CLASS(IEqualityComparer, T) : public Object::in {
  public: Boolean Equals(T x, T y);
  public: Int32 GetHashCode(T obj);
};
} // namespace IEqualityComparerNamespace
template <class T>
using IEqualityComparer = IEqualityComparerNamespace::IEqualityComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
