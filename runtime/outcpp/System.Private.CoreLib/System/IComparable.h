#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
namespace IComparableNamespace {
CLASS_FORWARD(IComparable, T1, T2)
CLASS_(IComparable) : public Object::in {
};
CLASS_(IComparable, T) : public Object::in {
};
} // namespace IComparableNamespace
template <class T1 = void, class T2 = void>
using IComparable = IComparableNamespace::IComparable<T1, T2>;
} // namespace System::Private::CoreLib::System
