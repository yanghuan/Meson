#include "DateTime-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Convert-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/DateTimeParse-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeStyles.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationInfoEnumerator-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfoOptions.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::DateTimeNamespace {
using namespace System::Globalization;
using namespace System::Runtime::Serialization;

DateTime::FullSystemTime::FullSystemTime(Int32 year, Int32 month, DayOfWeek dayOfWeek, Int32 day, Int32 hour, Int32 minute, Int32 second) {
  systemTime.Year = (UInt16)year;
  systemTime.Month = (UInt16)month;
  systemTime.DayOfWeek = (UInt16)dayOfWeek;
  systemTime.Day = (UInt16)day;
  systemTime.Hour = (UInt16)hour;
  systemTime.Minute = (UInt16)minute;
  systemTime.Second = (UInt16)second;
  systemTime.Milliseconds = 0;
  hundredNanoSecond = 0;
}

DateTime::FullSystemTime::FullSystemTime(Int64 ticks) {
  DateTime dateTime = DateTime(ticks);
}

Int64 DateTime::get_InternalTicks() {
}

UInt64 DateTime::get_InternalKind() {
}

DateTime DateTime::get_Date() {
  Int64 internalTicks = get_InternalTicks();
}

Int32 DateTime::get_Day() {
  return GetDatePart(3);
}

DayOfWeek DateTime::get_DayOfWeek() {
  return (DayOfWeek)((get_InternalTicks() / 864000000000 + 1) % 7);
}

Int32 DateTime::get_DayOfYear() {
  return GetDatePart(1);
}

Int32 DateTime::get_Hour() {
  return (Int32)(get_InternalTicks() / 36000000000 % 24);
}

DateTimeKind DateTime::get_Kind() {
  switch (get_InternalKind().get()) {
    case 0:
      return DateTimeKind::Unspecified;
    case 4611686018427387904:
      return DateTimeKind::Utc;
    default:
      return DateTimeKind::Local;
  }
}

Int32 DateTime::get_Millisecond() {
  return (Int32)(get_InternalTicks() / 10000 % 1000);
}

Int32 DateTime::get_Minute() {
  return (Int32)(get_InternalTicks() / 600000000 % 60);
}

Int32 DateTime::get_Month() {
  return GetDatePart(2);
}

DateTime DateTime::get_Now() {
  DateTime utcNow = get_UtcNow();
  Boolean isAmbiguousLocalDst;
  Int64 ticks = TimeZoneInfo::in::GetDateTimeNowUtcOffsetFromUtc(utcNow, isAmbiguousLocalDst).get_Ticks();
  Int64 num = utcNow.get_Ticks() + ticks;
  if (num > 3155378975999999999) {
    return DateTime(3155378975999999999, DateTimeKind::Local);
  }
  if (num < 0) {
    return DateTime(0, DateTimeKind::Local);
  }
  return DateTime(num, DateTimeKind::Local, isAmbiguousLocalDst);
}

Int32 DateTime::get_Second() {
  return (Int32)(get_InternalTicks() / 10000000 % 60);
}

Int64 DateTime::get_Ticks() {
  return get_InternalTicks();
}

TimeSpan DateTime::get_TimeOfDay() {
  return TimeSpan(get_InternalTicks() % 864000000000);
}

DateTime DateTime::get_Today() {
  return get_Now().get_Date();
}

Int32 DateTime::get_Year() {
  return GetDatePart(0);
}

DateTime DateTime::get_UtcNow() {
  if (s_systemSupportsLeapSeconds) {
    FullSystemTime time;
    GetSystemTimeWithLeapSecondsHandling(&time);
    return CreateDateTimeFromSystemTime(time);
  }
}

DateTime::DateTime(Int64 ticks) {
  if (ticks < 0 || ticks > 3155378975999999999) {
    rt::throw_exception<ArgumentOutOfRangeException>("ticks", SR::get_ArgumentOutOfRange_DateTimeBadTicks());
  }
  _dateData = (UInt64)ticks;
}

DateTime::DateTime(UInt64 dateData) {
  _dateData = dateData;
}

DateTime::DateTime(Int64 ticks, DateTimeKind kind) {
  if (ticks < 0 || ticks > 3155378975999999999) {
    rt::throw_exception<ArgumentOutOfRangeException>("ticks", SR::get_ArgumentOutOfRange_DateTimeBadTicks());
  }
  if (kind < DateTimeKind::Unspecified || kind > DateTimeKind::Local) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDateTimeKind(), "kind");
  }
}

DateTime::DateTime(Int64 ticks, DateTimeKind kind, Boolean isAmbiguousDst) {
  if (ticks < 0 || ticks > 3155378975999999999) {
    rt::throw_exception<ArgumentOutOfRangeException>("ticks", SR::get_ArgumentOutOfRange_DateTimeBadTicks());
  }
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day) {
  _dateData = (UInt64)DateToTicks(year, month, day);
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Calendar calendar) {
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second) {
  if (second == 60 && s_systemSupportsLeapSeconds && IsValidTimeWithLeapSeconds(year, month, day, hour, minute, second, DateTimeKind::Unspecified)) {
    second = 59;
  }
  _dateData = (UInt64)(DateToTicks(year, month, day) + TimeToTicks(hour, minute, second));
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateTimeKind kind) {
  if (kind < DateTimeKind::Unspecified || kind > DateTimeKind::Local) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDateTimeKind(), "kind");
  }
  if (second == 60 && s_systemSupportsLeapSeconds && IsValidTimeWithLeapSeconds(year, month, day, hour, minute, second, kind)) {
    second = 59;
  }
  Int64 num = DateToTicks(year, month, day) + TimeToTicks(hour, minute, second);
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Calendar calendar) {
  if (calendar == nullptr) {
    rt::throw_exception<ArgumentNullException>("calendar");
  }
  Int32 num = second;
  if (second == 60 && s_systemSupportsLeapSeconds) {
    second = 59;
  }
  _dateData = (UInt64)calendar->ToDateTime(year, month, day, hour, minute, second, 0).get_Ticks();
  if (num == 60) {
    DateTime dateTime = DateTime(_dateData);
    if (!IsValidTimeWithLeapSeconds(dateTime.get_Year(), dateTime.get_Month(), dateTime.get_Day(), dateTime.get_Hour(), dateTime.get_Minute(), 60, DateTimeKind::Unspecified)) {
      rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
    }
  }
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
  if (millisecond < 0 || millisecond >= 1000) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecond", SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
  }
  if (second == 60 && s_systemSupportsLeapSeconds && IsValidTimeWithLeapSeconds(year, month, day, hour, minute, second, DateTimeKind::Unspecified)) {
    second = 59;
  }
  Int64 num = DateToTicks(year, month, day) + TimeToTicks(hour, minute, second);
  num += (Int64)millisecond * 10000;
  if (num < 0 || num > 3155378975999999999) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DateTimeRange());
  }
  _dateData = (UInt64)num;
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, DateTimeKind kind) {
  if (millisecond < 0 || millisecond >= 1000) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecond", SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
  }
  if (kind < DateTimeKind::Unspecified || kind > DateTimeKind::Local) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDateTimeKind(), "kind");
  }
  if (second == 60 && s_systemSupportsLeapSeconds && IsValidTimeWithLeapSeconds(year, month, day, hour, minute, second, kind)) {
    second = 59;
  }
  Int64 num = DateToTicks(year, month, day) + TimeToTicks(hour, minute, second);
  num += (Int64)millisecond * 10000;
  if (num < 0 || num > 3155378975999999999) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DateTimeRange());
  }
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Calendar calendar) {
  if (calendar == nullptr) {
    rt::throw_exception<ArgumentNullException>("calendar");
  }
  if (millisecond < 0 || millisecond >= 1000) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecond", SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
  }
  Int32 num = second;
  if (second == 60 && s_systemSupportsLeapSeconds) {
    second = 59;
  }
  Int64 ticks = calendar->ToDateTime(year, month, day, hour, minute, second, 0).get_Ticks();
  ticks += (Int64)millisecond * 10000;
  if (ticks < 0 || ticks > 3155378975999999999) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DateTimeRange());
  }
  _dateData = (UInt64)ticks;
  if (num == 60) {
    DateTime dateTime = DateTime(_dateData);
    if (!IsValidTimeWithLeapSeconds(dateTime.get_Year(), dateTime.get_Month(), dateTime.get_Day(), dateTime.get_Hour(), dateTime.get_Minute(), 60, DateTimeKind::Unspecified)) {
      rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_BadHourMinuteSecond());
    }
  }
}

DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Calendar calendar, DateTimeKind kind) {
  if (calendar == nullptr) {
    rt::throw_exception<ArgumentNullException>("calendar");
  }
  if (millisecond < 0 || millisecond >= 1000) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecond", SR::Format(SR::get_ArgumentOutOfRange_Range(), 0, 999));
  }
  if (kind < DateTimeKind::Unspecified || kind > DateTimeKind::Local) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDateTimeKind(), "kind");
  }
  Int32 num = second;
  if (second == 60 && s_systemSupportsLeapSeconds) {
    second = 59;
  }
  Int64 ticks = calendar->ToDateTime(year, month, day, hour, minute, second, 0).get_Ticks();
  ticks += (Int64)millisecond * 10000;
  if (ticks < 0 || ticks > 3155378975999999999) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DateTimeRange());
  }
}

DateTime::DateTime(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  Boolean flag = false;
  Boolean flag2 = false;
  Int64 dateData = 0;
  UInt64 dateData2 = 0;
  SerializationInfoEnumerator enumerator = info->GetEnumerator();
  while (enumerator->MoveNext()) {
    String name = enumerator->get_Name();
    if (!(name == "ticks")) {
      if (name == "dateData") {
        dateData2 = Convert::ToUInt64(enumerator->get_Value(), CultureInfo::in::get_InvariantCulture());
        flag2 = true;
      }
    } else {
      dateData = Convert::ToInt64(enumerator->get_Value(), CultureInfo::in::get_InvariantCulture());
      flag = true;
    }
  }
  if (flag2) {
    _dateData = dateData2;
  } else {
    if (!flag) {
      rt::throw_exception<SerializationException>(SR::get_Serialization_MissingDateTimeData());
    }
    _dateData = (UInt64)dateData;
  }
  Int64 internalTicks = get_InternalTicks();
  if (internalTicks < 0 || internalTicks > 3155378975999999999) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_DateTimeTicksOutOfRange());
  }
}

DateTime DateTime::Add(TimeSpan value) {
  return AddTicks(value._ticks);
}

DateTime DateTime::Add(Double value, Int32 scale) {
  Double num = value * (Double)scale + ((value >= 0) ? 0.5 : (-0.5));
  if (num <= -315537897600000 || num >= 315537897600000) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_AddValue());
  }
  return AddTicks((Int64)num * 10000);
}

DateTime DateTime::AddDays(Double value) {
  return Add(value, 86400000);
}

DateTime DateTime::AddHours(Double value) {
  return Add(value, 3600000);
}

DateTime DateTime::AddMilliseconds(Double value) {
  return Add(value, 1);
}

DateTime DateTime::AddMinutes(Double value) {
  return Add(value, 60000);
}

DateTime DateTime::AddMonths(Int32 months) {
  if (months < -120000 || months > 120000) {
    rt::throw_exception<ArgumentOutOfRangeException>("months", SR::get_ArgumentOutOfRange_DateTimeBadMonths());
  }
}

DateTime DateTime::AddSeconds(Double value) {
  return Add(value, 1000);
}

DateTime DateTime::AddTicks(Int64 value) {
  Int64 internalTicks = get_InternalTicks();
}

Boolean DateTime::TryAddTicks(Int64 value, DateTime& result) {
  Int64 internalTicks = get_InternalTicks();
}

DateTime DateTime::AddYears(Int32 value) {
  if (value < -10000 || value > 10000) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_DateTimeBadYears());
  }
  return AddMonths(value * 12);
}

Int32 DateTime::Compare(DateTime t1, DateTime t2) {
  Int64 internalTicks = t1.get_InternalTicks();
  Int64 internalTicks2 = t2.get_InternalTicks();
  if (internalTicks > internalTicks2) {
    return 1;
  }
  if (internalTicks < internalTicks2) {
    return -1;
  }
  return 0;
}

Int32 DateTime::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (!rt::is<DateTime>(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDateTime());
  }
  return Compare(*this, (DateTime)value);
}

Int32 DateTime::CompareTo(DateTime value) {
  return Compare(*this, value);
}

Int64 DateTime::DateToTicks(Int32 year, Int32 month, Int32 day) {
  if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1) {
    ThrowHelper::ThrowArgumentOutOfRange_BadYearMonthDay();
  }
  Array<Int32> array = IsLeapYear(year) ? s_daysToMonth366 : s_daysToMonth365;
  if (day > array[month] - array[month - 1]) {
    ThrowHelper::ThrowArgumentOutOfRange_BadYearMonthDay();
  }
  Int32 num = year - 1;
  Int32 num2 = num * 365 + num / 4 - num / 100 + num / 400 + array[month - 1] + day - 1;
  return num2 * 864000000000;
}

Int64 DateTime::TimeToTicks(Int32 hour, Int32 minute, Int32 second) {
  if ((UInt32)hour >= 24u || (UInt32)minute >= 60u || (UInt32)second >= 60u) {
    ThrowHelper::ThrowArgumentOutOfRange_BadHourMinuteSecond();
  }
  return TimeSpan::TimeToTicks(hour, minute, second);
}

Int32 DateTime::DaysInMonth(Int32 year, Int32 month) {
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", SR::get_ArgumentOutOfRange_Month());
  }
  Array<Int32> array = IsLeapYear(year) ? s_daysToMonth366 : s_daysToMonth365;
  return array[month] - array[month - 1];
}

Int64 DateTime::DoubleDateToTicks(Double value) {
  if (!(value < 2958466) || !(value > -657435)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_OleAutDateInvalid());
  }
  Int64 num = (Int64)(value * 86400000 + ((value >= 0) ? 0.5 : (-0.5)));
  if (num < 0) {
    num -= num % 86400000 * 2;
  }
  num += 59926435200000;
  if (num < 0 || num >= 315537897600000) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_OleAutDateScale());
  }
  return num * 10000;
}

Boolean DateTime::Equals(Object value) {
  if (rt::is<DateTime>(value)) {
    return get_InternalTicks() == ((DateTime)value).get_InternalTicks();
  }
  return false;
}

Boolean DateTime::Equals(DateTime value) {
  return get_InternalTicks() == value.get_InternalTicks();
}

Boolean DateTime::Equals(DateTime t1, DateTime t2) {
  return t1.get_InternalTicks() == t2.get_InternalTicks();
}

DateTime DateTime::FromBinary(Int64 dateData) {
}

DateTime DateTime::FromBinaryRaw(Int64 dateData) {
}

DateTime DateTime::FromFileTime(Int64 fileTime) {
  return FromFileTimeUtc(fileTime).ToLocalTime();
}

DateTime DateTime::FromFileTimeUtc(Int64 fileTime) {
  if (fileTime < 0 || fileTime > 2650467743999999999) {
    rt::throw_exception<ArgumentOutOfRangeException>("fileTime", SR::get_ArgumentOutOfRange_FileTimeInvalid());
  }
  if (s_systemSupportsLeapSeconds) {
    return FromFileTimeLeapSecondsAware(fileTime);
  }
  Int64 ticks = fileTime + 504911232000000000;
  return DateTime(ticks, DateTimeKind::Utc);
}

DateTime DateTime::FromOADate(Double d) {
  return DateTime(DoubleDateToTicks(d), DateTimeKind::Unspecified);
}

Boolean DateTime::IsDaylightSavingTime() {
  if (get_Kind() == DateTimeKind::Utc) {
    return false;
  }
  return TimeZoneInfo::in::get_Local()->IsDaylightSavingTime(*this, TimeZoneInfoOptions::NoThrowOnInvalidTime);
}

DateTime DateTime::SpecifyKind(DateTime value, DateTimeKind kind) {
  return DateTime(value.get_InternalTicks(), kind);
}

Int64 DateTime::ToBinary() {
  if (get_Kind() == DateTimeKind::Local) {
    TimeSpan localUtcOffset = TimeZoneInfo::in::GetLocalUtcOffset(*this, TimeZoneInfoOptions::NoThrowOnInvalidTime);
    Int64 ticks = get_Ticks();
    Int64 num = ticks - localUtcOffset.get_Ticks();
    if (num < 0) {
      num = 4611686018427387904 + num;
    }
  }
  return (Int64)_dateData;
}

Int32 DateTime::GetDatePart(Int32 part) {
  Int64 internalTicks = get_InternalTicks();
  Int32 num = (Int32)(internalTicks / 864000000000);
  Int32 num2 = num / 146097;
  num -= num2 * 146097;
  Int32 num3 = num / 36524;
  if (num3 == 4) {
    num3 = 3;
  }
  num -= num3 * 36524;
  Int32 num4 = num / 1461;
  num -= num4 * 1461;
  Int32 num5 = num / 365;
  if (num5 == 4) {
    num5 = 3;
  }
  if (part == 0) {
    return num2 * 400 + num3 * 100 + num4 * 4 + num5 + 1;
  }
  num -= num5 * 365;
  if (part == 1) {
    return num + 1;
  }
  Array<Int32> array = (num5 == 3 && (num4 != 24 || num3 == 3)) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 i;
  for (i = (num >> 5) + 1; num >= array[i]; i++) {
  }
  if (part == 2) {
    return i;
  }
  return num - array[i - 1] + 1;
}

void DateTime::GetDate(Int32& year, Int32& month, Int32& day) {
  Int64 internalTicks = get_InternalTicks();
  Int32 num = (Int32)(internalTicks / 864000000000);
  Int32 num2 = num / 146097;
  num -= num2 * 146097;
  Int32 num3 = num / 36524;
  if (num3 == 4) {
    num3 = 3;
  }
  num -= num3 * 36524;
  Int32 num4 = num / 1461;
  num -= num4 * 1461;
  Int32 num5 = num / 365;
  if (num5 == 4) {
    num5 = 3;
  }
  year = num2 * 400 + num3 * 100 + num4 * 4 + num5 + 1;
  num -= num5 * 365;
  Array<Int32> array = (num5 == 3 && (num4 != 24 || num3 == 3)) ? s_daysToMonth366 : s_daysToMonth365;
  Int32 i;
  for (i = (num >> 5) + 1; num >= array[i]; i++) {
  }
  month = i;
  day = num - array[i - 1] + 1;
}

void DateTime::GetTime(Int32& hour, Int32& minute, Int32& second) {
  Int64 a = get_InternalTicks() / 10000000;
}

void DateTime::GetTime(Int32& hour, Int32& minute, Int32& second, Int32& millisecond) {
  Int64 a = get_InternalTicks() / 10000;
}

void DateTime::GetTimePrecise(Int32& hour, Int32& minute, Int32& second, Int32& tick) {
}

Int32 DateTime::GetHashCode() {
  Int64 internalTicks = get_InternalTicks();
}

Boolean DateTime::IsAmbiguousDaylightSavingTime() {
  return get_InternalKind() == 13835058055282163712;
}

Boolean DateTime::IsLeapYear(Int32 year) {
  if (year < 1 || year > 9999) {
    ThrowHelper::ThrowArgumentOutOfRange_Year();
  }
}

DateTime DateTime::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return DateTimeParse::Parse(s, DateTimeFormatInfo::in::get_CurrentInfo(), DateTimeStyles::None);
}

DateTime DateTime::Parse(String s, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return DateTimeParse::Parse(s, DateTimeFormatInfo::in::GetInstance(provider), DateTimeStyles::None);
}

DateTime DateTime::Parse(String s, IFormatProvider provider, DateTimeStyles styles) {
  DateTimeFormatInfo::in::ValidateStyles(styles, "styles");
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return DateTimeParse::Parse(s, DateTimeFormatInfo::in::GetInstance(provider), styles);
}

DateTime DateTime::Parse(ReadOnlySpan<Char> s, IFormatProvider provider, DateTimeStyles styles) {
  DateTimeFormatInfo::in::ValidateStyles(styles, "styles");
  return DateTimeParse::Parse(s, DateTimeFormatInfo::in::GetInstance(provider), styles);
}

DateTime DateTime::ParseExact(String s, String format, IFormatProvider provider) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if (format == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::format);
  }
  return DateTimeParse::ParseExact(s, format, DateTimeFormatInfo::in::GetInstance(provider), DateTimeStyles::None);
}

DateTime DateTime::ParseExact(String s, String format, IFormatProvider provider, DateTimeStyles style) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  if (format == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::format);
  }
  return DateTimeParse::ParseExact(s, format, DateTimeFormatInfo::in::GetInstance(provider), style);
}

DateTime DateTime::ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, IFormatProvider provider, DateTimeStyles style) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  return DateTimeParse::ParseExact(s, format, DateTimeFormatInfo::in::GetInstance(provider), style);
}

DateTime DateTime::ParseExact(String s, Array<String> formats, IFormatProvider provider, DateTimeStyles style) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::s);
  }
  return DateTimeParse::ParseExactMultiple(s, formats, DateTimeFormatInfo::in::GetInstance(provider), style);
}

DateTime DateTime::ParseExact(ReadOnlySpan<Char> s, Array<String> formats, IFormatProvider provider, DateTimeStyles style) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  return DateTimeParse::ParseExactMultiple(s, formats, DateTimeFormatInfo::in::GetInstance(provider), style);
}

TimeSpan DateTime::Subtract(DateTime value) {
  return TimeSpan(get_InternalTicks() - value.get_InternalTicks());
}

DateTime DateTime::Subtract(TimeSpan value) {
  Int64 internalTicks = get_InternalTicks();
  Int64 ticks = value._ticks;
  if (internalTicks < ticks || internalTicks - 3155378975999999999 > ticks) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_DateArithmetic());
  }
}

Double DateTime::TicksToOADate(Int64 value) {
  if (value == 0) {
    return 0;
  }
  if (value < 864000000000) {
    value += 599264352000000000;
  }
  if (value < 31241376000000000) {
    rt::throw_exception<OverflowException>(SR::get_Arg_OleAutDateInvalid());
  }
  Int64 num = (value - 599264352000000000) / 10000;
  if (num < 0) {
    Int64 num2 = num % 86400000;
    if (num2 != 0) {
      num -= (86400000 + num2) * 2;
    }
  }
  return (Double)num / 86400000;
}

Double DateTime::ToOADate() {
  return TicksToOADate(get_InternalTicks());
}

Int64 DateTime::ToFileTime() {
  return ToUniversalTime().ToFileTimeUtc();
}

Int64 DateTime::ToFileTimeUtc() {
}

DateTime DateTime::ToLocalTime() {
  return ToLocalTime(false);
}

DateTime DateTime::ToLocalTime(Boolean throwOnOverflow) {
  if (get_Kind() == DateTimeKind::Local) {
    return *this;
  }
  Boolean isDaylightSavings;
  Boolean isAmbiguousLocalDst;
  Int64 ticks = TimeZoneInfo::in::GetUtcOffsetFromUtc(*this, TimeZoneInfo::in::get_Local(), isDaylightSavings, isAmbiguousLocalDst).get_Ticks();
  Int64 num = get_Ticks() + ticks;
  if (num > 3155378975999999999) {
    if (throwOnOverflow) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_ArgumentOutOfRangeException());
    }
    return DateTime(3155378975999999999, DateTimeKind::Local);
  }
  if (num < 0) {
    if (throwOnOverflow) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_ArgumentOutOfRangeException());
    }
    return DateTime(0, DateTimeKind::Local);
  }
  return DateTime(num, DateTimeKind::Local, isAmbiguousLocalDst);
}

String DateTime::ToLongDateString() {
  return DateTimeFormat::Format(*this, "D", nullptr);
}

String DateTime::ToLongTimeString() {
  return DateTimeFormat::Format(*this, "T", nullptr);
}

String DateTime::ToShortDateString() {
  return DateTimeFormat::Format(*this, "d", nullptr);
}

String DateTime::ToShortTimeString() {
  return DateTimeFormat::Format(*this, "t", nullptr);
}

String DateTime::ToString() {
  return DateTimeFormat::Format(*this, nullptr, nullptr);
}

String DateTime::ToString(String format) {
  return DateTimeFormat::Format(*this, format, nullptr);
}

String DateTime::ToString(IFormatProvider provider) {
  return DateTimeFormat::Format(*this, nullptr, provider);
}

String DateTime::ToString(String format, IFormatProvider provider) {
  return DateTimeFormat::Format(*this, format, provider);
}

Boolean DateTime::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return DateTimeFormat::TryFormat(*this, destination, charsWritten, format, provider);
}

DateTime DateTime::ToUniversalTime() {
  return TimeZoneInfo::in::ConvertTimeToUtc(*this, TimeZoneInfoOptions::NoThrowOnInvalidTime);
}

Boolean DateTime::TryParse(String s, DateTime& result) {
  if (s == nullptr) {
    result = DateTime();
    return false;
  }
  return DateTimeParse::TryParse(s, DateTimeFormatInfo::in::get_CurrentInfo(), DateTimeStyles::None, result);
}

Boolean DateTime::TryParse(ReadOnlySpan<Char> s, DateTime& result) {
  return DateTimeParse::TryParse(s, DateTimeFormatInfo::in::get_CurrentInfo(), DateTimeStyles::None, result);
}

Boolean DateTime::TryParse(String s, IFormatProvider provider, DateTimeStyles styles, DateTime& result) {
  DateTimeFormatInfo::in::ValidateStyles(styles, "styles");
  if (s == nullptr) {
    result = DateTime();
    return false;
  }
  return DateTimeParse::TryParse(s, DateTimeFormatInfo::in::GetInstance(provider), styles, result);
}

Boolean DateTime::TryParse(ReadOnlySpan<Char> s, IFormatProvider provider, DateTimeStyles styles, DateTime& result) {
  DateTimeFormatInfo::in::ValidateStyles(styles, "styles");
  return DateTimeParse::TryParse(s, DateTimeFormatInfo::in::GetInstance(provider), styles, result);
}

Boolean DateTime::TryParseExact(String s, String format, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  if (s == nullptr || format == nullptr) {
    result = DateTime();
    return false;
  }
  return DateTimeParse::TryParseExact(s, format, DateTimeFormatInfo::in::GetInstance(provider), style, result);
}

Boolean DateTime::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  return DateTimeParse::TryParseExact(s, format, DateTimeFormatInfo::in::GetInstance(provider), style, result);
}

Boolean DateTime::TryParseExact(String s, Array<String> formats, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  if (s == nullptr) {
    result = DateTime();
    return false;
  }
  return DateTimeParse::TryParseExactMultiple(s, formats, DateTimeFormatInfo::in::GetInstance(provider), style, result);
}

Boolean DateTime::TryParseExact(ReadOnlySpan<Char> s, Array<String> formats, IFormatProvider provider, DateTimeStyles style, DateTime& result) {
  DateTimeFormatInfo::in::ValidateStyles(style, "style");
  return DateTimeParse::TryParseExactMultiple(s, formats, DateTimeFormatInfo::in::GetInstance(provider), style, result);
}

DateTime DateTime::op_Addition(DateTime d, TimeSpan t) {
  Int64 internalTicks = d.get_InternalTicks();
  Int64 ticks = t._ticks;
}

DateTime DateTime::op_Subtraction(DateTime d, TimeSpan t) {
  Int64 internalTicks = d.get_InternalTicks();
  Int64 ticks = t._ticks;
  if (internalTicks < ticks || internalTicks - 3155378975999999999 > ticks) {
    rt::throw_exception<ArgumentOutOfRangeException>("t", SR::get_ArgumentOutOfRange_DateArithmetic());
  }
}

TimeSpan DateTime::op_Subtraction(DateTime d1, DateTime d2) {
  return TimeSpan(d1.get_InternalTicks() - d2.get_InternalTicks());
}

Boolean DateTime::op_Equality(DateTime d1, DateTime d2) {
  return d1.get_InternalTicks() == d2.get_InternalTicks();
}

Boolean DateTime::op_Inequality(DateTime d1, DateTime d2) {
  return d1.get_InternalTicks() != d2.get_InternalTicks();
}

Boolean DateTime::op_LessThan(DateTime t1, DateTime t2) {
  return t1.get_InternalTicks() < t2.get_InternalTicks();
}

Boolean DateTime::op_LessThanOrEqual(DateTime t1, DateTime t2) {
  return t1.get_InternalTicks() <= t2.get_InternalTicks();
}

Boolean DateTime::op_GreaterThan(DateTime t1, DateTime t2) {
  return t1.get_InternalTicks() > t2.get_InternalTicks();
}

Boolean DateTime::op_GreaterThanOrEqual(DateTime t1, DateTime t2) {
  return t1.get_InternalTicks() >= t2.get_InternalTicks();
}

Array<String> DateTime::GetDateTimeFormats() {
  return GetDateTimeFormats(CultureInfo::in::get_CurrentCulture());
}

Array<String> DateTime::GetDateTimeFormats(IFormatProvider provider) {
  return DateTimeFormat::GetAllDateTimes(*this, DateTimeFormatInfo::in::GetInstance(provider));
}

Array<String> DateTime::GetDateTimeFormats(Char format) {
  return GetDateTimeFormats(format, CultureInfo::in::get_CurrentCulture());
}

Array<String> DateTime::GetDateTimeFormats(Char format, IFormatProvider provider) {
  return DateTimeFormat::GetAllDateTimes(*this, format, DateTimeFormatInfo::in::GetInstance(provider));
}

TypeCode DateTime::GetTypeCode() {
  return TypeCode::DateTime;
}

Boolean DateTime::TryCreate(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, DateTime& result) {
  result = MinValue;
  if (year < 1 || year > 9999 || month < 1 || month > 12) {
    return false;
  }
  Array<Int32> array = IsLeapYear(year) ? s_daysToMonth366 : s_daysToMonth365;
  if (day < 1 || day > array[month] - array[month - 1]) {
    return false;
  }
  if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second > 60) {
    return false;
  }
  if (millisecond < 0 || millisecond >= 1000) {
    return false;
  }
  if (second == 60) {
    if (!s_systemSupportsLeapSeconds || !IsValidTimeWithLeapSeconds(year, month, day, hour, minute, second, DateTimeKind::Unspecified)) {
      return false;
    }
    second = 59;
  }
  Int64 num = DateToTicks(year, month, day) + TimeToTicks(hour, minute, second);
  num += (Int64)millisecond * 10000;
  if (num < 0 || num > 3155378975999999999) {
    return false;
  }
  result = DateTime(num, DateTimeKind::Unspecified);
  return true;
}

Boolean DateTime::SystemSupportsLeapSeconds() {
  Interop::NtDll::SYSTEM_LEAP_SECOND_INFORMATION sYSTEM_LEAP_SECOND_INFORMATION;
  if (Interop::NtDll::NtQuerySystemInformation(206, &sYSTEM_LEAP_SECOND_INFORMATION, (UInt32)sizeof(Interop::NtDll::SYSTEM_LEAP_SECOND_INFORMATION), nullptr) == 0) {
    return sYSTEM_LEAP_SECOND_INFORMATION.Enabled != Interop::BOOLEAN::FALSE;
  }
  return false;
}

Boolean DateTime::IsValidTimeWithLeapSeconds(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateTimeKind kind) {
  FullSystemTime fullSystemTime = FullSystemTime(year, month, DateTime(year, month, day).get_DayOfWeek(), day, hour, minute, second);
  switch (kind) {
    case DateTimeKind::Local:
      return ValidateSystemTime(&fullSystemTime.systemTime, true);
    case DateTimeKind::Utc:
      return ValidateSystemTime(&fullSystemTime.systemTime, false);
    default:
      return ValidateSystemTime(&fullSystemTime.systemTime, true) || ValidateSystemTime(&fullSystemTime.systemTime, false);
  }
}

DateTime DateTime::FromFileTimeLeapSecondsAware(Int64 fileTime) {
  FullSystemTime time;
  if (FileTimeToSystemTime(fileTime, &time)) {
    return CreateDateTimeFromSystemTime(time);
  }
  rt::throw_exception<ArgumentOutOfRangeException>("fileTime", SR::get_ArgumentOutOfRange_DateTimeBadTicks());
}

Int64 DateTime::ToFileTimeLeapSecondsAware(Int64 ticks) {
  FullSystemTime fullSystemTime = FullSystemTime(ticks);
  Int64 num;
  if (SystemTimeToFileTime(&fullSystemTime.systemTime, &num)) {
    return num + ticks % 10000;
  }
  rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_ArgumentOutOfRange_FileTimeInvalid());
}

DateTime DateTime::CreateDateTimeFromSystemTime(FullSystemTime& time) {
  Int64 num = DateToTicks(time.systemTime.Year, time.systemTime.Month, time.systemTime.Day);
  num += TimeToTicks(time.systemTime.Hour, time.systemTime.Minute, time.systemTime.Second);
  num += (Int64)time.systemTime.Milliseconds * 10000;
  num += time.hundredNanoSecond;
}

void DateTime::cctor() {
  s_daysToMonth365 = rt::newarr<Array<Int32>>(13);
  s_daysToMonth366 = rt::newarr<Array<Int32>>(13);
  MinValue = DateTime(0, DateTimeKind::Unspecified);
  MaxValue = DateTime(3155378975999999999, DateTimeKind::Unspecified);
  UnixEpoch = DateTime(621355968000000000, DateTimeKind::Utc);
  s_systemSupportsLeapSeconds = SystemSupportsLeapSeconds();
}

} // namespace System::Private::CoreLib::System::DateTimeNamespace
