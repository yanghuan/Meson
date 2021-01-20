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
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARD(Type)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace DoubleNamespace {
using namespace System::Globalization;
struct Double : public valueType<Double, rt::TypeCode::Double> {
  public: using interface = rt::TypeList<IComparable<>, IConvertible, IFormattable, IComparable<Double>, IEquatable<Double>, ISpanFormattable>;
  public: static Boolean IsFinite(Double d);
  public: static Boolean IsInfinity(Double d);
  public: static Boolean IsNaN(Double d);
  public: static Boolean IsNegative(Double d);
  public: static Boolean IsNegativeInfinity(Double d);
  public: static Boolean IsNormal(Double d);
  public: static Boolean IsPositiveInfinity(Double d);
  public: static Boolean IsSubnormal(Double d);
  public: static Int32 ExtractExponentFromBits(UInt64 bits);
  public: static UInt64 ExtractSignificandFromBits(UInt64 bits);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Double value);
  public: Boolean Equals(Object obj);
  public: static Boolean op_Equality(Double left, Double right);
  public: static Boolean op_Inequality(Double left, Double right);
  public: static Boolean op_LessThan(Double left, Double right);
  public: static Boolean op_GreaterThan(Double left, Double right);
  public: static Boolean op_LessThanOrEqual(Double left, Double right);
  public: static Boolean op_GreaterThanOrEqual(Double left, Double right);
  public: Boolean Equals(Double obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default__, IFormatProvider provider = nullptr);
  public: static Double Parse(String s);
  public: static Double Parse(String s, NumberStyles style);
  public: static Double Parse(String s, IFormatProvider provider);
  public: static Double Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Double Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, Double& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Double& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Double& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Double& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Double& result);
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
  private: double m_value;
  public: static constexpr double MinValue = -1.7976931348623157E+308;
  public: static constexpr double MaxValue = 1.7976931348623157E+308;
  public: static constexpr double Epsilon = 5E-324;
  public: static constexpr double NegativeInfinity = rt::NegativeInfinity<double>;
  public: static constexpr double PositiveInfinity = rt::PositiveInfinity<double>;
  public: static constexpr double NaN = rt::NaN<double>;
  public: constexpr Double() noexcept : m_value(0) {}
  public: constexpr Double(double value) noexcept : m_value(value) {}
  public: template <class T> requires(std::is_enum_v<T>)
  constexpr explicit Double(T value) noexcept : Double((double)value) {}
  public: constexpr double& get() noexcept { return m_value; }
  public: constexpr double get() const noexcept { return m_value; }
};
} // namespace DoubleNamespace
using Double = DoubleNamespace::Double;
} // namespace System::Private::CoreLib::System
