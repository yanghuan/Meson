#include "CultureData-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>

namespace System::Private::CoreLib::System::Globalization::CultureDataNamespace {
Dictionary<String, String> CultureData___::get_RegionNames() {
  return nullptr;
};
CultureData CultureData___::get_Invariant() {
  return nullptr;
};
String CultureData___::get_CultureName() {
  return nullptr;
};
Boolean CultureData___::get_UseUserOverride() {
  return Boolean();
};
String CultureData___::get_Name() {
  return nullptr;
};
String CultureData___::get_ParentName() {
  return nullptr;
};
String CultureData___::get_DisplayName() {
  return nullptr;
};
String CultureData___::get_EnglishName() {
  return nullptr;
};
String CultureData___::get_NativeName() {
  return nullptr;
};
String CultureData___::get_SpecificCultureName() {
  return nullptr;
};
String CultureData___::get_TwoLetterISOLanguageName() {
  return nullptr;
};
String CultureData___::get_ThreeLetterISOLanguageName() {
  return nullptr;
};
String CultureData___::get_ThreeLetterWindowsLanguageName() {
  return nullptr;
};
String CultureData___::get_LocalizedLanguageName() {
  return nullptr;
};
String CultureData___::get_EnglishLanguageName() {
  return nullptr;
};
String CultureData___::get_NativeLanguageName() {
  return nullptr;
};
String CultureData___::get_RegionName() {
  return nullptr;
};
Int32 CultureData___::get_GeoId() {
  return Int32();
};
String CultureData___::get_LocalizedCountryName() {
  return nullptr;
};
String CultureData___::get_EnglishCountryName() {
  return nullptr;
};
String CultureData___::get_NativeCountryName() {
  return nullptr;
};
String CultureData___::get_TwoLetterISOCountryName() {
  return nullptr;
};
String CultureData___::get_ThreeLetterISOCountryName() {
  return nullptr;
};
Int32 CultureData___::get_KeyboardLayoutId() {
  return Int32();
};
String CultureData___::get_SCONSOLEFALLBACKNAME() {
  return nullptr;
};
Array<Int32> CultureData___::get_NumberGroupSizes() {
  return Array<Int32>();
};
String CultureData___::get_NaNSymbol() {
  return nullptr;
};
String CultureData___::get_PositiveInfinitySymbol() {
  return nullptr;
};
String CultureData___::get_NegativeInfinitySymbol() {
  return nullptr;
};
Int32 CultureData___::get_PercentNegativePattern() {
  return Int32();
};
Int32 CultureData___::get_PercentPositivePattern() {
  return Int32();
};
String CultureData___::get_PercentSymbol() {
  return nullptr;
};
String CultureData___::get_PerMilleSymbol() {
  return nullptr;
};
String CultureData___::get_CurrencySymbol() {
  return nullptr;
};
String CultureData___::get_ISOCurrencySymbol() {
  return nullptr;
};
String CultureData___::get_CurrencyEnglishName() {
  return nullptr;
};
String CultureData___::get_CurrencyNativeName() {
  return nullptr;
};
Array<Int32> CultureData___::get_CurrencyGroupSizes() {
  return Array<Int32>();
};
Int32 CultureData___::get_MeasurementSystem() {
  return Int32();
};
String CultureData___::get_ListSeparator() {
  return nullptr;
};
String CultureData___::get_AMDesignator() {
  return nullptr;
};
String CultureData___::get_PMDesignator() {
  return nullptr;
};
Array<String> CultureData___::get_LongTimes() {
  return Array<String>();
};
Array<String> CultureData___::get_ShortTimes() {
  return Array<String>();
};
Int32 CultureData___::get_FirstDayOfWeek() {
  return Int32();
};
Int32 CultureData___::get_CalendarWeekRule() {
  return Int32();
};
Array<CalendarId> CultureData___::get_CalendarIds() {
  return Array<CalendarId>();
};
Boolean CultureData___::get_IsRightToLeft() {
  return Boolean();
};
Int32 CultureData___::get_ReadingLayout() {
  return Int32();
};
String CultureData___::get_TextInfoName() {
  return nullptr;
};
String CultureData___::get_SortName() {
  return nullptr;
};
Boolean CultureData___::get_IsSupplementalCustomCulture() {
  return Boolean();
};
Int32 CultureData___::get_ANSICodePage() {
  return Int32();
};
Int32 CultureData___::get_OEMCodePage() {
  return Int32();
};
Int32 CultureData___::get_MacCodePage() {
  return Int32();
};
Int32 CultureData___::get_EBCDICCodePage() {
  return Int32();
};
Int32 CultureData___::get_LCID() {
  return Int32();
};
Boolean CultureData___::get_IsNeutralCulture() {
  return Boolean();
};
Boolean CultureData___::get_IsInvariantCulture() {
  return Boolean();
};
Calendar CultureData___::get_DefaultCalendar() {
  return nullptr;
};
String CultureData___::get_TimeSeparator() {
  return nullptr;
};
Boolean CultureData___::get_IsWin32Installed() {
  return Boolean();
};
Boolean CultureData___::get_IsReplacementCulture() {
  return Boolean();
};
CultureData CultureData___::GetCultureDataForRegion(String cultureName, Boolean useUserOverride) {
  return nullptr;
};
void CultureData___::ClearCachedData() {
};
Array<CultureInfo> CultureData___::GetCultures(CultureTypes types) {
  return Array<CultureInfo>();
};
CultureData CultureData___::CreateCultureWithInvariantData() {
  return nullptr;
};
CultureData CultureData___::GetCultureData(String cultureName, Boolean useUserOverride) {
  return nullptr;
};
String CultureData___::NormalizeCultureName(String name, Boolean& isNeutralName) {
  return nullptr;
};
CultureData CultureData___::CreateCultureData(String cultureName, Boolean useUserOverride) {
  return nullptr;
};
Boolean CultureData___::InitCompatibilityCultureData() {
  return Boolean();
};
CultureData CultureData___::GetCultureData(Int32 culture, Boolean bUseUserOverride) {
  return nullptr;
};
Array<String> CultureData___::DeriveShortTimesFromLong() {
  return Array<String>();
};
String CultureData___::StripSecondsFromPattern(String time) {
  return nullptr;
};
Int32 CultureData___::GetIndexOfNextTokenAfterSeconds(String time, Int32 index, Boolean& containsSpace) {
  return Int32();
};
Array<String> CultureData___::ShortDates(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::LongDates(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::YearMonths(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::DayNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::AbbreviatedDayNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::SuperShortDayNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::MonthNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::GenitiveMonthNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::AbbreviatedMonthNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::AbbreviatedGenitiveMonthNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::LeapYearMonthNames(CalendarId calendarId) {
  return Array<String>();
};
String CultureData___::MonthDay(CalendarId calendarId) {
  return nullptr;
};
String CultureData___::CalendarName(CalendarId calendarId) {
  return nullptr;
};
CalendarData CultureData___::GetCalendar(CalendarId calendarId) {
  return nullptr;
};
Array<String> CultureData___::EraNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::AbbrevEraNames(CalendarId calendarId) {
  return Array<String>();
};
Array<String> CultureData___::AbbreviatedEnglishEraNames(CalendarId calendarId) {
  return Array<String>();
};
String CultureData___::DateSeparator(CalendarId calendarId) {
  return nullptr;
};
String CultureData___::UnescapeNlsString(String str, Int32 start, Int32 end) {
  return nullptr;
};
String CultureData___::GetTimeSeparator(String format) {
  return nullptr;
};
String CultureData___::GetDateSeparator(String format) {
  return nullptr;
};
String CultureData___::GetSeparator(String format, String timeParts) {
  return nullptr;
};
Int32 CultureData___::IndexOfTimePart(String format, Int32 startIndex, String timeParts) {
  return Int32();
};
Boolean CultureData___::IsCustomCultureId(Int32 cultureId) {
  return Boolean();
};
void CultureData___::GetNFIValues(NumberFormatInfo nfi) {
};
String CultureData___::AnsiToLower(String testString) {
  return nullptr;
};
Boolean CultureData___::InitCultureData() {
  return Boolean();
};
String CultureData___::GetLocaleInfoEx(String localeName, UInt32 field) {
  return nullptr;
};
Int32 CultureData___::GetLocaleInfoExInt(String localeName, UInt32 field) {
  return Int32();
};
Int32 CultureData___::GetLocaleInfoEx(String lpLocaleName, UInt32 lcType, Char* lpLCData, Int32 cchData) {
  return Int32();
};
String CultureData___::GetLocaleInfo(LocaleStringData type) {
  return nullptr;
};
String CultureData___::GetLocaleInfo(String localeName, LocaleStringData type) {
  return nullptr;
};
Int32 CultureData___::GetLocaleInfo(LocaleNumberData type) {
  return Int32();
};
Array<Int32> CultureData___::GetLocaleInfo(LocaleGroupingData type) {
  return Array<Int32>();
};
String CultureData___::GetTimeFormatString() {
  return nullptr;
};
Int32 CultureData___::GetFirstDayOfWeek() {
  return Int32();
};
Array<String> CultureData___::GetTimeFormats() {
  return Array<String>();
};
Array<String> CultureData___::GetShortTimeFormats() {
  return Array<String>();
};
CultureData CultureData___::GetCultureDataFromRegionName(String regionName) {
  return nullptr;
};
String CultureData___::GetLanguageDisplayName(String cultureName) {
  return nullptr;
};
String CultureData___::GetRegionDisplayName() {
  return nullptr;
};
String CultureData___::GetLocaleInfoFromLCType(String localeName, UInt32 lctype, Boolean useUserOveride) {
  return nullptr;
};
String CultureData___::ReescapeWin32String(String str) {
  return nullptr;
};
Array<String> CultureData___::ReescapeWin32Strings(Array<String> array) {
  return Array<String>();
};
Array<Int32> CultureData___::ConvertWin32GroupString(String win32Str) {
  return Array<Int32>();
};
Int32 CultureData___::ConvertFirstDayOfWeekMonToSun(Int32 iTemp) {
  return Int32();
};
Interop::BOOL CultureData___::EnumSystemLocalesProc(Char* lpLocaleString, UInt32 flags, void* contextHandle) {
  return Interop::BOOL::TRUE;
};
Interop::BOOL CultureData___::EnumAllSystemLocalesProc(Char* lpLocaleString, UInt32 flags, void* contextHandle) {
  return Interop::BOOL::TRUE;
};
Interop::BOOL CultureData___::EnumTimeCallback(Char* lpTimeFormatString, void* lParam) {
  return Interop::BOOL::TRUE;
};
Array<String> CultureData___::nativeEnumTimeFormats(String localeName, UInt32 dwFlags, Boolean useUserOverride) {
  return Array<String>();
};
Int32 CultureData___::LocaleNameToLCID(String cultureName) {
  return Int32();
};
String CultureData___::LCIDToLocaleName(Int32 culture) {
  return nullptr;
};
Int32 CultureData___::GetAnsiCodePage(String cultureName) {
  return Int32();
};
Int32 CultureData___::GetOemCodePage(String cultureName) {
  return Int32();
};
Int32 CultureData___::GetMacCodePage(String cultureName) {
  return Int32();
};
Int32 CultureData___::GetEbcdicCodePage(String cultureName) {
  return Int32();
};
Int32 CultureData___::GetGeoId(String cultureName) {
  return Int32();
};
Int32 CultureData___::GetDigitSubstitution(String cultureName) {
  return Int32();
};
String CultureData___::GetThreeLetterWindowsLanguageName(String cultureName) {
  return nullptr;
};
Array<CultureInfo> CultureData___::EnumCultures(CultureTypes types) {
  return Array<CultureInfo>();
};
String CultureData___::GetConsoleFallbackName(String cultureName) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Globalization::CultureDataNamespace
