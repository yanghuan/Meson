#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
namespace IStructuralComparableNamespace {
CLASS(IStructuralComparable) : public object {
  public: Int32 CompareTo(Object other, IComparer comparer);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IStructuralComparableNamespace
using IStructuralComparable = IStructuralComparableNamespace::IStructuralComparable;
} // namespace System::Private::CoreLib::System::Collections
