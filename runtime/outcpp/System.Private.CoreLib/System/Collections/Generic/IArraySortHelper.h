#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IComparer, T)
namespace IArraySortHelperNamespace {
template <class T>
using IComparer = Generic::IComparer<T>;
CLASS_FORWARD(IArraySortHelper, T1, T2, T3)
CLASS_(IArraySortHelper, TKey) : public object {
  public: void Sort(Span<TKey> keys, IComparer<TKey> comparer);
  public: Int32 BinarySearch(Array<TKey> keys, Int32 index, Int32 length, TKey value, IComparer<TKey> comparer);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
CLASS_(IArraySortHelper, TKey, TValue) : public object {
  public: void Sort(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IArraySortHelperNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using IArraySortHelper = IArraySortHelperNamespace::IArraySortHelper<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
