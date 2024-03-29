#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(Comparison, T)
FORWARDS(Int32)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD_(IArraySortHelper)
FORWARD(IComparer, T)
namespace ArraySortHelperNamespace {
template <class T>
using IComparer = Generic::IComparer<T>;
CLASS_FORWARD(ArraySortHelper)
CLASS_(ArraySortHelper, T) : public object {
  public: using interface = rt::TypeList<IArraySortHelper<T>>;
  public: static IArraySortHelper<T> get_Default();
  private: static IArraySortHelper<T> CreateArraySortHelper();
  public: void Sort(Span<T> keys, IComparer<T> comparer);
  public: Int32 BinarySearch(Array<T> array, Int32 index, Int32 length, T value, IComparer<T> comparer);
  public: static void Sort(Span<T> keys, Comparison<T> comparer);
  public: static Int32 InternalBinarySearch(Array<T> array, Int32 index, Int32 length, T value, IComparer<T> comparer);
  private: static void SwapIfGreater(Span<T> keys, Comparison<T> comparer, Int32 i, Int32 j);
  private: static void Swap(Span<T> a, Int32 i, Int32 j);
  public: static void IntrospectiveSort(Span<T> keys, Comparison<T> comparer);
  private: static void IntroSort(Span<T> keys, Int32 depthLimit, Comparison<T> comparer);
  private: static Int32 PickPivotAndPartition(Span<T> keys, Comparison<T> comparer);
  private: static void HeapSort(Span<T> keys, Comparison<T> comparer);
  private: static void DownHeap(Span<T> keys, Int32 i, Int32 n, Int32 lo, Comparison<T> comparer);
  private: static void InsertionSort(Span<T> keys, Comparison<T> comparer);
  public: void ctor();
  public: static void cctor();
  private: static IArraySortHelper<T> s_defaultArraySortHelper;
};
CLASS_(ArraySortHelper, TKey, TValue) : public object {
  public: using interface = rt::TypeList<IArraySortHelper<TKey, TValue>>;
  public: static IArraySortHelper<TKey, TValue> get_Default();
  private: static IArraySortHelper<TKey, TValue> CreateArraySortHelper();
  public: void Sort(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  private: static void SwapIfGreaterWithValues(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer, Int32 i, Int32 j);
  private: static void Swap(Span<TKey> keys, Span<TValue> values, Int32 i, Int32 j);
  public: static void IntrospectiveSort(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  private: static void IntroSort(Span<TKey> keys, Span<TValue> values, Int32 depthLimit, IComparer<TKey> comparer);
  private: static Int32 PickPivotAndPartition(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  private: static void HeapSort(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  private: static void DownHeap(Span<TKey> keys, Span<TValue> values, Int32 i, Int32 n, Int32 lo, IComparer<TKey> comparer);
  private: static void InsertionSort(Span<TKey> keys, Span<TValue> values, IComparer<TKey> comparer);
  public: void ctor();
  public: static void cctor();
  private: static IArraySortHelper<TKey, TValue> s_defaultArraySortHelper;
};
} // namespace ArraySortHelperNamespace
template <class ...T>
using ArraySortHelper = ArraySortHelperNamespace::ArraySortHelper<T...>;
} // namespace System::Private::CoreLib::System::Collections::Generic
