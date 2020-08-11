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
FORWARD(IList)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::ObjectModel {
namespace ReadOnlyCollectionNamespace {
using namespace Generic;
template <class T>
using IList = Generic::IList<T>;
using IList1 = Collections::IList;
template <class T>
using ICollection = Generic::ICollection<T>;
using ICollection1 = Collections::ICollection;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(ReadOnlyCollection, T) : public Object::in {
  public: using interface = rt::TypeList<IList<T>, ICollection<T>, IEnumerable<T>, IEnumerable1, IList1, ICollection1, IReadOnlyList<T>, IReadOnlyCollection<T>>;
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
  private: static Boolean IsCompatibleObject(Object value);
  private: IList<T> list;
};
} // namespace ReadOnlyCollectionNamespace
template <class T>
using ReadOnlyCollection = ReadOnlyCollectionNamespace::ReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
