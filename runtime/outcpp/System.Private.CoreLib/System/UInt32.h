#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
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
namespace UInt32Namespace {
using namespace Globalization;
struct UInt32 : public rt::PrimitiveType<UInt32> {
  public: UInt32(): m_value(0) {}
  public: UInt32(uint32_t value): m_value(value) {}
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(UInt32 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(UInt32 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static UInt32 Parse(String s);
  public: static UInt32 Parse(String s, NumberStyles style);
  public: static UInt32 Parse(String s, IFormatProvider provider);
  public: static UInt32 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static UInt32 Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, UInt32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, UInt32& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, UInt32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt32& result);
  public: TypeCode GetTypeCode();
  private: uint32_t m_value;
  public: static UInt32 MaxValue;
  public: static UInt32 MinValue;
};
} // namespace UInt32Namespace
using UInt32 = UInt32Namespace::UInt32;
} // namespace System::Private::CoreLib::System
