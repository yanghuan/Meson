#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
namespace IListNamespace {
CLASS(IList) : public object {
  public: using interface = rt::TypeList<ICollection, IEnumerable>;
  public: Int32 get_Count();
  public: Object get_SyncRoot();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: IEnumerator GetEnumerator();
  public: void CopyTo(Array<> array, Int32 index);
  public: Int32 Add(Object value);
  public: Boolean Contains(Object value);
  public: void Clear();
  public: Int32 IndexOf(Object value);
  public: void Insert(Int32 index, Object value);
  public: void Remove(Object value);
  public: void RemoveAt(Int32 index);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IListNamespace
using IList = IListNamespace::IList;
} // namespace System::Private::CoreLib::System::Collections
