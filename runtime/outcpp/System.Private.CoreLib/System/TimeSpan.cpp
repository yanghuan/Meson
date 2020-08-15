#include "TimeSpan-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanFormat-dep.h>
#include <System.Private.CoreLib/System/Globalization/TimeSpanParse-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/OverflowException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>

namespace System::Private::CoreLib::System::TimeSpanNamespace {
using namespace System::Globalization;

Int64 TimeSpan::get_Ticks() {
  return _ticks;
}

Int32 TimeSpan::get_Days() {
  return (Int32)(_ticks / 864000000000);
}

Int32 TimeSpan::get_Hours() {
  return (Int32)(_ticks / 36000000000 % 24);
}

Int32 TimeSpan::get_Milliseconds() {
  return (Int32)(_ticks / 10000 % 1000);
}

Int32 TimeSpan::get_Minutes() {
  return (Int32)(_ticks / 600000000 % 60);
}

Int32 TimeSpan::get_Seconds() {
  return (Int32)(_ticks / 10000000 % 60);
}

Double TimeSpan::get_TotalDays() {
  return (Double)_ticks / 864000000000;
}

Double TimeSpan::get_TotalHours() {
  return (Double)_ticks / 36000000000;
}

Double TimeSpan::get_TotalMilliseconds() {
  Double num = (Double)_ticks / 10000;
  if (num > 922337203685477) {
    return 922337203685477;
  }
  if (num < -922337203685477) {
    return -922337203685477;
  }
  return num;
}

Double TimeSpan::get_TotalMinutes() {
  return (Double)_ticks / 600000000;
}

Double TimeSpan::get_TotalSeconds() {
  return (Double)_ticks / 10000000;
}

TimeSpan::TimeSpan(Int64 ticks) {
  _ticks = ticks;
}

TimeSpan::TimeSpan(Int32 hours, Int32 minutes, Int32 seconds) {
  _ticks = TimeToTicks(hours, minutes, seconds);
}

TimeSpan::TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds) {
}

TimeSpan::TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds) {
  Int64 num = ((Int64)days * 3600 * 24 + (Int64)hours * 3600 + (Int64)minutes * 60 + seconds) * 1000 + milliseconds;
  if (num > 922337203685477 || num < -922337203685477) {
    rt::throw_exception<ArgumentOutOfRangeException>(nullptr, SR::get_Overflow_TimeSpanTooLong());
  }
  _ticks = num * 10000;
}

TimeSpan TimeSpan::Add(TimeSpan ts) {
  Int64 num = _ticks + ts._ticks;
  if (_ticks >> 63 == ts._ticks >> 63 && _ticks >> 63 != num >> 63) {
    rt::throw_exception<OverflowException>(SR::get_Overflow_TimeSpanTooLong());
  }
  return TimeSpan(num);
}

Int32 TimeSpan::Compare(TimeSpan t1, TimeSpan t2) {
  if (t1._ticks > t2._ticks) {
    return 1;
  }
  if (t1._ticks < t2._ticks) {
    return -1;
  }
  return 0;
}

Int32 TimeSpan::CompareTo(Object value) {
  if (value == nullptr) {
    return 1;
  }
  if (!rt::is<TimeSpan>(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeTimeSpan());
  }
  Int64 ticks = ((TimeSpan)value)._ticks;
  if (_ticks > ticks) {
    return 1;
  }
  if (_ticks < ticks) {
    return -1;
  }
  return 0;
}

Int32 TimeSpan::CompareTo(TimeSpan value) {
  Int64 ticks = value._ticks;
  if (_ticks > ticks) {
    return 1;
  }
  if (_ticks < ticks) {
    return -1;
  }
  return 0;
}

TimeSpan TimeSpan::FromDays(Double value) {
  return Interval(value, 864000000000);
}

TimeSpan TimeSpan::Duration() {
  if (get_Ticks() == MinValue.get_Ticks()) {
    rt::throw_exception<OverflowException>(SR::get_Overflow_Duration());
  }
  return TimeSpan((_ticks >= 0) ? _ticks : (-_ticks));
}

Boolean TimeSpan::Equals(Object value) {
  if (rt::is<TimeSpan>(value)) {
    return _ticks == ((TimeSpan)value)._ticks;
  }
  return false;
}

Boolean TimeSpan::Equals(TimeSpan obj) {
  return _ticks == obj._ticks;
}

Boolean TimeSpan::Equals(TimeSpan t1, TimeSpan t2) {
  return t1._ticks == t2._ticks;
}

Int32 TimeSpan::GetHashCode() {
  return (Int32)_ticks ^ (Int32)(_ticks >> 32);
}

TimeSpan TimeSpan::FromHours(Double value) {
  return Interval(value, 36000000000);
}

TimeSpan TimeSpan::Interval(Double value, Double scale) {
  if (Double::IsNaN(value)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_CannotBeNaN());
  }
  Double ticks = value * scale;
  return IntervalFromDoubleTicks(ticks);
}

TimeSpan TimeSpan::IntervalFromDoubleTicks(Double ticks) {
  if (ticks > 9.223372036854776E+18 || ticks < -9.223372036854776E+18 || Double::IsNaN(ticks)) {
    rt::throw_exception<OverflowException>(SR::get_Overflow_TimeSpanTooLong());
  }
  if (ticks == 9.223372036854776E+18) {
    return MaxValue;
  }
  return TimeSpan((Int64)ticks);
}

TimeSpan TimeSpan::FromMilliseconds(Double value) {
  return Interval(value, 10000);
}

TimeSpan TimeSpan::FromMinutes(Double value) {
  return Interval(value, 600000000);
}

TimeSpan TimeSpan::Negate() {
  if (get_Ticks() == MinValue.get_Ticks()) {
    rt::throw_exception<OverflowException>(SR::get_Overflow_NegateTwosCompNum());
  }
  return TimeSpan(-_ticks);
}

TimeSpan TimeSpan::FromSeconds(Double value) {
  return Interval(value, 10000000);
}

TimeSpan TimeSpan::Subtract(TimeSpan ts) {
  Int64 num = _ticks - ts._ticks;
  if (_ticks >> 63 != ts._ticks >> 63 && _ticks >> 63 != num >> 63) {
    rt::throw_exception<OverflowException>(SR::get_Overflow_TimeSpanTooLong());
  }
  return TimeSpan(num);
}

TimeSpan TimeSpan::Multiply(Double factor) {
  return *this * factor;
}

TimeSpan TimeSpan::Divide(Double divisor) {
  return *this / divisor;
}

Double TimeSpan::Divide(TimeSpan ts) {
  return *this / ts;
}

TimeSpan TimeSpan::FromTicks(Int64 value) {
  return TimeSpan(value);
}

Int64 TimeSpan::TimeToTicks(Int32 hour, Int32 minute, Int32 second) {
  Int64 num = (Int64)hour * 3600 + (Int64)minute * 60 + second;
  if (num > 922337203685 || num < -922337203685) {
    ThrowHelper::ThrowArgumentOutOfRange_TimeSpanTooLong();
  }
  return num * 10000000;
}

void TimeSpan::ValidateStyles(TimeSpanStyles style, String parameterName) {
  if (style != 0 && style != TimeSpanStyles::AssumeNegative) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidTimeSpanStyles(), parameterName);
  }
}

TimeSpan TimeSpan::Parse(String s) {
  if (s == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  return TimeSpanParse::Parse(s, nullptr);
}

TimeSpan TimeSpan::Parse(String input, IFormatProvider formatProvider) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  return TimeSpanParse::Parse(input, formatProvider);
}

TimeSpan TimeSpan::Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider) {
  return TimeSpanParse::Parse(input, formatProvider);
}

TimeSpan TimeSpan::ParseExact(String input, String format, IFormatProvider formatProvider) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  if (format == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::format);
  }
  return TimeSpanParse::ParseExact(input, format, formatProvider, TimeSpanStyles::None);
}

TimeSpan TimeSpan::ParseExact(String input, Array<String> formats, IFormatProvider formatProvider) {
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  return TimeSpanParse::ParseExactMultiple(input, formats, formatProvider, TimeSpanStyles::None);
}

TimeSpan TimeSpan::ParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles) {
  ValidateStyles(styles, "styles");
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  if (format == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::format);
  }
  return TimeSpanParse::ParseExact(input, format, formatProvider, styles);
}

TimeSpan TimeSpan::ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles) {
  ValidateStyles(styles, "styles");
  return TimeSpanParse::ParseExact(input, format, formatProvider, styles);
}

TimeSpan TimeSpan::ParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles) {
  ValidateStyles(styles, "styles");
  if (input == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::input);
  }
  return TimeSpanParse::ParseExactMultiple(input, formats, formatProvider, styles);
}

TimeSpan TimeSpan::ParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles) {
  ValidateStyles(styles, "styles");
  return TimeSpanParse::ParseExactMultiple(input, formats, formatProvider, styles);
}

Boolean TimeSpan::TryParse(String s, TimeSpan& result) {
  if (s == nullptr) {
    result = TimeSpan();
    return false;
  }
  return TimeSpanParse::TryParse(s, nullptr, result);
}

Boolean TimeSpan::TryParse(ReadOnlySpan<Char> s, TimeSpan& result) {
  return TimeSpanParse::TryParse(s, nullptr, result);
}

Boolean TimeSpan::TryParse(String input, IFormatProvider formatProvider, TimeSpan& result) {
  if (input == nullptr) {
    result = TimeSpan();
    return false;
  }
  return TimeSpanParse::TryParse(input, formatProvider, result);
}

Boolean TimeSpan::TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, TimeSpan& result) {
  return TimeSpanParse::TryParse(input, formatProvider, result);
}

Boolean TimeSpan::TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpan& result) {
  if (input == nullptr || format == nullptr) {
    result = TimeSpan();
    return false;
  }
  return TimeSpanParse::TryParseExact(input, format, formatProvider, TimeSpanStyles::None, result);
}

Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpan& result) {
  return TimeSpanParse::TryParseExact(input, format, formatProvider, TimeSpanStyles::None, result);
}

Boolean TimeSpan::TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpan& result) {
  if (input == nullptr) {
    result = TimeSpan();
    return false;
  }
  return TimeSpanParse::TryParseExactMultiple(input, formats, formatProvider, TimeSpanStyles::None, result);
}

Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpan& result) {
  return TimeSpanParse::TryParseExactMultiple(input, formats, formatProvider, TimeSpanStyles::None, result);
}

Boolean TimeSpan::TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  ValidateStyles(styles, "styles");
  if (input == nullptr || format == nullptr) {
    result = TimeSpan();
    return false;
  }
  return TimeSpanParse::TryParseExact(input, format, formatProvider, styles, result);
}

Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  ValidateStyles(styles, "styles");
  return TimeSpanParse::TryParseExact(input, format, formatProvider, styles, result);
}

Boolean TimeSpan::TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  ValidateStyles(styles, "styles");
  if (input == nullptr) {
    result = TimeSpan();
    return false;
  }
  return TimeSpanParse::TryParseExactMultiple(input, formats, formatProvider, styles, result);
}

Boolean TimeSpan::TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result) {
  ValidateStyles(styles, "styles");
  return TimeSpanParse::TryParseExactMultiple(input, formats, formatProvider, styles, result);
}

String TimeSpan::ToString() {
  return TimeSpanFormat::FormatC(*this);
}

String TimeSpan::ToString(String format) {
  return TimeSpanFormat::Format(*this, format, nullptr);
}

String TimeSpan::ToString(String format, IFormatProvider formatProvider) {
  return TimeSpanFormat::Format(*this, format, formatProvider);
}

Boolean TimeSpan::TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider) {
  return TimeSpanFormat::TryFormat(*this, destination, charsWritten, format, formatProvider);
}

TimeSpan TimeSpan::op_UnaryNegation(TimeSpan t) {
  if (t._ticks == MinValue._ticks) {
    rt::throw_exception<OverflowException>(SR::get_Overflow_NegateTwosCompNum());
  }
  return TimeSpan(-t._ticks);
}

TimeSpan TimeSpan::op_Subtraction(TimeSpan t1, TimeSpan t2) {
  return t1.Subtract(t2);
}

TimeSpan TimeSpan::op_UnaryPlus(TimeSpan t) {
  return t;
}

TimeSpan TimeSpan::op_Addition(TimeSpan t1, TimeSpan t2) {
  return t1.Add(t2);
}

TimeSpan TimeSpan::op_Multiply(TimeSpan timeSpan, Double factor) {
  if (Double::IsNaN(factor)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_CannotBeNaN(), "factor");
  }
  Double ticks = Math::Round((Double)timeSpan.get_Ticks() * factor);
  return IntervalFromDoubleTicks(ticks);
}

TimeSpan TimeSpan::op_Multiply(Double factor, TimeSpan timeSpan) {
  return timeSpan * factor;
}

TimeSpan TimeSpan::op_Division(TimeSpan timeSpan, Double divisor) {
  if (Double::IsNaN(divisor)) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_CannotBeNaN(), "divisor");
  }
  Double ticks = Math::Round((Double)timeSpan.get_Ticks() / divisor);
  return IntervalFromDoubleTicks(ticks);
}

Double TimeSpan::op_Division(TimeSpan t1, TimeSpan t2) {
  return (Double)t1.get_Ticks() / (Double)t2.get_Ticks();
}

Boolean TimeSpan::op_Equality(TimeSpan t1, TimeSpan t2) {
  return t1._ticks == t2._ticks;
}

Boolean TimeSpan::op_Inequality(TimeSpan t1, TimeSpan t2) {
  return t1._ticks != t2._ticks;
}

Boolean TimeSpan::op_LessThan(TimeSpan t1, TimeSpan t2) {
  return t1._ticks < t2._ticks;
}

Boolean TimeSpan::op_LessThanOrEqual(TimeSpan t1, TimeSpan t2) {
  return t1._ticks <= t2._ticks;
}

Boolean TimeSpan::op_GreaterThan(TimeSpan t1, TimeSpan t2) {
  return t1._ticks > t2._ticks;
}

Boolean TimeSpan::op_GreaterThanOrEqual(TimeSpan t1, TimeSpan t2) {
  return t1._ticks >= t2._ticks;
}

void TimeSpan::cctor() {
  Zero = TimeSpan(0);
  MaxValue = TimeSpan(Int64::MaxValue);
  MinValue = TimeSpan(Int64::MinValue);
}

} // namespace System::Private::CoreLib::System::TimeSpanNamespace
