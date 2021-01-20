#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
namespace IComparableNamespace {
CLASS_FORWARD(IComparable)
CLASS_(IComparable) : public object {
  public: Int32 CompareTo(Object obj);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
CLASS_(IComparable, T) : public object {
  public: Int32 CompareTo(T other);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IComparableNamespace
template <class ...T>
using IComparable = IComparableNamespace::IComparable<T...>;
} // namespace System::Private::CoreLib::System
