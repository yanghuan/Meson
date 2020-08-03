#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD_(IArraySortHelper, T1, T2, T3)
namespace ArraySortHelperNamespace {
CLASS_FORWARD(ArraySortHelper, T1, T2, T3)
CLASS_(ArraySortHelper, T) : public Object::in {
  public: static IArraySortHelper<T> get_Default();
  private: static IArraySortHelper<T> s_defaultArraySortHelper;
};
CLASS_(ArraySortHelper, TKey, TValue) : public Object::in {
  public: static IArraySortHelper<TKey, TValue> get_Default();
  private: static IArraySortHelper<TKey, TValue> s_defaultArraySortHelper;
};
} // namespace ArraySortHelperNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using ArraySortHelper = ArraySortHelperNamespace::ArraySortHelper<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
