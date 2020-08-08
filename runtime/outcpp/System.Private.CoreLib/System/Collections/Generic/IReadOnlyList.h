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
FORWARD(IReadOnlyCollection, T)
namespace IReadOnlyListNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(IReadOnlyList, T) : public Object::in {
  public: using interface = rt::TypeList<IReadOnlyCollection<T>, IEnumerable<T>, IEnumerable1>;
  public: T get_Item(Int32 index);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlyListNamespace
template <class T>
using IReadOnlyList = IReadOnlyListNamespace::IReadOnlyList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
