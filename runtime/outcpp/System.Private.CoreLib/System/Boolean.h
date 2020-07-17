#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace BooleanNamespace {
struct Boolean : public rt::PrimitiveType<Boolean> {
  public: constexpr Boolean() noexcept : m_value(false) {}
  public: constexpr Boolean(bool value) noexcept : m_value(value) {}
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
  private: static void SCtor();
  public: void Ctor();
  private: bool m_value;
  public: static String TrueString;
  public: static String FalseString;
  template <class T>
  friend struct rt::PrimitiveType;
};
} // namespace BooleanNamespace
using Boolean = BooleanNamespace::Boolean;
} // namespace System::Private::CoreLib::System
