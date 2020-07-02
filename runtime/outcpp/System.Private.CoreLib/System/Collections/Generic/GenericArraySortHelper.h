#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace GenericArraySortHelperNamespace {
CLASS_FORWARD(GenericArraySortHelper, T1, T2, T3)
CLASS_(GenericArraySortHelper, T) {
};
CLASS_(GenericArraySortHelper, TKey, TValue) {
};
} // namespace GenericArraySortHelperNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using GenericArraySortHelper = GenericArraySortHelperNamespace::GenericArraySortHelper<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
