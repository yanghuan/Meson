#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
FORWARD(NumberFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD(String)
FORWARD(IFormatProvider)
FORWARDS(Span, T)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
enum class TypeCode;
namespace Int16Namespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct Int16 {
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
  private: int16_t m_value;
  public: static Int16 MaxValue;
  public: static Int16 MinValue;
};
} // namespace Int16Namespace
using Int16 = Int16Namespace::Int16;
} // namespace System::Private::CoreLib::System
