#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IListNamespace {
CLASS(IList, T) : public Object::in {
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
