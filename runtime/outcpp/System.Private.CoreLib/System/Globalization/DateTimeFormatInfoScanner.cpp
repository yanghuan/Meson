#include "DateTimeFormatInfoScanner-dep.h"

namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoScannerNamespace {
Dictionary<String, String> DateTimeFormatInfoScanner___::get_KnownWords() {
  return nullptr;
};
Int32 DateTimeFormatInfoScanner___::SkipWhiteSpacesAndNonLetter(String pattern, Int32 currentIndex) {
  return Int32();
};
void DateTimeFormatInfoScanner___::AddDateWordOrPostfix(String formatPostfix, String str) {
  return void();
};
Int32 DateTimeFormatInfoScanner___::AddDateWords(String pattern, Int32 index, String formatPostfix) {
  return Int32();
};
Int32 DateTimeFormatInfoScanner___::ScanRepeatChar(String pattern, Char ch, Int32 index, Int32& count) {
  return Int32();
};
void DateTimeFormatInfoScanner___::AddIgnorableSymbols(String text) {
  return void();
};
void DateTimeFormatInfoScanner___::ScanDateWord(String pattern) {
  return void();
};
Array<String> DateTimeFormatInfoScanner___::GetDateWordsOfDTFI(DateTimeFormatInfo dtfi) {
  return Array<String>();
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagGenitiveMonth(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames) {
  return FORMATFLAGS();
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseSpaceInMonthNames(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames) {
  return FORMATFLAGS();
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseSpaceInDayNames(Array<String> dayNames, Array<String> abbrevDayNames) {
  return FORMATFLAGS();
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseHebrewCalendar(Int32 calID) {
  return FORMATFLAGS();
};
Boolean DateTimeFormatInfoScanner___::EqualStringArrays(Array<String> array1, Array<String> array2) {
  return Boolean();
};
Boolean DateTimeFormatInfoScanner___::ArrayElementsHaveSpace(Array<String> array) {
  return Boolean();
};
Boolean DateTimeFormatInfoScanner___::ArrayElementsBeginWithDigit(Array<String> array) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoScannerNamespace
