#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
namespace IListNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using IEnumerator = Collections::IEnumerator;
template <class T>
using IEnumerator_ = Generic::IEnumerator<T>;
CLASS(IList, T) : public object {
  public: using interface = rt::TypeList<ICollection<T>, IEnumerable<T>, IEnumerable_>;
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: T get_Item(Int32 index);
  public: void set_Item(Int32 index, T value);
  public: IEnumerator GetEnumerator();
  public: IEnumerator_<T> GetEnumerator();
  public: void Add(T item);
  public: void Clear();
  public: Boolean Contains(T item);
  public: void CopyTo(Array<T> array, Int32 arrayIndex);
  public: Boolean Remove(T item);
  public: Int32 IndexOf(T item);
  public: void Insert(Int32 index, T item);
  public: void RemoveAt(Int32 index);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IListNamespace
template <class T>
using IList = IListNamespace::IList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
