#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
namespace ICollectionNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(ICollection, T) : public Object::in {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable1>;
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
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
