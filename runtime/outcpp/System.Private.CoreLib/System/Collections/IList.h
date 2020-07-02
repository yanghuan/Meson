#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace IListNamespace {
CLASS(IList) {
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
};
} // namespace IListNamespace
using IList = IListNamespace::IList;
} // namespace System::Private::CoreLib::System::Collections
