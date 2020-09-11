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
FORWARD(IReadOnlyCollection, T)
namespace IReadOnlyListNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
CLASS(IReadOnlyList, T) : public object {
  public: using interface = rt::TypeList<IReadOnlyCollection<T>, IEnumerable<T>, IEnumerable_>;
  public: Int32 get_Count();
  public: T get_Item(Int32 index);
  public: IEnumerator<T> GetEnumerator();
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlyListNamespace
template <class T>
using IReadOnlyList = IReadOnlyListNamespace::IReadOnlyList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
