#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
namespace IStructuralComparableNamespace {
CLASS(IStructuralComparable) : public Object::in {
  public: Int32 CompareTo(Object other, IComparer comparer);
};
} // namespace IStructuralComparableNamespace
using IStructuralComparable = IStructuralComparableNamespace::IStructuralComparable;
} // namespace System::Private::CoreLib::System::Collections
