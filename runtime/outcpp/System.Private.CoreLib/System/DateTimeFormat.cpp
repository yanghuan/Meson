#include "DateTimeFormat-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/DayOfWeek.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/Calendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarId.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatFlags.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumber-dep.h>
#include <System.Private.CoreLib/System/Globalization/MonthNameStyles.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfoOptions.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::DateTimeFormatNamespace {
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

void DateTimeFormat::FormatDigits(StringBuilder outputBuffer, Int32 value, Int32 len) {
  FormatDigits(outputBuffer, value, len, false);
}

void DateTimeFormat::FormatDigits(StringBuilder outputBuffer, Int32 value, Int32 len, Boolean overrideLengthLimit) {
  if (!overrideLengthLimit && len > 2) {
    len = 2;
  }
  Char as[16] = {};
  Char* ptr = as;
  Char* ptr2 = ptr + 16;
  Int32 num = value;
  do {
    *(--ptr2) = (Char)(num % 10 + 48);
    num /= 10;
  } while (num != 0 && ptr2 > ptr)
  Int32 i;
  for (i = (Int32)(ptr + 16 - ptr2); i < len; i++) {
    if (ptr2 <= ptr) {
      break;
    }
    *(--ptr2) = 48;
  }
  outputBuffer->Append(ptr2, i);
}

void DateTimeFormat::HebrewFormatDigits(StringBuilder outputBuffer, Int32 digits) {
  HebrewNumber::Append(outputBuffer, digits);
}

Int32 DateTimeFormat::ParseRepeatPattern(ReadOnlySpan<Char> format, Int32 pos, Char patternChar) {
  Int32 length = format.get_Length();
  Int32 i;
  for (i = pos + 1; i < length && format[i] == patternChar; i++) {
  }
  return i - pos;
}

String DateTimeFormat::FormatDayOfWeek(Int32 dayOfWeek, Int32 repeat, DateTimeFormatInfo dtfi) {
  if (repeat == 3) {
    return dtfi->GetAbbreviatedDayName((DayOfWeek)dayOfWeek);
  }
  return dtfi->GetDayName((DayOfWeek)dayOfWeek);
}

String DateTimeFormat::FormatMonth(Int32 month, Int32 repeatCount, DateTimeFormatInfo dtfi) {
  if (repeatCount == 3) {
    return dtfi->GetAbbreviatedMonthName(month);
  }
  return dtfi->GetMonthName(month);
}

String DateTimeFormat::FormatHebrewMonthName(DateTime time, Int32 month, Int32 repeatCount, DateTimeFormatInfo dtfi) {
  if (dtfi->get_Calendar()->IsLeapYear(dtfi->get_Calendar()->GetYear(time))) {
    return dtfi->InternalGetMonthName(month, MonthNameStyles::LeapYear, repeatCount == 3);
  }
  if (month >= 7) {
    month++;
  }
  if (repeatCount == 3) {
    return dtfi->GetAbbreviatedMonthName(month);
  }
  return dtfi->GetMonthName(month);
}

Int32 DateTimeFormat::ParseQuoteString(ReadOnlySpan<Char> format, Int32 pos, StringBuilder result) {
  Int32 length = format.get_Length();
  Int32 num = pos;
  Char c = format[pos++];
  Boolean flag = false;
  while (pos < length) {
    Char c2 = format[pos++];
    if (c2 == c) {
      flag = true;
      break;
    }
    if (c2 == 92) {
      if (pos >= length) {
        rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
      }
      result->Append(format[pos++]);
    } else {
      result->Append(c2);
    }
  }
  if (!flag) {
    rt::throw_exception<FormatException>(SR::Format(SR::get_Format_BadQuote(), c));
  }
  return pos - num;
}

Int32 DateTimeFormat::ParseNextChar(ReadOnlySpan<Char> format, Int32 pos) {
  if (pos >= format.get_Length() - 1) {
    return -1;
  }
  return format[pos + 1];
}

Boolean DateTimeFormat::IsUseGenitiveForm(ReadOnlySpan<Char> format, Int32 index, Int32 tokenLen, Char patternToMatch) {
  Int32 num = 0;
  Int32 num2 = index - 1;
  while (num2 >= 0 && format[num2] != patternToMatch) {
    num2--;
  }
  if (num2 >= 0) {
    while (--num2 >= 0 && format[num2] == patternToMatch) {
      num++;
    }
    if (num <= 1) {
      return true;
    }
  }
  for (num2 = index + tokenLen; num2 < format.get_Length() && format[num2] != patternToMatch; num2++) {
  }
  if (num2 < format.get_Length()) {
    num = 0;
    while (++num2 < format.get_Length() && format[num2] == patternToMatch) {
      num++;
    }
    if (num <= 1) {
      return true;
    }
  }
  return false;
}

StringBuilder DateTimeFormat::FormatCustomized(DateTime dateTime, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, TimeSpan offset, StringBuilder result) {
  Calendar calendar = dtfi->get_Calendar();
  Boolean flag = false;
  if (result == nullptr) {
    flag = true;
    result = StringBuilderCache::Acquire();
  }
  Boolean flag2 = calendar->get_ID() == CalendarId::HEBREW;
  Boolean flag3 = calendar->get_ID() == CalendarId::JAPAN;
  Boolean timeOnly = true;
  Int32 num;
  for (Int32 i = 0; i < format.get_Length(); i += num) {
    Char c = format[i];
    switch (c.get()) {
      case 103:
        num = ParseRepeatPattern(format, i, c);
        result->Append(dtfi->GetEraName(calendar->GetEra(dateTime)));
        break;
      case 104:
        {
          num = ParseRepeatPattern(format, i, c);
          Int32 num3 = dateTime.get_Hour() % 12;
          if (num3 == 0) {
            num3 = 12;
          }
          FormatDigits(result, num3, num);
          break;
        }case 72:
        num = ParseRepeatPattern(format, i, c);
        FormatDigits(result, dateTime.get_Hour(), num);
        break;
      case 109:
        num = ParseRepeatPattern(format, i, c);
        FormatDigits(result, dateTime.get_Minute(), num);
        break;
      case 115:
        num = ParseRepeatPattern(format, i, c);
        FormatDigits(result, dateTime.get_Second(), num);
        break;
      case 70:
      case 102:
        num = ParseRepeatPattern(format, i, c);
        if (num <= 7) {
          Int64 num4 = dateTime.get_Ticks() % 10000000;
          num4 /= (Int64)Math::Pow(10, 7 - num);
          if (c == 102) {
            result->AppendSpanFormattable((Int32)num4, fixedNumberFormats[num - 1], CultureInfo::in::get_InvariantCulture());
            break;
          }
          Int32 num5 = num;
          while (num5 > 0 && num4 % 10 == 0) {
            num4 /= 10;
            num5--;
          }
          if (num5 > 0) {
            result->AppendSpanFormattable((Int32)num4, fixedNumberFormats[num5 - 1], CultureInfo::in::get_InvariantCulture());
          } else if (result->get_Length() > 0 && result[result->get_Length() - 1] == 46) {
            result->Remove(result->get_Length() - 1, 1);
          }

          break;
        }
        if (flag) {
          StringBuilderCache::Release(result);
        }
        rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
      case 116:
        num = ParseRepeatPattern(format, i, c);
        if (num == 1) {
          if (dateTime.get_Hour() < 12) {
            if (dtfi->get_AMDesignator()->get_Length() >= 1) {
              result->Append(dtfi->get_AMDesignator()[0]);
            }
          } else if (dtfi->get_PMDesignator()->get_Length() >= 1) {
            result->Append(dtfi->get_PMDesignator()[0]);
          }

        } else {
          result->Append((dateTime.get_Hour() < 12) ? dtfi->get_AMDesignator() : dtfi->get_PMDesignator());
        }
        break;
      case 100:
        num = ParseRepeatPattern(format, i, c);
        if (num <= 2) {
          Int32 dayOfMonth = calendar->GetDayOfMonth(dateTime);
          if (flag2) {
            HebrewFormatDigits(result, dayOfMonth);
          } else {
            FormatDigits(result, dayOfMonth, num);
          }
        } else {
          Int32 dayOfWeek = (Int32)calendar->GetDayOfWeek(dateTime);
          result->Append(FormatDayOfWeek(dayOfWeek, num, dtfi));
        }
        timeOnly = false;
        break;
      case 77:
        {
          num = ParseRepeatPattern(format, i, c);
          Int32 month = calendar->GetMonth(dateTime);
          if (num <= 2) {
            if (flag2) {
              HebrewFormatDigits(result, month);
            } else {
              FormatDigits(result, month, num);
            }
          } else if (flag2) {
            result->Append(FormatHebrewMonthName(dateTime, month, num, dtfi));
          } else if ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseGenitiveMonth) != 0) {
            result->Append(dtfi->InternalGetMonthName(month, IsUseGenitiveForm(format, i, num, 100) ? MonthNameStyles::Genitive : MonthNameStyles::Regular, num == 3));
          } else {
            result->Append(FormatMonth(month, num, dtfi));
          }


          timeOnly = false;
          break;
        }case 121:
        {
          Int32 year = calendar->GetYear(dateTime);
          num = ParseRepeatPattern(format, i, c);
          if (flag3 && !LocalAppContextSwitches::get_FormatJapaneseFirstYearAsANumber() && year == 1 && ((i + num < format.get_Length() && format[i + num] == 24180) || (i + num < format.get_Length() - 1 && format[i + num] == 39 && format[i + num + 1] == 24180))) {
            result->Append("元"[0]);
          } else if (dtfi->get_HasForceTwoDigitYears()) {
            FormatDigits(result, year, (num <= 2) ? num : 2);
          } else if (calendar->get_ID() == CalendarId::HEBREW) {
            HebrewFormatDigits(result, year);
          } else if (num <= 2) {
            FormatDigits(result, year % 100, num);
          } else if (num <= 16) {
            FormatDigits(result, year, num, true);
          } else {
            result->Append(year.ToString("D" + num, CultureInfo::in::get_InvariantCulture()));
          }




          timeOnly = false;
          break;
        }case 122:
        num = ParseRepeatPattern(format, i, c);
        FormatCustomizedTimeZone(dateTime, offset, num, timeOnly, result);
        break;
      case 75:
        num = 1;
        FormatCustomizedRoundripTimeZone(dateTime, offset, result);
        break;
      case 58:
        result->Append(dtfi->get_TimeSeparator());
        num = 1;
        break;
      case 47:
        result->Append(dtfi->get_DateSeparator());
        num = 1;
        break;
      case 34:
      case 39:
        num = ParseQuoteString(format, i, result);
        break;
      case 37:
        {
          Int32 num2 = ParseNextChar(format, i);
          if (num2 >= 0 && num2 != 37) {
            Char reference = (Char)num2;
            StringBuilder stringBuilder = FormatCustomized(dateTime, MemoryMarshal::CreateReadOnlySpan(reference, 1), dtfi, offset, result);
            num = 2;
            break;
          }
          if (flag) {
            StringBuilderCache::Release(result);
          }
          rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
        }case 92:
        {
          Int32 num2 = ParseNextChar(format, i);
          if (num2 >= 0) {
            result->Append((Char)num2);
            num = 2;
            break;
          }
          if (flag) {
            StringBuilderCache::Release(result);
          }
          rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
        }default:
        result->Append(c);
        num = 1;
        break;
    }
  }
  return result;
}

void DateTimeFormat::FormatCustomizedTimeZone(DateTime dateTime, TimeSpan offset, Int32 tokenLen, Boolean timeOnly, StringBuilder result) {
  if (offset.get_Ticks() == Int64::MinValue) {
    offset = ((timeOnly && dateTime.get_Ticks() < 864000000000) ? TimeZoneInfo::in::GetLocalUtcOffset(DateTime::get_Now(), TimeZoneInfoOptions::NoThrowOnInvalidTime) : ((dateTime.get_Kind() != DateTimeKind::Utc) ? TimeZoneInfo::in::GetLocalUtcOffset(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime) : rt::default__));
  }
  if (offset.get_Ticks() >= 0) {
    result->Append(43);
  } else {
    result->Append(45);
    offset = offset.Negate();
  }
  if (tokenLen <= 1) {
    result->AppendFormat(CultureInfo::in::get_InvariantCulture(), "{0:0}", offset.get_Hours());
    return;
  }
  result->AppendFormat(CultureInfo::in::get_InvariantCulture(), "{0:00}", offset.get_Hours());
  if (tokenLen >= 3) {
    result->AppendFormat(CultureInfo::in::get_InvariantCulture(), ":{0:00}", offset.get_Minutes());
  }
}

void DateTimeFormat::FormatCustomizedRoundripTimeZone(DateTime dateTime, TimeSpan offset, StringBuilder result) {
  if (offset.get_Ticks() == Int64::MinValue) {
    switch (dateTime.get_Kind()) {
      default:
        return;
      case DateTimeKind::Local:
        break;
      case DateTimeKind::Utc:
        result->Append(90);
        return;
    }
    offset = TimeZoneInfo::in::GetLocalUtcOffset(dateTime, TimeZoneInfoOptions::NoThrowOnInvalidTime);
  }
  if (offset.get_Ticks() >= 0) {
    result->Append(43);
  } else {
    result->Append(45);
    offset = offset.Negate();
  }
  Append2DigitNumber(result, offset.get_Hours());
  result->Append(58);
  Append2DigitNumber(result, offset.get_Minutes());
}

void DateTimeFormat::Append2DigitNumber(StringBuilder result, Int32 val) {
  result->Append((Char)(48 + val / 10));
  result->Append((Char)(48 + val % 10));
}

String DateTimeFormat::GetRealFormat(ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi) {
  switch (format[0].get()) {
    case 100:
      return dtfi->get_ShortDatePattern();
    case 68:
      return dtfi->get_LongDatePattern();
    case 102:
      return dtfi->get_LongDatePattern() + " " + dtfi->get_ShortTimePattern();
    case 70:
      return dtfi->get_FullDateTimePattern();
    case 103:
      return dtfi->get_GeneralShortTimePattern();
    case 71:
      return dtfi->get_GeneralLongTimePattern();
    case 77:
    case 109:
      return dtfi->get_MonthDayPattern();
    case 79:
    case 111:
      return "yyyy'-'MM'-'dd'T'HH':'mm':'ss.fffffffK";
    case 82:
    case 114:
      return dtfi->get_RFC1123Pattern();
    case 115:
      return dtfi->get_SortableDateTimePattern();
    case 116:
      return dtfi->get_ShortTimePattern();
    case 84:
      return dtfi->get_LongTimePattern();
    case 117:
      return dtfi->get_UniversalSortableDateTimePattern();
    case 85:
      return dtfi->get_FullDateTimePattern();
    case 89:
    case 121:
      return dtfi->get_YearMonthPattern();
    default:
      rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
  }
}

String DateTimeFormat::ExpandPredefinedFormat(ReadOnlySpan<Char> format, DateTime& dateTime, DateTimeFormatInfo& dtfi, TimeSpan offset) {
  switch (format[0].get()) {
    case 79:
    case 111:
      dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
      break;
    case 82:
    case 114:
    case 117:
      if (offset.get_Ticks() != Int64::MinValue) {
        dateTime -= offset;
      }
      dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
      break;
    case 115:
      dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
      break;
    case 85:
      if (offset.get_Ticks() != Int64::MinValue) {
        rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
      }
      dtfi = (DateTimeFormatInfo)dtfi->Clone();
      if (dtfi->get_Calendar()->GetType() != typeof<GregorianCalendar>()) {
        dtfi->set_Calendar(GregorianCalendar::in::GetDefaultInstance());
      }
      dateTime = dateTime.ToUniversalTime();
      break;
  }
  return GetRealFormat(format, dtfi);
}

String DateTimeFormat::Format(DateTime dateTime, String format, IFormatProvider provider) {
  return Format(dateTime, format, provider, TimeSpan(Int64::MinValue));
}

String DateTimeFormat::Format(DateTime dateTime, String format, IFormatProvider provider, TimeSpan offset) {
  if (format != nullptr && format->get_Length() == 1) {
    switch (format[0].get()) {
      case 79:
      case 111:
        {
          Char as[33] = {};
          Span<Char> destination = as;
          Int32 charsWritten2;
          TryFormatO(dateTime, offset, destination, charsWritten2);
          return destination.Slice(0, charsWritten2).ToString();
        }case 82:
      case 114:
        {
          String text = String::in::FastAllocateString(29);
          Int32 charsWritten;
          TryFormatR(dateTime, offset, Span<Char>(text->GetRawStringData(), text->get_Length()), charsWritten);
          return text;
        }}
  }
  DateTimeFormatInfo instance = DateTimeFormatInfo::in::GetInstance(provider);
  return StringBuilderCache::GetStringAndRelease(FormatStringBuilder(dateTime, format, instance, offset));
}

Boolean DateTimeFormat::TryFormat(DateTime dateTime, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider) {
  return TryFormat(dateTime, destination, charsWritten, format, provider, TimeSpan(Int64::MinValue));
}

Boolean DateTimeFormat::TryFormat(DateTime dateTime, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider provider, TimeSpan offset) {
  if (format.get_Length() == 1) {
    switch (format[0].get()) {
      case 79:
      case 111:
        return TryFormatO(dateTime, offset, destination, charsWritten);
      case 82:
      case 114:
        return TryFormatR(dateTime, offset, destination, charsWritten);
    }
  }
  DateTimeFormatInfo instance = DateTimeFormatInfo::in::GetInstance(provider);
  StringBuilder stringBuilder = FormatStringBuilder(dateTime, format, instance, offset);
  Boolean flag = stringBuilder->get_Length() <= destination.get_Length();
  if (flag) {
    stringBuilder->CopyTo(0, destination, stringBuilder->get_Length());
    charsWritten = stringBuilder->set_Length();
  } else {
    charsWritten = 0;
  }
  StringBuilderCache::Release(stringBuilder);
  return flag;
}

StringBuilder DateTimeFormat::FormatStringBuilder(DateTime dateTime, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, TimeSpan offset) {
  if (format.get_Length() == 0) {
    Boolean flag = false;
    if (dateTime.get_Ticks() < 864000000000) {
      switch (dtfi->get_Calendar()->get_ID()) {
        case CalendarId::JAPAN:
        case CalendarId::TAIWAN:
        case CalendarId::HIJRI:
        case CalendarId::HEBREW:
        case CalendarId::JULIAN:
        case CalendarId::PERSIAN:
        case CalendarId::UMALQURA:
          flag = true;
          dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
          break;
      }
    }
    format = ((offset.get_Ticks() != Int64::MinValue) ? ((ReadOnlySpan<Char>)(flag ? "yyyy'-'MM'-'ddTHH':'mm':'ss zzz" : dtfi->get_DateTimeOffsetPattern())) : ((ReadOnlySpan<Char>)(flag ? "s" : "G")));
  }
  if (format.get_Length() == 1) {
    format = ExpandPredefinedFormat(format, dateTime, dtfi, offset);
  }
  return FormatCustomized(dateTime, format, dtfi, offset, nullptr);
}

Boolean DateTimeFormat::TryFormatO(DateTime dateTime, TimeSpan offset, Span<Char> destination, Int32& charsWritten) {
  Int32 num = 27;
  DateTimeKind dateTimeKind = DateTimeKind::Local;
  if (offset.get_Ticks() == Int64::MinValue) {
    dateTimeKind = dateTime.get_Kind();
    switch (dateTimeKind) {
      case DateTimeKind::Local:
        offset = TimeZoneInfo::in::get_Local()->GetUtcOffset(dateTime);
        num += 6;
        break;
      case DateTimeKind::Utc:
        num++;
        break;
    }
  } else {
    num += 6;
  }
  if (destination.get_Length() < num) {
    charsWritten = 0;
    return false;
  }
  charsWritten = num;
  Char& reference = destination[26];
  Int32 year;
  Int32 month;
  Int32 day;
  dateTime.GetDate(year, month, day);
  Int32 hour;
  Int32 minute;
  Int32 second;
  Int32 tick;
  dateTime.GetTimePrecise(hour, minute, second, tick);
  WriteFourDecimalDigits((UInt32)year, destination);
  destination[4] = 45;
  WriteTwoDecimalDigits((UInt32)month, destination, 5);
  destination[7] = 45;
  WriteTwoDecimalDigits((UInt32)day, destination, 8);
  destination[10] = 84;
  WriteTwoDecimalDigits((UInt32)hour, destination, 11);
  destination[13] = 58;
  WriteTwoDecimalDigits((UInt32)minute, destination, 14);
  destination[16] = 58;
  WriteTwoDecimalDigits((UInt32)second, destination, 17);
  destination[19] = 46;
  WriteDigits((UInt32)tick, destination.Slice(20, 7));
  switch (dateTimeKind) {
    case DateTimeKind::Local:
      {
        Int32 num2 = (Int32)(offset.get_Ticks() / 600000000);
        Char c;
        if (num2 < 0) {
          c = 45;
          num2 = -num2;
        } else {
          c = 43;
        }
        Int32 result;
        Int32 value = Math::DivRem(num2, 60, result);
        WriteTwoDecimalDigits((UInt32)result, destination, 31);
        destination[30] = 58;
        WriteTwoDecimalDigits((UInt32)value, destination, 28);
        destination[27] = c;
        break;
      }case DateTimeKind::Utc:
      destination[27] = 90;
      break;
  }
  return true;
}

Boolean DateTimeFormat::TryFormatR(DateTime dateTime, TimeSpan offset, Span<Char> destination, Int32& charsWritten) {
  if (28u >= (UInt32)destination.get_Length()) {
    charsWritten = 0;
    return false;
  }
  if (offset.get_Ticks() != Int64::MinValue) {
    dateTime -= offset;
  }
  Int32 year;
  Int32 month;
  Int32 day;
  dateTime.GetDate(year, month, day);
  Int32 hour;
  Int32 minute;
  Int32 second;
  dateTime.GetTime(hour, minute, second);
  String text = InvariantAbbreviatedDayNames[(Int32)dateTime.get_DayOfWeek()];
  String text2 = InvariantAbbreviatedMonthNames[month - 1];
  destination[0] = text[0];
  destination[1] = text[1];
  destination[2] = text[2];
  destination[3] = 44;
  destination[4] = 32;
  WriteTwoDecimalDigits((UInt32)day, destination, 5);
  destination[7] = 32;
  destination[8] = text2[0];
  destination[9] = text2[1];
  destination[10] = text2[2];
  destination[11] = 32;
  WriteFourDecimalDigits((UInt32)year, destination, 12);
  destination[16] = 32;
  WriteTwoDecimalDigits((UInt32)hour, destination, 17);
  destination[19] = 58;
  WriteTwoDecimalDigits((UInt32)minute, destination, 20);
  destination[22] = 58;
  WriteTwoDecimalDigits((UInt32)second, destination, 23);
  destination[25] = 32;
  destination[26] = 71;
  destination[27] = 77;
  destination[28] = 84;
  charsWritten = 29;
  return true;
}

void DateTimeFormat::WriteTwoDecimalDigits(UInt32 value, Span<Char> destination, Int32 offset) {
  UInt32 num = 48 + value;
  value /= 10u;
  destination[offset + 1] = (Char)(num - value * 10);
  destination[offset] = (Char)(48 + value);
}

void DateTimeFormat::WriteFourDecimalDigits(UInt32 value, Span<Char> buffer, Int32 startingIndex) {
  UInt32 num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 3] = (Char)(num - value * 10);
  num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 2] = (Char)(num - value * 10);
  num = 48 + value;
  value /= 10u;
  buffer[startingIndex + 1] = (Char)(num - value * 10);
  buffer[startingIndex] = (Char)(48 + value);
}

void DateTimeFormat::WriteDigits(UInt64 value, Span<Char> buffer) {
  for (Int32 num = buffer.get_Length() - 1; num >= 1; num--) {
    UInt64 num2 = 48 + value;
    value /= 10;
    buffer[num] = (Char)(num2 - value * 10);
  }
  buffer[0] = (Char)(48 + value);
}

Array<String> DateTimeFormat::GetAllDateTimes(DateTime dateTime, Char format, DateTimeFormatInfo dtfi) {
  Array<String> array;
  switch (format.get()) {
    case 68:
    case 70:
    case 71:
    case 77:
    case 84:
    case 89:
    case 100:
    case 102:
    case 103:
    case 109:
    case 116:
    case 121:
      {
        Array<String> allDateTimePatterns = dtfi->GetAllDateTimePatterns(format);
        array = rt::newarr<Array<String>>(allDateTimePatterns->get_Length());
        for (Int32 j = 0; j < allDateTimePatterns->get_Length(); j++) {
          array[j] = Format(dateTime, allDateTimePatterns[j], dtfi);
        }
        break;
      }case 85:
      {
        DateTime dateTime2 = dateTime.ToUniversalTime();
        Array<String> allDateTimePatterns = dtfi->GetAllDateTimePatterns(format);
        array = rt::newarr<Array<String>>(allDateTimePatterns->get_Length());
        for (Int32 i = 0; i < allDateTimePatterns->get_Length(); i++) {
          array[i] = Format(dateTime2, allDateTimePatterns[i], dtfi);
        }
        break;
      }case 79:
    case 82:
    case 111:
    case 114:
    case 115:
    case 117:
      array = rt::newarr<Array<String>>(1);
      break;
    default:
      rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
  }
  return array;
}

Array<String> DateTimeFormat::GetAllDateTimes(DateTime dateTime, DateTimeFormatInfo dtfi) {
  List<String> list = rt::newobj<List<String>>(132);
  for (Int32 i = 0; i < allStandardFormats->get_Length(); i++) {
    Array<String> allDateTimes = GetAllDateTimes(dateTime, allStandardFormats[i], dtfi);
    for (Int32 j = 0; j < allDateTimes->get_Length(); j++) {
      list->Add(allDateTimes[j]);
    }
  }
  return list->ToArray();
}

void DateTimeFormat::cctor() {
  allStandardFormats = rt::newarr<Array<Char>>(19);
  InvariantFormatInfo = CultureInfo::in::get_InvariantCulture()->set_DateTimeFormat();
  InvariantAbbreviatedMonthNames = InvariantFormatInfo->set_AbbreviatedMonthNames();
  InvariantAbbreviatedDayNames = InvariantFormatInfo->set_AbbreviatedDayNames();
  fixedNumberFormats = rt::newarr<Array<String>>(7);
}

} // namespace System::Private::CoreLib::System::DateTimeFormatNamespace
