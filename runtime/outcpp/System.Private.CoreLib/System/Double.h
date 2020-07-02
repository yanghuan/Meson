#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Globalization {
FORWARD(NumberFormatInfo)
enum class NumberStyles;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(UInt64)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(IFormatProvider)
FORWARDS(Span, T)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
enum class TypeCode;
namespace DoubleNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct Double {
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
  private: double m_value;
  public: static Double MinValue;
  public: static Double MaxValue;
  public: static Double Epsilon;
  public: static Double NegativeInfinity;
  public: static Double PositiveInfinity;
  public: static Double NaN;
};
} // namespace DoubleNamespace
using Double = DoubleNamespace::Double;
} // namespace System::Private::CoreLib::System