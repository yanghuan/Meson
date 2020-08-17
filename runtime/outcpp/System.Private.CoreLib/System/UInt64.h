#pragma once

#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD_(IComparable, T1, T2)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int32)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace UInt64Namespace {
using namespace System::Globalization;
struct UInt64 : public valueType<UInt64> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<UInt64>, IEquatable<UInt64>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(UInt64 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(UInt64 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = nullptr, IFormatProvider provider = nullptr);
  public: static UInt64 Parse(String s);
  public: static UInt64 Parse(String s, NumberStyles style);
  public: static UInt64 Parse(String s, IFormatProvider provider);
  public: static UInt64 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static UInt64 Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::Integer, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, UInt64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, UInt64& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, UInt64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt64& result);
  public: TypeCode GetTypeCode();
  private: uint64_t m_value;
  public: static constexpr uint64_t MaxValue = 18446744073709551615;
  public: static constexpr uint64_t MinValue = 0;
  public: static constexpr rt::TypeCode code = rt::TypeCode::UInt64;
  public: constexpr UInt64() noexcept : m_value(0) {}
  public: constexpr UInt64(uint64_t value) noexcept : m_value(value) {}
  public: constexpr uint64_t& get() noexcept { return m_value; }
  public: constexpr uint64_t get() const noexcept { return m_value; }
};
} // namespace UInt64Namespace
using UInt64 = UInt64Namespace::UInt64;
} // namespace System::Private::CoreLib::System
