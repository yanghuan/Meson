#include "DateTimeParse-dep.h"

namespace System::Private::CoreLib::System::DateTimeParseNamespace {
DateTime DateTimeParse::ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style) {
  return DateTime();
}

DateTime DateTimeParse::ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, TimeSpan& offset) {
  return DateTime();
}

Boolean DateTimeParse::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result) {
  return Boolean();
}

Boolean DateTimeParse::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result, TimeSpan& offset) {
  return Boolean();
}

Boolean DateTimeParse::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTimeResult& result) {
  return Boolean();
}

DateTime DateTimeParse::ParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style) {
  return DateTime();
}

DateTime DateTimeParse::ParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, TimeSpan& offset) {
  return DateTime();
}

Boolean DateTimeParse::TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result, TimeSpan& offset) {
  return Boolean();
}

Boolean DateTimeParse::TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result) {
  return Boolean();
}

Boolean DateTimeParse::TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchWord(__DTString& str, String target) {
  return Boolean();
}

Boolean DateTimeParse::GetTimeZoneName(__DTString& str) {
  return Boolean();
}

Boolean DateTimeParse::IsDigit(Char ch) {
  return Boolean();
}

Boolean DateTimeParse::ParseFraction(__DTString& str, Double& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseTimeZone(__DTString& str, TimeSpan& result) {
  return Boolean();
}

Boolean DateTimeParse::HandleTimeZone(__DTString& str, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::Lex(DS dps, __DTString& str, DateTimeToken& dtok, DateTimeRawInfo& raw, DateTimeResult& result, DateTimeFormatInfo& dtfi, DateTimeStyles styles) {
  return Boolean();
}

Boolean DateTimeParse::VerifyValidPunctuation(__DTString& str) {
  return Boolean();
}

Boolean DateTimeParse::GetYearMonthDayOrder(String datePattern, Int32& order) {
  return Boolean();
}

Boolean DateTimeParse::GetYearMonthOrder(String pattern, Int32& order) {
  return Boolean();
}

Boolean DateTimeParse::GetMonthDayOrder(String pattern, Int32& order) {
  return Boolean();
}

Boolean DateTimeParse::TryAdjustYear(DateTimeResult& result, Int32 year, Int32& adjustedYear) {
  return Boolean();
}

Boolean DateTimeParse::SetDateYMD(DateTimeResult& result, Int32 year, Int32 month, Int32 day) {
  return Boolean();
}

Boolean DateTimeParse::SetDateMDY(DateTimeResult& result, Int32 month, Int32 day, Int32 year) {
  return Boolean();
}

Boolean DateTimeParse::SetDateDMY(DateTimeResult& result, Int32 day, Int32 month, Int32 year) {
  return Boolean();
}

Boolean DateTimeParse::SetDateYDM(DateTimeResult& result, Int32 year, Int32 day, Int32 month) {
  return Boolean();
}

void DateTimeParse::GetDefaultYear(DateTimeResult& result, DateTimeStyles& styles) {
}

Boolean DateTimeParse::GetDayOfNN(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfNNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfMN(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetHebrewDayOfNM(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfNM(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfMNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfYNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfNNY(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfYMN(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfYN(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetDayOfYM(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

void DateTimeParse::AdjustTimeMark(DateTimeFormatInfo dtfi, DateTimeRawInfo& raw) {
}

Boolean DateTimeParse::AdjustHour(Int32& hour, TM timeMark) {
  return Boolean();
}

Boolean DateTimeParse::GetTimeOfN(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetTimeOfNN(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetTimeOfNNN(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetDateOfDSN(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetDateOfNDS(DateTimeResult& result, DateTimeRawInfo& raw) {
  return Boolean();
}

Boolean DateTimeParse::GetDateOfNNDS(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::ProcessDateTimeSuffix(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeToken& dtok) {
  return Boolean();
}

Boolean DateTimeParse::ProcessHebrewTerminalState(DS dps, DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

Boolean DateTimeParse::ProcessTerminalState(DS dps, DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  return Boolean();
}

DateTime DateTimeParse::Parse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles) {
  return DateTime();
}

DateTime DateTimeParse::Parse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, TimeSpan& offset) {
  return DateTime();
}

Boolean DateTimeParse::TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTime& result) {
  return Boolean();
}

Boolean DateTimeParse::TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTime& result, TimeSpan& offset) {
  return Boolean();
}

Boolean DateTimeParse::TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::DetermineTimeZoneAdjustments(DateTimeResult& result, DateTimeStyles styles, Boolean bTimeOnly) {
  return Boolean();
}

Boolean DateTimeParse::DateTimeOffsetTimeZonePostProcessing(DateTimeResult& result, DateTimeStyles styles) {
  return Boolean();
}

Boolean DateTimeParse::AdjustTimeZoneToUniversal(DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::AdjustTimeZoneToLocal(DateTimeResult& result, Boolean bTimeOnly) {
  return Boolean();
}

Boolean DateTimeParse::ParseISO8601(DateTimeRawInfo& raw, __DTString& str, DateTimeStyles styles, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchHebrewDigits(__DTString& str, Int32 digitLen, Int32& number) {
  return Boolean();
}

Boolean DateTimeParse::ParseDigits(__DTString& str, Int32 digitLen, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseDigits(__DTString& str, Int32 minDigitLen, Int32 maxDigitLen, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseFractionExact(__DTString& str, Int32 maxDigitLen, Double& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseSign(__DTString& str, Boolean& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseTimeZoneOffset(__DTString& str, Int32 len, TimeSpan& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchAbbreviatedMonthName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchMonthName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchAbbreviatedDayName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchDayName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchEraName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchTimeMark(__DTString& str, DateTimeFormatInfo dtfi, TM& result) {
  return Boolean();
}

Boolean DateTimeParse::MatchAbbreviatedTimeMark(__DTString& str, DateTimeFormatInfo dtfi, TM& result) {
  return Boolean();
}

Boolean DateTimeParse::CheckNewValue(Int32& currentValue, Int32 newValue, Char patternChar, DateTimeResult& result) {
  return Boolean();
}

DateTime DateTimeParse::GetDateTimeNow(DateTimeResult& result, DateTimeStyles& styles) {
  return DateTime();
}

Boolean DateTimeParse::CheckDefaultDateTime(DateTimeResult& result, Calendar& cal, DateTimeStyles styles) {
  return Boolean();
}

String DateTimeParse::ExpandPredefinedFormat(ReadOnlySpan<Char> format, DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo, DateTimeResult& result) {
  return nullptr;
}

Boolean DateTimeParse::ParseJapaneseEraStart(__DTString& str, DateTimeFormatInfo dtfi) {
  return Boolean();
}

void DateTimeParse::ConfigureFormatR(DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo, DateTimeResult& result) {
}

void DateTimeParse::ConfigureFormatOS(DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo) {
}

Boolean DateTimeParse::ParseByFormat(__DTString& str, __DTString& format, ParsingInfo& parseInfo, DateTimeFormatInfo dtfi, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::TryParseQuoteString(ReadOnlySpan<Char> format, Int32 pos, StringBuilder result, Int32& returnValue) {
  return Boolean();
}

Boolean DateTimeParse::DoStrictParse(ReadOnlySpan<Char> s, ReadOnlySpan<Char> formatParam, DateTimeStyles styles, DateTimeFormatInfo dtfi, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseFormatR(ReadOnlySpan<Char> source, ParsingInfo& parseInfo, DateTimeResult& result) {
  return Boolean();
}

Boolean DateTimeParse::ParseFormatO(ReadOnlySpan<Char> source, DateTimeResult& result) {
  return Boolean();
}

Exception DateTimeParse::GetDateTimeParseException(DateTimeResult& result) {
  return nullptr;
}

void DateTimeParse::SCtor() {
}

} // namespace System::Private::CoreLib::System::DateTimeParseNamespace
