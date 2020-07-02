#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace IComparableNamespace {
CLASS_FORWARD(IComparable, T1, T2)
CLASS_(IComparable) {
};
CLASS_(IComparable, T) {
};
} // namespace IComparableNamespace
template <class T1 = void, class T2 = void>
using IComparable = IComparableNamespace::IComparable<T1, T2>;
} // namespace System::Private::CoreLib::System
