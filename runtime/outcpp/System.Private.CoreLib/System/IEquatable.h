#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace IEquatableNamespace {
CLASS(IEquatable, T) : public Object::in {
  public: Boolean Equals(T other);
};
} // namespace IEquatableNamespace
template <class T>
using IEquatable = IEquatableNamespace::IEquatable<T>;
} // namespace System::Private::CoreLib::System
