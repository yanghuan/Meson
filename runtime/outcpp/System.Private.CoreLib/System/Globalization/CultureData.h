#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Char)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Globalization {
enum class CalendarId : uint16_t;
enum class CultureTypes : int32_t;
FORWARD(Calendar)
FORWARD(CalendarData)
FORWARD(CultureInfo)
FORWARD(NumberFormatInfo)
namespace CultureDataNamespace {
using namespace System::Collections::Generic;
CLASS(CultureData) : public object {
  private: enum class LocaleStringData : uint32_t {
    LocalizedDisplayName = 2,
    EnglishDisplayName = 114,
    NativeDisplayName = 115,
    LocalizedLanguageName = 111,
    EnglishLanguageName = 4097,
    NativeLanguageName = 4,
    LocalizedCountryName = 6,
    EnglishCountryName = 4098,
    NativeCountryName = 8,
    AbbreviatedWindowsLanguageName = 3,
    ListSeparator = 12,
    DecimalSeparator = 14,
    ThousandSeparator = 15,
    Digits = 19,
    MonetarySymbol = 20,
    CurrencyEnglishName = 4103,
    CurrencyNativeName = 4104,
    Iso4217MonetarySymbol = 21,
    MonetaryDecimalSeparator = 22,
    MonetaryThousandSeparator = 23,
    AMDesignator = 40,
    PMDesignator = 41,
    PositiveSign = 80,
    NegativeSign = 81,
    Iso639LanguageTwoLetterName = 89,
    Iso639LanguageThreeLetterName = 103,
    Iso639LanguageName = 89,
    Iso3166CountryName = 90,
    Iso3166CountryName2 = 104,
    NaNSymbol = 105,
    PositiveInfinitySymbol = 106,
    NegativeInfinitySymbol = 107,
    ParentName = 109,
    ConsoleFallbackName = 110,
    PercentSymbol = 118,
    PerMilleSymbol = 119,
  };
  private: enum class LocaleGroupingData : uint32_t {
    Digit = 16,
    Monetary = 24,
  };
  private: enum class LocaleNumberData : uint32_t {
    LanguageId = 1,
    GeoId = 91,
    DigitSubstitution = 4116,
    MeasurementSystem = 13,
    FractionalDigitsCount = 17,
    NegativeNumberFormat = 4112,
    MonetaryFractionalDigitsCount = 25,
    PositiveMonetaryNumberFormat = 27,
    NegativeMonetaryNumberFormat = 28,
    CalendarType = 4105,
    FirstDayOfWeek = 4108,
    FirstWeekOfYear = 4109,
    ReadingLayout = 112,
    NegativePercentFormat = 116,
    PositivePercentFormat = 117,
    OemCodePage = 11,
    AnsiCodePage = 4100,
    MacCodePage = 4113,
    EbcdicCodePage = 4114,
  };
  private: struct EnumLocaleData : public valueType<EnumLocaleData> {
    public: String regionName;
    public: String cultureName;
  };
  private: struct EnumData : public valueType<EnumData> {
    public: List<String> strings;
  };
  private: static Dictionary<String, String> get_RegionNames();
  public: static CultureData get_Invariant();
  public: String get_CultureName();
  public: Boolean get_UseUserOverride();
  public: String get_Name();
  public: String get_ParentName();
  public: String get_DisplayName();
  public: String get_EnglishName();
  public: String get_NativeName();
  public: String get_SpecificCultureName();
  public: String get_TwoLetterISOLanguageName();
  public: String get_ThreeLetterISOLanguageName();
  public: String get_ThreeLetterWindowsLanguageName();
  private: String get_LocalizedLanguageName();
  private: String get_EnglishLanguageName();
  private: String get_NativeLanguageName();
  public: String get_RegionName();
  public: Int32 get_GeoId();
  public: String get_LocalizedCountryName();
  public: String get_EnglishCountryName();
  public: String get_NativeCountryName();
  public: String get_TwoLetterISOCountryName();
  public: String get_ThreeLetterISOCountryName();
  public: Int32 get_KeyboardLayoutId();
  public: String get_SCONSOLEFALLBACKNAME();
  public: Array<Int32> get_NumberGroupSizes();
  private: String get_NaNSymbol();
  private: String get_PositiveInfinitySymbol();
  private: String get_NegativeInfinitySymbol();
  private: Int32 get_PercentNegativePattern();
  private: Int32 get_PercentPositivePattern();
  private: String get_PercentSymbol();
  private: String get_PerMilleSymbol();
  public: String get_CurrencySymbol();
  public: String get_ISOCurrencySymbol();
  public: String get_CurrencyEnglishName();
  public: String get_CurrencyNativeName();
  public: Array<Int32> get_CurrencyGroupSizes();
  public: Int32 get_MeasurementSystem();
  public: String get_ListSeparator();
  public: String get_AMDesignator();
  public: String get_PMDesignator();
  public: Array<String> get_LongTimes();
  public: Array<String> get_ShortTimes();
  public: Int32 get_FirstDayOfWeek();
  public: Int32 get_CalendarWeekRule();
  public: Array<CalendarId> get_CalendarIds();
  public: Boolean get_IsRightToLeft();
  private: Int32 get_ReadingLayout();
  public: String get_TextInfoName();
  public: String get_SortName();
  public: Boolean get_IsSupplementalCustomCulture();
  public: Int32 get_ANSICodePage();
  public: Int32 get_OEMCodePage();
  public: Int32 get_MacCodePage();
  public: Int32 get_EBCDICCodePage();
  public: Int32 get_LCID();
  public: Boolean get_IsNeutralCulture();
  public: Boolean get_IsInvariantCulture();
  public: Boolean get_IsReplacementCulture();
  public: Calendar get_DefaultCalendar();
  public: String get_TimeSeparator();
  public: Boolean get_NlsIsReplacementCulture();
  public: static Boolean get_IsWin32Installed();
  private: Boolean get_ShouldUseUserOverrideNlsData();
  public: static CultureData GetCultureDataForRegion(String cultureName, Boolean useUserOverride);
  public: static void ClearCachedData();
  public: static Array<CultureInfo> GetCultures(CultureTypes types);
  private: static CultureData CreateCultureWithInvariantData();
  public: static CultureData GetCultureData(String cultureName, Boolean useUserOverride);
  private: static String NormalizeCultureName(String name, Boolean& isNeutralName);
  private: static CultureData CreateCultureData(String cultureName, Boolean useUserOverride);
  private: Boolean InitCompatibilityCultureData();
  public: static CultureData GetCultureData(Int32 culture, Boolean bUseUserOverride);
  private: String GetLanguageDisplayNameCore(String cultureName);
  private: Array<String> DeriveShortTimesFromLong();
  private: static String StripSecondsFromPattern(String time);
  private: static Int32 GetIndexOfNextTokenAfterSeconds(String time, Int32 index, Boolean& containsSpace);
  public: Array<String> ShortDates(CalendarId calendarId);
  public: Array<String> LongDates(CalendarId calendarId);
  public: Array<String> YearMonths(CalendarId calendarId);
  public: Array<String> DayNames(CalendarId calendarId);
  public: Array<String> AbbreviatedDayNames(CalendarId calendarId);
  public: Array<String> SuperShortDayNames(CalendarId calendarId);
  public: Array<String> MonthNames(CalendarId calendarId);
  public: Array<String> GenitiveMonthNames(CalendarId calendarId);
  public: Array<String> AbbreviatedMonthNames(CalendarId calendarId);
  public: Array<String> AbbreviatedGenitiveMonthNames(CalendarId calendarId);
  public: Array<String> LeapYearMonthNames(CalendarId calendarId);
  public: String MonthDay(CalendarId calendarId);
  public: String CalendarName(CalendarId calendarId);
  public: CalendarData GetCalendar(CalendarId calendarId);
  public: Array<String> EraNames(CalendarId calendarId);
  public: Array<String> AbbrevEraNames(CalendarId calendarId);
  public: Array<String> AbbreviatedEnglishEraNames(CalendarId calendarId);
  public: String DateSeparator(CalendarId calendarId);
  private: static String UnescapeNlsString(String str, Int32 start, Int32 end);
  private: static String GetTimeSeparator(String format);
  private: static String GetDateSeparator(String format);
  private: static String GetSeparator(String format, String timeParts);
  private: static Int32 IndexOfTimePart(String format, Int32 startIndex, String timeParts);
  public: static Boolean IsCustomCultureId(Int32 cultureId);
  public: void GetNFIValues(NumberFormatInfo nfi);
  public: static String AnsiToLower(String testString);
  private: Int32 GetLocaleInfoCore(LocaleNumberData type);
  private: Int32 GetLocaleInfoCoreUserOverride(LocaleNumberData type);
  private: String GetLocaleInfoCoreUserOverride(LocaleStringData type);
  private: String GetLocaleInfoCore(LocaleStringData type);
  private: String GetLocaleInfoCore(String localeName, LocaleStringData type);
  private: Array<Int32> GetLocaleInfoCoreUserOverride(LocaleGroupingData type);
  private: String IcuGetLocaleInfo(LocaleStringData type);
  private: String IcuGetLocaleInfo(String localeName, LocaleStringData type);
  private: Int32 IcuGetLocaleInfo(LocaleNumberData type);
  private: Array<Int32> IcuGetLocaleInfo(LocaleGroupingData type);
  private: String IcuGetTimeFormatString();
  private: String IcuGetTimeFormatString(Boolean shortFormat);
  private: static CultureData IcuGetCultureDataFromRegionName(String regionName);
  private: static String IcuGetLanguageDisplayName(String cultureName);
  private: static String IcuGetRegionDisplayName();
  private: static String ConvertIcuTimeFormatString(ReadOnlySpan<Char> icuFormatString);
  private: static Int32 IcuLocaleNameToLCID(String cultureName);
  private: static Int32 IcuGetGeoId(String cultureName);
  private: static Int32 IcuGetDigitSubstitution(String cultureName);
  private: static String IcuGetListSeparator(String cultureName);
  private: static String IcuGetThreeLetterWindowsLanguageName(String cultureName);
  private: static Array<CultureInfo> IcuEnumCultures(CultureTypes types);
  private: static String IcuGetConsoleFallbackName(String cultureName);
  public: static String GetLocaleInfoEx(String localeName, UInt32 field);
  public: static Int32 GetLocaleInfoExInt(String localeName, UInt32 field);
  public: static Int32 GetLocaleInfoEx(String lpLocaleName, UInt32 lcType, Char* lpLCData, Int32 cchData);
  private: String NlsGetLocaleInfo(LocaleStringData type);
  private: String NlsGetLocaleInfo(String localeName, LocaleStringData type);
  private: Int32 NlsGetLocaleInfo(LocaleNumberData type);
  private: Array<Int32> NlsGetLocaleInfo(LocaleGroupingData type);
  private: String NlsGetTimeFormatString();
  private: Int32 NlsGetFirstDayOfWeek();
  private: static CultureData NlsGetCultureDataFromRegionName(String regionName);
  private: String NlsGetLanguageDisplayName(String cultureName);
  private: String NlsGetRegionDisplayName();
  private: static String GetLocaleInfoFromLCType(String localeName, UInt32 lctype, Boolean useUserOverride);
  public: static String ReescapeWin32String(String str);
  public: static Array<String> ReescapeWin32Strings(Array<String> array);
  private: static Array<Int32> ConvertWin32GroupString(String win32Str);
  private: static Int32 ConvertFirstDayOfWeekMonToSun(Int32 iTemp);
  private: static Interop::BOOL EnumSystemLocalesProc(Char* lpLocaleString, UInt32 flags, void* contextHandle);
  private: static Interop::BOOL EnumAllSystemLocalesProc(Char* lpLocaleString, UInt32 flags, void* contextHandle);
  private: static Interop::BOOL EnumTimeCallback(Char* lpTimeFormatString, void* lParam);
  private: static Array<String> nativeEnumTimeFormats(String localeName, UInt32 dwFlags, Boolean useUserOverride);
  private: static Int32 NlsLocaleNameToLCID(String cultureName);
  private: String NlsGetThreeLetterWindowsLanguageName(String cultureName);
  private: static Array<CultureInfo> NlsEnumCultures(CultureTypes types);
  private: String NlsGetConsoleFallbackName(String cultureName);
  private: Boolean InitCultureDataCore();
  private: void InitUserOverride(Boolean useUserOverride);
  public: static CultureData GetCurrentRegionData();
  private: static String LCIDToLocaleName(Int32 culture);
  private: Array<String> GetTimeFormatsCore(Boolean shortFormat);
  private: Int32 GetAnsiCodePage(String cultureName);
  private: Int32 GetOemCodePage(String cultureName);
  private: Int32 GetMacCodePage(String cultureName);
  private: Int32 GetEbcdicCodePage(String cultureName);
  public: void ctor();
  public: static void cctor();
  private: String _sRealName;
  private: String _sWindowsName;
  private: String _sName;
  private: String _sParent;
  private: String _sLocalizedDisplayName;
  private: String _sEnglishDisplayName;
  private: String _sNativeDisplayName;
  private: String _sSpecificCulture;
  private: String _sISO639Language;
  private: String _sISO639Language2;
  private: String _sLocalizedLanguage;
  private: String _sEnglishLanguage;
  private: String _sNativeLanguage;
  private: String _sAbbrevLang;
  private: String _sConsoleFallbackName;
  private: Int32 _iInputLanguageHandle;
  private: String _sRegionName;
  private: String _sLocalizedCountry;
  private: String _sEnglishCountry;
  private: String _sNativeCountry;
  private: String _sISO3166CountryName;
  private: String _sISO3166CountryName2;
  private: Int32 _iGeoId;
  private: String _sPositiveSign;
  private: String _sNegativeSign;
  private: Int32 _iDigits;
  private: Int32 _iNegativeNumber;
  private: Array<Int32> _waGrouping;
  private: String _sDecimalSeparator;
  private: String _sThousandSeparator;
  private: String _sNaN;
  private: String _sPositiveInfinity;
  private: String _sNegativeInfinity;
  private: Int32 _iNegativePercent;
  private: Int32 _iPositivePercent;
  private: String _sPercent;
  private: String _sPerMille;
  private: String _sCurrency;
  private: String _sIntlMonetarySymbol;
  private: String _sEnglishCurrency;
  private: String _sNativeCurrency;
  private: Int32 _iCurrencyDigits;
  private: Int32 _iCurrency;
  private: Int32 _iNegativeCurrency;
  private: Array<Int32> _waMonetaryGrouping;
  private: String _sMonetaryDecimal;
  private: String _sMonetaryThousand;
  private: Int32 _iMeasure;
  private: String _sListSeparator;
  private: String _sAM1159;
  private: String _sPM2359;
  private: String _sTimeSeparator;
  private: Array<String> _saLongTimes;
  private: Array<String> _saShortTimes;
  private: Array<String> _saDurationFormats;
  private: Int32 _iFirstDayOfWeek;
  private: Int32 _iFirstWeekOfYear;
  private: Array<CalendarId> _waCalendars;
  private: Array<CalendarData> _calendars;
  private: Int32 _iReadingLayout;
  private: Int32 _iDefaultAnsiCodePage;
  private: Int32 _iDefaultOemCodePage;
  private: Int32 _iDefaultMacCodePage;
  private: Int32 _iDefaultEbcdicCodePage;
  private: Int32 _iLanguage;
  private: Boolean _bUseOverrides;
  private: Boolean _bUseOverridesUserSetting;
  private: Boolean _bNeutral;
  private: static Dictionary<String, CultureData> s_cachedRegions;
  private: static Dictionary<String, String> s_regionNames;
  private: static CultureData s_Invariant;
  private: static Dictionary<String, CultureData> s_cachedCultures;
  private: static Object s_lock;
};
} // namespace CultureDataNamespace
using CultureData = CultureDataNamespace::CultureData;
} // namespace System::Private::CoreLib::System::Globalization
