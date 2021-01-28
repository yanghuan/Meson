#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>
#include <System.Private.CoreLib/System/TypeCode.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class NumberStyles : int32_t;
FORWARD(NumberFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Char)
FORWARDS(Decimal)
FORWARDS(Double)
FORWARD(Exception)
FORWARD(IFormatProvider)
FORWARDS(Int16)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Single)
FORWARD(String)
namespace NumberNamespace {
using namespace System::Globalization;
using namespace System::Text;
class Number {
  public: enum class NumberBufferKind : uint8_t {
    Unknown = 0,
    Integer = 1,
    Decimal = 2,
    FloatingPoint = 3,
  };
  public: enum class ParsingStatus : int32_t {
    OK = 0,
    Failed = 1,
    Overflow = 2,
  };
  public: struct DiyFp : public valueType<DiyFp> {
    public: static DiyFp CreateAndGetBoundaries(Double value, DiyFp& mMinus, DiyFp& mPlus);
    public: static DiyFp CreateAndGetBoundaries(Single value, DiyFp& mMinus, DiyFp& mPlus);
    public: explicit DiyFp(Double value);
    public: explicit DiyFp(Single value);
    public: explicit DiyFp(UInt64 f, Int32 e);
    public: DiyFp Multiply(DiyFp& other);
    public: DiyFp Normalize();
    public: DiyFp Subtract(DiyFp& other);
    private: void GetBoundaries(Int32 implicitBitIndex, DiyFp& mMinus, DiyFp& mPlus);
    public: explicit DiyFp() {}
    public: UInt64 f;
    public: Int32 e;
  };
  public: struct NumberBuffer : public valueType<NumberBuffer> {
    public: explicit NumberBuffer(NumberBufferKind kind, Byte* digits, Int32 digitsLength);
    public: Byte* GetDigitsPointer();
    public: String ToString();
    public: explicit NumberBuffer() {}
    public: Int32 DigitsCount;
    public: Int32 Scale;
    public: Boolean IsNegative;
    public: Boolean HasNonZeroTail;
    public: NumberBufferKind Kind;
    public: Span<Byte> Digits;
  };
  public: struct BigInteger : public valueType<BigInteger> {
    public: static void Add(BigInteger& lhs, BigInteger& rhs, BigInteger& result);
    public: static Int32 Compare(BigInteger& lhs, BigInteger& rhs);
    public: static UInt32 CountSignificantBits(UInt32 value);
    public: static UInt32 CountSignificantBits(UInt64 value);
    public: static UInt32 CountSignificantBits(BigInteger& value);
    public: static void DivRem(BigInteger& lhs, BigInteger& rhs, BigInteger& quo, BigInteger& rem);
    public: static UInt32 HeuristicDivide(BigInteger& dividend, BigInteger& divisor);
    public: static void Multiply(BigInteger& lhs, UInt32 value, BigInteger& result);
    public: static void Multiply(BigInteger& lhs, BigInteger& rhs, BigInteger& result);
    public: static void Pow2(UInt32 exponent, BigInteger& result);
    public: static void Pow10(UInt32 exponent, BigInteger& result);
    private: static UInt32 AddDivisor(BigInteger& lhs, Int32 lhsStartIndex, BigInteger& rhs);
    private: static Boolean DivideGuessTooBig(UInt64 q, UInt64 valHi, UInt32 valLo, UInt32 divHi, UInt32 divLo);
    private: static UInt32 SubtractDivisor(BigInteger& lhs, Int32 lhsStartIndex, BigInteger& rhs, UInt64 q);
    public: void Add(UInt32 value);
    public: UInt32 GetBlock(UInt32 index);
    public: Int32 GetLength();
    public: Boolean IsOne();
    public: Boolean IsZero();
    public: void Multiply(UInt32 value);
    public: void Multiply(BigInteger& value);
    public: void Multiply10();
    public: void MultiplyPow10(UInt32 exponent);
    public: static void SetUInt32(BigInteger& result, UInt32 value);
    public: static void SetUInt64(BigInteger& result, UInt64 value);
    public: static void SetValue(BigInteger& result, BigInteger& value);
    public: static void SetZero(BigInteger& result);
    public: void ShiftLeft(UInt32 shift);
    public: UInt64 ToUInt64();
    private: UInt32* GetBlocksPointer();
    private: static UInt32 DivRem32(UInt32 value, UInt32& remainder);
    public: static void cctor();
    private: static Array<UInt32> s_Pow10UInt32Table;
    private: static Array<Int32> s_Pow10BigNumTableIndices;
    private: static Array<UInt32> s_Pow10BigNumTable;
    private: Int32 _length;
    private: UInt32 _blocks[115];
  };
  public: class Grisu3 {
    public: static Boolean TryRunDouble(Double value, Int32 requestedDigits, NumberBuffer& number);
    public: static Boolean TryRunSingle(Single value, Int32 requestedDigits, NumberBuffer& number);
    private: static Boolean TryRunCounted(DiyFp& w, Int32 requestedDigits, Span<Byte> buffer, Int32& length, Int32& decimalExponent);
    private: static Boolean TryRunShortest(DiyFp& boundaryMinus, DiyFp& w, DiyFp& boundaryPlus, Span<Byte> buffer, Int32& length, Int32& decimalExponent);
    private: static UInt32 BiggestPowerTen(UInt32 number, Int32 numberBits, Int32& exponentPlusOne);
    private: static Boolean TryDigitGenCounted(DiyFp& w, Int32 requestedDigits, Span<Byte> buffer, Int32& length, Int32& kappa);
    private: static Boolean TryDigitGenShortest(DiyFp& low, DiyFp& w, DiyFp& high, Span<Byte> buffer, Int32& length, Int32& kappa);
    private: static DiyFp GetCachedPowerForBinaryExponentRange(Int32 minExponent, Int32 maxExponent, Int32& decimalExponent);
    private: static Boolean TryRoundWeedCounted(Span<Byte> buffer, Int32 length, UInt64 rest, UInt64 tenKappa, UInt64 unit, Int32& kappa);
    private: static Boolean TryRoundWeedShortest(Span<Byte> buffer, Int32 length, UInt64 distanceTooHighW, UInt64 unsafeInterval, UInt64 rest, UInt64 tenKappa, UInt64 unit);
    public: static void cctor();
    private: static Array<Int16> s_CachedPowersBinaryExponent;
    private: static Array<Int16> s_CachedPowersDecimalExponent;
    private: static Array<UInt64> s_CachedPowersSignificand;
    private: static Array<UInt32> s_SmallPowersOfTen;
  };
  public: struct FloatingPointInfo : public valueType<FloatingPointInfo> {
    public: UInt64 get_ZeroBits() { return ZeroBits; }
    public: UInt64 get_InfinityBits() { return InfinityBits; }
    public: UInt64 get_NormalMantissaMask() { return NormalMantissaMask; }
    public: UInt64 get_DenormalMantissaMask() { return DenormalMantissaMask; }
    public: Int32 get_MinBinaryExponent() { return MinBinaryExponent; }
    public: Int32 get_MaxBinaryExponent() { return MaxBinaryExponent; }
    public: Int32 get_ExponentBias() { return ExponentBias; }
    public: Int32 get_OverflowDecimalExponent() { return OverflowDecimalExponent; }
    public: UInt16 get_NormalMantissaBits() { return NormalMantissaBits; }
    public: UInt16 get_DenormalMantissaBits() { return DenormalMantissaBits; }
    public: explicit FloatingPointInfo(UInt16 denormalMantissaBits, UInt16 exponentBits, Int32 maxBinaryExponent, Int32 exponentBias, UInt64 infinityBits);
    public: static void cctor();
    public: explicit FloatingPointInfo() {}
    public: static FloatingPointInfo Double;
    public: static FloatingPointInfo Single;
    private: UInt64 ZeroBits;
    private: UInt64 InfinityBits;
    private: UInt64 NormalMantissaMask;
    private: UInt64 DenormalMantissaMask;
    private: Int32 MinBinaryExponent;
    private: Int32 MaxBinaryExponent;
    private: Int32 ExponentBias;
    private: Int32 OverflowDecimalExponent;
    private: UInt16 NormalMantissaBits;
    private: UInt16 DenormalMantissaBits;
    private: UInt16 ExponentBits;
  };
  public: static ReadOnlySpan<Byte> get_CharToHexLookup();
  public: static void Dragon4Double(Double value, Int32 cutoffNumber, Boolean isSignificantDigits, NumberBuffer& number);
  public: static void Dragon4Single(Single value, Int32 cutoffNumber, Boolean isSignificantDigits, NumberBuffer& number);
  private: static UInt32 Dragon4(UInt64 mantissa, Int32 exponent, UInt32 mantissaHighBitIdx, Boolean hasUnequalMargins, Int32 cutoffNumber, Boolean isSignificantDigits, Span<Byte> buffer, Int32& decimalExponent);
  public: static String FormatDecimal(Decimal value, ReadOnlySpan<Char> format, NumberFormatInfo info);
  public: static Boolean TryFormatDecimal(Decimal value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten);
  public: static void DecimalToNumber(Decimal& d, NumberBuffer& number);
  public: static String FormatDouble(Double value, String format, NumberFormatInfo info);
  public: static Boolean TryFormatDouble(Double value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten);
  private: static Int32 GetFloatingPointMaxDigitsAndPrecision(Char fmt, Int32& precision, NumberFormatInfo info, Boolean& isSignificantDigits);
  private: static String FormatDouble(ValueStringBuilder& sb, Double value, ReadOnlySpan<Char> format, NumberFormatInfo info);
  public: static String FormatSingle(Single value, String format, NumberFormatInfo info);
  public: static Boolean TryFormatSingle(Single value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten);
  private: static String FormatSingle(ValueStringBuilder& sb, Single value, ReadOnlySpan<Char> format, NumberFormatInfo info);
  private: static Boolean TryCopyTo(String source, Span<Char> destination, Int32& charsWritten);
  private: static Char GetHexBase(Char fmt);
  public: static String FormatInt32(Int32 value, Int32 hexMask, String format, IFormatProvider provider);
  public: static Boolean TryFormatInt32(Int32 value, Int32 hexMask, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static String FormatUInt32(UInt32 value, String format, IFormatProvider provider);
  public: static Boolean TryFormatUInt32(UInt32 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static String FormatInt64(Int64 value, String format, IFormatProvider provider);
  public: static Boolean TryFormatInt64(Int64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static String FormatUInt64(UInt64 value, String format, IFormatProvider provider);
  public: static Boolean TryFormatUInt64(UInt64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  private: static void Int32ToNumber(Int32 value, NumberBuffer& number);
  public: static String Int32ToDecStr(Int32 value);
  private: static String NegativeInt32ToDecStr(Int32 value, Int32 digits, String sNegative);
  private: static Boolean TryNegativeInt32ToDecStr(Int32 value, Int32 digits, String sNegative, Span<Char> destination, Int32& charsWritten);
  private: static String Int32ToHexStr(Int32 value, Char hexBase, Int32 digits);
  private: static Boolean TryInt32ToHexStr(Int32 value, Char hexBase, Int32 digits, Span<Char> destination, Int32& charsWritten);
  private: static Char* Int32ToHexChars(Char* buffer, UInt32 value, Int32 hexBase, Int32 digits);
  private: static void UInt32ToNumber(UInt32 value, NumberBuffer& number);
  public: static Byte* UInt32ToDecChars(Byte* bufferEnd, UInt32 value, Int32 digits);
  public: static Char* UInt32ToDecChars(Char* bufferEnd, UInt32 value, Int32 digits);
  public: static String UInt32ToDecStr(UInt32 value);
  private: static String UInt32ToDecStr(UInt32 value, Int32 digits);
  private: static Boolean TryUInt32ToDecStr(UInt32 value, Int32 digits, Span<Char> destination, Int32& charsWritten);
  private: static void Int64ToNumber(Int64 input, NumberBuffer& number);
  public: static String Int64ToDecStr(Int64 value);
  private: static String NegativeInt64ToDecStr(Int64 input, Int32 digits, String sNegative);
  private: static Boolean TryNegativeInt64ToDecStr(Int64 input, Int32 digits, String sNegative, Span<Char> destination, Int32& charsWritten);
  private: static String Int64ToHexStr(Int64 value, Char hexBase, Int32 digits);
  private: static Boolean TryInt64ToHexStr(Int64 value, Char hexBase, Int32 digits, Span<Char> destination, Int32& charsWritten);
  private: static void UInt64ToNumber(UInt64 value, NumberBuffer& number);
  public: static String UInt64ToDecStr(UInt64 value, Int32 digits);
  private: static Boolean TryUInt64ToDecStr(UInt64 value, Int32 digits, Span<Char> destination, Int32& charsWritten);
  public: static Char ParseFormatSpecifier(ReadOnlySpan<Char> format, Int32& digits);
  public: static void NumberToString(ValueStringBuilder& sb, NumberBuffer& number, Char format, Int32 nMaxDigits, NumberFormatInfo info);
  public: static void NumberToStringFormat(ValueStringBuilder& sb, NumberBuffer& number, ReadOnlySpan<Char> format, NumberFormatInfo info);
  private: static void FormatCurrency(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info);
  private: static void FormatFixed(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, Array<Int32> groupDigits, String sDecimal, String sGroup);
  private: static void FormatNumber(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info);
  private: static void FormatScientific(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info, Char expChar);
  private: static void FormatExponent(ValueStringBuilder& sb, NumberFormatInfo info, Int32 value, Char expChar, Int32 minDigits, Boolean positiveSign);
  private: static void FormatGeneral(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info, Char expChar, Boolean bSuppressScientific);
  private: static void FormatPercent(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info);
  public: static void RoundNumber(NumberBuffer& number, Int32 pos, Boolean isCorrectlyRounded);
  private: static Int32 FindSection(ReadOnlySpan<Char> format, Int32 section);
  private: static UInt32 Low32(UInt64 value);
  private: static UInt32 High32(UInt64 value);
  private: static UInt32 Int64DivMod1E9(UInt64& value);
  private: static UInt64 ExtractFractionAndBiasedExponent(Double value, Int32& exponent);
  private: static UInt32 ExtractFractionAndBiasedExponent(Single value, Int32& exponent);
  private: static void AccumulateDecimalDigitsIntoBigInteger(NumberBuffer& number, UInt32 firstIndex, UInt32 lastIndex, BigInteger& result);
  private: static UInt64 AssembleFloatingPointBits(FloatingPointInfo& info, UInt64 initialMantissa, Int32 initialExponent, Boolean hasZeroTail);
  private: static UInt64 ConvertBigIntegerToFloatingPointBits(BigInteger& value, FloatingPointInfo& info, UInt32 integerBitsOfPrecision, Boolean hasNonZeroFractionalPart);
  private: static UInt32 DigitsToUInt32(Byte* p, Int32 count);
  private: static UInt64 DigitsToUInt64(Byte* p, Int32 count);
  private: static UInt64 NumberToFloatingPointBits(NumberBuffer& number, FloatingPointInfo& info);
  private: static UInt64 NumberToFloatingPointBitsSlow(NumberBuffer& number, FloatingPointInfo& info, UInt32 positiveExponent, UInt32 integerDigitsPresent, UInt32 fractionalDigitsPresent);
  private: static UInt64 RightShiftWithRounding(UInt64 value, Int32 shift, Boolean hasZeroTail);
  private: static Boolean ShouldRoundUp(Boolean lsbBit, Boolean roundBit, Boolean hasTailBits);
  private: static Boolean TryNumberToInt32(NumberBuffer& number, Int32& value);
  private: static Boolean TryNumberToInt64(NumberBuffer& number, Int64& value);
  private: static Boolean TryNumberToUInt32(NumberBuffer& number, UInt32& value);
  private: static Boolean TryNumberToUInt64(NumberBuffer& number, UInt64& value);
  public: static Int32 ParseInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  public: static Int64 ParseInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  public: static UInt32 ParseUInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  public: static UInt64 ParseUInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  private: static Boolean TryParseNumber(Char*& str, Char* strEnd, NumberStyles styles, NumberBuffer& number, NumberFormatInfo info);
  public: static ParsingStatus TryParseInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result);
  private: static ParsingStatus TryParseInt32Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result);
  public: static ParsingStatus TryParseInt32IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result);
  public: static ParsingStatus TryParseInt64IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result);
  public: static ParsingStatus TryParseInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result);
  private: static ParsingStatus TryParseInt64Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result);
  public: static ParsingStatus TryParseUInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result);
  private: static ParsingStatus TryParseUInt32Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result);
  public: static ParsingStatus TryParseUInt32IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result);
  private: static ParsingStatus TryParseUInt32HexNumberStyle(ReadOnlySpan<Char> value, NumberStyles styles, UInt32& result);
  public: static ParsingStatus TryParseUInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result);
  private: static ParsingStatus TryParseUInt64Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result);
  public: static ParsingStatus TryParseUInt64IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result);
  private: static ParsingStatus TryParseUInt64HexNumberStyle(ReadOnlySpan<Char> value, NumberStyles styles, UInt64& result);
  public: static Decimal ParseDecimal(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  public: static Boolean TryNumberToDecimal(NumberBuffer& number, Decimal& value);
  public: static Double ParseDouble(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  public: static Single ParseSingle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info);
  public: static ParsingStatus TryParseDecimal(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Decimal& result);
  public: static Boolean TryParseDouble(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Double& result);
  public: static Boolean TryParseSingle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Single& result);
  public: static Boolean TryStringToNumber(ReadOnlySpan<Char> value, NumberStyles styles, NumberBuffer& number, NumberFormatInfo info);
  private: static Boolean TrailingZeros(ReadOnlySpan<Char> value, Int32 index);
  private: static Boolean IsSpaceReplacingChar(Char c);
  private: static Char* MatchChars(Char* p, Char* pEnd, String value);
  private: static Boolean IsWhite(Int32 ch);
  private: static Boolean IsDigit(Int32 ch);
  public: static void ThrowOverflowOrFormatException(ParsingStatus status, TypeCode type = TypeCode::Empty);
  public: static void ThrowOverflowException(TypeCode type);
  private: static Exception GetException(ParsingStatus status, TypeCode type);
  public: static Double NumberToDouble(NumberBuffer& number);
  public: static Single NumberToSingle(NumberBuffer& number);
  public: static void cctor();
  public: static String _FormatInt32_g__FormatInt32Slow32_0(Int32 value, Int32 hexMask, String format, IFormatProvider provider);
  public: static Boolean _TryFormatInt32_g__TryFormatInt32Slow33_0(Int32 value, Int32 hexMask, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static String _FormatUInt32_g__FormatUInt32Slow34_0(UInt32 value, String format, IFormatProvider provider);
  public: static Boolean _TryFormatUInt32_g__TryFormatUInt32Slow35_0(UInt32 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static String _FormatInt64_g__FormatInt64Slow36_0(Int64 value, String format, IFormatProvider provider);
  public: static Boolean _TryFormatInt64_g__TryFormatInt64Slow37_0(Int64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static String _FormatUInt64_g__FormatUInt64Slow38_0(UInt64 value, String format, IFormatProvider provider);
  public: static Boolean _TryFormatUInt64_g__TryFormatUInt64Slow39_0(UInt64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten);
  public: static Boolean _RoundNumber_g__ShouldRoundUp72_0(Byte* dig, Int32 i, NumberBufferKind numberKind, Boolean isCorrectlyRounded);
  private: static Array<String> s_singleDigitStringCache;
  private: static Array<String> s_posCurrencyFormats;
  private: static Array<String> s_negCurrencyFormats;
  private: static Array<String> s_posPercentFormats;
  private: static Array<String> s_negPercentFormats;
  private: static Array<String> s_negNumberFormats;
  private: static Array<Single> s_Pow10SingleTable;
  private: static Array<Double> s_Pow10DoubleTable;
};
} // namespace NumberNamespace
using Number = NumberNamespace::Number;
} // namespace System::Private::CoreLib::System
