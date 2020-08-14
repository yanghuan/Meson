#include "TimeSpanFormat-dep.h"

#include <System.Private.CoreLib/System/DateTimeFormat-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeFormatInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanFormat-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanParse-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Globalization::TimeSpanFormatNamespace {
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
  }
  return StringBuilderCache::GetStringAndRelease(FormatCustomized(value, format, DateTimeFormatInfo::in::GetInstance(formatProvider)));
}

Boolean TimeSpanFormat::TryFormat(TimeSpan value, Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  if (format.get_Length() == 0) {
    return TryFormatStandard(value, StandardFormat::C, nullptr, destination, charsWritten);
  }
  if (format.get_Length() == 1) {
    Char c = format[0];
  }
  StringBuilder stringBuilder = FormatCustomized(value, format, DateTimeFormatInfo::in::GetInstance(formatProvider));
  if (stringBuilder->get_Length() <= destination.get_Length()) {
    stringBuilder->CopyTo(0, destination, stringBuilder->get_Length());
    charsWritten = stringBuilder->set_Length;
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
}

String TimeSpanFormat::FormatG(TimeSpan value, DateTimeFormatInfo dtfi, StandardFormat format) {
  String decimalSeparator = dtfi->get_DecimalSeparator();
  Int32 num = 25 + decimalSeparator->get_Length();
  Char default[num] = {};
  Span<Char> span = (num >= 128) ? ((Span<Char>)rt::newarr<Array<Char>>(num)) : default;
  Span<Char> destination = span;
}

Boolean TimeSpanFormat::TryFormatStandard(TimeSpan value, StandardFormat format, String decimalSeparator, Span<Char> destination, Int32& charsWritten) {
  Int32 num = 8;
  Int64 num2 = value.get_Ticks();
  UInt32 valueWithoutTrailingZeros;
  UInt64 num3;
  if (num2 < 0) {
    num = 9;
  }
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
  }
  Int32 value2 = (Int32)(num2 / 36000000000 % 24);
  Int32 value3 = (Int32)(num2 / 600000000 % 60);
  Int32 value4 = (Int32)(num2 / 10000000 % 60);
  Int32 num3 = (Int32)(num2 % 10000000);
  Int64 num4 = 0;
  Int32 num6;
  for (Int32 i = 0; i < format.get_Length(); i += num6) {
    Char c = format[i];
  }
  return result;
}

void TimeSpanFormat::cctor() {
  PositiveInvariantFormatLiterals = FormatLiterals::InitInvariant(false);
  NegativeInvariantFormatLiterals = FormatLiterals::InitInvariant(true);
}

} // namespace System::Private::CoreLib::System::Globalization::TimeSpanFormatNamespace
