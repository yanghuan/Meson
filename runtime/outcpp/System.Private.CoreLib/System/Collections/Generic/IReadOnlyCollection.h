#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IReadOnlyCollectionNamespace {
CLASS(IReadOnlyCollection, T) {
  public: Int32 get_Count();
};
} // namespace IReadOnlyCollectionNamespace
template <class T>
using IReadOnlyCollection = IReadOnlyCollectionNamespace::IReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
