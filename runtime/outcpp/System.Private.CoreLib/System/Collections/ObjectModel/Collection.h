#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IList, T)
FORWARD(IReadOnlyCollection, T)
FORWARD(IReadOnlyList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
FORWARD(IList)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace CollectionNamespace {
using namespace System::Collections::Generic;
template <class T>
using IList = Generic::IList<T>;
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using IList_ = Collections::IList;
using ICollection_ = Collections::ICollection;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
CLASS(Collection, T) : public object {
  public: using interface = rt::TypeList<IList<T>, ICollection<T>, IEnumerable<T>, IEnumerable_, IList_, ICollection_, IReadOnlyList<T>, IReadOnlyCollection<T>>;
  public: Int32 get_Count();
  protected: IList<T> get_Items();
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  private: Boolean get_IsReadOnlyOfICollectionT();
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  private: Object get_ItemOfIList(Int32 index);
  private: void set_ItemOfIList(Int32 index, Object value);
  private: Boolean get_IsReadOnlyOfIList();
  private: Boolean get_IsFixedSizeOfIList();
  public: void ctor();
  public: void ctor(IList<T> list);
  public: void Add(T item);
  public: void Clear();
  public: void CopyTo(Array<T> array, Int32 index);
  public: Boolean Contains(T item);
  public: IEnumerator<T> GetEnumerator();
  public: Int32 IndexOf(T item);
  public: void Insert(Int32 index, T item);
  public: Boolean Remove(T item);
  public: void RemoveAt(Int32 index);
  protected: void ClearItems();
  protected: void InsertItem(Int32 index, T item);
  protected: void RemoveItem(Int32 index);
  protected: void SetItem(Int32 index, T item);
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  private: void CopyToOfICollection(Array<> array, Int32 index);
  private: Int32 AddOfIList(Object value);
  private: Boolean ContainsOfIList(Object value);
  private: Int32 IndexOfOfIList(Object value);
  private: void InsertOfIList(Int32 index, Object value);
  private: void RemoveOfIList(Object value);
  private: static Boolean IsCompatibleObject(Object value);
  private: IList<T> items;
};
} // namespace CollectionNamespace
template <class T>
using Collection = CollectionNamespace::Collection<T>;
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
