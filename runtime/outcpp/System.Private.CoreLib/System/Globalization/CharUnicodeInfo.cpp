#include "CharUnicodeInfo-dep.h"

namespace System::Private::CoreLib::System::Globalization::CharUnicodeInfoNamespace {
ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryCasingLevel1Index() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryCasingLevel2Index() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryCasingLevel3Index() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoriesValues() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericGraphemeLevel1Index() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericGraphemeLevel2Index() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericGraphemeLevel3Index() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_DigitValues() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericValues() {
  return ReadOnlySpan<Byte>();
}

ReadOnlySpan<Byte> CharUnicodeInfo::get_GraphemeSegmentationValues() {
  return ReadOnlySpan<Byte>();
}

StrongBidiCategory CharUnicodeInfo::GetBidiCategory(String s, Int32 index) {
  return StrongBidiCategory::StrongRightToLeft;
}

StrongBidiCategory CharUnicodeInfo::GetBidiCategory(StringBuilder s, Int32 index) {
  return StrongBidiCategory::StrongRightToLeft;
}

StrongBidiCategory CharUnicodeInfo::GetBidiCategoryNoBoundsChecks(UInt32 codePoint) {
  return StrongBidiCategory::StrongRightToLeft;
}

Int32 CharUnicodeInfo::GetDecimalDigitValue(Char ch) {
  return Int32();
}

Int32 CharUnicodeInfo::GetDecimalDigitValue(String s, Int32 index) {
  return Int32();
}

Int32 CharUnicodeInfo::GetDecimalDigitValueInternalNoBoundsCheck(UInt32 codePoint) {
  return Int32();
}

Int32 CharUnicodeInfo::GetDigitValue(Char ch) {
  return Int32();
}

Int32 CharUnicodeInfo::GetDigitValue(String s, Int32 index) {
  return Int32();
}

Int32 CharUnicodeInfo::GetDigitValueInternalNoBoundsCheck(UInt32 codePoint) {
  return Int32();
}

GraphemeClusterBreakType CharUnicodeInfo::GetGraphemeClusterBreakType(Rune rune) {
  return GraphemeClusterBreakType::Extended_Pictograph;
}

Boolean CharUnicodeInfo::GetIsWhiteSpace(Char ch) {
  return Boolean();
}

Double CharUnicodeInfo::GetNumericValue(Char ch) {
  return Double();
}

Double CharUnicodeInfo::GetNumericValue(Int32 codePoint) {
  return Double();
}

Double CharUnicodeInfo::GetNumericValue(String s, Int32 index) {
  return Double();
}

Double CharUnicodeInfo::GetNumericValueNoBoundsCheck(UInt32 codePoint) {
  return Double();
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(Char ch) {
  return UnicodeCategory::OtherNotAssigned;
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(Int32 codePoint) {
  return UnicodeCategory::OtherNotAssigned;
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(String s, Int32 index) {
  return UnicodeCategory::OtherNotAssigned;
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategoryInternal(String value, Int32 index) {
  return UnicodeCategory::OtherNotAssigned;
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategoryInternal(String str, Int32 index, Int32& charLength) {
  return UnicodeCategory::OtherNotAssigned;
}

UnicodeCategory CharUnicodeInfo::GetUnicodeCategoryNoBoundsChecks(UInt32 codePoint) {
  return UnicodeCategory::OtherNotAssigned;
}

Int32 CharUnicodeInfo::GetCodePointFromString(String s, Int32 index) {
  return Int32();
}

UIntPtr CharUnicodeInfo::GetCategoryCasingTableOffsetNoBoundsChecks(UInt32 codePoint) {
  return UIntPtr();
}

UIntPtr CharUnicodeInfo::GetNumericGraphemeTableOffsetNoBoundsChecks(UInt32 codePoint) {
  return UIntPtr();
}

} // namespace System::Private::CoreLib::System::Globalization::CharUnicodeInfoNamespace
