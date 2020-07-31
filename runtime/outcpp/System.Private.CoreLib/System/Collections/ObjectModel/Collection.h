#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace CollectionNamespace {
using namespace Generic;
using Generic::IList;
using Generic::IEnumerator;
CLASS(Collection, T) : public Object::in {
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
  public: void Ctor();
  public: void Ctor(IList<T> list);
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
  private: static Boolean IsCompatibleObject(Object value);
  private: IList<T> items;
};
} // namespace CollectionNamespace
template <class T>
using Collection = CollectionNamespace::Collection<T>;
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
