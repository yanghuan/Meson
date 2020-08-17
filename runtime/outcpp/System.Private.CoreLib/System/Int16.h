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
namespace Int16Namespace {
using namespace System::Globalization;
struct Int16 : public valueType<Int16> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Int16>, IEquatable<Int16>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Int16 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Int16 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = nullptr, IFormatProvider provider = nullptr);
  public: static Int16 Parse(String s);
  public: static Int16 Parse(String s, NumberStyles style);
  public: static Int16 Parse(String s, IFormatProvider provider);
  public: static Int16 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Int16 Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::Integer, IFormatProvider provider = nullptr);
  private: static Int16 Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info);
  public: static Boolean TryParse(String s, Int16& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Int16& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Int16& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int16& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Int16& result);
  public: TypeCode GetTypeCode();
  private: int16_t m_value;
  public: static constexpr int16_t MaxValue = 32767;
  public: static constexpr int16_t MinValue = -32768;
  public: static constexpr rt::TypeCode code = rt::TypeCode::Int16;
  public: constexpr Int16() noexcept : m_value(0) {}
  public: constexpr Int16(int16_t value) noexcept : m_value(value) {}
  public: constexpr int16_t& get() noexcept { return m_value; }
  public: constexpr int16_t get() const noexcept { return m_value; }
};
} // namespace Int16Namespace
using Int16 = Int16Namespace::Int16;
} // namespace System::Private::CoreLib::System
