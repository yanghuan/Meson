#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(Comparison, T)
FORWARD(Converter, TInput, TOutput)
FORWARD(Predicate, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IComparer, T)
FORWARD(IEnumerable, T)
namespace ListNamespace {
using namespace ObjectModel;
CLASS(List, T) : public Object::in {
  public: struct Enumerator {
    public: T get_Current();
    private: Object get_CurrentOfIEnumerator();
    public: explicit Enumerator(List<T> list);
    public: void Dispose();
    public: Boolean MoveNext();
    private: Boolean MoveNextRare();
    public: explicit Enumerator() {}
    private: List<T> _list;
    private: Int32 _index;
    private: Int32 _version;
    private: T _current;
  };
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int32 get_Count();
  private: Boolean get_IsFixedSizeOfIList();
  private: Boolean get_IsReadOnlyOfICollectionT();
  private: Boolean get_IsReadOnlyOfIList();
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  private: Object get_ItemOfIList(Int32 index);
  private: void set_ItemOfIList(Int32 index, Object value);
  public: void Ctor();
  public: void Ctor(Int32 capacity);
  public: void Ctor(IEnumerable<T> collection);
  private: static Boolean IsCompatibleObject(Object value);
  public: void Add(T item);
  private: void AddWithResize(T item);
  public: void AddRange(IEnumerable<T> collection);
  public: ReadOnlyCollection<T> AsReadOnly();
  public: Int32 BinarySearch(Int32 index, Int32 count, T item, IComparer<T> comparer);
  public: Int32 BinarySearch(T item);
  public: Int32 BinarySearch(T item, IComparer<T> comparer);
  public: void Clear();
  public: Boolean Contains(T item);
  public: template <class TOutput>
  List<TOutput> ConvertAll(Converter<T, TOutput> converter);
  public: void CopyTo(Array<T> array);
  public: void CopyTo(Int32 index, Array<T> array, Int32 arrayIndex, Int32 count);
  public: void CopyTo(Array<T> array, Int32 arrayIndex);
  private: void EnsureCapacity(Int32 min);
  public: Boolean Exists(Predicate<T> match);
  public: T Find(Predicate<T> match);
  public: List<T> FindAll(Predicate<T> match);
  public: Int32 FindIndex(Predicate<T> match);
  public: Int32 FindIndex(Int32 startIndex, Predicate<T> match);
  public: Int32 FindIndex(Int32 startIndex, Int32 count, Predicate<T> match);
  public: T FindLast(Predicate<T> match);
  public: Int32 FindLastIndex(Predicate<T> match);
  public: Int32 FindLastIndex(Int32 startIndex, Predicate<T> match);
  public: Int32 FindLastIndex(Int32 startIndex, Int32 count, Predicate<T> match);
  public: void ForEach(Action<T> action);
  public: Enumerator GetEnumerator();
  public: List<T> GetRange(Int32 index, Int32 count);
  public: Int32 IndexOf(T item);
  public: Int32 IndexOf(T item, Int32 index);
  public: Int32 IndexOf(T item, Int32 index, Int32 count);
  public: void Insert(Int32 index, T item);
  public: void InsertRange(Int32 index, IEnumerable<T> collection);
  public: Int32 LastIndexOf(T item);
  public: Int32 LastIndexOf(T item, Int32 index);
  public: Int32 LastIndexOf(T item, Int32 index, Int32 count);
  public: Boolean Remove(T item);
  public: Int32 RemoveAll(Predicate<T> match);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: void Reverse();
  public: void Reverse(Int32 index, Int32 count);
  public: void Sort();
  public: void Sort(IComparer<T> comparer);
  public: void Sort(Int32 index, Int32 count, IComparer<T> comparer);
  public: void Sort(Comparison<T> comparison);
  public: Array<T> ToArray();
  public: void TrimExcess();
  public: Boolean TrueForAll(Predicate<T> match);
  private: static void SCtor();
  public: Array<T> _items;
  public: Int32 _size;
  private: Int32 _version;
  private: static Array<T> s_emptyArray;
};
} // namespace ListNamespace
template <class T>
using List = ListNamespace::List<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
