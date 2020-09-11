#include "DateTimeFormatInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatFlags.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfoScanner-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumber-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumberParsingContext-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumberParsingState.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/NumberFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/TaiwanCalendar-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoNamespace {
using namespace System::Collections::Generic;

void DateTimeFormatInfo___::TokenHashValue___::ctor(String tokenString, TokenType tokenType, Int32 tokenValue) {
  this->tokenString = tokenString;
  this->tokenType = tokenType;
  this->tokenValue = tokenValue;
}

String DateTimeFormatInfo___::get_CultureName() {
  String as = _name;
  return as != nullptr ? as : (_name = _cultureData->get_CultureName());
}

CultureInfo DateTimeFormatInfo___::get_Culture() {
  CultureInfo as = _cultureInfo;
  return as != nullptr ? as : (_cultureInfo = CultureInfo::in::GetCultureInfo(get_CultureName()));
}

String DateTimeFormatInfo___::get_LanguageName() {
  String as = _langName;
  return as != nullptr ? as : (_langName = _cultureData->get_TwoLetterISOLanguageName());
}

DateTimeFormatInfo DateTimeFormatInfo___::get_InvariantInfo() {
  if (s_invariantInfo == nullptr) {
    DateTimeFormatInfo dateTimeFormatInfo = rt::newobj<DateTimeFormatInfo>();
    dateTimeFormatInfo->get_Calendar()->SetReadOnlyState(true);
    dateTimeFormatInfo->_isReadOnly = true;
    s_invariantInfo = dateTimeFormatInfo;
  }
  return s_invariantInfo;
}

DateTimeFormatInfo DateTimeFormatInfo___::get_CurrentInfo() {
  CultureInfo currentCulture = CultureInfo::in::get_CurrentCulture();
  if (!currentCulture->_isInherited) {
    DateTimeFormatInfo dateTimeInfo = currentCulture->_dateTimeInfo;
    if (dateTimeInfo != nullptr) {
      return dateTimeInfo;
    }
  }
  return (DateTimeFormatInfo)currentCulture->GetFormat(typeof<DateTimeFormatInfo>());
}

String DateTimeFormatInfo___::get_AMDesignator() {
  if (amDesignator == nullptr) {
    amDesignator = _cultureData->get_AMDesignator();
  }
  return amDesignator;
}

void DateTimeFormatInfo___::set_AMDesignator(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  ClearTokenHashTable();
  amDesignator = value;
}

Calendar DateTimeFormatInfo___::get_Calendar() {
  return calendar;
}

void DateTimeFormatInfo___::set_Calendar(Calendar value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value == calendar) {
    return;
  }
  for (Int32 i = 0; i < get_OptionalCalendars()->get_Length(); i++) {
    if (get_OptionalCalendars()[i] == value->get_ID()) {
      if (calendar != nullptr) {
        m_eraNames = nullptr;
        m_abbrevEraNames = nullptr;
        m_abbrevEnglishEraNames = nullptr;
        monthDayPattern = nullptr;
        dayNames = nullptr;
        abbreviatedDayNames = nullptr;
        m_superShortDayNames = nullptr;
        monthNames = nullptr;
        abbreviatedMonthNames = nullptr;
        genitiveMonthNames = nullptr;
        m_genitiveAbbreviatedMonthNames = nullptr;
        leapYearMonthNames = nullptr;
        formatFlags = DateTimeFormatFlags::NotInitialized;
        allShortDatePatterns = nullptr;
        allLongDatePatterns = nullptr;
        allYearMonthPatterns = nullptr;
        dateTimeOffsetPattern = nullptr;
        longDatePattern = nullptr;
        shortDatePattern = nullptr;
        yearMonthPattern = nullptr;
        fullDateTimePattern = nullptr;
        generalShortTimePattern = nullptr;
        generalLongTimePattern = nullptr;
        dateSeparator = nullptr;
        ClearTokenHashTable();
      }
      calendar = value;
      InitializeOverridableProperties(_cultureData, calendar->get_ID());
      return;
    }
  }
  rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::get_Argument_InvalidCalendar());
}

Array<CalendarId> DateTimeFormatInfo___::get_OptionalCalendars() {
  Array<CalendarId> as = optionalCalendars;
  return as != nullptr ? as : (optionalCalendars = _cultureData->get_CalendarIds());
}

Array<String> DateTimeFormatInfo___::get_EraNames() {
  Array<String> as = m_eraNames;
  return as != nullptr ? as : (m_eraNames = _cultureData->EraNames(get_Calendar()->get_ID()));
}

Array<String> DateTimeFormatInfo___::get_AbbreviatedEraNames() {
  Array<String> as = m_abbrevEraNames;
  return as != nullptr ? as : (m_abbrevEraNames = _cultureData->AbbrevEraNames(get_Calendar()->get_ID()));
}

Array<String> DateTimeFormatInfo___::get_AbbreviatedEnglishEraNames() {
  if (m_abbrevEnglishEraNames == nullptr) {
    m_abbrevEnglishEraNames = _cultureData->AbbreviatedEnglishEraNames(get_Calendar()->get_ID());
  }
  return m_abbrevEnglishEraNames;
}

String DateTimeFormatInfo___::get_DateSeparator() {
  if (dateSeparator == nullptr) {
    dateSeparator = _cultureData->DateSeparator(get_Calendar()->get_ID());
  }
  return dateSeparator;
}

void DateTimeFormatInfo___::set_DateSeparator(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  ClearTokenHashTable();
  dateSeparator = value;
}

DayOfWeek DateTimeFormatInfo___::get_FirstDayOfWeek() {
  if (firstDayOfWeek == -1) {
    firstDayOfWeek = _cultureData->get_FirstDayOfWeek();
  }
  return (DayOfWeek)firstDayOfWeek;
}

void DateTimeFormatInfo___::set_FirstDayOfWeek(DayOfWeek value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value < DayOfWeek::Sunday || value > DayOfWeek::Saturday) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), DayOfWeek::Sunday, DayOfWeek::Saturday));
  }
  firstDayOfWeek = (Int32)value;
}

CalendarWeekRule DateTimeFormatInfo___::get_CalendarWeekRule() {
  if (calendarWeekRule == -1) {
    calendarWeekRule = _cultureData->get_CalendarWeekRule();
  }
  return (CalendarWeekRule)calendarWeekRule;
}

void DateTimeFormatInfo___::set_CalendarWeekRule(CalendarWeekRule value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value < CalendarWeekRule::FirstDay || value > CalendarWeekRule::FirstFourDayWeek) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", value, SR::Format(SR::get_ArgumentOutOfRange_Range(), CalendarWeekRule::FirstDay, CalendarWeekRule::FirstFourDayWeek));
  }
  calendarWeekRule = (Int32)value;
}

String DateTimeFormatInfo___::get_FullDateTimePattern() {
  String as = fullDateTimePattern;
  return as != nullptr ? as : (fullDateTimePattern = get_LongDatePattern() + " " + get_LongTimePattern());
}

void DateTimeFormatInfo___::set_FullDateTimePattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  fullDateTimePattern = value;
}

String DateTimeFormatInfo___::get_LongDatePattern() {
  String as = longDatePattern;
  return as != nullptr ? as : (longDatePattern = get_UnclonedLongDatePatterns()[0]);
}

void DateTimeFormatInfo___::set_LongDatePattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  longDatePattern = value;
  OnLongDatePatternChanged();
}

String DateTimeFormatInfo___::get_LongTimePattern() {
  String as = longTimePattern;
  return as != nullptr ? as : (longTimePattern = get_UnclonedLongTimePatterns()[0]);
}

void DateTimeFormatInfo___::set_LongTimePattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  longTimePattern = value;
  OnLongTimePatternChanged();
}

String DateTimeFormatInfo___::get_MonthDayPattern() {
  if (monthDayPattern == nullptr) {
    monthDayPattern = _cultureData->MonthDay(get_Calendar()->get_ID());
  }
  return monthDayPattern;
}

void DateTimeFormatInfo___::set_MonthDayPattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  monthDayPattern = value;
}

String DateTimeFormatInfo___::get_PMDesignator() {
  if (pmDesignator == nullptr) {
    pmDesignator = _cultureData->get_PMDesignator();
  }
  return pmDesignator;
}

void DateTimeFormatInfo___::set_PMDesignator(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  ClearTokenHashTable();
  pmDesignator = value;
}

String DateTimeFormatInfo___::get_RFC1123Pattern() {
  return "ddd, dd MMM yyyy HH':'mm':'ss 'GMT'";
}

String DateTimeFormatInfo___::get_ShortDatePattern() {
  String as = shortDatePattern;
  return as != nullptr ? as : (shortDatePattern = get_UnclonedShortDatePatterns()[0]);
}

void DateTimeFormatInfo___::set_ShortDatePattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  shortDatePattern = value;
  OnShortDatePatternChanged();
}

String DateTimeFormatInfo___::get_ShortTimePattern() {
  String as = shortTimePattern;
  return as != nullptr ? as : (shortTimePattern = get_UnclonedShortTimePatterns()[0]);
}

void DateTimeFormatInfo___::set_ShortTimePattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  shortTimePattern = value;
  OnShortTimePatternChanged();
}

String DateTimeFormatInfo___::get_SortableDateTimePattern() {
  return "yyyy'-'MM'-'dd'T'HH':'mm':'ss";
}

String DateTimeFormatInfo___::get_GeneralShortTimePattern() {
  String as = generalShortTimePattern;
  return as != nullptr ? as : (generalShortTimePattern = get_ShortDatePattern() + " " + get_ShortTimePattern());
}

String DateTimeFormatInfo___::get_GeneralLongTimePattern() {
  String as = generalLongTimePattern;
  return as != nullptr ? as : (generalLongTimePattern = get_ShortDatePattern() + " " + get_LongTimePattern());
}

String DateTimeFormatInfo___::get_DateTimeOffsetPattern() {
  if (dateTimeOffsetPattern == nullptr) {
    Boolean flag = false;
    Boolean flag2 = false;
    Char c = '\'';
    Int32 num = 0;
    while (!flag && num < get_LongTimePattern()->get_Length()) {
      switch (get_LongTimePattern()[num].get()) {
        case 'z':
          flag = !flag2;
          break;
        case '"':
        case '\'':
          if (flag2 && c == get_LongTimePattern()[num]) {
            flag2 = false;
          } else if (!flag2) {
            c = get_LongTimePattern()[num];
            flag2 = true;
          }

          break;
        case '%':
        case '\\':
          num++;
          break;
      }
      num++;
    }
    dateTimeOffsetPattern = (flag ? (get_ShortDatePattern() + " " + get_LongTimePattern()) : (get_ShortDatePattern() + " " + get_LongTimePattern() + " zzz"));
  }
  return dateTimeOffsetPattern;
}

String DateTimeFormatInfo___::get_TimeSeparator() {
  if (timeSeparator == nullptr) {
    timeSeparator = _cultureData->get_TimeSeparator();
  }
  return timeSeparator;
}

void DateTimeFormatInfo___::set_TimeSeparator(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  ClearTokenHashTable();
  timeSeparator = value;
}

String DateTimeFormatInfo___::get_UniversalSortableDateTimePattern() {
  return "yyyy'-'MM'-'dd HH':'mm':'ss'Z'";
}

String DateTimeFormatInfo___::get_YearMonthPattern() {
  String as = yearMonthPattern;
  return as != nullptr ? as : (yearMonthPattern = get_UnclonedYearMonthPatterns()[0]);
}

void DateTimeFormatInfo___::set_YearMonthPattern(String value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  yearMonthPattern = value;
  OnYearMonthPatternChanged();
}

Array<String> DateTimeFormatInfo___::get_AbbreviatedDayNames() {
  return (Array<String>)InternalGetAbbreviatedDayOfWeekNames()->Clone();
}

void DateTimeFormatInfo___::set_AbbreviatedDayNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 7) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 7), "value");
  }
  CheckNullValue(value, value->get_Length());
  ClearTokenHashTable();
  abbreviatedDayNames = value;
}

Array<String> DateTimeFormatInfo___::get_ShortestDayNames() {
  return (Array<String>)InternalGetSuperShortDayNames()->Clone();
}

void DateTimeFormatInfo___::set_ShortestDayNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 7) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 7), "value");
  }
  CheckNullValue(value, value->get_Length());
  m_superShortDayNames = value;
}

Array<String> DateTimeFormatInfo___::get_DayNames() {
  return (Array<String>)InternalGetDayOfWeekNames()->Clone();
}

void DateTimeFormatInfo___::set_DayNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 7) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 7), "value");
  }
  CheckNullValue(value, value->get_Length());
  ClearTokenHashTable();
  dayNames = value;
}

Array<String> DateTimeFormatInfo___::get_AbbreviatedMonthNames() {
  return (Array<String>)InternalGetAbbreviatedMonthNames()->Clone();
}

void DateTimeFormatInfo___::set_AbbreviatedMonthNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 13) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 13), "value");
  }
  CheckNullValue(value, value->get_Length() - 1);
  ClearTokenHashTable();
  abbreviatedMonthNames = value;
}

Array<String> DateTimeFormatInfo___::get_MonthNames() {
  return (Array<String>)InternalGetMonthNames()->Clone();
}

void DateTimeFormatInfo___::set_MonthNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 13) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 13), "value");
  }
  CheckNullValue(value, value->get_Length() - 1);
  monthNames = value;
  ClearTokenHashTable();
}

Boolean DateTimeFormatInfo___::get_HasSpacesInMonthNames() {
  return (get_FormatFlags() & DateTimeFormatFlags::UseSpacesInMonthNames) != 0;
}

Boolean DateTimeFormatInfo___::get_HasSpacesInDayNames() {
  return (get_FormatFlags() & DateTimeFormatFlags::UseSpacesInDayNames) != 0;
}

Array<String> DateTimeFormatInfo___::get_AllYearMonthPatterns() {
  return GetMergedPatterns(get_UnclonedYearMonthPatterns(), get_YearMonthPattern());
}

Array<String> DateTimeFormatInfo___::get_AllShortDatePatterns() {
  return GetMergedPatterns(get_UnclonedShortDatePatterns(), get_ShortDatePattern());
}

Array<String> DateTimeFormatInfo___::get_AllShortTimePatterns() {
  return GetMergedPatterns(get_UnclonedShortTimePatterns(), get_ShortTimePattern());
}

Array<String> DateTimeFormatInfo___::get_AllLongDatePatterns() {
  return GetMergedPatterns(get_UnclonedLongDatePatterns(), get_LongDatePattern());
}

Array<String> DateTimeFormatInfo___::get_AllLongTimePatterns() {
  return GetMergedPatterns(get_UnclonedLongTimePatterns(), get_LongTimePattern());
}

Array<String> DateTimeFormatInfo___::get_UnclonedYearMonthPatterns() {
  if (allYearMonthPatterns == nullptr) {
    allYearMonthPatterns = _cultureData->YearMonths(get_Calendar()->get_ID());
  }
  return allYearMonthPatterns;
}

Array<String> DateTimeFormatInfo___::get_UnclonedShortDatePatterns() {
  if (allShortDatePatterns == nullptr) {
    allShortDatePatterns = _cultureData->ShortDates(get_Calendar()->get_ID());
  }
  return allShortDatePatterns;
}

Array<String> DateTimeFormatInfo___::get_UnclonedLongDatePatterns() {
  if (allLongDatePatterns == nullptr) {
    allLongDatePatterns = _cultureData->LongDates(get_Calendar()->get_ID());
  }
  return allLongDatePatterns;
}

Array<String> DateTimeFormatInfo___::get_UnclonedShortTimePatterns() {
  if (allShortTimePatterns == nullptr) {
    allShortTimePatterns = _cultureData->get_ShortTimes();
  }
  return allShortTimePatterns;
}

Array<String> DateTimeFormatInfo___::get_UnclonedLongTimePatterns() {
  if (allLongTimePatterns == nullptr) {
    allLongTimePatterns = _cultureData->get_LongTimes();
  }
  return allLongTimePatterns;
}

Boolean DateTimeFormatInfo___::get_IsReadOnly() {
  return _isReadOnly;
}

String DateTimeFormatInfo___::get_NativeCalendarName() {
  return _cultureData->CalendarName(get_Calendar()->get_ID());
}

Array<String> DateTimeFormatInfo___::get_AbbreviatedMonthGenitiveNames() {
  return (Array<String>)InternalGetGenitiveMonthNames(true)->Clone();
}

void DateTimeFormatInfo___::set_AbbreviatedMonthGenitiveNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 13) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 13), "value");
  }
  CheckNullValue(value, value->get_Length() - 1);
  ClearTokenHashTable();
  m_genitiveAbbreviatedMonthNames = value;
}

Array<String> DateTimeFormatInfo___::get_MonthGenitiveNames() {
  return (Array<String>)InternalGetGenitiveMonthNames(false)->Clone();
}

void DateTimeFormatInfo___::set_MonthGenitiveNames(Array<String> value) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (value->get_Length() != 13) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidArrayLength(), 13), "value");
  }
  CheckNullValue(value, value->get_Length() - 1);
  genitiveMonthNames = value;
  ClearTokenHashTable();
}

String DateTimeFormatInfo___::get_DecimalSeparator() {
  String as = _decimalSeparator;
  return as != nullptr ? as : (_decimalSeparator = rt::newobj<NumberFormatInfo>(_cultureData->get_UseUserOverride() ? CultureData::in::GetCultureData(_cultureData->get_CultureName(), false) : _cultureData)->set_NumberDecimalSeparator());
}

String DateTimeFormatInfo___::get_FullTimeSpanPositivePattern() {
  String as = _fullTimeSpanPositivePattern;
  return as != nullptr ? as : (_fullTimeSpanPositivePattern = "d':'h':'mm':'ss'" + get_DecimalSeparator() + "'FFFFFFF");
}

String DateTimeFormatInfo___::get_FullTimeSpanNegativePattern() {
  String as = _fullTimeSpanNegativePattern;
  return as != nullptr ? as : (_fullTimeSpanNegativePattern = "'-'" + get_FullTimeSpanPositivePattern());
}

CompareInfo DateTimeFormatInfo___::get_CompareInfo() {
  CompareInfo as = _compareInfo;
  return as != nullptr ? as : (_compareInfo = CompareInfo::in::GetCompareInfo(_cultureData->get_SortName()));
}

DateTimeFormatFlags DateTimeFormatInfo___::get_FormatFlags() {
  if (formatFlags == DateTimeFormatFlags::NotInitialized) {
    return InitializeFormatFlags();
  }
  return formatFlags;
}

Boolean DateTimeFormatInfo___::get_HasForceTwoDigitYears() {
  CalendarId iD = calendar->get_ID();
  if (iD - 3 <= CalendarId::GREGORIAN) {
    return true;
  }
  return false;
}

Boolean DateTimeFormatInfo___::get_HasYearMonthAdjustment() {
  return (get_FormatFlags() & DateTimeFormatFlags::UseHebrewRule) != 0;
}

Array<String> DateTimeFormatInfo___::InternalGetAbbreviatedDayOfWeekNames() {
  Array<String> as = abbreviatedDayNames;
  return as != nullptr ? as : InternalGetAbbreviatedDayOfWeekNamesCore();
}

Array<String> DateTimeFormatInfo___::InternalGetAbbreviatedDayOfWeekNamesCore() {
  abbreviatedDayNames = _cultureData->AbbreviatedDayNames(get_Calendar()->get_ID());
  return abbreviatedDayNames;
}

Array<String> DateTimeFormatInfo___::InternalGetSuperShortDayNames() {
  Array<String> as = m_superShortDayNames;
  return as != nullptr ? as : InternalGetSuperShortDayNamesCore();
}

Array<String> DateTimeFormatInfo___::InternalGetSuperShortDayNamesCore() {
  m_superShortDayNames = _cultureData->SuperShortDayNames(get_Calendar()->get_ID());
  return m_superShortDayNames;
}

Array<String> DateTimeFormatInfo___::InternalGetDayOfWeekNames() {
  Array<String> as = dayNames;
  return as != nullptr ? as : InternalGetDayOfWeekNamesCore();
}

Array<String> DateTimeFormatInfo___::InternalGetDayOfWeekNamesCore() {
  dayNames = _cultureData->DayNames(get_Calendar()->get_ID());
  return dayNames;
}

Array<String> DateTimeFormatInfo___::InternalGetAbbreviatedMonthNames() {
  Array<String> as = abbreviatedMonthNames;
  return as != nullptr ? as : InternalGetAbbreviatedMonthNamesCore();
}

Array<String> DateTimeFormatInfo___::InternalGetAbbreviatedMonthNamesCore() {
  abbreviatedMonthNames = _cultureData->AbbreviatedMonthNames(get_Calendar()->get_ID());
  return abbreviatedMonthNames;
}

Array<String> DateTimeFormatInfo___::InternalGetMonthNames() {
  Array<String> as = monthNames;
  return as != nullptr ? as : internalGetMonthNamesCore();
}

Array<String> DateTimeFormatInfo___::internalGetMonthNamesCore() {
  monthNames = _cultureData->MonthNames(get_Calendar()->get_ID());
  return monthNames;
}

void DateTimeFormatInfo___::ctor() {
}

void DateTimeFormatInfo___::ctor(CultureData cultureData, Calendar cal) {
  firstDayOfWeek = -1;
  calendarWeekRule = -1;
  formatFlags = DateTimeFormatFlags::NotInitialized;
  Object::in::ctor();
  _cultureData = cultureData;
  calendar = cal;
  InitializeOverridableProperties(cultureData, calendar->get_ID());
}

void DateTimeFormatInfo___::InitializeOverridableProperties(CultureData cultureData, CalendarId calendarId) {
  if (firstDayOfWeek == -1) {
    firstDayOfWeek = cultureData->get_FirstDayOfWeek();
  }
  if (calendarWeekRule == -1) {
    calendarWeekRule = cultureData->get_CalendarWeekRule();
  }
  if (amDesignator == nullptr) {
    amDesignator = cultureData->get_AMDesignator();
  }
  if (pmDesignator == nullptr) {
    pmDesignator = cultureData->get_PMDesignator();
  }
  if (timeSeparator == nullptr) {
    timeSeparator = cultureData->get_TimeSeparator();
  }
  if (dateSeparator == nullptr) {
    dateSeparator = cultureData->DateSeparator(calendarId);
  }
  allLongTimePatterns = _cultureData->get_LongTimes();
  allShortTimePatterns = _cultureData->get_ShortTimes();
  allLongDatePatterns = cultureData->LongDates(calendarId);
  allShortDatePatterns = cultureData->ShortDates(calendarId);
  allYearMonthPatterns = cultureData->YearMonths(calendarId);
}

DateTimeFormatInfo DateTimeFormatInfo___::GetInstance(IFormatProvider provider) {
  if (provider != nullptr) {
    CultureInfo cultureInfo = rt::as<CultureInfo>(provider);
    if (cultureInfo == nullptr || cultureInfo->_isInherited) {
      DateTimeFormatInfo dateTimeFormatInfo = rt::as<DateTimeFormatInfo>(provider);
      if (dateTimeFormatInfo == nullptr) {
        DateTimeFormatInfo dateTimeFormatInfo2 = rt::as<DateTimeFormatInfo>(provider->GetFormat(typeof<DateTimeFormatInfo>()));
        if (dateTimeFormatInfo2 == nullptr) {
          return get_CurrentInfo();
        }
        return dateTimeFormatInfo2;
      }
      return dateTimeFormatInfo;
    }
    return cultureInfo->get_DateTimeFormat();
  }
  return get_CurrentInfo();
}

Object DateTimeFormatInfo___::GetFormat(Type formatType) {
  if (!(formatType == typeof<DateTimeFormatInfo>())) {
    return nullptr;
  }
  return (DateTimeFormatInfo)this;
}

Object DateTimeFormatInfo___::Clone() {
  DateTimeFormatInfo dateTimeFormatInfo = (DateTimeFormatInfo)MemberwiseClone();
  dateTimeFormatInfo->calendar = (Calendar)get_Calendar()->Clone();
  dateTimeFormatInfo->_isReadOnly = false;
  return dateTimeFormatInfo;
}

Int32 DateTimeFormatInfo___::GetEra(String eraName) {
  if (eraName == nullptr) {
    rt::throw_exception<ArgumentNullException>("eraName");
  }
  if (eraName->get_Length() == 0) {
    return -1;
  }
  for (Int32 i = 0; i < get_EraNames()->get_Length(); i++) {
    if (m_eraNames[i]->get_Length() > 0 && get_Culture()->get_CompareInfo()->Compare(eraName, m_eraNames[i], CompareOptions::IgnoreCase) == 0) {
      return i + 1;
    }
  }
  for (Int32 j = 0; j < get_AbbreviatedEraNames()->get_Length(); j++) {
    if (get_Culture()->get_CompareInfo()->Compare(eraName, m_abbrevEraNames[j], CompareOptions::IgnoreCase) == 0) {
      return j + 1;
    }
  }
  for (Int32 k = 0; k < get_AbbreviatedEnglishEraNames()->get_Length(); k++) {
    if (CompareInfo::in::Invariant->Compare(eraName, m_abbrevEnglishEraNames[k], CompareOptions::IgnoreCase) == 0) {
      return k + 1;
    }
  }
  return -1;
}

String DateTimeFormatInfo___::GetEraName(Int32 era) {
  if (era == 0) {
    era = get_Calendar()->get_CurrentEraValue();
  }
  if (--era < get_EraNames()->get_Length() && era >= 0) {
    return m_eraNames[era];
  }
  rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
}

String DateTimeFormatInfo___::GetAbbreviatedEraName(Int32 era) {
  if (get_AbbreviatedEraNames()->get_Length() == 0) {
    return GetEraName(era);
  }
  if (era == 0) {
    era = get_Calendar()->get_CurrentEraValue();
  }
  if (--era < m_abbrevEraNames->get_Length() && era >= 0) {
    return m_abbrevEraNames[era];
  }
  rt::throw_exception<ArgumentOutOfRangeException>("era", era, SR::get_ArgumentOutOfRange_InvalidEraValue());
}

void DateTimeFormatInfo___::OnLongDatePatternChanged() {
  ClearTokenHashTable();
  fullDateTimePattern = nullptr;
}

void DateTimeFormatInfo___::OnLongTimePatternChanged() {
  ClearTokenHashTable();
  fullDateTimePattern = nullptr;
  generalLongTimePattern = nullptr;
  dateTimeOffsetPattern = nullptr;
}

void DateTimeFormatInfo___::OnShortDatePatternChanged() {
  ClearTokenHashTable();
  generalLongTimePattern = nullptr;
  generalShortTimePattern = nullptr;
  dateTimeOffsetPattern = nullptr;
}

void DateTimeFormatInfo___::OnShortTimePatternChanged() {
  ClearTokenHashTable();
  generalShortTimePattern = nullptr;
}

void DateTimeFormatInfo___::OnYearMonthPatternChanged() {
  ClearTokenHashTable();
}

void DateTimeFormatInfo___::CheckNullValue(Array<String> values, Int32 length) {
  for (Int32 i = 0; i < length; i++) {
    if (values[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("value", SR::get_ArgumentNull_ArrayValue());
    }
  }
}

String DateTimeFormatInfo___::InternalGetMonthName(Int32 month, MonthNameStyles style, Boolean abbreviated) {
  Array<String> array;
  switch (style) {
    case MonthNameStyles::Genitive:
      array = InternalGetGenitiveMonthNames(abbreviated);
      break;
    case MonthNameStyles::LeapYear:
      array = InternalGetLeapYearMonthNames();
      break;
    default:
      array = (abbreviated ? InternalGetAbbreviatedMonthNames() : InternalGetMonthNames());
      break;
  }
  Array<String> array2 = array;
  if (month < 1 || month > array2->get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, array2->get_Length()));
  }
  return array2[month - 1];
}

Array<String> DateTimeFormatInfo___::InternalGetGenitiveMonthNames(Boolean abbreviated) {
  if (abbreviated) {
    if (m_genitiveAbbreviatedMonthNames == nullptr) {
      m_genitiveAbbreviatedMonthNames = _cultureData->AbbreviatedGenitiveMonthNames(get_Calendar()->get_ID());
    }
    return m_genitiveAbbreviatedMonthNames;
  }
  if (genitiveMonthNames == nullptr) {
    genitiveMonthNames = _cultureData->GenitiveMonthNames(get_Calendar()->get_ID());
  }
  return genitiveMonthNames;
}

Array<String> DateTimeFormatInfo___::InternalGetLeapYearMonthNames() {
  if (leapYearMonthNames == nullptr) {
    leapYearMonthNames = _cultureData->LeapYearMonthNames(get_Calendar()->get_ID());
  }
  return leapYearMonthNames;
}

String DateTimeFormatInfo___::GetAbbreviatedDayName(DayOfWeek dayofweek) {
  if (dayofweek < DayOfWeek::Sunday || dayofweek > DayOfWeek::Saturday) {
    rt::throw_exception<ArgumentOutOfRangeException>("dayofweek", dayofweek, SR::Format(SR::get_ArgumentOutOfRange_Range(), DayOfWeek::Sunday, DayOfWeek::Saturday));
  }
  return InternalGetAbbreviatedDayOfWeekNames()[(Int32)dayofweek];
}

String DateTimeFormatInfo___::GetShortestDayName(DayOfWeek dayOfWeek) {
  if (dayOfWeek < DayOfWeek::Sunday || dayOfWeek > DayOfWeek::Saturday) {
    rt::throw_exception<ArgumentOutOfRangeException>("dayOfWeek", dayOfWeek, SR::Format(SR::get_ArgumentOutOfRange_Range(), DayOfWeek::Sunday, DayOfWeek::Saturday));
  }
  return InternalGetSuperShortDayNames()[(Int32)dayOfWeek];
}

Array<String> DateTimeFormatInfo___::GetCombinedPatterns(Array<String> patterns1, Array<String> patterns2, String connectString) {
  Array<String> array = rt::newarr<Array<String>>(patterns1->get_Length() * patterns2->get_Length());
  Int32 num = 0;
  for (Int32 i = 0; i < patterns1->get_Length(); i++) {
    for (Int32 j = 0; j < patterns2->get_Length(); j++) {
      array[num++] = patterns1[i] + connectString + patterns2[j];
    }
  }
  return array;
}

Array<String> DateTimeFormatInfo___::GetAllDateTimePatterns() {
  List<String> list = rt::newobj<List<String>>(132);
  for (Int32 i = 0; i < DateTimeFormat::allStandardFormats->get_Length(); i++) {
    Array<String> allDateTimePatterns = GetAllDateTimePatterns(DateTimeFormat::allStandardFormats[i]);
    for (Int32 j = 0; j < allDateTimePatterns->get_Length(); j++) {
      list->Add(allDateTimePatterns[j]);
    }
  }
  return list->ToArray();
}

Array<String> DateTimeFormatInfo___::GetAllDateTimePatterns(Char format) {
  switch (format.get()) {
    case 'd':
      return get_AllShortDatePatterns();
    case 'D':
      return get_AllLongDatePatterns();
    case 'f':
      return GetCombinedPatterns(get_AllLongDatePatterns(), get_AllShortTimePatterns(), " ");
    case 'F':
    case 'U':
      return GetCombinedPatterns(get_AllLongDatePatterns(), get_AllLongTimePatterns(), " ");
    case 'g':
      return GetCombinedPatterns(get_AllShortDatePatterns(), get_AllShortTimePatterns(), " ");
    case 'G':
      return GetCombinedPatterns(get_AllShortDatePatterns(), get_AllLongTimePatterns(), " ");
    case 'M':
    case 'm':
      return rt::newarr<Array<String>>(1);
    case 'O':
    case 'o':
      return rt::newarr<Array<String>>(1);
    case 'R':
    case 'r':
      return rt::newarr<Array<String>>(1);
    case 's':
      return rt::newarr<Array<String>>(1);
    case 't':
      return get_AllShortTimePatterns();
    case 'T':
      return get_AllLongTimePatterns();
    case 'u':
      return rt::newarr<Array<String>>(1);
    case 'Y':
    case 'y':
      return get_AllYearMonthPatterns();
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Format_BadFormatSpecifier(), format), "format");
  }
}

String DateTimeFormatInfo___::GetDayName(DayOfWeek dayofweek) {
  if (dayofweek < DayOfWeek::Sunday || dayofweek > DayOfWeek::Saturday) {
    rt::throw_exception<ArgumentOutOfRangeException>("dayofweek", dayofweek, SR::Format(SR::get_ArgumentOutOfRange_Range(), DayOfWeek::Sunday, DayOfWeek::Saturday));
  }
  return InternalGetDayOfWeekNames()[(Int32)dayofweek];
}

String DateTimeFormatInfo___::GetAbbreviatedMonthName(Int32 month) {
  if (month < 1 || month > 13) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 13));
  }
  return InternalGetAbbreviatedMonthNames()[month - 1];
}

String DateTimeFormatInfo___::GetMonthName(Int32 month) {
  if (month < 1 || month > 13) {
    rt::throw_exception<ArgumentOutOfRangeException>("month", month, SR::Format(SR::get_ArgumentOutOfRange_Range(), 1, 13));
  }
  return InternalGetMonthNames()[month - 1];
}

Array<String> DateTimeFormatInfo___::GetMergedPatterns(Array<String> patterns, String defaultPattern) {
  if (defaultPattern == patterns[0]) {
    return (Array<String>)patterns->Clone();
  }
  Int32 i;
  for (i = 0; i < patterns->get_Length() && !(defaultPattern == patterns[i]); i++) {
  }
  Array<String> array;
  if (i < patterns->get_Length()) {
    array = (Array<String>)patterns->Clone();
    array[i] = array[0];
  } else {
    array = rt::newarr<Array<String>>(patterns->get_Length() + 1);
    Array<>::in::Copy(patterns, 0, array, 1, patterns->get_Length());
  }
  array[0] = defaultPattern;
  return array;
}

DateTimeFormatInfo DateTimeFormatInfo___::ReadOnly(DateTimeFormatInfo dtfi) {
  if (dtfi == nullptr) {
    rt::throw_exception<ArgumentNullException>("dtfi");
  }
  if (dtfi->get_IsReadOnly()) {
    return dtfi;
  }
  DateTimeFormatInfo dateTimeFormatInfo = (DateTimeFormatInfo)dtfi->MemberwiseClone();
  dateTimeFormatInfo->calendar = Calendar::in::ReadOnly(dtfi->get_Calendar());
  dateTimeFormatInfo->_isReadOnly = true;
  return dateTimeFormatInfo;
}

void DateTimeFormatInfo___::SetAllDateTimePatterns(Array<String> patterns, Char format) {
  if (get_IsReadOnly()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
  if (patterns == nullptr) {
    rt::throw_exception<ArgumentNullException>("patterns");
  }
  if (patterns->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_ArrayZeroError(), "patterns");
  }
  for (Int32 i = 0; i < patterns->get_Length(); i++) {
    if (patterns[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("patterns[" + i + "]", SR::get_ArgumentNull_ArrayValue());
    }
  }
  switch (format.get()) {
    case 'd':
      allShortDatePatterns = patterns;
      shortDatePattern = allShortDatePatterns[0];
      OnShortDatePatternChanged();
      break;
    case 'D':
      allLongDatePatterns = patterns;
      longDatePattern = allLongDatePatterns[0];
      OnLongDatePatternChanged();
      break;
    case 't':
      allShortTimePatterns = patterns;
      shortTimePattern = allShortTimePatterns[0];
      OnShortTimePatternChanged();
      break;
    case 'T':
      allLongTimePatterns = patterns;
      longTimePattern = allLongTimePatterns[0];
      OnLongTimePatternChanged();
      break;
    case 'Y':
    case 'y':
      allYearMonthPatterns = patterns;
      yearMonthPattern = allYearMonthPatterns[0];
      OnYearMonthPatternChanged();
      break;
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Format_BadFormatSpecifier(), format), "format");
  }
}

void DateTimeFormatInfo___::ValidateStyles(DateTimeStyles style, String parameterName) {
  if ((style & ~(DateTimeStyles::AllowLeadingWhite | DateTimeStyles::AllowTrailingWhite | DateTimeStyles::AllowInnerWhite | DateTimeStyles::NoCurrentDateDefault | DateTimeStyles::AdjustToUniversal | DateTimeStyles::AssumeLocal | DateTimeStyles::AssumeUniversal | DateTimeStyles::RoundtripKind)) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidDateTimeStyles(), parameterName);
  }
  if ((style & DateTimeStyles::AssumeLocal) != 0 && (style & DateTimeStyles::AssumeUniversal) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ConflictingDateTimeStyles(), parameterName);
  }
  if ((style & DateTimeStyles::RoundtripKind) != 0 && (style & (DateTimeStyles::AdjustToUniversal | DateTimeStyles::AssumeLocal | DateTimeStyles::AssumeUniversal)) != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ConflictingDateTimeRoundtripStyles(), parameterName);
  }
}

DateTimeFormatFlags DateTimeFormatInfo___::InitializeFormatFlags() {
  formatFlags = (DateTimeFormatFlags)(DateTimeFormatInfoScanner::in::GetFormatFlagGenitiveMonth(get_MonthNames(), InternalGetGenitiveMonthNames(false), get_AbbreviatedMonthNames(), InternalGetGenitiveMonthNames(true)) | DateTimeFormatInfoScanner::in::GetFormatFlagUseSpaceInMonthNames(get_MonthNames(), InternalGetGenitiveMonthNames(false), get_AbbreviatedMonthNames(), InternalGetGenitiveMonthNames(true)) | DateTimeFormatInfoScanner::in::GetFormatFlagUseSpaceInDayNames(get_DayNames(), get_AbbreviatedDayNames()) | DateTimeFormatInfoScanner::in::GetFormatFlagUseHebrewCalendar((Int32)get_Calendar()->get_ID()));
  return formatFlags;
}

Boolean DateTimeFormatInfo___::YearMonthAdjustment(Int32& year, Int32& month, Boolean parsedMonthName) {
  if ((get_FormatFlags() & DateTimeFormatFlags::UseHebrewRule) != 0) {
    if (year < 1000) {
      year += 5000;
    }
    if (year < get_Calendar()->GetYear(get_Calendar()->get_MinSupportedDateTime()) || year > get_Calendar()->GetYear(get_Calendar()->get_MaxSupportedDateTime())) {
      return false;
    }
    if (parsedMonthName && !get_Calendar()->IsLeapYear(year)) {
      if (month >= 8) {
        month--;
      } else if (month == 7) {
        return false;
      }

    }
  }
  return true;
}

DateTimeFormatInfo DateTimeFormatInfo___::GetJapaneseCalendarDTFI() {
  DateTimeFormatInfo dateTimeFormat = s_jajpDTFI;
  if (dateTimeFormat == nullptr) {
    dateTimeFormat = rt::newobj<CultureInfo>("ja-JP", false)->set_DateTimeFormat();
    dateTimeFormat->set_Calendar(JapaneseCalendar::in::GetDefaultInstance());
    s_jajpDTFI = dateTimeFormat;
  }
  return dateTimeFormat;
}

DateTimeFormatInfo DateTimeFormatInfo___::GetTaiwanCalendarDTFI() {
  DateTimeFormatInfo dateTimeFormat = s_zhtwDTFI;
  if (dateTimeFormat == nullptr) {
    dateTimeFormat = rt::newobj<CultureInfo>("zh-TW", false)->set_DateTimeFormat();
    dateTimeFormat->set_Calendar(TaiwanCalendar::in::GetDefaultInstance());
    s_zhtwDTFI = dateTimeFormat;
  }
  return dateTimeFormat;
}

void DateTimeFormatInfo___::ClearTokenHashTable() {
  _dtfiTokenHash = nullptr;
  formatFlags = DateTimeFormatFlags::NotInitialized;
}

Array<DateTimeFormatInfo::in::TokenHashValue> DateTimeFormatInfo___::CreateTokenHashTable() {
  Array<TokenHashValue> array = _dtfiTokenHash;
  if (array == nullptr) {
    array = rt::newarr<Array<TokenHashValue>>(199);
    String b = get_TimeSeparator()->Trim();
    if ("," != b) {
      InsertHash(array, ",", TokenType::IgnorableSymbol, 0);
    }
    if ("." != b) {
      InsertHash(array, ".", TokenType::IgnorableSymbol, 0);
    }
    if ("시" != b && "時" != b && "时" != b) {
      InsertHash(array, get_TimeSeparator(), TokenType::SEP_Time, 0);
    }
    InsertHash(array, get_AMDesignator(), (TokenType)1027, 0);
    InsertHash(array, get_PMDesignator(), (TokenType)1284, 1);
    if (get_LanguageName()->Equals((String)"sq")) {
      InsertHash(array, "." + get_AMDesignator(), (TokenType)1027, 0);
      InsertHash(array, "." + get_PMDesignator(), (TokenType)1284, 1);
    }
    InsertHash(array, "年", TokenType::SEP_YearSuff, 0);
    InsertHash(array, "년", TokenType::SEP_YearSuff, 0);
    InsertHash(array, "月", TokenType::SEP_MonthSuff, 0);
    InsertHash(array, "월", TokenType::SEP_MonthSuff, 0);
    InsertHash(array, "日", TokenType::SEP_DaySuff, 0);
    InsertHash(array, "일", TokenType::SEP_DaySuff, 0);
    InsertHash(array, "時", TokenType::SEP_HourSuff, 0);
    InsertHash(array, "时", TokenType::SEP_HourSuff, 0);
    InsertHash(array, "分", TokenType::SEP_MinuteSuff, 0);
    InsertHash(array, "秒", TokenType::SEP_SecondSuff, 0);
    if (!LocalAppContextSwitches::get_EnforceLegacyJapaneseDateParsing() && get_Calendar()->get_ID() == CalendarId::JAPAN) {
      InsertHash(array, "元", TokenType::YearNumberToken, 1);
      InsertHash(array, "(", TokenType::IgnorableSymbol, 0);
      InsertHash(array, ")", TokenType::IgnorableSymbol, 0);
    }
    if (get_LanguageName()->Equals((String)"ko")) {
      InsertHash(array, "시", TokenType::SEP_HourSuff, 0);
      InsertHash(array, "분", TokenType::SEP_MinuteSuff, 0);
      InsertHash(array, "초", TokenType::SEP_SecondSuff, 0);
    }
    if (get_LanguageName()->Equals((String)"ky")) {
      InsertHash(array, "-", TokenType::IgnorableSymbol, 0);
    } else {
      InsertHash(array, "-", TokenType::SEP_DateOrOffset, 0);
    }
    DateTimeFormatInfoScanner dateTimeFormatInfoScanner = rt::newobj<DateTimeFormatInfoScanner>();
    Array<String> dateWordsOfDTFI = dateTimeFormatInfoScanner->GetDateWordsOfDTFI((DateTimeFormatInfo)this);
    DateTimeFormatFlags formatFlag = get_FormatFlags();
    Boolean flag = false;
    if (dateWordsOfDTFI != nullptr) {
      for (Int32 i = 0; i < dateWordsOfDTFI->get_Length(); i++) {
        switch (dateWordsOfDTFI[i][0].get()) {
          case '\0':
            {
              ReadOnlySpan<Char> monthPostfix = MemoryExtensions::AsSpan(dateWordsOfDTFI[i], 1);
              AddMonthNames(array, monthPostfix);
              break;
            }case '':
            {
              String text = dateWordsOfDTFI[i]->Substring(1);
              InsertHash(array, text, TokenType::IgnorableSymbol, 0);
              if (get_DateSeparator()->Trim(nullptr)->Equals(text)) {
                flag = true;
              }
              break;
            }default:
            InsertHash(array, dateWordsOfDTFI[i], TokenType::DateWordToken, 0);
            if (get_LanguageName()->Equals((String)"eu")) {
              InsertHash(array, "." + dateWordsOfDTFI[i], TokenType::DateWordToken, 0);
            }
            break;
        }
      }
    }
    if (!flag) {
      InsertHash(array, get_DateSeparator(), TokenType::SEP_Date, 0);
    }
    AddMonthNames(array);
    for (Int32 j = 1; j <= 13; j++) {
      InsertHash(array, GetAbbreviatedMonthName(j), TokenType::MonthToken, j);
    }
    if ((get_FormatFlags() & DateTimeFormatFlags::UseGenitiveMonth) != 0) {
      Array<String> array2 = InternalGetGenitiveMonthNames(false);
      Array<String> array3 = InternalGetGenitiveMonthNames(true);
      for (Int32 k = 1; k <= 13; k++) {
        InsertHash(array, array2[k - 1], TokenType::MonthToken, k);
        InsertHash(array, array3[k - 1], TokenType::MonthToken, k);
      }
    }
    if ((get_FormatFlags() & DateTimeFormatFlags::UseLeapYearMonth) != 0) {
      for (Int32 l = 1; l <= 13; l++) {
        String str = InternalGetMonthName(l, MonthNameStyles::LeapYear, false);
        InsertHash(array, str, TokenType::MonthToken, l);
      }
    }
    for (Int32 m = 0; m < 7; m++) {
      String dayName = GetDayName((DayOfWeek)m);
      InsertHash(array, dayName, TokenType::DayOfWeekToken, m);
      dayName = GetAbbreviatedDayName((DayOfWeek)m);
      InsertHash(array, dayName, TokenType::DayOfWeekToken, m);
    }
    Array<Int32> eras = calendar->get_Eras();
    for (Int32 n = 1; n <= eras->get_Length(); n++) {
      InsertHash(array, GetEraName(n), TokenType::EraToken, n);
      InsertHash(array, GetAbbreviatedEraName(n), TokenType::EraToken, n);
    }
    if (!GlobalizationMode::get_Invariant()) {
      if (get_LanguageName()->Equals((String)"ja")) {
        for (Int32 num = 0; num < 7; num++) {
          String str2 = "(" + GetAbbreviatedDayName((DayOfWeek)num) + ")";
          InsertHash(array, str2, TokenType::DayOfWeekToken, num);
        }
        if (get_Calendar()->GetType() != typeof<JapaneseCalendar>()) {
          DateTimeFormatInfo japaneseCalendarDTFI = GetJapaneseCalendarDTFI();
          for (Int32 num2 = 1; num2 <= japaneseCalendarDTFI->get_Calendar()->get_Eras()->get_Length(); num2++) {
            InsertHash(array, japaneseCalendarDTFI->GetEraName(num2), TokenType::JapaneseEraToken, num2);
            InsertHash(array, japaneseCalendarDTFI->GetAbbreviatedEraName(num2), TokenType::JapaneseEraToken, num2);
            InsertHash(array, japaneseCalendarDTFI->get_AbbreviatedEnglishEraNames()[num2 - 1], TokenType::JapaneseEraToken, num2);
          }
        }
      } else if (get_CultureName()->Equals((String)"zh-TW")) {
        DateTimeFormatInfo taiwanCalendarDTFI = GetTaiwanCalendarDTFI();
        for (Int32 num3 = 1; num3 <= taiwanCalendarDTFI->get_Calendar()->get_Eras()->get_Length(); num3++) {
          if (taiwanCalendarDTFI->GetEraName(num3)->get_Length() > 0) {
            InsertHash(array, taiwanCalendarDTFI->GetEraName(num3), TokenType::TEraToken, num3);
          }
        }
      }

    }
    InsertHash(array, get_InvariantInfo()->get_AMDesignator(), (TokenType)1027, 0);
    InsertHash(array, get_InvariantInfo()->get_PMDesignator(), (TokenType)1284, 1);
    for (Int32 num4 = 1; num4 <= 12; num4++) {
      String monthName = get_InvariantInfo()->GetMonthName(num4);
      InsertHash(array, monthName, TokenType::MonthToken, num4);
      monthName = get_InvariantInfo()->GetAbbreviatedMonthName(num4);
      InsertHash(array, monthName, TokenType::MonthToken, num4);
    }
    for (Int32 num5 = 0; num5 < 7; num5++) {
      String dayName2 = get_InvariantInfo()->GetDayName((DayOfWeek)num5);
      InsertHash(array, dayName2, TokenType::DayOfWeekToken, num5);
      dayName2 = get_InvariantInfo()->GetAbbreviatedDayName((DayOfWeek)num5);
      InsertHash(array, dayName2, TokenType::DayOfWeekToken, num5);
    }
    for (Int32 num6 = 0; num6 < get_AbbreviatedEnglishEraNames()->get_Length(); num6++) {
      InsertHash(array, get_AbbreviatedEnglishEraNames()[num6], TokenType::EraToken, num6 + 1);
    }
    InsertHash(array, "T", TokenType::SEP_LocalTimeMark, 0);
    InsertHash(array, "GMT", TokenType::TimeZoneToken, 0);
    InsertHash(array, "Z", TokenType::TimeZoneToken, 0);
    InsertHash(array, "/", TokenType::SEP_Date, 0);
    InsertHash(array, ":", TokenType::SEP_Time, 0);
    _dtfiTokenHash = array;
  }
  return array;
}

template <>
void DateTimeFormatInfo___::AddMonthNames(Array<TokenHashValue> temp, ReadOnlySpan<Char> monthPostfix) {
  for (Int32 i = 1; i <= 13; i++) {
    String monthName = GetMonthName(i);
    if (monthName->get_Length() > 0) {
      if (!monthPostfix.get_IsEmpty()) {
        InsertHash(temp, monthName + monthPostfix, TokenType::MonthToken, i);
      } else {
        InsertHash(temp, monthName, TokenType::MonthToken, i);
      }
    }
    monthName = GetAbbreviatedMonthName(i);
    InsertHash(temp, monthName, TokenType::MonthToken, i);
  }
}

Boolean DateTimeFormatInfo___::TryParseHebrewNumber(__DTString& str, Boolean& badFormat, Int32& number) {
  number = -1;
  badFormat = false;
  Int32 index = str.Index;
  if (!HebrewNumber::IsDigit(str.Value[index])) {
    return false;
  }
  HebrewNumberParsingContext context = HebrewNumberParsingContext(0);
  HebrewNumberParsingState hebrewNumberParsingState;
  do {
    hebrewNumberParsingState = HebrewNumber::ParseByChar(str.Value[index++], context);
    if ((UInt32)hebrewNumberParsingState <= 1u) {
      return false;
    }
  } while (index < str.Value.get_Length() && hebrewNumberParsingState != HebrewNumberParsingState::FoundEndOfHebrewNumber)
  if (hebrewNumberParsingState != HebrewNumberParsingState::FoundEndOfHebrewNumber) {
    return false;
  }
  str.Advance(index - str.Index);
  number = context.result;
  return true;
}

Boolean DateTimeFormatInfo___::IsHebrewChar(Char ch) {
  if (ch >= '') {
    return ch <= 'ÿ';
  }
  return false;
}

Boolean DateTimeFormatInfo___::IsAllowedJapaneseTokenFollowedByNonSpaceLetter(String tokenString, Char nextCh) {
  if (!LocalAppContextSwitches::get_EnforceLegacyJapaneseDateParsing() && get_Calendar()->get_ID() == CalendarId::JAPAN && (nextCh == "元"[0] || (tokenString == "元" && nextCh == "年"[0]))) {
    return true;
  }
  return false;
}

Boolean DateTimeFormatInfo___::Tokenize(TokenType TokenMask, TokenType& tokenType, Int32& tokenValue, __DTString& str) {
  tokenType = TokenType::UnknownToken;
  tokenValue = 0;
  Char c = str.m_current;
  Boolean flag = Char::IsLetter(c);
  if (flag) {
    c = get_Culture()->get_TextInfo()->ToLower(c);
    Boolean badFormat;
    if (IsHebrewChar(c) && TokenMask == TokenType::RegularTokenMask && TryParseHebrewNumber(str, badFormat, tokenValue)) {
      if (badFormat) {
        tokenType = TokenType::UnknownToken;
        return false;
      }
      tokenType = TokenType::HebrewNumber;
      return true;
    }
  }
  Int32 num = (Int32)c % 199;
  Int32 num2 = 1 + (Int32)c % 197;
  Int32 num3 = str.get_Length() - str.Index;
  Int32 num4 = 0;
  Array<TokenHashValue> as = _dtfiTokenHash;
  Array<TokenHashValue> array = as != nullptr ? as : CreateTokenHashTable();
  do {
    TokenHashValue tokenHashValue = array[num];
    if (tokenHashValue == nullptr) {
      break;
    }
    if ((tokenHashValue->tokenType & TokenMask) > (TokenType)0 && tokenHashValue->tokenString->get_Length() <= num3) {
      Boolean flag2 = true;
      if (flag) {
        Int32 num5 = str.Index + tokenHashValue->tokenString->get_Length();
        if (num5 > str.get_Length()) {
          flag2 = false;
        } else if (num5 < str.get_Length()) {
          Char c2 = str.Value[num5];
          flag2 = (!Char::IsLetter(c2) || IsAllowedJapaneseTokenFollowedByNonSpaceLetter(tokenHashValue->tokenString, c2));
        }

      }
      if (flag2 && ((tokenHashValue->tokenString->get_Length() == 1 && str.Value[str.Index] == tokenHashValue->tokenString[0]) || get_Culture()->get_CompareInfo()->Compare(str.Value.Slice(str.Index, tokenHashValue->tokenString->get_Length()), tokenHashValue->tokenString, CompareOptions::IgnoreCase) == 0)) {
        tokenType = (tokenHashValue->tokenType & TokenMask);
        tokenValue = tokenHashValue->tokenValue;
        str.Advance(tokenHashValue->tokenString->get_Length());
        return true;
      }
      if ((tokenHashValue->tokenType == TokenType::MonthToken && get_HasSpacesInMonthNames()) || (tokenHashValue->tokenType == TokenType::DayOfWeekToken && get_HasSpacesInDayNames())) {
        Int32 matchLength = 0;
        if (str.MatchSpecifiedWords(tokenHashValue->tokenString, true, matchLength)) {
          tokenType = (tokenHashValue->tokenType & TokenMask);
          tokenValue = tokenHashValue->tokenValue;
          str.Advance(matchLength);
          return true;
        }
      }
    }
    num4++;
    num += num2;
    if (num >= 199) {
      num -= 199;
    }
  } while (num4 < 199)
  return false;
}

void DateTimeFormatInfo___::InsertAtCurrentHashNode(Array<TokenHashValue> hashTable, String str, Char ch, TokenType tokenType, Int32 tokenValue, Int32 pos, Int32 hashcode, Int32 hashProbe) {
  TokenHashValue tokenHashValue = hashTable[hashcode];
  hashTable[hashcode] = rt::newobj<TokenHashValue>(str, tokenType, tokenValue);
  while (++pos < 199) {
    hashcode += hashProbe;
    if (hashcode >= 199) {
      hashcode -= 199;
    }
    TokenHashValue tokenHashValue2 = hashTable[hashcode];
    if (tokenHashValue2 == nullptr || get_Culture()->get_TextInfo()->ToLower(tokenHashValue2->tokenString[0]) == ch) {
      hashTable[hashcode] = tokenHashValue;
      if (tokenHashValue2 == nullptr) {
        break;
      }
      tokenHashValue = tokenHashValue2;
    }
  }
}

void DateTimeFormatInfo___::InsertHash(Array<TokenHashValue> hashTable, String str, TokenType tokenType, Int32 tokenValue) {
  if (String::in::IsNullOrEmpty(str)) {
    return;
  }
  Int32 num = 0;
}

Boolean DateTimeFormatInfo___::CompareStringIgnoreCaseOptimized(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2) {
  if (length1 == 1 && length2 == 1 && string1[offset1] == string2[offset2]) {
    return true;
  }
  return get_Culture()->get_CompareInfo()->Compare(string1, offset1, length1, string2, offset2, length2, CompareOptions::IgnoreCase) == 0;
}

} // namespace System::Private::CoreLib::System::Globalization::DateTimeFormatInfoNamespace
