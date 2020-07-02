#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
namespace NullableNamespace {
template <class T1 = void, class T2 = void>
class Nullable {
};
template <>
class Nullable<> {
};
template <class T>
struct Nullable<T> {
  public: Boolean get_HasValue();
  public: T get_Value();
  private: Boolean hasValue;
  public: T value;
};
} // namespace NullableNamespace
template <class T1 = void, class T2 = void>
using Nullable = NullableNamespace::Nullable<T1, T2>;
} // namespace System::Private::CoreLib::System
