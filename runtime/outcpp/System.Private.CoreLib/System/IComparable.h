#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
namespace IComparableNamespace {
CLASS_FORWARD(IComparable, T1, T2)
CLASS_(IComparable) : public Object::in {
  public: Int32 CompareTo(Object obj);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
CLASS_(IComparable, T) : public Object::in {
  public: Int32 CompareTo(T other);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IComparableNamespace
template <class T1 = void, class T2 = void>
using IComparable = IComparableNamespace::IComparable<T1, T2>;
} // namespace System::Private::CoreLib::System
