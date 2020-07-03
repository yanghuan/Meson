#include "DateTime-dep.h"

#include <System.Private.CoreLib/System/DateTime-dep.h>

namespace System::Private::CoreLib::System::DateTimeNamespace {
Int64 DateTime::get_InternalTicks() {
  return Int64();
};
UInt64 DateTime::get_InternalKind() {
  return UInt64();
};
DateTime DateTime::get_Date() {
  return DateTime();
};
Int32 DateTime::get_Day() {
  return Int32();
};
DayOfWeek DateTime::get_DayOfWeek() {
  return DayOfWeek();
};
Int32 DateTime::get_DayOfYear() {
  return Int32();
};
Int32 DateTime::get_Hour() {
  return Int32();
};
DateTimeKind DateTime::get_Kind() {
  return DateTimeKind();
};
Int32 DateTime::get_Millisecond() {
  return Int32();
};
Int32 DateTime::get_Minute() {
  return Int32();
};
Int32 DateTime::get_Month() {
  return Int32();
};
DateTime DateTime::get_Now() {
  return DateTime();
};
Int32 DateTime::get_Second() {
  return Int32();
};
Int64 DateTime::get_Ticks() {
  return Int64();
};
TimeSpan DateTime::get_TimeOfDay() {
  return TimeSpan();
};
DateTime DateTime::get_Today() {
  return DateTime();
};
Int32 DateTime::get_Year() {
  return Int32();
};
DateTime DateTime::get_UtcNow() {
  return DateTime();
};
DateTime DateTime::Add(TimeSpan value) {
  return DateTime();
};
DateTime DateTime::Add(Double value, Int32 scale) {
  return DateTime();
};
DateTime DateTime::AddDays(Double value) {
  return DateTime();
};
DateTime DateTime::AddHours(Double value) {
  return DateTime();
};
DateTime DateTime::AddMilliseconds(Double value) {
  return DateTime();
};
DateTime DateTime::AddMinutes(Double value) {
  return DateTime();
};
DateTime DateTime::AddMonths(Int32 months) {
  return DateTime();
};
DateTime DateTime::AddSeconds(Double value) {
  return DateTime();
};
DateTime DateTime::AddTicks(Int64 value) {
  return DateTime();
};
Boolean DateTime::TryAddTicks(Int64 value, DateTime& result) {
  return Boolean();
};
DateTime DateTime::AddYears(Int32 value) {
  return DateTime();
};
Int32 DateTime::Compare(DateTime t1, DateTime t2) {
  return Int32();
};
Int32 DateTime::CompareTo(Object value) {
  return Int32();
};
Int32 DateTime::CompareTo(DateTime value) {
  return Int32();
};
Int64 DateTime::DateToTicks(Int32 year, Int32 month, Int32 day) {
  return Int64();
};
Int64 DateTime::TimeToTicks(Int32 hour, Int32 minute, Int32 second) {
  return Int64();
};
Int32 DateTime::DaysInMonth(Int32 year, Int32 month) {
  return Int32();
};
Int64 DateTime::DoubleDateToTicks(Double value) {
  return Int64();
};
Boolean DateTime::Equals(Object value) {
  return Boolean();
};
Boolean DateTime::Equals(DateTime value) {
  return Boolean();
};
Boolean DateTime::Equals(DateTime t1, DateTime t2) {
  return Boolean();
};
DateTime DateTime::FromBinary(Int64 dateData) {
  return DateTime();
};
DateTime DateTime::FromBinaryRaw(Int64 dateData) {
  return DateTime();
};
DateTime DateTime::FromFileTime(Int64 fileTime) {
  return DateTime();
};
DateTime DateTime::FromFileTimeUtc(Int64 fileTime) {
  return DateTime();
};
DateTime DateTime::FromOADate(Double d) {
  return DateTime();
};
Boolean DateTime::IsDaylightSavingTime() {
  return Boolean();
};
DateTime DateTime::SpecifyKind(DateTime value, DateTimeKind kind) {
  return DateTime();
};
Int64 DateTime::ToBinary() {
  return Int64();
};
Int32 DateTime::GetDatePart(Int32 part) {
  return Int32();
};
void DateTime::GetDatePart(Int32& year, Int32& month, Int32& day) {
};
Int32 DateTime::GetHashCode() {
  return Int32();
};
Boolean DateTime::IsAmbiguousDaylightSavingTime() {
  return Boolean();
};
Boolean DateTime::IsLeapYear(Int32 year) {
  return Boolean();
};
DateTime DateTime::Parse(String s) {
  return DateTime();
};
DateTime DateTime::Parse(String s, IFormatProvider provider) {
  return DateTime();
};
DateTime DateTime::Parse(String s, IFormatProvider provider, DateTimeStyles styles) {
  return DateTime();
};
DateTime DateTime::Parse(ReadOnlySpan<Char> s, IFormatProvider provider, DateTimeStyles styles) {
  return DateTime();
};
DateTime DateTime::ParseExact(String s, String format, IFormatProvider provider) {
  return DateTime();
};
DateTime DateTime::ParseExact(String s, String format, IFormatProvider provider, DateTimeStyles style) {
  return DateTime();
};
DateTime DateTime::ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, IFormatProvider provider, DateTimeStyles style) {
  return DateTime();
};
DateTime DateTime::ParseExact(String s, Array<String> formats, IFormatProvider provider, DateTimeStyles style) {
  return DateTime();
};
DateTime DateTime::ParseExact(ReadOnlySpan<Char> s, Array<String> formats, IFormatProvider provider, DateTimeStyles style) {
  return DateTime();
};
TimeSpan DateTime::Subtract(DateTime value) {
  return TimeSpan();
};
DateTime DateTime::Subtract(TimeSpan value) {
  return DateTime();
};
Double DateTime::TicksToOADate(Int64 value) {
  return Double();
};
Double DateTime::ToOADate() {
  return Double();
};
Int64 DateTime::ToFileTime() {
  return Int64();
};
Int64 DateTime::ToFileTimeUtc() {
  return Int64();
};
DateTime DateTime::ToLocalTime() {
  return DateTime();
};
DateTime DateTime::ToLocalTime(Boolean throwOnOverflow) {
  return DateTime();
};
String DateTime::ToLongDateString() {
  return nullptr;
};
String DateTime::ToLongTimeString() {
  return nullptr;
};
String DateTime::ToShortDateString() {
  return nullptr;
};
String DateTime::ToShortTimeString() {
  return nullptr;
};
String DateTime::ToString() {
  return nullptr;
};
String DateTime::ToString(String format) {
  return nullptr;
};
String DateTime::ToString(IFormatProvider provider) {
  return nullptr;
};
String DateTime::ToString(String format, IFormatProvider provider) {
  return nullptr;
};
Boolean DateTime::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return Boolean();
};
DateTime DateTime::ToUniversalTime() {
  return DateTime();
};
Boolean DateTime::TryParse(String s, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParse(ReadOnlySpan<Char> s, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParse(String s, IFormatProvider provider, DateTimeStyles styles, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParse(ReadOnlySpan<Char> s, IFormatProvider provider, DateTimeStyles styles, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParseExact(String s, String format, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParseExact(String s, Array<String> formats, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  return Boolean();
};
Boolean DateTime::TryParseExact(ReadOnlySpan<Char> s, Array<String> formats, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  return Boolean();
};
Array<String> DateTime::GetDateTimeFormats() {
  return Array<String>();
};
Array<String> DateTime::GetDateTimeFormats(IFormatProvider provider) {
  return Array<String>();
};
Array<String> DateTime::GetDateTimeFormats(Char format) {
  return Array<String>();
};
Array<String> DateTime::GetDateTimeFormats(Char format, IFormatProvider provider) {
  return Array<String>();
};
TypeCode DateTime::GetTypeCode() {
  return TypeCode();
};
Boolean DateTime::TryCreate(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, DateTime& result) {
  return Boolean();
};
Boolean DateTime::IsValidTimeWithLeapSeconds(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateTimeKind kind) {
  return Boolean();
};
DateTime DateTime::FromFileTimeLeapSecondsAware(Int64 fileTime) {
  return DateTime();
};
Int64 DateTime::ToFileTimeLeapSecondsAware(Int64 ticks) {
  return Int64();
};
DateTime DateTime::CreateDateTimeFromSystemTime(FullSystemTime& time) {
  return DateTime();
};
Boolean DateTime::SystemSupportsLeapSeconds() {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::DateTimeNamespace
