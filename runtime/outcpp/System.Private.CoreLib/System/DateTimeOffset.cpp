#include "DateTimeOffset-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/DateTimeOffset-dep.h>
#include <System.Private.CoreLib/System/DateTimeParse-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeStyles.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfoOptions.h>

namespace System::Private::CoreLib::System::DateTimeOffsetNamespace {
using namespace System::Globalization;

DateTimeOffset DateTimeOffset::get_Now() {
  return ToLocalTime(DateTime::get_UtcNow(), true);
}

DateTimeOffset DateTimeOffset::get_UtcNow() {
  return DateTimeOffset(DateTime::get_UtcNow());
}

DateTime DateTimeOffset::get_DateTime() {
  return get_ClockDateTime();
}

DateTime DateTimeOffset::get_UtcDateTime() {
  return DateTime::SpecifyKind(_dateTime, DateTimeKind::Utc);
}

DateTime DateTimeOffset::get_LocalDateTime() {
  return get_UtcDateTime().ToLocalTime();
}

DateTime DateTimeOffset::get_ClockDateTime() {
  return DateTime((_dateTime + get_Offset()).get_Ticks(), DateTimeKind::Unspecified);
}

DateTime DateTimeOffset::get_Date() {
  return get_ClockDateTime().get_Date();
}

Int32 DateTimeOffset::get_Day() {
  return get_ClockDateTime().get_Day();
}

DayOfWeek DateTimeOffset::get_DayOfWeek() {
  return get_ClockDateTime().get_DayOfWeek();
}

Int32 DateTimeOffset::get_DayOfYear() {
  return get_ClockDateTime().get_DayOfYear();
}

Int32 DateTimeOffset::get_Hour() {
  return get_ClockDateTime().get_Hour();
}

Int32 DateTimeOffset::get_Millisecond() {
  return get_ClockDateTime().get_Millisecond();
}

Int32 DateTimeOffset::get_Minute() {
  return get_ClockDateTime().get_Minute();
}

Int32 DateTimeOffset::get_Month() {
  return get_ClockDateTime().get_Month();
}

TimeSpan DateTimeOffset::get_Offset() {
  return TimeSpan(0, _offsetMinutes, 0);
}

Int32 DateTimeOffset::get_Second() {
  return get_ClockDateTime().get_Second();
}

Int64 DateTimeOffset::get_Ticks() {
  return get_ClockDateTime().get_Ticks();
}

Int64 DateTimeOffset::get_UtcTicks() {
  return get_UtcDateTime().get_Ticks();
}

TimeSpan DateTimeOffset::get_TimeOfDay() {
  return get_ClockDateTime().get_TimeOfDay();
}

Int32 DateTimeOffset::get_Year() {
  return get_ClockDateTime().get_Year();
}

DateTimeOffset::DateTimeOffset(Int64 ticks, TimeSpan offset) {
  _offsetMinutes = ValidateOffset(offset);
  DateTime dateTime = DateTime(ticks);
  _dateTime = ValidateDate(dateTime, offset);
}

DateTimeOffset::DateTimeOffset(DateTime dateTime) {
  TimeSpan offset = (dateTime.get_Kind() != DateTimeKind::Utc) ? TimeZoneInfo::in::GetLocalUtcOffset(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime) : TimeSpan(0);
  _offsetMinutes = ValidateOffset(offset);
  _dateTime = ValidateDate(dateTime, offset);
}

DateTimeOffset::DateTimeOffset(DateTime dateTime, TimeSpan offset) {
  if (dateTime.get_Kind() == DateTimeKind::Local) {
    if (offset != TimeZoneInfo::in::GetLocalUtcOffset(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime)) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_OffsetLocalMismatch(), "offset");
    }
  } else if (dateTime.get_Kind() == DateTimeKind::Utc && offset != TimeSpan::Zero) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_OffsetUtcMismatch(), "offset");
  }

  _offsetMinutes = ValidateOffset(offset);
  _dateTime = ValidateDate(dateTime, offset);
}

DateTimeOffset::DateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, TimeSpan offset) {
  _offsetMinutes = ValidateOffset(offset);
  Int32 num = second;
  if (second == 60 && DateTime::s_systemSupportsLeapSeconds) {
    second = 59;
  }
  _dateTime = ValidateDate(DateTime(year, month, day, hour, minute, second), offset);
  if (num == 60 && !DateTime::IsValidTimeWithLeapSeconds(_dateTime.get_Year(), _dateTime.get_Month(), _dateTime.get_Day(), _dateTime.get_Hour(), _dateTime.get_Minute(), 60, DateTimeKind::Utc)) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
  }
}

DateTimeOffset::DateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, TimeSpan offset) {
  _offsetMinutes = ValidateOffset(offset);
  Int32 num = second;
  if (second == 60 && DateTime::s_systemSupportsLeapSeconds) {
    second = 59;
  }
  _dateTime = ValidateDate(DateTime(year, month, day, hour, minute, second, millisecond), offset);
  if (num == 60 && !DateTime::IsValidTimeWithLeapSeconds(_dateTime.get_Year(), _dateTime.get_Month(), _dateTime.get_Day(), _dateTime.get_Hour(), _dateTime.get_Minute(), 60, DateTimeKind::Utc)) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
  }
}

DateTimeOffset::DateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Calendar calendar, TimeSpan offset) {
  _offsetMinutes = ValidateOffset(offset);
  Int32 num = second;
  if (second == 60 && DateTime::s_systemSupportsLeapSeconds) {
    second = 59;
  }
  _dateTime = ValidateDate(DateTime(year, month, day, hour, minute, second, millisecond, calendar), offset);
  if (num == 60 && !DateTime::IsValidTimeWithLeapSeconds(_dateTime.get_Year(), _dateTime.get_Month(), _dateTime.get_Day(), _dateTime.get_Hour(), _dateTime.get_Minute(), 60, DateTimeKind::Utc)) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
  }
}

DateTimeOffset DateTimeOffset::ToOffset(TimeSpan offset) {
  return DateTimeOffset((_dateTime + offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::Add(TimeSpan timeSpan) {
  return DateTimeOffset(get_ClockDateTime().Add(timeSpan), get_Offset());
}

DateTimeOffset DateTimeOffset::AddDays(Double days) {
  return DateTimeOffset(get_ClockDateTime().AddDays(days), get_Offset());
}

DateTimeOffset DateTimeOffset::AddHours(Double hours) {
  return DateTimeOffset(get_ClockDateTime().AddHours(hours), get_Offset());
}

DateTimeOffset DateTimeOffset::AddMilliseconds(Double milliseconds) {
  return DateTimeOffset(get_ClockDateTime().AddMilliseconds(milliseconds), get_Offset());
}

DateTimeOffset DateTimeOffset::AddMinutes(Double minutes) {
  return DateTimeOffset(get_ClockDateTime().AddMinutes(minutes), get_Offset());
}

DateTimeOffset DateTimeOffset::AddMonths(Int32 months) {
  return DateTimeOffset(get_ClockDateTime().AddMonths(months), get_Offset());
}

DateTimeOffset DateTimeOffset::AddSeconds(Double seconds) {
  return DateTimeOffset(get_ClockDateTime().AddSeconds(seconds), get_Offset());
}

DateTimeOffset DateTimeOffset::AddTicks(Int64 ticks) {
  return DateTimeOffset(get_ClockDateTime().AddTicks(ticks), get_Offset());
}

DateTimeOffset DateTimeOffset::AddYears(Int32 years) {
  return DateTimeOffset(get_ClockDateTime().AddYears(years), get_Offset());
}

Int32 DateTimeOffset::Compare(DateTimeOffset first, DateTimeOffset second) {
  return DateTime::Compare(first.get_UtcDateTime(), second.get_UtcDateTime());
}

Int32 DateTimeOffset::CompareTo(DateTimeOffset other) {
  DateTime utcDateTime = other.get_UtcDateTime();
  DateTime utcDateTime2 = get_UtcDateTime();
  if (utcDateTime2 > utcDateTime) {
    return 1;
  }
  if (utcDateTime2 < utcDateTime) {
    return -1;
  }
  return 0;
}

Boolean DateTimeOffset::Equals(Object obj) {
  if (rt::is<DateTimeOffset>(obj)) {
    return get_UtcDateTime().Equals(((DateTimeOffset)obj).get_UtcDateTime());
  }
  return false;
}

Boolean DateTimeOffset::Equals(DateTimeOffset other) {
  return get_UtcDateTime().Equals(other.get_UtcDateTime());
}

Boolean DateTimeOffset::EqualsExact(DateTimeOffset other) {
  if (get_ClockDateTime() == other.get_ClockDateTime() && get_Offset() == other.get_Offset()) {
    return get_ClockDateTime().get_Kind() == other.get_ClockDateTime().get_Kind();
  }
  return false;
}

Boolean DateTimeOffset::Equals(DateTimeOffset first, DateTimeOffset second) {
  return DateTime::Equals(first.get_UtcDateTime(), second.get_UtcDateTime());
}

DateTimeOffset DateTimeOffset::FromFileTime(Int64 fileTime) {
  return ToLocalTime(DateTime::FromFileTimeUtc(fileTime), true);
}

DateTimeOffset DateTimeOffset::FromUnixTimeSeconds(Int64 seconds) {
  if (seconds < -62135596800 || seconds > 253402300799) {
    rt::throw_exception<ArgumentOutOfRangeException>("seconds", SR::Format(SR::get_ArgumentOutOfRange_Range(), -62135596800, 253402300799));
  }
  Int64 ticks = seconds * 10000000 + 621355968000000000;
  return DateTimeOffset(ticks, TimeSpan::Zero);
}

DateTimeOffset DateTimeOffset::FromUnixTimeMilliseconds(Int64 milliseconds) {
  if (milliseconds < -62135596800000 || milliseconds > 253402300799999) {
    rt::throw_exception<ArgumentOutOfRangeException>("milliseconds", SR::Format(SR::get_ArgumentOutOfRange_Range(), -62135596800000, 253402300799999));
  }
  Int64 ticks = milliseconds * 10000 + 621355968000000000;
  return DateTimeOffset(ticks, TimeSpan::Zero);
}

DateTimeOffset::DateTimeOffset(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _dateTime = (DateTime)info->GetValue("DateTime", rt::typeof<DateTime>());
  _offsetMinutes = (Int16)info->GetValue("OffsetMinutes", rt::typeof<Int16>());
}

Int32 DateTimeOffset::GetHashCode() {
  return get_UtcDateTime().GetHashCode();
}

DateTimeOffset DateTimeOffset::Parse(String input) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::Parse(input, DateTimeFormatInfo::in::get_CurrentInfo(), DateTimeStyles::None, offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::Parse(String input, IFormatProvider formatProvider) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  return Parse(input, formatProvider, DateTimeStyles::None);
}

DateTimeOffset DateTimeOffset::Parse(String input, IFormatProvider formatProvider, DateTimeStyles styles) {
  styles = ValidateStyles(styles, "styles");
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::Parse(input, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, DateTimeStyles styles) {
  styles = ValidateStyles(styles, "styles");
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::Parse(input, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::ParseExact(String input, String format, IFormatProvider formatProvider) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  if (format == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::format);
  }
  return ParseExact(input, format, formatProvider, DateTimeStyles::None);
}

DateTimeOffset DateTimeOffset::ParseExact(String input, String format, IFormatProvider formatProvider, DateTimeStyles styles) {
  styles = ValidateStyles(styles, "styles");
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  if (format == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::format);
  }
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::ParseExact(input, format, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, DateTimeStyles styles) {
  styles = ValidateStyles(styles, "styles");
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::ParseExact(input, format, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::ParseExact(String input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles) {
  styles = ValidateStyles(styles, "styles");
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::ParseExactMultiple(input, formats, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, offset).get_Ticks(), offset);
}

DateTimeOffset DateTimeOffset::ParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles) {
  styles = ValidateStyles(styles, "styles");
  TimeSpan offset;
  return DateTimeOffset(DateTimeParse::ParseExactMultiple(input, formats, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, offset).get_Ticks(), offset);
}

TimeSpan DateTimeOffset::Subtract(DateTimeOffset value) {
  return get_UtcDateTime().Subtract(value.get_UtcDateTime());
}

DateTimeOffset DateTimeOffset::Subtract(TimeSpan value) {
  return DateTimeOffset(get_ClockDateTime().Subtract(value), get_Offset());
}

Int64 DateTimeOffset::ToFileTime() {
  return get_UtcDateTime().ToFileTime();
}

Int64 DateTimeOffset::ToUnixTimeSeconds() {
  Int64 num = get_UtcDateTime().get_Ticks() / 10000000;
  return num - 62135596800;
}

Int64 DateTimeOffset::ToUnixTimeMilliseconds() {
  Int64 num = get_UtcDateTime().get_Ticks() / 10000;
  return num - 62135596800000;
}

DateTimeOffset DateTimeOffset::ToLocalTime() {
  return ToLocalTime(false);
}

DateTimeOffset DateTimeOffset::ToLocalTime(Boolean throwOnOverflow) {
  return ToLocalTime(get_UtcDateTime(), throwOnOverflow);
}

DateTimeOffset DateTimeOffset::ToLocalTime(DateTime utcDateTime, Boolean throwOnOverflow) {
  TimeSpan localUtcOffset = TimeZoneInfo::in::GetLocalUtcOffset(utcDateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime);
  Int64 num = utcDateTime.get_Ticks() + localUtcOffset.get_Ticks();
  if (num < 0 || num > 3155378975999999999) {
    if (throwOnOverflow) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_ArgumentOutOfRangeException());
    }
    num = ((num < 0) ? 0 : 3155378975999999999);
  }
  return DateTimeOffset(num, localUtcOffset);
}

String DateTimeOffset::ToString() {
  return DateTimeFormat::Format(get_ClockDateTime(), nullptr, nullptr, get_Offset());
}

String DateTimeOffset::ToString(String format) {
  return DateTimeFormat::Format(get_ClockDateTime(), format, nullptr, get_Offset());
}

String DateTimeOffset::ToString(IFormatProvider formatProvider) {
  return DateTimeFormat::Format(get_ClockDateTime(), nullptr, formatProvider, get_Offset());
}

String DateTimeOffset::ToString(String format, IFormatProvider formatProvider) {
  return DateTimeFormat::Format(get_ClockDateTime(), format, formatProvider, get_Offset());
}

template <>
Boolean DateTimeOffset::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  return DateTimeFormat::TryFormat(get_ClockDateTime(), destination, charsWritten, format, formatProvider, get_Offset());
}

DateTimeOffset DateTimeOffset::ToUniversalTime() {
  return DateTimeOffset(get_UtcDateTime());
}

Boolean DateTimeOffset::TryParse(String input, DateTimeOffset& result) {
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParse(input, DateTimeFormatInfo::in::get_CurrentInfo(), DateTimeStyles::None, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParse(ReadOnlySpan<Char> input, DateTimeOffset& result) {
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParse(input, DateTimeFormatInfo::in::get_CurrentInfo(), DateTimeStyles::None, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParse(String input, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  styles = ValidateStyles(styles, "styles");
  if (input == nullptr) {
    result = DateTimeOffset();
    return false;
  }
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParse(input, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  styles = ValidateStyles(styles, "styles");
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParse(input, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParseExact(String input, String format, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  styles = ValidateStyles(styles, "styles");
  if (input == nullptr || format == nullptr) {
    result = DateTimeOffset();
    return false;
  }
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParseExact(input, format, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  styles = ValidateStyles(styles, "styles");
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParseExact(input, format, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  styles = ValidateStyles(styles, "styles");
  if (input == nullptr) {
    result = DateTimeOffset();
    return false;
  }
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParseExactMultiple(input, formats, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Boolean DateTimeOffset::TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result) {
  styles = ValidateStyles(styles, "styles");
  DateTime result2;
  TimeSpan offset;
  Boolean result3 = DateTimeParse::TryParseExactMultiple(input, formats, DateTimeFormatInfo::in::GetInstance(formatProvider), styles, result2, offset);
  result = DateTimeOffset(result2.get_Ticks(), offset);
  return result3;
}

Int16 DateTimeOffset::ValidateOffset(TimeSpan offset) {
  Int64 ticks = offset.get_Ticks();
  if (ticks % 600000000 != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_OffsetPrecision(), "offset");
  }
  if (ticks < -504000000000 || ticks > 504000000000) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_Argument_OffsetOutOfRange());
  }
  return (Int16)(offset.get_Ticks() / 600000000);
}

DateTime DateTimeOffset::ValidateDate(DateTime dateTime, TimeSpan offset) {
  Int64 num = dateTime.get_Ticks() - offset.get_Ticks();
  if (num < 0 || num > 3155378975999999999) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_Argument_UTCOutOfRange());
  }
  return DateTime(num, DateTimeKind::Unspecified);
}

DateTimeStyles DateTimeOffset::ValidateStyles(DateTimeStyles style, String parameterName) {
  if ((style & ~(DateTimeStyles::AllowLeadingWhite | DateTimeStyles::AllowTrailingWhite | DateTimeStyles::AllowInnerWhite | DateTimeStyles::NoCurrentDateDefault | DateTimeStyles::AdjustToUniversal | DateTimeStyles::AssumeLocal | DateTimeStyles::AssumeUniversal | DateTimeStyles::RoundtripKind)) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDateTimeStyles(), parameterName);
  }
  if ((style & DateTimeStyles::AssumeLocal) != 0 && (style & DateTimeStyles::AssumeUniversal) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ConflictingDateTimeStyles(), parameterName);
  }
  if ((style & DateTimeStyles::NoCurrentDateDefault) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeOffsetInvalidDateTimeStyles(), parameterName);
  }
  style &= ~DateTimeStyles::RoundtripKind;
  style &= ~DateTimeStyles::AssumeLocal;
  return style;
}

DateTimeOffset DateTimeOffset::op_Implicit(DateTime dateTime) {
  return DateTimeOffset(dateTime);
}

DateTimeOffset DateTimeOffset::op_Addition(DateTimeOffset dateTimeOffset, TimeSpan timeSpan) {
  return DateTimeOffset(dateTimeOffset.get_ClockDateTime() + timeSpan, dateTimeOffset.get_Offset());
}

DateTimeOffset DateTimeOffset::op_Subtraction(DateTimeOffset dateTimeOffset, TimeSpan timeSpan) {
  return DateTimeOffset(dateTimeOffset.get_ClockDateTime() - timeSpan, dateTimeOffset.get_Offset());
}

TimeSpan DateTimeOffset::op_Subtraction(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() - right.get_UtcDateTime();
}

Boolean DateTimeOffset::op_Equality(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() == right.get_UtcDateTime();
}

Boolean DateTimeOffset::op_Inequality(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() != right.get_UtcDateTime();
}

Boolean DateTimeOffset::op_LessThan(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() < right.get_UtcDateTime();
}

Boolean DateTimeOffset::op_LessThanOrEqual(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() <= right.get_UtcDateTime();
}

Boolean DateTimeOffset::op_GreaterThan(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() > right.get_UtcDateTime();
}

Boolean DateTimeOffset::op_GreaterThanOrEqual(DateTimeOffset left, DateTimeOffset right) {
  return left.get_UtcDateTime() >= right.get_UtcDateTime();
}

void DateTimeOffset::cctor() {
  MinValue = DateTimeOffset(0, TimeSpan::Zero);
  MaxValue = DateTimeOffset(3155378975999999999, TimeSpan::Zero);
  UnixEpoch = DateTimeOffset(621355968000000000, TimeSpan::Zero);
}

} // namespace System::Private::CoreLib::System::DateTimeOffsetNamespace
