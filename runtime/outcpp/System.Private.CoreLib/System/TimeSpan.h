#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System::Globalization {
enum class TimeSpanStyles;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Double)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD(String)
FORWARD(IFormatProvider)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Char)
FORWARD_(Array, T1, T2)
FORWARDS(Span, T)
namespace TimeSpanNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
struct TimeSpan {
  public: Int64 get_Ticks();
  public: Int32 get_Days();
  public: Int32 get_Hours();
  public: Int32 get_Milliseconds();
  public: Int32 get_Minutes();
  public: Int32 get_Seconds();
  public: Double get_TotalDays();
  public: Double get_TotalHours();
  public: Double get_TotalMilliseconds();
  public: Double get_TotalMinutes();
  public: Double get_TotalSeconds();
  public: TimeSpan Add(TimeSpan ts);
  public: static Int32 Compare(TimeSpan t1, TimeSpan t2);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(TimeSpan value);
  public: static TimeSpan FromDays(Double value);
  public: TimeSpan Duration();
  public: Boolean Equals(Object value);
  public: Boolean Equals(TimeSpan obj);
  public: static Boolean Equals(TimeSpan t1, TimeSpan t2);
  public: Int32 GetHashCode();
  public: static TimeSpan FromHours(Double value);
  private: static TimeSpan Interval(Double value, Double scale);
  private: static TimeSpan IntervalFromDoubleTicks(Double ticks);
  public: static TimeSpan FromMilliseconds(Double value);
  public: static TimeSpan FromMinutes(Double value);
  public: TimeSpan Negate();
  public: static TimeSpan FromSeconds(Double value);
  public: TimeSpan Subtract(TimeSpan ts);
  public: TimeSpan Multiply(Double factor);
  public: TimeSpan Divide(Double divisor);
  public: Double Divide(TimeSpan ts);
  public: static TimeSpan FromTicks(Int64 value);
  public: static Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second);
  private: static void ValidateStyles(TimeSpanStyles style, String parameterName);
  public: static TimeSpan Parse(String s);
  public: static TimeSpan Parse(String input, IFormatProvider formatProvider);
  public: static TimeSpan Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider);
  public: static TimeSpan ParseExact(String input, String format, IFormatProvider formatProvider);
  public: static TimeSpan ParseExact(String input, Array<String> formats, IFormatProvider formatProvider);
  public: static TimeSpan ParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles);
  public: static TimeSpan ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles);
  public: static TimeSpan ParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles);
  public: static TimeSpan ParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles);
  public: static Boolean TryParse(String s, TimeSpan& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, TimeSpan& result);
  public: static Boolean TryParse(String input, IFormatProvider formatProvider, TimeSpan& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, TimeSpan& result);
  public: static Boolean TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpan& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpan& result);
  public: static Boolean TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpan& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpan& result);
  public: static Boolean TryParseExact(String input, String format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result);
  public: static Boolean TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, TimeSpanStyles styles, TimeSpan& result);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider formatProvider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format, IFormatProvider formatProvider);
  public: static Int64 TicksPerMillisecond;
  public: static Int64 TicksPerSecond;
  public: static Int64 TicksPerMinute;
  public: static Int64 TicksPerHour;
  public: static Int64 TicksPerDay;
  public: static TimeSpan Zero;
  public: static TimeSpan MaxValue;
  public: static TimeSpan MinValue;
  public: Int64 _ticks;
};
} // namespace TimeSpanNamespace
using TimeSpan = TimeSpanNamespace::TimeSpan;
} // namespace System::Private::CoreLib::System
