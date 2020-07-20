#pragma once

#include <rt/GCObject.h>

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
namespace Int16Namespace {
using namespace Globalization;
struct Int16 : public rt::PrimitiveType<Int16> {
  public: constexpr Int16() noexcept : m_value(0) {}
  public: constexpr Int16(int16_t value) noexcept : m_value(value) {}
  public: constexpr int16_t& getValue() noexcept  { return m_value; }
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Int16 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Int16 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Int16 Parse(String s);
  public: static Int16 Parse(String s, NumberStyles style);
  public: static Int16 Parse(String s, IFormatProvider provider);
  public: static Int16 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Int16 Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  private: static Int16 Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info);
  public: static Boolean TryParse(String s, Int16& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Int16& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Int16& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int16& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Int16& result);
  public: TypeCode GetTypeCode();
  public: void Ctor();
  private: int16_t m_value;
  public: static constexpr int16_t MaxValue = 32767;
  public: static constexpr int16_t MinValue = -32768;
  template <class T>
  friend struct rt::PrimitiveType;
};
} // namespace Int16Namespace
using Int16 = Int16Namespace::Int16;
} // namespace System::Private::CoreLib::System
