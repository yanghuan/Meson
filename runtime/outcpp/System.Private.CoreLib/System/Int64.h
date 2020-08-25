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
namespace Int64Namespace {
using namespace System::Globalization;
struct Int64 : public valueType<Int64, rt::TypeCode::Int64> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Int64>, IEquatable<Int64>, ISpanFormattable>;
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Int64 value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Int64 obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default__, IFormatProvider provider = nullptr);
  public: static Int64 Parse(String s);
  public: static Int64 Parse(String s, NumberStyles style);
  public: static Int64 Parse(String s, IFormatProvider provider);
  public: static Int64 Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Int64 Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::Integer, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, Int64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Int64& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Int64& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Int64& result);
  public: TypeCode GetTypeCode();
  private: int64_t m_value;
  public: static constexpr int64_t MaxValue = 9223372036854775807;
  public: static constexpr int64_t MinValue = -9223372036854775808;
  public: constexpr Int64() noexcept : m_value(0) {}
  public: constexpr Int64(int64_t value) noexcept : m_value(value) {}
  public: template <class T> requires(std::is_enum_v<T>)
  constexpr Int64(T value) noexcept : Int64((int64_t)value) {}
  public: constexpr int64_t& get() noexcept { return m_value; }
  public: constexpr int64_t get() const noexcept { return m_value; }
};
} // namespace Int64Namespace
using Int64 = Int64Namespace::Int64;
} // namespace System::Private::CoreLib::System
