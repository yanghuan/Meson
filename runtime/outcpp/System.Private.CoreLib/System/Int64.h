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
namespace Int64Namespace {
using namespace Globalization;
struct Int64 : public rt::PrimitiveType<Int64> {
  public: constexpr Int64() noexcept : m_value(0) {}
  public: constexpr Int64(int64_t value) noexcept : m_value(value) {}
  public: constexpr int64_t& get() noexcept  { return m_value; }
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
  public: static constexpr int64_t MaxValue = 9223372036854775807;
  public: static constexpr int64_t MinValue = -9223372036854775808;
  template <class T>
  friend struct rt::PrimitiveType;
};
} // namespace Int64Namespace
using Int64 = Int64Namespace::Int64;
} // namespace System::Private::CoreLib::System
