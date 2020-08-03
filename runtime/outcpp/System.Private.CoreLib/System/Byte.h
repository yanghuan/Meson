#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
FORWARD(NumberFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode;
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace ByteNamespace {
using namespace Globalization;
struct Byte : public valueType<Byte> {
  public: constexpr Byte() noexcept : m_value(0) {}
  public: constexpr Byte(uint8_t value) noexcept : m_value(value) {}
  public: constexpr uint8_t& get() noexcept  { return m_value; }
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Byte value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Byte obj);
  public: Int32 GetHashCode();
  public: static Byte Parse(String s);
  public: static Byte Parse(String s, NumberStyles style);
  public: static Byte Parse(String s, IFormatProvider provider);
  public: static Byte Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Byte Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  private: static Byte Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info);
  public: static Boolean TryParse(String s, Byte& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Byte& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Byte& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Byte& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Byte& result);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: TypeCode GetTypeCode();
  private: uint8_t m_value;
  public: static constexpr uint8_t MaxValue = 255;
  public: static constexpr uint8_t MinValue = 0;
};
} // namespace ByteNamespace
using Byte = ByteNamespace::Byte;
} // namespace System::Private::CoreLib::System
namespace rt {
template <>
struct TypeKind<::System::Private::CoreLib::System::Byte> {
  static constexpr TypeCode Kind = TypeCode::Byte;
};
} // namespace rt
