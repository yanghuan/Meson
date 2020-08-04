#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles;
FORWARD(NumberFormatInfo)
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
namespace SByteNamespace {
using namespace Globalization;
struct SByte : public valueType<SByte> {
  public: constexpr SByte() noexcept : m_value(0) {}
  public: constexpr SByte(int8_t value) noexcept : m_value(value) {}
  public: constexpr int8_t& get() noexcept { return m_value; }
  public: constexpr int8_t get() const noexcept { return m_value; }
  public: Int32 CompareTo(Object obj);
  public: Int32 CompareTo(SByte value);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SByte obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
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
  public: static constexpr int8_t MaxValue = 127;
  public: static constexpr int8_t MinValue = -128;
};
} // namespace SByteNamespace
using SByte = SByteNamespace::SByte;
} // namespace System::Private::CoreLib::System
namespace rt {
template <>
struct TypeKind<::System::Private::CoreLib::System::SByte> {
  static constexpr TypeCode code = TypeCode::SByte;
};
} // namespace rt
