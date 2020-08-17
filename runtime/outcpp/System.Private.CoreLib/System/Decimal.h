#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles : int32_t;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class MidpointRounding : int32_t;
enum class TypeCode : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Char)
FORWARDS(Currency)
FORWARDS(Double)
FORWARD_(IComparable, T1, T2)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
namespace DecimalNamespace {
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
struct Decimal : public valueType<Decimal> {
  public: using interface = rt::TypeList<IFormattable, IComparable<>, IConvertible, IComparable<Decimal>, IEquatable<Decimal>, IDeserializationCallback, ISpanFormattable>;
  private: struct DecCalc : public valueType<DecCalc> {
    private: struct Buf24 : public valueType<Buf24> {
      public: UInt64 get_Low64();
      public: void set_Low64(UInt64 value);
      public: void set_Mid64(UInt64 value);
      public: void set_High64(UInt64 value);
      public: UInt32 U0;
      public: UInt32 U1;
      public: UInt32 U2;
      public: UInt32 U3;
      public: UInt32 U4;
      public: UInt32 U5;
      private: UInt64 ulo64LE;
      private: UInt64 umid64LE;
      private: UInt64 uhigh64LE;
    };
    private: struct PowerOvfl : public valueType<PowerOvfl> {
      public: explicit PowerOvfl(UInt32 hi, UInt32 mid, UInt32 lo);
      public: explicit PowerOvfl() {}
      public: UInt32 Hi;
      public: UInt64 MidLo;
    };
    private: struct Buf12 : public valueType<Buf12> {
      public: UInt64 get_Low64();
      public: void set_Low64(UInt64 value);
      public: UInt64 get_High64();
      public: void set_High64(UInt64 value);
      public: UInt32 U0;
      public: UInt32 U1;
      public: UInt32 U2;
      private: UInt64 ulo64LE;
      private: UInt64 uhigh64LE;
    };
    private: struct Buf16 : public valueType<Buf16> {
      public: UInt64 get_Low64();
      public: void set_Low64(UInt64 value);
      public: UInt64 get_High64();
      public: void set_High64(UInt64 value);
      public: UInt32 U0;
      public: UInt32 U1;
      public: UInt32 U2;
      public: UInt32 U3;
      private: UInt64 ulo64LE;
      private: UInt64 uhigh64LE;
    };
    private: struct Buf28 : public valueType<Buf28> {
      public: Buf24 Buf24;
      public: UInt32 U6;
    };
    private: UInt32 get_High();
    private: void set_High(UInt32 value);
    private: UInt32 get_Low();
    private: void set_Low(UInt32 value);
    private: UInt32 get_Mid();
    private: void set_Mid(UInt32 value);
    private: Boolean get_IsNegative();
    private: Int32 get_Scale();
    private: UInt64 get_Low64();
    private: void set_Low64(UInt64 value);
    private: static UInt32 GetExponent(Single f);
    private: static UInt32 GetExponent(Double d);
    private: static UInt64 UInt32x32To64(UInt32 a, UInt32 b);
    private: static void UInt64x64To128(UInt64 a, UInt64 b, DecCalc& result);
    private: static UInt32 Div96By32(Buf12& bufNum, UInt32 den);
    private: static Boolean Div96ByConst(UInt64& high64, UInt32& low, UInt32 pow);
    private: static void Unscale(UInt32& low, UInt64& high64, Int32& scale);
    private: static UInt32 Div96By64(Buf12& bufNum, UInt64 den);
    private: static UInt32 Div128By96(Buf16& bufNum, Buf12& bufDen);
    private: static UInt32 IncreaseScale(Buf12& bufNum, UInt32 power);
    private: static void IncreaseScale64(Buf12& bufNum, UInt32 power);
    private: static Int32 ScaleResult(Buf24* bufRes, UInt32 hiRes, Int32 scale);
    private: static UInt32 DivByConst(UInt32* result, UInt32 hiRes, UInt32& quotient, UInt32& remainder, UInt32 power);
    private: static Int32 OverflowUnscale(Buf12& bufQuo, Int32 scale, Boolean sticky);
    private: static Int32 SearchScale(Buf12& bufQuo, Int32 scale);
    private: static Boolean Add32To96(Buf12& bufNum, UInt32 value);
    public: static void DecAddSub(DecCalc& d1, DecCalc& d2, Boolean sign);
    public: static Int64 VarCyFromDec(DecCalc& pdecIn);
    public: static Int32 VarDecCmp(Decimal& d1, Decimal& d2);
    private: static Int32 VarDecCmpSub(Decimal& d1, Decimal& d2);
    public: static void VarDecMul(DecCalc& d1, DecCalc& d2);
    public: static void VarDecFromR4(Single input, DecCalc& result);
    public: static void VarDecFromR8(Double input, DecCalc& result);
    public: static Single VarR4FromDec(Decimal& value);
    public: static Double VarR8FromDec(Decimal& value);
    public: static Int32 GetHashCode(Decimal& d);
    public: static void VarDecDiv(DecCalc& d1, DecCalc& d2);
    public: static void VarDecMod(DecCalc& d1, DecCalc& d2);
    private: static void VarDecModFull(DecCalc& d1, DecCalc& d2, Int32 scale);
    public: static void InternalRound(DecCalc& d, UInt32 scale, MidpointRounding mode);
    public: static UInt32 DecDivMod1E9(DecCalc& value);
    private: static void cctor();
    private: UInt32 uflags;
    private: UInt32 uhi;
    private: UInt32 ulo;
    private: UInt32 umid;
    private: UInt64 ulomidLE;
    private: static Array<UInt32> s_powers10;
    private: static Array<UInt64> s_ulongPowers10;
    private: static Array<Double> s_doublePowers10;
    private: static Array<PowerOvfl> PowerOvflValues;
  };
  public: UInt32 get_High();
  public: UInt32 get_Low();
  public: UInt32 get_Mid();
  public: Boolean get_IsNegative();
  public: Int32 get_Scale();
  private: UInt64 get_Low64();
  public: explicit Decimal(Currency value);
  public: explicit Decimal(Int32 value);
  public: explicit Decimal(UInt32 value);
  public: explicit Decimal(Int64 value);
  public: explicit Decimal(UInt64 value);
  public: explicit Decimal(Single value);
  public: explicit Decimal(Double value);
  public: static Decimal FromOACurrency(Int64 cy);
  public: static Int64 ToOACurrency(Decimal value);
  private: static Boolean IsValid(Int32 flags);
  public: explicit Decimal(Array<Int32> bits);
  public: explicit Decimal(ReadOnlySpan<Int32> bits);
  public: explicit Decimal(Int32 lo, Int32 mid, Int32 hi, Boolean isNegative, Byte scale);
  private: explicit Decimal(Int32 lo, Int32 mid, Int32 hi, Int32 flags);
  private: explicit Decimal(Decimal& d, Int32 flags);
  public: static Decimal Abs(Decimal& d);
  public: static Decimal Add(Decimal d1, Decimal d2);
  public: static Decimal Ceiling(Decimal d);
  public: static Int32 Compare(Decimal d1, Decimal d2);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(Decimal value);
  public: static Decimal Divide(Decimal d1, Decimal d2);
  public: Boolean Equals(Object value);
  public: Boolean Equals(Decimal value);
  public: Int32 GetHashCode();
  public: static Boolean Equals(Decimal d1, Decimal d2);
  public: static Decimal Floor(Decimal d);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = nullptr, IFormatProvider provider = nullptr);
  public: static Decimal Parse(String s);
  public: static Decimal Parse(String s, NumberStyles style);
  public: static Decimal Parse(String s, IFormatProvider provider);
  public: static Decimal Parse(String s, NumberStyles style, IFormatProvider provider);
  public: static Decimal Parse(ReadOnlySpan<Char> s, NumberStyles style = 111, IFormatProvider provider = nullptr);
  public: static Boolean TryParse(String s, Decimal& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, Decimal& result);
  public: static Boolean TryParse(String s, NumberStyles style, IFormatProvider provider, Decimal& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, NumberStyles style, IFormatProvider provider, Decimal& result);
  public: static Array<Int32> GetBits(Decimal d);
  public: static Int32 GetBits(Decimal d, Span<Int32> destination);
  public: static Boolean TryGetBits(Decimal d, Span<Int32> destination, Int32& valuesWritten);
  public: static void GetBytes(Decimal& d, Array<Byte> buffer);
  public: static Decimal ToDecimal(ReadOnlySpan<Byte> span);
  public: static Decimal& Max(Decimal& d1, Decimal& d2);
  public: static Decimal& Min(Decimal& d1, Decimal& d2);
  public: static Decimal Remainder(Decimal d1, Decimal d2);
  public: static Decimal Multiply(Decimal d1, Decimal d2);
  public: static Decimal Negate(Decimal d);
  public: static Decimal Round(Decimal d);
  public: static Decimal Round(Decimal d, Int32 decimals);
  public: static Decimal Round(Decimal d, MidpointRounding mode);
  public: static Decimal Round(Decimal d, Int32 decimals, MidpointRounding mode);
  private: static Decimal Round(Decimal& d, Int32 decimals, MidpointRounding mode);
  public: static Int32 Sign(Decimal& d);
  public: static Decimal Subtract(Decimal d1, Decimal d2);
  public: static Byte ToByte(Decimal value);
  public: static SByte ToSByte(Decimal value);
  public: static Int16 ToInt16(Decimal value);
  public: static Double ToDouble(Decimal d);
  public: static Int32 ToInt32(Decimal d);
  public: static Int64 ToInt64(Decimal d);
  public: static UInt16 ToUInt16(Decimal value);
  public: static UInt32 ToUInt32(Decimal d);
  public: static UInt64 ToUInt64(Decimal d);
  public: static Single ToSingle(Decimal d);
  public: static Decimal Truncate(Decimal d);
  private: static void Truncate(Decimal& d);
  public: static Decimal op_Implicit(Byte value);
  public: static Decimal op_Implicit(SByte value);
  public: static Decimal op_Implicit(Int16 value);
  public: static Decimal op_Implicit(UInt16 value);
  public: static Decimal op_Implicit(Char value);
  public: static Decimal op_Implicit(Int32 value);
  public: static Decimal op_Implicit(UInt32 value);
  public: static Decimal op_Implicit(Int64 value);
  public: static Decimal op_Implicit(UInt64 value);
  public: static Decimal op_Explicit(Single value);
  public: static Decimal op_Explicit(Double value);
  public: static Byte op_Explicit(Decimal value, Byte);
  public: static SByte op_Explicit(Decimal value, SByte);
  public: static Char op_Explicit(Decimal value, Char);
  public: static Int16 op_Explicit(Decimal value, Int16);
  public: static UInt16 op_Explicit(Decimal value, UInt16);
  public: static Int32 op_Explicit(Decimal value, Int32);
  public: static UInt32 op_Explicit(Decimal value, UInt32);
  public: static Int64 op_Explicit(Decimal value, Int64);
  public: static UInt64 op_Explicit(Decimal value, UInt64);
  public: static Single op_Explicit(Decimal value, Single);
  public: static Double op_Explicit(Decimal value, Double);
  public: static Decimal op_UnaryPlus(Decimal d);
  public: static Decimal op_UnaryNegation(Decimal d);
  public: static Decimal op_Increment(Decimal d);
  public: static Decimal op_Decrement(Decimal d);
  public: static Decimal op_Addition(Decimal d1, Decimal d2);
  public: static Decimal op_Subtraction(Decimal d1, Decimal d2);
  public: static Decimal op_Multiply(Decimal d1, Decimal d2);
  public: static Decimal op_Division(Decimal d1, Decimal d2);
  public: static Decimal op_Modulus(Decimal d1, Decimal d2);
  public: static Boolean op_Equality(Decimal d1, Decimal d2);
  public: static Boolean op_Inequality(Decimal d1, Decimal d2);
  public: static Boolean op_LessThan(Decimal d1, Decimal d2);
  public: static Boolean op_LessThanOrEqual(Decimal d1, Decimal d2);
  public: static Boolean op_GreaterThan(Decimal d1, Decimal d2);
  public: static Boolean op_GreaterThanOrEqual(Decimal d1, Decimal d2);
  public: TypeCode GetTypeCode();
  private: static DecCalc& AsMutable(Decimal& d);
  public: static UInt32 DecDivMod1E9(Decimal& value);
  private: static void cctor();
  public: explicit Decimal() {}
  private: Int32 flags;
  private: Int32 hi;
  private: Int32 lo;
  private: Int32 mid;
};
} // namespace DecimalNamespace
using Decimal = DecimalNamespace::Decimal;
} // namespace System::Private::CoreLib::System
