#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Char)
FORWARD_(IComparable, T1, T2)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace BooleanNamespace {
struct Boolean : public valueType<Boolean, rt::TypeCode::Boolean> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IComparable<Boolean>, IEquatable<Boolean>>;
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Boolean obj);
  public: Int32 CompareTo(Object obj);
  public: Int32 CompareTo(Boolean value);
  public: static Boolean IsTrueStringIgnoreCase(ReadOnlySpan<Char> value);
  public: static Boolean IsFalseStringIgnoreCase(ReadOnlySpan<Char> value);
  public: static Boolean Parse(String value);
  public: static Boolean Parse(ReadOnlySpan<Char> value);
  public: static Boolean TryParse(String value, Boolean& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> value, Boolean& result);
  private: static ReadOnlySpan<Char> TrimWhiteSpaceAndNull(ReadOnlySpan<Char> value);
  public: TypeCode GetTypeCode();
  private: static void cctor();
  private: bool m_value;
  public: static String TrueString;
  public: static String FalseString;
  public: static constexpr rt::TypeCode code = rt::TypeCode::Boolean;
  public: constexpr Boolean() noexcept : m_value(false) {}
  public: constexpr Boolean(bool value) noexcept : m_value(value) {}
  public: constexpr bool& get() noexcept { return m_value; }
  public: constexpr bool get() const noexcept { return m_value; }
};
} // namespace BooleanNamespace
using Boolean = BooleanNamespace::Boolean;
} // namespace System::Private::CoreLib::System
