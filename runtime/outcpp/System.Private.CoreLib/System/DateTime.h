#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Globalization/DateTimeStyles.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
FORWARD(Calendar)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
enum class DateTimeKind : int32_t;
enum class DayOfWeek : int32_t;
enum class TypeCode : int32_t;
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Double)
FORWARD_(IComparable, T1, T2)
FORWARD(IConvertible)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int32)
FORWARD(ISpanFormattable)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(TimeSpan)
namespace DateTimeNamespace {
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
struct DateTime : public valueType<DateTime> {
  public: using interface = rt::TypeList<IComparable<>, IFormattable, IConvertible, IComparable<DateTime>, IEquatable<DateTime>, ISerializable, ISpanFormattable>;
  private: struct FullSystemTime : public valueType<FullSystemTime> {
    public: explicit FullSystemTime(Int32 year, Int32 month, DayOfWeek dayOfWeek, Int32 day, Int32 hour, Int32 minute, Int32 second);
    public: explicit FullSystemTime(Int64 ticks);
    public: explicit FullSystemTime() {}
    public: Interop::Kernel32::SYSTEMTIME systemTime;
    public: Int64 hundredNanoSecond;
  };
  public: Int64 get_InternalTicks();
  private: UInt64 get_InternalKind();
  public: DateTime get_Date();
  public: Int32 get_Day();
  public: DayOfWeek get_DayOfWeek();
  public: Int32 get_DayOfYear();
  public: Int32 get_Hour();
  public: DateTimeKind get_Kind();
  public: Int32 get_Millisecond();
  public: Int32 get_Minute();
  public: Int32 get_Month();
  public: static DateTime get_Now();
  public: Int32 get_Second();
  public: Int64 get_Ticks();
  public: TimeSpan get_TimeOfDay();
  public: static DateTime get_Today();
  public: Int32 get_Year();
  public: static DateTime get_UtcNow();
  private: static Boolean ValidateSystemTime(Interop::Kernel32::SYSTEMTIME* time, Boolean localTime);
  private: static Boolean FileTimeToSystemTime(Int64 fileTime, FullSystemTime* time);
  private: static void GetSystemTimeWithLeapSecondsHandling(FullSystemTime* time);
  private: static Boolean SystemTimeToFileTime(Interop::Kernel32::SYSTEMTIME* time, Int64* fileTime);
  private: static Int64 GetSystemTimeAsFileTime();
  public: explicit DateTime(Int64 ticks);
  private: explicit DateTime(UInt64 dateData);
  public: explicit DateTime(Int64 ticks, DateTimeKind kind);
  public: explicit DateTime(Int64 ticks, DateTimeKind kind, Boolean isAmbiguousDst);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Calendar calendar);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateTimeKind kind);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Calendar calendar);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, DateTimeKind kind);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Calendar calendar);
  public: explicit DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, Calendar calendar, DateTimeKind kind);
  private: explicit DateTime(SerializationInfo info, StreamingContext context);
  public: DateTime Add(TimeSpan value);
  private: DateTime Add(Double value, Int32 scale);
  public: DateTime AddDays(Double value);
  public: DateTime AddHours(Double value);
  public: DateTime AddMilliseconds(Double value);
  public: DateTime AddMinutes(Double value);
  public: DateTime AddMonths(Int32 months);
  public: DateTime AddSeconds(Double value);
  public: DateTime AddTicks(Int64 value);
  public: Boolean TryAddTicks(Int64 value, DateTime& result);
  public: DateTime AddYears(Int32 value);
  public: static Int32 Compare(DateTime t1, DateTime t2);
  public: Int32 CompareTo(Object value);
  public: Int32 CompareTo(DateTime value);
  private: static Int64 DateToTicks(Int32 year, Int32 month, Int32 day);
  private: static Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second);
  public: static Int32 DaysInMonth(Int32 year, Int32 month);
  public: static Int64 DoubleDateToTicks(Double value);
  public: Boolean Equals(Object value);
  public: Boolean Equals(DateTime value);
  public: static Boolean Equals(DateTime t1, DateTime t2);
  public: static DateTime FromBinary(Int64 dateData);
  public: static DateTime FromBinaryRaw(Int64 dateData);
  public: static DateTime FromFileTime(Int64 fileTime);
  public: static DateTime FromFileTimeUtc(Int64 fileTime);
  public: static DateTime FromOADate(Double d);
  public: Boolean IsDaylightSavingTime();
  public: static DateTime SpecifyKind(DateTime value, DateTimeKind kind);
  public: Int64 ToBinary();
  private: Int32 GetDatePart(Int32 part);
  public: void GetDate(Int32& year, Int32& month, Int32& day);
  public: void GetTime(Int32& hour, Int32& minute, Int32& second);
  public: void GetTime(Int32& hour, Int32& minute, Int32& second, Int32& millisecond);
  public: void GetTimePrecise(Int32& hour, Int32& minute, Int32& second, Int32& tick);
  public: Int32 GetHashCode();
  public: Boolean IsAmbiguousDaylightSavingTime();
  public: static Boolean IsLeapYear(Int32 year);
  public: static DateTime Parse(String s);
  public: static DateTime Parse(String s, IFormatProvider provider);
  public: static DateTime Parse(String s, IFormatProvider provider, DateTimeStyles styles);
  public: static DateTime Parse(ReadOnlySpan<Char> s, IFormatProvider provider = nullptr, DateTimeStyles styles = DateTimeStyles::None);
  public: static DateTime ParseExact(String s, String format, IFormatProvider provider);
  public: static DateTime ParseExact(String s, String format, IFormatProvider provider, DateTimeStyles style);
  public: static DateTime ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, IFormatProvider provider, DateTimeStyles style = DateTimeStyles::None);
  public: static DateTime ParseExact(String s, Array<String> formats, IFormatProvider provider, DateTimeStyles style);
  public: static DateTime ParseExact(ReadOnlySpan<Char> s, Array<String> formats, IFormatProvider provider, DateTimeStyles style = DateTimeStyles::None);
  public: TimeSpan Subtract(DateTime value);
  public: DateTime Subtract(TimeSpan value);
  private: static Double TicksToOADate(Int64 value);
  public: Double ToOADate();
  public: Int64 ToFileTime();
  public: Int64 ToFileTimeUtc();
  public: DateTime ToLocalTime();
  public: DateTime ToLocalTime(Boolean throwOnOverflow);
  public: String ToLongDateString();
  public: String ToLongTimeString();
  public: String ToShortDateString();
  public: String ToShortTimeString();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(IFormatProvider provider);
  public: String ToString(String format, IFormatProvider provider);
  public: Boolean TryFormat(Span<Char> destination, Int32& charsWritten, ReadOnlySpan<Char> format = rt::default, IFormatProvider provider = nullptr);
  public: DateTime ToUniversalTime();
  public: static Boolean TryParse(String s, DateTime& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, DateTime& result);
  public: static Boolean TryParse(String s, IFormatProvider provider, DateTimeStyles styles, DateTime& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, IFormatProvider provider, DateTimeStyles styles, DateTime& result);
  public: static Boolean TryParseExact(String s, String format, IFormatProvider provider, DateTimeStyles style, DateTime& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, IFormatProvider provider, DateTimeStyles style, DateTime& result);
  public: static Boolean TryParseExact(String s, Array<String> formats, IFormatProvider provider, DateTimeStyles style, DateTime& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> s, Array<String> formats, IFormatProvider provider, DateTimeStyles style, DateTime& result);
  public: static DateTime op_Addition(DateTime d, TimeSpan t);
  public: static DateTime op_Subtraction(DateTime d, TimeSpan t);
  public: static TimeSpan op_Subtraction(DateTime d1, DateTime d2);
  public: static Boolean op_Equality(DateTime d1, DateTime d2);
  public: static Boolean op_Inequality(DateTime d1, DateTime d2);
  public: static Boolean op_LessThan(DateTime t1, DateTime t2);
  public: static Boolean op_LessThanOrEqual(DateTime t1, DateTime t2);
  public: static Boolean op_GreaterThan(DateTime t1, DateTime t2);
  public: static Boolean op_GreaterThanOrEqual(DateTime t1, DateTime t2);
  public: Array<String> GetDateTimeFormats();
  public: Array<String> GetDateTimeFormats(IFormatProvider provider);
  public: Array<String> GetDateTimeFormats(Char format);
  public: Array<String> GetDateTimeFormats(Char format, IFormatProvider provider);
  public: TypeCode GetTypeCode();
  public: static Boolean TryCreate(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond, DateTime& result);
  private: static Boolean SystemSupportsLeapSeconds();
  public: static Boolean IsValidTimeWithLeapSeconds(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateTimeKind kind);
  private: static DateTime FromFileTimeLeapSecondsAware(Int64 fileTime);
  private: static Int64 ToFileTimeLeapSecondsAware(Int64 ticks);
  private: static DateTime CreateDateTimeFromSystemTime(FullSystemTime& time);
  private: static void cctor();
  public: explicit DateTime() {}
  private: static Array<Int32> s_daysToMonth365;
  private: static Array<Int32> s_daysToMonth366;
  public: static DateTime MinValue;
  public: static DateTime MaxValue;
  public: static DateTime UnixEpoch;
  private: UInt64 _dateData;
  public: static Boolean s_systemSupportsLeapSeconds;
};
} // namespace DateTimeNamespace
using DateTime = DateTimeNamespace::DateTime;
} // namespace System::Private::CoreLib::System
