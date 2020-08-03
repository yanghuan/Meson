#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>

namespace System::Private::CoreLib::System::Globalization {
enum class DateTimeStyles;
FORWARD(Calendar)
FORWARD(DateTimeFormatInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARDS(__DTString)
FORWARD_(Array, T1, T2)
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(DateTime)
FORWARDS(DateTimeRawInfo)
FORWARDS(DateTimeResult)
FORWARDS(DateTimeToken)
FORWARDS(Double)
FORWARD(Exception)
FORWARD(IAsyncResult)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(ParsingInfo)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARDS(TimeSpan)
namespace DateTimeParseNamespace {
using namespace Globalization;
using namespace Text;
class DateTimeParse {
  public: enum class DTT {
    End = 0,
    NumEnd = 1,
    NumAmpm = 2,
    NumSpace = 3,
    NumDatesep = 4,
    NumTimesep = 5,
    MonthEnd = 6,
    MonthSpace = 7,
    MonthDatesep = 8,
    NumDatesuff = 9,
    NumTimesuff = 10,
    DayOfWeek = 11,
    YearSpace = 12,
    YearDateSep = 13,
    YearEnd = 14,
    TimeZone = 15,
    Era = 16,
    NumUTCTimeMark = 17,
    Unk = 18,
    NumLocalTimeMark = 19,
    Max = 20,
  };
  public: enum class TM {
    NotSet = -1,
    AM = 0,
    PM = 1,
  };
  public: enum class DS {
    BEGIN = 0,
    N = 1,
    NN = 2,
    D_Nd = 3,
    D_NN = 4,
    D_NNd = 5,
    D_M = 6,
    D_MN = 7,
    D_NM = 8,
    D_MNd = 9,
    D_NDS = 10,
    D_Y = 11,
    D_YN = 12,
    D_YNd = 13,
    D_YM = 14,
    D_YMd = 15,
    D_S = 16,
    T_S = 17,
    T_Nt = 18,
    T_NNt = 19,
    ERROR = 20,
    DX_NN = 21,
    DX_NNN = 22,
    DX_MN = 23,
    DX_NM = 24,
    DX_MNN = 25,
    DX_DS = 26,
    DX_DSN = 27,
    DX_NDS = 28,
    DX_NNDS = 29,
    DX_YNN = 30,
    DX_YMN = 31,
    DX_YN = 32,
    DX_YM = 33,
    TX_N = 34,
    TX_NN = 35,
    TX_NNN = 36,
    TX_TS = 37,
    DX_NNY = 38,
  };
  public: CLASS(MatchNumberDelegate) : public MulticastDelegate::in {
    public: void Ctor(Object object, IntPtr method);
    public: Boolean Invoke(__DTString& str, Int32 digitLen, Int32& result);
    public: IAsyncResult BeginInvoke(__DTString& str, Int32 digitLen, Int32& result, AsyncCallback callback, Object object);
    public: Boolean EndInvoke(__DTString& str, Int32& result, IAsyncResult __result);
  };
  public: static DateTime ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style);
  public: static DateTime ParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, TimeSpan& offset);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result, TimeSpan& offset);
  public: static Boolean TryParseExact(ReadOnlySpan<Char> s, ReadOnlySpan<Char> format, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTimeResult& result);
  public: static DateTime ParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style);
  public: static DateTime ParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, TimeSpan& offset);
  public: static Boolean TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result, TimeSpan& offset);
  public: static Boolean TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTime& result);
  public: static Boolean TryParseExactMultiple(ReadOnlySpan<Char> s, Array<String> formats, DateTimeFormatInfo dtfi, DateTimeStyles style, DateTimeResult& result);
  private: static Boolean MatchWord(__DTString& str, String target);
  private: static Boolean GetTimeZoneName(__DTString& str);
  public: static Boolean IsDigit(Char ch);
  private: static Boolean ParseFraction(__DTString& str, Double& result);
  private: static Boolean ParseTimeZone(__DTString& str, TimeSpan& result);
  private: static Boolean HandleTimeZone(__DTString& str, DateTimeResult& result);
  private: static Boolean Lex(DS dps, __DTString& str, DateTimeToken& dtok, DateTimeRawInfo& raw, DateTimeResult& result, DateTimeFormatInfo& dtfi, DateTimeStyles styles);
  private: static Boolean VerifyValidPunctuation(__DTString& str);
  private: static Boolean GetYearMonthDayOrder(String datePattern, Int32& order);
  private: static Boolean GetYearMonthOrder(String pattern, Int32& order);
  private: static Boolean GetMonthDayOrder(String pattern, Int32& order);
  private: static Boolean TryAdjustYear(DateTimeResult& result, Int32 year, Int32& adjustedYear);
  private: static Boolean SetDateYMD(DateTimeResult& result, Int32 year, Int32 month, Int32 day);
  private: static Boolean SetDateMDY(DateTimeResult& result, Int32 month, Int32 day, Int32 year);
  private: static Boolean SetDateDMY(DateTimeResult& result, Int32 day, Int32 month, Int32 year);
  private: static Boolean SetDateYDM(DateTimeResult& result, Int32 year, Int32 day, Int32 month);
  private: static void GetDefaultYear(DateTimeResult& result, DateTimeStyles& styles);
  private: static Boolean GetDayOfNN(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfNNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfMN(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetHebrewDayOfNM(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfNM(DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfMNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfYNN(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfNNY(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean GetDayOfYMN(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetDayOfYN(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetDayOfYM(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static void AdjustTimeMark(DateTimeFormatInfo dtfi, DateTimeRawInfo& raw);
  private: static Boolean AdjustHour(Int32& hour, TM timeMark);
  private: static Boolean GetTimeOfN(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetTimeOfNN(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetTimeOfNNN(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetDateOfDSN(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetDateOfNDS(DateTimeResult& result, DateTimeRawInfo& raw);
  private: static Boolean GetDateOfNNDS(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  private: static Boolean ProcessDateTimeSuffix(DateTimeResult& result, DateTimeRawInfo& raw, DateTimeToken& dtok);
  public: static Boolean ProcessHebrewTerminalState(DS dps, DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  public: static Boolean ProcessTerminalState(DS dps, DateTimeResult& result, DateTimeStyles& styles, DateTimeRawInfo& raw, DateTimeFormatInfo dtfi);
  public: static DateTime Parse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles);
  public: static DateTime Parse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, TimeSpan& offset);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTime& result);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTime& result, TimeSpan& offset);
  public: static Boolean TryParse(ReadOnlySpan<Char> s, DateTimeFormatInfo dtfi, DateTimeStyles styles, DateTimeResult& result);
  private: static Boolean DetermineTimeZoneAdjustments(DateTimeResult& result, DateTimeStyles styles, Boolean bTimeOnly);
  private: static Boolean DateTimeOffsetTimeZonePostProcessing(DateTimeResult& result, DateTimeStyles styles);
  private: static Boolean AdjustTimeZoneToUniversal(DateTimeResult& result);
  private: static Boolean AdjustTimeZoneToLocal(DateTimeResult& result, Boolean bTimeOnly);
  private: static Boolean ParseISO8601(DateTimeRawInfo& raw, __DTString& str, DateTimeStyles styles, DateTimeResult& result);
  public: static Boolean MatchHebrewDigits(__DTString& str, Int32 digitLen, Int32& number);
  public: static Boolean ParseDigits(__DTString& str, Int32 digitLen, Int32& result);
  public: static Boolean ParseDigits(__DTString& str, Int32 minDigitLen, Int32 maxDigitLen, Int32& result);
  private: static Boolean ParseFractionExact(__DTString& str, Int32 maxDigitLen, Double& result);
  private: static Boolean ParseSign(__DTString& str, Boolean& result);
  private: static Boolean ParseTimeZoneOffset(__DTString& str, Int32 len, TimeSpan& result);
  private: static Boolean MatchAbbreviatedMonthName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result);
  private: static Boolean MatchMonthName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result);
  private: static Boolean MatchAbbreviatedDayName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result);
  private: static Boolean MatchDayName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result);
  private: static Boolean MatchEraName(__DTString& str, DateTimeFormatInfo dtfi, Int32& result);
  private: static Boolean MatchTimeMark(__DTString& str, DateTimeFormatInfo dtfi, TM& result);
  private: static Boolean MatchAbbreviatedTimeMark(__DTString& str, DateTimeFormatInfo dtfi, TM& result);
  private: static Boolean CheckNewValue(Int32& currentValue, Int32 newValue, Char patternChar, DateTimeResult& result);
  private: static DateTime GetDateTimeNow(DateTimeResult& result, DateTimeStyles& styles);
  private: static Boolean CheckDefaultDateTime(DateTimeResult& result, Calendar& cal, DateTimeStyles styles);
  private: static String ExpandPredefinedFormat(ReadOnlySpan<Char> format, DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo, DateTimeResult& result);
  private: static Boolean ParseJapaneseEraStart(__DTString& str, DateTimeFormatInfo dtfi);
  private: static void ConfigureFormatR(DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo, DateTimeResult& result);
  private: static void ConfigureFormatOS(DateTimeFormatInfo& dtfi, ParsingInfo& parseInfo);
  private: static Boolean ParseByFormat(__DTString& str, __DTString& format, ParsingInfo& parseInfo, DateTimeFormatInfo dtfi, DateTimeResult& result);
  public: static Boolean TryParseQuoteString(ReadOnlySpan<Char> format, Int32 pos, StringBuilder result, Int32& returnValue);
  private: static Boolean DoStrictParse(ReadOnlySpan<Char> s, ReadOnlySpan<Char> formatParam, DateTimeStyles styles, DateTimeFormatInfo dtfi, DateTimeResult& result);
  private: static Boolean ParseFormatR(ReadOnlySpan<Char> source, ParsingInfo& parseInfo, DateTimeResult& result);
  private: static Boolean ParseFormatO(ReadOnlySpan<Char> source, DateTimeResult& result);
  private: static Exception GetDateTimeParseException(DateTimeResult& result);
  private: static void SCtor();
  private: static MatchNumberDelegate s_hebrewNumberParser;
  private: static Array<Array<DS>> s_dateParsingStates;
};
} // namespace DateTimeParseNamespace
using DateTimeParse = DateTimeParseNamespace::DateTimeParse;
} // namespace System::Private::CoreLib::System
