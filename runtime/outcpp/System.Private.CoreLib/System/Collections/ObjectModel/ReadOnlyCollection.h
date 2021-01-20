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
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace ReadOnlyCollectionNamespace {
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
CLASS(ReadOnlyCollection, T) : public object {
  public: using interface = rt::TypeList<IList<T>, ICollection<T>, IEnumerable<T>, IEnumerable_, IList_, ICollection_, IReadOnlyList<T>, IReadOnlyCollection<T>>;
  public: Int32 get_Count();
  public: T get_Item(Int32 index);
  protected: IList<T> get_Items();
  private: Boolean get_IsReadOnlyOfICollectionT();
  private: T get_ItemOfIListT(Int32 index);
  private: void set_ItemOfIListT(Int32 index, T value);
  private: Boolean get_IsSynchronizedOfICollection();
  private: Object get_SyncRootOfICollection();
  private: Boolean get_IsFixedSizeOfIList();
  private: Boolean get_IsReadOnlyOfIList();
  private: Object get_ItemOfIList(Int32 index);
  private: void set_ItemOfIList(Int32 index, Object value);
  public: void ctor(IList<T> list);
  public: Boolean Contains(T value);
  public: void CopyTo(Array<T> array, Int32 index);
  public: IEnumerator<T> GetEnumerator();
  public: Int32 IndexOf(T value);
  private: void AddOfICollectionT(T value);
  private: void ClearOfICollectionT();
  private: void InsertOfIListT(Int32 index, T value);
  private: Boolean RemoveOfICollectionT(T value);
  private: void RemoveAtOfIListT(Int32 index);
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  private: void CopyToOfICollection(Array<> array, Int32 index);
  private: Int32 AddOfIList(Object value);
  private: void ClearOfIList();
  private: static Boolean IsCompatibleObject(Object value);
  private: Boolean ContainsOfIList(Object value);
  private: Int32 IndexOfOfIList(Object value);
  private: void InsertOfIList(Int32 index, Object value);
  private: void RemoveOfIList(Object value);
  private: void RemoveAtOfIList(Int32 index);
  private: IList<T> list;
};
} // namespace ReadOnlyCollectionNamespace
template <class T>
using ReadOnlyCollection = ReadOnlyCollectionNamespace::ReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
