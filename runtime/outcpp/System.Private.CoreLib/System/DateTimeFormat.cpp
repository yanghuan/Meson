#include "DateTimeFormat-dep.h"

namespace System::Private::CoreLib::System::DateTimeFormatNamespace {
void DateTimeFormat::FormatDigits(StringBuilder outputBuffer, Int32 value, Int32 len) {
};
void DateTimeFormat::FormatDigits(StringBuilder outputBuffer, Int32 value, Int32 len, Boolean overrideLengthLimit) {
};
void DateTimeFormat::HebrewFormatDigits(StringBuilder outputBuffer, Int32 digits) {
};
Int32 DateTimeFormat::ParseRepeatPattern(ReadOnlySpan<Char> format, Int32 pos, Char patternChar) {
  return Int32();
};
String DateTimeFormat::FormatDayOfWeek(Int32 dayOfWeek, Int32 repeat, DateTimeFormatInfo dtfi) {
  return nullptr;
};
String DateTimeFormat::FormatMonth(Int32 month, Int32 repeatCount, DateTimeFormatInfo dtfi) {
  return nullptr;
};
String DateTimeFormat::FormatHebrewMonthName(DateTime time, Int32 month, Int32 repeatCount, DateTimeFormatInfo dtfi) {
  return nullptr;
};
Int32 DateTimeFormat::ParseQuoteString(ReadOnlySpan<Char> format, Int32 pos, StringBuilder result) {
  return Int32();
};
Int32 DateTimeFormat::ParseNextChar(ReadOnlySpan<Char> format, Int32 pos) {
  return Int32();
};
Boolean DateTimeFormat::IsUseGenitiveForm(ReadOnlySpan<Char> format, Int32 index, Int32 tokenLen, Char patternToMatch) {
  return Boolean();
};
StringBuilder DateTimeFormat::FormatCustomized(DateTime dateTime, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, TimeSpan offset, StringBuilder result) {
  return nullptr;
};
void DateTimeFormat::FormatCustomizedTimeZone(DateTime dateTime, TimeSpan offset, Int32 tokenLen, Boolean timeOnly, StringBuilder result) {
};
void DateTimeFormat::FormatCustomizedRoundripTimeZone(DateTime dateTime, TimeSpan offset, StringBuilder result) {
};
void DateTimeFormat::Append2DigitNumber(StringBuilder result, Int32 val) {
};
String DateTimeFormat::GetRealFormat(ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi) {
  return nullptr;
};
String DateTimeFormat::ExpandPredefinedFormat(ReadOnlySpan<Char> format, DateTime& dateTime, DateTimeFormatInfo& dtfi, TimeSpan& offset) {
  return nullptr;
};
String DateTimeFormat::Format(DateTime dateTime, String format, IFormatProvider provider) {
  return nullptr;
};
String DateTimeFormat::Format(DateTime dateTime, String format, IFormatProvider provider, TimeSpan offset) {
  return nullptr;
};
Boolean DateTimeFormat::TryFormat(DateTime dateTime, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};
Boolean DateTimeFormat::TryFormat(DateTime dateTime, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider, TimeSpan offset) {
  return Boolean();
};
StringBuilder DateTimeFormat::FormatStringBuilder(DateTime dateTime, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, TimeSpan offset) {
  return nullptr;
};
Boolean DateTimeFormat::TryFormatO(DateTime dateTime, TimeSpan offset, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
Boolean DateTimeFormat::TryFormatR(DateTime dateTime, TimeSpan offset, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
void DateTimeFormat::WriteTwoDecimalDigits(UInt32 value, Span<Char> destination, Int32 offset) {
};
void DateTimeFormat::WriteFourDecimalDigits(UInt32 value, Span<Char> buffer, Int32 startingIndex) {
};
void DateTimeFormat::WriteDigits(UInt64 value, Span<Char> buffer) {
};
Array<String> DateTimeFormat::GetAllDateTimes(DateTime dateTime, Char format, DateTimeFormatInfo dtfi) {
  return Array<String>();
};
Array<String> DateTimeFormat::GetAllDateTimes(DateTime dateTime, DateTimeFormatInfo dtfi) {
  return Array<String>();
};
} // namespace System::Private::CoreLib::System::DateTimeFormatNamespace
