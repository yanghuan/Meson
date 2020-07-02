#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(String)
FORWARD(IFormatProvider)
FORWARDS(Span, T)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
enum class TypeCode;
namespace Int32Namespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct Int32 {
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Int32 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Int32 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Int32 Parse(String s);
  public: static Int32 Parse(String s, NumberStyles style);
  public: static Int32 Parse(String s, IFormatProvider provider);
  public: static Int32 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Int32 Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, Int32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Int32& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Int32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int32& result);
  public: TypeCode GetTypeCode();
  private: int32_t m_value;
  public: static Int32 MaxValue;
  public: static Int32 MinValue;
};
} // namespace Int32Namespace
using Int32 = Int32Namespace::Int32;
} // namespace System::Private::CoreLib::System