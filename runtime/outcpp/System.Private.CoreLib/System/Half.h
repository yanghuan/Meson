#pragma once

#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Double)
FORWARD_(IComparable, T1, T2)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt32)
FORWARDS(UInt64)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
namespace HalfNamespace {
using namespace System::Globalization;
struct Half : public valueType<Half> {
  public: using interface = rt::TypeList<IComparable<>, IFormattable, IComparable<Half>, IEquatable<Half>, ISpanFormattable>;
  public: static Half get_Epsilon();
  public: static Half get_PositiveInfinity();
  public: static Half get_NegativeInfinity();
  public: static Half get_NaN();
  public: static Half get_MinValue();
  public: static Half get_MaxValue();
  private: SByte get_Exponent();
  private: UInt16 get_Significand();
  public: explicit Half(UInt16 value);
  private: explicit Half(Boolean sign, UInt16 exp, UInt16 sig);
  public: static Boolean op_LessThan(Half left, Half right);
  public: static Boolean op_GreaterThan(Half left, Half right);
  public: static Boolean op_LessThanOrEqual(Half left, Half right);
  public: static Boolean op_GreaterThanOrEqual(Half left, Half right);
  public: static Boolean op_Equality(Half left, Half right);
  public: static Boolean op_Inequality(Half left, Half right);
  public: static Boolean IsFinite(Half value);
  public: static Boolean IsInfinity(Half value);
  public: static Boolean IsNaN(Half value);
  public: static Boolean IsNegative(Half value);
  public: static Boolean IsNegativeInfinity(Half value);
  public: static Boolean IsNormal(Half value);
  public: static Boolean IsPositiveInfinity(Half value);
  public: static Boolean IsSubnormal(Half value);
  public: static Half Parse(String s);
  public: static Half Parse(String s, NumberStyles style);
  public: static Half Parse(String s, IFormatProvider provider);
  public: static Half Parse(String s, NumberStyles style = NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, IFormatProvider provider = nullptr);
  public: static Half Parse(ReadOnlySpan<Char> s, NumberStyles style = NumberStyles::AllowLeadingWhite | NumberStyles::AllowTrailingWhite | NumberStyles::AllowLeadingSign | NumberStyles::AllowDecimalPoint | NumberStyles::AllowThousands | NumberStyles::AllowExponent, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, Half& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Half& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Half& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Half& result);
  private: static Boolean AreZero(Half left, Half right);
  private: static Boolean IsNaNOrZero(Half value);
  private: static UInt32 StripSign(Half value);
  public: Int32 CompareTo(Object obj);
  public: Int32 CompareTo(Half other);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Half other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: template <class T0 = ReadOnlySpan<Char>>
  Boolean TryFormat(Span<Char> destination, Int32& charsWritten, T0 format = rt::default__, IFormatProvider provider = nullptr);
  public: static Half op_Explicit(Single value);
  public: static Half op_Explicit(Double value);
  public: static Single op_Explicit(Half value, Single);
  public: static Double op_Explicit(Half value, Double);
  public: static Half Negate(Half value);
  private: static ValueTuple<Int32, UInt32> NormSubnormalF16Sig(UInt32 sig);
  private: static Half CreateHalfNaN(Boolean sign, UInt64 significand);
  private: static UInt16 RoundPackToHalf(Boolean sign, Int16 exp, UInt16 sig);
  private: static UInt32 ShiftRightJam(UInt32 i, Int32 dist);
  private: static UInt64 ShiftRightJam(UInt64 l, Int32 dist);
  private: static Single CreateSingleNaN(Boolean sign, UInt64 significand);
  private: static Double CreateDoubleNaN(Boolean sign, UInt64 significand);
  private: static Single CreateSingle(Boolean sign, Byte exp, UInt32 sig);
  private: static Double CreateDouble(Boolean sign, UInt16 exp, UInt64 sig);
  private: static void cctor();
  public: explicit Half() {}
  private: static Half PositiveZero;
  private: static Half NegativeZero;
  private: UInt16 _value;
};
} // namespace HalfNamespace
using Half = HalfNamespace::Half;
} // namespace System::Private::CoreLib::System
