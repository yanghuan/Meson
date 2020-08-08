#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IEnumerable)
namespace IListNamespace {
CLASS(IList) : public Object::in {
  public: using interface = rt::TypeList<ICollection, IEnumerable>;
  public: Object get_Item(Int32 index);
  public: void set_Item(Int32 index, Object value);
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
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
