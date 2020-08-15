#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles : int32_t;
FORWARD(NumberFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD_(IComparable, T1, T2)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int32)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace UInt16Namespace {
using namespace System::Globalization;
struct UInt16 : public valueType<UInt16> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<UInt16>, IEquatable<UInt16>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(UInt16 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(UInt16 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static UInt16 Parse(String s);
  public: static UInt16 Parse(String s, NumberStyles style);
  public: static UInt16 Parse(String s, IFormatProvider provider);
  public: static UInt16 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static UInt16 Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  private: static UInt16 Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info);
  public: static Boolean TryParse(String s, UInt16& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, UInt16& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, UInt16& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt16& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, UInt16& result);
  public: TypeCode GetTypeCode();
  private: uint16_t m_value;
  public: static constexpr uint16_t MaxValue = 65535;
  public: static constexpr uint16_t MinValue = 0;
  public: static constexpr rt::TypeCode code = rt::TypeCode::UInt16;
  public: constexpr UInt16() noexcept : m_value(0) {}
  public: constexpr UInt16(uint16_t value) noexcept : m_value(value) {}
  public: constexpr uint16_t& get() noexcept { return m_value; }
  public: constexpr uint16_t get() const noexcept { return m_value; }
};
} // namespace UInt16Namespace
using UInt16 = UInt16Namespace::UInt16;
} // namespace System::Private::CoreLib::System
