#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace IEquatableNamespace {
CLASS(IEquatable, T) {
  public: Boolean Equals(T other);
};
} // namespace IEquatableNamespace
template <class T>
using IEquatable = IEquatableNamespace::IEquatable<T>;
} // namespace System::Private::CoreLib::System
