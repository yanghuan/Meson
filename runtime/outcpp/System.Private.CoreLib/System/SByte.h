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
namespace SByteNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct SByte {
  public: Int32 CompareTo(Object obj);
  public: Int32 CompareTo(SByte value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SByte obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static SByte Parse(String s);
  public: static SByte Parse(String s, NumberStyles style);
  public: static SByte Parse(String s, IFormatProvider provider);
  public: static SByte Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static SByte Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  private: static SByte Parse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info);
  public: static Boolean TryParse(String s, SByte& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, SByte& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, SByte& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, SByte& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, SByte& result);
  public: TypeCode GetTypeCode();
  private: int8_t m_value;
  public: static SByte MaxValue;
  public: static SByte MinValue;
};
} // namespace SByteNamespace
using SByte = SByteNamespace::SByte;
} // namespace System::Private::CoreLib::System
