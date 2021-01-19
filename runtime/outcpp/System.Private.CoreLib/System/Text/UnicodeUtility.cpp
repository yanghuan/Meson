#include "UnicodeUtility-dep.h"

namespace System::Private::CoreLib::System::Text::UnicodeUtilityNamespace {
Int32 UnicodeUtility::GetPlane(UInt32 codePoint) {
  return (Int32)(codePoint >> 16);
}

UInt32 UnicodeUtility::GetScalarFromUtf16SurrogatePair(UInt32 highSurrogateCodePoint, UInt32 lowSurrogateCodePoint) {
  return (highSurrogateCodePoint << 10) + lowSurrogateCodePoint - 56613888;
}

Int32 UnicodeUtility::GetUtf16SequenceLength(UInt32 value) {
  value -= 65536;
  value += 33554432;
  value >>= 24;
  return (Int32)value;
}

void UnicodeUtility::GetUtf16SurrogatesFromSupplementaryPlaneScalar(UInt32 value, Char& highSurrogateCodePoint, Char& lowSurrogateCodePoint) {
  highSurrogateCodePoint = (Char)(value + 56557568 >> 10);
  lowSurrogateCodePoint = (Char)((value & 1023) + 56320);
}

Int32 UnicodeUtility::GetUtf8SequenceLength(UInt32 value) {
  Int32 num = (Int32)(value - 2048) >> 31;
  value ^= 63488u;
  value -= 63616;
  value += 67108864;
  value >>= 24;
  return (Int32)value + num * 2;
}

Boolean UnicodeUtility::IsAsciiCodePoint(UInt32 value) {
  return value <= 127;
}

Boolean UnicodeUtility::IsBmpCodePoint(UInt32 value) {
  return value <= 65535;
}

Boolean UnicodeUtility::IsHighSurrogateCodePoint(UInt32 value) {
  return IsInRangeInclusive(value, 55296u, 56319u);
}

Boolean UnicodeUtility::IsInRangeInclusive(UInt32 value, UInt32 lowerBound, UInt32 upperBound) {
  return value - lowerBound <= upperBound - lowerBound;
}

Boolean UnicodeUtility::IsLowSurrogateCodePoint(UInt32 value) {
  return IsInRangeInclusive(value, 56320u, 57343u);
}

Boolean UnicodeUtility::IsSurrogateCodePoint(UInt32 value) {
  return IsInRangeInclusive(value, 55296u, 57343u);
}

Boolean UnicodeUtility::IsValidCodePoint(UInt32 codePoint) {
  return codePoint <= 1114111;
}

Boolean UnicodeUtility::IsValidUnicodeScalar(UInt32 value) {
  return ((value - 1114112) ^ 55296) >= 4293855232u;
}

} // namespace System::Private::CoreLib::System::Text::UnicodeUtilityNamespace
