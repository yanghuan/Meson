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
namespace IReadOnlyCollectionNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(IReadOnlyCollection, T) : public Object::in {
  public: using interface = rt::TypeList<IEnumerable<T>, IEnumerable1>;
  public: Int32 get_Count();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlyCollectionNamespace
template <class T>
using IReadOnlyCollection = IReadOnlyCollectionNamespace::IReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
