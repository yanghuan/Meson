#include "DateTimeFormatInfoScanner-dep.h"

namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoScannerNamespace {
Int32 DateTimeFormatInfoScanner___::SkipWhiteSpacesAndNonLetter(String pattern, Int32 currentIndex) {
  return Int32();
};
void DateTimeFormatInfoScanner___::AddDateWordOrPostfix(String formatPostfix, String str) {
};
Int32 DateTimeFormatInfoScanner___::AddDateWords(String pattern, Int32 index, String formatPostfix) {
  return Int32();
};
Int32 DateTimeFormatInfoScanner___::ScanRepeatChar(String pattern, Char ch, Int32 index, Int32& count) {
  return Int32();
};
void DateTimeFormatInfoScanner___::AddIgnorableSymbols(String text) {
};
void DateTimeFormatInfoScanner___::ScanDateWord(String pattern) {
};
Array<String> DateTimeFormatInfoScanner___::GetDateWordsOfDTFI(DateTimeFormatInfo dtfi) {
  return Array<String>();
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagGenitiveMonth(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames) {
  return FORMATFLAGS::UseDigitPrefixInTokens;
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseSpaceInMonthNames(Array<String> monthNames, Array<String> genitveMonthNames, Array<String> abbrevMonthNames, Array<String> genetiveAbbrevMonthNames) {
  return FORMATFLAGS::UseDigitPrefixInTokens;
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseSpaceInDayNames(Array<String> dayNames, Array<String> abbrevDayNames) {
  return FORMATFLAGS::UseDigitPrefixInTokens;
};
FORMATFLAGS DateTimeFormatInfoScanner___::GetFormatFlagUseHebrewCalendar(Int32 calID) {
  return FORMATFLAGS::UseDigitPrefixInTokens;
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
