#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
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
namespace Int64Namespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct Int64 {
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Int64 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Int64 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Int64 Parse(String s);
  public: static Int64 Parse(String s, NumberStyles style);
  public: static Int64 Parse(String s, IFormatProvider provider);
  public: static Int64 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Int64 Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, Int64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Int64& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Int64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int64& result);
  public: TypeCode GetTypeCode();
  private: int64_t m_value;
  public: static Int64 MaxValue;
  public: static Int64 MinValue;
};
} // namespace Int64Namespace
using Int64 = Int64Namespace::Int64;
} // namespace System::Private::CoreLib::System
