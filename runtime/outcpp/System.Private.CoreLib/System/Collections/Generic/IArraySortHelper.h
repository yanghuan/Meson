#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace IArraySortHelperNamespace {
CLASS_FORWARD(IArraySortHelper, T1, T2, T3)
CLASS_(IArraySortHelper, TKey) {
};
CLASS_(IArraySortHelper, TKey, TValue) {
};
} // namespace IArraySortHelperNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using IArraySortHelper = IArraySortHelperNamespace::IArraySortHelper<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
