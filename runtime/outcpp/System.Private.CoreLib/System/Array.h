#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IComparer)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
FORWARD(IEqualityComparer)
FORWARD(IList)
FORWARD(IStructuralComparable)
FORWARD(IStructuralEquatable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IComparer, T)
FORWARD(IList, T)
FORWARD(IReadOnlyCollection, T)
FORWARD(IReadOnlyList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class CorElementType : uint8_t;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
FORWARD(Comparison, T)
FORWARD(Converter, TInput, TOutput)
FORWARD(ICloneable)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Predicate, T)
FORWARDS(Span, T)
FORWARD(Type)
namespace ArrayNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace System::Reflection;
using IList = Collections::IList;
using ICollection = Collections::ICollection;
using IEnumerable = Collections::IEnumerable;
template <class T>
using IList_ = Collections::Generic::IList<T>;
using IComparer = Collections::IComparer;
using IEqualityComparer = Collections::IEqualityComparer;
template <class T>
using IComparer_ = Collections::Generic::IComparer<T>;
using IEnumerator = Collections::IEnumerator;
CLASS_FORWARD(Array)
CLASS_(Array, T1);
CLASS_(Array) : public object {
  public: using interface = rt::TypeList<ICloneable, IList, ICollection, IEnumerable, IStructuralComparable, IStructuralEquatable>;
  private: template <class T>
  class EmptyArray {
    public: static void cctor();
    public: static Array<T> Value;
  };
  private: struct SorterObjectArray : public valueType<SorterObjectArray> {
    public: explicit SorterObjectArray(Array<Object> keys, Array<Object> items, IComparer comparer);
    public: void SwapIfGreater(Int32 a, Int32 b);
    private: void Swap(Int32 i, Int32 j);
    public: void Sort(Int32 left, Int32 length);
    private: void IntrospectiveSort(Int32 left, Int32 length);
    private: void IntroSort(Int32 lo, Int32 hi, Int32 depthLimit);
    private: Int32 PickPivotAndPartition(Int32 lo, Int32 hi);
    private: void Heapsort(Int32 lo, Int32 hi);
    private: void DownHeap(Int32 i, Int32 n, Int32 lo);
    private: void InsertionSort(Int32 lo, Int32 hi);
    public: explicit SorterObjectArray() {}
    private: Array<Object> keys;
    private: Array<Object> items;
    private: IComparer comparer;
  };
  private: struct SorterGenericArray : public valueType<SorterGenericArray> {
    public: explicit SorterGenericArray(Array<> keys, Array<> items, IComparer comparer);
    public: void SwapIfGreater(Int32 a, Int32 b);
    private: void Swap(Int32 i, Int32 j);
    public: void Sort(Int32 left, Int32 length);
    private: void IntrospectiveSort(Int32 left, Int32 length);
    private: void IntroSort(Int32 lo, Int32 hi, Int32 depthLimit);
    private: Int32 PickPivotAndPartition(Int32 lo, Int32 hi);
    private: void Heapsort(Int32 lo, Int32 hi);
    private: void DownHeap(Int32 i, Int32 n, Int32 lo);
    private: void InsertionSort(Int32 lo, Int32 hi);
    public: explicit SorterGenericArray() {}
    private: Array<> keys;
    private: Array<> items;
    private: IComparer comparer;
  };
  public: Int32 get_Length();
  public: Int64 get_LongLength();
  public: Int32 get_Rank();
  private: Int32 get_CountOfICollection();
  public: Object get_SyncRoot();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  private: Object get_ItemOfIList(Int32 index);
  private: void set_ItemOfIList(Int32 index, Object value);
  public: static Array<> CreateInstance(Type elementType, Int32 length);
  public: static Array<> CreateInstance(Type elementType, Int32 length1, Int32 length2);
  public: static Array<> CreateInstance(Type elementType, Int32 length1, Int32 length2, Int32 length3);
  public: static Array<> CreateInstance(Type elementType, Array<Int32> lengths);
  public: static Array<> CreateInstance(Type elementType, Array<Int32> lengths, Array<Int32> lowerBounds);
  private: static Array<> InternalCreate(void* elementType, Int32 rank, Int32* pLengths, Int32* pLowerBounds);
  public: static void Copy(Array<> sourceArray, Array<> destinationArray, Int32 length);
  public: static void Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length);
  private: static void Copy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length, Boolean reliable);
  private: static Boolean IsSimpleCopy(Array<> sourceArray, Array<> destinationArray);
  private: static void CopySlow(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length);
  public: static void ConstrainedCopy(Array<> sourceArray, Int32 sourceIndex, Array<> destinationArray, Int32 destinationIndex, Int32 length);
  public: static void Clear(Array<> array, Int32 index, Int32 length);
  public: Object GetValue(Array<Int32> indices);
  public: Object GetValue(Int32 index);
  public: Object GetValue(Int32 index1, Int32 index2);
  public: Object GetValue(Int32 index1, Int32 index2, Int32 index3);
  public: void SetValue(Object value, Int32 index);
  public: void SetValue(Object value, Int32 index1, Int32 index2);
  public: void SetValue(Object value, Int32 index1, Int32 index2, Int32 index3);
  public: void SetValue(Object value, Array<Int32> indices);
  private: void InternalGetReference(void* elemRef, Int32 rank, Int32* pIndices);
  private: static void InternalSetValue(void* target, Object value);
  public: Int32 GetLength(Int32 dimension);
  public: Int32 GetUpperBound(Int32 dimension);
  public: Int32 GetLowerBound(Int32 dimension);
  public: CorElementType GetCorElementTypeOfElementType();
  private: Boolean IsValueOfElementType(Object value);
  public: void Initialize();
  public: void ctor();
  public: template <class T>
  static ReadOnlyCollection<T> AsReadOnly(Array<T> array);
  public: template <class T>
  static void Resize(Array<T>& array, Int32 newSize);
  public: static Array<> CreateInstance(Type elementType, Array<Int64> lengths);
  public: static void Copy(Array<> sourceArray, Array<> destinationArray, Int64 length);
  public: static void Copy(Array<> sourceArray, Int64 sourceIndex, Array<> destinationArray, Int64 destinationIndex, Int64 length);
  public: Object GetValue(Int64 index);
  public: Object GetValue(Int64 index1, Int64 index2);
  public: Object GetValue(Int64 index1, Int64 index2, Int64 index3);
  public: Object GetValue(Array<Int64> indices);
  public: void SetValue(Object value, Int64 index);
  public: void SetValue(Object value, Int64 index1, Int64 index2);
  public: void SetValue(Object value, Int64 index1, Int64 index2, Int64 index3);
  public: void SetValue(Object value, Array<Int64> indices);
  private: static Int32 GetMedian(Int32 low, Int32 hi);
  public: Int64 GetLongLength(Int32 dimension);
  private: Int32 AddOfIList(Object value);
  private: Boolean ContainsOfIList(Object value);
  private: void ClearOfIList();
  private: Int32 IndexOfOfIList(Object value);
  private: void InsertOfIList(Int32 index, Object value);
  private: void RemoveOfIList(Object value);
  private: void RemoveAtOfIList(Int32 index);
  public: Object Clone();
  private: Int32 CompareToOfIStructuralComparable(Object other, IComparer comparer);
  private: Boolean EqualsOfIStructuralEquatable(Object other, IEqualityComparer comparer);
  private: Int32 GetHashCodeOfIStructuralEquatable(IEqualityComparer comparer);
  public: static Int32 BinarySearch(Array<> array, Object value);
  public: static Int32 BinarySearch(Array<> array, Int32 index, Int32 length, Object value);
  public: static Int32 BinarySearch(Array<> array, Object value, IComparer comparer);
  public: static Int32 BinarySearch(Array<> array, Int32 index, Int32 length, Object value, IComparer comparer);
  public: template <class T>
  static Int32 BinarySearch(Array<T> array, T value);
  public: template <class T>
  static Int32 BinarySearch(Array<T> array, T value, IComparer_<T> comparer);
  public: template <class T>
  static Int32 BinarySearch(Array<T> array, Int32 index, Int32 length, T value);
  public: template <class T>
  static Int32 BinarySearch(Array<T> array, Int32 index, Int32 length, T value, IComparer_<T> comparer);
  public: template <class TInput, class TOutput>
  static Array<TOutput> ConvertAll(Array<TInput> array, Converter<TInput, TOutput> converter);
  public: void CopyTo(Array<> array, Int32 index);
  public: void CopyTo(Array<> array, Int64 index);
  public: template <class T>
  static Array<T> Empty();
  public: template <class T>
  static Boolean Exists(Array<T> array, Predicate<T> match);
  public: template <class T>
  static void Fill(Array<T> array, T value);
  public: template <class T>
  static void Fill(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: template <class T>
  static T Find(Array<T> array, Predicate<T> match);
  public: template <class T>
  static Array<T> FindAll(Array<T> array, Predicate<T> match);
  public: template <class T>
  static Int32 FindIndex(Array<T> array, Predicate<T> match);
  public: template <class T>
  static Int32 FindIndex(Array<T> array, Int32 startIndex, Predicate<T> match);
  public: template <class T>
  static Int32 FindIndex(Array<T> array, Int32 startIndex, Int32 count, Predicate<T> match);
  public: template <class T>
  static T FindLast(Array<T> array, Predicate<T> match);
  public: template <class T>
  static Int32 FindLastIndex(Array<T> array, Predicate<T> match);
  public: template <class T>
  static Int32 FindLastIndex(Array<T> array, Int32 startIndex, Predicate<T> match);
  public: template <class T>
  static Int32 FindLastIndex(Array<T> array, Int32 startIndex, Int32 count, Predicate<T> match);
  public: template <class T>
  static void ForEach(Array<T> array, Action<T> action);
  public: static Int32 IndexOf(Array<> array, Object value);
  public: static Int32 IndexOf(Array<> array, Object value, Int32 startIndex);
  public: static Int32 IndexOf(Array<> array, Object value, Int32 startIndex, Int32 count);
  public: template <class T>
  static Int32 IndexOf(Array<T> array, T value);
  public: template <class T>
  static Int32 IndexOf(Array<T> array, T value, Int32 startIndex);
  public: template <class T>
  static Int32 IndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: static Int32 LastIndexOf(Array<> array, Object value);
  public: static Int32 LastIndexOf(Array<> array, Object value, Int32 startIndex);
  public: static Int32 LastIndexOf(Array<> array, Object value, Int32 startIndex, Int32 count);
  public: template <class T>
  static Int32 LastIndexOf(Array<T> array, T value);
  public: template <class T>
  static Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex);
  public: template <class T>
  static Int32 LastIndexOf(Array<T> array, T value, Int32 startIndex, Int32 count);
  public: static void Reverse(Array<> array);
  public: static void Reverse(Array<> array, Int32 index, Int32 length);
  public: template <class T>
  static void Reverse(Array<T> array);
  public: template <class T>
  static void Reverse(Array<T> array, Int32 index, Int32 length);
  public: static void Sort(Array<> array);
  public: static void Sort(Array<> keys, Array<> items);
  public: static void Sort(Array<> array, Int32 index, Int32 length);
  public: static void Sort(Array<> keys, Array<> items, Int32 index, Int32 length);
  public: static void Sort(Array<> array, IComparer comparer);
  public: static void Sort(Array<> keys, Array<> items, IComparer comparer);
  public: static void Sort(Array<> array, Int32 index, Int32 length, IComparer comparer);
  public: static void Sort(Array<> keys, Array<> items, Int32 index, Int32 length, IComparer comparer);
  public: template <class T>
  static void Sort(Array<T> array);
  public: template <class TKey, class TValue>
  static void Sort(Array<TKey> keys, Array<TValue> items);
  public: template <class T>
  static void Sort(Array<T> array, Int32 index, Int32 length);
  public: template <class TKey, class TValue>
  static void Sort(Array<TKey> keys, Array<TValue> items, Int32 index, Int32 length);
  public: template <class T>
  static void Sort(Array<T> array, IComparer_<T> comparer);
  public: template <class TKey, class TValue>
  static void Sort(Array<TKey> keys, Array<TValue> items, IComparer_<TKey> comparer);
  public: template <class T>
  static void Sort(Array<T> array, Int32 index, Int32 length, IComparer_<T> comparer);
  public: template <class TKey, class TValue>
  static void Sort(Array<TKey> keys, Array<TValue> items, Int32 index, Int32 length, IComparer_<TKey> comparer);
  public: template <class T>
  static void Sort(Array<T> array, Comparison<T> comparison);
  public: template <class T>
  static Boolean TrueForAll(Array<T> array, Predicate<T> match);
  private: template <class T>
  static Span<T> UnsafeArrayAsSpan(Array<> array, Int32 adjustedIndex, Int32 length);
  public: IEnumerator GetEnumerator();
  public: template <class T>
  static Int32 _BinarySearch_g__GenericBinarySearch81_0(Array<> array, Int32 adjustedIndex, Int32 length, Object value);
  public: template <class T>
  static Int32 _IndexOf_g__GenericIndexOf106_0(Array<> array, Object value, Int32 adjustedIndex, Int32 length);
  public: template <class T>
  static Int32 _LastIndexOf_g__GenericLastIndexOf112_0(Array<> array, Object value, Int32 adjustedIndex, Int32 length);
  public: template <class T>
  static void _Sort_g__GenericSort127_0(Array<> keys, Array<> items, Int32 adjustedIndex, Int32 length);
};
CLASS_(Array, T) : public rt::Array<T, Array<>::in> {
  public: using interface = rt::TypeList<IList_<T>, IReadOnlyList<T>, IReadOnlyCollection<T>, ICloneable, IList, ICollection, IEnumerable, IStructuralComparable, IStructuralEquatable>;
};
} // namespace ArrayNamespace
template <class ...T>
using Array = ArrayNamespace::Array<T...>;
} // namespace System::Private::CoreLib::System
