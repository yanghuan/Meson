#include "CharUnicodeInfo-dep.h"

namespace System::Private::CoreLib::System::Globalization::CharUnicodeInfoNamespace {
ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryLevel1Index() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryLevel2Index() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoryLevel3Index() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_CategoriesValue() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericLevel1Index() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericLevel2Index() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericLevel3Index() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_NumericValues() {
  return ReadOnlySpan<Byte>();
};
ReadOnlySpan<Byte> CharUnicodeInfo::get_DigitValues() {
  return ReadOnlySpan<Byte>();
};
Int32 CharUnicodeInfo::InternalConvertToUtf32(String s, Int32 index) {
  return Int32();
};
Int32 CharUnicodeInfo::InternalConvertToUtf32(StringBuilder s, Int32 index) {
  return Int32();
};
Int32 CharUnicodeInfo::InternalConvertToUtf32(String s, Int32 index, Int32& charLength) {
  return Int32();
};
Double CharUnicodeInfo::InternalGetNumericValue(Int32 ch) {
  return Double();
};
Byte CharUnicodeInfo::InternalGetDigitValues(Int32 ch, Int32 offset) {
  return Byte();
};
Double CharUnicodeInfo::GetNumericValue(Char ch) {
  return Double();
};
Double CharUnicodeInfo::GetNumericValue(String s, Int32 index) {
  return Double();
};
Int32 CharUnicodeInfo::GetDecimalDigitValue(Char ch) {
  return Int32();
};
Int32 CharUnicodeInfo::GetDecimalDigitValue(String s, Int32 index) {
  return Int32();
};
Int32 CharUnicodeInfo::GetDigitValue(Char ch) {
  return Int32();
};
Int32 CharUnicodeInfo::GetDigitValue(String s, Int32 index) {
  return Int32();
};
UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(Char ch) {
  return UnicodeCategory();
};
UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(String s, Int32 index) {
  return UnicodeCategory();
};
UnicodeCategory CharUnicodeInfo::GetUnicodeCategory(Int32 codePoint) {
  return UnicodeCategory();
};
Byte CharUnicodeInfo::InternalGetCategoryValue(Int32 ch, Int32 offset) {
  return Byte();
};
UnicodeCategory CharUnicodeInfo::InternalGetUnicodeCategory(String value, Int32 index) {
  return UnicodeCategory();
};
BidiCategory CharUnicodeInfo::GetBidiCategory(String s, Int32 index) {
  return BidiCategory();
};
BidiCategory CharUnicodeInfo::GetBidiCategory(StringBuilder s, Int32 index) {
  return BidiCategory();
};
UnicodeCategory CharUnicodeInfo::InternalGetUnicodeCategory(String str, Int32 index, Int32& charLength) {
  return UnicodeCategory();
};
Boolean CharUnicodeInfo::IsCombiningCategory(UnicodeCategory uc) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Globalization::CharUnicodeInfoNamespace
