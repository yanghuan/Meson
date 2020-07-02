#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IReadOnlyListNamespace {
CLASS(IReadOnlyList, T) {
  public: T get_Item(Int32 index);
};
} // namespace IReadOnlyListNamespace
template <class T>
using IReadOnlyList = IReadOnlyListNamespace::IReadOnlyList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
