#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
namespace IReadOnlyCollectionNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
CLASS(IReadOnlyCollection, T) : public object {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable_>;
  public: Int32 get_Count();
  public: IEnumerator<T> GetEnumerator();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlyCollectionNamespace
template <class T>
using IReadOnlyCollection = IReadOnlyCollectionNamespace::IReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
