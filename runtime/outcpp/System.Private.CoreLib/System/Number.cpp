#include "Number-dep.h"

#include <System.Private.CoreLib/System/Number-dep.h>

namespace System::Private::CoreLib::System::NumberNamespace {
Number::DiyFp Number::DiyFp::CreateAndGetBoundaries(Double value, DiyFp& mMinus, DiyFp& mPlus) {
  return Number::DiyFp();
}

Number::DiyFp Number::DiyFp::CreateAndGetBoundaries(Single value, DiyFp& mMinus, DiyFp& mPlus) {
  return Number::DiyFp();
}

Number::DiyFp::DiyFp(Double value) {
}

Number::DiyFp::DiyFp(Single value) {
}

Number::DiyFp::DiyFp(UInt64 f, Int32 e) {
}

Number::DiyFp Number::DiyFp::Multiply(DiyFp& other) {
  return Number::DiyFp();
}

Number::DiyFp Number::DiyFp::Normalize() {
  return Number::DiyFp();
}

Number::DiyFp Number::DiyFp::Subtract(DiyFp& other) {
  return Number::DiyFp();
}

void Number::DiyFp::GetBoundaries(Int32 implicitBitIndex, DiyFp& mMinus, DiyFp& mPlus) {
}

Number::NumberBuffer::NumberBuffer(NumberBufferKind kind, Byte* digits, Int32 digitsLength) {
}

Byte* Number::NumberBuffer::GetDigitsPointer() {
  return nullptr;
}

String Number::NumberBuffer::ToString() {
  return nullptr;
}

void Number::BigInteger::Add(BigInteger& lhs, BigInteger& rhs, BigInteger& result) {
}

Int32 Number::BigInteger::Compare(BigInteger& lhs, BigInteger& rhs) {
  return Int32();
}

UInt32 Number::BigInteger::CountSignificantBits(UInt32 value) {
  return UInt32();
}

UInt32 Number::BigInteger::CountSignificantBits(UInt64 value) {
  return UInt32();
}

UInt32 Number::BigInteger::CountSignificantBits(BigInteger& value) {
  return UInt32();
}

void Number::BigInteger::DivRem(BigInteger& lhs, BigInteger& rhs, BigInteger& quo, BigInteger& rem) {
}

UInt32 Number::BigInteger::HeuristicDivide(BigInteger& dividend, BigInteger& divisor) {
  return UInt32();
}

void Number::BigInteger::Multiply(BigInteger& lhs, UInt32 value, BigInteger& result) {
}

void Number::BigInteger::Multiply(BigInteger& lhs, BigInteger& rhs, BigInteger& result) {
}

void Number::BigInteger::Pow2(UInt32 exponent, BigInteger& result) {
}

void Number::BigInteger::Pow10(UInt32 exponent, BigInteger& result) {
}

UInt32 Number::BigInteger::AddDivisor(BigInteger& lhs, Int32 lhsStartIndex, BigInteger& rhs) {
  return UInt32();
}

Boolean Number::BigInteger::DivideGuessTooBig(UInt64 q, UInt64 valHi, UInt32 valLo, UInt32 divHi, UInt32 divLo) {
  return Boolean();
}

UInt32 Number::BigInteger::SubtractDivisor(BigInteger& lhs, Int32 lhsStartIndex, BigInteger& rhs, UInt64 q) {
  return UInt32();
}

void Number::BigInteger::Add(UInt32 value) {
}

UInt32 Number::BigInteger::GetBlock(UInt32 index) {
  return UInt32();
}

Int32 Number::BigInteger::GetLength() {
  return Int32();
}

Boolean Number::BigInteger::IsOne() {
  return Boolean();
}

Boolean Number::BigInteger::IsZero() {
  return Boolean();
}

void Number::BigInteger::Multiply(UInt32 value) {
}

void Number::BigInteger::Multiply(BigInteger& value) {
}

void Number::BigInteger::Multiply10() {
}

void Number::BigInteger::MultiplyPow10(UInt32 exponent) {
}

void Number::BigInteger::SetUInt32(BigInteger& result, UInt32 value) {
}

void Number::BigInteger::SetUInt64(BigInteger& result, UInt64 value) {
}

void Number::BigInteger::SetValue(BigInteger& result, BigInteger& value) {
}

void Number::BigInteger::SetZero(BigInteger& result) {
}

void Number::BigInteger::ShiftLeft(UInt32 shift) {
}

UInt64 Number::BigInteger::ToUInt64() {
  return UInt64();
}

UInt32* Number::BigInteger::GetBlocksPointer() {
  return nullptr;
}

UInt32 Number::BigInteger::DivRem32(UInt32 value, UInt32& remainder) {
  return UInt32();
}

void Number::BigInteger::ctor_static() {
}

Boolean Number::Grisu3::TryRunDouble(Double value, Int32 requestedDigits, NumberBuffer& number) {
  return Boolean();
}

Boolean Number::Grisu3::TryRunSingle(Single value, Int32 requestedDigits, NumberBuffer& number) {
  return Boolean();
}

Boolean Number::Grisu3::TryRunCounted(DiyFp& w, Int32 requestedDigits, Span<Byte> buffer, Int32& length, Int32& decimalExponent) {
  return Boolean();
}

Boolean Number::Grisu3::TryRunShortest(DiyFp& boundaryMinus, DiyFp& w, DiyFp& boundaryPlus, Span<Byte> buffer, Int32& length, Int32& decimalExponent) {
  return Boolean();
}

UInt32 Number::Grisu3::BiggestPowerTen(UInt32 number, Int32 numberBits, Int32& exponentPlusOne) {
  return UInt32();
}

Boolean Number::Grisu3::TryDigitGenCounted(DiyFp& w, Int32 requestedDigits, Span<Byte> buffer, Int32& length, Int32& kappa) {
  return Boolean();
}

Boolean Number::Grisu3::TryDigitGenShortest(DiyFp& low, DiyFp& w, DiyFp& high, Span<Byte> buffer, Int32& length, Int32& kappa) {
  return Boolean();
}

Number::DiyFp Number::Grisu3::GetCachedPowerForBinaryExponentRange(Int32 minExponent, Int32 maxExponent, Int32& decimalExponent) {
  return Number::DiyFp();
}

Boolean Number::Grisu3::TryRoundWeedCounted(Span<Byte> buffer, Int32 length, UInt64 rest, UInt64 tenKappa, UInt64 unit, Int32& kappa) {
  return Boolean();
}

Boolean Number::Grisu3::TryRoundWeedShortest(Span<Byte> buffer, Int32 length, UInt64 distanceTooHighW, UInt64 unsafeInterval, UInt64 rest, UInt64 tenKappa, UInt64 unit) {
  return Boolean();
}

void Number::Grisu3::ctor_static() {
}

Number::FloatingPointInfo::FloatingPointInfo(UInt16 denormalMantissaBits, UInt16 exponentBits, Int32 maxBinaryExponent, Int32 exponentBias, UInt64 infinityBits) {
}

void Number::FloatingPointInfo::ctor_static() {
}

ReadOnlySpan<Byte> Number::get_CharToHexLookup() {
  return ReadOnlySpan<Byte>();
}

void Number::Dragon4Double(Double value, Int32 cutoffNumber, Boolean isSignificantDigits, NumberBuffer& number) {
}

void Number::Dragon4Single(Single value, Int32 cutoffNumber, Boolean isSignificantDigits, NumberBuffer& number) {
}

UInt32 Number::Dragon4(UInt64 mantissa, Int32 exponent, UInt32 mantissaHighBitIdx, Boolean hasUnequalMargins, Int32 cutoffNumber, Boolean isSignificantDigits, Span<Byte> buffer, Int32& decimalExponent) {
  return UInt32();
}

String Number::FormatDecimal(Decimal value, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  return nullptr;
}

Boolean Number::TryFormatDecimal(Decimal value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

void Number::DecimalToNumber(Decimal& d, NumberBuffer& number) {
}

String Number::FormatDouble(Double value, String format, NumberFormatInfo info) {
  return nullptr;
}

Boolean Number::TryFormatDouble(Double value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

Int32 Number::GetFloatingPointMaxDigitsAndPrecision(Char fmt, Int32& precision, NumberFormatInfo info, Boolean& isSignificantDigits) {
  return Int32();
}

String Number::FormatDouble(ValueStringBuilder& sb, Double value, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  return nullptr;
}

String Number::FormatSingle(Single value, String format, NumberFormatInfo info) {
  return nullptr;
}

Boolean Number::TryFormatSingle(Single value, ReadOnlySpan<Char> format, NumberFormatInfo info, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

String Number::FormatSingle(ValueStringBuilder& sb, Single value, ReadOnlySpan<Char> format, NumberFormatInfo info) {
  return nullptr;
}

Boolean Number::TryCopyTo(String source, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

Char Number::GetHexBase(Char fmt) {
  return Char();
}

String Number::FormatInt32(Int32 value, Int32 hexMask, String format, IFormatProvider provider) {
  return nullptr;
}

Boolean Number::TryFormatInt32(Int32 value, Int32 hexMask, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

String Number::FormatUInt32(UInt32 value, String format, IFormatProvider provider) {
  return nullptr;
}

Boolean Number::TryFormatUInt32(UInt32 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

String Number::FormatInt64(Int64 value, String format, IFormatProvider provider) {
  return nullptr;
}

Boolean Number::TryFormatInt64(Int64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

String Number::FormatUInt64(UInt64 value, String format, IFormatProvider provider) {
  return nullptr;
}

Boolean Number::TryFormatUInt64(UInt64 value, ReadOnlySpan<Char> format, IFormatProvider provider, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

void Number::Int32ToNumber(Int32 value, NumberBuffer& number) {
}

String Number::Int32ToDecStr(Int32 value) {
  return nullptr;
}

String Number::NegativeInt32ToDecStr(Int32 value, Int32 digits, String sNegative) {
  return nullptr;
}

Boolean Number::TryNegativeInt32ToDecStr(Int32 value, Int32 digits, String sNegative, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

String Number::Int32ToHexStr(Int32 value, Char hexBase, Int32 digits) {
  return nullptr;
}

Boolean Number::TryInt32ToHexStr(Int32 value, Char hexBase, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

Char* Number::Int32ToHexChars(Char* buffer, UInt32 value, Int32 hexBase, Int32 digits) {
  return nullptr;
}

void Number::UInt32ToNumber(UInt32 value, NumberBuffer& number) {
}

Byte* Number::UInt32ToDecChars(Byte* bufferEnd, UInt32 value, Int32 digits) {
  return nullptr;
}

Char* Number::UInt32ToDecChars(Char* bufferEnd, UInt32 value, Int32 digits) {
  return nullptr;
}

String Number::UInt32ToDecStr(UInt32 value) {
  return nullptr;
}

String Number::UInt32ToDecStr(UInt32 value, Int32 digits) {
  return nullptr;
}

Boolean Number::TryUInt32ToDecStr(UInt32 value, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

void Number::Int64ToNumber(Int64 input, NumberBuffer& number) {
}

String Number::Int64ToDecStr(Int64 value) {
  return nullptr;
}

String Number::NegativeInt64ToDecStr(Int64 input, Int32 digits, String sNegative) {
  return nullptr;
}

Boolean Number::TryNegativeInt64ToDecStr(Int64 input, Int32 digits, String sNegative, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

String Number::Int64ToHexStr(Int64 value, Char hexBase, Int32 digits) {
  return nullptr;
}

Boolean Number::TryInt64ToHexStr(Int64 value, Char hexBase, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

void Number::UInt64ToNumber(UInt64 value, NumberBuffer& number) {
}

String Number::UInt64ToDecStr(UInt64 value, Int32 digits) {
  return nullptr;
}

Boolean Number::TryUInt64ToDecStr(UInt64 value, Int32 digits, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
}

Char Number::ParseFormatSpecifier(ReadOnlySpan<Char> format, Int32& digits) {
  return Char();
}

void Number::NumberToString(ValueStringBuilder& sb, NumberBuffer& number, Char format, Int32 nMaxDigits, NumberFormatInfo info) {
}

void Number::NumberToStringFormat(ValueStringBuilder& sb, NumberBuffer& number, ReadOnlySpan<Char> format, NumberFormatInfo info) {
}

void Number::FormatCurrency(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info) {
}

void Number::FormatFixed(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, Array<Int32> groupDigits, String sDecimal, String sGroup) {
}

void Number::FormatNumber(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info) {
}

void Number::FormatScientific(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info, Char expChar) {
}

void Number::FormatExponent(ValueStringBuilder& sb, NumberFormatInfo info, Int32 value, Char expChar, Int32 minDigits, Boolean positiveSign) {
}

void Number::FormatGeneral(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info, Char expChar, Boolean bSuppressScientific) {
}

void Number::FormatPercent(ValueStringBuilder& sb, NumberBuffer& number, Int32 nMaxDigits, NumberFormatInfo info) {
}

void Number::RoundNumber(NumberBuffer& number, Int32 pos, Boolean isCorrectlyRounded) {
}

Int32 Number::FindSection(ReadOnlySpan<Char> format, Int32 section) {
  return Int32();
}

UInt32 Number::Low32(UInt64 value) {
  return UInt32();
}

UInt32 Number::High32(UInt64 value) {
  return UInt32();
}

UInt32 Number::Int64DivMod1E9(UInt64& value) {
  return UInt32();
}

UInt64 Number::ExtractFractionAndBiasedExponent(Double value, Int32& exponent) {
  return UInt64();
}

UInt32 Number::ExtractFractionAndBiasedExponent(Single value, Int32& exponent) {
  return UInt32();
}

void Number::AccumulateDecimalDigitsIntoBigInteger(NumberBuffer& number, UInt32 firstIndex, UInt32 lastIndex, BigInteger& result) {
}

UInt64 Number::AssembleFloatingPointBits(FloatingPointInfo& info, UInt64 initialMantissa, Int32 initialExponent, Boolean hasZeroTail) {
  return UInt64();
}

UInt64 Number::ConvertBigIntegerToFloatingPointBits(BigInteger& value, FloatingPointInfo& info, UInt32 integerBitsOfPrecision, Boolean hasNonZeroFractionalPart) {
  return UInt64();
}

UInt32 Number::DigitsToUInt32(Byte* p, Int32 count) {
  return UInt32();
}

UInt64 Number::DigitsToUInt64(Byte* p, Int32 count) {
  return UInt64();
}

UInt64 Number::NumberToFloatingPointBits(NumberBuffer& number, FloatingPointInfo& info) {
  return UInt64();
}

UInt64 Number::NumberToFloatingPointBitsSlow(NumberBuffer& number, FloatingPointInfo& info, UInt32 positiveExponent, UInt32 integerDigitsPresent, UInt32 fractionalDigitsPresent) {
  return UInt64();
}

UInt64 Number::RightShiftWithRounding(UInt64 value, Int32 shift, Boolean hasZeroTail) {
  return UInt64();
}

Boolean Number::ShouldRoundUp(Boolean lsbBit, Boolean roundBit, Boolean hasTailBits) {
  return Boolean();
}

Boolean Number::TryNumberToInt32(NumberBuffer& number, Int32& value) {
  return Boolean();
}

Boolean Number::TryNumberToInt64(NumberBuffer& number, Int64& value) {
  return Boolean();
}

Boolean Number::TryNumberToUInt32(NumberBuffer& number, UInt32& value) {
  return Boolean();
}

Boolean Number::TryNumberToUInt64(NumberBuffer& number, UInt64& value) {
  return Boolean();
}

Int32 Number::ParseInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return Int32();
}

Int64 Number::ParseInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return Int64();
}

UInt32 Number::ParseUInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return UInt32();
}

UInt64 Number::ParseUInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return UInt64();
}

Boolean Number::TryParseNumber(Char*& str, Char* strEnd, NumberStyles styles, NumberBuffer& number, NumberFormatInfo info) {
  return Boolean();
}

Number::ParsingStatus Number::TryParseInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseInt32Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseInt32IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseInt64IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseInt64Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Int64& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt32(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt32Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt32IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt32HexNumberStyle(ReadOnlySpan<Char> value, NumberStyles styles, UInt32& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt64(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt64Number(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt64IntegerStyle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, UInt64& result) {
  return Number::ParsingStatus::Overflow;
}

Number::ParsingStatus Number::TryParseUInt64HexNumberStyle(ReadOnlySpan<Char> value, NumberStyles styles, UInt64& result) {
  return Number::ParsingStatus::Overflow;
}

Decimal Number::ParseDecimal(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return Decimal();
}

Boolean Number::TryNumberToDecimal(NumberBuffer& number, Decimal& value) {
  return Boolean();
}

Double Number::ParseDouble(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return Double();
}

Single Number::ParseSingle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info) {
  return Single();
}

Number::ParsingStatus Number::TryParseDecimal(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Decimal& result) {
  return Number::ParsingStatus::Overflow;
}

Boolean Number::TryParseDouble(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Double& result) {
  return Boolean();
}

Boolean Number::TryParseSingle(ReadOnlySpan<Char> value, NumberStyles styles, NumberFormatInfo info, Single& result) {
  return Boolean();
}

Boolean Number::TryStringToNumber(ReadOnlySpan<Char> value, NumberStyles styles, NumberBuffer& number, NumberFormatInfo info) {
  return Boolean();
}

Boolean Number::TrailingZeros(ReadOnlySpan<Char> value, Int32 index) {
  return Boolean();
}

Boolean Number::IsSpaceReplacingChar(Char c) {
  return Boolean();
}

Char* Number::MatchChars(Char* p, Char* pEnd, String value) {
  return nullptr;
}

Boolean Number::IsWhite(Int32 ch) {
  return Boolean();
}

Boolean Number::IsDigit(Int32 ch) {
  return Boolean();
}

void Number::ThrowOverflowOrFormatException(ParsingStatus status, TypeCode type) {
}

void Number::ThrowOverflowException(TypeCode type) {
}

Exception Number::GetException(ParsingStatus status, TypeCode type) {
  return nullptr;
}

Double Number::NumberToDouble(NumberBuffer& number) {
  return Double();
}

Single Number::NumberToSingle(NumberBuffer& number) {
  return Single();
}

void Number::ctor_static() {
}

} // namespace System::Private::CoreLib::System::NumberNamespace
