#include "CultureInfo-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>

namespace System::Private::CoreLib::System::Globalization::CultureInfoNamespace {
CultureInfo CultureInfo___::get_CurrentCulture() {
  return nullptr;
};
void CultureInfo___::set_CurrentCulture(CultureInfo value) {
  return void();
};
CultureInfo CultureInfo___::get_CurrentUICulture() {
  return nullptr;
};
void CultureInfo___::set_CurrentUICulture(CultureInfo value) {
  return void();
};
CultureInfo CultureInfo___::get_UserDefaultUICulture() {
  return nullptr;
};
CultureInfo CultureInfo___::get_InstalledUICulture() {
  return nullptr;
};
CultureInfo CultureInfo___::get_DefaultThreadCurrentCulture() {
  return nullptr;
};
void CultureInfo___::set_DefaultThreadCurrentCulture(CultureInfo value) {
  return void();
};
CultureInfo CultureInfo___::get_DefaultThreadCurrentUICulture() {
  return nullptr;
};
void CultureInfo___::set_DefaultThreadCurrentUICulture(CultureInfo value) {
  return void();
};
CultureInfo CultureInfo___::get_InvariantCulture() {
  return nullptr;
};
CultureInfo CultureInfo___::get_Parent() {
  return nullptr;
};
Int32 CultureInfo___::get_LCID() {
  return Int32();
};
Int32 CultureInfo___::get_KeyboardLayoutId() {
  return Int32();
};
String CultureInfo___::get_Name() {
  return nullptr;
};
String CultureInfo___::get_SortName() {
  return nullptr;
};
String CultureInfo___::get_IetfLanguageTag() {
  return nullptr;
};
String CultureInfo___::get_DisplayName() {
  return nullptr;
};
String CultureInfo___::get_NativeName() {
  return nullptr;
};
String CultureInfo___::get_EnglishName() {
  return nullptr;
};
String CultureInfo___::get_TwoLetterISOLanguageName() {
  return nullptr;
};
String CultureInfo___::get_ThreeLetterISOLanguageName() {
  return nullptr;
};
String CultureInfo___::get_ThreeLetterWindowsLanguageName() {
  return nullptr;
};
CompareInfo CultureInfo___::get_CompareInfo() {
  return nullptr;
};
TextInfo CultureInfo___::get_TextInfo() {
  return nullptr;
};
Boolean CultureInfo___::get_IsNeutralCulture() {
  return Boolean();
};
CultureTypes CultureInfo___::get_CultureTypes() {
  return CultureTypes();
};
NumberFormatInfo CultureInfo___::get_NumberFormat() {
  return nullptr;
};
void CultureInfo___::set_NumberFormat(NumberFormatInfo value) {
  return void();
};
DateTimeFormatInfo CultureInfo___::get_DateTimeFormat() {
  return nullptr;
};
void CultureInfo___::set_DateTimeFormat(DateTimeFormatInfo value) {
  return void();
};
Calendar CultureInfo___::get_Calendar() {
  return nullptr;
};
Array<Calendar> CultureInfo___::get_OptionalCalendars() {
  return Array<Calendar>();
};
Boolean CultureInfo___::get_UseUserOverride() {
  return Boolean();
};
Boolean CultureInfo___::get_IsReadOnly() {
  return Boolean();
};
Boolean CultureInfo___::get_HasInvariantCultureName() {
  return Boolean();
};
void CultureInfo___::AsyncLocalSetCurrentCulture(AsyncLocalValueChangedArgs<CultureInfo> args) {
  return void();
};
void CultureInfo___::AsyncLocalSetCurrentUICulture(AsyncLocalValueChangedArgs<CultureInfo> args) {
  return void();
};
CultureInfo CultureInfo___::InitializeUserDefaultCulture() {
  return nullptr;
};
CultureInfo CultureInfo___::InitializeUserDefaultUICulture() {
  return nullptr;
};
CultureInfo CultureInfo___::CreateCultureInfoNoThrow(String name, Boolean useUserOverride) {
  return nullptr;
};
CultureInfo CultureInfo___::GetCultureByName(String name) {
  return nullptr;
};
CultureInfo CultureInfo___::CreateSpecificCulture(String name) {
  return nullptr;
};
Boolean CultureInfo___::VerifyCultureName(String cultureName, Boolean throwException) {
  return Boolean();
};
Boolean CultureInfo___::VerifyCultureName(CultureInfo culture, Boolean throwException) {
  return Boolean();
};
Array<CultureInfo> CultureInfo___::GetCultures(CultureTypes types) {
  return Array<CultureInfo>();
};
Boolean CultureInfo___::Equals(Object value) {
  return Boolean();
};
Int32 CultureInfo___::GetHashCode() {
  return Int32();
};
String CultureInfo___::ToString() {
  return nullptr;
};
Object CultureInfo___::GetFormat(Type formatType) {
  return nullptr;
};
void CultureInfo___::ClearCachedData() {
  return void();
};
Calendar CultureInfo___::GetCalendarInstance(CalendarId calType) {
  return nullptr;
};
Calendar CultureInfo___::GetCalendarInstanceRare(CalendarId calType) {
  return nullptr;
};
CultureInfo CultureInfo___::GetConsoleFallbackUICulture() {
  return nullptr;
};
Object CultureInfo___::Clone() {
  return nullptr;
};
CultureInfo CultureInfo___::ReadOnly(CultureInfo ci) {
  return nullptr;
};
void CultureInfo___::VerifyWritable() {
  return void();
};
CultureInfo CultureInfo___::GetCultureInfoHelper(Int32 lcid, String name, String altName) {
  return nullptr;
};
CultureInfo CultureInfo___::GetCultureInfo(Int32 culture) {
  return nullptr;
};
CultureInfo CultureInfo___::GetCultureInfo(String name) {
  return nullptr;
};
CultureInfo CultureInfo___::GetCultureInfo(String name, String altName) {
  return nullptr;
};
CultureInfo CultureInfo___::GetCultureInfoByIetfLanguageTag(String name) {
  return nullptr;
};
CultureInfo CultureInfo___::GetUserDefaultCulture() {
  return nullptr;
};
CultureInfo CultureInfo___::GetUserDefaultUICulture() {
  return nullptr;
};
CultureInfo CultureInfo___::GetCultureInfoForUserPreferredLanguageInAppX() {
  return nullptr;
};
Boolean CultureInfo___::SetCultureInfoForUserPreferredLanguageInAppX(CultureInfo ci) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Globalization::CultureInfoNamespace
