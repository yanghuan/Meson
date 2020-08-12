#pragma once

#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Globalization {
enum class TimeSpanStyles : int32_t;
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Double)
FORWARD_(IComparable, T1, T2)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int32)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
namespace TimeSpanNamespace {
using namespace System::Globalization;
struct TimeSpan : public valueType<TimeSpan> {
  public: using interface = rt::TypeList<IComparable<>, IComparable<TimeSpan>, IEquatable<TimeSpan>, IFormattable, ISpanFormattable>;
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
  public: explicit TimeSpan(Int64 ticks);
  public: explicit TimeSpan(Int32 hours, Int32 minutes, Int32 seconds);
  public: explicit TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds);
  public: explicit TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds);
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
  public: static TimeSpan op_UnaryNegation(TimeSpan t);
  public: static TimeSpan op_Subtraction(TimeSpan t1, TimeSpan t2);
  public: static TimeSpan op_UnaryPlus(TimeSpan t);
  public: static TimeSpan op_Addition(TimeSpan t1, TimeSpan t2);
  public: static TimeSpan op_Multiply(TimeSpan timeSpan, Double factor);
  public: static TimeSpan op_Multiply(Double factor, TimeSpan timeSpan);
  public: static TimeSpan op_Division(TimeSpan timeSpan, Double divisor);
  public: static Double op_Division(TimeSpan t1, TimeSpan t2);
  public: static Boolean op_Equality(TimeSpan t1, TimeSpan t2);
  public: static Boolean op_Inequality(TimeSpan t1, TimeSpan t2);
  public: static Boolean op_LessThan(TimeSpan t1, TimeSpan t2);
  public: static Boolean op_LessThanOrEqual(TimeSpan t1, TimeSpan t2);
  public: static Boolean op_GreaterThan(TimeSpan t1, TimeSpan t2);
  public: static Boolean op_GreaterThanOrEqual(TimeSpan t1, TimeSpan t2);
  private: static void ctor_static();
  public: explicit TimeSpan() {}
  public: static constexpr Int64 TicksPerMillisecond = 10000;
  public: static constexpr Int64 TicksPerSecond = 10000000;
  public: static constexpr Int64 TicksPerMinute = 600000000;
  public: static constexpr Int64 TicksPerHour = 36000000000;
  public: static constexpr Int64 TicksPerDay = 864000000000;
  public: static TimeSpan Zero;
  public: static TimeSpan MaxValue;
  public: static TimeSpan MinValue;
  public: Int64 _ticks;
};
} // namespace TimeSpanNamespace
using TimeSpan = TimeSpanNamespace::TimeSpan;
} // namespace System::Private::CoreLib::System
