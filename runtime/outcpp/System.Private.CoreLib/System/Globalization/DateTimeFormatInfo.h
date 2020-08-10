#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
enum class DayOfWeek;
enum class TokenType;
FORWARDS(__DTString)
FORWARD_(Array, T1, T2)
FORWARDS(Char)
FORWARD(ICloneable)
FORWARD(IFormatProvider)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarId : uint16_t;
enum class CalendarWeekRule;
enum class DateTimeFormatFlags;
enum class DateTimeStyles;
enum class MonthNameStyles;
FORWARD(Calendar)
FORWARD(CompareInfo)
FORWARD(CultureData)
FORWARD(CultureInfo)
namespace DateTimeFormatInfoNamespace {
CLASS(DateTimeFormatInfo) : public Object::in {
  public: using interface = rt::TypeList<IFormatProvider, ICloneable>;
  public: CLASS(TokenHashValue) : public Object::in {
    public: void ctor(String tokenString, TokenType tokenType, Int32 tokenValue);
    public: String tokenString;
    public: TokenType tokenType;
    public: Int32 tokenValue;
  };
  private: String get_CultureName();
  private: CultureInfo get_Culture();
  private: String get_LanguageName();
  public: static DateTimeFormatInfo get_InvariantInfo();
  public: static DateTimeFormatInfo get_CurrentInfo();
  public: String get_AMDesignator();
  public: void set_AMDesignator(String value);
  public: Calendar get_Calendar();
  public: void set_Calendar(Calendar value);
  private: Array<CalendarId> get_OptionalCalendars();
  public: Array<String> get_EraNames();
  public: Array<String> get_AbbreviatedEraNames();
  public: Array<String> get_AbbreviatedEnglishEraNames();
  public: String get_DateSeparator();
  public: void set_DateSeparator(String value);
  public: DayOfWeek get_FirstDayOfWeek();
  public: void set_FirstDayOfWeek(DayOfWeek value);
  public: CalendarWeekRule get_CalendarWeekRule();
  public: void set_CalendarWeekRule(CalendarWeekRule value);
  public: String get_FullDateTimePattern();
  public: void set_FullDateTimePattern(String value);
  public: String get_LongDatePattern();
  public: void set_LongDatePattern(String value);
  public: String get_LongTimePattern();
  public: void set_LongTimePattern(String value);
  public: String get_MonthDayPattern();
  public: void set_MonthDayPattern(String value);
  public: String get_PMDesignator();
  public: void set_PMDesignator(String value);
  public: String get_RFC1123Pattern();
  public: String get_ShortDatePattern();
  public: void set_ShortDatePattern(String value);
  public: String get_ShortTimePattern();
  public: void set_ShortTimePattern(String value);
  public: String get_SortableDateTimePattern();
  public: String get_GeneralShortTimePattern();
  public: String get_GeneralLongTimePattern();
  public: String get_DateTimeOffsetPattern();
  public: String get_TimeSeparator();
  public: void set_TimeSeparator(String value);
  public: String get_UniversalSortableDateTimePattern();
  public: String get_YearMonthPattern();
  public: void set_YearMonthPattern(String value);
  public: Array<String> get_AbbreviatedDayNames();
  public: void set_AbbreviatedDayNames(Array<String> value);
  public: Array<String> get_ShortestDayNames();
  public: void set_ShortestDayNames(Array<String> value);
  public: Array<String> get_DayNames();
  public: void set_DayNames(Array<String> value);
  public: Array<String> get_AbbreviatedMonthNames();
  public: void set_AbbreviatedMonthNames(Array<String> value);
  public: Array<String> get_MonthNames();
  public: void set_MonthNames(Array<String> value);
  public: Boolean get_HasSpacesInMonthNames();
  public: Boolean get_HasSpacesInDayNames();
  private: Array<String> get_AllYearMonthPatterns();
  private: Array<String> get_AllShortDatePatterns();
  private: Array<String> get_AllShortTimePatterns();
  private: Array<String> get_AllLongDatePatterns();
  private: Array<String> get_AllLongTimePatterns();
  private: Array<String> get_UnclonedYearMonthPatterns();
  private: Array<String> get_UnclonedShortDatePatterns();
  private: Array<String> get_UnclonedLongDatePatterns();
  private: Array<String> get_UnclonedShortTimePatterns();
  private: Array<String> get_UnclonedLongTimePatterns();
  public: Boolean get_IsReadOnly();
  public: String get_NativeCalendarName();
  public: Array<String> get_AbbreviatedMonthGenitiveNames();
  public: void set_AbbreviatedMonthGenitiveNames(Array<String> value);
  public: Array<String> get_MonthGenitiveNames();
  public: void set_MonthGenitiveNames(Array<String> value);
  public: String get_DecimalSeparator();
  public: String get_FullTimeSpanPositivePattern();
  public: String get_FullTimeSpanNegativePattern();
  public: CompareInfo get_CompareInfo();
  public: DateTimeFormatFlags get_FormatFlags();
  public: Boolean get_HasForceTwoDigitYears();
  public: Boolean get_HasYearMonthAdjustment();
  private: Array<String> InternalGetAbbreviatedDayOfWeekNames();
  private: Array<String> InternalGetAbbreviatedDayOfWeekNamesCore();
  private: Array<String> InternalGetSuperShortDayNames();
  private: Array<String> InternalGetSuperShortDayNamesCore();
  private: Array<String> InternalGetDayOfWeekNames();
  private: Array<String> InternalGetDayOfWeekNamesCore();
  private: Array<String> InternalGetAbbreviatedMonthNames();
  private: Array<String> InternalGetAbbreviatedMonthNamesCore();
  private: Array<String> InternalGetMonthNames();
  private: Array<String> internalGetMonthNamesCore();
  public: void ctor();
  public: void ctor(CultureData cultureData, Calendar cal);
  private: void InitializeOverridableProperties(CultureData cultureData, CalendarId calendarId);
  public: static DateTimeFormatInfo GetInstance(IFormatProvider provider);
  public: Object GetFormat(Type formatType);
  public: Object Clone();
  public: Int32 GetEra(String eraName);
  public: String GetEraName(Int32 era);
  public: String GetAbbreviatedEraName(Int32 era);
  private: void OnLongDatePatternChanged();
  private: void OnLongTimePatternChanged();
  private: void OnShortDatePatternChanged();
  private: void OnShortTimePatternChanged();
  private: void OnYearMonthPatternChanged();
  private: static void CheckNullValue(Array<String> values, Int32 length);
  public: String InternalGetMonthName(Int32 month, MonthNameStyles style, Boolean abbreviated);
  private: Array<String> InternalGetGenitiveMonthNames(Boolean abbreviated);
  public: Array<String> InternalGetLeapYearMonthNames();
  public: String GetAbbreviatedDayName(DayOfWeek dayofweek);
  public: String GetShortestDayName(DayOfWeek dayOfWeek);
  private: static Array<String> GetCombinedPatterns(Array<String> patterns1, Array<String> patterns2, String connectString);
  public: Array<String> GetAllDateTimePatterns();
  public: Array<String> GetAllDateTimePatterns(Char format);
  public: String GetDayName(DayOfWeek dayofweek);
  public: String GetAbbreviatedMonthName(Int32 month);
  public: String GetMonthName(Int32 month);
  private: static Array<String> GetMergedPatterns(Array<String> patterns, String defaultPattern);
  public: static DateTimeFormatInfo ReadOnly(DateTimeFormatInfo dtfi);
  public: void SetAllDateTimePatterns(Array<String> patterns, Char format);
  public: static void ValidateStyles(DateTimeStyles style, String parameterName);
  private: DateTimeFormatFlags InitializeFormatFlags();
  public: Boolean YearMonthAdjustment(Int32& year, Int32& month, Boolean parsedMonthName);
  public: static DateTimeFormatInfo GetJapaneseCalendarDTFI();
  public: static DateTimeFormatInfo GetTaiwanCalendarDTFI();
  private: void ClearTokenHashTable();
  public: Array<TokenHashValue> CreateTokenHashTable();
  private: void AddMonthNames(Array<TokenHashValue> temp, ReadOnlySpan<Char> monthPostfix);
  private: static Boolean TryParseHebrewNumber(__DTString& str, Boolean& badFormat, Int32& number);
  private: static Boolean IsHebrewChar(Char ch);
  private: Boolean IsAllowedJapaneseTokenFollowedByNonSpaceLetter(String tokenString, Char nextCh);
  public: Boolean Tokenize(TokenType TokenMask, TokenType& tokenType, Int32& tokenValue, __DTString& str);
  private: void InsertAtCurrentHashNode(Array<TokenHashValue> hashTable, String str, Char ch, TokenType tokenType, Int32 tokenValue, Int32 pos, Int32 hashcode, Int32 hashProbe);
  private: void InsertHash(Array<TokenHashValue> hashTable, String str, TokenType tokenType, Int32 tokenValue);
  private: Boolean CompareStringIgnoreCaseOptimized(String string1, Int32 offset1, Int32 length1, String string2, Int32 offset2, Int32 length2);
  private: static DateTimeFormatInfo s_invariantInfo;
  private: CultureData _cultureData;
  private: String _name;
  private: String _langName;
  private: CompareInfo _compareInfo;
  private: CultureInfo _cultureInfo;
  private: String amDesignator;
  private: String pmDesignator;
  private: String dateSeparator;
  private: String generalShortTimePattern;
  private: String generalLongTimePattern;
  private: String timeSeparator;
  private: String monthDayPattern;
  private: String dateTimeOffsetPattern;
  private: Calendar calendar;
  private: Int32 firstDayOfWeek;
  private: Int32 calendarWeekRule;
  private: String fullDateTimePattern;
  private: Array<String> abbreviatedDayNames;
  private: Array<String> m_superShortDayNames;
  private: Array<String> dayNames;
  private: Array<String> abbreviatedMonthNames;
  private: Array<String> monthNames;
  private: Array<String> genitiveMonthNames;
  private: Array<String> m_genitiveAbbreviatedMonthNames;
  private: Array<String> leapYearMonthNames;
  private: String longDatePattern;
  private: String shortDatePattern;
  private: String yearMonthPattern;
  private: String longTimePattern;
  private: String shortTimePattern;
  private: Array<String> allYearMonthPatterns;
  private: Array<String> allShortDatePatterns;
  private: Array<String> allLongDatePatterns;
  private: Array<String> allShortTimePatterns;
  private: Array<String> allLongTimePatterns;
  private: Array<String> m_eraNames;
  private: Array<String> m_abbrevEraNames;
  private: Array<String> m_abbrevEnglishEraNames;
  private: Array<CalendarId> optionalCalendars;
  public: Boolean _isReadOnly;
  private: DateTimeFormatFlags formatFlags;
  private: String _decimalSeparator;
  private: String _fullTimeSpanPositivePattern;
  private: String _fullTimeSpanNegativePattern;
  private: Array<TokenHashValue> _dtfiTokenHash;
  private: static DateTimeFormatInfo s_jajpDTFI;
  private: static DateTimeFormatInfo s_zhtwDTFI;
};
} // namespace DateTimeFormatInfoNamespace
using DateTimeFormatInfo = DateTimeFormatInfoNamespace::DateTimeFormatInfo;
} // namespace System::Private::CoreLib::System::Globalization
