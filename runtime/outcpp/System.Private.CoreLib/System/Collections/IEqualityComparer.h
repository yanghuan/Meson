#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IEqualityComparerNamespace {
CLASS(IEqualityComparer) {
  public: Boolean Equals(Object x, Object y);
  public: Int32 GetHashCode(Object obj);
};
} // namespace IEqualityComparerNamespace
using IEqualityComparer = IEqualityComparerNamespace::IEqualityComparer;
} // namespace System::Private::CoreLib::System::Collections
