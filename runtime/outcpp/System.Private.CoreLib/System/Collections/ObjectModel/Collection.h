#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerator, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace CollectionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
using System::Collections::Generic::IList;
CLASS(Collection, T) {
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
