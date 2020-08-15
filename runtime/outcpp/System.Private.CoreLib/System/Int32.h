#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles : int32_t;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Char)
FORWARD_(IComparable, T1, T2)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace Int32Namespace {
using namespace System::Globalization;
struct Int32 : public valueType<Int32> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Int32>, IEquatable<Int32>, ISpanFormattable>;
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
  public: static constexpr int32_t MaxValue = 2147483647;
  public: static constexpr int32_t MinValue = -2147483648;
  public: static constexpr rt::TypeCode code = rt::TypeCode::Int32;
  public: constexpr Int32() noexcept : m_value(0) {}
  public: constexpr Int32(int32_t value) noexcept : m_value(value) {}
  public: template <class T> requires(std::is_enum_v<T>)
  constexpr Int32(T value) noexcept : Int32((int32_t)value) {}
  public: constexpr int32_t& get() noexcept { return m_value; }
  public: constexpr int32_t get() const noexcept { return m_value; }
};
} // namespace Int32Namespace
using Int32 = Int32Namespace::Int32;
} // namespace System::Private::CoreLib::System
