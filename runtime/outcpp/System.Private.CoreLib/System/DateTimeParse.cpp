#include "DateTimeParse-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/DateTimeKind.h>
#include <System.Private.CoreLib/System/DateTimeParse-dep.h>
#include <System.Private.CoreLib/System/DateTimeResult-dep.h>
#include <System.Private.CoreLib/System/DayOfWeek.h>
#include <System.Private.CoreLib/System/DTSubString-dep.h>
#include <System.Private.CoreLib/System/DTSubStringType.h>
#include <System.Private.CoreLib/System/Globalization/Calendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarId.h>
#include <System.Private.CoreLib/System/Globalization/CompareOptions.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatFlags.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumber-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumberParsingContext-dep.h>
#include <System.Private.CoreLib/System/Globalization/HebrewNumberParsingState.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/TaiwanCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanParse-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ParseFailureKind.h>
#include <System.Private.CoreLib/System/ParseFlags.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfoOptions.h>
#include <System.Private.CoreLib/System/TokenType.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::DateTimeParseNamespace {
using namespace System::Globalization;
using namespace System::Text;

DateTime DateTimeParse::ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style) {
  DateTimeResult result;
  result.Init(s);
  if (TryParseExact(s, format, dtfi, style, result)) {
    return result.parsedDate;
  }
  rt::throw_exception(GetDateTimeParseException(result));
}

DateTime DateTimeParse::ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, TimeSpan& offset) {
  DateTimeResult result;
  result.Init(s);
  result.flags |= ParseFlags::CaptureOffset;
  if (TryParseExact(s, format, dtfi, style, result)) {
    offset = result.timeZoneOffset;
    return result.parsedDate;
  }
  rt::throw_exception(GetDateTimeParseException(result));
}

Boolean DateTimeParse::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result) {
  DateTimeResult result2;
  result2.Init(s);
  if (TryParseExact(s, format, dtfi, style, result2)) {
    result = result2.parsedDate;
    return true;
  }
  result = DateTime::MinValue;
  return false;
}

Boolean DateTimeParse::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result, TimeSpan& offset) {
  DateTimeResult result2;
  result2.Init(s);
  result2.flags |= ParseFlags::CaptureOffset;
  if (TryParseExact(s, format, dtfi, style, result2)) {
    result = result2.parsedDate;
    offset = result2.timeZoneOffset;
    return true;
  }
  result = DateTime::MinValue;
  offset = TimeSpan::Zero;
  return false;
}

Boolean DateTimeParse::TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTimeResult& result) {
  if (s.get_Length() == 0) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDateTime");
    return false;
  }
  if (format.get_Length() == 0) {
    result.SetBadFormatSpecifierFailure();
    return false;
  }
  return DoStrictParse(s, format, style, dtfi, result);
}

DateTime DateTimeParse::ParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style) {
  DateTimeResult result;
  result.Init(s);
  if (TryParseExactMultiple(s, formats, dtfi, style, result)) {
    return result.parsedDate;
  }
  rt::throw_exception(GetDateTimeParseException(result));
}

DateTime DateTimeParse::ParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, TimeSpan& offset) {
  DateTimeResult result;
  result.Init(s);
  result.flags |= ParseFlags::CaptureOffset;
  if (TryParseExactMultiple(s, formats, dtfi, style, result)) {
    offset = result.timeZoneOffset;
    return result.parsedDate;
  }
  rt::throw_exception(GetDateTimeParseException(result));
}

Boolean DateTimeParse::TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result, TimeSpan& offset) {
  DateTimeResult result2;
  result2.Init(s);
  result2.flags |= ParseFlags::CaptureOffset;
  if (TryParseExactMultiple(s, formats, dtfi, style, result2)) {
    result = result2.parsedDate;
    offset = result2.timeZoneOffset;
    return true;
  }
  result = DateTime::MinValue;
  offset = TimeSpan::Zero;
  return false;
}

Boolean DateTimeParse::TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result) {
  DateTimeResult result2;
  result2.Init(s);
  if (TryParseExactMultiple(s, formats, dtfi, style, result2)) {
    result = result2.parsedDate;
    return true;
  }
  result = DateTime::MinValue;
  return false;
}

Boolean DateTimeParse::TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTimeResult& result) {
  if (formats == nullptr) {
    result.SetFailure(ParseFailureKind::ArgumentNull, "ArgumentNull_String", nullptr, "formats");
    return false;
  }
  if (s.get_Length() == 0) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDateTime");
    return false;
  }
  if (formats->get_Length() == 0) {
    result.SetFailure(ParseFailureKind::Format, "Format_NoFormatSpecifier");
    return false;
  }
  for (Int32 i = 0; i < formats->get_Length(); i++) {
    if (formats[i] == nullptr || formats[i]->get_Length() == 0) {
      result.SetBadFormatSpecifierFailure();
      return false;
    }
    DateTimeResult result2;
    result2.Init(s);
    result2.flags = result.flags;
    if (TryParseExact(s, formats[i], dtfi, style, result2)) {
      result.parsedDate = result2.parsedDate;
      result.timeZoneOffset = result2.timeZoneOffset;
      return true;
    }
  }
  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::MatchWord(__DTString& str, String target) {
  if (target->get_Length() > str.Value.get_Length() - str.Index) {
    return false;
  }
  if (str.get_CompareInfo()->Compare(str.Value.Slice(str.Index, target->get_Length()), target, CompareOptions::IgnoreCase) != 0) {
    return false;
  }
  Int32 num = str.Index + target->get_Length();
  if (num < str.Value.get_Length()) {
    Char c = str.Value[num];
    if (Char::IsLetter(c)) {
      return false;
    }
  }
  str.Index = num;
  if (str.Index < str.get_Length()) {
    str.m_current = str.Value[str.Index];
  }
  return true;
}

Boolean DateTimeParse::GetTimeZoneName(__DTString& str) {
  if (MatchWord(str, "GMT")) {
    return true;
  }
  if (MatchWord(str, "Z")) {
    return true;
  }
  return false;
}

Boolean DateTimeParse::IsDigit(Char ch) {
  return (UInt32)(ch - 48) <= 9u;
}

Boolean DateTimeParse::ParseFraction(__DTString& str, Double& result) {
  result = 0;
  Double num = 0.1;
  Int32 num2 = 0;
  Char current;
  while (str.GetNext() && IsDigit(current = str.m_current)) {
    result += (Double)(current - 48) * num;
    num *= 0.1;
    num2++;
  }
  return num2 > 0;
}

Boolean DateTimeParse::ParseTimeZone(__DTString& str, TimeSpan& result) {
  Int32 num = 0;
  DTSubString subString = str.GetSubString();
  if (subString.length != 1) {
    return false;
  }
  Char c = subString[0];
  if (c != u'+' && c != u'-') {
    return false;
  }
  str.ConsumeSubString(subString);
  subString = str.GetSubString();
  if (subString.type != DTSubStringType::Number) {
    return false;
  }
  Int32 value = subString.value;
  Int32 hours;
  switch (subString.length.get()) {
    case 1:
    case 2:
      hours = value;
      str.ConsumeSubString(subString);
      subString = str.GetSubString();
      if (subString.length == 1 && subString[0] == u':') {
        str.ConsumeSubString(subString);
        subString = str.GetSubString();
        if (subString.type != DTSubStringType::Number || subString.length < 1 || subString.length > 2) {
          return false;
        }
        num = subString.value;
        str.ConsumeSubString(subString);
      }
      break;
    case 3:
    case 4:
      hours = value / 100;
      num = value % 100;
      str.ConsumeSubString(subString);
      break;
    default:
      return false;
  }
  if (num < 0 || num >= 60) {
    return false;
  }
  result = TimeSpan(hours, num, 0);
  if (c == u'-') {
    result = result.Negate();
  }
  return true;
}

Boolean DateTimeParse::HandleTimeZone(__DTString& str, DateTimeResult& result) {
  if (str.Index < str.get_Length() - 1) {
    Char c = str.Value[str.Index];
    Int32 num = 0;
    while (Char::IsWhiteSpace(c) && str.Index + num < str.get_Length() - 1) {
      num++;
      c = str.Value[str.Index + num];
    }
    if (c == u'+' || c == u'-') {
      str.Index += num;
      if ((result.flags & ParseFlags::TimeZoneUsed) != 0) {
        result.SetBadDateTimeFailure();
        return false;
      }
      result.flags |= ParseFlags::TimeZoneUsed;
      if (!ParseTimeZone(str, result.timeZoneOffset)) {
        result.SetBadDateTimeFailure();
        return false;
      }
    }
  }
  return true;
}

Boolean DateTimeParse::Lex(DS dps, __DTString& str, DateTimeToken& dtok, DateTimeRawInfo& raw, DateTimeResult& result, DateTimeFormatInfo& dtfi, DateTimeStyles styles) {
  dtok.dtt = DTT::Unk;
  TokenType tokenType;
  Int32 tokenValue;
  str.GetRegularToken(tokenType, tokenValue, dtfi);
  Int32 indexBeforeSeparator;
  Char charBeforeSeparator;
  switch (tokenType) {
    case TokenType::NumberToken:
    case TokenType::YearNumberToken:
      {
        if (raw.numCount == 3 || tokenValue == -1) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if (dps == DS::T_NNt && str.Index < str.get_Length() - 1) {
          Char c = str.Value[str.Index];
          if (c == u'.') {
            ParseFraction(str, raw.fraction);
          }
        }
        if ((dps == DS::T_NNt || dps == DS::T_Nt) && str.Index < str.get_Length() - 1 && !HandleTimeZone(str, result)) {
          return false;
        }
        dtok.num = tokenValue;
        TokenType separatorToken;
        if (tokenType == TokenType::YearNumberToken) {
          if (raw.year == -1) {
            raw.year = tokenValue;
            switch (separatorToken = str.GetSeparatorToken(dtfi, indexBeforeSeparator, charBeforeSeparator)) {
              case TokenType::SEP_End:
                dtok.dtt = DTT::YearEnd;
                break;
              case TokenType::SEP_Am:
              case TokenType::SEP_Pm:
                if (raw.timeMark == TM::NotSet) {
                  raw.timeMark = ((separatorToken != TokenType::SEP_Am) ? TM::PM : TM::AM);
                  dtok.dtt = DTT::YearSpace;
                } else {
                  result.SetBadDateTimeFailure();
                }
                break;
              case TokenType::SEP_Space:
                dtok.dtt = DTT::YearSpace;
                break;
              case TokenType::SEP_Date:
                dtok.dtt = DTT::YearDateSep;
                break;
              case TokenType::SEP_Time:
                if (!raw.hasSameDateAndTimeSeparators) {
                  result.SetBadDateTimeFailure();
                  return false;
                }
                dtok.dtt = DTT::YearDateSep;
                break;
              case TokenType::SEP_DateOrOffset:
                if (s_dateParsingStates[(Int32)dps][13] == DS::ERROR && s_dateParsingStates[(Int32)dps][12] > DS::ERROR) {
                  str.Index = indexBeforeSeparator;
                  str.m_current = charBeforeSeparator;
                  dtok.dtt = DTT::YearSpace;
                } else {
                  dtok.dtt = DTT::YearDateSep;
                }
                break;
              case TokenType::SEP_YearSuff:
              case TokenType::SEP_MonthSuff:
              case TokenType::SEP_DaySuff:
                dtok.dtt = DTT::NumDatesuff;
                dtok.suffix = separatorToken;
                break;
              case TokenType::SEP_HourSuff:
              case TokenType::SEP_MinuteSuff:
              case TokenType::SEP_SecondSuff:
                dtok.dtt = DTT::NumTimesuff;
                dtok.suffix = separatorToken;
                break;
              default:
                result.SetBadDateTimeFailure();
                return false;
            }
            return true;
          }
          result.SetBadDateTimeFailure();
          return false;
        }
        switch (separatorToken = str.GetSeparatorToken(dtfi, indexBeforeSeparator, charBeforeSeparator)) {
          case TokenType::SEP_End:
            dtok.dtt = DTT::NumEnd;
            raw.AddNumber(dtok.num);
            break;
          case TokenType::SEP_Am:
          case TokenType::SEP_Pm:
            if (raw.timeMark == TM::NotSet) {
              raw.timeMark = ((separatorToken != TokenType::SEP_Am) ? TM::PM : TM::AM);
              dtok.dtt = DTT::NumAmpm;
              if (dps == DS::D_NN && !ProcessTerminalState(DS::DX_NN, result, styles, raw, dtfi)) {
                return false;
              }
              raw.AddNumber(dtok.num);
              if ((dps == DS::T_NNt || dps == DS::T_Nt) && !HandleTimeZone(str, result)) {
                return false;
              }
            } else {
              result.SetBadDateTimeFailure();
            }
            break;
          case TokenType::SEP_Space:
            dtok.dtt = DTT::NumSpace;
            raw.AddNumber(dtok.num);
            break;
          case TokenType::SEP_Date:
            dtok.dtt = DTT::NumDatesep;
            raw.AddNumber(dtok.num);
            break;
          case TokenType::SEP_DateOrOffset:
            if (s_dateParsingStates[(Int32)dps][4] == DS::ERROR && s_dateParsingStates[(Int32)dps][3] > DS::ERROR) {
              str.Index = indexBeforeSeparator;
              str.m_current = charBeforeSeparator;
              dtok.dtt = DTT::NumSpace;
            } else {
              dtok.dtt = DTT::NumDatesep;
            }
            raw.AddNumber(dtok.num);
            break;
          case TokenType::SEP_Time:
            if (raw.hasSameDateAndTimeSeparators && (dps == DS::D_Y || dps == DS::D_YN || dps == DS::D_YNd || dps == DS::D_YM || dps == DS::D_YMd)) {
              dtok.dtt = DTT::NumDatesep;
              raw.AddNumber(dtok.num);
            } else {
              dtok.dtt = DTT::NumTimesep;
              raw.AddNumber(dtok.num);
            }
            break;
          case TokenType::SEP_YearSuff:
            try {
              dtok.num = dtfi->get_Calendar()->ToFourDigitYear(tokenValue);
            } catch (ArgumentOutOfRangeException) {
              result.SetBadDateTimeFailure();
              return false;
            }
            dtok.dtt = DTT::NumDatesuff;
            dtok.suffix = separatorToken;
            break;
          case TokenType::SEP_MonthSuff:
          case TokenType::SEP_DaySuff:
            dtok.dtt = DTT::NumDatesuff;
            dtok.suffix = separatorToken;
            break;
          case TokenType::SEP_HourSuff:
          case TokenType::SEP_MinuteSuff:
          case TokenType::SEP_SecondSuff:
            dtok.dtt = DTT::NumTimesuff;
            dtok.suffix = separatorToken;
            break;
          case TokenType::SEP_LocalTimeMark:
            dtok.dtt = DTT::NumLocalTimeMark;
            raw.AddNumber(dtok.num);
            break;
          default:
            result.SetBadDateTimeFailure();
            return false;
        }
        break;
      }case TokenType::HebrewNumber:
      {
        TokenType separatorToken;
        if (tokenValue >= 100) {
          if (raw.year == -1) {
            raw.year = tokenValue;
            TokenType tokenType2 = (separatorToken = str.GetSeparatorToken(dtfi, indexBeforeSeparator, charBeforeSeparator));
            if (tokenType2 != TokenType::SEP_End) {
              if (tokenType2 != TokenType::SEP_Space) {
                if (tokenType2 != TokenType::SEP_DateOrOffset || s_dateParsingStates[(Int32)dps][12] <= DS::ERROR) {
                  result.SetBadDateTimeFailure();
                  return false;
                }
                str.Index = indexBeforeSeparator;
                str.m_current = charBeforeSeparator;
                dtok.dtt = DTT::YearSpace;
              } else {
                dtok.dtt = DTT::YearSpace;
              }
            } else {
              dtok.dtt = DTT::YearEnd;
            }
            break;
          }
          result.SetBadDateTimeFailure();
          return false;
        }
        dtok.num = tokenValue;
        raw.AddNumber(dtok.num);
        switch (separatorToken = str.GetSeparatorToken(dtfi, indexBeforeSeparator, charBeforeSeparator)) {
          case TokenType::SEP_End:
            dtok.dtt = DTT::NumEnd;
            break;
          case TokenType::SEP_Space:
          case TokenType::SEP_Date:
            dtok.dtt = DTT::NumDatesep;
            break;
          case TokenType::SEP_DateOrOffset:
            if (s_dateParsingStates[(Int32)dps][4] == DS::ERROR && s_dateParsingStates[(Int32)dps][3] > DS::ERROR) {
              str.Index = indexBeforeSeparator;
              str.m_current = charBeforeSeparator;
              dtok.dtt = DTT::NumSpace;
            } else {
              dtok.dtt = DTT::NumDatesep;
            }
            break;
          default:
            result.SetBadDateTimeFailure();
            return false;
        }
        break;
      }case TokenType::DayOfWeekToken:
      if (raw.dayOfWeek == -1) {
        raw.dayOfWeek = tokenValue;
        dtok.dtt = DTT::DayOfWeek;
        break;
      }
      result.SetBadDateTimeFailure();
      return false;
    case TokenType::MonthToken:
      if (raw.month == -1) {
        TokenType separatorToken;
        switch (separatorToken = str.GetSeparatorToken(dtfi, indexBeforeSeparator, charBeforeSeparator)) {
          case TokenType::SEP_End:
            dtok.dtt = DTT::MonthEnd;
            break;
          case TokenType::SEP_Space:
            dtok.dtt = DTT::MonthSpace;
            break;
          case TokenType::SEP_Date:
            dtok.dtt = DTT::MonthDatesep;
            break;
          case TokenType::SEP_Time:
            if (!raw.hasSameDateAndTimeSeparators) {
              result.SetBadDateTimeFailure();
              return false;
            }
            dtok.dtt = DTT::MonthDatesep;
            break;
          case TokenType::SEP_DateOrOffset:
            if (s_dateParsingStates[(Int32)dps][8] == DS::ERROR && s_dateParsingStates[(Int32)dps][7] > DS::ERROR) {
              str.Index = indexBeforeSeparator;
              str.m_current = charBeforeSeparator;
              dtok.dtt = DTT::MonthSpace;
            } else {
              dtok.dtt = DTT::MonthDatesep;
            }
            break;
          default:
            result.SetBadDateTimeFailure();
            return false;
        }
        raw.month = tokenValue;
        break;
      }
      result.SetBadDateTimeFailure();
      return false;
    case TokenType::EraToken:
      if (result.era != -1) {
        result.era = tokenValue;
        dtok.dtt = DTT::Era;
        break;
      }
      result.SetBadDateTimeFailure();
      return false;
    case TokenType::JapaneseEraToken:
      result.calendar = JapaneseCalendar::in::GetDefaultInstance();
      dtfi = DateTimeFormatInfo::in::GetJapaneseCalendarDTFI();
      if (result.era != -1) {
        result.era = tokenValue;
        dtok.dtt = DTT::Era;
        break;
      }
      result.SetBadDateTimeFailure();
      return false;
    case TokenType::TEraToken:
      result.calendar = TaiwanCalendar::in::GetDefaultInstance();
      dtfi = DateTimeFormatInfo::in::GetTaiwanCalendarDTFI();
      if (result.era != -1) {
        result.era = tokenValue;
        dtok.dtt = DTT::Era;
        break;
      }
      result.SetBadDateTimeFailure();
      return false;
    case TokenType::TimeZoneToken:
      if ((result.flags & ParseFlags::TimeZoneUsed) != 0) {
        result.SetBadDateTimeFailure();
        return false;
      }
      dtok.dtt = DTT::TimeZone;
      result.flags |= ParseFlags::TimeZoneUsed;
      result.timeZoneOffset = TimeSpan(0);
      result.flags |= ParseFlags::TimeZoneUtc;
      break;
    case TokenType::EndOfString:
      dtok.dtt = DTT::End;
      break;
    case TokenType::Am:
    case TokenType::Pm:
      if (raw.timeMark == TM::NotSet) {
        raw.timeMark = (TM)tokenValue;
        break;
      }
      result.SetBadDateTimeFailure();
      return false;
    case TokenType::UnknownToken:
      if (Char::IsLetter(str.m_current)) {
        result.SetFailure(ParseFailureKind::FormatWithOriginalDateTimeAndParameter, "Format_UnknownDateTimeWord", str.Index);
        return false;
      }
      if ((str.m_current == u'-' || str.m_current == u'+') && (result.flags & ParseFlags::TimeZoneUsed) == 0) {
        Int32 index = str.Index;
        if (ParseTimeZone(str, result.timeZoneOffset)) {
          result.flags |= ParseFlags::TimeZoneUsed;
          return true;
        }
        str.Index = index;
      }
      if (VerifyValidPunctuation(str)) {
        return true;
      }
      result.SetBadDateTimeFailure();
      return false;
  }
  return true;
}

Boolean DateTimeParse::VerifyValidPunctuation(__DTString& str) {
  switch (str.Value[str.Index].get()) {
    case u'#':
      {
        Boolean flag = false;
        Boolean flag2 = false;
        for (Int32 j = 0; j < str.get_Length(); j++) {
          Char c = str.Value[j];
          switch (c.get()) {
            case u'#':
              if (flag) {
                if (flag2) {
                  return false;
                }
                flag2 = true;
              } else {
                flag = true;
              }
              break;
            case u'\0':
              if (!flag2) {
                return false;
              }
              break;
            default:
              if (!Char::IsWhiteSpace(c) && (!flag || flag2)) {
                return false;
              }
              break;
          }
        }
        if (!flag2) {
          return false;
        }
        str.GetNext();
        return true;
      }case u'\0':
      {
        for (Int32 i = str.Index; i < str.get_Length(); i++) {
          if (str.Value[i] != 0) {
            return false;
          }
        }
        str.Index = str.get_Length();
        return true;
      }default:
      return false;
  }
}

Boolean DateTimeParse::GetYearMonthDayOrder(String datePattern, Int32& order) {
  Int32 num = -1;
  Int32 num2 = -1;
  Int32 num3 = -1;
  Int32 num4 = 0;
  Boolean flag = false;
  for (Int32 i = 0; i < datePattern->get_Length() && num4 < 3; i++) {
    Char c = datePattern[i];
    switch (c.get()) {
      case u'%':
      case u'\\':
        i++;
        continue;
      case u'"':
      case u'\'':
        flag = !flag;
        break;
    }
    if (flag) {
      continue;
    }
    switch (c.get()) {
      case u'y':
        num = num4++;
        for (; i + 1 < datePattern->get_Length() && datePattern[i + 1] == u'y'; i++) {
        }
        break;
      case u'M':
        num2 = num4++;
        for (; i + 1 < datePattern->get_Length() && datePattern[i + 1] == u'M'; i++) {
        }
        break;
      case u'd':
        {
          Int32 num5 = 1;
          for (; i + 1 < datePattern->get_Length() && datePattern[i + 1] == u'd'; i++) {
            num5++;
          }
          if (num5 <= 2) {
            num3 = num4++;
          }
          break;
        }}
  }
  if (num == 0 && num2 == 1 && num3 == 2) {
    order = 0;
    return true;
  }
  if (num2 == 0 && num3 == 1 && num == 2) {
    order = 1;
    return true;
  }
  if (num3 == 0 && num2 == 1 && num == 2) {
    order = 2;
    return true;
  }
  if (num == 0 && num3 == 1 && num2 == 2) {
    order = 3;
    return true;
  }
  order = -1;
  return false;
}

Boolean DateTimeParse::GetYearMonthOrder(String pattern, Int32& order) {
  Int32 num = -1;
  Int32 num2 = -1;
  Int32 num3 = 0;
  Boolean flag = false;
  for (Int32 i = 0; i < pattern->get_Length() && num3 < 2; i++) {
    Char c = pattern[i];
    switch (c.get()) {
      case u'%':
      case u'\\':
        i++;
        continue;
      case u'"':
      case u'\'':
        flag = !flag;
        break;
    }
    if (flag) {
      continue;
    }
    switch (c.get()) {
      case u'y':
        num = num3++;
        for (; i + 1 < pattern->get_Length() && pattern[i + 1] == u'y'; i++) {
        }
        break;
      case u'M':
        num2 = num3++;
        for (; i + 1 < pattern->get_Length() && pattern[i + 1] == u'M'; i++) {
        }
        break;
    }
  }
  if (num == 0 && num2 == 1) {
    order = 4;
    return true;
  }
  if (num2 == 0 && num == 1) {
    order = 5;
    return true;
  }
  order = -1;
  return false;
}

Boolean DateTimeParse::GetMonthDayOrder(String pattern, Int32& order) {
  Int32 num = -1;
  Int32 num2 = -1;
  Int32 num3 = 0;
  Boolean flag = false;
  for (Int32 i = 0; i < pattern->get_Length() && num3 < 2; i++) {
    Char c = pattern[i];
    switch (c.get()) {
      case u'%':
      case u'\\':
        i++;
        continue;
      case u'"':
      case u'\'':
        flag = !flag;
        break;
    }
    if (flag) {
      continue;
    }
    switch (c.get()) {
      case u'd':
        {
          Int32 num4 = 1;
          for (; i + 1 < pattern->get_Length() && pattern[i + 1] == u'd'; i++) {
            num4++;
          }
          if (num4 <= 2) {
            num2 = num3++;
          }
          break;
        }case u'M':
        num = num3++;
        for (; i + 1 < pattern->get_Length() && pattern[i + 1] == u'M'; i++) {
        }
        break;
    }
  }
  if (num == 0 && num2 == 1) {
    order = 6;
    return true;
  }
  if (num2 == 0 && num == 1) {
    order = 7;
    return true;
  }
  order = -1;
  return false;
}

Boolean DateTimeParse::TryAdjustYear(DateTimeResult& result, Int32 year, Int32& adjustedYear) {
  if (year < 100) {
    try {
      year = result.calendar->ToFourDigitYear(year);
    } catch (ArgumentOutOfRangeException) {
      adjustedYear = -1;
      return false;
    }
  }
  adjustedYear = year;
  return true;
}

Boolean DateTimeParse::SetDateYMD(DateTimeResult& result, Int32 year, Int32 month, Int32 day) {
  if (result.calendar->IsValidDay(year, month, day, result.era)) {
    result.SetDate(year, month, day);
    return true;
  }
  return false;
}

Boolean DateTimeParse::SetDateMDY(DateTimeResult& result, Int32 month, Int32 day, Int32 year) {
  return SetDateYMD(result, year, month, day);
}

Boolean DateTimeParse::SetDateDMY(DateTimeResult& result, Int32 day, Int32 month, Int32 year) {
  return SetDateYMD(result, year, month, day);
}

Boolean DateTimeParse::SetDateYDM(DateTimeResult& result, Int32 year, Int32 day, Int32 month) {
  return SetDateYMD(result, year, month, day);
}

void DateTimeParse::GetDefaultYear(DateTimeResult& result, DateTimeStyles& styles) {
  result.Year = result.calendar->GetYear(GetDateTimeNow(result, styles));
  result.flags |= ParseFlags::YearDefault;
}

Boolean DateTimeParse::GetDayOfNN(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 number = raw.GetNumber(0);
  Int32 number2 = raw.GetNumber(1);
  GetDefaultYear(result, styles);
  Int32 order;
  if (!GetMonthDayOrder(dtfi->get_MonthDayPattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_MonthDayPattern());
    return false;
  }
  if (order == 6) {
    if (SetDateYMD(result, result.Year, number, number2)) {
      result.flags |= ParseFlags::HaveDate;
      return true;
    }
  } else if (SetDateYMD(result, result.Year, number2, number)) {
    result.flags |= ParseFlags::HaveDate;
    return true;
  }

  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfNNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 number = raw.GetNumber(0);
  Int32 number2 = raw.GetNumber(1);
  Int32 number3 = raw.GetNumber(2);
  Int32 order;
  if (!GetYearMonthDayOrder(dtfi->get_ShortDatePattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_ShortDatePattern());
    return false;
  }
  Int32 adjustedYear;
  switch (order.get()) {
    case 0:
      if (TryAdjustYear(result, number, adjustedYear) && SetDateYMD(result, adjustedYear, number2, number3)) {
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
    case 1:
      if (TryAdjustYear(result, number3, adjustedYear) && SetDateMDY(result, number, number2, adjustedYear)) {
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
    case 2:
      if (TryAdjustYear(result, number3, adjustedYear) && SetDateDMY(result, number, number2, adjustedYear)) {
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
    case 3:
      if (TryAdjustYear(result, number, adjustedYear) && SetDateYDM(result, adjustedYear, number2, number3)) {
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
  }
  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfMN(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 order;
  if (!GetMonthDayOrder(dtfi->get_MonthDayPattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_MonthDayPattern());
    return false;
  }
  if (order == 7) {
    Int32 order2;
    if (!GetYearMonthOrder(dtfi->get_YearMonthPattern(), order2)) {
      result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_YearMonthPattern());
      return false;
    }
    if (order2 == 5) {
      Int32 adjustedYear;
      if (!TryAdjustYear(result, raw.GetNumber(0), adjustedYear) || !SetDateYMD(result, adjustedYear, raw.month, 1)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      return true;
    }
  }
  GetDefaultYear(result, styles);
  if (!SetDateYMD(result, result.Year, raw.month, raw.GetNumber(0))) {
    result.SetBadDateTimeFailure();
    return false;
  }
  return true;
}

Boolean DateTimeParse::GetHebrewDayOfNM(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  Int32 order;
  if (!GetMonthDayOrder(dtfi->get_MonthDayPattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_MonthDayPattern());
    return false;
  }
  result.Month = raw.month;
  if ((order == 7 || order == 6) && result.calendar->IsValidDay(result.Year, result.Month, raw.GetNumber(0), result.era)) {
    result.Day = raw.GetNumber(0);
    return true;
  }
  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfNM(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 order;
  if (!GetMonthDayOrder(dtfi->get_MonthDayPattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_MonthDayPattern());
    return false;
  }
  if (order == 6) {
    Int32 order2;
    if (!GetYearMonthOrder(dtfi->get_YearMonthPattern(), order2)) {
      result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_YearMonthPattern());
      return false;
    }
    if (order2 == 4) {
      Int32 adjustedYear;
      if (!TryAdjustYear(result, raw.GetNumber(0), adjustedYear) || !SetDateYMD(result, adjustedYear, raw.month, 1)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      return true;
    }
  }
  GetDefaultYear(result, styles);
  if (!SetDateYMD(result, result.Year, raw.month, raw.GetNumber(0))) {
    result.SetBadDateTimeFailure();
    return false;
  }
  return true;
}

Boolean DateTimeParse::GetDayOfMNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 number = raw.GetNumber(0);
  Int32 number2 = raw.GetNumber(1);
  Int32 order;
  if (!GetYearMonthDayOrder(dtfi->get_ShortDatePattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_ShortDatePattern());
    return false;
  }
  Int32 adjustedYear;
  switch (order.get()) {
    case 1:
      if (TryAdjustYear(result, number2, adjustedYear) && result.calendar->IsValidDay(adjustedYear, raw.month, number, result.era)) {
        result.SetDate(adjustedYear, raw.month, number);
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      if (TryAdjustYear(result, number, adjustedYear) && result.calendar->IsValidDay(adjustedYear, raw.month, number2, result.era)) {
        result.SetDate(adjustedYear, raw.month, number2);
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
    case 0:
      if (TryAdjustYear(result, number, adjustedYear) && result.calendar->IsValidDay(adjustedYear, raw.month, number2, result.era)) {
        result.SetDate(adjustedYear, raw.month, number2);
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      if (TryAdjustYear(result, number2, adjustedYear) && result.calendar->IsValidDay(adjustedYear, raw.month, number, result.era)) {
        result.SetDate(adjustedYear, raw.month, number);
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
    case 2:
      if (TryAdjustYear(result, number2, adjustedYear) && result.calendar->IsValidDay(adjustedYear, raw.month, number, result.era)) {
        result.SetDate(adjustedYear, raw.month, number);
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      if (TryAdjustYear(result, number, adjustedYear) && result.calendar->IsValidDay(adjustedYear, raw.month, number2, result.era)) {
        result.SetDate(adjustedYear, raw.month, number2);
        result.flags |= ParseFlags::HaveDate;
        return true;
      }
      break;
  }
  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfYNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 number = raw.GetNumber(0);
  Int32 number2 = raw.GetNumber(1);
  String shortDatePattern = dtfi->get_ShortDatePattern();
  Int32 order;
  if (GetYearMonthDayOrder(shortDatePattern, order) && order == 3) {
    if (SetDateYMD(result, raw.year, number2, number)) {
      result.flags |= ParseFlags::HaveDate;
      return true;
    }
  } else if (SetDateYMD(result, raw.year, number, number2)) {
    result.flags |= ParseFlags::HaveDate;
    return true;
  }

  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfNNY(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 number = raw.GetNumber(0);
  Int32 number2 = raw.GetNumber(1);
  Int32 order;
  if (!GetYearMonthDayOrder(dtfi->get_ShortDatePattern(), order)) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_ShortDatePattern());
    return false;
  }
  if (order == 1 || order == 0) {
    if (SetDateYMD(result, raw.year, number, number2)) {
      result.flags |= ParseFlags::HaveDate;
      return true;
    }
  } else if (SetDateYMD(result, raw.year, number2, number)) {
    result.flags |= ParseFlags::HaveDate;
    return true;
  }

  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfYMN(DateTimeResult& result, DateTimeRawInfo& raw) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (SetDateYMD(result, raw.year, raw.month, raw.GetNumber(0))) {
    result.flags |= ParseFlags::HaveDate;
    return true;
  }
  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfYN(DateTimeResult& result, DateTimeRawInfo& raw) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (SetDateYMD(result, raw.year, raw.GetNumber(0), 1)) {
    result.flags |= ParseFlags::HaveDate;
    return true;
  }
  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::GetDayOfYM(DateTimeResult& result, DateTimeRawInfo& raw) {
  if ((result.flags & ParseFlags::HaveDate) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (SetDateYMD(result, raw.year, raw.month, 1)) {
    result.flags |= ParseFlags::HaveDate;
    return true;
  }
  result.SetBadDateTimeFailure();
  return false;
}

void DateTimeParse::AdjustTimeMark(DateTimeFormatInfo dtfi, DateTimeRawInfo& raw) {
  if (raw.timeMark == TM::NotSet && dtfi->get_AMDesignator() != nullptr && dtfi->get_PMDesignator() != nullptr) {
    if (dtfi->get_AMDesignator()->get_Length() == 0 && dtfi->get_PMDesignator()->get_Length() != 0) {
      raw.timeMark = TM::AM;
    }
    if (dtfi->get_PMDesignator()->get_Length() == 0 && dtfi->get_AMDesignator()->get_Length() != 0) {
      raw.timeMark = TM::PM;
    }
  }
}

Boolean DateTimeParse::AdjustHour(Int32& hour, TM timeMark) {
  switch (timeMark) {
    case TM::AM:
      if (hour < 0 || hour > 12) {
        return false;
      }
      hour = ((hour != 12) ? hour : 0);
      break;
    default:
      if (hour < 0 || hour > 23) {
        return false;
      }
      if (hour < 12) {
        hour += 12;
      }
      break;
    case TM::NotSet:
      break;
  }
  return true;
}

Boolean DateTimeParse::GetTimeOfN(DateTimeResult& result, DateTimeRawInfo& raw) {
  if ((result.flags & ParseFlags::HaveTime) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (raw.timeMark == TM::NotSet) {
    result.SetBadDateTimeFailure();
    return false;
  }
  result.Hour = raw.GetNumber(0);
  result.flags |= ParseFlags::HaveTime;
  return true;
}

Boolean DateTimeParse::GetTimeOfNN(DateTimeResult& result, DateTimeRawInfo& raw) {
  if ((result.flags & ParseFlags::HaveTime) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  result.Hour = raw.GetNumber(0);
  result.Minute = raw.GetNumber(1);
  result.flags |= ParseFlags::HaveTime;
  return true;
}

Boolean DateTimeParse::GetTimeOfNNN(DateTimeResult& result, DateTimeRawInfo& raw) {
  if ((result.flags & ParseFlags::HaveTime) != 0) {
    result.SetBadDateTimeFailure();
    return false;
  }
  result.Hour = raw.GetNumber(0);
  result.Minute = raw.GetNumber(1);
  result.Second = raw.GetNumber(2);
  result.flags |= ParseFlags::HaveTime;
  return true;
}

Boolean DateTimeParse::GetDateOfDSN(DateTimeResult& result, DateTimeRawInfo& raw) {
  if (raw.numCount != 1 || result.Day != -1) {
    result.SetBadDateTimeFailure();
    return false;
  }
  result.Day = raw.GetNumber(0);
  return true;
}

Boolean DateTimeParse::GetDateOfNDS(DateTimeResult& result, DateTimeRawInfo& raw) {
  if (result.Month == -1) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (result.Year != -1) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (!TryAdjustYear(result, raw.GetNumber(0), result.Year)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  result.Day = 1;
  return true;
}

Boolean DateTimeParse::GetDateOfNNDS(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  if ((result.flags & ParseFlags::HaveYear) != 0) {
    if ((result.flags & ParseFlags::HaveMonth) == 0 && (result.flags & ParseFlags::HaveDay) == 0 && TryAdjustYear(result, raw.year, result.Year) && SetDateYMD(result, result.Year, raw.GetNumber(0), raw.GetNumber(1))) {
      return true;
    }
  } else if ((result.flags & ParseFlags::HaveMonth) != 0 && (result.flags & ParseFlags::HaveYear) == 0 && (result.flags & ParseFlags::HaveDay) == 0) {
    Int32 order;
    if (!GetYearMonthDayOrder(dtfi->get_ShortDatePattern(), order)) {
      result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDatePattern", dtfi->get_ShortDatePattern());
      return false;
    }
    Int32 adjustedYear;
    if (order == 0) {
      if (TryAdjustYear(result, raw.GetNumber(0), adjustedYear) && SetDateYMD(result, adjustedYear, result.Month, raw.GetNumber(1))) {
        return true;
      }
    } else if (TryAdjustYear(result, raw.GetNumber(1), adjustedYear) && SetDateYMD(result, adjustedYear, result.Month, raw.GetNumber(0))) {
      return true;
    }

  }

  result.SetBadDateTimeFailure();
  return false;
}

Boolean DateTimeParse::ProcessDateTimeSuffix(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeToken& dtok) {
  switch (dtok.suffix) {
    case TokenType::SEP_YearSuff:
      if ((result.flags & ParseFlags::HaveYear) != 0) {
        return false;
      }
      result.flags |= ParseFlags::HaveYear;
      result.Year = (raw.year = dtok.num);
      break;
    case TokenType::SEP_MonthSuff:
      if ((result.flags & ParseFlags::HaveMonth) != 0) {
        return false;
      }
      result.flags |= ParseFlags::HaveMonth;
      result.Month = (raw.month = dtok.num);
      break;
    case TokenType::SEP_DaySuff:
      if ((result.flags & ParseFlags::HaveDay) != 0) {
        return false;
      }
      result.flags |= ParseFlags::HaveDay;
      result.Day = dtok.num;
      break;
    case TokenType::SEP_HourSuff:
      if ((result.flags & ParseFlags::HaveHour) != 0) {
        return false;
      }
      result.flags |= ParseFlags::HaveHour;
      result.Hour = dtok.num;
      break;
    case TokenType::SEP_MinuteSuff:
      if ((result.flags & ParseFlags::HaveMinute) != 0) {
        return false;
      }
      result.flags |= ParseFlags::HaveMinute;
      result.Minute = dtok.num;
      break;
    case TokenType::SEP_SecondSuff:
      if ((result.flags & ParseFlags::HaveSecond) != 0) {
        return false;
      }
      result.flags |= ParseFlags::HaveSecond;
      result.Second = dtok.num;
      break;
  }
  return true;
}

Boolean DateTimeParse::ProcessHebrewTerminalState(DS dps, DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  switch (dps) {
    case DS::DX_MNN:
      raw.year = raw.GetNumber(1);
      if (!dtfi->YearMonthAdjustment(raw.year, raw.month, true)) {
        result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
        return false;
      }
      if (!GetDayOfMNN(result, raw, dtfi)) {
        return false;
      }
      break;
    case DS::DX_YMN:
      if (!dtfi->YearMonthAdjustment(raw.year, raw.month, true)) {
        result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
        return false;
      }
      if (!GetDayOfYMN(result, raw)) {
        return false;
      }
      break;
    case DS::DX_NNY:
      if (raw.year < 1000) {
        raw.year += 5000;
      }
      if (!GetDayOfNNY(result, raw, dtfi)) {
        return false;
      }
      if (!dtfi->YearMonthAdjustment(result.Year, raw.month, true)) {
        result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
        return false;
      }
      break;
    case DS::DX_MN:
    case DS::DX_NM:
      GetDefaultYear(result, styles);
      if (!dtfi->YearMonthAdjustment(result.Year, raw.month, true)) {
        result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
        return false;
      }
      if (!GetHebrewDayOfNM(result, raw, dtfi)) {
        return false;
      }
      break;
    case DS::DX_YM:
      if (!dtfi->YearMonthAdjustment(raw.year, raw.month, true)) {
        result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
        return false;
      }
      if (!GetDayOfYM(result, raw)) {
        return false;
      }
      break;
    case DS::TX_N:
      if (!GetTimeOfN(result, raw)) {
        return false;
      }
      break;
    case DS::TX_NN:
      if (!GetTimeOfNN(result, raw)) {
        return false;
      }
      break;
    case DS::TX_NNN:
      if (!GetTimeOfNNN(result, raw)) {
        return false;
      }
      break;
    default:
      result.SetBadDateTimeFailure();
      return false;
  }
  if (dps > DS::ERROR) {
    raw.numCount = 0;
  }
  return true;
}

Boolean DateTimeParse::ProcessTerminalState(DS dps, DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi) {
  Boolean flag = true;
  switch (dps) {
    case DS::DX_NN:
      flag = GetDayOfNN(result, styles, raw, dtfi);
      break;
    case DS::DX_NNN:
      flag = GetDayOfNNN(result, raw, dtfi);
      break;
    case DS::DX_MN:
      flag = GetDayOfMN(result, styles, raw, dtfi);
      break;
    case DS::DX_NM:
      flag = GetDayOfNM(result, styles, raw, dtfi);
      break;
    case DS::DX_MNN:
      flag = GetDayOfMNN(result, raw, dtfi);
      break;
    case DS::DX_DS:
      flag = true;
      break;
    case DS::DX_YNN:
      flag = GetDayOfYNN(result, raw, dtfi);
      break;
    case DS::DX_NNY:
      flag = GetDayOfNNY(result, raw, dtfi);
      break;
    case DS::DX_YMN:
      flag = GetDayOfYMN(result, raw);
      break;
    case DS::DX_YN:
      flag = GetDayOfYN(result, raw);
      break;
    case DS::DX_YM:
      flag = GetDayOfYM(result, raw);
      break;
    case DS::TX_N:
      flag = GetTimeOfN(result, raw);
      break;
    case DS::TX_NN:
      flag = GetTimeOfNN(result, raw);
      break;
    case DS::TX_NNN:
      flag = GetTimeOfNNN(result, raw);
      break;
    case DS::TX_TS:
      flag = true;
      break;
    case DS::DX_DSN:
      flag = GetDateOfDSN(result, raw);
      break;
    case DS::DX_NDS:
      flag = GetDateOfNDS(result, raw);
      break;
    case DS::DX_NNDS:
      flag = GetDateOfNNDS(result, raw, dtfi);
      break;
  }
  if (!flag) {
    return false;
  }
  if (dps > DS::ERROR) {
    raw.numCount = 0;
  }
  return true;
}

DateTime DateTimeParse::Parse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles) {
  DateTimeResult result;
  result.Init(s);
  if (TryParse(s, dtfi, styles, result)) {
    return result.parsedDate;
  }
  rt::throw_exception(GetDateTimeParseException(result));
}

DateTime DateTimeParse::Parse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, TimeSpan& offset) {
  DateTimeResult result;
  result.Init(s);
  result.flags |= ParseFlags::CaptureOffset;
  if (TryParse(s, dtfi, styles, result)) {
    offset = result.timeZoneOffset;
    return result.parsedDate;
  }
  rt::throw_exception(GetDateTimeParseException(result));
}

Boolean DateTimeParse::TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTime& result) {
  DateTimeResult result2;
  result2.Init(s);
  if (TryParse(s, dtfi, styles, result2)) {
    result = result2.parsedDate;
    return true;
  }
  result = DateTime::MinValue;
  return false;
}

Boolean DateTimeParse::TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTime& result, TimeSpan& offset) {
  DateTimeResult result2;
  result2.Init(s);
  result2.flags |= ParseFlags::CaptureOffset;
  if (TryParse(s, dtfi, styles, result2)) {
    result = result2.parsedDate;
    offset = result2.timeZoneOffset;
    return true;
  }
  result = DateTime::MinValue;
  offset = TimeSpan::Zero;
  return false;
}

Boolean DateTimeParse::TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTimeResult& result) {
  if (s.get_Length() == 0) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadDateTime");
    return false;
  }
  DS dS = DS::BEGIN;
  Boolean flag = false;
  DateTimeToken dtok;
  dtok.suffix = TokenType::SEP_Unk;
  DateTimeRawInfo raw;
  Int32 as[3] = {};
  Int32* numberBuffer = as;
  raw.Init(numberBuffer);
  raw.hasSameDateAndTimeSeparators = dtfi->get_DateSeparator()->Equals(dtfi->get_TimeSeparator(), StringComparison::Ordinal);
  result.calendar = dtfi->set_Calendar();
  result.era = 0;
  __DTString str = __DTString(s, dtfi);
  str.GetNext();
  do {
    if (!Lex(dS, str, dtok, raw, result, dtfi, styles)) {
      return false;
    }
    if (dtok.dtt == DTT::Unk) {
      continue;
    }
    if (dtok.suffix != TokenType::SEP_Unk) {
      if (!ProcessDateTimeSuffix(result, raw, dtok)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      dtok.suffix = TokenType::SEP_Unk;
    }
    if (dtok.dtt == DTT::NumLocalTimeMark) {
      if (dS == DS::D_YNd || dS == DS::D_YN) {
        return ParseISO8601(raw, str, styles, result);
      }
      result.SetBadDateTimeFailure();
      return false;
    }
    if (raw.hasSameDateAndTimeSeparators) {
      if (dtok.dtt == DTT::YearEnd || dtok.dtt == DTT::YearSpace || dtok.dtt == DTT::YearDateSep) {
        if (dS == DS::T_Nt) {
          dS = DS::D_Nd;
        }
        if (dS == DS::T_NNt) {
          dS = DS::D_NNd;
        }
      }
      Boolean flag2 = str.AtEnd();
      if (s_dateParsingStates[(Int32)dS][(Int32)dtok.dtt] == DS::ERROR || flag2) {
        switch (dtok.dtt) {
          case DTT::YearDateSep:
            dtok.dtt = (flag2 ? DTT::YearEnd : DTT::YearSpace);
            break;
          case DTT::NumDatesep:
            dtok.dtt = (flag2 ? DTT::NumEnd : DTT::NumSpace);
            break;
          case DTT::NumTimesep:
            dtok.dtt = (flag2 ? DTT::NumEnd : DTT::NumSpace);
            break;
          case DTT::MonthDatesep:
            dtok.dtt = (flag2 ? DTT::MonthEnd : DTT::MonthSpace);
            break;
        }
      }
    }
    dS = s_dateParsingStates[(Int32)dS][(Int32)dtok.dtt];
    if (dS == DS::ERROR) {
      result.SetBadDateTimeFailure();
      return false;
    }
    if (dS <= DS::ERROR) {
      continue;
    }
    if ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseHebrewRule) != 0) {
      if (!ProcessHebrewTerminalState(dS, result, styles, raw, dtfi)) {
        return false;
      }
    } else if (!ProcessTerminalState(dS, result, styles, raw, dtfi)) {
      return false;
    }

    flag = true;
    dS = DS::BEGIN;
  } while (dtok.dtt != 0 && dtok.dtt != DTT::NumEnd && dtok.dtt != DTT::MonthEnd);
  if (!flag) {
    result.SetBadDateTimeFailure();
    return false;
  }
  AdjustTimeMark(dtfi, raw);
  if (!AdjustHour(result.Hour, raw.timeMark)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Boolean bTimeOnly = result.Year == -1 && result.Month == -1 && result.Day == -1;
  if (!CheckDefaultDateTime(result, result.calendar, styles)) {
    return false;
  }
  DateTime result2;
  if (!result.calendar->TryToDateTime(result.Year, result.Month, result.Day, result.Hour, result.Minute, result.Second, 0, result.era, result2)) {
    result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
    return false;
  }
  if (raw.fraction > 0 && !result2.TryAddTicks((Int64)Math::Round(raw.fraction * 10000000), result2)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (raw.dayOfWeek != -1 && raw.dayOfWeek != (Int32)result.calendar->GetDayOfWeek(result2)) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_BadDayOfWeek");
    return false;
  }
  result.parsedDate = result2;
  if (!DetermineTimeZoneAdjustments(result, styles, bTimeOnly)) {
    return false;
  }
  return true;
}

Boolean DateTimeParse::DetermineTimeZoneAdjustments(DateTimeResult& result, DateTimeStyles styles, Boolean bTimeOnly) {
  if ((result.flags & ParseFlags::CaptureOffset) != 0) {
    return DateTimeOffsetTimeZonePostProcessing(result, styles);
  }
  Int64 ticks = result.timeZoneOffset.get_Ticks();
  if (ticks < -504000000000 || ticks > 504000000000) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_OffsetOutOfRange");
    return false;
  }
  if ((result.flags & ParseFlags::TimeZoneUsed) == 0) {
    if ((styles & DateTimeStyles::AssumeLocal) != 0) {
      if ((styles & DateTimeStyles::AdjustToUniversal) == 0) {
        result.parsedDate = DateTime::SpecifyKind(result.parsedDate, DateTimeKind::Local);
        return true;
      }
      result.flags |= ParseFlags::TimeZoneUsed;
      result.timeZoneOffset = TimeZoneInfo::in::GetLocalUtcOffset(result.parsedDate, TimeZoneInfoOptions::NoThrowOnInvalidTime);
    } else {
      if ((styles & DateTimeStyles::AssumeUniversal) == 0) {
        return true;
      }
      if ((styles & DateTimeStyles::AdjustToUniversal) != 0) {
        result.parsedDate = DateTime::SpecifyKind(result.parsedDate, DateTimeKind::Utc);
        return true;
      }
      result.flags |= ParseFlags::TimeZoneUsed;
      result.timeZoneOffset = TimeSpan::Zero;
    }
  }
  if ((styles & DateTimeStyles::RoundtripKind) != 0 && (result.flags & ParseFlags::TimeZoneUtc) != 0) {
    result.parsedDate = DateTime::SpecifyKind(result.parsedDate, DateTimeKind::Utc);
    return true;
  }
  if ((styles & DateTimeStyles::AdjustToUniversal) != 0) {
    return AdjustTimeZoneToUniversal(result);
  }
  return AdjustTimeZoneToLocal(result, bTimeOnly);
}

Boolean DateTimeParse::DateTimeOffsetTimeZonePostProcessing(DateTimeResult& result, DateTimeStyles styles) {
  if ((result.flags & ParseFlags::TimeZoneUsed) == 0) {
    if ((styles & DateTimeStyles::AssumeUniversal) != 0) {
      result.timeZoneOffset = TimeSpan::Zero;
    } else {
      result.timeZoneOffset = TimeZoneInfo::in::GetLocalUtcOffset(result.parsedDate, TimeZoneInfoOptions::NoThrowOnInvalidTime);
    }
  }
  Int64 ticks = result.timeZoneOffset.get_Ticks();
  Int64 num = result.parsedDate.get_Ticks() - ticks;
  if (num < 0 || num > 3155378975999999999) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_UTCOutOfRange");
    return false;
  }
  if (ticks < -504000000000 || ticks > 504000000000) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_OffsetOutOfRange");
    return false;
  }
  if ((styles & DateTimeStyles::AdjustToUniversal) != 0) {
    if ((result.flags & ParseFlags::TimeZoneUsed) == 0 && (styles & DateTimeStyles::AssumeUniversal) == 0) {
      Boolean result2 = AdjustTimeZoneToUniversal(result);
      result.timeZoneOffset = TimeSpan::Zero;
      return result2;
    }
    result.parsedDate = DateTime(num, DateTimeKind::Utc);
    result.timeZoneOffset = TimeSpan::Zero;
  }
  return true;
}

Boolean DateTimeParse::AdjustTimeZoneToUniversal(DateTimeResult& result) {
  Int64 ticks = result.parsedDate.get_Ticks();
  ticks -= result.timeZoneOffset.get_Ticks();
  if (ticks < 0) {
    ticks += 864000000000;
  }
  if (ticks < 0 || ticks > 3155378975999999999) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_DateOutOfRange");
    return false;
  }
  result.parsedDate = DateTime(ticks, DateTimeKind::Utc);
  return true;
}

Boolean DateTimeParse::AdjustTimeZoneToLocal(DateTimeResult& result, Boolean bTimeOnly) {
  Int64 ticks = result.parsedDate.get_Ticks();
  TimeZoneInfo local = TimeZoneInfo::in::get_Local();
  Boolean isAmbiguousLocalDst = false;
  if (ticks < 864000000000) {
    ticks -= result.timeZoneOffset.get_Ticks();
    ticks += local->GetUtcOffset(bTimeOnly ? DateTime::get_Now() : result.parsedDate, TimeZoneInfoOptions::NoThrowOnInvalidTime).get_Ticks();
    if (ticks < 0) {
      ticks += 864000000000;
    }
  } else {
    ticks -= result.timeZoneOffset.get_Ticks();
    if (ticks < 0 || ticks > 3155378975999999999) {
      ticks += local->GetUtcOffset(result.parsedDate, TimeZoneInfoOptions::NoThrowOnInvalidTime).get_Ticks();
    } else {
      DateTime time = DateTime(ticks, DateTimeKind::Utc);
      Boolean isDaylightSavings;
      ticks += TimeZoneInfo::in::GetUtcOffsetFromUtc(time, TimeZoneInfo::in::get_Local(), isDaylightSavings, isAmbiguousLocalDst).get_Ticks();
    }
  }
  if (ticks < 0 || ticks > 3155378975999999999) {
    result.parsedDate = DateTime::MinValue;
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_DateOutOfRange");
    return false;
  }
  result.parsedDate = DateTime(ticks, DateTimeKind::Local, isAmbiguousLocalDst);
  return true;
}

Boolean DateTimeParse::ParseISO8601(DateTimeRawInfo& raw, __DTString& str, DateTimeStyles styles, DateTimeResult& result) {
  if (raw.year >= 0 && raw.GetNumber(0) >= 0) {
    raw.GetNumber(1);
    Int32 num = 0;
  }
  str.Index--;
  Int32 result2 = 0;
  Double result3 = 0;
  str.SkipWhiteSpaces();
  Int32 result4;
  if (!ParseDigits(str, 2, result4)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  str.SkipWhiteSpaces();
  if (!str.Match(u':')) {
    result.SetBadDateTimeFailure();
    return false;
  }
  str.SkipWhiteSpaces();
  Int32 result5;
  if (!ParseDigits(str, 2, result5)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  str.SkipWhiteSpaces();
  if (str.Match(u':')) {
    str.SkipWhiteSpaces();
    if (!ParseDigits(str, 2, result2)) {
      result.SetBadDateTimeFailure();
      return false;
    }
    if (str.Match(u'.')) {
      if (!ParseFraction(str, result3)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      str.Index--;
    }
    str.SkipWhiteSpaces();
  }
  if (str.GetNext()) {
    switch (str.GetChar().get()) {
      case u'+':
      case u'-':
        result.flags |= ParseFlags::TimeZoneUsed;
        if (!ParseTimeZone(str, result.timeZoneOffset)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        break;
      case u'Z':
      case u'z':
        result.flags |= ParseFlags::TimeZoneUsed;
        result.timeZoneOffset = TimeSpan::Zero;
        result.flags |= ParseFlags::TimeZoneUtc;
        break;
      default:
        str.Index--;
        break;
    }
    str.SkipWhiteSpaces();
    if (str.Match(u'#')) {
      if (!VerifyValidPunctuation(str)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      str.SkipWhiteSpaces();
    }
    if (str.Match(u'\0') && !VerifyValidPunctuation(str)) {
      result.SetBadDateTimeFailure();
      return false;
    }
    if (str.GetNext()) {
      result.SetBadDateTimeFailure();
      return false;
    }
  }
  Calendar defaultInstance = GregorianCalendar::in::GetDefaultInstance();
  DateTime result6;
  if (!defaultInstance->TryToDateTime(raw.year, raw.GetNumber(0), raw.GetNumber(1), result4, result5, result2, 0, result.era, result6)) {
    result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
    return false;
  }
  if (!result6.TryAddTicks((Int64)Math::Round(result3 * 10000000), result6)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  result.parsedDate = result6;
  return DetermineTimeZoneAdjustments(result, styles, false);
}

Boolean DateTimeParse::MatchHebrewDigits(__DTString& str, Int32 digitLen, Int32& number) {
  number = 0;
  HebrewNumberParsingContext context = HebrewNumberParsingContext(0);
  HebrewNumberParsingState hebrewNumberParsingState = HebrewNumberParsingState::ContinueParsing;
  while (hebrewNumberParsingState == HebrewNumberParsingState::ContinueParsing && str.GetNext()) {
    hebrewNumberParsingState = HebrewNumber::ParseByChar(str.GetChar(), context);
  }
  if (hebrewNumberParsingState == HebrewNumberParsingState::FoundEndOfHebrewNumber) {
    number = context.result;
    return true;
  }
  return false;
}

Boolean DateTimeParse::ParseDigits(__DTString& str, Int32 digitLen, Int32& result) {
  if (digitLen == 1) {
    return ParseDigits(str, 1, 2, result);
  }
  return ParseDigits(str, digitLen, digitLen, result);
}

Boolean DateTimeParse::ParseDigits(__DTString& str, Int32 minDigitLen, Int32 maxDigitLen, Int32& result) {
  Int32 num = 0;
  Int32 index = str.Index;
  Int32 i;
  for (i = 0; i < maxDigitLen; i++) {
    if (!str.GetNextDigit()) {
      str.Index--;
      break;
    }
    num = num * 10 + str.GetDigit();
  }
  result = num;
  if (i < minDigitLen) {
    str.Index = index;
    return false;
  }
  return true;
}

Boolean DateTimeParse::ParseFractionExact(__DTString& str, Int32 maxDigitLen, Double& result) {
  if (!str.GetNextDigit()) {
    str.Index--;
    return false;
  }
  result = str.GetDigit();
  Int32 i;
  for (i = 1; i < maxDigitLen; i++) {
    if (!str.GetNextDigit()) {
      str.Index--;
      break;
    }
    result = result * 10 + (Double)str.GetDigit();
  }
  result /= TimeSpanParse::Pow10(i);
  return i == maxDigitLen;
}

Boolean DateTimeParse::ParseSign(__DTString& str, Boolean& result) {
  if (!str.GetNext()) {
    return false;
  }
  switch (str.GetChar().get()) {
    case u'+':
      result = true;
      return true;
    case u'-':
      result = false;
      return true;
    default:
      return false;
  }
}

Boolean DateTimeParse::ParseTimeZoneOffset(__DTString& str, Int32 len, TimeSpan& result) {
  Boolean result2 = true;
  Int32 result3 = 0;
  Int32 result4;
  if ((UInt32)(len - 1) <= 1u) {
    if (!ParseSign(str, result2)) {
      return false;
    }
    if (!ParseDigits(str, len, result4)) {
      return false;
    }
  } else {
    if (!ParseSign(str, result2)) {
      return false;
    }
    if (!ParseDigits(str, 1, result4)) {
      return false;
    }
    if (str.Match(":")) {
      if (!ParseDigits(str, 2, result3)) {
        return false;
      }
    } else {
      str.Index--;
      if (!ParseDigits(str, 2, result3)) {
        return false;
      }
    }
  }
  if (result3 < 0 || result3 >= 60) {
    return false;
  }
  result = TimeSpan(result4, result3, 0);
  if (!result2) {
    result = result.Negate();
  }
  return true;
}

Boolean DateTimeParse::MatchAbbreviatedMonthName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  Int32 maxMatchStrLen = 0;
  result = -1;
  if (str.GetNext()) {
    Int32 num = ((dtfi->GetMonthName(13)->get_Length() == 0) ? 12 : 13);
    for (Int32 i = 1; i <= num; i++) {
      String abbreviatedMonthName = dtfi->GetAbbreviatedMonthName(i);
      Int32 matchLength = abbreviatedMonthName->get_Length();
      if ((dtfi->get_HasSpacesInMonthNames() ? str.MatchSpecifiedWords(abbreviatedMonthName, false, matchLength) : str.MatchSpecifiedWord(abbreviatedMonthName)) && matchLength > maxMatchStrLen) {
        maxMatchStrLen = matchLength;
        result = i;
      }
    }
    if ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseGenitiveMonth) != 0) {
      Int32 num2 = str.MatchLongestWords(dtfi->get_AbbreviatedMonthGenitiveNames(), maxMatchStrLen);
      if (num2 >= 0) {
        result = num2 + 1;
      }
    }
    if ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseLeapYearMonth) != 0) {
      Int32 num3 = str.MatchLongestWords(dtfi->InternalGetLeapYearMonthNames(), maxMatchStrLen);
      if (num3 >= 0) {
        result = num3 + 1;
      }
    }
  }
  if (result > 0) {
    str.Index += maxMatchStrLen - 1;
    return true;
  }
  return false;
}

Boolean DateTimeParse::MatchMonthName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  Int32 maxMatchStrLen = 0;
  result = -1;
  if (str.GetNext()) {
    Int32 num = ((dtfi->GetMonthName(13)->get_Length() == 0) ? 12 : 13);
    for (Int32 i = 1; i <= num; i++) {
      String monthName = dtfi->GetMonthName(i);
      Int32 matchLength = monthName->get_Length();
      if ((dtfi->get_HasSpacesInMonthNames() ? str.MatchSpecifiedWords(monthName, false, matchLength) : str.MatchSpecifiedWord(monthName)) && matchLength > maxMatchStrLen) {
        maxMatchStrLen = matchLength;
        result = i;
      }
    }
    if ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseGenitiveMonth) != 0) {
      Int32 num2 = str.MatchLongestWords(dtfi->get_MonthGenitiveNames(), maxMatchStrLen);
      if (num2 >= 0) {
        result = num2 + 1;
      }
    }
    if ((dtfi->get_FormatFlags() & DateTimeFormatFlags::UseLeapYearMonth) != 0) {
      Int32 num3 = str.MatchLongestWords(dtfi->InternalGetLeapYearMonthNames(), maxMatchStrLen);
      if (num3 >= 0) {
        result = num3 + 1;
      }
    }
  }
  if (result > 0) {
    str.Index += maxMatchStrLen - 1;
    return true;
  }
  return false;
}

Boolean DateTimeParse::MatchAbbreviatedDayName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  Int32 num = 0;
  result = -1;
  if (str.GetNext()) {
    for (DayOfWeek dayOfWeek = DayOfWeek::Sunday; dayOfWeek <= DayOfWeek::Saturday; dayOfWeek++) {
      String abbreviatedDayName = dtfi->GetAbbreviatedDayName(dayOfWeek);
      Int32 matchLength = abbreviatedDayName->get_Length();
      if ((dtfi->get_HasSpacesInDayNames() ? str.MatchSpecifiedWords(abbreviatedDayName, false, matchLength) : str.MatchSpecifiedWord(abbreviatedDayName)) && matchLength > num) {
        num = matchLength;
        result = (Int32)dayOfWeek;
      }
    }
  }
  if (result >= 0) {
    str.Index += num - 1;
    return true;
  }
  return false;
}

Boolean DateTimeParse::MatchDayName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  Int32 num = 0;
  result = -1;
  if (str.GetNext()) {
    for (DayOfWeek dayOfWeek = DayOfWeek::Sunday; dayOfWeek <= DayOfWeek::Saturday; dayOfWeek++) {
      String dayName = dtfi->GetDayName(dayOfWeek);
      Int32 matchLength = dayName->get_Length();
      if ((dtfi->get_HasSpacesInDayNames() ? str.MatchSpecifiedWords(dayName, false, matchLength) : str.MatchSpecifiedWord(dayName)) && matchLength > num) {
        num = matchLength;
        result = (Int32)dayOfWeek;
      }
    }
  }
  if (result >= 0) {
    str.Index += num - 1;
    return true;
  }
  return false;
}

Boolean DateTimeParse::MatchEraName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result) {
  if (str.GetNext()) {
    Array<Int32> eras = dtfi->get_Calendar()->get_Eras();
    if (eras != nullptr) {
      for (Int32 i = 0; i < eras->get_Length(); i++) {
        String eraName = dtfi->GetEraName(eras[i]);
        if (str.MatchSpecifiedWord(eraName)) {
          str.Index += eraName->get_Length() - 1;
          result = eras[i];
          return true;
        }
        eraName = dtfi->GetAbbreviatedEraName(eras[i]);
        if (str.MatchSpecifiedWord(eraName)) {
          str.Index += eraName->get_Length() - 1;
          result = eras[i];
          return true;
        }
      }
    }
  }
  return false;
}

Boolean DateTimeParse::MatchTimeMark(__DTString& str, DateTimeFormatInfo dtfi, TM& result) {
  result = TM::NotSet;
  if (dtfi->get_AMDesignator()->get_Length() == 0) {
    result = TM::AM;
  }
  if (dtfi->get_PMDesignator()->get_Length() == 0) {
    result = TM::PM;
  }
  if (str.GetNext()) {
    String aMDesignator = dtfi->get_AMDesignator();
    if (aMDesignator->get_Length() > 0 && str.MatchSpecifiedWord(aMDesignator)) {
      str.Index += aMDesignator->get_Length() - 1;
      result = TM::AM;
      return true;
    }
    aMDesignator = dtfi->set_PMDesignator();
    if (aMDesignator->get_Length() > 0 && str.MatchSpecifiedWord(aMDesignator)) {
      str.Index += aMDesignator->get_Length() - 1;
      result = TM::PM;
      return true;
    }
    str.Index--;
  }
  if (result != TM::NotSet) {
    return true;
  }
  return false;
}

Boolean DateTimeParse::MatchAbbreviatedTimeMark(__DTString& str, DateTimeFormatInfo dtfi, TM& result) {
  if (str.GetNext()) {
    String aMDesignator = dtfi->get_AMDesignator();
    if (aMDesignator->get_Length() > 0 && str.GetChar() == aMDesignator[0]) {
      result = TM::AM;
      return true;
    }
    String pMDesignator = dtfi->get_PMDesignator();
    if (pMDesignator->get_Length() > 0 && str.GetChar() == pMDesignator[0]) {
      result = TM::PM;
      return true;
    }
  }
  return false;
}

Boolean DateTimeParse::CheckNewValue(Int32& currentValue, Int32 newValue, Char patternChar, DateTimeResult& result) {
  if (currentValue == -1) {
    currentValue = newValue;
    return true;
  }
  if (newValue != currentValue) {
    result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", patternChar);
    return false;
  }
  return true;
}

DateTime DateTimeParse::GetDateTimeNow(DateTimeResult& result, DateTimeStyles& styles) {
  if ((result.flags & ParseFlags::CaptureOffset) != 0) {
    if ((result.flags & ParseFlags::TimeZoneUsed) != 0) {
      return DateTime(DateTime::get_UtcNow().get_Ticks() + result.timeZoneOffset.get_Ticks(), DateTimeKind::Unspecified);
    }
    if ((styles & DateTimeStyles::AssumeUniversal) != 0) {
      return DateTime::get_UtcNow();
    }
  }
  return DateTime::get_Now();
}

Boolean DateTimeParse::CheckDefaultDateTime(DateTimeResult& result, Calendar& cal, DateTimeStyles styles) {
  if ((result.flags & ParseFlags::CaptureOffset) != 0 && (result.Month != -1 || result.Day != -1) && (result.Year == -1 || (result.flags & ParseFlags::YearDefault) != 0) && (result.flags & ParseFlags::TimeZoneUsed) != 0) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_MissingIncompleteDate");
    return false;
  }
  if (result.Year == -1 || result.Month == -1 || result.Day == -1) {
    DateTime dateTimeNow = GetDateTimeNow(result, styles);
    if (result.Month == -1 && result.Day == -1) {
      if (result.Year == -1) {
        if ((styles & DateTimeStyles::NoCurrentDateDefault) != 0) {
          cal = GregorianCalendar::in::GetDefaultInstance();
          result.Year = (result.Month = (result.Day = 1));
        } else {
          result.Year = cal->GetYear(dateTimeNow);
          result.Month = cal->GetMonth(dateTimeNow);
          result.Day = cal->GetDayOfMonth(dateTimeNow);
        }
      } else {
        result.Month = 1;
        result.Day = 1;
      }
    } else {
      if (result.Year == -1) {
        result.Year = cal->GetYear(dateTimeNow);
      }
      if (result.Month == -1) {
        result.Month = 1;
      }
      if (result.Day == -1) {
        result.Day = 1;
      }
    }
  }
  if (result.Hour == -1) {
    result.Hour = 0;
  }
  if (result.Minute == -1) {
    result.Minute = 0;
  }
  if (result.Second == -1) {
    result.Second = 0;
  }
  if (result.era == -1) {
    result.era = 0;
  }
  return true;
}

String DateTimeParse::ExpandPredefinedFormat(ReadOnlySpan<Char> format, DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo, DateTimeResult& result) {
  switch (format[0].get()) {
    case u'O':
    case u'o':
    case u's':
      ConfigureFormatOS(dtfi, parseInfo);
      break;
    case u'R':
    case u'r':
      ConfigureFormatR(dtfi, parseInfo, result);
      break;
    case u'u':
      parseInfo.calendar = GregorianCalendar::in::GetDefaultInstance();
      dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
      if ((result.flags & ParseFlags::CaptureOffset) != 0) {
        result.flags |= ParseFlags::UtcSortPattern;
      }
      break;
    case u'U':
      parseInfo.calendar = GregorianCalendar::in::GetDefaultInstance();
      result.flags |= ParseFlags::TimeZoneUsed;
      result.timeZoneOffset = TimeSpan(0);
      result.flags |= ParseFlags::TimeZoneUtc;
      if (dtfi->get_Calendar()->GetType() != typeof<GregorianCalendar>()) {
        dtfi = (DateTimeFormatInfo)dtfi->Clone();
        dtfi->set_Calendar(GregorianCalendar::in::GetDefaultInstance());
      }
      break;
  }
  return DateTimeFormat::GetRealFormat(format, dtfi);
}

Boolean DateTimeParse::ParseJapaneseEraStart(__DTString& str, DateTimeFormatInfo dtfi) {
  if (LocalAppContextSwitches::get_EnforceLegacyJapaneseDateParsing() || dtfi->get_Calendar()->get_ID() != CalendarId::JAPAN || !str.GetNext()) {
    return false;
  }
  if (str.m_current != "元"[0]) {
    str.Index--;
    return false;
  }
  return true;
}

void DateTimeParse::ConfigureFormatR(DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo, DateTimeResult& result) {
  parseInfo.calendar = GregorianCalendar::in::GetDefaultInstance();
  dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
  if ((result.flags & ParseFlags::CaptureOffset) != 0) {
    result.flags |= ParseFlags::Rfc1123Pattern;
  }
}

void DateTimeParse::ConfigureFormatOS(DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo) {
  parseInfo.calendar = GregorianCalendar::in::GetDefaultInstance();
  dtfi = DateTimeFormatInfo::in::get_InvariantInfo();
}

Boolean DateTimeParse::ParseByFormat(__DTString& str, __DTString& format, ParsingInfo& parseInfo, DateTimeFormatInfo dtfi, DateTimeResult& result) {
  Int32 result2 = 0;
  Int32 result3 = 0;
  Int32 result4 = 0;
  Int32 result5 = 0;
  Int32 result6 = 0;
  Int32 result7 = 0;
  Int32 result8 = 0;
  Double result9 = 0;
  TM result10 = TM::AM;
  Char char一 = format.GetChar();
  switch (char一.get()) {
    case u'y':
      {
        Int32 repeatCount = format.GetRepeatCount();
        Boolean flag;
        if (ParseJapaneseEraStart(str, dtfi)) {
          result2 = 1;
          flag = true;
        } else if (dtfi->get_HasForceTwoDigitYears()) {
          flag = ParseDigits(str, 1, 4, result2);
        } else {
          if (repeatCount <= 2) {
            parseInfo.fUseTwoDigitYear = true;
          }
          flag = ParseDigits(str, repeatCount, result2);
        }

        if (!flag && parseInfo.fCustomNumberParser) {
          flag = parseInfo.parseNumberDelegate(str, repeatCount, result2);
        }
        if (!flag) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if (!CheckNewValue(result.Year, result2, char一, result)) {
          return false;
        }
        break;
      }case u'M':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (repeatCount <= 2) {
          if (!ParseDigits(str, repeatCount, result3) && (!parseInfo.fCustomNumberParser || !parseInfo.parseNumberDelegate(str, repeatCount, result3))) {
            result.SetBadDateTimeFailure();
            return false;
          }
        } else {
          if (repeatCount == 3) {
            if (!MatchAbbreviatedMonthName(str, dtfi, result3)) {
              result.SetBadDateTimeFailure();
              return false;
            }
          } else if (!MatchMonthName(str, dtfi, result3)) {
            result.SetBadDateTimeFailure();
            return false;
          }

          result.flags |= ParseFlags::ParsedMonthName;
        }
        if (!CheckNewValue(result.Month, result3, char一, result)) {
          return false;
        }
        break;
      }case u'd':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (repeatCount <= 2) {
          if (!ParseDigits(str, repeatCount, result4) && (!parseInfo.fCustomNumberParser || !parseInfo.parseNumberDelegate(str, repeatCount, result4))) {
            result.SetBadDateTimeFailure();
            return false;
          }
          if (!CheckNewValue(result.Day, result4, char一, result)) {
            return false;
          }
          break;
        }
        if (repeatCount == 3) {
          if (!MatchAbbreviatedDayName(str, dtfi, result5)) {
            result.SetBadDateTimeFailure();
            return false;
          }
        } else if (!MatchDayName(str, dtfi, result5)) {
          result.SetBadDateTimeFailure();
          return false;
        }

        if (!CheckNewValue(parseInfo.dayOfWeek, result5, char一, result)) {
          return false;
        }
        break;
      }case u'g':
      format.GetRepeatCount();
      if (!MatchEraName(str, dtfi, result.era)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      break;
    case u'h':
      {
        parseInfo.fUseHour12 = true;
        Int32 repeatCount = format.GetRepeatCount();
        if (!ParseDigits(str, (repeatCount < 2) ? 1 : 2, result6)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if (!CheckNewValue(result.Hour, result6, char一, result)) {
          return false;
        }
        break;
      }case u'H':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (!ParseDigits(str, (repeatCount < 2) ? 1 : 2, result6)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if (!CheckNewValue(result.Hour, result6, char一, result)) {
          return false;
        }
        break;
      }case u'm':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (!ParseDigits(str, (repeatCount < 2) ? 1 : 2, result7)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if (!CheckNewValue(result.Minute, result7, char一, result)) {
          return false;
        }
        break;
      }case u's':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (!ParseDigits(str, (repeatCount < 2) ? 1 : 2, result8)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if (!CheckNewValue(result.Second, result8, char一, result)) {
          return false;
        }
        break;
      }case u'F':
    case u'f':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (repeatCount <= 7) {
          if (!ParseFractionExact(str, repeatCount, result9) && char一 == u'f') {
            result.SetBadDateTimeFailure();
            return false;
          }
          if (result.fraction < 0) {
            result.fraction = result9;
          } else if (result9 != result.fraction) {
            result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", char一);
            return false;
          }

          break;
        }
        result.SetBadDateTimeFailure();
        return false;
      }case u't':
      {
        Int32 repeatCount = format.GetRepeatCount();
        if (repeatCount == 1) {
          if (!MatchAbbreviatedTimeMark(str, dtfi, result10)) {
            result.SetBadDateTimeFailure();
            return false;
          }
        } else if (!MatchTimeMark(str, dtfi, result10)) {
          result.SetBadDateTimeFailure();
          return false;
        }

        if (parseInfo.timeMark == TM::NotSet) {
          parseInfo.timeMark = result10;
        } else if (parseInfo.timeMark != result10) {
          result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", char一);
          return false;
        }

        break;
      }case u'z':
      {
        Int32 repeatCount = format.GetRepeatCount();
        TimeSpan result11 = TimeSpan(0);
        if (!ParseTimeZoneOffset(str, repeatCount, result11)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if ((result.flags & ParseFlags::TimeZoneUsed) != 0 && result11 != result.timeZoneOffset) {
          result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", u'z');
          return false;
        }
        result.timeZoneOffset = result11;
        result.flags |= ParseFlags::TimeZoneUsed;
        break;
      }case u'Z':
      if ((result.flags & ParseFlags::TimeZoneUsed) != 0 && result.timeZoneOffset != TimeSpan::Zero) {
        result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", u'Z');
        return false;
      }
      result.flags |= ParseFlags::TimeZoneUsed;
      result.timeZoneOffset = TimeSpan(0);
      result.flags |= ParseFlags::TimeZoneUtc;
      str.Index++;
      if (!GetTimeZoneName(str)) {
        result.SetBadDateTimeFailure();
        return false;
      }
      str.Index--;
      break;
    case u'K':
      if (str.Match(u'Z')) {
        if ((result.flags & ParseFlags::TimeZoneUsed) != 0 && result.timeZoneOffset != TimeSpan::Zero) {
          result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", u'K');
          return false;
        }
        result.flags |= ParseFlags::TimeZoneUsed;
        result.timeZoneOffset = TimeSpan(0);
        result.flags |= ParseFlags::TimeZoneUtc;
      } else if (str.Match(u'+') || str.Match(u'-')) {
        str.Index--;
        TimeSpan result12 = TimeSpan(0);
        if (!ParseTimeZoneOffset(str, 3, result12)) {
          result.SetBadDateTimeFailure();
          return false;
        }
        if ((result.flags & ParseFlags::TimeZoneUsed) != 0 && result12 != result.timeZoneOffset) {
          result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_RepeatDateTimePattern", u'K');
          return false;
        }
        result.timeZoneOffset = result12;
        result.flags |= ParseFlags::TimeZoneUsed;
      }

      break;
    case u':':
      if (((dtfi->get_TimeSeparator()->get_Length() > 1 && dtfi->get_TimeSeparator()[0] == u':') || !str.Match(u':')) && !str.Match(dtfi->get_TimeSeparator())) {
        result.SetBadDateTimeFailure();
        return false;
      }
      break;
    case u'/':
      if (((dtfi->get_DateSeparator()->get_Length() > 1 && dtfi->get_DateSeparator()[0] == u'/') || !str.Match(u'/')) && !str.Match(dtfi->get_DateSeparator())) {
        result.SetBadDateTimeFailure();
        return false;
      }
      break;
    case u'"':
    case u'\'':
      {
        StringBuilder stringBuilder = StringBuilderCache::Acquire();
        Int32 repeatCount;
        if (!TryParseQuoteString(format.Value, format.Index, stringBuilder, repeatCount)) {
          result.SetFailure(ParseFailureKind::FormatWithParameter, "Format_BadQuote", char一);
          StringBuilderCache::Release(stringBuilder);
          return false;
        }
        format.Index += repeatCount - 1;
        String stringAndRelease = StringBuilderCache::GetStringAndRelease(stringBuilder);
        for (Int32 i = 0; i < stringAndRelease->get_Length(); i++) {
          if (stringAndRelease[i] == u' ' && parseInfo.fAllowInnerWhite) {
            str.SkipWhiteSpaces();
          } else if (!str.Match(stringAndRelease[i])) {
            result.SetBadDateTimeFailure();
            return false;
          }

        }
        if ((result.flags & ParseFlags::CaptureOffset) != 0 && (((result.flags & ParseFlags::Rfc1123Pattern) != 0 && stringAndRelease == "GMT") || ((result.flags & ParseFlags::UtcSortPattern) != 0 && stringAndRelease == "Z"))) {
          result.flags |= ParseFlags::TimeZoneUsed;
          result.timeZoneOffset = TimeSpan::Zero;
        }
        break;
      }case u'%':
      if (format.Index >= format.Value.get_Length() - 1 || format.Value[format.Index + 1] == u'%') {
        result.SetBadFormatSpecifierFailure(format.Value);
        return false;
      }
      break;
    case u'\\':
      if (format.GetNext()) {
        if (!str.Match(format.GetChar())) {
          result.SetBadDateTimeFailure();
          return false;
        }
        break;
      }
      result.SetBadFormatSpecifierFailure(format.Value);
      return false;
    case u'.':
      if (!str.Match(char一)) {
        if (!format.GetNext() || !format.Match(u'F')) {
          result.SetBadDateTimeFailure();
          return false;
        }
        format.GetRepeatCount();
      }
      break;
    default:
      if (char一 == u' ') {
        if (!parseInfo.fAllowInnerWhite && !str.Match(char一)) {
          if (parseInfo.fAllowTrailingWhite && format.GetNext() && ParseByFormat(str, format, parseInfo, dtfi, result)) {
            return true;
          }
          result.SetBadDateTimeFailure();
          return false;
        }
      } else if (format.MatchSpecifiedWord("GMT")) {
        format.Index += "GMT"->get_Length() - 1;
        result.flags |= ParseFlags::TimeZoneUsed;
        result.timeZoneOffset = TimeSpan::Zero;
        if (!str.Match("GMT")) {
          result.SetBadDateTimeFailure();
          return false;
        }
      } else if (!str.Match(char一)) {
        result.SetBadDateTimeFailure();
        return false;
      }


      break;
  }
  return true;
}

Boolean DateTimeParse::TryParseQuoteString(ReadOnlySpan<Char> format, Int32 pos, StringBuilder result, Int32& returnValue) {
  returnValue = 0;
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
    if (c2 == u'\\') {
      if (pos >= length) {
        return false;
      }
      result->Append(format[pos++]);
    } else {
      result->Append(c2);
    }
  }
  if (!flag) {
    return false;
  }
  returnValue = pos - num;
  return true;
}

Boolean DateTimeParse::DoStrictParse(ReadOnlySpan<Char> s, ReadOnlySpan<Char> formatParam, DateTimeStyles styles, DateTimeFormatInfo dtfi, DateTimeResult& result) {
  ParsingInfo parseInfo;
  parseInfo.Init();
  parseInfo.calendar = dtfi->set_Calendar();
  parseInfo.fAllowInnerWhite = (styles & DateTimeStyles::AllowInnerWhite) != 0;
  parseInfo.fAllowTrailingWhite = (styles & DateTimeStyles::AllowTrailingWhite) != 0;
  if (formatParam.get_Length() == 1) {
    Char c = formatParam[0];
    if (styles == DateTimeStyles::None) {
      switch (c.get()) {
        case u'R':
        case u'r':
          ConfigureFormatR(dtfi, parseInfo, result);
          return ParseFormatR(s, parseInfo, result);
        case u'O':
        case u'o':
          ConfigureFormatOS(dtfi, parseInfo);
          return ParseFormatO(s, result);
      }
    }
    if ((result.flags & ParseFlags::CaptureOffset) != 0 && c == u'U') {
      result.SetBadFormatSpecifierFailure(formatParam);
      return false;
    }
    formatParam = ExpandPredefinedFormat(formatParam, dtfi, parseInfo, result);
  }
  result.calendar = parseInfo.calendar;
  if (parseInfo.calendar->get_ID() == CalendarId::HEBREW) {
    parseInfo.parseNumberDelegate = s_hebrewNumberParser;
    parseInfo.fCustomNumberParser = true;
  }
  result.Hour = (result.Minute = (result.Second = -1));
  __DTString format = __DTString(formatParam, dtfi, false);
  __DTString str = __DTString(s, dtfi, false);
  if (parseInfo.fAllowTrailingWhite) {
    format.TrimTail();
    format.RemoveTrailingInQuoteSpaces();
    str.TrimTail();
  }
  if ((styles & DateTimeStyles::AllowLeadingWhite) != 0) {
    format.SkipWhiteSpaces();
    format.RemoveLeadingInQuoteSpaces();
    str.SkipWhiteSpaces();
  }
  while (format.GetNext()) {
    if (parseInfo.fAllowInnerWhite) {
      str.SkipWhiteSpaces();
    }
    if (!ParseByFormat(str, format, parseInfo, dtfi, result)) {
      return false;
    }
  }
  if (str.Index < str.Value.get_Length() - 1) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (parseInfo.fUseTwoDigitYear && (dtfi->get_FormatFlags() & DateTimeFormatFlags::UseHebrewRule) == 0) {
    if (result.Year >= 100) {
      result.SetBadDateTimeFailure();
      return false;
    }
    try {
      result.Year = parseInfo.calendar->ToFourDigitYear(result.Year);
    } catch (ArgumentOutOfRangeException) {
      result.SetBadDateTimeFailure();
      return false;
    }
  }
  if (parseInfo.fUseHour12) {
    if (parseInfo.timeMark == TM::NotSet) {
      parseInfo.timeMark = TM::AM;
    }
    if (result.Hour > 12) {
      result.SetBadDateTimeFailure();
      return false;
    }
    if (parseInfo.timeMark == TM::AM) {
      if (result.Hour == 12) {
        result.Hour = 0;
      }
    } else {
      result.Hour = ((result.Hour == 12) ? 12 : (result.Hour + 12));
    }
  } else if ((parseInfo.timeMark == TM::AM && result.Hour >= 12) || (parseInfo.timeMark == TM::PM && result.Hour < 12)) {
    result.SetBadDateTimeFailure();
    return false;
  }

  Boolean flag = result.Year == -1 && result.Month == -1 && result.Day == -1;
  if (!CheckDefaultDateTime(result, parseInfo.calendar, styles)) {
    return false;
  }
  if (!flag && dtfi->get_HasYearMonthAdjustment() && !dtfi->YearMonthAdjustment(result.Year, result.Month, (result.flags & ParseFlags::ParsedMonthName) != 0)) {
    result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
    return false;
  }
  if (!parseInfo.calendar->TryToDateTime(result.Year, result.Month, result.Day, result.Hour, result.Minute, result.Second, 0, result.era, result.parsedDate)) {
    result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
    return false;
  }
  if (result.fraction > 0 && !result.parsedDate.TryAddTicks((Int64)Math::Round(result.fraction * 10000000), result.parsedDate)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (parseInfo.dayOfWeek != -1 && parseInfo.dayOfWeek != (Int32)parseInfo.calendar->GetDayOfWeek(result.parsedDate)) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_BadDayOfWeek");
    return false;
  }
  return DetermineTimeZoneAdjustments(result, styles, flag);
}

Boolean DateTimeParse::ParseFormatR(ReadOnlySpan<Char> source, ParsingInfo& parseInfo, DateTimeResult& result) {
  if (source.get_Length() != 29) {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num = source[0];
  UInt32 num2 = source[1];
  UInt32 num3 = source[2];
  UInt32 num4 = source[3];
  if ((num | num2 | num3 | num4) > 127) {
    result.SetBadDateTimeFailure();
    return false;
  }
  DayOfWeek dayOfWeek;
  switch ((num << 24) | (num2 << 16) | (num3 << 8) | num4 | 538976256.get()) {
    case 1937075756u:
      dayOfWeek = DayOfWeek::Sunday;
      break;
    case 1836019244u:
      dayOfWeek = DayOfWeek::Monday;
      break;
    case 1953850668u:
      dayOfWeek = DayOfWeek::Tuesday;
      break;
    case 2003133484u:
      dayOfWeek = DayOfWeek::Wednesday;
      break;
    case 1953002796u:
      dayOfWeek = DayOfWeek::Thursday;
      break;
    case 1718774060u:
      dayOfWeek = DayOfWeek::Friday;
      break;
    case 1935766572u:
      dayOfWeek = DayOfWeek::Saturday;
      break;
    default:
      result.SetBadDateTimeFailure();
      return false;
  }
  if (source[4] != u' ') {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num5 = (UInt32)(source[5] - 48);
  UInt32 num6 = (UInt32)(source[6] - 48);
  if (num5 > 9 || num6 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 day = (Int32)(num5 * 10 + num6);
  if (source[7] != u' ') {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num7 = source[8];
  UInt32 num8 = source[9];
  UInt32 num9 = source[10];
  UInt32 num10 = source[11];
  if ((num7 | num8 | num9 | num10) > 127) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 month;
  switch ((num7 << 24) | (num8 << 16) | (num9 << 8) | num10 | 538976256.get()) {
    case 1784770080u:
      month = 1;
      break;
    case 1717920288u:
      month = 2;
      break;
    case 1835102752u:
      month = 3;
      break;
    case 1634759200u:
      month = 4;
      break;
    case 1835104544u:
      month = 5;
      break;
    case 1786080800u:
      month = 6;
      break;
    case 1786080288u:
      month = 7;
      break;
    case 1635084064u:
      month = 8;
      break;
    case 1936027680u:
      month = 9;
      break;
    case 1868788768u:
      month = 10;
      break;
    case 1852798496u:
      month = 11;
      break;
    case 1684366112u:
      month = 12;
      break;
    default:
      result.SetBadDateTimeFailure();
      return false;
  }
  UInt32 num11 = (UInt32)(source[12] - 48);
  UInt32 num12 = (UInt32)(source[13] - 48);
  UInt32 num13 = (UInt32)(source[14] - 48);
  UInt32 num14 = (UInt32)(source[15] - 48);
  if (num11 > 9 || num12 > 9 || num13 > 9 || num14 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 year = (Int32)(num11 * 1000 + num12 * 100 + num13 * 10 + num14);
  if (source[16] != u' ') {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num15 = (UInt32)(source[17] - 48);
  UInt32 num16 = (UInt32)(source[18] - 48);
  if (num15 > 9 || num16 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 hour = (Int32)(num15 * 10 + num16);
  if (source[19] != u':') {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num17 = (UInt32)(source[20] - 48);
  UInt32 num18 = (UInt32)(source[21] - 48);
  if (num17 > 9 || num18 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 minute = (Int32)(num17 * 10 + num18);
  if (source[22] != u':') {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num19 = (UInt32)(source[23] - 48);
  UInt32 num20 = (UInt32)(source[24] - 48);
  if (num19 > 9 || num20 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 second = (Int32)(num19 * 10 + num20);
  if (source[25] != u' ' || source[26] != u'G' || source[27] != u'M' || source[28] != u'T') {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (!parseInfo.calendar->TryToDateTime(year, month, day, hour, minute, second, 0, 0, result.parsedDate)) {
    result.SetFailure(ParseFailureKind::FormatBadDateTimeCalendar, "Format_BadDateTimeCalendar");
    return false;
  }
  if (dayOfWeek != result.parsedDate.get_DayOfWeek()) {
    result.SetFailure(ParseFailureKind::FormatWithOriginalDateTime, "Format_BadDayOfWeek");
    return false;
  }
  return true;
}

Boolean DateTimeParse::ParseFormatO(ReadOnlySpan<Char> source, DateTimeResult& result) {
  if ((UInt32)source.get_Length() < 27u || source[4] != u'-' || source[7] != u'-' || source[10] != u'T' || source[13] != u':' || source[16] != u':' || source[19] != u'.') {
    result.SetBadDateTimeFailure();
    return false;
  }
  UInt32 num = (UInt32)(source[0] - 48);
  UInt32 num2 = (UInt32)(source[1] - 48);
  UInt32 num3 = (UInt32)(source[2] - 48);
  UInt32 num4 = (UInt32)(source[3] - 48);
  if (num > 9 || num2 > 9 || num3 > 9 || num4 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 year = (Int32)(num * 1000 + num2 * 100 + num3 * 10 + num4);
  UInt32 num5 = (UInt32)(source[5] - 48);
  UInt32 num6 = (UInt32)(source[6] - 48);
  if (num5 > 9 || num6 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 month = (Int32)(num5 * 10 + num6);
  UInt32 num7 = (UInt32)(source[8] - 48);
  UInt32 num8 = (UInt32)(source[9] - 48);
  if (num7 > 9 || num8 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 day = (Int32)(num7 * 10 + num8);
  UInt32 num9 = (UInt32)(source[11] - 48);
  UInt32 num10 = (UInt32)(source[12] - 48);
  if (num9 > 9 || num10 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 hour = (Int32)(num9 * 10 + num10);
  UInt32 num11 = (UInt32)(source[14] - 48);
  UInt32 num12 = (UInt32)(source[15] - 48);
  if (num11 > 9 || num12 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 minute = (Int32)(num11 * 10 + num12);
  UInt32 num13 = (UInt32)(source[17] - 48);
  UInt32 num14 = (UInt32)(source[18] - 48);
  if (num13 > 9 || num14 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Int32 second = (Int32)(num13 * 10 + num14);
  UInt32 num15 = (UInt32)(source[20] - 48);
  UInt32 num16 = (UInt32)(source[21] - 48);
  UInt32 num17 = (UInt32)(source[22] - 48);
  UInt32 num18 = (UInt32)(source[23] - 48);
  UInt32 num19 = (UInt32)(source[24] - 48);
  UInt32 num20 = (UInt32)(source[25] - 48);
  UInt32 num21 = (UInt32)(source[26] - 48);
  if (num15 > 9 || num16 > 9 || num17 > 9 || num18 > 9 || num19 > 9 || num20 > 9 || num21 > 9) {
    result.SetBadDateTimeFailure();
    return false;
  }
  Double num22 = (Double)(num15 * 1000000 + num16 * 100000 + num17 * 10000 + num18 * 1000 + num19 * 100 + num20 * 10 + num21) / 10000000;
  DateTime result2;
  if (!DateTime::TryCreate(year, month, day, hour, minute, second, 0, result2)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if (!result2.TryAddTicks((Int64)Math::Round(num22 * 10000000), result.parsedDate)) {
    result.SetBadDateTimeFailure();
    return false;
  }
  if ((UInt32)source.get_Length() > 27u) {
    Char c = source[27];
    switch (c.get()) {
      case u'Z':
        if (source.get_Length() != 28) {
          result.SetBadDateTimeFailure();
          return false;
        }
        result.flags |= ParseFlags::TimeZoneUsed | ParseFlags::TimeZoneUtc;
        break;
      case u'+':
      case u'-':
        {
          Int32 num25;
          Int32 num26;
          if (source.get_Length() == 33) {
            UInt32 num23 = (UInt32)(source[28] - 48);
            UInt32 num24 = (UInt32)(source[29] - 48);
            if (num23 > 9 || num24 > 9) {
              result.SetBadDateTimeFailure();
              return false;
            }
            num25 = (Int32)(num23 * 10 + num24);
            num26 = 30;
          } else {
            if (source.get_Length() != 32) {
              result.SetBadDateTimeFailure();
              return false;
            }
            num25 = source[28] - 48;
            if ((UInt32)num25 > 9u) {
              result.SetBadDateTimeFailure();
              return false;
            }
            num26 = 29;
          }
          if (source[num26] != u':') {
            result.SetBadDateTimeFailure();
            return false;
          }
          UInt32 num27 = (UInt32)(source[num26 + 1] - 48);
          UInt32 num28 = (UInt32)(source[num26 + 2] - 48);
          if (num27 > 9 || num28 > 9) {
            result.SetBadDateTimeFailure();
            return false;
          }
          Int32 minutes = (Int32)(num27 * 10 + num28);
          result.flags |= ParseFlags::TimeZoneUsed;
          result.timeZoneOffset = TimeSpan(num25, minutes, 0);
          if (c == u'-') {
            result.timeZoneOffset = result.timeZoneOffset.Negate();
          }
          break;
        }default:
        result.SetBadDateTimeFailure();
        return false;
    }
  }
  return DetermineTimeZoneAdjustments(result, DateTimeStyles::None, false);
}

Exception DateTimeParse::GetDateTimeParseException(DateTimeResult& result) {
}

void DateTimeParse::cctor() {
  s_hebrewNumberParser = &MatchHebrewDigits;
  s_dateParsingStates = rt::newarr<Array<Array<DS>>>(20);
}

} // namespace System::Private::CoreLib::System::DateTimeParseNamespace
