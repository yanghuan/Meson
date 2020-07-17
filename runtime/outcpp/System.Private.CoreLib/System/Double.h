#pragma once

#include <rt/GCObject.h>

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
FORWARDS(UInt64)
namespace DoubleNamespace {
using namespace Globalization;
struct Double : public rt::PrimitiveType<Double> {
  public: constexpr Double() noexcept : m_value(0) {}
  public: constexpr Double(double value) noexcept : m_value(value) {}
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
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider);
  public: static Double Parse(String s);
  public: static Double Parse(String s, NumberStyles style);
  public: static Double Parse(String s, IFormatProvider provider);
  public: static Double Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Double Parse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider);
  public: static Boolean TryParse(String s, Double& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Double& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Double& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Double& result);
  private: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, NumberFormatInfo info, Double& result);
  public: TypeCode GetTypeCode();
  public: void Ctor();
  private: double m_value;
  public: static constexpr double MinValue = -1.7976931348623157E+308;
  public: static constexpr double MaxValue = 1.7976931348623157E+308;
  public: static constexpr double Epsilon = 5E-324;
  public: static constexpr double NegativeInfinity = rt::NegativeInfinity<double>;
  public: static constexpr double PositiveInfinity = rt::PositiveInfinity<double>;
  public: static constexpr double NaN = rt::NaN<double>;
  template <class T>
  friend struct rt::PrimitiveType;
};
} // namespace DoubleNamespace
using Double = DoubleNamespace::Double;
} // namespace System::Private::CoreLib::System
