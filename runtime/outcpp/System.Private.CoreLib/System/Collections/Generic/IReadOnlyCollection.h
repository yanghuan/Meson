#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace IReadOnlyCollectionNamespace {
CLASS(IReadOnlyCollection, T) {
};
} // namespace IReadOnlyCollectionNamespace
template <class T>
using IReadOnlyCollection = IReadOnlyCollectionNamespace::IReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
