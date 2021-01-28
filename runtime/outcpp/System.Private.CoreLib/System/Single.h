#pragma once

#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(NumberFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class TypeCode : int32_t;
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD_(IComparable)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace SingleNamespace {
using namespace System::Globalization;
struct Single : public valueType<Single, rt::TypeCode::Single> {
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
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default__, IFormatProvider provider = nullptr);
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
  private: Boolean ToBooleanOfIConvertible(IFormatProvider provider);
  private: Char ToCharOfIConvertible(IFormatProvider provider);
  private: SByte ToSByteOfIConvertible(IFormatProvider provider);
  private: Byte ToByteOfIConvertible(IFormatProvider provider);
  private: Int16 ToInt16OfIConvertible(IFormatProvider provider);
  private: UInt16 ToUInt16OfIConvertible(IFormatProvider provider);
  private: Int32 ToInt32OfIConvertible(IFormatProvider provider);
  private: UInt32 ToUInt32OfIConvertible(IFormatProvider provider);
  private: Int64 ToInt64OfIConvertible(IFormatProvider provider);
  private: UInt64 ToUInt64OfIConvertible(IFormatProvider provider);
  private: Single ToSingleOfIConvertible(IFormatProvider provider);
  private: Double ToDoubleOfIConvertible(IFormatProvider provider);
  private: Decimal ToDecimalOfIConvertible(IFormatProvider provider);
  private: DateTime ToDateTimeOfIConvertible(IFormatProvider provider);
  private: Object ToTypeOfIConvertible(Type type, IFormatProvider provider);
  private: float m_value;
  public: static constexpr Single MinValue() { return -3.4028235E+38; }
  public: static constexpr Single Epsilon() { return 1E-45; }
  public: static constexpr Single MaxValue() { return 3.4028235E+38; }
  public: static constexpr Single PositiveInfinity() { return rt::PositiveInfinity<float>; }
  public: static constexpr Single NegativeInfinity() { return rt::NegativeInfinity<float>; }
  public: static constexpr Single NaN() { return rt::NaN<float>; }
  public: constexpr Single() noexcept : m_value(0) {}
  public: constexpr Single(float value) noexcept : m_value(value) {}
  public: template <class T> requires(std::is_enum_v<T> || std::is_pointer_v<T>)
  constexpr explicit Single(T value) noexcept : Single((float)value) {}
  public: constexpr float& get() noexcept { return m_value; }
  public: constexpr float get() const noexcept { return m_value; }
};
} // namespace SingleNamespace
using Single = SingleNamespace::Single;
} // namespace System::Private::CoreLib::System
