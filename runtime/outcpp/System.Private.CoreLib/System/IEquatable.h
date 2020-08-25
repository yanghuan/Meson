#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace IEquatableNamespace {
CLASS(IEquatable, T) : public object {
  public: Boolean Equals(T other);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IEquatableNamespace
template <class T>
using IEquatable = IEquatableNamespace::IEquatable<T>;
} // namespace System::Private::CoreLib::System
