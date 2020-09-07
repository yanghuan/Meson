#include "CalendarData-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarData-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseCalendar-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>

namespace System::Private::CoreLib::System::Globalization::CalendarDataNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Text;

void CalendarData___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void CalendarData___::__c___::ctor() {
}

Interop::Globalization::ResultCode CalendarData___::__c___::_GetCalendarInfo_b__33_0(Span<Char> buffer, String locale, CalendarId id, CalendarDataType type) {
  {
    Char* result = buffer;
    return Interop::Globalization::GetCalendarInfo(locale, id, type, result, buffer.get_Length());
  }
}

void CalendarData___::ctor() {
  iTwoDigitYearMax = 2029;
  Object::in::ctor();
}

CalendarData CalendarData___::CreateInvariant() {
  CalendarData calendarData = rt::newobj<CalendarData>();
  calendarData->sNativeName = "Gregorian Calendar";
  calendarData->iTwoDigitYearMax = 2029;
  calendarData->iCurrentEra = 1;
  calendarData->saShortDates = rt::newarr<Array<String>>(2);
  calendarData->saLongDates = rt::newarr<Array<String>>(1);
  calendarData->saYearMonths = rt::newarr<Array<String>>(1);
  calendarData->sMonthDay = "MMMM dd";
  calendarData->saEraNames = rt::newarr<Array<String>>(1);
  calendarData->saAbbrevEraNames = rt::newarr<Array<String>>(1);
  calendarData->saAbbrevEnglishEraNames = rt::newarr<Array<String>>(1);
  calendarData->saDayNames = rt::newarr<Array<String>>(7);
  calendarData->saAbbrevDayNames = rt::newarr<Array<String>>(7);
  calendarData->saSuperShortDayNames = rt::newarr<Array<String>>(7);
  calendarData->saMonthNames = rt::newarr<Array<String>>(13);
  calendarData->saAbbrevMonthNames = rt::newarr<Array<String>>(13);
  calendarData->saMonthGenitiveNames = calendarData->saMonthNames;
  calendarData->saAbbrevMonthGenitiveNames = calendarData->saAbbrevMonthNames;
  calendarData->saLeapYearMonthNames = calendarData->saMonthNames;
  calendarData->bUseUserOverrides = false;
  return calendarData;
}

void CalendarData___::ctor(String localeName, CalendarId calendarId, Boolean bUseUserOverrides) {
  iTwoDigitYearMax = 2029;
  Object::in::ctor();
  this->bUseUserOverrides = bUseUserOverrides;
  if (!LoadCalendarDataFromSystemCore(localeName, calendarId)) {
    if (sNativeName == nullptr) {
      sNativeName = String::in::Empty;
    }
    if (saShortDates == nullptr) {
      saShortDates = Invariant->saShortDates;
    }
    if (saYearMonths == nullptr) {
      saYearMonths = Invariant->saYearMonths;
    }
    if (saLongDates == nullptr) {
      saLongDates = Invariant->saLongDates;
    }
    if (sMonthDay == nullptr) {
      sMonthDay = Invariant->sMonthDay;
    }
    if (saEraNames == nullptr) {
      saEraNames = Invariant->saEraNames;
    }
    if (saAbbrevEraNames == nullptr) {
      saAbbrevEraNames = Invariant->saAbbrevEraNames;
    }
    if (saAbbrevEnglishEraNames == nullptr) {
      saAbbrevEnglishEraNames = Invariant->saAbbrevEnglishEraNames;
    }
    if (saDayNames == nullptr) {
      saDayNames = Invariant->saDayNames;
    }
    if (saAbbrevDayNames == nullptr) {
      saAbbrevDayNames = Invariant->saAbbrevDayNames;
    }
    if (saSuperShortDayNames == nullptr) {
      saSuperShortDayNames = Invariant->saSuperShortDayNames;
    }
    if (saMonthNames == nullptr) {
      saMonthNames = Invariant->saMonthNames;
    }
    if (saAbbrevMonthNames == nullptr) {
      saAbbrevMonthNames = Invariant->saAbbrevMonthNames;
    }
  }
  if (calendarId == CalendarId::TAIWAN) {
    if (SystemSupportsTaiwaneseCalendar()) {
      sNativeName = "中華民國曆";
    } else {
      sNativeName = String::in::Empty;
    }
  }
  if (saMonthGenitiveNames == nullptr || saMonthGenitiveNames->get_Length() == 0 || String::in::IsNullOrEmpty(saMonthGenitiveNames[0])) {
    saMonthGenitiveNames = saMonthNames;
  }
  if (saAbbrevMonthGenitiveNames == nullptr || saAbbrevMonthGenitiveNames->get_Length() == 0 || String::in::IsNullOrEmpty(saAbbrevMonthGenitiveNames[0])) {
    saAbbrevMonthGenitiveNames = saAbbrevMonthNames;
  }
  if (saLeapYearMonthNames == nullptr || saLeapYearMonthNames->get_Length() == 0 || String::in::IsNullOrEmpty(saLeapYearMonthNames[0])) {
    saLeapYearMonthNames = saMonthNames;
  }
  InitializeEraNames(localeName, calendarId);
  InitializeAbbreviatedEraNames(localeName, calendarId);
  if (calendarId == CalendarId::JAPAN) {
    saAbbrevEnglishEraNames = JapaneseCalendar::in::EnglishEraNames();
  } else {
    saAbbrevEnglishEraNames = rt::newarr<Array<String>>(1);
  }
  iCurrentEra = saEraNames->get_Length();
}

void CalendarData___::InitializeEraNames(String localeName, CalendarId calendarId) {
  switch (calendarId) {
    case CalendarId::GREGORIAN:
      if (saEraNames == nullptr || saEraNames->get_Length() == 0 || String::in::IsNullOrEmpty(saEraNames[0])) {
        saEraNames = rt::newarr<Array<String>>(1);
      }
      break;
    case CalendarId::GREGORIAN_US:
    case CalendarId::JULIAN:
      saEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::HEBREW:
      saEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::HIJRI:
    case CalendarId::UMALQURA:
      if (localeName == "dv-MV") {
        saEraNames = rt::newarr<Array<String>>(1);
      } else {
        saEraNames = rt::newarr<Array<String>>(1);
      }
      break;
    case CalendarId::GREGORIAN_ARABIC:
    case CalendarId::GREGORIAN_XLIT_ENGLISH:
    case CalendarId::GREGORIAN_XLIT_FRENCH:
      saEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::GREGORIAN_ME_FRENCH:
      saEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::TAIWAN:
      if (SystemSupportsTaiwaneseCalendar()) {
        saEraNames = rt::newarr<Array<String>>(1);
      } else {
        saEraNames = rt::newarr<Array<String>>(1);
      }
      break;
    case CalendarId::KOREA:
      saEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::THAI:
      saEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::JAPAN:
    case CalendarId::JAPANESELUNISOLAR:
      saEraNames = JapaneseCalendar::in::EraNames();
      break;
    case CalendarId::PERSIAN:
      if (saEraNames == nullptr || saEraNames->get_Length() == 0 || String::in::IsNullOrEmpty(saEraNames[0])) {
        saEraNames = rt::newarr<Array<String>>(1);
      }
      break;
    default:
      saEraNames = Invariant->saEraNames;
      break;
  }
}

void CalendarData___::InitializeAbbreviatedEraNames(String localeName, CalendarId calendarId) {
  switch (calendarId) {
    case CalendarId::GREGORIAN:
      if (saAbbrevEraNames == nullptr || saAbbrevEraNames->get_Length() == 0 || String::in::IsNullOrEmpty(saAbbrevEraNames[0])) {
        saAbbrevEraNames = rt::newarr<Array<String>>(1);
      }
      break;
    case CalendarId::GREGORIAN_US:
    case CalendarId::JULIAN:
      saAbbrevEraNames = rt::newarr<Array<String>>(1);
      break;
    case CalendarId::JAPAN:
    case CalendarId::JAPANESELUNISOLAR:
      saAbbrevEraNames = JapaneseCalendar::in::AbbrevEraNames();
      break;
    case CalendarId::HIJRI:
    case CalendarId::UMALQURA:
      if (localeName == "dv-MV") {
        saAbbrevEraNames = rt::newarr<Array<String>>(1);
      } else {
        saAbbrevEraNames = rt::newarr<Array<String>>(1);
      }
      break;
    case CalendarId::TAIWAN:
      saAbbrevEraNames = rt::newarr<Array<String>>(1);
      if (saEraNames[0]->get_Length() == 4) {
        saAbbrevEraNames[0] = saEraNames[0]->Substring(2, 2);
      } else {
        saAbbrevEraNames[0] = saEraNames[0];
      }
      break;
    case CalendarId::PERSIAN:
      if (saAbbrevEraNames == nullptr || saAbbrevEraNames->get_Length() == 0 || String::in::IsNullOrEmpty(saAbbrevEraNames[0])) {
        saAbbrevEraNames = saEraNames;
      }
      break;
    default:
      saAbbrevEraNames = saEraNames;
      break;
  }
}

Int32 CalendarData___::GetCalendarCurrentEra(Calendar calendar) {
  if (GlobalizationMode::get_Invariant()) {
    return Invariant->iCurrentEra;
  }
  CalendarId baseCalendarID = calendar->get_BaseCalendarID();
  String name = CalendarIdToCultureName(baseCalendarID);
  return CultureInfo::in::GetCultureInfo(name)->_cultureData->GetCalendar(baseCalendarID)->iCurrentEra;
}

String CalendarData___::CalendarIdToCultureName(CalendarId calendarId) {
  switch (calendarId) {
    case CalendarId::GREGORIAN_US:
      return "fa-IR";
    case CalendarId::JAPAN:
      return "ja-JP";
    case CalendarId::TAIWAN:
      return "zh-TW";
    case CalendarId::KOREA:
      return "ko-KR";
    case CalendarId::HIJRI:
    case CalendarId::GREGORIAN_ARABIC:
    case CalendarId::UMALQURA:
      return "ar-SA";
    case CalendarId::THAI:
      return "th-TH";
    case CalendarId::HEBREW:
      return "he-IL";
    case CalendarId::GREGORIAN_ME_FRENCH:
      return "ar-DZ";
    case CalendarId::GREGORIAN_XLIT_ENGLISH:
    case CalendarId::GREGORIAN_XLIT_FRENCH:
      return "ar-IQ";
    default:
      return "en-US";
  }
}

Boolean CalendarData___::SystemSupportsTaiwaneseCalendar() {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuSystemSupportsTaiwaneseCalendar();
  }
  return NlsSystemSupportsTaiwaneseCalendar();
}

Boolean CalendarData___::IcuLoadCalendarDataFromSystem(String localeName, CalendarId calendarId) {
  Boolean flag = true;
  flag &= GetCalendarInfo(localeName, calendarId, CalendarDataType::NativeName, sNativeName);
  flag &= GetCalendarInfo(localeName, calendarId, CalendarDataType::MonthDay, sMonthDay);
  if (sMonthDay != nullptr) {
    sMonthDay = NormalizeDatePattern(sMonthDay);
  }
  flag &= EnumDatePatterns(localeName, calendarId, CalendarDataType::ShortDates, saShortDates);
  flag &= EnumDatePatterns(localeName, calendarId, CalendarDataType::LongDates, saLongDates);
  flag &= EnumDatePatterns(localeName, calendarId, CalendarDataType::YearMonths, saYearMonths);
  flag &= EnumCalendarInfo(localeName, calendarId, CalendarDataType::DayNames, saDayNames);
  flag &= EnumCalendarInfo(localeName, calendarId, CalendarDataType::AbbrevDayNames, saAbbrevDayNames);
  flag &= EnumCalendarInfo(localeName, calendarId, CalendarDataType::SuperShortDayNames, saSuperShortDayNames);
  String leapHebrewMonthName = nullptr;
  flag &= EnumMonthNames(localeName, calendarId, CalendarDataType::MonthNames, saMonthNames, leapHebrewMonthName);
  if (leapHebrewMonthName != nullptr) {
    saLeapYearMonthNames = (Array<String>)saMonthNames->Clone();
    saLeapYearMonthNames[6] = leapHebrewMonthName;
    saMonthNames[5] = saMonthNames[6];
    saMonthNames[6] = leapHebrewMonthName;
  }
  flag &= EnumMonthNames(localeName, calendarId, CalendarDataType::AbbrevMonthNames, saAbbrevMonthNames, leapHebrewMonthName);
  flag &= EnumMonthNames(localeName, calendarId, CalendarDataType::MonthGenitiveNames, saMonthGenitiveNames, leapHebrewMonthName);
  flag &= EnumMonthNames(localeName, calendarId, CalendarDataType::AbbrevMonthGenitiveNames, saAbbrevMonthGenitiveNames, leapHebrewMonthName);
  flag &= EnumEraNames(localeName, calendarId, CalendarDataType::EraNames, saEraNames);
  return flag & EnumEraNames(localeName, calendarId, CalendarDataType::AbbrevEraNames, saAbbrevEraNames);
}

Int32 CalendarData___::IcuGetTwoDigitYearMax(CalendarId calendarId) {
  return -1;
}

Int32 CalendarData___::IcuGetCalendars(String localeName, Array<CalendarId> calendars) {
  Int32 num = Interop::Globalization::GetCalendars(localeName, calendars, calendars->get_Length());
  if (num == 0 && calendars->get_Length() != 0) {
    calendars[0] = CalendarId::GREGORIAN;
    num = 1;
  }
  return num;
}

Boolean CalendarData___::IcuSystemSupportsTaiwaneseCalendar() {
  return true;
}

Boolean CalendarData___::GetCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, String& calendarString) {
  SpanFunc<Char, String, CalendarId, CalendarDataType, Interop::Globalization::ResultCode> as = __c::in::__9__33_0;
  return Interop::CallStringMethod(as != nullptr ? as : (__c::in::__9__33_0 = &__c::in::__9->_GetCalendarInfo_b__33_0), localeName, calendarId, dataType, calendarString);
}

Boolean CalendarData___::EnumDatePatterns(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& datePatterns) {
  datePatterns = nullptr;
  IcuEnumCalendarsData callbackContext;
  callbackContext.Results = rt::newobj<List<String>>();
  callbackContext.DisallowDuplicates = true;
  Boolean flag = EnumCalendarInfo(localeName, calendarId, dataType, callbackContext);
  if (flag) {
    List<String> results = callbackContext.Results;
    for (Int32 i = 0; i < results->get_Count(); i++) {
      results[i] = NormalizeDatePattern(results[i]);
    }
    if (dataType == CalendarDataType::ShortDates) {
      FixDefaultShortDatePattern(results);
    }
    datePatterns = results->ToArray();
  }
  return flag;
}

void CalendarData___::FixDefaultShortDatePattern(List<String> shortDatePatterns) {
  if (shortDatePatterns->get_Count() == 0) {
    return;
  }
  String text = shortDatePatterns[0];
  if (text->get_Length() > 100) {
    return;
  }
  Char as[text->get_Length() + 2] = {};
  Span<Char> span = as;
  Int32 i;
  for (i = 0; i < text->get_Length(); i++) {
    if (text[i] == 39) {
      do {
        span[i] = text[i];
        i++;
      } while (i < text->get_Length() && text[i] != 39)
      if (i >= text->get_Length()) {
        return;
      }
    } else if (text[i] == 121) {
      span[i] = 121;
      break;
    }

    span[i] = text[i];
  }
  if (i >= text->get_Length() - 1 || text[i + 1] != 121 || (i + 2 < text->get_Length() && text[i + 2] == 121)) {
    return;
  }
  span[i + 1] = 121;
  span[i + 2] = 121;
  span[i + 3] = 121;
  for (i += 2; i < text->get_Length(); i++) {
    span[i + 2] = text[i];
  }
  shortDatePatterns[0] = span.ToString();
  for (Int32 j = 1; j < shortDatePatterns->get_Count(); j++) {
    if (shortDatePatterns[j] == shortDatePatterns[0]) {
      shortDatePatterns[j] = text;
      return;
    }
  }
  shortDatePatterns->Add(text);
}

String CalendarData___::NormalizeDatePattern(String input) {
  StringBuilder stringBuilder = StringBuilderCache::Acquire(input->get_Length());
  Int32 index = 0;
  while (index < input->get_Length()) {
    switch (input[index].get()) {
      case 39:
        stringBuilder->Append(input[index++]);
        while (index < input->get_Length()) {
          Char c = input[index++];
          stringBuilder->Append(c);
          if (c == 39) {
            break;
          }
        }
        break;
      case 69:
      case 99:
      case 101:
        NormalizeDayOfWeek(input, stringBuilder, index);
        break;
      case 76:
      case 77:
        {
          Int32 num = CountOccurrences(input, input[index], index);
          if (num > 4) {
            num = 3;
          }
          stringBuilder->Append(77, num);
          break;
        }case 71:
        {
          Int32 num = CountOccurrences(input, 71, index);
          stringBuilder->Append(103);
          break;
        }case 121:
        {
          Int32 num = CountOccurrences(input, 121, index);
          if (num == 1) {
            num = 4;
          }
          stringBuilder->Append(121, num);
          break;
        }default:
        stringBuilder->Append(input[index++]);
        break;
    }
  }
  return StringBuilderCache::GetStringAndRelease(stringBuilder);
}

void CalendarData___::NormalizeDayOfWeek(String input, StringBuilder destination, Int32& index) {
  Char value = input[index];
  Int32 val = CountOccurrences(input, value, index);
  val = Math::Max(val, 3);
  if (val > 4) {
    val = 3;
  }
  destination->Append(100, val);
}

Int32 CalendarData___::CountOccurrences(String input, Char value, Int32& index) {
  Int32 num = index;
  while (index < input->get_Length() && input[index] == value) {
    index++;
  }
  return index - num;
}

Boolean CalendarData___::EnumMonthNames(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& monthNames, String& leapHebrewMonthName) {
  monthNames = nullptr;
  IcuEnumCalendarsData callbackContext;
  callbackContext.Results = rt::newobj<List<String>>();
  Boolean flag = EnumCalendarInfo(localeName, calendarId, dataType, callbackContext);
  if (flag) {
    if (callbackContext.Results->get_Count() == 12) {
      callbackContext.Results->Add(String::in::Empty);
    }
    if (callbackContext.Results->get_Count() > 13) {
      if (calendarId == CalendarId::HEBREW) {
        leapHebrewMonthName = callbackContext.Results[13];
      }
      callbackContext.Results->RemoveRange(13, callbackContext.Results->get_Count() - 13);
    }
    monthNames = callbackContext.Results->ToArray();
  }
  return flag;
}

Boolean CalendarData___::EnumEraNames(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& eraNames) {
  Boolean result = EnumCalendarInfo(localeName, calendarId, dataType, eraNames);
  if (calendarId != CalendarId::JAPAN && calendarId != CalendarId::JAPANESELUNISOLAR) {
    Array<String> obj = eraNames;
    if (obj != nullptr && obj->get_Length() != 0) {
      Array<String> array = eraNames = rt::newarr<Array<String>>(1);
    }
  }
  return result;
}

Boolean CalendarData___::EnumCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, Array<String>& calendarData) {
  calendarData = nullptr;
  IcuEnumCalendarsData callbackContext;
  callbackContext.Results = rt::newobj<List<String>>();
  Boolean flag = EnumCalendarInfo(localeName, calendarId, dataType, callbackContext);
  if (flag) {
    calendarData = callbackContext.Results->ToArray();
  }
  return flag;
}

Boolean CalendarData___::EnumCalendarInfo(String localeName, CalendarId calendarId, CalendarDataType dataType, IcuEnumCalendarsData& callbackContext) {
  return Interop::Globalization::EnumCalendarInfo(EnumCalendarInfoCallback, localeName, calendarId, dataType, (IntPtr)Unsafe::AsPointer(callbackContext));
}

void CalendarData___::EnumCalendarInfoCallback(Char* calendarStringPtr, IntPtr context) {
  try {
    ReadOnlySpan<Char> strA = ReadOnlySpan<Char>(calendarStringPtr, String::in::wcslen(calendarStringPtr));
    IcuEnumCalendarsData& reference = Unsafe::As<Byte, IcuEnumCalendarsData>(*(Byte*)(void*)context);
    if (reference.DisallowDuplicates) {
      for (String&& result : *reference.Results) {
        if (String::in::CompareOrdinal(strA, result) == 0) {
          return;
        }
      }
    }
    reference.Results->Add(strA.ToString());
  } catch (Exception) {
  }
}

Int32 CalendarData___::NlsGetTwoDigitYearMax(CalendarId calendarId) {
  if (!GlobalizationMode::get_Invariant()) {
    Int32 data;
    if (!CallGetCalendarInfoEx(nullptr, calendarId, 48u, data)) {
      return -1;
    }
    return data;
  }
  return Invariant->iTwoDigitYearMax;
}

Boolean CalendarData___::NlsSystemSupportsTaiwaneseCalendar() {
  String data;
  return CallGetCalendarInfoEx("zh-TW", CalendarId::TAIWAN, 2u, data);
}

Boolean CalendarData___::CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, Int32& data) {
  return Interop::Kernel32::GetCalendarInfoEx(localeName, (UInt32)calendar, IntPtr::Zero, calType | 536870912, IntPtr::Zero, 0, data) != 0;
}

Boolean CalendarData___::CallGetCalendarInfoEx(String localeName, CalendarId calendar, UInt32 calType, String& data) {
  Char as[80] = {};
  Char* ptr = as;
  Int32 num = Interop::Kernel32::GetCalendarInfoEx(localeName, (UInt32)calendar, IntPtr::Zero, calType, (IntPtr)(void*)ptr, 80, IntPtr::Zero);
  if (num > 0) {
    if (*(ptr + num - 1) == 0) {
      num--;
    }
    data = rt::newstr<String>(ptr, 0, num);
    return true;
  }
  data = "";
  return false;
}

Interop::BOOL CalendarData___::EnumCalendarInfoCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr pReserved, void* lParam) {
  EnumData& reference = Unsafe::As<Byte, EnumData>(*(Byte*)lParam);
  try {
    String text = rt::newstr<String>(lpCalendarInfoString);
    if (reference.userOverride != text) {
      reference.strings->Add(text);
    }
    return Interop::BOOL::TRUE;
  } catch (Exception) {
    return Interop::BOOL::FALSE;
  }
}

Interop::BOOL CalendarData___::EnumCalendarsCallback(Char* lpCalendarInfoString, UInt32 calendar, IntPtr reserved, void* lParam) {
  NlsEnumCalendarsData& reference = Unsafe::As<Byte, NlsEnumCalendarsData>(*(Byte*)lParam);
  try {
    if (reference.userOverride != calendar) {
      reference.calendars->Add((Int32)calendar);
    }
    return Interop::BOOL::TRUE;
  } catch (Exception) {
    return Interop::BOOL::FALSE;
  }
}

Boolean CalendarData___::LoadCalendarDataFromSystemCore(String localeName, CalendarId calendarId) {
  if (GlobalizationMode::get_UseNls()) {
    return NlsLoadCalendarDataFromSystem(localeName, calendarId);
  }
  Boolean flag = IcuLoadCalendarDataFromSystem(localeName, calendarId);
  if (flag && bUseUserOverrides) {
    NormalizeCalendarId(calendarId, localeName);
    flag &= CallGetCalendarInfoEx(localeName, calendarId, 48u, iTwoDigitYearMax);
    CalendarId calendarId2 = (CalendarId)CultureData::in::GetLocaleInfoExInt(localeName, 4105u);
    if (calendarId2 == calendarId) {
      String value = CultureData::in::ReescapeWin32String(CultureData::in::GetLocaleInfoEx(localeName, 31u));
      String value2 = CultureData::in::ReescapeWin32String(CultureData::in::GetLocaleInfoEx(localeName, 32u));
      InsertOrSwapOverride(value, saShortDates);
      InsertOrSwapOverride(value2, saLongDates);
    }
  }
  return flag;
}

void CalendarData___::InsertOrSwapOverride(String value, Array<String>& destination) {
  if (value == nullptr) {
    return;
  }
  for (Int32 i = 0; i < destination->get_Length(); i++) {
    if (destination[i] == value) {
      if (i > 0) {
        String text = destination[0];
        destination[0] = value;
        destination[i] = text;
      }
      return;
    }
  }
  Array<String> array = rt::newarr<Array<String>>(destination->get_Length() + 1);
  array[0] = value;
  Array<>::in::Copy(destination, 0, array, 1, destination->get_Length());
  destination = array;
}

Boolean CalendarData___::NlsLoadCalendarDataFromSystem(String localeName, CalendarId calendarId) {
  Boolean flag = true;
  UInt32 num = (!bUseUserOverrides) ? 2147483648u : 0u;
  NormalizeCalendarId(calendarId, localeName);
  flag &= CallGetCalendarInfoEx(localeName, calendarId, 48 | num, iTwoDigitYearMax);
  flag &= CallGetCalendarInfoEx(localeName, calendarId, 2u, sNativeName);
  flag &= CallGetCalendarInfoEx(localeName, calendarId, 56u, sMonthDay);
  flag &= CallEnumCalendarInfo(localeName, calendarId, 5u, 31 | num, saShortDates);
  flag &= CallEnumCalendarInfo(localeName, calendarId, 6u, 32 | num, saLongDates);
  flag &= CallEnumCalendarInfo(localeName, calendarId, 47u, 4102u, saYearMonths);
  flag &= GetCalendarDayInfo(localeName, calendarId, 13u, saDayNames);
  flag &= GetCalendarDayInfo(localeName, calendarId, 20u, saAbbrevDayNames);
  flag &= GetCalendarMonthInfo(localeName, calendarId, 21u, saMonthNames);
  flag &= GetCalendarMonthInfo(localeName, calendarId, 34u, saAbbrevMonthNames);
  GetCalendarDayInfo(localeName, calendarId, 55u, saSuperShortDayNames);
  if (calendarId == CalendarId::GREGORIAN) {
    GetCalendarMonthInfo(localeName, calendarId, 268435477u, saMonthGenitiveNames);
    GetCalendarMonthInfo(localeName, calendarId, 268435490u, saAbbrevMonthGenitiveNames);
  }
  CallEnumCalendarInfo(localeName, calendarId, 4u, 0u, saEraNames);
  CallEnumCalendarInfo(localeName, calendarId, 57u, 0u, saAbbrevEraNames);
  saShortDates = CultureData::in::ReescapeWin32Strings(saShortDates);
  saLongDates = CultureData::in::ReescapeWin32Strings(saLongDates);
  saYearMonths = CultureData::in::ReescapeWin32Strings(saYearMonths);
  sMonthDay = CultureData::in::ReescapeWin32String(sMonthDay);
  return flag;
}

void CalendarData___::NormalizeCalendarId(CalendarId& calendarId, String& localeName) {
  switch (calendarId) {
    case CalendarId::JAPANESELUNISOLAR:
      calendarId = CalendarId::JAPAN;
      break;
    case CalendarId::JULIAN:
    case CalendarId::CHINESELUNISOLAR:
    case CalendarId::SAKA:
    case CalendarId::LUNAR_ETO_CHN:
    case CalendarId::LUNAR_ETO_KOR:
    case CalendarId::LUNAR_ETO_ROKUYOU:
    case CalendarId::KOREANLUNISOLAR:
    case CalendarId::TAIWANLUNISOLAR:
      calendarId = CalendarId::GREGORIAN_US;
      break;
  }
  CheckSpecialCalendar(calendarId, localeName);
}

void CalendarData___::CheckSpecialCalendar(CalendarId& calendar, String& localeName) {
  switch (calendar) {
    case CalendarId::GREGORIAN_US:
      {
        String data;
        if (!CallGetCalendarInfoEx(localeName, calendar, 2u, data)) {
          localeName = "fa-IR";
          if (!CallGetCalendarInfoEx(localeName, calendar, 2u, data)) {
            localeName = "en-US";
            calendar = CalendarId::GREGORIAN;
          }
        }
        break;
      }case CalendarId::TAIWAN:
      if (!NlsSystemSupportsTaiwaneseCalendar()) {
        calendar = CalendarId::GREGORIAN;
      }
      break;
  }
}

Boolean CalendarData___::CallEnumCalendarInfo(String localeName, CalendarId calendar, UInt32 calType, UInt32 lcType, Array<String>& data) {
  EnumData value;
  value.userOverride = nullptr;
  value.strings = rt::newobj<List<String>>();
  if (lcType != 0 && ((Int32)lcType & Int32::MinValue) == 0) {
    CalendarId calendarId = (CalendarId)CultureData::in::GetLocaleInfoExInt(localeName, 4105u);
    if (calendarId == calendar) {
      String localeInfoEx = CultureData::in::GetLocaleInfoEx(localeName, lcType);
      if (localeInfoEx != nullptr) {
        value.userOverride = localeInfoEx;
        value.strings->Add(localeInfoEx);
      }
    }
  }
  Interop::Kernel32::EnumCalendarInfoExEx(EnumCalendarInfoCallback, localeName, (UInt32)calendar, nullptr, calType, Unsafe::AsPointer(value));
  if (value.strings->get_Count() == 0) {
    data = nullptr;
    return false;
  }
  Array<String> array = value.strings->ToArray();
  if (calType == 57 || calType == 4) {
    Array<>::in::Reverse(array, 0, array->get_Length());
  }
  data = array;
  return true;
}

Boolean CalendarData___::GetCalendarDayInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings) {
  Boolean flag = true;
  Array<String> array = rt::newarr<Array<String>>(7);
  Int32 num = 0;
  while (num < 7) {
    flag &= CallGetCalendarInfoEx(localeName, calendar, calType, array[num]);
    if (num == 0) {
      calType -= 7;
    }
    num++;
    calType++;
  }
  outputStrings = array;
  return flag;
}

Boolean CalendarData___::GetCalendarMonthInfo(String localeName, CalendarId calendar, UInt32 calType, Array<String>& outputStrings) {
  Array<String> array = rt::newarr<Array<String>>(13);
  Int32 num = 0;
  while (num < 13) {
    if (!CallGetCalendarInfoEx(localeName, calendar, calType, array[num])) {
      array[num] = "";
    }
    num++;
    calType++;
  }
  outputStrings = array;
  return true;
}

Int32 CalendarData___::GetCalendarsCore(String localeName, Boolean useUserOverride, Array<CalendarId> calendars) {
  if (GlobalizationMode::get_UseNls()) {
    return NlsGetCalendars(localeName, useUserOverride, calendars);
  }
  Int32 num = IcuGetCalendars(localeName, calendars);
  if (useUserOverride) {
    Int32 localeInfoExInt = CultureData::in::GetLocaleInfoExInt(localeName, 4105u);
    if (localeInfoExInt != 0 && (UInt32)(UInt16)localeInfoExInt != (UInt32)calendars[0]) {
      CalendarId calendarId = (CalendarId)localeInfoExInt;
      for (Int32 i = 1; i < calendars->get_Length(); i++) {
        if (calendars[i] == calendarId) {
          CalendarId calendarId2 = calendars[0];
          calendars[0] = calendarId;
          calendars[i] = calendarId2;
          return num;
        }
      }
      num = ((num < calendars->get_Length()) ? (num + 1) : num);
      CalendarId as[num] = {};
      Span<CalendarId> span = as;
      Span<CalendarId> span2 = span;
      span2[0] = calendarId;
      span = MemoryExtensions::AsSpan(calendars);
      span = span.Slice(0, num - 1);
      span.CopyTo(span2.Slice(1));
      span2.CopyTo(calendars);
    }
  }
  return num;
}

Int32 CalendarData___::NlsGetCalendars(String localeName, Boolean useUserOverride, Array<CalendarId> calendars) {
  NlsEnumCalendarsData value;
  value.userOverride = 0;
  value.calendars = rt::newobj<List<Int32>>();
  if (useUserOverride) {
    Int32 localeInfoExInt = CultureData::in::GetLocaleInfoExInt(localeName, 4105u);
    if (localeInfoExInt != 0) {
      value.userOverride = localeInfoExInt;
      value.calendars->Add(localeInfoExInt);
    }
  }
  Interop::Kernel32::EnumCalendarInfoExEx(EnumCalendarsCallback, localeName, UInt32::MaxValue, nullptr, 1u, Unsafe::AsPointer(value));
  for (Int32 i = 0; i < Math::Min(calendars->get_Length(), value.calendars->get_Count()); i++) {
    calendars[i] = (CalendarId)value.calendars[i];
  }
  return value.calendars->get_Count();
}

void CalendarData___::cctor() {
  Invariant = CreateInvariant();
}

} // namespace System::Private::CoreLib::System::Globalization::CalendarDataNamespace
