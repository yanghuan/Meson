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
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char)
FORWARDS(Span, T)
enum class TypeCode;
namespace ByteNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct Byte {
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
  public: static Byte MaxValue;
  public: static Byte MinValue;
};
} // namespace ByteNamespace
using Byte = ByteNamespace::Byte;
} // namespace System::Private::CoreLib::System
