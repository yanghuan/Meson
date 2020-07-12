#include "DateTimeOffset-dep.h"

#include <System.Private.CoreLib/System/DateTimeOffset-dep.h>

namespace System::Private::CoreLib::System::DateTimeOffsetNamespace {
DateTimeOffset DateTimeOffset::get_Now() {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::get_UtcNow() {
  return DateTimeOffset();
};

DateTime DateTimeOffset::get_DateTime() {
  return DateTime();
};

DateTime DateTimeOffset::get_UtcDateTime() {
  return DateTime();
};

DateTime DateTimeOffset::get_LocalDateTime() {
  return DateTime();
};

DateTime DateTimeOffset::get_ClockDateTime() {
  return DateTime();
};

DateTime DateTimeOffset::get_Date() {
  return DateTime();
};

Int32 DateTimeOffset::get_Day() {
  return Int32();
};

DayOfWeek DateTimeOffset::get_DayOfWeek() {
  return DayOfWeek::Saturday;
};

Int32 DateTimeOffset::get_DayOfYear() {
  return Int32();
};

Int32 DateTimeOffset::get_Hour() {
  return Int32();
};

Int32 DateTimeOffset::get_Millisecond() {
  return Int32();
};

Int32 DateTimeOffset::get_Minute() {
  return Int32();
};

Int32 DateTimeOffset::get_Month() {
  return Int32();
};

TimeSpan DateTimeOffset::get_Offset() {
  return TimeSpan();
};

Int32 DateTimeOffset::get_Second() {
  return Int32();
};

Int64 DateTimeOffset::get_Ticks() {
  return Int64();
};

Int64 DateTimeOffset::get_UtcTicks() {
  return Int64();
};

TimeSpan DateTimeOffset::get_TimeOfDay() {
  return TimeSpan();
};

Int32 DateTimeOffset::get_Year() {
  return Int32();
};

DateTimeOffset DateTimeOffset::ToOffset(TimeSpan offset) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::Add(TimeSpan timeSpan) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddDays(Double days) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddHours(Double hours) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddMilliseconds(Double milliseconds) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddMinutes(Double minutes) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddMonths(Int32 months) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddSeconds(Double seconds) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddTicks(Int64 ticks) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::AddYears(Int32 years) {
  return DateTimeOffset();
};

Int32 DateTimeOffset::Compare(DateTimeOffset first, DateTimeOffset second) {
  return Int32();
};

Int32 DateTimeOffset::CompareTo(DateTimeOffset other) {
  return Int32();
};

Boolean DateTimeOffset::Equals(Object obj) {
  return Boolean();
};

Boolean DateTimeOffset::Equals(DateTimeOffset other) {
  return Boolean();
};

Boolean DateTimeOffset::EqualsExact(DateTimeOffset other) {
  return Boolean();
};

Boolean DateTimeOffset::Equals(DateTimeOffset first, DateTimeOffset second) {
  return Boolean();
};

DateTimeOffset DateTimeOffset::FromFileTime(Int64 fileTime) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::FromUnixTimeSeconds(Int64 seconds) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::FromUnixTimeMilliseconds(Int64 milliseconds) {
  return DateTimeOffset();
};

Int32 DateTimeOffset::GetHashCode() {
  return Int32();
};

DateTimeOffset DateTimeOffset::Parse(String input) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::Parse(String input, IFormatProvider formatProvider) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::Parse(String input, IFormatProvider formatProvider, DateTimeStyles styles) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, DateTimeStyles styles) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ParseExact(String input, String format, IFormatProvider formatProvider) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ParseExact(String input, String format, IFormatProvider formatProvider, DateTimeStyles styles) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, DateTimeStyles styles) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ParseExact(String input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles) {
  return DateTimeOffset();
};

TimeSpan DateTimeOffset::Subtract(DateTimeOffset value) {
  return TimeSpan();
};

DateTimeOffset DateTimeOffset::Subtract(TimeSpan value) {
  return DateTimeOffset();
};

Int64 DateTimeOffset::ToFileTime() {
  return Int64();
};

Int64 DateTimeOffset::ToUnixTimeSeconds() {
  return Int64();
};

Int64 DateTimeOffset::ToUnixTimeMilliseconds() {
  return Int64();
};

DateTimeOffset DateTimeOffset::ToLocalTime() {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ToLocalTime(Boolean throwOnOverflow) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::ToLocalTime(DateTime utcDateTime, Boolean throwOnOverflow) {
  return DateTimeOffset();
};

String DateTimeOffset::ToString() {
  return nullptr;
};

String DateTimeOffset::ToString(String format) {
  return nullptr;
};

String DateTimeOffset::ToString(IFormatProvider formatProvider) {
  return nullptr;
};

String DateTimeOffset::ToString(String format, IFormatProvider formatProvider) {
  return nullptr;
};

Boolean DateTimeOffset::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  return Boolean();
};

DateTimeOffset DateTimeOffset::ToUniversalTime() {
  return DateTimeOffset();
};

Boolean DateTimeOffset::TryParse(String input, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParse(ReadOnlySpan<Char> input, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParse(String input, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParseExact(String input, String format, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  return Boolean();
};

Boolean DateTimeOffset::TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  return Boolean();
};

Int16 DateTimeOffset::ValidateOffset(TimeSpan offset) {
  return Int16();
};

DateTime DateTimeOffset::ValidateDate(DateTime dateTime, TimeSpan offset) {
  return DateTime();
};

DateTimeStyles DateTimeOffset::ValidateStyles(DateTimeStyles style, String parameterName) {
  return DateTimeStyles::RoundtripKind;
};

DateTimeOffset DateTimeOffset::op_Implicit(DateTime dateTime) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::op_Addition(DateTimeOffset dateTimeOffset, TimeSpan timeSpan) {
  return DateTimeOffset();
};

DateTimeOffset DateTimeOffset::op_Subtraction(DateTimeOffset dateTimeOffset, TimeSpan timeSpan) {
  return DateTimeOffset();
};

TimeSpan DateTimeOffset::op_Subtraction(DateTimeOffset left, DateTimeOffset right) {
  return TimeSpan();
};

Boolean DateTimeOffset::op_Equality(DateTimeOffset left, DateTimeOffset right) {
  return Boolean();
};

Boolean DateTimeOffset::op_Inequality(DateTimeOffset left, DateTimeOffset right) {
  return Boolean();
};

Boolean DateTimeOffset::op_LessThan(DateTimeOffset left, DateTimeOffset right) {
  return Boolean();
};

Boolean DateTimeOffset::op_LessThanOrEqual(DateTimeOffset left, DateTimeOffset right) {
  return Boolean();
};

Boolean DateTimeOffset::op_GreaterThan(DateTimeOffset left, DateTimeOffset right) {
  return Boolean();
};

Boolean DateTimeOffset::op_GreaterThanOrEqual(DateTimeOffset left, DateTimeOffset right) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::DateTimeOffsetNamespace
