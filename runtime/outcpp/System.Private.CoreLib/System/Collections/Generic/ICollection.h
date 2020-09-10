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
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
namespace ICollectionNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
using IEnumerator = Collections::IEnumerator;
template <class T>
using IEnumerator_ = Generic::IEnumerator<T>;
CLASS(ICollection, T) : public object {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable_>;
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: IEnumerator GetEnumerator();
  public: IEnumerator_<T> GetEnumerator();
  public: void Add(T item);
  public: void Clear();
  public: Boolean Contains(T item);
  public: void CopyTo(Array<T> array, Int32 arrayIndex);
  public: Boolean Remove(T item);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace ICollectionNamespace
template <class T>
using ICollection = ICollectionNamespace::ICollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
