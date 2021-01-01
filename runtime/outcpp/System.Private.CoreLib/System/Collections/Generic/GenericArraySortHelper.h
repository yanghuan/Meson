#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD_(IArraySortHelper, T1, T2, T3)
FORWARD(IComparer, T)
namespace GenericArraySortHelperNamespace {
template <class T>
using IComparer = Generic::IComparer<T>;
CLASS_FORWARD(GenericArraySortHelper, T1, T2, T3)
CLASS_(GenericArraySortHelper, T) : public object {
  public: using interface = rt::TypeList<IArraySortHelper<T>>;
  public: void Sort(Span<T> keys, IComparer<T> comparer);
  public: Int32 BinarySearch(Array<T> array, Int32 index, Int32 length, T value, IComparer<T> comparer);
  private: static Int32 BinarySearch(Array<T> array, Int32 index, Int32 length, T value);
  private: static void SwapIfGreater(T& i, T& j);
  private: static void Swap(T& i, T& j);
  private: static void IntroSort(Span<T> keys, Int32 depthLimit);
  private: static Int32 PickPivotAndPartition(Span<T> keys);
  private: static void HeapSort(Span<T> keys);
  private: static void DownHeap(Span<T> keys, Int32 i, Int32 n, Int32 lo);
  private: static void InsertionSort(Span<T> keys);
  public: void ctor();
};
CLASS_(GenericArraySortHelper, TKey, TValue) : public object {
  public: using interface = rt::TypeList<IArraySortHelper<TKey, TValue>>;
  public: void Sort(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  private: static void SwapIfGreaterWithValues(Span<TKey> keys, Span<TValue> values, Int32 i, Int32 j);
  private: static void Swap(Span<TKey> keys, Span<TValue> values, Int32 i, Int32 j);
  public: static void IntrospectiveSort(Span<TKey> keys, Span<TValue> values);
  private: static void IntroSort(Span<TKey> keys, Span<TValue> values, Int32 depthLimit);
  private: static Int32 PickPivotAndPartition(Span<TKey> keys, Span<TValue> values);
  private: static void HeapSort(Span<TKey> keys, Span<TValue> values);
  private: static void DownHeap(Span<TKey> keys, Span<TValue> values, Int32 i, Int32 n, Int32 lo);
  private: static void InsertionSort(Span<TKey> keys, Span<TValue> values);
  public: void ctor();
};
} // namespace GenericArraySortHelperNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using GenericArraySortHelper = GenericArraySortHelperNamespace::GenericArraySortHelper<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
