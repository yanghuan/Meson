#include "CultureData-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarData-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureNotFoundException-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/IcuLocaleData-dep.h>
#include <System.Private.CoreLib/System/Globalization/IcuLocaleDataParts.h>
#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/LocalAppContextSwitches-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::CultureDataNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Text;

Dictionary<String, String> CultureData___::get_RegionNames() {
  Object obj = s_regionNames;
  if (obj == nullptr) {
    obj = rt::newobj<Dictionary<String, String>>(257);
    s_regionNames = (Dictionary<String, String>)obj;
  }
  return (Dictionary<String, String>)obj;
}

CultureData CultureData___::get_Invariant() {
  auto& default = s_Invariant;
  return default != nullptr ? default : (s_Invariant = CreateCultureWithInvariantData());
}

String CultureData___::get_CultureName() {
  String sName = _sName;
  if (sName == "zh-CHS" || sName == "zh-CHT") {
    return _sName;
  }
  return _sRealName;
}

Boolean CultureData___::get_UseUserOverride() {
  return _bUseOverrides;
}

String CultureData___::get_Name() {
  auto& default = _sName;
  return default != nullptr ? default : String::in::Empty;
}

String CultureData___::get_ParentName() {
  auto& default = _sParent;
  return default != nullptr ? default : (_sParent = GetLocaleInfoCore(_sRealName, LocaleStringData::ParentName));
}

String CultureData___::get_DisplayName() {
  String text = _sLocalizedDisplayName;
  if (text == nullptr) {
    if (get_IsSupplementalCustomCulture()) {
      text = ((!get_IsNeutralCulture()) ? get_NativeName() : get_NativeLanguageName());
    } else {
      try {
        text = (get_Name()->Equals("zh-CHT", StringComparison::OrdinalIgnoreCase) ? GetLanguageDisplayNameCore("zh-Hant") : ((!get_Name()->Equals("zh-CHS", StringComparison::OrdinalIgnoreCase)) ? GetLanguageDisplayNameCore(get_Name()) : GetLanguageDisplayNameCore("zh-Hans")));
      } catch (...) {
      }
    }
    if (String::in::IsNullOrEmpty(text)) {
      CultureInfo userDefaultCulture;
      text = (get_IsNeutralCulture() ? get_LocalizedLanguageName() : ((CultureInfo::in::get_DefaultThreadCurrentUICulture() == nullptr || (userDefaultCulture = CultureInfo::in::GetUserDefaultCulture()) == nullptr || CultureInfo::in::get_DefaultThreadCurrentUICulture()->get_Name()->Equals(userDefaultCulture->get_Name())) ? GetLocaleInfoCore(LocaleStringData::LocalizedDisplayName) : get_NativeName()));
    }
    _sLocalizedDisplayName = text;
  }
  return text;
}

String CultureData___::get_EnglishName() {
  String text = _sEnglishDisplayName;
  if (text == nullptr) {
    if (get_IsNeutralCulture()) {
      text = get_EnglishLanguageName();
      String sName = _sName;
      if (sName == "zh-CHS" || sName == "zh-CHT") {
        text += " Legacy";
      }
    } else {
      text = GetLocaleInfoCore(LocaleStringData::EnglishDisplayName);
      if (String::in::IsNullOrEmpty(text)) {
      }
    }
    _sEnglishDisplayName = text;
  }
  return text;
}

String CultureData___::get_NativeName() {
  String text = _sNativeDisplayName;
  if (text == nullptr) {
    if (get_IsNeutralCulture()) {
      text = get_NativeLanguageName();
      String sName = _sName;
      if (!(sName == "zh-CHS")) {
        if (sName == "zh-CHT") {
          text += " 舊版";
        }
      } else {
        text += " 旧版";
      }
    } else {
      text = GetLocaleInfoCore(LocaleStringData::NativeDisplayName);
      if (String::in::IsNullOrEmpty(text)) {
        text = get_NativeLanguageName() + " (" + get_NativeCountryName() + ")";
      }
    }
    _sNativeDisplayName = text;
  }
  return text;
}

String CultureData___::get_SpecificCultureName() {
  return _sSpecificCulture;
}

String CultureData___::get_TwoLetterISOLanguageName() {
  auto& default = _sISO639Language;
  return default != nullptr ? default : (_sISO639Language = GetLocaleInfoCore(LocaleStringData::Iso639LanguageTwoLetterName));
}

String CultureData___::get_ThreeLetterISOLanguageName() {
  auto& default = _sISO639Language2;
  return default != nullptr ? default : (_sISO639Language2 = GetLocaleInfoCore(LocaleStringData::Iso639LanguageThreeLetterName));
}

String CultureData___::get_ThreeLetterWindowsLanguageName() {
  auto& default = _sAbbrevLang;
  return default != nullptr ? default : (_sAbbrevLang = (GlobalizationMode::get_UseNls() ? NlsGetThreeLetterWindowsLanguageName(_sRealName) : IcuGetThreeLetterWindowsLanguageName(_sRealName)));
}

String CultureData___::get_LocalizedLanguageName() {
  if (_sLocalizedLanguage == nullptr) {
    CultureInfo userDefaultCulture;
    if (CultureInfo::in::get_DefaultThreadCurrentUICulture() != nullptr && (userDefaultCulture = CultureInfo::in::GetUserDefaultCulture()) != nullptr && !CultureInfo::in::get_DefaultThreadCurrentUICulture()->get_Name()->Equals(userDefaultCulture->get_Name())) {
      _sLocalizedLanguage = get_NativeLanguageName();
    } else {
      _sLocalizedLanguage = GetLocaleInfoCore(LocaleStringData::LocalizedLanguageName);
    }
  }
  return _sLocalizedLanguage;
}

String CultureData___::get_EnglishLanguageName() {
  auto& default = _sEnglishLanguage;
  return default != nullptr ? default : (_sEnglishLanguage = GetLocaleInfoCore(LocaleStringData::EnglishLanguageName));
}

String CultureData___::get_NativeLanguageName() {
  auto& default = _sNativeLanguage;
  return default != nullptr ? default : (_sNativeLanguage = GetLocaleInfoCore(LocaleStringData::NativeLanguageName));
}

String CultureData___::get_RegionName() {
  auto& default = _sRegionName;
  return default != nullptr ? default : (_sRegionName = GetLocaleInfoCore(LocaleStringData::Iso3166CountryName));
}

Int32 CultureData___::get_GeoId() {
  if (_iGeoId == -1) {
    _iGeoId = (GlobalizationMode::get_UseNls() ? NlsGetGeoId(_sRealName) : IcuGetGeoId(_sRealName));
  }
  return _iGeoId;
}

String CultureData___::get_LocalizedCountryName() {
  String text = _sLocalizedCountry;
  if (text == nullptr) {
    try {
      text = (GlobalizationMode::get_UseNls() ? NlsGetRegionDisplayName() : IcuGetRegionDisplayName());
    } catch (...) {
    }
    if (text == nullptr) {
      text = get_NativeCountryName();
    }
    _sLocalizedCountry = text;
  }
  return text;
}

String CultureData___::get_EnglishCountryName() {
  auto& default = _sEnglishCountry;
  return default != nullptr ? default : (_sEnglishCountry = GetLocaleInfoCore(LocaleStringData::EnglishCountryName));
}

String CultureData___::get_NativeCountryName() {
  auto& default = _sNativeCountry;
  return default != nullptr ? default : (_sNativeCountry = GetLocaleInfoCore(LocaleStringData::NativeCountryName));
}

String CultureData___::get_TwoLetterISOCountryName() {
  auto& default = _sISO3166CountryName;
  return default != nullptr ? default : (_sISO3166CountryName = GetLocaleInfoCore(LocaleStringData::Iso3166CountryName));
}

String CultureData___::get_ThreeLetterISOCountryName() {
  auto& default = _sISO3166CountryName2;
  return default != nullptr ? default : (_sISO3166CountryName2 = GetLocaleInfoCore(LocaleStringData::Iso3166CountryName2));
}

Int32 CultureData___::get_KeyboardLayoutId() {
  if (_iInputLanguageHandle == -1) {
    if (get_IsSupplementalCustomCulture()) {
      _iInputLanguageHandle = 1033;
    } else {
      _iInputLanguageHandle = get_LCID();
    }
  }
  return _iInputLanguageHandle;
}

String CultureData___::get_SCONSOLEFALLBACKNAME() {
  auto& default = _sConsoleFallbackName;
  return default != nullptr ? default : (_sConsoleFallbackName = (GlobalizationMode::get_UseNls() ? NlsGetConsoleFallbackName(_sRealName) : IcuGetConsoleFallbackName(_sRealName)));
}

Array<Int32> CultureData___::get_NumberGroupSizes() {
  auto& default = _waGrouping;
  return default != nullptr ? default : (_waGrouping = GetLocaleInfoCore(LocaleGroupingData::Digit));
}

String CultureData___::get_NaNSymbol() {
  auto& default = _sNaN;
  return default != nullptr ? default : (_sNaN = GetLocaleInfoCore(LocaleStringData::NaNSymbol));
}

String CultureData___::get_PositiveInfinitySymbol() {
  auto& default = _sPositiveInfinity;
  return default != nullptr ? default : (_sPositiveInfinity = GetLocaleInfoCore(LocaleStringData::PositiveInfinitySymbol));
}

String CultureData___::get_NegativeInfinitySymbol() {
  auto& default = _sNegativeInfinity;
  return default != nullptr ? default : (_sNegativeInfinity = GetLocaleInfoCore(LocaleStringData::NegativeInfinitySymbol));
}

Int32 CultureData___::get_PercentNegativePattern() {
  if (_iNegativePercent == -1) {
    _iNegativePercent = GetLocaleInfoCore(LocaleNumberData::NegativePercentFormat);
  }
  return _iNegativePercent;
}

Int32 CultureData___::get_PercentPositivePattern() {
  if (_iPositivePercent == -1) {
    _iPositivePercent = GetLocaleInfoCore(LocaleNumberData::PositivePercentFormat);
  }
  return _iPositivePercent;
}

String CultureData___::get_PercentSymbol() {
  auto& default = _sPercent;
  return default != nullptr ? default : (_sPercent = GetLocaleInfoCore(LocaleStringData::PercentSymbol));
}

String CultureData___::get_PerMilleSymbol() {
  auto& default = _sPerMille;
  return default != nullptr ? default : (_sPerMille = GetLocaleInfoCore(LocaleStringData::PerMilleSymbol));
}

String CultureData___::get_CurrencySymbol() {
  auto& default = _sCurrency;
  return default != nullptr ? default : (_sCurrency = GetLocaleInfoCore(LocaleStringData::MonetarySymbol));
}

String CultureData___::get_ISOCurrencySymbol() {
  auto& default = _sIntlMonetarySymbol;
  return default != nullptr ? default : (_sIntlMonetarySymbol = GetLocaleInfoCore(LocaleStringData::Iso4217MonetarySymbol));
}

String CultureData___::get_CurrencyEnglishName() {
  auto& default = _sEnglishCurrency;
  return default != nullptr ? default : (_sEnglishCurrency = GetLocaleInfoCore(LocaleStringData::CurrencyEnglishName));
}

String CultureData___::get_CurrencyNativeName() {
  auto& default = _sNativeCurrency;
  return default != nullptr ? default : (_sNativeCurrency = GetLocaleInfoCore(LocaleStringData::CurrencyNativeName));
}

Array<Int32> CultureData___::get_CurrencyGroupSizes() {
  auto& default = _waMonetaryGrouping;
  return default != nullptr ? default : (_waMonetaryGrouping = GetLocaleInfoCore(LocaleGroupingData::Monetary));
}

Int32 CultureData___::get_MeasurementSystem() {
  if (_iMeasure == -1) {
    _iMeasure = GetLocaleInfoCore(LocaleNumberData::MeasurementSystem);
  }
  return _iMeasure;
}

String CultureData___::get_ListSeparator() {
  auto& default = _sListSeparator;
  return default != nullptr ? default : (_sListSeparator = GetLocaleInfoCore(LocaleStringData::ListSeparator));
}

String CultureData___::get_AMDesignator() {
  auto& default = _sAM1159;
  return default != nullptr ? default : (_sAM1159 = GetLocaleInfoCore(LocaleStringData::AMDesignator));
}

String CultureData___::get_PMDesignator() {
  auto& default = _sPM2359;
  return default != nullptr ? default : (_sPM2359 = GetLocaleInfoCore(LocaleStringData::PMDesignator));
}

Array<String> CultureData___::get_LongTimes() {
  if (_saLongTimes == nullptr) {
    Array<String> array = GlobalizationMode::get_UseNls() ? NlsGetTimeFormats() : IcuGetTimeFormats();
    if (array == nullptr || array->get_Length() == 0) {
      _saLongTimes = get_Invariant()->_saLongTimes;
    } else {
      _saLongTimes = array;
    }
  }
  return _saLongTimes;
}

Array<String> CultureData___::get_ShortTimes() {
  if (_saShortTimes == nullptr) {
    Array<String> array = GlobalizationMode::get_UseNls() ? NlsGetShortTimeFormats() : IcuGetShortTimeFormats();
    if (array == nullptr || array->get_Length() == 0) {
      array = DeriveShortTimesFromLong();
    }
    _saShortTimes = array;
  }
  return _saShortTimes;
}

Int32 CultureData___::get_FirstDayOfWeek() {
  if (_iFirstDayOfWeek == -1) {
    _iFirstDayOfWeek = (GlobalizationMode::get_UseNls() ? NlsGetFirstDayOfWeek() : IcuGetFirstDayOfWeek());
  }
  return _iFirstDayOfWeek;
}

Int32 CultureData___::get_CalendarWeekRule() {
  if (_iFirstWeekOfYear == -1) {
    _iFirstWeekOfYear = GetLocaleInfoCore(LocaleNumberData::FirstWeekOfYear);
  }
  return _iFirstWeekOfYear;
}

Array<CalendarId> CultureData___::get_CalendarIds() {
  if (_waCalendars == nullptr) {
    Array<CalendarId> array = rt::newarr<Array<CalendarId>>(23);
    Int32 num = GlobalizationMode::get_UseNls() ? CalendarData::in::NlsGetCalendars(_sWindowsName, _bUseOverrides, array) : CalendarData::in::IcuGetCalendars(_sWindowsName, _bUseOverrides, array);
    if (num == 0) {
      _waCalendars = get_Invariant()->_waCalendars;
    } else {
      if (_sWindowsName == "zh-TW") {
        Boolean flag = false;
        for (Int32 i = 0; i < num; i++) {
          if (array[i] == CalendarId::TAIWAN) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          num++;
          Array<>::in::Copy(array, 1, array, 2, 21);
          array[1] = CalendarId::TAIWAN;
        }
      }
      Array<CalendarId> array2 = rt::newarr<Array<CalendarId>>(num);
      Array<>::in::Copy(array, array2, num);
      if (array2->get_Length() > 1) {
        CalendarId calendarId = (CalendarId)GetLocaleInfoCore(LocaleNumberData::CalendarType);
        if (array2[1] == calendarId) {
          array2[1] = array2[0];
          array2[0] = calendarId;
        }
      }
      _waCalendars = array2;
    }
  }
  return _waCalendars;
}

Boolean CultureData___::get_IsRightToLeft() {
  return get_ReadingLayout() == 1;
}

Int32 CultureData___::get_ReadingLayout() {
  if (_iReadingLayout == -1) {
    _iReadingLayout = GetLocaleInfoCore(LocaleNumberData::ReadingLayout);
  }
  return _iReadingLayout;
}

String CultureData___::get_TextInfoName() {
  return _sRealName;
}

String CultureData___::get_SortName() {
  return _sRealName;
}

Boolean CultureData___::get_IsSupplementalCustomCulture() {
  return IsCustomCultureId(get_LCID());
}

Int32 CultureData___::get_ANSICodePage() {
  if (_iDefaultAnsiCodePage == -1) {
    _iDefaultAnsiCodePage = (GlobalizationMode::get_UseNls() ? NlsGetAnsiCodePage(_sRealName) : IcuGetAnsiCodePage(_sRealName));
  }
  return _iDefaultAnsiCodePage;
}

Int32 CultureData___::get_OEMCodePage() {
  if (_iDefaultOemCodePage == -1) {
    _iDefaultOemCodePage = (GlobalizationMode::get_UseNls() ? NlsGetOemCodePage(_sRealName) : IcuGetOemCodePage(_sRealName));
  }
  return _iDefaultOemCodePage;
}

Int32 CultureData___::get_MacCodePage() {
  if (_iDefaultMacCodePage == -1) {
    _iDefaultMacCodePage = (GlobalizationMode::get_UseNls() ? NlsGetMacCodePage(_sRealName) : IcuGetMacCodePage(_sRealName));
  }
  return _iDefaultMacCodePage;
}

Int32 CultureData___::get_EBCDICCodePage() {
  if (_iDefaultEbcdicCodePage == -1) {
    _iDefaultEbcdicCodePage = (GlobalizationMode::get_UseNls() ? NlsGetEbcdicCodePage(_sRealName) : IcuGetEbcdicCodePage(_sRealName));
  }
  return _iDefaultEbcdicCodePage;
}

Int32 CultureData___::get_LCID() {
  if (_iLanguage == 0) {
    _iLanguage = (GlobalizationMode::get_UseNls() ? NlsLocaleNameToLCID(_sRealName) : IcuLocaleNameToLCID(_sRealName));
  }
  return _iLanguage;
}

Boolean CultureData___::get_IsNeutralCulture() {
  return _bNeutral;
}

Boolean CultureData___::get_IsInvariantCulture() {
  return String::in::IsNullOrEmpty(get_Name());
}

Boolean CultureData___::get_IsReplacementCulture() {
  if (!GlobalizationMode::get_UseNls()) {
    return false;
  }
  return get_NlsIsReplacementCulture();
}

Calendar CultureData___::get_DefaultCalendar() {
  if (GlobalizationMode::get_Invariant()) {
    return CultureInfo::in::GetCalendarInstance(get_CalendarIds()[0]);
  }
  CalendarId calendarId = (CalendarId)GetLocaleInfoCore(LocaleNumberData::CalendarType);
  if (calendarId == CalendarId::UNINITIALIZED_VALUE) {
    calendarId = get_CalendarIds()[0];
  }
  return CultureInfo::in::GetCalendarInstance(calendarId);
}

String CultureData___::get_TimeSeparator() {
  if (_sTimeSeparator == nullptr) {
    String text = GlobalizationMode::get_UseNls() ? NlsGetTimeFormatString() : IcuGetTimeFormatString();
    if (String::in::IsNullOrEmpty(text)) {
      text = get_LongTimes()[0];
    }
    _sTimeSeparator = GetTimeSeparator(text);
  }
  return _sTimeSeparator;
}

Boolean CultureData___::get_NlsIsReplacementCulture() {
  EnumData value = EnumData();
  value.strings = rt::newobj<List<String>>();
  Interop::Kernel32::EnumSystemLocalesEx(EnumAllSystemLocalesProc, 8u, Unsafe::AsPointer(value), IntPtr::Zero);
  for (Int32 i = 0; i < value.strings->get_Count(); i++) {
    if (String::in::Equals(value.strings[i], _sWindowsName, StringComparison::OrdinalIgnoreCase)) {
      return true;
    }
  }
  return false;
}

Boolean CultureData___::get_IsWin32Installed() {
  return true;
}

CultureData CultureData___::GetCultureDataForRegion(String cultureName, Boolean useUserOverride) {
  if (String::in::IsNullOrEmpty(cultureName)) {
    return get_Invariant();
  }
  CultureData value = GetCultureData(cultureName, useUserOverride);
  if (value != nullptr && !value->get_IsNeutralCulture()) {
    return value;
  }
  CultureData cultureData = value;
  String key = AnsiToLower(useUserOverride ? cultureName : (cultureName + "*"));
  Dictionary<String, CultureData> dictionary = s_cachedRegions;
  if (dictionary == nullptr) {
    dictionary = rt::newobj<Dictionary<String, CultureData>>();
  } else {
    {
      rt::lock(s_lock);
      dictionary->TryGetValue(key, value);
    }
    if (value != nullptr) {
      return value;
    }
  }
  String value2;
  if ((value == nullptr || value->get_IsNeutralCulture()) && get_RegionNames()->TryGetValue(cultureName, value2)) {
    value = GetCultureData(value2, useUserOverride);
  }
  if (!GlobalizationMode::get_Invariant() && (value == nullptr || value->get_IsNeutralCulture())) {
    value = (GlobalizationMode::get_UseNls() ? NlsGetCultureDataFromRegionName(cultureName) : IcuGetCultureDataFromRegionName(cultureName));
  }
  if (value != nullptr && !value->get_IsNeutralCulture()) {
    {
      rt::lock(s_lock);
      dictionary[key] = value;
    }
    s_cachedRegions = dictionary;
  } else {
    value = cultureData;
  }
  return value;
}

void CultureData___::ClearCachedData() {
  s_cachedCultures = nullptr;
  s_cachedRegions = nullptr;
}

Array<CultureInfo> CultureData___::GetCultures(CultureTypes types) {
  if (types <= (CultureTypes)0 || (types & ~(CultureTypes::NeutralCultures | CultureTypes::SpecificCultures | CultureTypes::InstalledWin32Cultures | CultureTypes::UserCustomCulture | CultureTypes::ReplacementCultures | CultureTypes::WindowsOnlyCultures | CultureTypes::FrameworkCultures)) != 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("types", SR::Format(SR::get_ArgumentOutOfRange_Range(), CultureTypes::NeutralCultures, CultureTypes::FrameworkCultures));
  }
  if ((types & CultureTypes::WindowsOnlyCultures) != 0) {
    types &= ~CultureTypes::WindowsOnlyCultures;
  }
  if (GlobalizationMode::get_Invariant()) {
    return rt::newarr<Array<CultureInfo>>(1);
  }
  if (!GlobalizationMode::get_UseNls()) {
    return IcuEnumCultures(types);
  }
  return NlsEnumCultures(types);
}

CultureData CultureData___::CreateCultureWithInvariantData() {
  CultureData cultureData = rt::newobj<CultureData>();
  cultureData->_bUseOverrides = false;
  cultureData->_sRealName = "";
  cultureData->_sWindowsName = "";
  cultureData->_sName = "";
  cultureData->_sParent = "";
  cultureData->_bNeutral = false;
  cultureData->_sEnglishDisplayName = "Invariant Language (Invariant Country)";
  cultureData->_sNativeDisplayName = "Invariant Language (Invariant Country)";
  cultureData->_sSpecificCulture = "";
  cultureData->_sISO639Language = "iv";
  cultureData->_sISO639Language2 = "ivl";
  cultureData->_sLocalizedLanguage = "Invariant Language";
  cultureData->_sEnglishLanguage = "Invariant Language";
  cultureData->_sNativeLanguage = "Invariant Language";
  cultureData->_sAbbrevLang = "IVL";
  cultureData->_sConsoleFallbackName = "";
  cultureData->_iInputLanguageHandle = 127;
  cultureData->_sRegionName = "IV";
  cultureData->_sEnglishCountry = "Invariant Country";
  cultureData->_sNativeCountry = "Invariant Country";
  cultureData->_sISO3166CountryName = "IV";
  cultureData->_sISO3166CountryName2 = "ivc";
  cultureData->_iGeoId = 244;
  cultureData->_sPositiveSign = "+";
  cultureData->_sNegativeSign = "-";
  cultureData->_iDigits = 2;
  cultureData->_iNegativeNumber = 1;
  cultureData->_waGrouping = rt::newarr<Array<Int32>>(1);
  cultureData->_sDecimalSeparator = ".";
  cultureData->_sThousandSeparator = ",";
  cultureData->_sNaN = "NaN";
  cultureData->_sPositiveInfinity = "Infinity";
  cultureData->_sNegativeInfinity = "-Infinity";
  cultureData->_iNegativePercent = 0;
  cultureData->_iPositivePercent = 0;
  cultureData->_sPercent = "%";
  cultureData->_sPerMille = "‰";
  cultureData->_sCurrency = "¤";
  cultureData->_sIntlMonetarySymbol = "XDR";
  cultureData->_sEnglishCurrency = "International Monetary Fund";
  cultureData->_sNativeCurrency = "International Monetary Fund";
  cultureData->_iCurrencyDigits = 2;
  cultureData->_iCurrency = 0;
  cultureData->_iNegativeCurrency = 0;
  cultureData->_waMonetaryGrouping = rt::newarr<Array<Int32>>(1);
  cultureData->_sMonetaryDecimal = ".";
  cultureData->_sMonetaryThousand = ",";
  cultureData->_iMeasure = 0;
  cultureData->_sListSeparator = ",";
  cultureData->_sTimeSeparator = ":";
  cultureData->_sAM1159 = "AM";
  cultureData->_sPM2359 = "PM";
  cultureData->_saLongTimes = rt::newarr<Array<String>>(1);
  cultureData->_saShortTimes = rt::newarr<Array<String>>(4);
  cultureData->_saDurationFormats = rt::newarr<Array<String>>(1);
  cultureData->_iFirstDayOfWeek = 0;
  cultureData->_iFirstWeekOfYear = 0;
  cultureData->_waCalendars = rt::newarr<Array<CalendarId>>(1);
  cultureData->_calendars = rt::newarr<Array<CalendarData>>(23);
  cultureData->_calendars[0] = CalendarData::in::Invariant;
  cultureData->_iReadingLayout = 0;
  cultureData->_iLanguage = 127;
  cultureData->_iDefaultAnsiCodePage = 1252;
  cultureData->_iDefaultOemCodePage = 437;
  cultureData->_iDefaultMacCodePage = 10000;
  cultureData->_iDefaultEbcdicCodePage = 37;
  if (GlobalizationMode::get_Invariant()) {
    cultureData->_sLocalizedDisplayName = cultureData->_sNativeDisplayName;
    cultureData->_sLocalizedCountry = cultureData->_sNativeCountry;
  }
  return cultureData;
}

CultureData CultureData___::GetCultureData(String cultureName, Boolean useUserOverride) {
  if (String::in::IsNullOrEmpty(cultureName)) {
    return get_Invariant();
  }
  String key = AnsiToLower(useUserOverride ? cultureName : (cultureName + "*"));
  Dictionary<String, CultureData> dictionary = s_cachedCultures;
  if (dictionary == nullptr) {
    dictionary = rt::newobj<Dictionary<String, CultureData>>();
  } else {
    Boolean flag;
    CultureData value;
    {
      rt::lock(s_lock);
      flag = dictionary->TryGetValue(key, value);
    }
    if (flag && value != nullptr) {
      return value;
    }
  }
  CultureData cultureData = CreateCultureData(cultureName, useUserOverride);
  if (cultureData == nullptr) {
    return nullptr;
  }
  {
    rt::lock(s_lock);
    dictionary[key] = cultureData;
  }
  s_cachedCultures = dictionary;
  return cultureData;
}

String CultureData___::NormalizeCultureName(String name, Boolean& isNeutralName) {
  isNeutralName = true;
  Int32 i = 0;
  if (name->get_Length() > 85) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidId(), "name"));
  }
  Char default[name->get_Length()] = {};
  Span<Char> span = default;
  Boolean flag = false;
  for (; i < name->get_Length() && name[i] != 45 && name[i] != 95; i++) {
    if (name[i] >= 65 && name[i] <= 90) {
      span[i] = (Char)(name[i] + 32);
      flag = true;
    } else {
      span[i] = name[i];
    }
  }
  if (i < name->get_Length()) {
    isNeutralName = false;
  }
  for (; i < name->get_Length(); i++) {
    if (name[i] >= 97 && name[i] <= 122) {
      span[i] = (Char)(name[i] - 32);
      flag = true;
    } else {
      span[i] = name[i];
    }
  }
  if (flag) {
    return rt::newobj<String>(span);
  }
  return name;
}

CultureData CultureData___::CreateCultureData(String cultureName, Boolean useUserOverride) {
  if (GlobalizationMode::get_Invariant()) {
    if (cultureName->get_Length() > 85 || !CultureInfo::in::VerifyCultureName(cultureName, false)) {
      return nullptr;
    }
    CultureData cultureData = CreateCultureWithInvariantData();
    cultureData->_bUseOverrides = useUserOverride;
    cultureData->_sName = NormalizeCultureName(cultureName, cultureData->_bNeutral);
    cultureData->_sRealName = cultureData->_sName;
    cultureData->_sWindowsName = cultureData->_sName;
    cultureData->_iLanguage = 4096;
    return cultureData;
  }
  if (cultureName->get_Length() == 1 && (cultureName[0] == 67 || cultureName[0] == 99)) {
    return get_Invariant();
  }
  CultureData cultureData2 = rt::newobj<CultureData>();
  cultureData2->_bUseOverrides = useUserOverride;
  cultureData2->_sRealName = cultureName;
  if (!cultureData2->InitCultureDataCore() && !cultureData2->InitCompatibilityCultureData()) {
    return nullptr;
  }
  return cultureData2;
}

Boolean CultureData___::InitCompatibilityCultureData() {
  String sRealName = _sRealName;
  String a = AnsiToLower(sRealName);
  String text;
  String sName;
  if (!(a == "zh-chs")) {
    if (!(a == "zh-cht")) {
      return false;
    }
    text = "zh-Hant";
    sName = "zh-CHT";
  } else {
    text = "zh-Hans";
    sName = "zh-CHS";
  }
  _sRealName = text;
  if (!InitCultureDataCore()) {
    return false;
  }
  _sName = sName;
  _sParent = text;
  return true;
}

CultureData CultureData___::GetCultureData(Int32 culture, Boolean bUseUserOverride) {
  String text = nullptr;
  CultureData cultureData = nullptr;
  if (culture == 127) {
    return get_Invariant();
  }
  if (GlobalizationMode::get_Invariant()) {
    rt::throw_exception<CultureNotFoundException>("culture", culture, SR::get_Argument_CultureNotSupported());
  }
  text = (GlobalizationMode::get_UseNls() ? NlsLCIDToLocaleName(culture) : IcuLCIDToLocaleName(culture));
  if (!String::in::IsNullOrEmpty(text)) {
    cultureData = GetCultureData(text, bUseUserOverride);
  }
  if (cultureData == nullptr) {
    rt::throw_exception<CultureNotFoundException>("culture", culture, SR::get_Argument_CultureNotSupported());
  }
  return cultureData;
}

String CultureData___::GetLanguageDisplayNameCore(String cultureName) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetLanguageDisplayName(cultureName);
  }
  return NlsGetLanguageDisplayName(cultureName);
}

Array<String> CultureData___::DeriveShortTimesFromLong() {
  Array<String> longTimes = get_LongTimes();
  Array<String> array = rt::newarr<Array<String>>(longTimes->get_Length());
  for (Int32 i = 0; i < longTimes->get_Length(); i++) {
    array[i] = StripSecondsFromPattern(longTimes[i]);
  }
  return array;
}

String CultureData___::StripSecondsFromPattern(String time) {
  Boolean flag = false;
  Int32 num = -1;
  for (Int32 i = 0; i < time->get_Length(); i++) {
    if (time[i] == 39) {
      flag = !flag;
    } else if (time[i] == 92) {
      i++;
    } else {
      if (flag) {
        continue;
      }
      switch (time[i].get()) {
        case 115:
          {
            if (i - num <= 4 && i - num > 1 && time[num + 1] != 39 && time[i - 1] != 39 && num >= 0) {
              i = num + 1;
            }
            Boolean containsSpace;
            Int32 indexOfNextTokenAfterSeconds = GetIndexOfNextTokenAfterSeconds(time, i, containsSpace);
            String value = (!containsSpace) ? "" : " ";
            time = String::in::Concat(MemoryExtensions::AsSpan(time, 0, i), value, MemoryExtensions::AsSpan(time, indexOfNextTokenAfterSeconds));
            break;
          }case 72:
        case 104:
        case 109:
          num = i;
          break;
      }
    }

  }
  return time;
}

Int32 CultureData___::GetIndexOfNextTokenAfterSeconds(String time, Int32 index, Boolean& containsSpace) {
  Boolean flag = false;
  containsSpace = false;
  while (index < time->get_Length()) {
    switch (time[index].get()) {
      case 39:
        flag = !flag;
        break;
      case 92:
        index++;
        if (time[index] == 32) {
          containsSpace = true;
        }
        break;
      case 32:
        containsSpace = true;
        break;
      case 72:
      case 104:
      case 109:
      case 116:
        if (!flag) {
          return index;
        }
        break;
    }
    index++;
  }
  containsSpace = false;
  return index;
}

Array<String> CultureData___::ShortDates(CalendarId calendarId) {
  return GetCalendar(calendarId)->saShortDates;
}

Array<String> CultureData___::LongDates(CalendarId calendarId) {
  return GetCalendar(calendarId)->saLongDates;
}

Array<String> CultureData___::YearMonths(CalendarId calendarId) {
  return GetCalendar(calendarId)->saYearMonths;
}

Array<String> CultureData___::DayNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saDayNames;
}

Array<String> CultureData___::AbbreviatedDayNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saAbbrevDayNames;
}

Array<String> CultureData___::SuperShortDayNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saSuperShortDayNames;
}

Array<String> CultureData___::MonthNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saMonthNames;
}

Array<String> CultureData___::GenitiveMonthNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saMonthGenitiveNames;
}

Array<String> CultureData___::AbbreviatedMonthNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saAbbrevMonthNames;
}

Array<String> CultureData___::AbbreviatedGenitiveMonthNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saAbbrevMonthGenitiveNames;
}

Array<String> CultureData___::LeapYearMonthNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saLeapYearMonthNames;
}

String CultureData___::MonthDay(CalendarId calendarId) {
  return GetCalendar(calendarId)->sMonthDay;
}

String CultureData___::CalendarName(CalendarId calendarId) {
  return GetCalendar(calendarId)->sNativeName;
}

CalendarData CultureData___::GetCalendar(CalendarId calendarId) {
  Int32 num = (Int32)(calendarId - 1);
  if (_calendars == nullptr) {
    _calendars = rt::newarr<Array<CalendarData>>(23);
  }
  CalendarData calendarData = _calendars[num];
  if (calendarData == nullptr) {
    calendarData = rt::newobj<CalendarData>(_sWindowsName, calendarId, get_UseUserOverride());
    _calendars[num] = calendarData;
  }
  return calendarData;
}

Array<String> CultureData___::EraNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saEraNames;
}

Array<String> CultureData___::AbbrevEraNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saAbbrevEraNames;
}

Array<String> CultureData___::AbbreviatedEnglishEraNames(CalendarId calendarId) {
  return GetCalendar(calendarId)->saAbbrevEnglishEraNames;
}

String CultureData___::DateSeparator(CalendarId calendarId) {
  if (calendarId == CalendarId::JAPAN && !LocalAppContextSwitches::get_EnforceLegacyJapaneseDateParsing()) {
    return "/";
  }
  return GetDateSeparator(ShortDates(calendarId)[0]);
}

String CultureData___::UnescapeNlsString(String str, Int32 start, Int32 end) {
  StringBuilder stringBuilder = nullptr;
  for (Int32 i = start; i < str->get_Length() && i <= end; i++) {
    auto& default = stringBuilder;
    switch (str[i].get()) {
      case 39:
        if (stringBuilder == nullptr) {
          stringBuilder = rt::newobj<StringBuilder>(str, start, i - start, str->get_Length());
        }
        break;
      case 92:
        if (stringBuilder == nullptr) {
          stringBuilder = rt::newobj<StringBuilder>(str, start, i - start, str->get_Length());
        }
        i++;
        if (i < str->get_Length()) {
          stringBuilder->Append(str[i]);
        }
        break;
      default:
        default == nullptr ? nullptr : default->Append(str[i]);
        break;
    }
  }
  if (stringBuilder == nullptr) {
    return str->Substring(start, end - start + 1);
  }
  return stringBuilder->ToString();
}

String CultureData___::GetTimeSeparator(String format) {
  return GetSeparator(format, "Hhms");
}

String CultureData___::GetDateSeparator(String format) {
  return GetSeparator(format, "dyM");
}

String CultureData___::GetSeparator(String format, String timeParts) {
  Int32 num = IndexOfTimePart(format, 0, timeParts);
  if (num != -1) {
    Char c = format[num];
    do {
      num++;
    } while (num < format->get_Length() && format[num] == c)
    Int32 num2 = num;
    if (num2 < format->get_Length()) {
      Int32 num3 = IndexOfTimePart(format, num2, timeParts);
      if (num3 != -1) {
        return UnescapeNlsString(format, num2, num3 - 1);
      }
    }
  }
  return String::in::Empty;
}

Int32 CultureData___::IndexOfTimePart(String format, Int32 startIndex, String timeParts) {
  Boolean flag = false;
  for (Int32 i = startIndex; i < format->get_Length(); i++) {
    if (!flag && timeParts->Contains(format[i])) {
      return i;
    }
    switch (format[i].get()) {
      case 92:
        if (i + 1 < format->get_Length()) {
          i++;
          Char c = format[i];
          if (c != 39 && c != 92) {
            i--;
          }
        }
        break;
      case 39:
        flag = !flag;
        break;
    }
  }
  return -1;
}

Boolean CultureData___::IsCustomCultureId(Int32 cultureId) {
  if (cultureId != 3072) {
    return cultureId == 4096;
  }
  return true;
}

void CultureData___::GetNFIValues(NumberFormatInfo nfi) {
  if (GlobalizationMode::get_Invariant() || get_IsInvariantCulture()) {
    nfi->_positiveSign = _sPositiveSign;
    nfi->_negativeSign = _sNegativeSign;
    nfi->_numberGroupSeparator = _sThousandSeparator;
    nfi->_numberDecimalSeparator = _sDecimalSeparator;
    nfi->_numberDecimalDigits = _iDigits;
    nfi->_numberNegativePattern = _iNegativeNumber;
    nfi->_currencySymbol = _sCurrency;
    nfi->_currencyGroupSeparator = _sMonetaryThousand;
    nfi->_currencyDecimalSeparator = _sMonetaryDecimal;
    nfi->_currencyDecimalDigits = _iCurrencyDigits;
    nfi->_currencyNegativePattern = _iNegativeCurrency;
    nfi->_currencyPositivePattern = _iCurrency;
  } else {
    nfi->_positiveSign = GetLocaleInfoCore(LocaleStringData::PositiveSign);
    nfi->_negativeSign = GetLocaleInfoCore(LocaleStringData::NegativeSign);
    nfi->_numberDecimalSeparator = GetLocaleInfoCore(LocaleStringData::DecimalSeparator);
    nfi->_numberGroupSeparator = GetLocaleInfoCore(LocaleStringData::ThousandSeparator);
    nfi->_currencyGroupSeparator = GetLocaleInfoCore(LocaleStringData::MonetaryThousandSeparator);
    nfi->_currencyDecimalSeparator = GetLocaleInfoCore(LocaleStringData::MonetaryDecimalSeparator);
    nfi->_currencySymbol = GetLocaleInfoCore(LocaleStringData::MonetarySymbol);
    nfi->_numberDecimalDigits = GetLocaleInfoCore(LocaleNumberData::FractionalDigitsCount);
    nfi->_currencyDecimalDigits = GetLocaleInfoCore(LocaleNumberData::MonetaryFractionalDigitsCount);
    nfi->_currencyPositivePattern = GetLocaleInfoCore(LocaleNumberData::PositiveMonetaryNumberFormat);
    nfi->_currencyNegativePattern = GetLocaleInfoCore(LocaleNumberData::NegativeMonetaryNumberFormat);
    nfi->_numberNegativePattern = GetLocaleInfoCore(LocaleNumberData::NegativeNumberFormat);
    String localeInfoCore = GetLocaleInfoCore(LocaleStringData::Digits);
    nfi->_nativeDigits = rt::newarr<Array<String>>(10);
    for (Int32 i = 0; i < nfi->_nativeDigits->get_Length(); i++) {
      nfi->_nativeDigits[i] = Char::ToString(localeInfoCore[i]);
    }
    nfi->_digitSubstitution = (GlobalizationMode::get_UseNls() ? NlsGetDigitSubstitution(_sRealName) : IcuGetDigitSubstitution(_sRealName));
  }
  nfi->_numberGroupSizes = get_NumberGroupSizes();
  nfi->_currencyGroupSizes = get_CurrencyGroupSizes();
  nfi->_percentNegativePattern = get_PercentNegativePattern();
  nfi->_percentPositivePattern = get_PercentPositivePattern();
  nfi->_percentSymbol = get_PercentSymbol();
  nfi->_perMilleSymbol = get_PerMilleSymbol();
  nfi->_negativeInfinitySymbol = get_NegativeInfinitySymbol();
  nfi->_positiveInfinitySymbol = get_PositiveInfinitySymbol();
  nfi->_nanSymbol = get_NaNSymbol();
  nfi->_percentDecimalDigits = nfi->_numberDecimalDigits;
  nfi->_percentDecimalSeparator = nfi->_numberDecimalSeparator;
  nfi->_percentGroupSizes = nfi->_numberGroupSizes;
  nfi->_percentGroupSeparator = nfi->_numberGroupSeparator;
  if (String::in::IsNullOrEmpty(nfi->_positiveSign)) {
    nfi->_positiveSign = "+";
  }
  if (String::in::IsNullOrEmpty(nfi->_currencyDecimalSeparator)) {
    nfi->_currencyDecimalSeparator = nfi->_numberDecimalSeparator;
  }
}

String CultureData___::AnsiToLower(String testString) {
  return TextInfo::in::ToLowerAsciiInvariant(testString);
}

Int32 CultureData___::GetLocaleInfoCore(LocaleNumberData type) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetLocaleInfo(type);
  }
  return NlsGetLocaleInfo(type);
}

String CultureData___::GetLocaleInfoCore(LocaleStringData type) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetLocaleInfo(type);
  }
  return NlsGetLocaleInfo(type);
}

String CultureData___::GetLocaleInfoCore(String localeName, LocaleStringData type) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetLocaleInfo(localeName, type);
  }
  return NlsGetLocaleInfo(localeName, type);
}

Array<Int32> CultureData___::GetLocaleInfoCore(LocaleGroupingData type) {
  if (!GlobalizationMode::get_UseNls()) {
    return IcuGetLocaleInfo(type);
  }
  return NlsGetLocaleInfo(type);
}

String CultureData___::IcuGetLocaleInfo(LocaleStringData type) {
  return IcuGetLocaleInfo(_sWindowsName, type);
}

String CultureData___::IcuGetLocaleInfo(String localeName, LocaleStringData type) {
  if (type == LocaleStringData::NegativeInfinitySymbol) {
    return IcuGetLocaleInfo(localeName, LocaleStringData::NegativeSign) + IcuGetLocaleInfo(localeName, LocaleStringData::PositiveInfinitySymbol);
  }
  Char default[100] = {};
  Char* value = default;
  if (!Interop::Globalization::GetLocaleInfoString(localeName, (UInt32)type, value, 100)) {
    return String::in::Empty;
  }
  return rt::newobj<String>(value);
}

Int32 CultureData___::IcuGetLocaleInfo(LocaleNumberData type) {
  if (type == LocaleNumberData::CalendarType) {
    return 0;
  }
  Int32 value = 0;
  Boolean localeInfoInt = Interop::Globalization::GetLocaleInfoInt(_sWindowsName, (UInt32)type, value);
  return value;
}

Array<Int32> CultureData___::IcuGetLocaleInfo(LocaleGroupingData type) {
  Int32 primaryGroupSize = 0;
  Int32 secondaryGroupSize = 0;
  Boolean localeInfoGroupingSizes = Interop::Globalization::GetLocaleInfoGroupingSizes(_sWindowsName, (UInt32)type, primaryGroupSize, secondaryGroupSize);
  if (secondaryGroupSize != 0) {
    return rt::newarr<Array<Int32>>(2);
  }
  return rt::newarr<Array<Int32>>(1);
}

String CultureData___::IcuGetTimeFormatString() {
  return IcuGetTimeFormatString(false);
}

String CultureData___::IcuGetTimeFormatString(Boolean shortFormat) {
  Char default[100] = {};
  Char* ptr = default;
  if (!Interop::Globalization::GetLocaleTimeFormat(_sWindowsName, shortFormat, ptr, 100)) {
    return String::in::Empty;
  }
  ReadOnlySpan<Char> span = ReadOnlySpan<Char>(ptr, 100);
  return ConvertIcuTimeFormatString(span.Slice(0, MemoryExtensions::IndexOf(span, 0)));
}

Int32 CultureData___::IcuGetFirstDayOfWeek() {
  return IcuGetLocaleInfo(LocaleNumberData::FirstDayOfWeek);
}

Array<String> CultureData___::IcuGetTimeFormats() {
  String text = IcuGetTimeFormatString(false);
  return rt::newarr<Array<String>>(1);
}

Array<String> CultureData___::IcuGetShortTimeFormats() {
  String text = IcuGetTimeFormatString(true);
  return rt::newarr<Array<String>>(1);
}

CultureData CultureData___::IcuGetCultureDataFromRegionName(String regionName) {
  return nullptr;
}

String CultureData___::IcuGetLanguageDisplayName(String cultureName) {
  return rt::newobj<CultureInfo>(cultureName)->_cultureData->IcuGetLocaleInfo(cultureName, LocaleStringData::LocalizedDisplayName);
}

String CultureData___::IcuGetRegionDisplayName() {
  return nullptr;
}

String CultureData___::ConvertIcuTimeFormatString(ReadOnlySpan<Char> icuFormatString) {
  Char default[157] = {};
  Span<Char> span = default;
  Boolean flag = false;
  Int32 length = 0;
  for (Int32 i = 0; i < icuFormatString.get_Length(); i++) {
    switch (icuFormatString[i].get()) {
      case 39:
        span[length++] = icuFormatString[i++];
        for (; i < icuFormatString.get_Length(); i++) {
          Char c = icuFormatString[i];
          span[length++] = c;
          if (c == 39) {
            break;
          }
        }
        break;
      case 46:
      case 58:
      case 72:
      case 104:
      case 109:
      case 115:
        span[length++] = icuFormatString[i];
        break;
      case 32:
      case 160:
        span[length++] = 32;
        break;
      case 97:
        if (!flag) {
          flag = true;
          span[length++] = 116;
          span[length++] = 116;
        }
        break;
    }
  }
  return span.Slice(0, length).ToString();
}

String CultureData___::IcuLCIDToLocaleName(Int32 culture) {
  return IcuLocaleData::LCIDToLocaleName(culture);
}

Int32 CultureData___::IcuLocaleNameToLCID(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::Lcid);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return 4096;
}

Int32 CultureData___::IcuGetAnsiCodePage(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::AnsiCodePage);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return get_Invariant()->get_ANSICodePage();
}

Int32 CultureData___::IcuGetOemCodePage(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::OemCodePage);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return get_Invariant()->get_OEMCodePage();
}

Int32 CultureData___::IcuGetMacCodePage(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::MacCodePage);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return get_Invariant()->get_MacCodePage();
}

Int32 CultureData___::IcuGetEbcdicCodePage(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::EbcdicCodePage);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return get_Invariant()->get_EBCDICCodePage();
}

Int32 CultureData___::IcuGetGeoId(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::GeoId);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return get_Invariant()->get_GeoId();
}

Int32 CultureData___::IcuGetDigitSubstitution(String cultureName) {
  Int32 localeDataNumericPart = IcuLocaleData::GetLocaleDataNumericPart(cultureName, IcuLocaleDataParts::DigitSubstitution);
  if (localeDataNumericPart != -1) {
    return localeDataNumericPart;
  }
  return 1;
}

String CultureData___::IcuGetThreeLetterWindowsLanguageName(String cultureName) {
  auto& default = IcuLocaleData::GetThreeLetterWindowsLanguageName(cultureName);
  return default != nullptr ? default : "ZZZ";
}

Array<CultureInfo> CultureData___::IcuEnumCultures(CultureTypes types) {
  if ((types & (CultureTypes::NeutralCultures | CultureTypes::SpecificCultures)) == 0) {
    return Array<>::in::Empty<CultureInfo>();
  }
  Int32 locales = Interop::Globalization::GetLocales(nullptr, 0);
  if (locales <= 0) {
    return Array<>::in::Empty<CultureInfo>();
  }
  Array<Char> array = rt::newarr<Array<Char>>(locales);
  locales = Interop::Globalization::GetLocales(array, locales);
  if (locales <= 0) {
    return Array<>::in::Empty<CultureInfo>();
  }
  Boolean flag = (types & CultureTypes::NeutralCultures) != 0;
  Boolean flag2 = (types & CultureTypes::SpecificCultures) != 0;
  List<CultureInfo> list = rt::newobj<List<CultureInfo>>();
  if (flag) {
    list->Add(CultureInfo::in::get_InvariantCulture());
  }
  Int32 num;
  for (Int32 i = 0; i < locales; i += num) {
    num = array[i++];
    if (i + num <= locales) {
      CultureInfo cultureInfo = CultureInfo::in::GetCultureInfo(rt::newobj<String>(array, i, num));
      if ((flag && cultureInfo->get_IsNeutralCulture()) || (flag2 && !cultureInfo->get_IsNeutralCulture())) {
        list->Add(cultureInfo);
      }
    }
  }
  return list->ToArray();
}

String CultureData___::IcuGetConsoleFallbackName(String cultureName) {
  return IcuLocaleData::GetConsoleUICulture(cultureName);
}

String CultureData___::GetLocaleInfoEx(String localeName, UInt32 field) {
  Char default[530] = {};
  Char* ptr = default;
  Int32 localeInfoEx = GetLocaleInfoEx(localeName, field, ptr, 530);
  if (localeInfoEx > 0) {
    return rt::newobj<String>(ptr);
  }
  return nullptr;
}

Int32 CultureData___::GetLocaleInfoExInt(String localeName, UInt32 field) {
  field |= 536870912;
  Int32 result = 0;
  GetLocaleInfoEx(localeName, field, (Char*)(&result), 4);
  return result;
}

Int32 CultureData___::GetLocaleInfoEx(String lpLocaleName, UInt32 lcType, Char* lpLCData, Int32 cchData) {
  return Interop::Kernel32::GetLocaleInfoEx(lpLocaleName, lcType, lpLCData, cchData);
}

String CultureData___::NlsGetLocaleInfo(LocaleStringData type) {
  return NlsGetLocaleInfo(_sWindowsName, type);
}

String CultureData___::NlsGetLocaleInfo(String localeName, LocaleStringData type) {
  return GetLocaleInfoFromLCType(localeName, (UInt32)type, get_UseUserOverride());
}

Int32 CultureData___::NlsGetLocaleInfo(LocaleNumberData type) {
  UInt32 num = (UInt32)type;
  if (!get_UseUserOverride()) {
    num |= 2147483648u;
  }
  return GetLocaleInfoExInt(_sWindowsName, num);
}

Array<Int32> CultureData___::NlsGetLocaleInfo(LocaleGroupingData type) {
  return ConvertWin32GroupString(GetLocaleInfoFromLCType(_sWindowsName, (UInt32)type, get_UseUserOverride()));
}

String CultureData___::NlsGetTimeFormatString() {
  return ReescapeWin32String(GetLocaleInfoFromLCType(_sWindowsName, 4099u, get_UseUserOverride()));
}

Int32 CultureData___::NlsGetFirstDayOfWeek() {
  Int32 localeInfoExInt = GetLocaleInfoExInt(_sWindowsName, (UInt32)(4108 | ((!get_UseUserOverride()) ? Int32::MinValue : 0)));
  return ConvertFirstDayOfWeekMonToSun(localeInfoExInt);
}

Array<String> CultureData___::NlsGetTimeFormats() {
  return ReescapeWin32Strings(nativeEnumTimeFormats(_sWindowsName, 0u, get_UseUserOverride()));
}

Array<String> CultureData___::NlsGetShortTimeFormats() {
  return ReescapeWin32Strings(nativeEnumTimeFormats(_sWindowsName, 2u, get_UseUserOverride()));
}

CultureData CultureData___::NlsGetCultureDataFromRegionName(String regionName) {
  EnumLocaleData value;
  value.cultureName = nullptr;
  value.regionName = regionName;
  Interop::Kernel32::EnumSystemLocalesEx(EnumSystemLocalesProc, 34u, Unsafe::AsPointer(value), IntPtr::Zero);
  if (value.cultureName != nullptr) {
    return GetCultureData(value.cultureName, true);
  }
  return nullptr;
}

String CultureData___::NlsGetLanguageDisplayName(String cultureName) {
  CultureInfo userDefaultCulture;
  if (CultureInfo::in::get_DefaultThreadCurrentUICulture() != nullptr && (userDefaultCulture = CultureInfo::in::GetUserDefaultCulture()) != nullptr && !CultureInfo::in::get_DefaultThreadCurrentUICulture()->get_Name()->Equals(userDefaultCulture->get_Name())) {
    return get_NativeName();
  }
  return NlsGetLocaleInfo(cultureName, LocaleStringData::LocalizedDisplayName);
}

String CultureData___::NlsGetRegionDisplayName() {
  if (CultureInfo::in::get_CurrentUICulture()->get_Name()->Equals(CultureInfo::in::get_UserDefaultUICulture()->get_Name())) {
    return NlsGetLocaleInfo(LocaleStringData::LocalizedCountryName);
  }
  return get_NativeCountryName();
}

String CultureData___::GetLocaleInfoFromLCType(String localeName, UInt32 lctype, Boolean useUserOveride) {
  if (!useUserOveride) {
    lctype |= 2147483648u;
  }
  auto& default = GetLocaleInfoEx(localeName, lctype);
  return default != nullptr ? default : String::in::Empty;
}

String CultureData___::ReescapeWin32String(String str) {
  if (str == nullptr) {
    return nullptr;
  }
  StringBuilder stringBuilder = nullptr;
  Boolean flag = false;
  for (Int32 i = 0; i < str->get_Length(); i++) {
    if (str[i] == 39) {
      if (flag) {
        if (i + 1 < str->get_Length() && str[i + 1] == 39) {
          if (stringBuilder == nullptr) {
            stringBuilder = rt::newobj<StringBuilder>(str, 0, i, str->get_Length() * 2);
          }
          stringBuilder->Append("\'");
          i++;
          continue;
        }
        flag = false;
      } else {
        flag = true;
      }
    } else if (str[i] == 92) {
      if (stringBuilder == nullptr) {
        stringBuilder = rt::newobj<StringBuilder>(str, 0, i, str->get_Length() * 2);
      }
      stringBuilder->Append("\\");
      continue;
    }

    auto& default = stringBuilder;
    default == nullptr ? nullptr : default->Append(str[i]);
  }
  if (stringBuilder == nullptr) {
    return str;
  }
  return stringBuilder->ToString();
}

Array<String> CultureData___::ReescapeWin32Strings(Array<String> array) {
  if (array != nullptr) {
    for (Int32 i = 0; i < array->get_Length(); i++) {
      array[i] = ReescapeWin32String(array[i]);
    }
  }
  return array;
}

Array<Int32> CultureData___::ConvertWin32GroupString(String win32Str) {
  if (String::in::IsNullOrEmpty(win32Str)) {
    return rt::newarr<Array<Int32>>(1);
  }
  if (win32Str[0] == 48) {
    return rt::newarr<Array<Int32>>(1);
  }
  Array<Int32> array;
}

Int32 CultureData___::ConvertFirstDayOfWeekMonToSun(Int32 iTemp) {
  iTemp++;
  if (iTemp > 6) {
    iTemp = 0;
  }
  return iTemp;
}

Interop::BOOL CultureData___::EnumSystemLocalesProc(Char* lpLocaleString, UInt32 flags, void* contextHandle) {
  EnumLocaleData& reference = Unsafe::As<Byte, EnumLocaleData>(*(Byte*)contextHandle);
  try {
    String text = rt::newobj<String>(lpLocaleString);
    String localeInfoEx = GetLocaleInfoEx(text, 90u);
    if (localeInfoEx != nullptr && localeInfoEx->Equals(reference.regionName, StringComparison::OrdinalIgnoreCase)) {
      reference.cultureName = text;
      return Interop::BOOL::FALSE;
    }
    return Interop::BOOL::TRUE;
  } catch (Exception) {
  }
}

Interop::BOOL CultureData___::EnumAllSystemLocalesProc(Char* lpLocaleString, UInt32 flags, void* contextHandle) {
  EnumData& reference = Unsafe::As<Byte, EnumData>(*(Byte*)contextHandle);
  try {
    reference.strings->Add(rt::newobj<String>(lpLocaleString));
    return Interop::BOOL::TRUE;
  } catch (Exception) {
  }
}

Interop::BOOL CultureData___::EnumTimeCallback(Char* lpTimeFormatString, void* lParam) {
  EnumData& reference = Unsafe::As<Byte, EnumData>(*(Byte*)lParam);
  try {
    reference.strings->Add(rt::newobj<String>(lpTimeFormatString));
    return Interop::BOOL::TRUE;
  } catch (Exception) {
  }
}

Array<String> CultureData___::nativeEnumTimeFormats(String localeName, UInt32 dwFlags, Boolean useUserOverride) {
  EnumData value = EnumData();
  value.strings = rt::newobj<List<String>>();
  Interop::Kernel32::EnumTimeFormatsEx(EnumTimeCallback, localeName, dwFlags, Unsafe::AsPointer(value));
  if (value.strings->get_Count() > 0) {
    Array<String> array = value.strings->ToArray();
    if (!useUserOverride && value.strings->get_Count() > 1) {
      UInt32 lctype = (dwFlags == 2) ? 121u : 4099u;
      String localeInfoFromLCType = GetLocaleInfoFromLCType(localeName, lctype, useUserOverride);
      if (localeInfoFromLCType != "") {
        String text = array[0];
        if (localeInfoFromLCType != text) {
          array[0] = array[1];
          array[1] = text;
        }
      }
    }
    return array;
  }
  return nullptr;
}

Int32 CultureData___::NlsLocaleNameToLCID(String cultureName) {
  return Interop::Kernel32::LocaleNameToLCID(cultureName, 134217728u);
}

String CultureData___::NlsLCIDToLocaleName(Int32 culture) {
  Char default[86] = {};
  Char* ptr = default;
  Int32 num = Interop::Kernel32::LCIDToLocaleName(culture, ptr, 86, 134217728u);
  if (num > 0) {
    return rt::newobj<String>(ptr);
  }
  return nullptr;
}

Int32 CultureData___::NlsGetAnsiCodePage(String cultureName) {
  return NlsGetLocaleInfo(LocaleNumberData::AnsiCodePage);
}

Int32 CultureData___::NlsGetOemCodePage(String cultureName) {
  return NlsGetLocaleInfo(LocaleNumberData::OemCodePage);
}

Int32 CultureData___::NlsGetMacCodePage(String cultureName) {
  return NlsGetLocaleInfo(LocaleNumberData::MacCodePage);
}

Int32 CultureData___::NlsGetEbcdicCodePage(String cultureName) {
  return NlsGetLocaleInfo(LocaleNumberData::EbcdicCodePage);
}

Int32 CultureData___::NlsGetGeoId(String cultureName) {
  return NlsGetLocaleInfo(LocaleNumberData::GeoId);
}

Int32 CultureData___::NlsGetDigitSubstitution(String cultureName) {
  return NlsGetLocaleInfo(LocaleNumberData::DigitSubstitution);
}

String CultureData___::NlsGetThreeLetterWindowsLanguageName(String cultureName) {
  return NlsGetLocaleInfo(cultureName, LocaleStringData::AbbreviatedWindowsLanguageName);
}

Array<CultureInfo> CultureData___::NlsEnumCultures(CultureTypes types) {
  UInt32 num = 0u;
  if ((types & (CultureTypes::InstalledWin32Cultures | CultureTypes::ReplacementCultures | CultureTypes::FrameworkCultures)) != 0) {
    num |= 48;
  }
  if ((types & CultureTypes::NeutralCultures) != 0) {
    num |= 16;
  }
  if ((types & CultureTypes::SpecificCultures) != 0) {
    num |= 32;
  }
  if ((types & CultureTypes::UserCustomCulture) != 0) {
    num |= 2;
  }
  if ((types & CultureTypes::ReplacementCultures) != 0) {
    num |= 2;
  }
  EnumData value = EnumData();
  value.strings = rt::newobj<List<String>>();
  Interop::Kernel32::EnumSystemLocalesEx(EnumAllSystemLocalesProc, num, Unsafe::AsPointer(value), IntPtr::Zero);
  Array<CultureInfo> array = rt::newarr<Array<CultureInfo>>(value.strings->get_Count());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = rt::newobj<CultureInfo>(value.strings[i]);
  }
  return array;
}

String CultureData___::NlsGetConsoleFallbackName(String cultureName) {
  return NlsGetLocaleInfo(cultureName, LocaleStringData::ConsoleFallbackName);
}

Boolean CultureData___::InitCultureDataCore() {
  String sRealName = _sRealName;
  Char default[85] = {};
  Char* ptr = default;
  Int32 localeInfoEx = GetLocaleInfoEx(sRealName, 92u, ptr, 85);
  if (localeInfoEx == 0) {
    return false;
  }
  _sRealName = rt::newobj<String>(ptr, 0, localeInfoEx - 1);
  sRealName = _sRealName;
  if (GetLocaleInfoEx(sRealName, 536871025u, ptr, 2) == 0) {
    return false;
  }
  _bNeutral = (*(UInt32*)ptr != 0);
  _sWindowsName = sRealName;
  if (_bNeutral) {
    _sName = sRealName;
    localeInfoEx = Interop::Kernel32::ResolveLocaleName(sRealName, ptr, 85);
    if (localeInfoEx < 1) {
      return false;
    }
    _sSpecificCulture = rt::newobj<String>(ptr, 0, localeInfoEx - 1);
  } else {
    _sSpecificCulture = sRealName;
    _sName = sRealName;
    if (GetLocaleInfoEx(sRealName, 536870913u, ptr, 2) == 0) {
      return false;
    }
    _iLanguage = *(Int32*)ptr;
    if (!IsCustomCultureId(_iLanguage)) {
      Int32 num = sRealName->IndexOf(95);
      if (num > 0) {
        _sName = sRealName->Substring(0, num);
      }
    }
  }
  return true;
}

CultureData CultureData___::GetCurrentRegionData() {
  Char default[10] = {};
  Span<Char> span = default;
  Int32 userGeoID = Interop::Kernel32::GetUserGeoID(16);
  if (userGeoID != -1) {
    Int32 geoInfo;
    {
      Char* lpGeoData = span;
      geoInfo = Interop::Kernel32::GetGeoInfo(userGeoID, 4, lpGeoData, span.get_Length(), 0);
    }
    if (geoInfo != 0) {
      geoInfo -= ((span[geoInfo - 1] == 0) ? 1 : 0);
      CultureData cultureDataForRegion = GetCultureDataForRegion(span.Slice(0, geoInfo).ToString(), true);
      if (cultureDataForRegion != nullptr) {
        return cultureDataForRegion;
      }
    }
  }
  return CultureInfo::in::get_CurrentCulture()->_cultureData;
}

void CultureData___::ctor() {
  _iInputLanguageHandle = -1;
  _iGeoId = -1;
  _iNegativePercent = -1;
  _iPositivePercent = -1;
  _iMeasure = -1;
  _iFirstDayOfWeek = -1;
  _iFirstWeekOfYear = -1;
  _iReadingLayout = -1;
  _iDefaultAnsiCodePage = -1;
  _iDefaultOemCodePage = -1;
  _iDefaultMacCodePage = -1;
  _iDefaultEbcdicCodePage = -1;
  Object::in::ctor();
}

void CultureData___::cctor() {
  s_lock = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::Globalization::CultureDataNamespace
