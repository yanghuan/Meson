#pragma once

#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(NumberFormatInfo)
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
FORWARDS(Int32)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt32)
namespace SingleNamespace {
using namespace System::Globalization;
struct Single : public valueType<Single> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Single>, IEquatable<Single>, ISpanFormattable>;
  public: static Boolean IsFinite(Single f);
  public: static Boolean IsInfinity(Single f);
  public: static Boolean IsNaN(Single f);
  public: static Boolean IsNegative(Single f);
  public: static Boolean IsNegativeInfinity(Single f);
  public: static Boolean IsNormal(Single f);
  public: static Boolean IsPositiveInfinity(Single f);
  public: static Boolean IsSubnormal(Single f);
  public: static Int32 ExtractExponentFromBits(UInt32 bits);
  public: static UInt32 ExtractSignificandFromBits(UInt32 bits);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Single value);
  public: static Boolean op_Equality(Single left, Single right);
  public: static Boolean op_Inequality(Single left, Single right);
  public: static Boolean op_LessThan(Single left, Single right);
  public: static Boolean op_GreaterThan(Single left, Single right);
  public: static Boolean op_LessThanOrEqual(Single left, Single right);
  public: static Boolean op_GreaterThanOrEqual(Single left, Single right);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Single obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = nullptr, IFormatProvider provider = nullptr);
  public: static Single Parse(String s);
  public: static Single Parse(String s, NumberStyles style);
  public: static Single Parse(String s, IFormatProvider provider);
  public: static Single Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Single Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, Single& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Single& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Single& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Single& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Single& result);
  public: TypeCode GetTypeCode();
  private: float m_value;
  public: static constexpr float MinValue = -3.4028235E+38;
  public: static constexpr float Epsilon = 1E-45;
  public: static constexpr float MaxValue = 3.4028235E+38;
  public: static constexpr float PositiveInfinity = rt::PositiveInfinity<float>;
  public: static constexpr float NegativeInfinity = rt::NegativeInfinity<float>;
  public: static constexpr float NaN = rt::NaN<float>;
  public: static constexpr rt::TypeCode code = rt::TypeCode::Single;
  public: constexpr Single() noexcept : m_value(0) {}
  public: constexpr Single(float value) noexcept : m_value(value) {}
  public: constexpr float& get() noexcept { return m_value; }
  public: constexpr float get() const noexcept { return m_value; }
};
} // namespace SingleNamespace
using Single = SingleNamespace::Single;
} // namespace System::Private::CoreLib::System
