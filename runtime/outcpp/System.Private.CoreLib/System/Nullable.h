#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
namespace NullableNamespace {
template <class T1 = void, class T2 = void>
class Nullable {
};
template <>
class Nullable<> {
  public: template <class T>
  static Int32 Compare(Nullable<T> n1, Nullable<T> n2);
  public: template <class T>
  static Boolean Equals(Nullable<T> n1, Nullable<T> n2);
  public: static Type GetUnderlyingType(Type nullableType);
};
template <class T>
struct Nullable<T> : public valueType<Nullable<T>> {
  public: Boolean get_HasValue();
  public: T get_Value();
  public: explicit Nullable(T value);
  public: T GetValueOrDefault();
  public: T GetValueOrDefault(T defaultValue);
  public: Boolean Equals(Object other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static Nullable<T> op_Implicit(T value);
  public: static T op_Explicit(Nullable<T> value);
  public: explicit Nullable() {}
  private: Boolean hasValue;
  public: T value;
  public: constexpr Nullable(std::nullptr_t) noexcept {}
};
} // namespace NullableNamespace
template <class T1 = void, class T2 = void>
using Nullable = NullableNamespace::Nullable<T1, T2>;
} // namespace System::Private::CoreLib::System
