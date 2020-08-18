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
namespace UInt32Namespace {
using namespace System::Globalization;
struct UInt32 : public valueType<UInt32> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<UInt32>, IEquatable<UInt32>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(UInt32 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(UInt32 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = rt::default, IFormatProvider provider = nullptr);
  public: static UInt32 Parse(String s);
  public: static UInt32 Parse(String s, NumberStyles style);
  public: static UInt32 Parse(String s, IFormatProvider provider);
  public: static UInt32 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static UInt32 Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::Integer, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, UInt32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, UInt32& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, UInt32& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, UInt32& result);
  public: TypeCode GetTypeCode();
  private: uint32_t m_value;
  public: static constexpr uint32_t MaxValue = 4294967295u;
  public: static constexpr uint32_t MinValue = 0u;
  public: static constexpr rt::TypeCode code = rt::TypeCode::UInt32;
  public: constexpr UInt32() noexcept : m_value(0) {}
  public: constexpr UInt32(uint32_t value) noexcept : m_value(value) {}
  public: constexpr uint32_t& get() noexcept { return m_value; }
  public: constexpr uint32_t get() const noexcept { return m_value; }
};
} // namespace UInt32Namespace
using UInt32 = UInt32Namespace::UInt32;
} // namespace System::Private::CoreLib::System
