#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
namespace IStructuralComparableNamespace {
CLASS(IStructuralComparable) {
  public: Int32 CompareTo(Object other, IComparer comparer);
};
} // namespace IStructuralComparableNamespace
using IStructuralComparable = IStructuralComparableNamespace::IStructuralComparable;
} // namespace System::Private::CoreLib::System::Collections
