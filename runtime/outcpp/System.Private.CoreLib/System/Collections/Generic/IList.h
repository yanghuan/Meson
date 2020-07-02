#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IListNamespace {
CLASS(IList, T) {
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  public: Int32 IndexOf(T item);
  public: void Insert(Int32 index, T item);
  public: void RemoveAt(Int32 index);
};
} // namespace IListNamespace
template <class T>
using IList = IListNamespace::IList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
