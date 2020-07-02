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
namespace UInt64Namespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct UInt64 {
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(UInt64 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(UInt64 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static UInt64 Parse(String s);
  public: static UInt64 Parse(String s, NumberStyles style);
  public: static UInt64 Parse(String s, IFormatProvider provider);
  public: static UInt64 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static UInt64 Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, UInt64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, UInt64& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, UInt64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt64& result);
  public: TypeCode GetTypeCode();
  private: uint64_t m_value;
  public: static UInt64 MaxValue;
  public: static UInt64 MinValue;
};
} // namespace UInt64Namespace
using UInt64 = UInt64Namespace::UInt64;
} // namespace System::Private::CoreLib::System