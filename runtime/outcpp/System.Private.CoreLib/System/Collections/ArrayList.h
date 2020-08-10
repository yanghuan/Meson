#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(ICloneable)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IComparer)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
FORWARD(IList)
namespace ArrayListNamespace {
CLASS(ArrayList) : public Object::in {
  public: using interface = rt::TypeList<IList, ICollection, IEnumerable, ICloneable>;
  private: FRIENDN(IListWrapper)
  private: FRIENDN(SyncArrayList)
  private: CLASS(SyncIList) : public Object::in {
    public: using interface = rt::TypeList<IList, ICollection, IEnumerable>;
    public: Int32 get_Count();
    public: Boolean get_IsReadOnly();
    public: Boolean get_IsFixedSize();
    public: Boolean get_IsSynchronized();
    public: Object get_Item(Int32 index);
    public: void set_Item(Int32 index, Object value);
    public: Object get_SyncRoot();
    public: void ctor(IList list);
    public: Int32 Add(Object value);
    public: void Clear();
    public: Boolean Contains(Object item);
    public: void CopyTo(Array<> array, Int32 index);
    public: IEnumerator GetEnumerator();
    public: Int32 IndexOf(Object value);
    public: void Insert(Int32 index, Object value);
    public: void Remove(Object value);
    public: void RemoveAt(Int32 index);
    private: IList _list;
    private: Object _root;
  };
  private: CLASS(FixedSizeList) : public Object::in {
    public: using interface = rt::TypeList<IList, ICollection, IEnumerable>;
    public: Int32 get_Count();
    public: Boolean get_IsReadOnly();
    public: Boolean get_IsFixedSize();
    public: Boolean get_IsSynchronized();
    public: Object get_Item(Int32 index);
    public: void set_Item(Int32 index, Object value);
    public: Object get_SyncRoot();
    public: void ctor(IList l);
    public: Int32 Add(Object obj);
    public: void Clear();
    public: Boolean Contains(Object obj);
    public: void CopyTo(Array<> array, Int32 index);
    public: IEnumerator GetEnumerator();
    public: Int32 IndexOf(Object value);
    public: void Insert(Int32 index, Object obj);
    public: void Remove(Object value);
    public: void RemoveAt(Int32 index);
    private: IList _list;
  };
  private: FRIENDN(FixedSizeArrayList)
  private: CLASS(ReadOnlyList) : public Object::in {
    public: using interface = rt::TypeList<IList, ICollection, IEnumerable>;
    public: Int32 get_Count();
    public: Boolean get_IsReadOnly();
    public: Boolean get_IsFixedSize();
    public: Boolean get_IsSynchronized();
    public: Object get_Item(Int32 index);
    public: void set_Item(Int32 index, Object value);
    public: Object get_SyncRoot();
    public: void ctor(IList l);
    public: Int32 Add(Object obj);
    public: void Clear();
    public: Boolean Contains(Object obj);
    public: void CopyTo(Array<> array, Int32 index);
    public: IEnumerator GetEnumerator();
    public: Int32 IndexOf(Object value);
    public: void Insert(Int32 index, Object obj);
    public: void Remove(Object value);
    public: void RemoveAt(Int32 index);
    private: IList _list;
  };
  private: FRIENDN(ReadOnlyArrayList)
  private: CLASS(ArrayListEnumerator) : public Object::in {
    public: using interface = rt::TypeList<IEnumerator, ICloneable>;
    public: Object get_Current();
    public: void ctor(ArrayList list, Int32 index, Int32 count);
    public: Object Clone();
    public: Boolean MoveNext();
    public: void Reset();
    private: ArrayList _list;
    private: Int32 _index;
    private: Int32 _endIndex;
    private: Int32 _version;
    private: Object _currentElement;
    private: Int32 _startIndex;
  };
  private: FRIENDN(Range)
  private: CLASS(ArrayListEnumeratorSimple) : public Object::in {
    public: using interface = rt::TypeList<IEnumerator, ICloneable>;
    public: Object get_Current();
    public: void ctor(ArrayList list);
    public: Object Clone();
    public: Boolean MoveNext();
    public: void Reset();
    private: static void ctor_static();
    private: ArrayList _list;
    private: Int32 _index;
    private: Int32 _version;
    private: Object _currentElement;
    private: Boolean _isArrayList;
    private: static Object s_dummyObject;
  };
  public: CLASS(ArrayListDebugView) : public Object::in {
    public: Array<Object> get_Items();
    public: void ctor(ArrayList arrayList);
    private: ArrayList _arrayList;
  };
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int32 get_Count();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsSynchronized();
  public: Object get_SyncRoot();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: void ctor();
  public: void ctor(Int32 capacity);
  public: void ctor(ICollection c);
  public: static ArrayList Adapter(IList list);
  public: Int32 Add(Object value);
  public: void AddRange(ICollection c);
  public: Int32 BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer);
  public: Int32 BinarySearch(Object value);
  public: Int32 BinarySearch(Object value, IComparer comparer);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object item);
  public: void CopyTo(Array<> array);
  public: void CopyTo(Array<> array, Int32 arrayIndex);
  public: void CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count);
  private: void EnsureCapacity(Int32 min);
  public: static IList FixedSize(IList list);
  public: static ArrayList FixedSize(ArrayList list);
  public: IEnumerator GetEnumerator();
  public: IEnumerator GetEnumerator(Int32 index, Int32 count);
  public: Int32 IndexOf(Object value);
  public: Int32 IndexOf(Object value, Int32 startIndex);
  public: Int32 IndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Insert(Int32 index, Object value);
  public: void InsertRange(Int32 index, ICollection c);
  public: Int32 LastIndexOf(Object value);
  public: Int32 LastIndexOf(Object value, Int32 startIndex);
  public: Int32 LastIndexOf(Object value, Int32 startIndex, Int32 count);
  public: static IList ReadOnly(IList list);
  public: static ArrayList ReadOnly(ArrayList list);
  public: void Remove(Object obj);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: static ArrayList Repeat(Object value, Int32 count);
  public: void Reverse();
  public: void Reverse(Int32 index, Int32 count);
  public: void SetRange(Int32 index, ICollection c);
  public: ArrayList GetRange(Int32 index, Int32 count);
  public: void Sort();
  public: void Sort(IComparer comparer);
  public: void Sort(Int32 index, Int32 count, IComparer comparer);
  public: static IList Synchronized(IList list);
  public: static ArrayList Synchronized(ArrayList list);
  public: Array<Object> ToArray();
  public: Array<> ToArray(Type type);
  public: void TrimToSize();
  private: Array<Object> _items;
  private: Int32 _size;
  private: Int32 _version;
};
CLASS(IListWrapper) : public ArrayList::in {
  private: CLASS(IListWrapperEnumWrapper) : public Object::in {
    public: using interface = rt::TypeList<IEnumerator, ICloneable>;
    public: Object get_Current();
    public: void ctor(IListWrapper listWrapper, Int32 startIndex, Int32 count);
    private: void ctor();
    public: Object Clone();
    public: Boolean MoveNext();
    public: void Reset();
    private: IEnumerator _en;
    private: Int32 _remaining;
    private: Int32 _initialStartIndex;
    private: Int32 _initialCount;
    private: Boolean _firstCall;
  };
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: Object get_SyncRoot();
  public: void ctor(IList list);
  public: Int32 Add(Object obj);
  public: void AddRange(ICollection c);
  public: Int32 BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object obj);
  public: void CopyTo(Array<> array, Int32 index);
  public: void CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count);
  public: IEnumerator GetEnumerator();
  public: IEnumerator GetEnumerator(Int32 index, Int32 count);
  public: Int32 IndexOf(Object value);
  public: Int32 IndexOf(Object value, Int32 startIndex);
  public: Int32 IndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Insert(Int32 index, Object obj);
  public: void InsertRange(Int32 index, ICollection c);
  public: Int32 LastIndexOf(Object value);
  public: Int32 LastIndexOf(Object value, Int32 startIndex);
  public: Int32 LastIndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Remove(Object value);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: void Reverse(Int32 index, Int32 count);
  public: void SetRange(Int32 index, ICollection c);
  public: ArrayList GetRange(Int32 index, Int32 count);
  public: void Sort(Int32 index, Int32 count, IComparer comparer);
  public: Array<Object> ToArray();
  public: Array<> ToArray(Type type);
  public: void TrimToSize();
  private: IList _list;
};
CLASS(SyncArrayList) : public ArrayList::in {
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: Object get_SyncRoot();
  public: void ctor(ArrayList list);
  public: Int32 Add(Object value);
  public: void AddRange(ICollection c);
  public: Int32 BinarySearch(Object value);
  public: Int32 BinarySearch(Object value, IComparer comparer);
  public: Int32 BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object item);
  public: void CopyTo(Array<> array);
  public: void CopyTo(Array<> array, Int32 index);
  public: void CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count);
  public: IEnumerator GetEnumerator();
  public: IEnumerator GetEnumerator(Int32 index, Int32 count);
  public: Int32 IndexOf(Object value);
  public: Int32 IndexOf(Object value, Int32 startIndex);
  public: Int32 IndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Insert(Int32 index, Object value);
  public: void InsertRange(Int32 index, ICollection c);
  public: Int32 LastIndexOf(Object value);
  public: Int32 LastIndexOf(Object value, Int32 startIndex);
  public: Int32 LastIndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Remove(Object value);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: void Reverse(Int32 index, Int32 count);
  public: void SetRange(Int32 index, ICollection c);
  public: ArrayList GetRange(Int32 index, Int32 count);
  public: void Sort();
  public: void Sort(IComparer comparer);
  public: void Sort(Int32 index, Int32 count, IComparer comparer);
  public: Array<Object> ToArray();
  public: Array<> ToArray(Type type);
  public: void TrimToSize();
  private: ArrayList _list;
  private: Object _root;
};
CLASS(FixedSizeArrayList) : public ArrayList::in {
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: Object get_SyncRoot();
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: void ctor(ArrayList l);
  public: Int32 Add(Object obj);
  public: void AddRange(ICollection c);
  public: Int32 BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object obj);
  public: void CopyTo(Array<> array, Int32 index);
  public: void CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count);
  public: IEnumerator GetEnumerator();
  public: IEnumerator GetEnumerator(Int32 index, Int32 count);
  public: Int32 IndexOf(Object value);
  public: Int32 IndexOf(Object value, Int32 startIndex);
  public: Int32 IndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Insert(Int32 index, Object obj);
  public: void InsertRange(Int32 index, ICollection c);
  public: Int32 LastIndexOf(Object value);
  public: Int32 LastIndexOf(Object value, Int32 startIndex);
  public: Int32 LastIndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Remove(Object value);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: void SetRange(Int32 index, ICollection c);
  public: ArrayList GetRange(Int32 index, Int32 count);
  public: void Reverse(Int32 index, Int32 count);
  public: void Sort(Int32 index, Int32 count, IComparer comparer);
  public: Array<Object> ToArray();
  public: Array<> ToArray(Type type);
  public: void TrimToSize();
  private: ArrayList _list;
};
CLASS(ReadOnlyArrayList) : public ArrayList::in {
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: Object get_SyncRoot();
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: void ctor(ArrayList l);
  public: Int32 Add(Object obj);
  public: void AddRange(ICollection c);
  public: Int32 BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object obj);
  public: void CopyTo(Array<> array, Int32 index);
  public: void CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count);
  public: IEnumerator GetEnumerator();
  public: IEnumerator GetEnumerator(Int32 index, Int32 count);
  public: Int32 IndexOf(Object value);
  public: Int32 IndexOf(Object value, Int32 startIndex);
  public: Int32 IndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Insert(Int32 index, Object obj);
  public: void InsertRange(Int32 index, ICollection c);
  public: Int32 LastIndexOf(Object value);
  public: Int32 LastIndexOf(Object value, Int32 startIndex);
  public: Int32 LastIndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Remove(Object value);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: void SetRange(Int32 index, ICollection c);
  public: ArrayList GetRange(Int32 index, Int32 count);
  public: void Reverse(Int32 index, Int32 count);
  public: void Sort(Int32 index, Int32 count, IComparer comparer);
  public: Array<Object> ToArray();
  public: Array<> ToArray(Type type);
  public: void TrimToSize();
  private: ArrayList _list;
};
CLASS(Range) : public ArrayList::in {
  public: Int32 get_Capacity();
  public: void set_Capacity(Int32 value);
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_SyncRoot();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: void ctor(ArrayList list, Int32 index, Int32 count);
  private: void InternalUpdateRange();
  private: void InternalUpdateVersion();
  public: Int32 Add(Object value);
  public: void AddRange(ICollection c);
  public: Int32 BinarySearch(Int32 index, Int32 count, Object value, IComparer comparer);
  public: void Clear();
  public: Object Clone();
  public: Boolean Contains(Object item);
  public: void CopyTo(Array<> array, Int32 index);
  public: void CopyTo(Int32 index, Array<> array, Int32 arrayIndex, Int32 count);
  public: IEnumerator GetEnumerator();
  public: IEnumerator GetEnumerator(Int32 index, Int32 count);
  public: ArrayList GetRange(Int32 index, Int32 count);
  public: Int32 IndexOf(Object value);
  public: Int32 IndexOf(Object value, Int32 startIndex);
  public: Int32 IndexOf(Object value, Int32 startIndex, Int32 count);
  public: void Insert(Int32 index, Object value);
  public: void InsertRange(Int32 index, ICollection c);
  public: Int32 LastIndexOf(Object value);
  public: Int32 LastIndexOf(Object value, Int32 startIndex);
  public: Int32 LastIndexOf(Object value, Int32 startIndex, Int32 count);
  public: void RemoveAt(Int32 index);
  public: void RemoveRange(Int32 index, Int32 count);
  public: void Reverse(Int32 index, Int32 count);
  public: void SetRange(Int32 index, ICollection c);
  public: void Sort(Int32 index, Int32 count, IComparer comparer);
  public: Array<Object> ToArray();
  public: Array<> ToArray(Type type);
  public: void TrimToSize();
  private: ArrayList _baseList;
  private: Int32 _baseIndex;
  private: Int32 _baseSize;
  private: Int32 _baseVersion;
};
} // namespace ArrayListNamespace
using ArrayList = ArrayListNamespace::ArrayList;
} // namespace System::Private::CoreLib::System::Collections
