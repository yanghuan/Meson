#include "TimeSpanFormat-dep.h"

#include <System.Private.CoreLib/System/Globalization/TimeSpanFormat-dep.h>

namespace System::Private::CoreLib::System::Globalization::TimeSpanFormatNamespace {
String TimeSpanFormat::FormatLiterals::get_Start() {
  return nullptr;
};
String TimeSpanFormat::FormatLiterals::get_DayHourSep() {
  return nullptr;
};
String TimeSpanFormat::FormatLiterals::get_HourMinuteSep() {
  return nullptr;
};
String TimeSpanFormat::FormatLiterals::get_MinuteSecondSep() {
  return nullptr;
};
String TimeSpanFormat::FormatLiterals::get_SecondFractionSep() {
  return nullptr;
};
String TimeSpanFormat::FormatLiterals::get_End() {
  return nullptr;
};
TimeSpanFormat::FormatLiterals TimeSpanFormat::FormatLiterals::InitInvariant(Boolean isNegative) {
  return TimeSpanFormat::FormatLiterals();
};
void TimeSpanFormat::FormatLiterals::Init(ReadOnlySpan<Char> format, Boolean useInvariantFieldLengths) {
  return void();
};
String TimeSpanFormat::Format(TimeSpan value, String format, IFormatProvider formatProvider) {
  return nullptr;
};
Boolean TimeSpanFormat::TryFormat(TimeSpan value, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  return Boolean();
};
String TimeSpanFormat::FormatC(TimeSpan value) {
  return nullptr;
};
String TimeSpanFormat::FormatG(TimeSpan value, DateTimeFormatInfo dtfi, StandardFormat format) {
  return nullptr;
};
Boolean TimeSpanFormat::TryFormatStandard(TimeSpan value, StandardFormat format, String decimalSeparator, Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
void TimeSpanFormat::WriteTwoDigits(UInt32 value, Span<Char> buffer) {
  return void();
};
void TimeSpanFormat::WriteDigits(UInt32 value, Span<Char> buffer) {
  return void();
};
StringBuilder TimeSpanFormat::FormatCustomized(TimeSpan value, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, StringBuilder result) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Globalization::TimeSpanFormatNamespace