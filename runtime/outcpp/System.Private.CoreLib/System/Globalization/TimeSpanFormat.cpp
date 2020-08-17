#include "TimeSpanFormat-dep.h"

#include <System.Private.CoreLib/System/Buffers/Text/FormattingHelpers-dep.h>
#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanFormat-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanParse-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Globalization::TimeSpanFormatNamespace {
using namespace System::Buffers::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

String TimeSpanFormat::FormatLiterals::get_Start() {
  return _literals[0];
}

String TimeSpanFormat::FormatLiterals::get_DayHourSep() {
  return _literals[1];
}

String TimeSpanFormat::FormatLiterals::get_HourMinuteSep() {
  return _literals[2];
}

String TimeSpanFormat::FormatLiterals::get_MinuteSecondSep() {
  return _literals[3];
}

String TimeSpanFormat::FormatLiterals::get_SecondFractionSep() {
  return _literals[4];
}

String TimeSpanFormat::FormatLiterals::get_End() {
  return _literals[5];
}

TimeSpanFormat::FormatLiterals TimeSpanFormat::FormatLiterals::InitInvariant(Boolean isNegative) {
  FormatLiterals result = FormatLiterals();
  result._literals = rt::newarr<Array<String>>(6);
  result._literals[0] = (isNegative ? "-" : String::in::Empty);
  result._literals[1] = ".";
  result._literals[2] = ":";
  result._literals[3] = ":";
  result._literals[4] = ".";
  result._literals[5] = String::in::Empty;
  result.AppCompatLiteral = ":.";
  result.dd = 2;
  result.hh = 2;
  result.mm = 2;
  result.ss = 2;
  result.ff = 7;
  return result;
}

void TimeSpanFormat::FormatLiterals::Init(ReadOnlySpan<Char> format, Boolean useInvariantFieldLengths) {
  dd = (hh = (mm = (ss = (ff = 0))));
  _literals = rt::newarr<Array<String>>(6);
  for (Int32 i = 0; i < _literals->get_Length(); i++) {
    _literals[i] = String::in::Empty;
  }
  StringBuilder stringBuilder = StringBuilderCache::Acquire();
  Boolean flag = false;
  Char c = 39;
  Int32 num = 0;
  for (Int32 j = 0; j < format.get_Length(); j++) {
    switch (format[j].get()) {
      case 34:
      case 39:
        if (flag && c == format[j]) {
          if (num < 0 || num > 5) {
            return;
          }
          _literals[num] = stringBuilder->ToString();
          stringBuilder->set_Length(0);
          flag = false;
        } else if (!flag) {
          c = format[j];
          flag = true;
        }

        continue;
      case 92:
        if (!flag) {
          j++;
          continue;
        }
        break;
      case 100:
        if (!flag) {
          num = 1;
          dd++;
        }
        continue;
      case 104:
        if (!flag) {
          num = 2;
          hh++;
        }
        continue;
      case 109:
        if (!flag) {
          num = 3;
          mm++;
        }
        continue;
      case 115:
        if (!flag) {
          num = 4;
          ss++;
        }
        continue;
      case 70:
      case 102:
        if (!flag) {
          num = 5;
          ff++;
        }
        continue;
    }
    stringBuilder->Append(format[j]);
  }
  AppCompatLiteral = get_MinuteSecondSep() + get_SecondFractionSep();
  if (useInvariantFieldLengths) {
    dd = 2;
    hh = 2;
    mm = 2;
    ss = 2;
    ff = 7;
  } else {
    if (dd < 1 || dd > 2) {
      dd = 2;
    }
    if (hh < 1 || hh > 2) {
      hh = 2;
    }
    if (mm < 1 || mm > 2) {
      mm = 2;
    }
    if (ss < 1 || ss > 2) {
      ss = 2;
    }
    if (ff < 1 || ff > 7) {
      ff = 7;
    }
  }
  StringBuilderCache::Release(stringBuilder);
}

String TimeSpanFormat::Format(TimeSpan value, String format, IFormatProvider formatProvider) {
  if (String::in::IsNullOrEmpty(format)) {
    return FormatC(value);
  }
  if (format->get_Length() == 1) {
    Char c = format[0];
    if (c == 99 || (c | 32) == 116) {
      return FormatC(value);
    }
    if ((c | 32) == 103) {
      return FormatG(value, DateTimeFormatInfo::in::GetInstance(formatProvider), (c == 71) ? StandardFormat::G : StandardFormat::g);
    }
    rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
  }
  return StringBuilderCache::GetStringAndRelease(FormatCustomized(value, format, DateTimeFormatInfo::in::GetInstance(formatProvider)));
}

Boolean TimeSpanFormat::TryFormat(TimeSpan value, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  if (format.get_Length() == 0) {
    return TryFormatStandard(value, StandardFormat::C, nullptr, destination, charsWritten);
  }
  if (format.get_Length() == 1) {
    Char c = format[0];
    if (c == 99 || (c | 32) == 116) {
      return TryFormatStandard(value, StandardFormat::C, nullptr, destination, charsWritten);
    }
    Int32 num;
    switch (c.get()) {
      default:
        rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
      case 71:
        num = 1;
        break;
      case 103:
        num = 2;
        break;
    }
    StandardFormat format2 = (StandardFormat)num;
    return TryFormatStandard(value, format2, DateTimeFormatInfo::in::GetInstance(formatProvider)->get_DecimalSeparator(), destination, charsWritten);
  }
  StringBuilder stringBuilder = FormatCustomized(value, format, DateTimeFormatInfo::in::GetInstance(formatProvider));
  if (stringBuilder->get_Length() <= destination.get_Length()) {
    stringBuilder->CopyTo(0, destination, stringBuilder->get_Length());
    charsWritten = stringBuilder->set_Length();
    StringBuilderCache::Release(stringBuilder);
    return true;
  }
  charsWritten = 0;
  StringBuilderCache::Release(stringBuilder);
  return false;
}

String TimeSpanFormat::FormatC(TimeSpan value) {
  Char default[26] = {};
  Span<Char> destination = default;
  Int32 charsWritten;
  TryFormatStandard(value, StandardFormat::C, nullptr, destination, charsWritten);
  return rt::newobj<String>(destination.Slice(0, charsWritten));
}

String TimeSpanFormat::FormatG(TimeSpan value, DateTimeFormatInfo dtfi, StandardFormat format) {
  String decimalSeparator = dtfi->get_DecimalSeparator();
  Int32 num = 25 + decimalSeparator->get_Length();
  Char default[num] = {};
  Span<Char> span = (num >= 128) ? ((Span<Char>)rt::newarr<Array<Char>>(num)) : default;
  Span<Char> destination = span;
  Int32 charsWritten;
  TryFormatStandard(value, format, decimalSeparator, destination, charsWritten);
  return rt::newobj<String>(destination.Slice(0, charsWritten));
}

Boolean TimeSpanFormat::TryFormatStandard(TimeSpan value, StandardFormat format, String decimalSeparator, Span<Char> destination, Int32& charsWritten) {
  Int32 num = 8;
  Int64 num2 = value.get_Ticks();
  UInt32 valueWithoutTrailingZeros;
  UInt64 num3;
  if (num2 < 0) {
    num = 9;
    num2 = -num2;
    if (num2 < 0) {
      valueWithoutTrailingZeros = 4775808u;
      num3 = 922337203685;
      goto IL_0045;
    }
  }
  UInt64 result;
  num3 = Math::DivRem((UInt64)num2, 10000000, result);
  valueWithoutTrailingZeros = (UInt32)result;
  goto IL_0045;

IL_0045:
  Int32 num4 = 0;
  switch (format) {
    case StandardFormat::C:
      if (valueWithoutTrailingZeros != 0) {
        num4 = 7;
        num += num4 + 1;
      }
      break;
    case StandardFormat::G:
      num4 = 7;
      num += num4 + 1;
      break;
    default:
      if (valueWithoutTrailingZeros != 0) {
        num4 = 7 - FormattingHelpers::CountDecimalTrailingZeros(valueWithoutTrailingZeros, valueWithoutTrailingZeros);
        num += num4 + 1;
      }
      break;
  }
  UInt64 num5 = 0;
  UInt64 result2 = 0;
  if (num3 != 0) {
    num5 = Math::DivRem(num3, 60, result2);
  }
  UInt64 num6 = 0;
  UInt64 result3 = 0;
  if (num5 != 0) {
    num6 = Math::DivRem(num5, 60, result3);
  }
  UInt32 num7 = 0u;
  UInt32 result4 = 0u;
  if (num6 != 0) {
    num7 = Math::DivRem((UInt32)num6, 24u, result4);
  }
  Int32 num8 = 2;
  if (format == StandardFormat::g && result4 < 10) {
    num8 = 1;
    num--;
  }
  Int32 num9 = 0;
  if (num7 != 0) {
    num9 = FormattingHelpers::CountDigits(num7);
    num += num9 + 1;
  } else if (format == StandardFormat::G) {
    num += 2;
    num9 = 1;
  }

  if (destination.get_Length() < num) {
    charsWritten = 0;
    return false;
  }
  Int32 num10 = 0;
  if (value.get_Ticks() < 0) {
    destination[num10++] = 45;
  }
  if (num9 != 0) {
    WriteDigits(num7, destination.Slice(num10, num9));
    num10 += num9;
    destination[num10++] = ((format == StandardFormat::C) ? 46 : 58);
  }
  if (num8 == 2) {
    WriteTwoDigits(result4, destination.Slice(num10));
    num10 += 2;
  } else {
    destination[num10++] = (Char)(48 + result4);
  }
  destination[num10++] = 58;
  WriteTwoDigits((UInt32)result3, destination.Slice(num10));
  num10 += 2;
  destination[num10++] = 58;
  WriteTwoDigits((UInt32)result2, destination.Slice(num10));
  num10 += 2;
  if (num4 != 0) {
    if (format == StandardFormat::C) {
      destination[num10++] = 46;
    } else if (decimalSeparator->get_Length() == 1) {
      destination[num10++] = decimalSeparator[0];
    } else {
      MemoryExtensions::AsSpan(decimalSeparator).CopyTo(destination);
      num10 += decimalSeparator->get_Length();
    }

    WriteDigits(valueWithoutTrailingZeros, destination.Slice(num10, num4));
    num10 += num4;
  }
  charsWritten = num;
  return true;
}

void TimeSpanFormat::WriteTwoDigits(UInt32 value, Span<Char> buffer) {
  UInt32 num = 48 + value;
  value /= 10u;
  buffer[1] = (Char)(num - value * 10);
  buffer[0] = (Char)(48 + value);
}

void TimeSpanFormat::WriteDigits(UInt32 value, Span<Char> buffer) {
  for (Int32 num = buffer.get_Length() - 1; num >= 1; num--) {
    UInt32 num2 = 48 + value;
    value /= 10u;
    buffer[num] = (Char)(num2 - value * 10);
  }
  buffer[0] = (Char)(48 + value);
}

StringBuilder TimeSpanFormat::FormatCustomized(TimeSpan value, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, StringBuilder result) {
  Boolean flag = false;
  if (result == nullptr) {
    result = StringBuilderCache::Acquire();
    flag = true;
  }
  Int32 num = (Int32)(value.get_Ticks() / 864000000000);
  Int64 num2 = value.get_Ticks() % 864000000000;
  if (value.get_Ticks() < 0) {
    num = -num;
    num2 = -num2;
  }
  Int32 value2 = (Int32)(num2 / 36000000000 % 24);
  Int32 value3 = (Int32)(num2 / 600000000 % 60);
  Int32 value4 = (Int32)(num2 / 10000000 % 60);
  Int32 num3 = (Int32)(num2 % 10000000);
  Int64 num4 = 0;
  Int32 num6;
  for (Int32 i = 0; i < format.get_Length(); i += num6) {
    Char c = format[i];
    switch (c.get()) {
      case 104:
        num6 = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (num6 <= 2) {
          DateTimeFormat::FormatDigits(result, value2, num6);
          continue;
        }
        break;
      case 109:
        num6 = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (num6 <= 2) {
          DateTimeFormat::FormatDigits(result, value3, num6);
          continue;
        }
        break;
      case 115:
        num6 = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (num6 <= 2) {
          DateTimeFormat::FormatDigits(result, value4, num6);
          continue;
        }
        break;
      case 102:
        num6 = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (num6 <= 7) {
          num4 = num3;
          num4 /= TimeSpanParse::Pow10(7 - num6);
          result->AppendSpanFormattable(num4, DateTimeFormat::fixedNumberFormats[num6 - 1], CultureInfo::in::get_InvariantCulture());
          continue;
        }
        break;
      case 70:
        num6 = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (num6 <= 7) {
          num4 = num3;
          num4 /= TimeSpanParse::Pow10(7 - num6);
          Int32 num7 = num6;
          while (num7 > 0 && num4 % 10 == 0) {
            num4 /= 10;
            num7--;
          }
          if (num7 > 0) {
            result->AppendSpanFormattable(num4, DateTimeFormat::fixedNumberFormats[num7 - 1], CultureInfo::in::get_InvariantCulture());
          }
          continue;
        }
        break;
      case 100:
        num6 = DateTimeFormat::ParseRepeatPattern(format, i, c);
        if (num6 <= 8) {
          DateTimeFormat::FormatDigits(result, num, num6, true);
          continue;
        }
        break;
      case 34:
      case 39:
        num6 = DateTimeFormat::ParseQuoteString(format, i, result);
        continue;
      case 37:
        {
          Int32 num5 = DateTimeFormat::ParseNextChar(format, i);
          if (num5 >= 0 && num5 != 37) {
            Char reference = (Char)num5;
            StringBuilder stringBuilder = FormatCustomized(value, MemoryMarshal::CreateReadOnlySpan(reference, 1), dtfi, result);
            num6 = 2;
            continue;
          }
          break;
        }case 92:
        {
          Int32 num5 = DateTimeFormat::ParseNextChar(format, i);
          if (num5 >= 0) {
            result->Append((Char)num5);
            num6 = 2;
            continue;
          }
          break;
        }}
    if (flag) {
      StringBuilderCache::Release(result);
    }
    rt::throw_exception<FormatException>(SR::get_Format_InvalidString());
  }
  return result;
}

void TimeSpanFormat::cctor() {
  PositiveInvariantFormatLiterals = FormatLiterals::InitInvariant(false);
  NegativeInvariantFormatLiterals = FormatLiterals::InitInvariant(true);
}

} // namespace System::Private::CoreLib::System::Globalization::TimeSpanFormatNamespace
