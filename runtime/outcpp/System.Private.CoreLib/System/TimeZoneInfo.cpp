#include "TimeZoneInfo-dep.h"

#include <System.Private.CoreLib/Internal/Win32/Registry-dep.h>
#include <System.Private.CoreLib/Internal/Win32/RegistryKey-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/EntryPointNotFoundException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeStyles.h>
#include <System.Private.CoreLib/System/Globalization/DaylightTimeStruct-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberStyles.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/InvalidTimeZoneException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/Nullable-dep.h>
#include <System.Private.CoreLib/System/Runtime/Serialization/SerializationException-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfoOptions.h>
#include <System.Private.CoreLib/System/TimeZoneNotFoundException-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::TimeZoneInfoNamespace {
using namespace Internal::Win32;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::IO;
using namespace System::Runtime::Serialization;
using namespace System::Text;

DateTime TimeZoneInfo___::TransitionTime::get_TimeOfDay() {
  return _timeOfDay;
}

Int32 TimeZoneInfo___::TransitionTime::get_Month() {
  return _month;
}

Int32 TimeZoneInfo___::TransitionTime::get_Week() {
  return _week;
}

Int32 TimeZoneInfo___::TransitionTime::get_Day() {
  return _day;
}

DayOfWeek TimeZoneInfo___::TransitionTime::get_DayOfWeek() {
  return _dayOfWeek;
}

Boolean TimeZoneInfo___::TransitionTime::get_IsFixedDateRule() {
  return _isFixedDateRule;
}

Boolean TimeZoneInfo___::TransitionTime::Equals(Object obj) {
  if (rt::is<TransitionTime>(obj)) {
    return Equals((TransitionTime)obj);
  }
  return false;
}

Boolean TimeZoneInfo___::TransitionTime::op_Equality(TransitionTime t1, TransitionTime t2) {
  return t1.Equals(t2);
}

Boolean TimeZoneInfo___::TransitionTime::op_Inequality(TransitionTime t1, TransitionTime t2) {
  return !t1.Equals(t2);
}

Boolean TimeZoneInfo___::TransitionTime::Equals(TransitionTime other) {
  if (_isFixedDateRule == other._isFixedDateRule && _timeOfDay == other._timeOfDay && _month == other._month) {
    if (!other._isFixedDateRule) {
      if (_week == other._week) {
        return _dayOfWeek == other._dayOfWeek;
      }
      return false;
    }
    return _day == other._day;
  }
  return false;
}

Int32 TimeZoneInfo___::TransitionTime::GetHashCode() {
  return _month ^ (_week << 8);
}

TimeZoneInfo___::TransitionTime::TransitionTime(DateTime timeOfDay, Int32 month, Int32 week, Int32 day, DayOfWeek dayOfWeek, Boolean isFixedDateRule) {
  ValidateTransitionTime(timeOfDay, month, week, day, dayOfWeek);
  _timeOfDay = timeOfDay;
  _month = (Byte)month;
  _week = (Byte)week;
  _day = (Byte)day;
  _dayOfWeek = dayOfWeek;
  _isFixedDateRule = isFixedDateRule;
}

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::TransitionTime::CreateFixedDateRule(DateTime timeOfDay, Int32 month, Int32 day) {
  return TransitionTime(timeOfDay, month, 1, day, DayOfWeek::Sunday, true);
}

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::TransitionTime::CreateFloatingDateRule(DateTime timeOfDay, Int32 month, Int32 week, DayOfWeek dayOfWeek) {
  return TransitionTime(timeOfDay, month, week, 1, dayOfWeek, false);
}

void TimeZoneInfo___::TransitionTime::ValidateTransitionTime(DateTime timeOfDay, Int32 month, Int32 week, Int32 day, DayOfWeek dayOfWeek) {
  if (timeOfDay.get_Kind() != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeKindMustBeUnspecified(), "timeOfDay");
  }
  if (month < 1 || month > 12) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", SR::get_ArgumentOutOfRange_MonthParam());
  }
  if (day < 1 || day > 31) {
    rt::throw_exception<ArgumentOutOfRangeException>("day", SR::get_ArgumentOutOfRange_DayParam());
  }
  if (week < 1 || week > 5) {
    rt::throw_exception<ArgumentOutOfRangeException>("week", SR::get_ArgumentOutOfRange_Week());
  }
  if (dayOfWeek < DayOfWeek::Sunday || dayOfWeek > DayOfWeek::Saturday) {
    rt::throw_exception<ArgumentOutOfRangeException>("dayOfWeek", SR::get_ArgumentOutOfRange_DayOfWeek());
  }
  Int32 year;
  Int32 month2;
  Int32 day2;
  timeOfDay.GetDate(year, month2, day2);
  if (year != 1 || month2 != 1 || day2 != 1 || timeOfDay.get_Ticks() % 10000 != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeHasTicks(), "timeOfDay");
  }
}

void TimeZoneInfo___::TransitionTime::OnDeserializationOfIDeserializationCallback(Object sender) {
  if (*this != rt::default__) {
    try {
      ValidateTransitionTime(_timeOfDay, _month, _week, _day, _dayOfWeek);
    } catch (ArgumentException innerException) {
      rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
    }
  }
}

void TimeZoneInfo___::TransitionTime::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("TimeOfDay", _timeOfDay);
  info->AddValue("Month", _month);
  info->AddValue("Week", _week);
  info->AddValue("Day", _day);
  info->AddValue("DayOfWeek", _dayOfWeek);
  info->AddValue("IsFixedDateRule", _isFixedDateRule);
}

TimeZoneInfo___::TransitionTime::TransitionTime(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _timeOfDay = (DateTime)info->GetValue("TimeOfDay", typeof<DateTime>());
  _month = (Byte)info->GetValue("Month", typeof<Byte>());
  _week = (Byte)info->GetValue("Week", typeof<Byte>());
  _day = (Byte)info->GetValue("Day", typeof<Byte>());
  _dayOfWeek = (DayOfWeek)info->GetValue("DayOfWeek", typeof<DayOfWeek>());
  _isFixedDateRule = (Boolean)info->GetValue("IsFixedDateRule", typeof<Boolean>());
}

DateTime TimeZoneInfo___::AdjustmentRule___::get_DateStart() {
  return _dateStart;
}

DateTime TimeZoneInfo___::AdjustmentRule___::get_DateEnd() {
  return _dateEnd;
}

TimeSpan TimeZoneInfo___::AdjustmentRule___::get_DaylightDelta() {
  return _daylightDelta;
}

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::AdjustmentRule___::get_DaylightTransitionStart() {
  return _daylightTransitionStart;
}

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::AdjustmentRule___::get_DaylightTransitionEnd() {
  return _daylightTransitionEnd;
}

TimeSpan TimeZoneInfo___::AdjustmentRule___::get_BaseUtcOffsetDelta() {
  return _baseUtcOffsetDelta;
}

Boolean TimeZoneInfo___::AdjustmentRule___::get_NoDaylightTransitions() {
  return _noDaylightTransitions;
}

Boolean TimeZoneInfo___::AdjustmentRule___::get_HasDaylightSaving() {
  if (!(get_DaylightDelta() != TimeSpan::Zero) && (!(get_DaylightTransitionStart() != rt::default__) || !(get_DaylightTransitionStart().get_TimeOfDay() != DateTime::MinValue))) {
    if (get_DaylightTransitionEnd() != rt::default__) {
      return get_DaylightTransitionEnd().get_TimeOfDay() != DateTime::MinValue.AddMilliseconds(1);
    }
    return false;
  }
  return true;
}

Boolean TimeZoneInfo___::AdjustmentRule___::Equals(AdjustmentRule other) {
  if (other != nullptr && _dateStart == other->_dateStart && _dateEnd == other->_dateEnd && _daylightDelta == other->_daylightDelta && _baseUtcOffsetDelta == other->_baseUtcOffsetDelta && _daylightTransitionEnd.Equals(other->_daylightTransitionEnd)) {
    return _daylightTransitionStart.Equals(other->_daylightTransitionStart);
  }
  return false;
}

Int32 TimeZoneInfo___::AdjustmentRule___::GetHashCode() {
  return _dateStart.GetHashCode();
}

void TimeZoneInfo___::AdjustmentRule___::ctor(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, TimeSpan baseUtcOffsetDelta, Boolean noDaylightTransitions) {
  ValidateAdjustmentRule(dateStart, dateEnd, daylightDelta, daylightTransitionStart, daylightTransitionEnd, noDaylightTransitions);
  _dateStart = dateStart;
  _dateEnd = dateEnd;
  _daylightDelta = daylightDelta;
  _daylightTransitionStart = daylightTransitionStart;
  _daylightTransitionEnd = daylightTransitionEnd;
  _baseUtcOffsetDelta = baseUtcOffsetDelta;
  _noDaylightTransitions = noDaylightTransitions;
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::AdjustmentRule___::CreateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd) {
  return rt::newobj<AdjustmentRule>(dateStart, dateEnd, daylightDelta, daylightTransitionStart, daylightTransitionEnd, TimeSpan::Zero, false);
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::AdjustmentRule___::CreateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, TimeSpan baseUtcOffsetDelta, Boolean noDaylightTransitions) {
  AdjustDaylightDeltaToExpectedRange(daylightDelta, baseUtcOffsetDelta);
  return rt::newobj<AdjustmentRule>(dateStart, dateEnd, daylightDelta, daylightTransitionStart, daylightTransitionEnd, baseUtcOffsetDelta, noDaylightTransitions);
}

Boolean TimeZoneInfo___::AdjustmentRule___::IsStartDateMarkerForBeginningOfYear() {
  if (!get_NoDaylightTransitions() && get_DaylightTransitionStart().get_Month() == 1 && get_DaylightTransitionStart().get_Day() == 1 && get_DaylightTransitionStart().get_TimeOfDay().get_TimeOfDay().get_Ticks() < 10000000) {
    return _dateStart.get_Year() == _dateEnd.get_Year();
  }
  return false;
}

Boolean TimeZoneInfo___::AdjustmentRule___::IsEndDateMarkerForEndOfYear() {
  if (!get_NoDaylightTransitions() && get_DaylightTransitionEnd().get_Month() == 1 && get_DaylightTransitionEnd().get_Day() == 1 && get_DaylightTransitionEnd().get_TimeOfDay().get_TimeOfDay().get_Ticks() < 10000000) {
    return _dateStart.get_Year() == _dateEnd.get_Year();
  }
  return false;
}

void TimeZoneInfo___::AdjustmentRule___::ValidateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, Boolean noDaylightTransitions) {
  if (dateStart.get_Kind() != 0 && dateStart.get_Kind() != DateTimeKind::Utc) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeKindMustBeUnspecifiedOrUtc(), "dateStart");
  }
  if (dateEnd.get_Kind() != 0 && dateEnd.get_Kind() != DateTimeKind::Utc) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeKindMustBeUnspecifiedOrUtc(), "dateEnd");
  }
  if (daylightTransitionStart.Equals(daylightTransitionEnd) && !noDaylightTransitions) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TransitionTimesAreIdentical(), "daylightTransitionEnd");
  }
  if (dateStart > dateEnd) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_OutOfOrderDateTimes(), "dateStart");
  }
  if (daylightDelta.get_TotalHours() < -23 || daylightDelta.get_TotalHours() > 14) {
    rt::throw_exception<ArgumentOutOfRangeException>("daylightDelta", daylightDelta, SR::get_ArgumentOutOfRange_UtcOffset());
  }
  if (daylightDelta.get_Ticks() % 600000000 != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TimeSpanHasSeconds(), "daylightDelta");
  }
  if (dateStart != DateTime::MinValue && dateStart.get_Kind() == DateTimeKind::Unspecified && dateStart.get_TimeOfDay() != TimeSpan::Zero) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeHasTimeOfDay(), "dateStart");
  }
  if (dateEnd != DateTime::MaxValue && dateEnd.get_Kind() == DateTimeKind::Unspecified && dateEnd.get_TimeOfDay() != TimeSpan::Zero) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeHasTimeOfDay(), "dateEnd");
  }
}

void TimeZoneInfo___::AdjustmentRule___::AdjustDaylightDeltaToExpectedRange(TimeSpan& daylightDelta, TimeSpan& baseUtcOffsetDelta) {
  if (daylightDelta > MaxDaylightDelta) {
    daylightDelta -= DaylightDeltaAdjustment;
    baseUtcOffsetDelta += DaylightDeltaAdjustment;
  } else if (daylightDelta < -MaxDaylightDelta) {
    daylightDelta += DaylightDeltaAdjustment;
    baseUtcOffsetDelta -= DaylightDeltaAdjustment;
  }

}

void TimeZoneInfo___::AdjustmentRule___::OnDeserializationOfIDeserializationCallback(Object sender) {
  try {
    ValidateAdjustmentRule(_dateStart, _dateEnd, _daylightDelta, _daylightTransitionStart, _daylightTransitionEnd, _noDaylightTransitions);
  } catch (ArgumentException innerException) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
  }
}

void TimeZoneInfo___::AdjustmentRule___::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("DateStart", _dateStart);
  info->AddValue("DateEnd", _dateEnd);
  info->AddValue("DaylightDelta", _daylightDelta);
  info->AddValue("DaylightTransitionStart", _daylightTransitionStart);
  info->AddValue("DaylightTransitionEnd", _daylightTransitionEnd);
  info->AddValue("BaseUtcOffsetDelta", _baseUtcOffsetDelta);
  info->AddValue("NoDaylightTransitions", _noDaylightTransitions);
}

void TimeZoneInfo___::AdjustmentRule___::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _dateStart = (DateTime)info->GetValue("DateStart", typeof<DateTime>());
  _dateEnd = (DateTime)info->GetValue("DateEnd", typeof<DateTime>());
  _daylightDelta = (TimeSpan)info->GetValue("DaylightDelta", typeof<TimeSpan>());
  _daylightTransitionStart = (TransitionTime)info->GetValue("DaylightTransitionStart", typeof<TransitionTime>());
  _daylightTransitionEnd = (TransitionTime)info->GetValue("DaylightTransitionEnd", typeof<TransitionTime>());
  Object valueNoThrow = info->GetValueNoThrow("BaseUtcOffsetDelta", typeof<TimeSpan>());
  if (valueNoThrow != nullptr) {
    _baseUtcOffsetDelta = (TimeSpan)valueNoThrow;
  }
  valueNoThrow = info->GetValueNoThrow("NoDaylightTransitions", typeof<Boolean>());
  if (valueNoThrow != nullptr) {
    _noDaylightTransitions = (Boolean)valueNoThrow;
  }
}

void TimeZoneInfo___::AdjustmentRule___::cctor() {
  DaylightDeltaAdjustment = TimeSpan::FromHours(24);
  MaxDaylightDelta = TimeSpan::FromHours(12);
}

void TimeZoneInfo___::OffsetAndRule___::ctor(Int32 year, TimeSpan offset, AdjustmentRule rule) {
  Year = year;
  Offset = offset;
  Rule = rule;
}

TimeZoneInfo TimeZoneInfo___::CachedData___::get_Local() {
  TimeZoneInfo as = _localTimeZone;
  return as != nullptr ? as : CreateLocal();
}

TimeZoneInfo TimeZoneInfo___::CachedData___::CreateLocal() {
  {
    rt::lock((CachedData)this);
    TimeZoneInfo timeZoneInfo = _localTimeZone;
    if (timeZoneInfo == nullptr) {
      timeZoneInfo = GetLocalTimeZone((CachedData)this);
      timeZoneInfo = (_localTimeZone = rt::newobj<TimeZoneInfo>(timeZoneInfo->_id, timeZoneInfo->_baseUtcOffset, timeZoneInfo->_displayName, timeZoneInfo->_standardDisplayName, timeZoneInfo->_daylightDisplayName, timeZoneInfo->_adjustmentRules, false));
    }
    return timeZoneInfo;
  }
}

DateTimeKind TimeZoneInfo___::CachedData___::GetCorrespondingKind(TimeZoneInfo timeZone) {
  if (timeZone != s_utcTimeZone) {
    if (timeZone != _localTimeZone) {
      return DateTimeKind::Unspecified;
    }
    return DateTimeKind::Local;
  }
  return DateTimeKind::Utc;
}

TimeZoneInfo TimeZoneInfo___::CachedData___::GetCurrentOneYearLocal() {
  Interop::Kernel32::TIME_ZONE_INFORMATION lpTimeZoneInformation;
  UInt32 timeZoneInformation = Interop::Kernel32::GetTimeZoneInformation(lpTimeZoneInformation);
  if (timeZoneInformation != UInt32::MaxValue()) {
    return GetLocalTimeZoneFromWin32Data(lpTimeZoneInformation, false);
  }
  return CreateCustomTimeZone("Local", TimeSpan::Zero, "Local", "Local");
}

TimeZoneInfo::in::OffsetAndRule TimeZoneInfo___::CachedData___::GetOneYearLocalFromUtc(Int32 year) {
  OffsetAndRule offsetAndRule = _oneYearLocalFromUtc;
  if (offsetAndRule == nullptr || offsetAndRule->Year != year) {
    TimeZoneInfo currentOneYearLocal = GetCurrentOneYearLocal();
    Array<AdjustmentRule> adjustmentRules = currentOneYearLocal->_adjustmentRules;
    AdjustmentRule rule = ((adjustmentRules != nullptr) ? adjustmentRules[0] : nullptr);
    offsetAndRule = (_oneYearLocalFromUtc = rt::newobj<OffsetAndRule>(year, currentOneYearLocal->get_BaseUtcOffset(), rule));
  }
  return offsetAndRule;
}

void TimeZoneInfo___::CachedData___::ctor() {
}

String TimeZoneInfo___::StringSerializer::GetSerializedString(TimeZoneInfo zone) {
  Char as[64] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder serializedText = ValueStringBuilder(initialBuffer);
  SerializeSubstitute(zone->get_Id(), serializedText);
  serializedText.Append(u';');
  serializedText.AppendSpanFormattable(zone->get_BaseUtcOffset().get_TotalMinutes(), nullptr, CultureInfo::in::get_InvariantCulture());
  serializedText.Append(u';');
  SerializeSubstitute(zone->get_DisplayName(), serializedText);
  serializedText.Append(u';');
  SerializeSubstitute(zone->get_StandardName(), serializedText);
  serializedText.Append(u';');
  SerializeSubstitute(zone->get_DaylightName(), serializedText);
  serializedText.Append(u';');
  Array<AdjustmentRule> adjustmentRules = zone->GetAdjustmentRules();
  Array<AdjustmentRule> array = adjustmentRules;
  for (AdjustmentRule&& adjustmentRule : *array) {
    serializedText.Append(u'[');
    serializedText.AppendSpanFormattable(adjustmentRule->get_DateStart(), "MM:dd:yyyy", DateTimeFormatInfo::in::get_InvariantInfo());
    serializedText.Append(u';');
    serializedText.AppendSpanFormattable(adjustmentRule->get_DateEnd(), "MM:dd:yyyy", DateTimeFormatInfo::in::get_InvariantInfo());
    serializedText.Append(u';');
    serializedText.AppendSpanFormattable(adjustmentRule->get_DaylightDelta().get_TotalMinutes(), nullptr, CultureInfo::in::get_InvariantCulture());
    serializedText.Append(u';');
    SerializeTransitionTime(adjustmentRule->get_DaylightTransitionStart(), serializedText);
    serializedText.Append(u';');
    SerializeTransitionTime(adjustmentRule->get_DaylightTransitionEnd(), serializedText);
    serializedText.Append(u';');
    if (adjustmentRule->get_BaseUtcOffsetDelta() != TimeSpan::Zero) {
      serializedText.AppendSpanFormattable(adjustmentRule->get_BaseUtcOffsetDelta().get_TotalMinutes(), nullptr, CultureInfo::in::get_InvariantCulture());
      serializedText.Append(u';');
    }
    if (adjustmentRule->get_NoDaylightTransitions()) {
      serializedText.Append(u'1');
      serializedText.Append(u';');
    }
    serializedText.Append(u']');
  }
  serializedText.Append(u';');
  return serializedText.ToString();
}

TimeZoneInfo TimeZoneInfo___::StringSerializer::GetDeserializedTimeZoneInfo(String source) {
  StringSerializer stringSerializer = StringSerializer(source);
  String nextStringValue = stringSerializer.GetNextStringValue();
  TimeSpan nextTimeSpanValue = stringSerializer.GetNextTimeSpanValue();
  String nextStringValue2 = stringSerializer.GetNextStringValue();
  String nextStringValue3 = stringSerializer.GetNextStringValue();
  String nextStringValue4 = stringSerializer.GetNextStringValue();
  Array<AdjustmentRule> nextAdjustmentRuleArrayValue = stringSerializer.GetNextAdjustmentRuleArrayValue();
  try {
    return rt::newobj<TimeZoneInfo>(nextStringValue, nextTimeSpanValue, nextStringValue2, nextStringValue3, nextStringValue4, nextAdjustmentRuleArrayValue, false);
  } catch (ArgumentException innerException) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
  } catch (InvalidTimeZoneException innerException2) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException2);
  }
}

TimeZoneInfo___::StringSerializer::StringSerializer(String str) {
  _serializedText = str;
  _currentTokenStartIndex = 0;
  _state = State::StartOfToken;
}

void TimeZoneInfo___::StringSerializer::SerializeSubstitute(String text, ValueStringBuilder& serializedText) {
  for (Char&& c : *text) {
    if (c == u'\\' || c == u'[' || c == u']' || c == u';') {
      serializedText.Append(u'\\');
    }
    serializedText.Append(c);
  }
}

void TimeZoneInfo___::StringSerializer::SerializeTransitionTime(TransitionTime time, ValueStringBuilder& serializedText) {
  serializedText.Append(u'[');
  serializedText.Append(time.get_IsFixedDateRule() ? u'1' : u'0');
  serializedText.Append(u';');
  serializedText.AppendSpanFormattable(time.get_TimeOfDay(), "HH:mm:ss.FFF", DateTimeFormatInfo::in::get_InvariantInfo());
  serializedText.Append(u';');
  serializedText.AppendSpanFormattable(time.get_Month(), nullptr, CultureInfo::in::get_InvariantCulture());
  serializedText.Append(u';');
  if (time.get_IsFixedDateRule()) {
    serializedText.AppendSpanFormattable(time.get_Day(), nullptr, CultureInfo::in::get_InvariantCulture());
    serializedText.Append(u';');
  } else {
    serializedText.AppendSpanFormattable(time.get_Week(), nullptr, CultureInfo::in::get_InvariantCulture());
    serializedText.Append(u';');
    serializedText.AppendSpanFormattable((Int32)time.get_DayOfWeek(), nullptr, CultureInfo::in::get_InvariantCulture());
    serializedText.Append(u';');
  }
  serializedText.Append(u']');
}

void TimeZoneInfo___::StringSerializer::VerifyIsEscapableCharacter(Char c) {
  if (c != u'\\' && c != u';' && c != u'[' && c != u']') {
    rt::throw_exception<SerializationException>(SR::Format(SR::get_Serialization_InvalidEscapeSequence(), c));
  }
}

void TimeZoneInfo___::StringSerializer::SkipVersionNextDataFields(Int32 depth) {
  if (_currentTokenStartIndex < 0 || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  State state = State::NotEscaped;
  for (Int32 i = _currentTokenStartIndex; i < _serializedText->get_Length(); i++) {
    switch (state) {
      case State::Escaped:
        VerifyIsEscapableCharacter(_serializedText[i]);
        state = State::NotEscaped;
        break;
      case State::NotEscaped:
        switch (_serializedText[i].get()) {
          case u'\\':
            state = State::Escaped;
            break;
          case u'[':
            depth++;
            break;
          case u']':
            depth--;
            if (depth == 0) {
              _currentTokenStartIndex = i + 1;
              if (_currentTokenStartIndex >= _serializedText->get_Length()) {
                _state = State::EndOfLine;
              } else {
                _state = State::StartOfToken;
              }
              return;
            }
            break;
          case u'\0':
            rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
        }
        break;
    }
  }
  rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
}

String TimeZoneInfo___::StringSerializer::GetNextStringValue() {
  if (_state == State::EndOfLine) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_currentTokenStartIndex < 0 || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  State state = State::NotEscaped;
  Char as[64] = {};
  Span<Char> initialBuffer = as;
  ValueStringBuilder valueStringBuilder = ValueStringBuilder(initialBuffer);
  for (Int32 i = _currentTokenStartIndex; i < _serializedText->get_Length(); i++) {
    switch (state) {
      case State::Escaped:
        VerifyIsEscapableCharacter(_serializedText[i]);
        valueStringBuilder.Append(_serializedText[i]);
        state = State::NotEscaped;
        break;
      case State::NotEscaped:
        switch (_serializedText[i].get()) {
          case u'\\':
            state = State::Escaped;
            break;
          case u'[':
            rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
          case u']':
            rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
          case u';':
            _currentTokenStartIndex = i + 1;
            if (_currentTokenStartIndex >= _serializedText->get_Length()) {
              _state = State::EndOfLine;
            } else {
              _state = State::StartOfToken;
            }
            return valueStringBuilder.ToString();
          case u'\0':
            rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
          default:
            valueStringBuilder.Append(_serializedText[i]);
            break;
        }
        break;
    }
  }
  if (state == State::Escaped) {
    rt::throw_exception<SerializationException>(SR::Format(SR::get_Serialization_InvalidEscapeSequence(), String::in::Empty));
  }
  rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
}

DateTime TimeZoneInfo___::StringSerializer::GetNextDateTimeValue(String format) {
  String nextStringValue = GetNextStringValue();
  DateTime result;
  if (!DateTime::TryParseExact(nextStringValue, format, DateTimeFormatInfo::in::get_InvariantInfo(), DateTimeStyles::None, result)) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  return result;
}

TimeSpan TimeZoneInfo___::StringSerializer::GetNextTimeSpanValue() {
  Int32 nextInt32Value = GetNextInt32Value();
  try {
    return TimeSpan(0, nextInt32Value, 0);
  } catch (ArgumentOutOfRangeException innerException) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
  }
}

Int32 TimeZoneInfo___::StringSerializer::GetNextInt32Value() {
  String nextStringValue = GetNextStringValue();
  Int32 result;
  if (!Int32::TryParse(nextStringValue, NumberStyles::AllowLeadingSign, CultureInfo::in::get_InvariantCulture(), result)) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  return result;
}

Array<TimeZoneInfo::in::AdjustmentRule> TimeZoneInfo___::StringSerializer::GetNextAdjustmentRuleArrayValue() {
  List<AdjustmentRule> list = rt::newobj<List<AdjustmentRule>>(1);
  Int32 num = 0;
  for (AdjustmentRule nextAdjustmentRuleValue = GetNextAdjustmentRuleValue(); nextAdjustmentRuleValue != nullptr; nextAdjustmentRuleValue = GetNextAdjustmentRuleValue()) {
    list->Add(nextAdjustmentRuleValue);
    num++;
  }
  if (_state == State::EndOfLine) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_currentTokenStartIndex < 0 || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (num == 0) {
    return nullptr;
  }
  return list->ToArray();
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::StringSerializer::GetNextAdjustmentRuleValue() {
  if (_state == State::EndOfLine) {
    return nullptr;
  }
  if (_currentTokenStartIndex < 0 || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_serializedText[_currentTokenStartIndex] == u';') {
    return nullptr;
  }
  if (_serializedText[_currentTokenStartIndex] != u'[') {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  _currentTokenStartIndex++;
  DateTime nextDateTimeValue = GetNextDateTimeValue("MM:dd:yyyy");
  DateTime nextDateTimeValue2 = GetNextDateTimeValue("MM:dd:yyyy");
  TimeSpan nextTimeSpanValue = GetNextTimeSpanValue();
  TransitionTime nextTransitionTimeValue = GetNextTransitionTimeValue();
  TransitionTime nextTransitionTimeValue2 = GetNextTransitionTimeValue();
  TimeSpan baseUtcOffsetDelta = TimeSpan::Zero;
  Int32 num = 0;
  if (_state == State::EndOfLine || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if ((_serializedText[_currentTokenStartIndex] >= u'0' && _serializedText[_currentTokenStartIndex] <= u'9') || _serializedText[_currentTokenStartIndex] == u'-' || _serializedText[_currentTokenStartIndex] == u'+') {
    baseUtcOffsetDelta = GetNextTimeSpanValue();
  }
  if (_serializedText[_currentTokenStartIndex] >= u'0' && _serializedText[_currentTokenStartIndex] <= u'1') {
    num = GetNextInt32Value();
  }
  if (_state == State::EndOfLine || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_serializedText[_currentTokenStartIndex] != u']') {
    SkipVersionNextDataFields(1);
  } else {
    _currentTokenStartIndex++;
  }
  AdjustmentRule result;
  try {
    result = AdjustmentRule::in::CreateAdjustmentRule(nextDateTimeValue, nextDateTimeValue2, nextTimeSpanValue, nextTransitionTimeValue, nextTransitionTimeValue2, baseUtcOffsetDelta, num > 0);
  } catch (ArgumentException innerException) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
  }
  if (_currentTokenStartIndex >= _serializedText->get_Length()) {
    _state = State::EndOfLine;
  } else {
    _state = State::StartOfToken;
  }
  return result;
}

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::StringSerializer::GetNextTransitionTimeValue() {
  if (_state == State::EndOfLine || (_currentTokenStartIndex < _serializedText->get_Length() && _serializedText[_currentTokenStartIndex] == u']')) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_currentTokenStartIndex < 0 || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_serializedText[_currentTokenStartIndex] != u'[') {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  _currentTokenStartIndex++;
  Int32 nextInt32Value = GetNextInt32Value();
  if (nextInt32Value != 0 && nextInt32Value != 1) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  DateTime nextDateTimeValue = GetNextDateTimeValue("HH:mm:ss.FFF");
  nextDateTimeValue = DateTime(1, 1, 1, nextDateTimeValue.get_Hour(), nextDateTimeValue.get_Minute(), nextDateTimeValue.get_Second(), nextDateTimeValue.get_Millisecond());
  Int32 nextInt32Value2 = GetNextInt32Value();
  TransitionTime result;
  if (nextInt32Value == 1) {
    Int32 nextInt32Value3 = GetNextInt32Value();
    try {
      result = TransitionTime::CreateFixedDateRule(nextDateTimeValue, nextInt32Value2, nextInt32Value3);
    } catch (ArgumentException innerException) {
      rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
    }
  } else {
    Int32 nextInt32Value4 = GetNextInt32Value();
    Int32 nextInt32Value5 = GetNextInt32Value();
    try {
      result = TransitionTime::CreateFloatingDateRule(nextDateTimeValue, nextInt32Value2, nextInt32Value4, (DayOfWeek)nextInt32Value5);
    } catch (ArgumentException innerException2) {
      rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException2);
    }
  }
  if (_state == State::EndOfLine || _currentTokenStartIndex >= _serializedText->get_Length()) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_serializedText[_currentTokenStartIndex] != u']') {
    SkipVersionNextDataFields(1);
  } else {
    _currentTokenStartIndex++;
  }
  Boolean flag = false;
  if (_currentTokenStartIndex < _serializedText->get_Length() && _serializedText[_currentTokenStartIndex] == u';') {
    _currentTokenStartIndex++;
    flag = true;
  }
  if (!flag) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData());
  }
  if (_currentTokenStartIndex >= _serializedText->get_Length()) {
    _state = State::EndOfLine;
  } else {
    _state = State::StartOfToken;
  }
  return result;
}

void TimeZoneInfo___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void TimeZoneInfo___::__c___::ctor() {
}

Int32 TimeZoneInfo___::__c___::_GetSystemTimeZones_b__62_0(TimeZoneInfo x, TimeZoneInfo y) {
  Int32 num = x->get_BaseUtcOffset().CompareTo(y->get_BaseUtcOffset());
  if (num != 0) {
    return num;
  }
  return String::in::CompareOrdinal(x->get_DisplayName(), y->get_DisplayName());
}

String TimeZoneInfo___::get_Id() {
  return _id;
}

String TimeZoneInfo___::get_DisplayName() {
  String as = _displayName;
  return as != nullptr ? as : String::in::Empty;
}

String TimeZoneInfo___::get_StandardName() {
  String as = _standardDisplayName;
  return as != nullptr ? as : String::in::Empty;
}

String TimeZoneInfo___::get_DaylightName() {
  String as = _daylightDisplayName;
  return as != nullptr ? as : String::in::Empty;
}

TimeSpan TimeZoneInfo___::get_BaseUtcOffset() {
  return _baseUtcOffset;
}

Boolean TimeZoneInfo___::get_SupportsDaylightSavingTime() {
  return _supportsDaylightSavingTime;
}

TimeZoneInfo TimeZoneInfo___::get_Local() {
  return s_cachedData->get_Local();
}

TimeZoneInfo TimeZoneInfo___::get_Utc() {
  return s_utcTimeZone;
}

Array<TimeSpan> TimeZoneInfo___::GetAmbiguousTimeOffsets(DateTimeOffset dateTimeOffset) {
  if (!get_SupportsDaylightSavingTime()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeOffsetIsNotAmbiguous(), "dateTimeOffset");
  }
  DateTime dateTime = ConvertTime(dateTimeOffset, (TimeZoneInfo)this).get_DateTime();
  Boolean flag = false;
  Nullable<Int32> ruleIndex;
  AdjustmentRule adjustmentRuleForAmbiguousOffsets = GetAdjustmentRuleForAmbiguousOffsets(dateTime, ruleIndex);
  if (adjustmentRuleForAmbiguousOffsets != nullptr && adjustmentRuleForAmbiguousOffsets->get_HasDaylightSaving()) {
    DaylightTimeStruct daylightTime = GetDaylightTime(dateTime.get_Year(), adjustmentRuleForAmbiguousOffsets, ruleIndex);
    flag = GetIsAmbiguousTime(dateTime, adjustmentRuleForAmbiguousOffsets, daylightTime);
  }
  if (!flag) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeOffsetIsNotAmbiguous(), "dateTimeOffset");
  }
  Array<TimeSpan> array = rt::newarr<Array<TimeSpan>>(2);
  TimeSpan timeSpan = _baseUtcOffset + adjustmentRuleForAmbiguousOffsets->get_BaseUtcOffsetDelta();
  if (adjustmentRuleForAmbiguousOffsets->get_DaylightDelta() > TimeSpan::Zero) {
    array[0] = timeSpan;
    array[1] = timeSpan + adjustmentRuleForAmbiguousOffsets->get_DaylightDelta();
  } else {
    array[0] = timeSpan + adjustmentRuleForAmbiguousOffsets->get_DaylightDelta();
    array[1] = timeSpan;
  }
  return array;
}

Array<TimeSpan> TimeZoneInfo___::GetAmbiguousTimeOffsets(DateTime dateTime) {
  if (!get_SupportsDaylightSavingTime()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeIsNotAmbiguous(), "dateTime");
  }
  DateTime dateTime2;
  if (dateTime.get_Kind() == DateTimeKind::Local) {
    CachedData cachedData = s_cachedData;
    dateTime2 = ConvertTime(dateTime, cachedData->get_Local(), (TimeZoneInfo)this, TimeZoneInfoOptions::None, cachedData);
  } else if (dateTime.get_Kind() == DateTimeKind::Utc) {
    CachedData cachedData2 = s_cachedData;
    dateTime2 = ConvertTime(dateTime, s_utcTimeZone, (TimeZoneInfo)this, TimeZoneInfoOptions::None, cachedData2);
  } else {
    dateTime2 = dateTime;
  }

  Boolean flag = false;
  Nullable<Int32> ruleIndex;
  AdjustmentRule adjustmentRuleForAmbiguousOffsets = GetAdjustmentRuleForAmbiguousOffsets(dateTime2, ruleIndex);
  if (adjustmentRuleForAmbiguousOffsets != nullptr && adjustmentRuleForAmbiguousOffsets->get_HasDaylightSaving()) {
    DaylightTimeStruct daylightTime = GetDaylightTime(dateTime2.get_Year(), adjustmentRuleForAmbiguousOffsets, ruleIndex);
    flag = GetIsAmbiguousTime(dateTime2, adjustmentRuleForAmbiguousOffsets, daylightTime);
  }
  if (!flag) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeIsNotAmbiguous(), "dateTime");
  }
  Array<TimeSpan> array = rt::newarr<Array<TimeSpan>>(2);
  TimeSpan timeSpan = _baseUtcOffset + adjustmentRuleForAmbiguousOffsets->get_BaseUtcOffsetDelta();
  if (adjustmentRuleForAmbiguousOffsets->get_DaylightDelta() > TimeSpan::Zero) {
    array[0] = timeSpan;
    array[1] = timeSpan + adjustmentRuleForAmbiguousOffsets->get_DaylightDelta();
  } else {
    array[0] = timeSpan + adjustmentRuleForAmbiguousOffsets->get_DaylightDelta();
    array[1] = timeSpan;
  }
  return array;
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetAdjustmentRuleForAmbiguousOffsets(DateTime adjustedTime, Nullable<Int32>& ruleIndex) {
  AdjustmentRule adjustmentRuleForTime = GetAdjustmentRuleForTime(adjustedTime, ruleIndex);
  if (adjustmentRuleForTime != nullptr && adjustmentRuleForTime->get_NoDaylightTransitions() && !adjustmentRuleForTime->get_HasDaylightSaving()) {
    return GetPreviousAdjustmentRule(adjustmentRuleForTime, ruleIndex);
  }
  return adjustmentRuleForTime;
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetPreviousAdjustmentRule(AdjustmentRule rule, Nullable<Int32> ruleIndex) {
  if (ruleIndex.get_HasValue() && 0 < ruleIndex.GetValueOrDefault() && ruleIndex.GetValueOrDefault() < _adjustmentRules->get_Length()) {
    return _adjustmentRules[ruleIndex.GetValueOrDefault() - 1];
  }
  AdjustmentRule result = rule;
  for (Int32 i = 1; i < _adjustmentRules->get_Length(); i++) {
    if (rule == _adjustmentRules[i]) {
      result = _adjustmentRules[i - 1];
      break;
    }
  }
  return result;
}

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTimeOffset dateTimeOffset) {
  return GetUtcOffsetFromUtc(dateTimeOffset.get_UtcDateTime(), (TimeZoneInfo)this);
}

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime dateTime) {
  return GetUtcOffset(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime, s_cachedData);
}

TimeSpan TimeZoneInfo___::GetLocalUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags) {
  CachedData cachedData = s_cachedData;
  return cachedData->get_Local()->GetUtcOffset(dateTime, flags, cachedData);
}

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags) {
  return GetUtcOffset(dateTime, flags, s_cachedData);
}

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags, CachedData cachedData) {
  if (dateTime.get_Kind() == DateTimeKind::Local) {
    if (cachedData->GetCorrespondingKind((TimeZoneInfo)this) != DateTimeKind::Local) {
      DateTime time = ConvertTime(dateTime, cachedData->get_Local(), s_utcTimeZone, flags);
      return GetUtcOffsetFromUtc(time, (TimeZoneInfo)this);
    }
  } else if (dateTime.get_Kind() == DateTimeKind::Utc) {
    if (cachedData->GetCorrespondingKind((TimeZoneInfo)this) == DateTimeKind::Utc) {
      return _baseUtcOffset;
    }
    return GetUtcOffsetFromUtc(dateTime, (TimeZoneInfo)this);
  }

  return GetUtcOffset(dateTime, (TimeZoneInfo)this);
}

Boolean TimeZoneInfo___::IsAmbiguousTime(DateTimeOffset dateTimeOffset) {
  if (!_supportsDaylightSavingTime) {
    return false;
  }
  return IsAmbiguousTime(ConvertTime(dateTimeOffset, (TimeZoneInfo)this).get_DateTime());
}

Boolean TimeZoneInfo___::IsAmbiguousTime(DateTime dateTime) {
  return IsAmbiguousTime(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime);
}

Boolean TimeZoneInfo___::IsAmbiguousTime(DateTime dateTime, TimeZoneInfoOptions flags) {
  if (!_supportsDaylightSavingTime) {
    return false;
  }
  CachedData cachedData = s_cachedData;
  DateTime dateTime2 = ((dateTime.get_Kind() == DateTimeKind::Local) ? ConvertTime(dateTime, cachedData->get_Local(), (TimeZoneInfo)this, flags, cachedData) : ((dateTime.get_Kind() == DateTimeKind::Utc) ? ConvertTime(dateTime, s_utcTimeZone, (TimeZoneInfo)this, flags, cachedData) : dateTime));
  Nullable<Int32> ruleIndex;
  AdjustmentRule adjustmentRuleForTime = GetAdjustmentRuleForTime(dateTime2, ruleIndex);
  if (adjustmentRuleForTime != nullptr && adjustmentRuleForTime->get_HasDaylightSaving()) {
    DaylightTimeStruct daylightTime = GetDaylightTime(dateTime2.get_Year(), adjustmentRuleForTime, ruleIndex);
    return GetIsAmbiguousTime(dateTime2, adjustmentRuleForTime, daylightTime);
  }
  return false;
}

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTimeOffset dateTimeOffset) {
  Boolean isDaylightSavings;
  GetUtcOffsetFromUtc(dateTimeOffset.get_UtcDateTime(), (TimeZoneInfo)this, isDaylightSavings);
  return isDaylightSavings;
}

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTime dateTime) {
  return IsDaylightSavingTime(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime, s_cachedData);
}

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTime dateTime, TimeZoneInfoOptions flags) {
  return IsDaylightSavingTime(dateTime, flags, s_cachedData);
}

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTime dateTime, TimeZoneInfoOptions flags, CachedData cachedData) {
  if (!_supportsDaylightSavingTime || _adjustmentRules == nullptr) {
    return false;
  }
  DateTime dateTime2;
  if (dateTime.get_Kind() == DateTimeKind::Local) {
    dateTime2 = ConvertTime(dateTime, cachedData->get_Local(), (TimeZoneInfo)this, flags, cachedData);
  } else {
    if (dateTime.get_Kind() == DateTimeKind::Utc) {
      if (cachedData->GetCorrespondingKind((TimeZoneInfo)this) == DateTimeKind::Utc) {
        return false;
      }
      Boolean isDaylightSavings;
      GetUtcOffsetFromUtc(dateTime, (TimeZoneInfo)this, isDaylightSavings);
      return isDaylightSavings;
    }
    dateTime2 = dateTime;
  }
  Nullable<Int32> ruleIndex;
  AdjustmentRule adjustmentRuleForTime = GetAdjustmentRuleForTime(dateTime2, ruleIndex);
  if (adjustmentRuleForTime != nullptr && adjustmentRuleForTime->get_HasDaylightSaving()) {
    DaylightTimeStruct daylightTime = GetDaylightTime(dateTime2.get_Year(), adjustmentRuleForTime, ruleIndex);
    return GetIsDaylightSavings(dateTime2, adjustmentRuleForTime, daylightTime);
  }
  return false;
}

Boolean TimeZoneInfo___::IsInvalidTime(DateTime dateTime) {
  Boolean result = false;
  if (dateTime.get_Kind() == DateTimeKind::Unspecified || (dateTime.get_Kind() == DateTimeKind::Local && s_cachedData->GetCorrespondingKind((TimeZoneInfo)this) == DateTimeKind::Local)) {
    Nullable<Int32> ruleIndex;
    AdjustmentRule adjustmentRuleForTime = GetAdjustmentRuleForTime(dateTime, ruleIndex);
    if (adjustmentRuleForTime != nullptr && adjustmentRuleForTime->get_HasDaylightSaving()) {
      DaylightTimeStruct daylightTime = GetDaylightTime(dateTime.get_Year(), adjustmentRuleForTime, ruleIndex);
      result = GetIsInvalidTime(dateTime, adjustmentRuleForTime, daylightTime);
    } else {
      result = false;
    }
  }
  return result;
}

void TimeZoneInfo___::ClearCachedData() {
  s_cachedData = rt::newobj<CachedData>();
}

DateTimeOffset TimeZoneInfo___::ConvertTimeBySystemTimeZoneId(DateTimeOffset dateTimeOffset, String destinationTimeZoneId) {
  return ConvertTime(dateTimeOffset, FindSystemTimeZoneById(destinationTimeZoneId));
}

DateTime TimeZoneInfo___::ConvertTimeBySystemTimeZoneId(DateTime dateTime, String destinationTimeZoneId) {
  return ConvertTime(dateTime, FindSystemTimeZoneById(destinationTimeZoneId));
}

DateTime TimeZoneInfo___::ConvertTimeBySystemTimeZoneId(DateTime dateTime, String sourceTimeZoneId, String destinationTimeZoneId) {
  if (dateTime.get_Kind() == DateTimeKind::Local && String::in::Equals(sourceTimeZoneId, get_Local()->get_Id(), StringComparison::OrdinalIgnoreCase)) {
    CachedData cachedData = s_cachedData;
    return ConvertTime(dateTime, cachedData->get_Local(), FindSystemTimeZoneById(destinationTimeZoneId), TimeZoneInfoOptions::None, cachedData);
  }
  if (dateTime.get_Kind() == DateTimeKind::Utc && String::in::Equals(sourceTimeZoneId, get_Utc()->get_Id(), StringComparison::OrdinalIgnoreCase)) {
    return ConvertTime(dateTime, s_utcTimeZone, FindSystemTimeZoneById(destinationTimeZoneId), TimeZoneInfoOptions::None, s_cachedData);
  }
  return ConvertTime(dateTime, FindSystemTimeZoneById(sourceTimeZoneId), FindSystemTimeZoneById(destinationTimeZoneId));
}

DateTimeOffset TimeZoneInfo___::ConvertTime(DateTimeOffset dateTimeOffset, TimeZoneInfo destinationTimeZone) {
  if (destinationTimeZone == nullptr) {
    rt::throw_exception<ArgumentNullException>("destinationTimeZone");
  }
  DateTime utcDateTime = dateTimeOffset.get_UtcDateTime();
  TimeSpan utcOffsetFromUtc = GetUtcOffsetFromUtc(utcDateTime, destinationTimeZone);
  Int64 num = utcDateTime.get_Ticks() + utcOffsetFromUtc.get_Ticks();
  if (num <= DateTimeOffset::MaxValue.get_Ticks()) {
    if (num >= DateTimeOffset::MinValue.get_Ticks()) {
      return DateTimeOffset(num, utcOffsetFromUtc);
    }
    return DateTimeOffset::MinValue;
  }
  return DateTimeOffset::MaxValue;
}

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo destinationTimeZone) {
  if (destinationTimeZone == nullptr) {
    rt::throw_exception<ArgumentNullException>("destinationTimeZone");
  }
  if (dateTime.get_Ticks() == 0) {
    ClearCachedData();
  }
  CachedData cachedData = s_cachedData;
  TimeZoneInfo sourceTimeZone = ((dateTime.get_Kind() == DateTimeKind::Utc) ? s_utcTimeZone : cachedData->get_Local());
  return ConvertTime(dateTime, sourceTimeZone, destinationTimeZone, TimeZoneInfoOptions::None, cachedData);
}

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone) {
  return ConvertTime(dateTime, sourceTimeZone, destinationTimeZone, TimeZoneInfoOptions::None, s_cachedData);
}

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone, TimeZoneInfoOptions flags) {
  return ConvertTime(dateTime, sourceTimeZone, destinationTimeZone, flags, s_cachedData);
}

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone, TimeZoneInfoOptions flags, CachedData cachedData) {
  if (sourceTimeZone == nullptr) {
    rt::throw_exception<ArgumentNullException>("sourceTimeZone");
  }
  if (destinationTimeZone == nullptr) {
    rt::throw_exception<ArgumentNullException>("destinationTimeZone");
  }
  DateTimeKind correspondingKind = cachedData->GetCorrespondingKind(sourceTimeZone);
  if ((flags & TimeZoneInfoOptions::NoThrowOnInvalidTime) == 0 && dateTime.get_Kind() != 0 && dateTime.get_Kind() != correspondingKind) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ConvertMismatch(), "sourceTimeZone");
  }
  Nullable<Int32> ruleIndex;
  AdjustmentRule adjustmentRuleForTime = sourceTimeZone->GetAdjustmentRuleForTime(dateTime, ruleIndex);
  TimeSpan baseUtcOffset = sourceTimeZone->get_BaseUtcOffset();
  if (adjustmentRuleForTime != nullptr) {
    baseUtcOffset += adjustmentRuleForTime->get_BaseUtcOffsetDelta();
    if (adjustmentRuleForTime->get_HasDaylightSaving()) {
      Boolean flag = false;
      DaylightTimeStruct daylightTime = sourceTimeZone->GetDaylightTime(dateTime.get_Year(), adjustmentRuleForTime, ruleIndex);
      if ((flags & TimeZoneInfoOptions::NoThrowOnInvalidTime) == 0 && GetIsInvalidTime(dateTime, adjustmentRuleForTime, daylightTime)) {
        rt::throw_exception<ArgumentException>(SR::get_Argument_DateTimeIsInvalid(), "dateTime");
      }
      flag = GetIsDaylightSavings(dateTime, adjustmentRuleForTime, daylightTime);
      baseUtcOffset += (flag ? adjustmentRuleForTime->get_DaylightDelta() : TimeSpan::Zero);
    }
  }
  DateTimeKind correspondingKind2 = cachedData->GetCorrespondingKind(destinationTimeZone);
  if (dateTime.get_Kind() != 0 && correspondingKind != 0 && correspondingKind == correspondingKind2) {
    return dateTime;
  }
  Int64 ticks = dateTime.get_Ticks() - baseUtcOffset.get_Ticks();
  Boolean isAmbiguousLocalDst;
  DateTime dateTime2 = ConvertUtcToTimeZone(ticks, destinationTimeZone, isAmbiguousLocalDst);
  if (correspondingKind2 == DateTimeKind::Local) {
    return DateTime(dateTime2.get_Ticks(), DateTimeKind::Local, isAmbiguousLocalDst);
  }
  return DateTime(dateTime2.get_Ticks(), correspondingKind2);
}

DateTime TimeZoneInfo___::ConvertTimeFromUtc(DateTime dateTime, TimeZoneInfo destinationTimeZone) {
  return ConvertTime(dateTime, s_utcTimeZone, destinationTimeZone, TimeZoneInfoOptions::None, s_cachedData);
}

DateTime TimeZoneInfo___::ConvertTimeToUtc(DateTime dateTime) {
  if (dateTime.get_Kind() == DateTimeKind::Utc) {
    return dateTime;
  }
  CachedData cachedData = s_cachedData;
  return ConvertTime(dateTime, cachedData->get_Local(), s_utcTimeZone, TimeZoneInfoOptions::None, cachedData);
}

DateTime TimeZoneInfo___::ConvertTimeToUtc(DateTime dateTime, TimeZoneInfoOptions flags) {
  if (dateTime.get_Kind() == DateTimeKind::Utc) {
    return dateTime;
  }
  CachedData cachedData = s_cachedData;
  return ConvertTime(dateTime, cachedData->get_Local(), s_utcTimeZone, flags, cachedData);
}

DateTime TimeZoneInfo___::ConvertTimeToUtc(DateTime dateTime, TimeZoneInfo sourceTimeZone) {
  return ConvertTime(dateTime, sourceTimeZone, s_utcTimeZone, TimeZoneInfoOptions::None, s_cachedData);
}

Boolean TimeZoneInfo___::Equals(TimeZoneInfo other) {
  if (other != nullptr && String::in::Equals(_id, other->_id, StringComparison::OrdinalIgnoreCase)) {
    return HasSameRules(other);
  }
  return false;
}

Boolean TimeZoneInfo___::Equals(Object obj) {
  return Equals(rt::as<TimeZoneInfo>(obj));
}

TimeZoneInfo TimeZoneInfo___::FromSerializedString(String source) {
  if (source == nullptr) {
    rt::throw_exception<ArgumentNullException>("source");
  }
  if (source->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidSerializedString(), source), "source");
  }
  return StringSerializer::GetDeserializedTimeZoneInfo(source);
}

Int32 TimeZoneInfo___::GetHashCode() {
  return StringComparer::in::get_OrdinalIgnoreCase()->GetHashCode(_id);
}

ReadOnlyCollection<TimeZoneInfo> TimeZoneInfo___::GetSystemTimeZones() {
  CachedData cachedData = s_cachedData;
  {
    rt::lock(cachedData);
    if (cachedData->_readOnlySystemTimeZones == nullptr) {
      PopulateAllSystemTimeZones(cachedData);
      cachedData->_allSystemTimeZonesRead = true;
      List<TimeZoneInfo> list = ((cachedData->_systemTimeZones == nullptr) ? rt::newobj<List<TimeZoneInfo>>() : rt::newobj<List<TimeZoneInfo>>(cachedData->_systemTimeZones->get_Values()));
      Comparison<TimeZoneInfo> as = __c::in::__9__62_0;
      list->Sort(as != nullptr ? as : (__c::in::__9__62_0 = {__c::in::__9, &__c::in::_GetSystemTimeZones_b__62_0}));
      cachedData->_readOnlySystemTimeZones = rt::newobj<ReadOnlyCollection<TimeZoneInfo>>(list);
    }
  }
  return cachedData->_readOnlySystemTimeZones;
}

Boolean TimeZoneInfo___::HasSameRules(TimeZoneInfo other) {
  if (other == nullptr) {
    rt::throw_exception<ArgumentNullException>("other");
  }
  if (_baseUtcOffset != other->_baseUtcOffset || _supportsDaylightSavingTime != other->_supportsDaylightSavingTime) {
    return false;
  }
  Array<AdjustmentRule> adjustmentRules = _adjustmentRules;
  Array<AdjustmentRule> adjustmentRules2 = other->_adjustmentRules;
  Boolean flag = (adjustmentRules == nullptr && adjustmentRules2 == nullptr) || (adjustmentRules != nullptr && adjustmentRules2 != nullptr);
  if (!flag) {
    return false;
  }
  if (adjustmentRules != nullptr) {
    if (adjustmentRules->get_Length() != adjustmentRules2->get_Length()) {
      return false;
    }
    for (Int32 i = 0; i < adjustmentRules->get_Length(); i++) {
      if (!adjustmentRules[i]->Equals(adjustmentRules2[i])) {
        return false;
      }
    }
  }
  return flag;
}

String TimeZoneInfo___::ToSerializedString() {
  return StringSerializer::GetSerializedString((TimeZoneInfo)this);
}

String TimeZoneInfo___::ToString() {
  return get_DisplayName();
}

void TimeZoneInfo___::ctor(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules, Boolean disableDaylightSavingTime) {
  Boolean adjustmentRulesSupportDst;
  ValidateTimeZoneInfo(id, baseUtcOffset, adjustmentRules, adjustmentRulesSupportDst);
  _id = id;
  _baseUtcOffset = baseUtcOffset;
  _displayName = displayName;
  _standardDisplayName = standardDisplayName;
  _daylightDisplayName = (disableDaylightSavingTime ? nullptr : daylightDisplayName);
  _supportsDaylightSavingTime = adjustmentRulesSupportDst && !disableDaylightSavingTime;
  _adjustmentRules = adjustmentRules;
}

TimeZoneInfo TimeZoneInfo___::CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName) {
  return rt::newobj<TimeZoneInfo>(id, baseUtcOffset, displayName, standardDisplayName, standardDisplayName, nullptr, false);
}

TimeZoneInfo TimeZoneInfo___::CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules) {
  return CreateCustomTimeZone(id, baseUtcOffset, displayName, standardDisplayName, daylightDisplayName, adjustmentRules, false);
}

TimeZoneInfo TimeZoneInfo___::CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules, Boolean disableDaylightSavingTime) {
  if (!disableDaylightSavingTime && adjustmentRules != nullptr && adjustmentRules->get_Length() != 0) {
    adjustmentRules = (Array<AdjustmentRule>)adjustmentRules->Clone();
  }
  return rt::newobj<TimeZoneInfo>(id, baseUtcOffset, displayName, standardDisplayName, daylightDisplayName, adjustmentRules, disableDaylightSavingTime);
}

void TimeZoneInfo___::OnDeserializationOfIDeserializationCallback(Object sender) {
  try {
    Boolean adjustmentRulesSupportDst;
    ValidateTimeZoneInfo(_id, _baseUtcOffset, _adjustmentRules, adjustmentRulesSupportDst);
    if (adjustmentRulesSupportDst != _supportsDaylightSavingTime) {
      rt::throw_exception<SerializationException>(SR::Format(SR::get_Serialization_CorruptField(), "SupportsDaylightSavingTime"));
    }
  } catch (ArgumentException innerException) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException);
  } catch (InvalidTimeZoneException innerException2) {
    rt::throw_exception<SerializationException>(SR::get_Serialization_InvalidData(), innerException2);
  }
}

void TimeZoneInfo___::GetObjectDataOfISerializable(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  info->AddValue("Id", _id);
  info->AddValue("DisplayName", _displayName);
  info->AddValue("StandardName", _standardDisplayName);
  info->AddValue("DaylightName", _daylightDisplayName);
  info->AddValue("BaseUtcOffset", _baseUtcOffset);
  info->AddValue("AdjustmentRules", _adjustmentRules);
  info->AddValue("SupportsDaylightSavingTime", _supportsDaylightSavingTime);
}

void TimeZoneInfo___::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
  _id = (String)info->GetValue("Id", typeof<String>());
  _displayName = (String)info->GetValue("DisplayName", typeof<String>());
  _standardDisplayName = (String)info->GetValue("StandardName", typeof<String>());
  _daylightDisplayName = (String)info->GetValue("DaylightName", typeof<String>());
  _baseUtcOffset = (TimeSpan)info->GetValue("BaseUtcOffset", typeof<TimeSpan>());
  _adjustmentRules = (Array<AdjustmentRule>)info->GetValue("AdjustmentRules", typeof<Array<AdjustmentRule>>());
  _supportsDaylightSavingTime = (Boolean)info->GetValue("SupportsDaylightSavingTime", typeof<Boolean>());
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetAdjustmentRuleForTime(DateTime dateTime, Nullable<Int32>& ruleIndex) {
  return GetAdjustmentRuleForTime(dateTime, false, ruleIndex);
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetAdjustmentRuleForTime(DateTime dateTime, Boolean dateTimeisUtc, Nullable<Int32>& ruleIndex) {
  if (_adjustmentRules == nullptr || _adjustmentRules->get_Length() == 0) {
    ruleIndex = nullptr;
    return nullptr;
  }
  DateTime dateOnly = (dateTimeisUtc ? (dateTime + get_BaseUtcOffset()).get_Date() : dateTime.get_Date());
  Int32 num = 0;
  Int32 num2 = _adjustmentRules->get_Length() - 1;
  while (num <= num2) {
    Int32 num3 = num + (num2 - num >> 1);
    AdjustmentRule adjustmentRule = _adjustmentRules[num3];
    AdjustmentRule previousRule = ((num3 > 0) ? _adjustmentRules[num3 - 1] : adjustmentRule);
    Int32 num4 = CompareAdjustmentRuleToDateTime(adjustmentRule, previousRule, dateTime, dateOnly, dateTimeisUtc);
    if (num4 == 0) {
      ruleIndex = num3;
      return adjustmentRule;
    }
    if (num4 < 0) {
      num = num3 + 1;
    } else {
      num2 = num3 - 1;
    }
  }
  ruleIndex = nullptr;
  return nullptr;
}

Int32 TimeZoneInfo___::CompareAdjustmentRuleToDateTime(AdjustmentRule rule, AdjustmentRule previousRule, DateTime dateTime, DateTime dateOnly, Boolean dateTimeisUtc) {
  Boolean flag;
  if (rule->get_DateStart().get_Kind() == DateTimeKind::Utc) {
    DateTime t = (dateTimeisUtc ? dateTime : ConvertToUtc(dateTime, previousRule->get_DaylightDelta(), previousRule->get_BaseUtcOffsetDelta()));
    flag = t >= rule->get_DateStart();
  } else {
    flag = dateOnly >= rule->get_DateStart();
  }
  if (!flag) {
    return 1;
  }
  Boolean flag2;
  if (rule->get_DateEnd().get_Kind() == DateTimeKind::Utc) {
    DateTime t2 = (dateTimeisUtc ? dateTime : ConvertToUtc(dateTime, rule->get_DaylightDelta(), rule->get_BaseUtcOffsetDelta()));
    flag2 = t2 <= rule->get_DateEnd();
  } else {
    flag2 = dateOnly <= rule->get_DateEnd();
  }
  if (!flag2) {
    return -1;
  }
  return 0;
}

DateTime TimeZoneInfo___::ConvertToUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta) {
  return ConvertToFromUtc(dateTime, daylightDelta, baseUtcOffsetDelta, true);
}

DateTime TimeZoneInfo___::ConvertFromUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta) {
  return ConvertToFromUtc(dateTime, daylightDelta, baseUtcOffsetDelta, false);
}

DateTime TimeZoneInfo___::ConvertToFromUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta, Boolean convertToUtc) {
  TimeSpan timeSpan = get_BaseUtcOffset() + daylightDelta + baseUtcOffsetDelta;
  if (convertToUtc) {
    timeSpan = timeSpan.Negate();
  }
  Int64 num = dateTime.get_Ticks() + timeSpan.get_Ticks();
  if (num <= DateTime::MaxValue.get_Ticks()) {
    if (num >= DateTime::MinValue.get_Ticks()) {
      return DateTime(num);
    }
    return DateTime::MinValue;
  }
  return DateTime::MaxValue;
}

DateTime TimeZoneInfo___::ConvertUtcToTimeZone(Int64 ticks, TimeZoneInfo destinationTimeZone, Boolean& isAmbiguousLocalDst) {
  DateTime time = ((ticks > DateTime::MaxValue.get_Ticks()) ? DateTime::MaxValue : ((ticks < DateTime::MinValue.get_Ticks()) ? DateTime::MinValue : DateTime(ticks)));
  ticks += GetUtcOffsetFromUtc(time, destinationTimeZone, isAmbiguousLocalDst).get_Ticks();
  if (ticks <= DateTime::MaxValue.get_Ticks()) {
    if (ticks >= DateTime::MinValue.get_Ticks()) {
      return DateTime(ticks);
    }
    return DateTime::MinValue;
  }
  return DateTime::MaxValue;
}

DaylightTimeStruct TimeZoneInfo___::GetDaylightTime(Int32 year, AdjustmentRule rule, Nullable<Int32> ruleIndex) {
  TimeSpan daylightDelta = rule->get_DaylightDelta();
  DateTime start;
  DateTime end;
  if (rule->get_NoDaylightTransitions()) {
    AdjustmentRule previousAdjustmentRule = GetPreviousAdjustmentRule(rule, ruleIndex);
    start = ConvertFromUtc(rule->get_DateStart(), previousAdjustmentRule->get_DaylightDelta(), previousAdjustmentRule->get_BaseUtcOffsetDelta());
    end = ConvertFromUtc(rule->get_DateEnd(), rule->get_DaylightDelta(), rule->get_BaseUtcOffsetDelta());
  } else {
    start = TransitionTimeToDateTime(year, rule->get_DaylightTransitionStart());
    end = TransitionTimeToDateTime(year, rule->get_DaylightTransitionEnd());
  }
  return DaylightTimeStruct(start, end, daylightDelta);
}

Boolean TimeZoneInfo___::GetIsDaylightSavings(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime) {
  if (rule == nullptr) {
    return false;
  }
  DateTime startTime;
  DateTime endTime;
  if (time.get_Kind() == DateTimeKind::Local) {
    startTime = (rule->IsStartDateMarkerForBeginningOfYear() ? DateTime(daylightTime.Start.get_Year(), 1, 1, 0, 0, 0) : (daylightTime.Start + daylightTime.Delta));
    endTime = (rule->IsEndDateMarkerForEndOfYear() ? DateTime(daylightTime.End.get_Year() + 1, 1, 1, 0, 0, 0).AddTicks(-1) : daylightTime.End);
  } else {
    Boolean flag = rule->get_DaylightDelta() > TimeSpan::Zero;
    startTime = (rule->IsStartDateMarkerForBeginningOfYear() ? DateTime(daylightTime.Start.get_Year(), 1, 1, 0, 0, 0) : (daylightTime.Start + (flag ? rule->get_DaylightDelta() : TimeSpan::Zero)));
    endTime = (rule->IsEndDateMarkerForEndOfYear() ? DateTime(daylightTime.End.get_Year() + 1, 1, 1, 0, 0, 0).AddTicks(-1) : (daylightTime.End + (flag ? (-rule->get_DaylightDelta()) : TimeSpan::Zero)));
  }
  Boolean flag2 = CheckIsDst(startTime, time, endTime, false, rule);
  if (flag2 && time.get_Kind() == DateTimeKind::Local && GetIsAmbiguousTime(time, rule, daylightTime)) {
    flag2 = time.IsAmbiguousDaylightSavingTime();
  }
  return flag2;
}

TimeSpan TimeZoneInfo___::GetDaylightSavingsStartOffsetFromUtc(TimeSpan baseUtcOffset, AdjustmentRule rule, Nullable<Int32> ruleIndex) {
  if (rule->get_NoDaylightTransitions()) {
    AdjustmentRule previousAdjustmentRule = GetPreviousAdjustmentRule(rule, ruleIndex);
    return baseUtcOffset + previousAdjustmentRule->get_BaseUtcOffsetDelta() + previousAdjustmentRule->get_DaylightDelta();
  }
  return baseUtcOffset + rule->get_BaseUtcOffsetDelta();
}

TimeSpan TimeZoneInfo___::GetDaylightSavingsEndOffsetFromUtc(TimeSpan baseUtcOffset, AdjustmentRule rule) {
  return baseUtcOffset + rule->get_BaseUtcOffsetDelta() + rule->get_DaylightDelta();
}

Boolean TimeZoneInfo___::GetIsDaylightSavingsFromUtc(DateTime time, Int32 year, TimeSpan utc, AdjustmentRule rule, Nullable<Int32> ruleIndex, Boolean& isAmbiguousLocalDst, TimeZoneInfo zone) {
  isAmbiguousLocalDst = false;
  if (rule == nullptr) {
    return false;
  }
  DaylightTimeStruct daylightTime = zone->GetDaylightTime(year, rule, ruleIndex);
  Boolean ignoreYearAdjustment = false;
  TimeSpan daylightSavingsStartOffsetFromUtc = zone->GetDaylightSavingsStartOffsetFromUtc(utc, rule, ruleIndex);
  DateTime dateTime;
  if (rule->IsStartDateMarkerForBeginningOfYear() && daylightTime.Start.get_Year() > DateTime::MinValue.get_Year()) {
    Nullable<Int32> ruleIndex2;
    AdjustmentRule adjustmentRuleForTime = zone->GetAdjustmentRuleForTime(DateTime(daylightTime.Start.get_Year() - 1, 12, 31), ruleIndex2);
    if (adjustmentRuleForTime != nullptr && adjustmentRuleForTime->IsEndDateMarkerForEndOfYear()) {
      dateTime = zone->GetDaylightTime(daylightTime.Start.get_Year() - 1, adjustmentRuleForTime, ruleIndex2).Start - utc - adjustmentRuleForTime->get_BaseUtcOffsetDelta();
      ignoreYearAdjustment = true;
    } else {
      dateTime = DateTime(daylightTime.Start.get_Year(), 1, 1, 0, 0, 0) - daylightSavingsStartOffsetFromUtc;
    }
  } else {
    dateTime = daylightTime.Start - daylightSavingsStartOffsetFromUtc;
  }
  TimeSpan daylightSavingsEndOffsetFromUtc = zone->GetDaylightSavingsEndOffsetFromUtc(utc, rule);
  DateTime dateTime2;
  if (rule->IsEndDateMarkerForEndOfYear() && daylightTime.End.get_Year() < DateTime::MaxValue.get_Year()) {
    Nullable<Int32> ruleIndex3;
    AdjustmentRule adjustmentRuleForTime2 = zone->GetAdjustmentRuleForTime(DateTime(daylightTime.End.get_Year() + 1, 1, 1), ruleIndex3);
    if (adjustmentRuleForTime2 != nullptr && adjustmentRuleForTime2->IsStartDateMarkerForBeginningOfYear()) {
      dateTime2 = ((!adjustmentRuleForTime2->IsEndDateMarkerForEndOfYear()) ? (zone->GetDaylightTime(daylightTime.End.get_Year() + 1, adjustmentRuleForTime2, ruleIndex3).End - utc - adjustmentRuleForTime2->get_BaseUtcOffsetDelta() - adjustmentRuleForTime2->get_DaylightDelta()) : (DateTime(daylightTime.End.get_Year() + 1, 12, 31) - utc - adjustmentRuleForTime2->get_BaseUtcOffsetDelta() - adjustmentRuleForTime2->get_DaylightDelta()));
      ignoreYearAdjustment = true;
    } else {
      dateTime2 = DateTime(daylightTime.End.get_Year() + 1, 1, 1, 0, 0, 0).AddTicks(-1) - daylightSavingsEndOffsetFromUtc;
    }
  } else {
    dateTime2 = daylightTime.End - daylightSavingsEndOffsetFromUtc;
  }
  DateTime t;
  DateTime t2;
  if (daylightTime.Delta.get_Ticks() > 0) {
    t = dateTime2 - daylightTime.Delta;
    t2 = dateTime2;
  } else {
    t = dateTime;
    t2 = dateTime - daylightTime.Delta;
  }
  Boolean flag = CheckIsDst(dateTime, time, dateTime2, ignoreYearAdjustment, rule);
  if (flag) {
    isAmbiguousLocalDst = time >= t && time < t2;
    if (!isAmbiguousLocalDst && t.get_Year() != t2.get_Year()) {
      try {
        DateTime t3 = t.AddYears(1);
        DateTime t4 = t2.AddYears(1);
        isAmbiguousLocalDst = time >= t3 && time < t4;
      } catch (ArgumentOutOfRangeException) {
      }
      if (!isAmbiguousLocalDst) {
        try {
          DateTime t3 = t.AddYears(-1);
          DateTime t4 = t2.AddYears(-1);
          isAmbiguousLocalDst = time >= t3 && time < t4;
          return flag;
        } catch (ArgumentOutOfRangeException) {
          return flag;
        }
      }
    }
  }
  return flag;
}

Boolean TimeZoneInfo___::CheckIsDst(DateTime startTime, DateTime time, DateTime endTime, Boolean ignoreYearAdjustment, AdjustmentRule rule) {
  if (!ignoreYearAdjustment && !rule->get_NoDaylightTransitions()) {
    Int32 year = startTime.get_Year();
    Int32 year2 = endTime.get_Year();
    if (year != year2) {
      endTime = endTime.AddYears(year - year2);
    }
    Int32 year3 = time.get_Year();
    if (year != year3) {
      time = time.AddYears(year - year3);
    }
  }
  if (startTime > endTime) {
    if (!(time < endTime)) {
      return time >= startTime;
    }
    return true;
  }
  if (rule->get_NoDaylightTransitions()) {
    if (time >= startTime) {
      return time <= endTime;
    }
    return false;
  }
  if (time >= startTime) {
    return time < endTime;
  }
  return false;
}

Boolean TimeZoneInfo___::GetIsAmbiguousTime(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime) {
  Boolean result = false;
  if (rule == nullptr || rule->get_DaylightDelta() == TimeSpan::Zero) {
    return result;
  }
  DateTime t;
  DateTime t2;
  if (rule->get_DaylightDelta() > TimeSpan::Zero) {
    if (rule->IsEndDateMarkerForEndOfYear()) {
      return false;
    }
    t = daylightTime.End;
    t2 = daylightTime.End - rule->get_DaylightDelta();
  } else {
    if (rule->IsStartDateMarkerForBeginningOfYear()) {
      return false;
    }
    t = daylightTime.Start;
    t2 = daylightTime.Start + rule->get_DaylightDelta();
  }
  result = time >= t2 && time < t;
  if (!result && t.get_Year() != t2.get_Year()) {
    try {
      DateTime t3 = t.AddYears(1);
      DateTime t4 = t2.AddYears(1);
      result = time >= t4 && time < t3;
    } catch (ArgumentOutOfRangeException) {
    }
    if (!result) {
      try {
        DateTime t3 = t.AddYears(-1);
        DateTime t4 = t2.AddYears(-1);
        result = time >= t4 && time < t3;
        return result;
      } catch (ArgumentOutOfRangeException) {
        return result;
      }
    }
  }
  return result;
}

Boolean TimeZoneInfo___::GetIsInvalidTime(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime) {
  Boolean result = false;
  if (rule == nullptr || rule->get_DaylightDelta() == TimeSpan::Zero) {
    return result;
  }
  DateTime t;
  DateTime t2;
  if (rule->get_DaylightDelta() < TimeSpan::Zero) {
    if (rule->IsEndDateMarkerForEndOfYear()) {
      return false;
    }
    t = daylightTime.End;
    t2 = daylightTime.End - rule->get_DaylightDelta();
  } else {
    if (rule->IsStartDateMarkerForBeginningOfYear()) {
      return false;
    }
    t = daylightTime.Start;
    t2 = daylightTime.Start + rule->get_DaylightDelta();
  }
  result = time >= t && time < t2;
  if (!result && t.get_Year() != t2.get_Year()) {
    try {
      DateTime t3 = t.AddYears(1);
      DateTime t4 = t2.AddYears(1);
      result = time >= t3 && time < t4;
    } catch (ArgumentOutOfRangeException) {
    }
    if (!result) {
      try {
        DateTime t3 = t.AddYears(-1);
        DateTime t4 = t2.AddYears(-1);
        result = time >= t3 && time < t4;
        return result;
      } catch (ArgumentOutOfRangeException) {
        return result;
      }
    }
  }
  return result;
}

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime time, TimeZoneInfo zone) {
  TimeSpan baseUtcOffset = zone->get_BaseUtcOffset();
  Nullable<Int32> ruleIndex;
  AdjustmentRule adjustmentRuleForTime = zone->GetAdjustmentRuleForTime(time, ruleIndex);
  if (adjustmentRuleForTime != nullptr) {
    baseUtcOffset += adjustmentRuleForTime->get_BaseUtcOffsetDelta();
    if (adjustmentRuleForTime->get_HasDaylightSaving()) {
      DaylightTimeStruct daylightTime = zone->GetDaylightTime(time.get_Year(), adjustmentRuleForTime, ruleIndex);
      Boolean isDaylightSavings = GetIsDaylightSavings(time, adjustmentRuleForTime, daylightTime);
      baseUtcOffset += (isDaylightSavings ? adjustmentRuleForTime->get_DaylightDelta() : TimeSpan::Zero);
    }
  }
  return baseUtcOffset;
}

TimeSpan TimeZoneInfo___::GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone) {
  Boolean isDaylightSavings;
  return GetUtcOffsetFromUtc(time, zone, isDaylightSavings);
}

TimeSpan TimeZoneInfo___::GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone, Boolean& isDaylightSavings) {
  Boolean isAmbiguousLocalDst;
  return GetUtcOffsetFromUtc(time, zone, isDaylightSavings, isAmbiguousLocalDst);
}

TimeSpan TimeZoneInfo___::GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone, Boolean& isDaylightSavings, Boolean& isAmbiguousLocalDst) {
  isDaylightSavings = false;
  isAmbiguousLocalDst = false;
  TimeSpan baseUtcOffset = zone->get_BaseUtcOffset();
  AdjustmentRule adjustmentRuleForTime;
  Nullable<Int32> ruleIndex;
  Int32 year;
  if (time > s_maxDateOnly) {
    adjustmentRuleForTime = zone->GetAdjustmentRuleForTime(DateTime::MaxValue, ruleIndex);
    year = 9999;
  } else if (time < s_minDateOnly) {
    adjustmentRuleForTime = zone->GetAdjustmentRuleForTime(DateTime::MinValue, ruleIndex);
    year = 1;
  } else {
    adjustmentRuleForTime = zone->GetAdjustmentRuleForTime(time, true, ruleIndex);
    year = (time + baseUtcOffset).get_Year();
  }

  if (adjustmentRuleForTime != nullptr) {
    baseUtcOffset += adjustmentRuleForTime->get_BaseUtcOffsetDelta();
    if (adjustmentRuleForTime->get_HasDaylightSaving()) {
      isDaylightSavings = GetIsDaylightSavingsFromUtc(time, year, zone->_baseUtcOffset, adjustmentRuleForTime, ruleIndex, isAmbiguousLocalDst, zone);
      baseUtcOffset += (isDaylightSavings ? adjustmentRuleForTime->get_DaylightDelta() : TimeSpan::Zero);
    }
  }
  return baseUtcOffset;
}

DateTime TimeZoneInfo___::TransitionTimeToDateTime(Int32 year, TransitionTime transitionTime) {
  TimeSpan timeOfDay = transitionTime.get_TimeOfDay().get_TimeOfDay();
  DateTime result;
  if (transitionTime.get_IsFixedDateRule()) {
    Int32 num = transitionTime.get_Day();
    if (num > 28) {
      Int32 num2 = DateTime::DaysInMonth(year, transitionTime.get_Month());
      if (num > num2) {
        num = num2;
      }
    }
    result = DateTime(year, transitionTime.get_Month(), num) + timeOfDay;
  } else if (transitionTime.get_Week() <= 4) {
    result = DateTime(year, transitionTime.get_Month(), 1) + timeOfDay;
    Int32 dayOfWeek = (Int32)result.get_DayOfWeek();
    Int32 num3 = (Int32)(transitionTime.get_DayOfWeek() - dayOfWeek);
    if (num3 < 0) {
      num3 += 7;
    }
    num3 += 7 * (transitionTime.get_Week() - 1);
    if (num3 > 0) {
      result = result.AddDays(num3);
    }
  } else {
    Int32 day = DateTime::DaysInMonth(year, transitionTime.get_Month());
    result = DateTime(year, transitionTime.get_Month(), day) + timeOfDay;
    Int32 dayOfWeek2 = (Int32)result.get_DayOfWeek();
    Int32 num4 = (Int32)(dayOfWeek2 - transitionTime.get_DayOfWeek());
    if (num4 < 0) {
      num4 += 7;
    }
    if (num4 > 0) {
      result = result.AddDays(-num4);
    }
  }

  return result;
}

TimeZoneInfo::in::TimeZoneInfoResult TimeZoneInfo___::TryGetTimeZone(String id, Boolean dstDisabled, TimeZoneInfo& value, Exception& e, CachedData cachedData, Boolean alwaysFallbackToLocalMachine) {
  TimeZoneInfoResult result = TimeZoneInfoResult::Success;
  e = nullptr;
  TimeZoneInfo value2;
  if (cachedData->_systemTimeZones != nullptr && cachedData->_systemTimeZones->TryGetValue(id, value2)) {
    if (dstDisabled && value2->_supportsDaylightSavingTime) {
      value = CreateCustomTimeZone(value2->_id, value2->_baseUtcOffset, value2->_displayName, value2->_standardDisplayName);
    } else {
      value = rt::newobj<TimeZoneInfo>(value2->_id, value2->_baseUtcOffset, value2->_displayName, value2->_standardDisplayName, value2->_daylightDisplayName, value2->_adjustmentRules, false);
    }
    return result;
  }
  if (!cachedData->_allSystemTimeZonesRead || alwaysFallbackToLocalMachine) {
    result = TryGetTimeZoneFromLocalMachine(id, dstDisabled, value, e, cachedData);
  } else {
    result = TimeZoneInfoResult::TimeZoneNotFoundException;
    value = nullptr;
  }
  return result;
}

TimeZoneInfo::in::TimeZoneInfoResult TimeZoneInfo___::TryGetTimeZoneFromLocalMachine(String id, Boolean dstDisabled, TimeZoneInfo& value, Exception& e, CachedData cachedData) {
  TimeZoneInfo value2;
  TimeZoneInfoResult timeZoneInfoResult = TryGetTimeZoneFromLocalMachine(id, value2, e);
  if (timeZoneInfoResult == TimeZoneInfoResult::Success) {
    if (cachedData->_systemTimeZones == nullptr) {
      cachedData->_systemTimeZones = rt::newobj<Dictionary<String, TimeZoneInfo>>(StringComparer::in::get_OrdinalIgnoreCase());
    }
    if (!id->Equals("UTC", StringComparison::OrdinalIgnoreCase)) {
      cachedData->_systemTimeZones->Add(id, value2);
    }
    if (dstDisabled && value2->_supportsDaylightSavingTime) {
      value = CreateCustomTimeZone(value2->_id, value2->_baseUtcOffset, value2->_displayName, value2->_standardDisplayName);
    } else {
      value = rt::newobj<TimeZoneInfo>(value2->_id, value2->_baseUtcOffset, value2->_displayName, value2->_standardDisplayName, value2->_daylightDisplayName, value2->_adjustmentRules, false);
    }
  } else {
    value = nullptr;
  }
  return timeZoneInfoResult;
}

void TimeZoneInfo___::ValidateTimeZoneInfo(String id, TimeSpan baseUtcOffset, Array<AdjustmentRule> adjustmentRules, Boolean& adjustmentRulesSupportDst) {
  if (id == nullptr) {
    rt::throw_exception<ArgumentNullException>("id");
  }
  if (id->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidId(), id), "id");
  }
  if (UtcOffsetOutOfRange(baseUtcOffset)) {
    rt::throw_exception<ArgumentOutOfRangeException>("baseUtcOffset", SR::get_ArgumentOutOfRange_UtcOffset());
  }
  if (baseUtcOffset.get_Ticks() % 600000000 != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_TimeSpanHasSeconds(), "baseUtcOffset");
  }
  adjustmentRulesSupportDst = false;
  if (adjustmentRules == nullptr || adjustmentRules->get_Length() == 0) {
    return;
  }
  adjustmentRulesSupportDst = true;
  AdjustmentRule adjustmentRule = nullptr;
  AdjustmentRule adjustmentRule2 = nullptr;
  for (Int32 i = 0; i < adjustmentRules->get_Length(); i++) {
    adjustmentRule = adjustmentRule2;
    adjustmentRule2 = adjustmentRules[i];
    if (adjustmentRule2 == nullptr) {
      rt::throw_exception<InvalidTimeZoneException>(SR::get_Argument_AdjustmentRulesNoNulls());
    }
    if (!IsValidAdjustmentRuleOffest(baseUtcOffset, adjustmentRule2)) {
      rt::throw_exception<InvalidTimeZoneException>(SR::get_ArgumentOutOfRange_UtcOffsetAndDaylightDelta());
    }
    if (adjustmentRule != nullptr && adjustmentRule2->get_DateStart() <= adjustmentRule->get_DateEnd()) {
      rt::throw_exception<InvalidTimeZoneException>(SR::get_Argument_AdjustmentRulesOutOfOrder());
    }
  }
}

Boolean TimeZoneInfo___::UtcOffsetOutOfRange(TimeSpan offset) {
  if (!(offset < MinOffset)) {
    return offset > MaxOffset;
  }
  return true;
}

TimeSpan TimeZoneInfo___::GetUtcOffset(TimeSpan baseUtcOffset, AdjustmentRule adjustmentRule) {
  return baseUtcOffset + adjustmentRule->get_BaseUtcOffsetDelta() + (adjustmentRule->get_HasDaylightSaving() ? adjustmentRule->get_DaylightDelta() : TimeSpan::Zero);
}

Boolean TimeZoneInfo___::IsValidAdjustmentRuleOffest(TimeSpan baseUtcOffset, AdjustmentRule adjustmentRule) {
  TimeSpan utcOffset = GetUtcOffset(baseUtcOffset, adjustmentRule);
  return !UtcOffsetOutOfRange(utcOffset);
}

Array<TimeZoneInfo::in::AdjustmentRule> TimeZoneInfo___::GetAdjustmentRules() {
  if (_adjustmentRules == nullptr) {
    return Array<>::in::Empty<AdjustmentRule>();
  }
  return (Array<AdjustmentRule>)_adjustmentRules->Clone();
}

void TimeZoneInfo___::PopulateAllSystemTimeZones(CachedData cachedData) {
  {
    RegistryKey registryKey = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones", false);
    rt::Using(registryKey);
    if (registryKey != nullptr) {
      Array<String> subKeyNames = registryKey->GetSubKeyNames();
      for (String&& id : *subKeyNames) {
        TimeZoneInfo value;
        Exception e;
        TryGetTimeZone(id, false, value, e, cachedData);
      }
    }
  }
}

void TimeZoneInfo___::ctor(Interop::Kernel32::TIME_ZONE_INFORMATION& zone, Boolean dstDisabled) {
  String standardName = zone.GetStandardName();
  if (standardName->get_Length() == 0) {
    _id = "Local";
  } else {
    _id = standardName;
  }
  _baseUtcOffset = TimeSpan(0, -zone.Bias, 0);
  if (!dstDisabled) {
    Interop::Kernel32::REG_TZI_FORMAT timeZoneInformation = Interop::Kernel32::REG_TZI_FORMAT(zone);
    AdjustmentRule adjustmentRule = CreateAdjustmentRuleFromTimeZoneInformation(timeZoneInformation, DateTime::MinValue.get_Date(), DateTime::MaxValue.get_Date(), zone.Bias);
    if (adjustmentRule != nullptr) {
      _adjustmentRules = rt::newarr<Array<AdjustmentRule>>(1);
    }
  }
  ValidateTimeZoneInfo(_id, _baseUtcOffset, _adjustmentRules, _supportsDaylightSavingTime);
  _displayName = standardName;
  _standardDisplayName = standardName;
  _daylightDisplayName = zone.GetDaylightName();
}

Boolean TimeZoneInfo___::CheckDaylightSavingTimeNotSupported(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone) {
  return timeZone.DaylightDate.Equals(timeZone.StandardDate);
}

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::CreateAdjustmentRuleFromTimeZoneInformation(Interop::Kernel32::REG_TZI_FORMAT& timeZoneInformation, DateTime startDate, DateTime endDate, Int32 defaultBaseUtcOffset) {
  if (timeZoneInformation.StandardDate.Month == 0) {
    if (timeZoneInformation.Bias == defaultBaseUtcOffset) {
      return nullptr;
    }
    return AdjustmentRule::in::CreateAdjustmentRule(startDate, endDate, TimeSpan::Zero, TransitionTime::CreateFixedDateRule(DateTime::MinValue, 1, 1), TransitionTime::CreateFixedDateRule(DateTime::MinValue.AddMilliseconds(1), 1, 1), TimeSpan(0, defaultBaseUtcOffset - timeZoneInformation.Bias, 0), false);
  }
  TransitionTime transitionTime;
  if (!TransitionTimeFromTimeZoneInformation(timeZoneInformation, transitionTime, true)) {
    return nullptr;
  }
  TransitionTime transitionTime2;
  if (!TransitionTimeFromTimeZoneInformation(timeZoneInformation, transitionTime2, false)) {
    return nullptr;
  }
  if (transitionTime.Equals(transitionTime2)) {
    return nullptr;
  }
  return AdjustmentRule::in::CreateAdjustmentRule(startDate, endDate, TimeSpan(0, -timeZoneInformation.DaylightBias, 0), transitionTime, transitionTime2, TimeSpan(0, defaultBaseUtcOffset - timeZoneInformation.Bias, 0), false);
}

String TimeZoneInfo___::FindIdFromTimeZoneInformation(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, Boolean& dstDisabled) {
  dstDisabled = false;
  {
    RegistryKey registryKey = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones", false);
    rt::Using(registryKey);
    if (registryKey == nullptr) {
      return nullptr;
    }
    Array<String> subKeyNames = registryKey->GetSubKeyNames();
    for (String&& text : *subKeyNames) {
      if (TryCompareTimeZoneInformationToRegistry(timeZone, text, dstDisabled)) {
        return text;
      }
    }
  }
  return nullptr;
}

TimeZoneInfo TimeZoneInfo___::GetLocalTimeZone(CachedData cachedData) {
  Interop::Kernel32::TIME_DYNAMIC_ZONE_INFORMATION pTimeZoneInformation;
  UInt32 dynamicTimeZoneInformation = Interop::Kernel32::GetDynamicTimeZoneInformation(pTimeZoneInformation);
  if (dynamicTimeZoneInformation == UInt32::MaxValue()) {
    return CreateCustomTimeZone("Local", TimeSpan::Zero, "Local", "Local");
  }
  String timeZoneKeyName = pTimeZoneInformation.GetTimeZoneKeyName();
  TimeZoneInfo value;
  Exception e;
  if (timeZoneKeyName->get_Length() != 0 && TryGetTimeZone(timeZoneKeyName, pTimeZoneInformation.DynamicDaylightTimeDisabled != 0, value, e, cachedData) == TimeZoneInfoResult::Success) {
    return value;
  }
  Interop::Kernel32::TIME_ZONE_INFORMATION timeZone = Interop::Kernel32::TIME_ZONE_INFORMATION(pTimeZoneInformation);
  Boolean dstDisabled;
  String text = FindIdFromTimeZoneInformation(timeZone, dstDisabled);
  TimeZoneInfo value2;
  if (text != nullptr && TryGetTimeZone(text, dstDisabled, value2, e, cachedData) == TimeZoneInfoResult::Success) {
    return value2;
  }
  return GetLocalTimeZoneFromWin32Data(timeZone, dstDisabled);
}

TimeZoneInfo TimeZoneInfo___::GetLocalTimeZoneFromWin32Data(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZoneInformation, Boolean dstDisabled) {
  try {
    return rt::newobj<TimeZoneInfo>(timeZoneInformation, dstDisabled);
  } catch (ArgumentException) {
  } catch (InvalidTimeZoneException) {
  }
  if (!dstDisabled) {
    try {
      return rt::newobj<TimeZoneInfo>(timeZoneInformation, true);
    } catch (ArgumentException) {
    } catch (InvalidTimeZoneException) {
    }
  }
  return CreateCustomTimeZone("Local", TimeSpan::Zero, "Local", "Local");
}

TimeZoneInfo TimeZoneInfo___::FindSystemTimeZoneById(String id) {
  if (String::in::Equals(id, "UTC", StringComparison::OrdinalIgnoreCase)) {
    return get_Utc();
  }
  if (id == nullptr) {
    rt::throw_exception<ArgumentNullException>("id");
  }
  if (id->get_Length() == 0 || id->get_Length() > 255 || id->Contains(u'\0')) {
    rt::throw_exception<TimeZoneNotFoundException>(SR::Format(SR::get_TimeZoneNotFound_MissingData(), id));
  }
  CachedData cachedData = s_cachedData;
  TimeZoneInfoResult timeZoneInfoResult;
  TimeZoneInfo value;
  Exception e;
  {
    rt::lock(cachedData);
    timeZoneInfoResult = TryGetTimeZone(id, false, value, e, cachedData);
  }
}

TimeSpan TimeZoneInfo___::GetDateTimeNowUtcOffsetFromUtc(DateTime time, Boolean& isAmbiguousLocalDst) {
  isAmbiguousLocalDst = false;
  Int32 year = time.get_Year();
  OffsetAndRule oneYearLocalFromUtc = s_cachedData->GetOneYearLocalFromUtc(year);
  TimeSpan offset = oneYearLocalFromUtc->Offset;
  if (oneYearLocalFromUtc->Rule != nullptr) {
    offset += oneYearLocalFromUtc->Rule->get_BaseUtcOffsetDelta();
    if (oneYearLocalFromUtc->Rule->get_HasDaylightSaving()) {
      Boolean isDaylightSavingsFromUtc = GetIsDaylightSavingsFromUtc(time, year, oneYearLocalFromUtc->Offset, oneYearLocalFromUtc->Rule, nullptr, isAmbiguousLocalDst, get_Local());
      offset += (isDaylightSavingsFromUtc ? oneYearLocalFromUtc->Rule->get_DaylightDelta() : TimeSpan::Zero);
    }
  }
  return offset;
}

Boolean TimeZoneInfo___::TransitionTimeFromTimeZoneInformation(Interop::Kernel32::REG_TZI_FORMAT& timeZoneInformation, TransitionTime& transitionTime, Boolean readStartDate) {
  if (timeZoneInformation.StandardDate.Month == 0) {
    transitionTime = rt::default__;
    return false;
  }
  if (readStartDate) {
    if (timeZoneInformation.DaylightDate.Year == 0) {
      transitionTime = TransitionTime::CreateFloatingDateRule(DateTime(1, 1, 1, timeZoneInformation.DaylightDate.Hour, timeZoneInformation.DaylightDate.Minute, timeZoneInformation.DaylightDate.Second, timeZoneInformation.DaylightDate.Milliseconds), timeZoneInformation.DaylightDate.Month, timeZoneInformation.DaylightDate.Day, (DayOfWeek)timeZoneInformation.DaylightDate.DayOfWeek);
    } else {
      transitionTime = TransitionTime::CreateFixedDateRule(DateTime(1, 1, 1, timeZoneInformation.DaylightDate.Hour, timeZoneInformation.DaylightDate.Minute, timeZoneInformation.DaylightDate.Second, timeZoneInformation.DaylightDate.Milliseconds), timeZoneInformation.DaylightDate.Month, timeZoneInformation.DaylightDate.Day);
    }
  } else if (timeZoneInformation.StandardDate.Year == 0) {
    transitionTime = TransitionTime::CreateFloatingDateRule(DateTime(1, 1, 1, timeZoneInformation.StandardDate.Hour, timeZoneInformation.StandardDate.Minute, timeZoneInformation.StandardDate.Second, timeZoneInformation.StandardDate.Milliseconds), timeZoneInformation.StandardDate.Month, timeZoneInformation.StandardDate.Day, (DayOfWeek)timeZoneInformation.StandardDate.DayOfWeek);
  } else {
    transitionTime = TransitionTime::CreateFixedDateRule(DateTime(1, 1, 1, timeZoneInformation.StandardDate.Hour, timeZoneInformation.StandardDate.Minute, timeZoneInformation.StandardDate.Second, timeZoneInformation.StandardDate.Milliseconds), timeZoneInformation.StandardDate.Month, timeZoneInformation.StandardDate.Day);
  }

  return true;
}

Boolean TimeZoneInfo___::TryCreateAdjustmentRules(String id, Interop::Kernel32::REG_TZI_FORMAT& defaultTimeZoneInformation, Array<AdjustmentRule>& rules, Exception& e, Int32 defaultBaseUtcOffset) {
  rules = nullptr;
  e = nullptr;
  try {
    {
      RegistryKey registryKey = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\" + id + "\\Dynamic DST", false);
      rt::Using(registryKey);
      if (registryKey == nullptr) {
        AdjustmentRule adjustmentRule = CreateAdjustmentRuleFromTimeZoneInformation(defaultTimeZoneInformation, DateTime::MinValue.get_Date(), DateTime::MaxValue.get_Date(), defaultBaseUtcOffset);
        if (adjustmentRule != nullptr) {
          rules = rt::newarr<Array<AdjustmentRule>>(1);
        }
        return true;
      }
      Int32 num = (Int32)registryKey->GetValue("FirstEntry", -1);
      Int32 num2 = (Int32)registryKey->GetValue("LastEntry", -1);
      if (num == -1 || num2 == -1 || num > num2) {
        return false;
      }
      Interop::Kernel32::REG_TZI_FORMAT dtzi;
      if (!TryGetTimeZoneEntryFromRegistry(registryKey, num.ToString(CultureInfo::in::get_InvariantCulture()), dtzi)) {
        return false;
      }
      if (num == num2) {
        AdjustmentRule adjustmentRule2 = CreateAdjustmentRuleFromTimeZoneInformation(dtzi, DateTime::MinValue.get_Date(), DateTime::MaxValue.get_Date(), defaultBaseUtcOffset);
        if (adjustmentRule2 != nullptr) {
          rules = rt::newarr<Array<AdjustmentRule>>(1);
        }
        return true;
      }
      List<AdjustmentRule> list = rt::newobj<List<AdjustmentRule>>(1);
      AdjustmentRule adjustmentRule3 = CreateAdjustmentRuleFromTimeZoneInformation(dtzi, DateTime::MinValue.get_Date(), DateTime(num, 12, 31), defaultBaseUtcOffset);
      if (adjustmentRule3 != nullptr) {
        list->Add(adjustmentRule3);
      }
      for (Int32 i = num + 1; i < num2; i++) {
        if (!TryGetTimeZoneEntryFromRegistry(registryKey, i.ToString(CultureInfo::in::get_InvariantCulture()), dtzi)) {
          return false;
        }
        AdjustmentRule adjustmentRule4 = CreateAdjustmentRuleFromTimeZoneInformation(dtzi, DateTime(i, 1, 1), DateTime(i, 12, 31), defaultBaseUtcOffset);
        if (adjustmentRule4 != nullptr) {
          list->Add(adjustmentRule4);
        }
      }
      if (!TryGetTimeZoneEntryFromRegistry(registryKey, num2.ToString(CultureInfo::in::get_InvariantCulture()), dtzi)) {
        return false;
      }
      AdjustmentRule adjustmentRule5 = CreateAdjustmentRuleFromTimeZoneInformation(dtzi, DateTime(num2, 1, 1), DateTime::MaxValue.get_Date(), defaultBaseUtcOffset);
      if (adjustmentRule5 != nullptr) {
        list->Add(adjustmentRule5);
      }
      if (list->get_Count() != 0) {
        rules = list->ToArray();
      }
    }
  } catch (InvalidCastException ex) {
    InvalidCastException ex2 = (InvalidCastException)(e = ex);
    return false;
  } catch (ArgumentOutOfRangeException ex3) {
    ArgumentOutOfRangeException ex4 = (ArgumentOutOfRangeException)(e = ex3);
    return false;
  } catch (ArgumentException ex5) {
    ArgumentException ex6 = (ArgumentException)(e = ex5);
    return false;
  }
  return true;
}

Boolean TimeZoneInfo___::TryGetTimeZoneEntryFromRegistry(RegistryKey key, String name, Interop::Kernel32::REG_TZI_FORMAT& dtzi) {
  Array<Byte> array = rt::as<Array<Byte>>(key->GetValue(name, nullptr));
  if (array == nullptr || array->get_Length() != sizeof(Interop::Kernel32::REG_TZI_FORMAT)) {
    dtzi = rt::default__;
    return false;
  }
  {
    Byte* ptr = rt::fixed(&array[0]);
    dtzi = *(Interop::Kernel32::REG_TZI_FORMAT*)ptr;
  }
  return true;
}

Boolean TimeZoneInfo___::TryCompareStandardDate(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, Interop::Kernel32::REG_TZI_FORMAT& registryTimeZoneInfo) {
  if (timeZone.Bias == registryTimeZoneInfo.Bias && timeZone.StandardBias == registryTimeZoneInfo.StandardBias) {
    return timeZone.StandardDate.Equals(registryTimeZoneInfo.StandardDate);
  }
  return false;
}

Boolean TimeZoneInfo___::TryCompareTimeZoneInformationToRegistry(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, String id, Boolean& dstDisabled) {
  dstDisabled = false;
  {
    RegistryKey registryKey = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\" + id, false);
    rt::Using(registryKey);
    if (registryKey == nullptr) {
      return false;
    }
    Interop::Kernel32::REG_TZI_FORMAT dtzi;
    if (!TryGetTimeZoneEntryFromRegistry(registryKey, "TZI", dtzi)) {
      return false;
    }
    if (!TryCompareStandardDate(timeZone, dtzi)) {
      return false;
    }
    Boolean flag = dstDisabled || CheckDaylightSavingTimeNotSupported(timeZone) || (timeZone.DaylightBias == dtzi.DaylightBias && timeZone.DaylightDate.Equals(dtzi.DaylightDate));
    if (flag) {
      String a = rt::as<String>(registryKey->GetValue("Std", String::in::Empty));
      flag = String::in::Equals(a, timeZone.GetStandardName(), StringComparison::Ordinal);
    }
    return flag;
  }
}

String TimeZoneInfo___::TryGetLocalizedNameByMuiNativeResource(String resource) {
  if (String::in::IsNullOrEmpty(resource)) {
    return String::in::Empty;
  }
  Array<String> array = resource->Split(u',');
  if (array->get_Length() != 2) {
    return String::in::Empty;
  }
  String systemDirectory = Environment::get_SystemDirectory();
  String path = array[0]->TrimStart(u'@');
  String pcwszFilePath;
  try {
    pcwszFilePath = Path::Combine(systemDirectory, path);
  } catch (ArgumentException) {
    return String::in::Empty;
  }
  Int32 result;
  if (!Int32::TryParse(array[1], NumberStyles::Integer, CultureInfo::in::get_InvariantCulture(), result)) {
    return String::in::Empty;
  }
  result = -result;
  try {
    Char as[260] = {};
    Char* ptr = as;
    Int32 pcchFileMUIPath = 260;
    Int32 pcchLanguage = 0;
    Int64 pululEnumerator = 0;
    return Interop::Kernel32::GetFileMUIPath(16u, pcwszFilePath, nullptr, pcchLanguage, ptr, pcchFileMUIPath, pululEnumerator) ? TryGetLocalizedNameByNativeResource(rt::newstr<String>(ptr, 0, pcchFileMUIPath), result) : String::in::Empty;
  } catch (EntryPointNotFoundException) {
    return String::in::Empty;
  }
}

String TimeZoneInfo___::TryGetLocalizedNameByNativeResource(String filePath, Int32 resource) {
  IntPtr intPtr = IntPtr::Zero;
  try {
    intPtr = Interop::Kernel32::LoadLibraryEx(filePath, IntPtr::Zero, 2);
    if (intPtr != IntPtr::Zero) {
      Char as[500] = {};
      Char* ptr = as;
      Int32 num = Interop::User32::LoadString(intPtr, (UInt32)resource, ptr, 500);
      if (num != 0) {
        return rt::newstr<String>(ptr, 0, num);
      }
    }
  } catch (...) {
  } finally: {
    if (intPtr != IntPtr::Zero) {
      Interop::Kernel32::FreeLibrary(intPtr);
    }
  }
  return String::in::Empty;
}

void TimeZoneInfo___::GetLocalizedNamesByRegistryKey(RegistryKey key, String& displayName, String& standardName, String& daylightName) {
  displayName = String::in::Empty;
  standardName = String::in::Empty;
  daylightName = String::in::Empty;
  String text = rt::as<String>(key->GetValue("MUI_Display", String::in::Empty));
  String text2 = rt::as<String>(key->GetValue("MUI_Std", String::in::Empty));
  String text3 = rt::as<String>(key->GetValue("MUI_Dlt", String::in::Empty));
  if (!String::in::IsNullOrEmpty(text)) {
    displayName = TryGetLocalizedNameByMuiNativeResource(text);
  }
  if (!String::in::IsNullOrEmpty(text2)) {
    standardName = TryGetLocalizedNameByMuiNativeResource(text2);
  }
  if (!String::in::IsNullOrEmpty(text3)) {
    daylightName = TryGetLocalizedNameByMuiNativeResource(text3);
  }
  if (String::in::IsNullOrEmpty(displayName)) {
    displayName = rt::as<String>(key->GetValue("Display", String::in::Empty));
  }
  if (String::in::IsNullOrEmpty(standardName)) {
    standardName = rt::as<String>(key->GetValue("Std", String::in::Empty));
  }
  if (String::in::IsNullOrEmpty(daylightName)) {
    daylightName = rt::as<String>(key->GetValue("Dlt", String::in::Empty));
  }
}

TimeZoneInfo::in::TimeZoneInfoResult TimeZoneInfo___::TryGetTimeZoneFromLocalMachine(String id, TimeZoneInfo& value, Exception& e) {
  e = nullptr;
  {
    RegistryKey registryKey = Registry::LocalMachine->OpenSubKey("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\" + id, false);
    rt::Using(registryKey);
    if (registryKey == nullptr) {
      value = nullptr;
      return TimeZoneInfoResult::TimeZoneNotFoundException;
    }
    Interop::Kernel32::REG_TZI_FORMAT dtzi;
    if (!TryGetTimeZoneEntryFromRegistry(registryKey, "TZI", dtzi)) {
      value = nullptr;
      return TimeZoneInfoResult::InvalidTimeZoneException;
    }
    Array<AdjustmentRule> rules;
    if (!TryCreateAdjustmentRules(id, dtzi, rules, e, dtzi.Bias)) {
      value = nullptr;
      return TimeZoneInfoResult::InvalidTimeZoneException;
    }
    String displayName;
    String standardName;
    String daylightName;
    GetLocalizedNamesByRegistryKey(registryKey, displayName, standardName, daylightName);
    try {
      value = rt::newobj<TimeZoneInfo>(id, TimeSpan(0, -dtzi.Bias, 0), displayName, standardName, daylightName, rules, false);
      return TimeZoneInfoResult::Success;
    } catch (ArgumentException ex) {
      value = nullptr;
      e = ex;
      return TimeZoneInfoResult::InvalidTimeZoneException;
    } catch (InvalidTimeZoneException ex2) {
      value = nullptr;
      e = ex2;
      return TimeZoneInfoResult::InvalidTimeZoneException;
    }
  }
}

void TimeZoneInfo___::cctor() {
  s_utcTimeZone = CreateCustomTimeZone("UTC", TimeSpan::Zero, "(UTC) Coordinated Universal Time", "Coordinated Universal Time");
  s_cachedData = rt::newobj<CachedData>();
  s_maxDateOnly = DateTime(9999, 12, 31);
  s_minDateOnly = DateTime(1, 1, 2);
  MaxOffset = TimeSpan::FromHours(14);
  MinOffset = -MaxOffset;
}

} // namespace System::Private::CoreLib::System::TimeZoneInfoNamespace
