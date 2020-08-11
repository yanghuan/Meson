#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
namespace IListNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
CLASS(IList, T) : public Object::in {
  public: using interface = rt::TypeList<ICollection<T>, IEnumerable<T>, IEnumerable_>;
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  public: Int32 IndexOf(T item);
  public: void Insert(Int32 index, T item);
  public: void RemoveAt(Int32 index);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IListNamespace
template <class T>
using IList = IListNamespace::IList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
