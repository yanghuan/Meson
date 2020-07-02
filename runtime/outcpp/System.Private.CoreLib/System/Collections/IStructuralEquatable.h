#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEqualityComparer)
namespace IStructuralEquatableNamespace {
CLASS(IStructuralEquatable) {
  public: Boolean Equals(Object other, IEqualityComparer comparer);
  public: Int32 GetHashCode(IEqualityComparer comparer);
};
} // namespace IStructuralEquatableNamespace
using IStructuralEquatable = IStructuralEquatableNamespace::IStructuralEquatable;
} // namespace System::Private::CoreLib::System::Collections
