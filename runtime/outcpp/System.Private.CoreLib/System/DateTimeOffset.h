#pragma once

#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeStyles.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
FORWARD(Calendar)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class DayOfWeek : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Double)
FORWARD_(IComparable, T1, T2)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(TimeSpan)
namespace DateTimeOffsetNamespace {
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
struct DateTimeOffset : public valueType<DateTimeOffset> {
  public: using interface = rt::TypeList<IComparable<>, IFormattable, IComparable<DateTimeOffset>, IEquatable<DateTimeOffset>, ISerializable, IDeserializationCallback, ISpanFormattable>;
  public: static DateTimeOffset get_Now();
  public: static DateTimeOffset get_UtcNow();
  public: DateTime get_DateTime();
  public: DateTime get_UtcDateTime();
  public: DateTime get_LocalDateTime();
  private: DateTime get_ClockDateTime();
  public: DateTime get_Date();
  public: Int32 get_Day();
  public: DayOfWeek get_DayOfWeek();
  public: Int32 get_DayOfYear();
  public: Int32 get_Hour();
  public: Int32 get_Millisecond();
  public: Int32 get_Minute();
  public: Int32 get_Month();
  public: TimeSpan get_Offset();
  public: Int32 get_Second();
  public: Int64 get_Ticks();
  public: Int64 get_UtcTicks();
  public: TimeSpan get_TimeOfDay();
  public: Int32 get_Year();
  public: explicit DateTimeOffset(Int64 ticks, TimeSpan offset);
  public: explicit DateTimeOffset(DateTime dateTime);
  public: explicit DateTimeOffset(DateTime dateTime, TimeSpan offset);
  public: explicit DateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, TimeSpan offset);
  public: explicit DateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, TimeSpan offset);
  public: explicit DateTimeOffset(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Calendar calendar, TimeSpan offset);
  public: DateTimeOffset ToOffset(TimeSpan offset);
  public: DateTimeOffset Add(TimeSpan timeSpan);
  public: DateTimeOffset AddDays(Double days);
  public: DateTimeOffset AddHours(Double hours);
  public: DateTimeOffset AddMilliseconds(Double milliseconds);
  public: DateTimeOffset AddMinutes(Double minutes);
  public: DateTimeOffset AddMonths(Int32 months);
  public: DateTimeOffset AddSeconds(Double seconds);
  public: DateTimeOffset AddTicks(Int64 ticks);
  public: DateTimeOffset AddYears(Int32 years);
  public: static Int32 Compare(DateTimeOffset first, DateTimeOffset second);
  public: Int32 CompareTo(DateTimeOffset other);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(DateTimeOffset other);
  public: Boolean EqualsExact(DateTimeOffset other);
  public: static Boolean Equals(DateTimeOffset first, DateTimeOffset second);
  public: static DateTimeOffset FromFileTime(Int64 fileTime);
  public: static DateTimeOffset FromUnixTimeSeconds(Int64 seconds);
  public: static DateTimeOffset FromUnixTimeMilliseconds(Int64 milliseconds);
  private: explicit DateTimeOffset(SerializationInfo info, StreamingContext context);
  public: Int32 GetHashCode();
  public: static DateTimeOffset Parse(String input);
  public: static DateTimeOffset Parse(String input, IFormatProvider formatProvider);
  public: static DateTimeOffset Parse(String input, IFormatProvider formatProvider, DateTimeStyles styles);
  public: static DateTimeOffset Parse(ReadOnlySpan<Char> input, IFormatProvider formatProvider = nullptr, DateTimeStyles styles = DateTimeStyles::None);
  public: static DateTimeOffset ParseExact(String input, String format, IFormatProvider formatProvider);
  public: static DateTimeOffset ParseExact(String input, String format, IFormatProvider formatProvider, DateTimeStyles styles);
  public: static DateTimeOffset ParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, DateTimeStyles styles = DateTimeStyles::None);
  public: static DateTimeOffset ParseExact(String input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles);
  public: static DateTimeOffset ParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles = DateTimeStyles::None);
  public: TimeSpan Subtract(DateTimeOffset value);
  public: DateTimeOffset Subtract(TimeSpan value);
  public: Int64 ToFileTime();
  public: Int64 ToUnixTimeSeconds();
  public: Int64 ToUnixTimeMilliseconds();
  public: DateTimeOffset ToLocalTime();
  public: DateTimeOffset ToLocalTime(Boolean throwOnOverflow);
  private: static DateTimeOffset ToLocalTime(DateTime utcDateTime, Boolean throwOnOverflow);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider formatProvider);
  public: String ToString(String format, IFormatProvider formatProvider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = rt::default, IFormatProvider formatProvider = nullptr);
  public: DateTimeOffset ToUniversalTime();
  public: static Boolean TryParse(String input, DateTimeOffset& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> input, DateTimeOffset& result);
  public: static Boolean TryParse(String input, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> input, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result);
  public: static Boolean TryParseExact(String input, String format, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, ReadOnlySpan<Char> format, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result);
  public: static Boolean TryParseExact(String input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> input, Array<String> formats, IFormatProvider formatProvider, DateTimeStyles styles, DateTimeOffset& result);
  private: static Int16 ValidateOffset(TimeSpan offset);
  private: static DateTime ValidateDate(DateTime dateTime, TimeSpan offset);
  private: static DateTimeStyles ValidateStyles(DateTimeStyles style, String parameterName);
  public: static DateTimeOffset op_Implicit(DateTime dateTime);
  public: static DateTimeOffset op_Addition(DateTimeOffset dateTimeOffset, TimeSpan timeSpan);
  public: static DateTimeOffset op_Subtraction(DateTimeOffset dateTimeOffset, TimeSpan timeSpan);
  public: static TimeSpan op_Subtraction(DateTimeOffset left, DateTimeOffset right);
  public: static Boolean op_Equality(DateTimeOffset left, DateTimeOffset right);
  public: static Boolean op_Inequality(DateTimeOffset left, DateTimeOffset right);
  public: static Boolean op_LessThan(DateTimeOffset left, DateTimeOffset right);
  public: static Boolean op_LessThanOrEqual(DateTimeOffset left, DateTimeOffset right);
  public: static Boolean op_GreaterThan(DateTimeOffset left, DateTimeOffset right);
  public: static Boolean op_GreaterThanOrEqual(DateTimeOffset left, DateTimeOffset right);
  private: static void cctor();
  public: explicit DateTimeOffset() {}
  public: static DateTimeOffset MinValue;
  public: static DateTimeOffset MaxValue;
  public: static DateTimeOffset UnixEpoch;
  private: DateTime _dateTime;
  private: Int16 _offsetMinutes;
};
} // namespace DateTimeOffsetNamespace
using DateTimeOffset = DateTimeOffsetNamespace::DateTimeOffset;
} // namespace System::Private::CoreLib::System
