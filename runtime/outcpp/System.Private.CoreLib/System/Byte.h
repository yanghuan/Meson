#pragma once

#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
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
namespace ByteNamespace {
using namespace System::Globalization;
struct Byte : public valueType<Byte> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Byte>, IEquatable<Byte>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Byte value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Byte obj);
  public: Int32 GetHashCode();
  public: static Byte Parse(String s);
  public: static Byte Parse(String s, NumberStyles style);
  public: static Byte Parse(String s, IFormatProvider provider);
  public: static Byte Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Byte Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::Integer, IFormatProvider provider = nullptr);
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
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default, IFormatProvider provider = nullptr);
  public: TypeCode GetTypeCode();
  private: uint8_t m_value;
  public: static constexpr uint8_t MaxValue = 255;
  public: static constexpr uint8_t MinValue = 0;
  public: static constexpr rt::TypeCode code = rt::TypeCode::Byte;
  public: constexpr Byte() noexcept : m_value(0) {}
  public: constexpr Byte(uint8_t value) noexcept : m_value(value) {}
  public: constexpr uint8_t& get() noexcept { return m_value; }
  public: constexpr uint8_t get() const noexcept { return m_value; }
};
} // namespace ByteNamespace
using Byte = ByteNamespace::Byte;
} // namespace System::Private::CoreLib::System
