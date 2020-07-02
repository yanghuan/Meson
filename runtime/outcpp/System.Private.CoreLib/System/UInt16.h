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
namespace UInt16Namespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct UInt16 {
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
  public: static UInt16 MaxValue;
  public: static UInt16 MinValue;
};
} // namespace UInt16Namespace
using UInt16 = UInt16Namespace::UInt16;
} // namespace System::Private::CoreLib::System
