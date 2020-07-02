#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace IReadOnlyListNamespace {
CLASS(IReadOnlyList, T) {
};
} // namespace IReadOnlyListNamespace
template <class T>
using IReadOnlyList = IReadOnlyListNamespace::IReadOnlyList<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
