#include "CultureInfo-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Action-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Globalization/CalendarId.h>
#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureNotFoundException-dep.h>
#include <System.Private.CoreLib/System/Globalization/GlobalizationMode-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/GregorianCalendarTypes.h>
#include <System.Private.CoreLib/System/Globalization/HebrewCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/HijriCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/JapaneseCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/KoreanCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/PersianCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/RegionInfo-dep.h>
#include <System.Private.CoreLib/System/Globalization/TaiwanCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/ThaiBuddhistCalendar-dep.h>
#include <System.Private.CoreLib/System/Globalization/UmAlQuraCalendar-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocalValueChangedArgs-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/TimeZone-dep.h>
#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Globalization::CultureInfoNamespace {
using namespace System::Threading;

CultureInfo CultureInfo___::get_CurrentCulture() {
  CultureInfo as = s_userDefaultCulture;
  CultureInfo is = s_DefaultThreadCurrentCulture;
  CultureInfo in = s_currentThreadCulture;
  return in != nullptr ? in : is != nullptr ? is : as != nullptr ? as : InitializeUserDefaultCulture();
}

void CultureInfo___::set_CurrentCulture(CultureInfo value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (s_asyncLocalCurrentCulture == nullptr) {
    Interlocked::CompareExchange(s_asyncLocalCurrentCulture, rt::newobj<AsyncLocal<CultureInfo>>(&AsyncLocalSetCurrentCulture), (AsyncLocal<CultureInfo>)nullptr);
  }
  s_asyncLocalCurrentCulture->set_Value(value);
}

CultureInfo CultureInfo___::get_CurrentUICulture() {
  CultureInfo as = s_DefaultThreadCurrentUICulture;
  CultureInfo is = s_currentThreadUICulture;
  return is != nullptr ? is : as != nullptr ? as : get_UserDefaultUICulture();
}

void CultureInfo___::set_CurrentUICulture(CultureInfo value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyCultureName(value, true);
  if (s_asyncLocalCurrentUICulture == nullptr) {
    Interlocked::CompareExchange(s_asyncLocalCurrentUICulture, rt::newobj<AsyncLocal<CultureInfo>>(&AsyncLocalSetCurrentUICulture), (AsyncLocal<CultureInfo>)nullptr);
  }
  s_asyncLocalCurrentUICulture->set_Value(value);
}

CultureInfo CultureInfo___::get_UserDefaultUICulture() {
  CultureInfo as = s_userDefaultUICulture;
  return as != nullptr ? as : InitializeUserDefaultUICulture();
}

CultureInfo CultureInfo___::get_InstalledUICulture() {
  CultureInfo as = s_userDefaultCulture;
  return as != nullptr ? as : InitializeUserDefaultCulture();
}

CultureInfo CultureInfo___::get_DefaultThreadCurrentCulture() {
  return s_DefaultThreadCurrentCulture;
}

void CultureInfo___::set_DefaultThreadCurrentCulture(CultureInfo value) {
  s_DefaultThreadCurrentCulture = value;
}

CultureInfo CultureInfo___::get_DefaultThreadCurrentUICulture() {
  return s_DefaultThreadCurrentUICulture;
}

void CultureInfo___::set_DefaultThreadCurrentUICulture(CultureInfo value) {
  if (value != nullptr) {
    VerifyCultureName(value, true);
  }
  s_DefaultThreadCurrentUICulture = value;
}

CultureInfo CultureInfo___::get_InvariantCulture() {
  return s_InvariantCultureInfo;
}

CultureInfo CultureInfo___::get_Parent() {
  if (_parent == nullptr) {
    String parentName = _cultureData->get_ParentName();
    CultureInfo as = CreateCultureInfoNoThrow(parentName, _cultureData->get_UseUserOverride());
    CultureInfo value = (!String::in::IsNullOrEmpty(parentName)) ? (as != nullptr ? as : get_InvariantCulture()) : get_InvariantCulture();
    Interlocked::CompareExchange(_parent, value, (CultureInfo)nullptr);
  }
  return _parent;
}

Int32 CultureInfo___::get_LCID() {
  return _cultureData->get_LCID();
}

Int32 CultureInfo___::get_KeyboardLayoutId() {
  return _cultureData->get_KeyboardLayoutId();
}

String CultureInfo___::get_Name() {
  String text = _nonSortName;
  if (text == nullptr) {
    String as = _cultureData->get_Name();
    String obj = as != nullptr ? as : String::in::Empty;
    String text2 = obj;
    _nonSortName = obj;
    text = text2;
  }
  return text;
}

String CultureInfo___::get_SortName() {
  String as = _sortName;
  return as != nullptr ? as : (_sortName = _cultureData->get_SortName());
}

String CultureInfo___::get_IetfLanguageTag() {
  String name = get_Name();
  if (!(name == "zh-CHT")) {
    if (name == "zh-CHS") {
      return "zh-Hans";
    }
    return get_Name();
  }
  return "zh-Hant";
}

String CultureInfo___::get_DisplayName() {
  return _cultureData->get_DisplayName();
}

String CultureInfo___::get_NativeName() {
  return _cultureData->get_NativeName();
}

String CultureInfo___::get_EnglishName() {
  return _cultureData->get_EnglishName();
}

String CultureInfo___::get_TwoLetterISOLanguageName() {
  return _cultureData->get_TwoLetterISOLanguageName();
}

String CultureInfo___::get_ThreeLetterISOLanguageName() {
  return _cultureData->get_ThreeLetterISOLanguageName();
}

String CultureInfo___::get_ThreeLetterWindowsLanguageName() {
  return _cultureData->get_ThreeLetterWindowsLanguageName();
}

CompareInfo CultureInfo___::get_CompareInfo() {
  CompareInfo as = _compareInfo;
  return as != nullptr ? as : (_compareInfo = (get_UseUserOverride() ? GetCultureInfo(_name)->get_CompareInfo() : rt::newobj<CompareInfo>((CultureInfo)this)));
}

TextInfo CultureInfo___::get_TextInfo() {
  if (_textInfo == nullptr) {
    TextInfo textInfo = rt::newobj<TextInfo>(_cultureData);
    textInfo->SetReadOnlyState(_isReadOnly);
    _textInfo = textInfo;
  }
  return _textInfo;
}

Boolean CultureInfo___::get_IsNeutralCulture() {
  return _cultureData->get_IsNeutralCulture();
}

CultureTypes CultureInfo___::get_CultureTypes() {
  CultureTypes cultureTypes = _cultureData->get_IsNeutralCulture() ? CultureTypes::NeutralCultures : CultureTypes::SpecificCultures;
  Boolean isWin32Installed = CultureData::in::get_IsWin32Installed();
  cultureTypes |= CultureTypes::InstalledWin32Cultures;
  if (_cultureData->get_IsSupplementalCustomCulture()) {
    cultureTypes |= CultureTypes::UserCustomCulture;
  }
  if (_cultureData->get_IsReplacementCulture()) {
    cultureTypes |= CultureTypes::ReplacementCultures;
  }
  return cultureTypes;
}

NumberFormatInfo CultureInfo___::get_NumberFormat() {
  if (_numInfo == nullptr) {
    NumberFormatInfo numberFormatInfo = rt::newobj<NumberFormatInfo>(_cultureData);
    numberFormatInfo->_isReadOnly = _isReadOnly;
    Interlocked::CompareExchange(_numInfo, numberFormatInfo, (NumberFormatInfo)nullptr);
  }
  return _numInfo;
}

void CultureInfo___::set_NumberFormat(NumberFormatInfo value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _numInfo = value;
}

DateTimeFormatInfo CultureInfo___::get_DateTimeFormat() {
  if (_dateTimeInfo == nullptr) {
    DateTimeFormatInfo dateTimeFormatInfo = rt::newobj<DateTimeFormatInfo>(_cultureData, get_Calendar());
    dateTimeFormatInfo->_isReadOnly = _isReadOnly;
    Interlocked::CompareExchange(_dateTimeInfo, dateTimeFormatInfo, (DateTimeFormatInfo)nullptr);
  }
  return _dateTimeInfo;
}

void CultureInfo___::set_DateTimeFormat(DateTimeFormatInfo value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  VerifyWritable();
  _dateTimeInfo = value;
}

Calendar CultureInfo___::get_Calendar() {
  if (_calendar == nullptr) {
    Calendar defaultCalendar = _cultureData->get_DefaultCalendar();
    Interlocked::MemoryBarrier();
    defaultCalendar->SetReadOnlyState(_isReadOnly);
    _calendar = defaultCalendar;
  }
  return _calendar;
}

Array<Calendar> CultureInfo___::get_OptionalCalendars() {
  if (GlobalizationMode::get_Invariant()) {
    return rt::newarr<Array<GregorianCalendar>>(1);
  }
  Array<CalendarId> calendarIds = _cultureData->get_CalendarIds();
  Array<Calendar> array = rt::newarr<Array<Calendar>>(calendarIds->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = GetCalendarInstance(calendarIds[i]);
  }
  return array;
}

Boolean CultureInfo___::get_UseUserOverride() {
  return _cultureData->get_UseUserOverride();
}

Boolean CultureInfo___::get_IsReadOnly() {
  return _isReadOnly;
}

Boolean CultureInfo___::get_HasInvariantCultureName() {
  return get_Name() == get_InvariantCulture()->get_Name();
}

Dictionary<String, CultureInfo> CultureInfo___::get_CachedCulturesByName() {
  Dictionary<String, CultureInfo> dictionary = s_cachedCulturesByName;
  if (dictionary == nullptr) {
    dictionary = rt::newobj<Dictionary<String, CultureInfo>>();
    Dictionary<String, CultureInfo> as = Interlocked::CompareExchange(s_cachedCulturesByName, dictionary, (Dictionary<String, CultureInfo>)nullptr);
    dictionary = (as != nullptr ? as : dictionary);
  }
  return dictionary;
}

Dictionary<Int32, CultureInfo> CultureInfo___::get_CachedCulturesByLcid() {
  Dictionary<Int32, CultureInfo> dictionary = s_cachedCulturesByLcid;
  if (dictionary == nullptr) {
    dictionary = rt::newobj<Dictionary<Int32, CultureInfo>>();
    Dictionary<Int32, CultureInfo> as = Interlocked::CompareExchange(s_cachedCulturesByLcid, dictionary, (Dictionary<Int32, CultureInfo>)nullptr);
    dictionary = (as != nullptr ? as : dictionary);
  }
  return dictionary;
}

void CultureInfo___::set_UserDefaultLocaleName(String value) {
  UserDefaultLocaleName = value;
}

void CultureInfo___::AsyncLocalSetCurrentCulture(AsyncLocalValueChangedArgs<CultureInfo> args) {
  s_currentThreadCulture = args.get_CurrentValue();
}

void CultureInfo___::AsyncLocalSetCurrentUICulture(AsyncLocalValueChangedArgs<CultureInfo> args) {
  s_currentThreadUICulture = args.get_CurrentValue();
}

CultureInfo CultureInfo___::InitializeUserDefaultCulture() {
  Interlocked::CompareExchange(s_userDefaultCulture, GetUserDefaultCulture(), (CultureInfo)nullptr);
  return s_userDefaultCulture;
}

CultureInfo CultureInfo___::InitializeUserDefaultUICulture() {
  Interlocked::CompareExchange(s_userDefaultUICulture, GetUserDefaultUICulture(), (CultureInfo)nullptr);
  return s_userDefaultUICulture;
}

void CultureInfo___::ctor(String name) {
}

void CultureInfo___::ctor(String name, Boolean useUserOverride) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  CultureData cultureData = CultureData::in::GetCultureData(name, useUserOverride);
  if (cultureData == nullptr) {
    rt::throw_exception<CultureNotFoundException>("name", name, SR::get_Argument_CultureNotSupported());
  }
  _cultureData = cultureData;
  _name = _cultureData->get_CultureName();
  _isInherited = (GetType() != typeof<CultureInfo>());
}

void CultureInfo___::ctor(CultureData cultureData, Boolean isReadOnly) {
  _cultureData = cultureData;
  _name = cultureData->get_CultureName();
  _isReadOnly = isReadOnly;
}

CultureInfo CultureInfo___::CreateCultureInfoNoThrow(String name, Boolean useUserOverride) {
  CultureData cultureData = CultureData::in::GetCultureData(name, useUserOverride);
  if (cultureData == nullptr) {
    return nullptr;
  }
  return rt::newobj<CultureInfo>(cultureData);
}

void CultureInfo___::ctor(Int32 culture) {
}

void CultureInfo___::ctor(Int32 culture, Boolean useUserOverride) {
  if (culture < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("culture", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  switch (culture.get()) {
    case 0:
    case 1024:
    case 2048:
    case 3072:
    case 4096:
      rt::throw_exception<CultureNotFoundException>("culture", culture, SR::get_Argument_CultureNotSupported());
  }
  _cultureData = CultureData::in::GetCultureData(culture, useUserOverride);
  _isInherited = (GetType() != typeof<CultureInfo>());
  _name = _cultureData->get_CultureName();
}

void CultureInfo___::ctor(String cultureName, String textAndCompareCultureName) {
  if (cultureName == nullptr) {
    rt::throw_exception<ArgumentNullException>("cultureName", SR::get_ArgumentNull_String());
  }
  CultureData cultureData = CultureData::in::GetCultureData(cultureName, false);
  if (cultureData == nullptr) {
    rt::throw_exception<CultureNotFoundException>("cultureName", cultureName, SR::get_Argument_CultureNotSupported());
  }
  CultureData cultureData2 = _cultureData = cultureData;
  _name = _cultureData->get_CultureName();
  CultureInfo cultureInfo = GetCultureInfo(textAndCompareCultureName);
  _compareInfo = cultureInfo->get_CompareInfo();
  _textInfo = cultureInfo->get_TextInfo();
}

CultureInfo CultureInfo___::GetCultureByName(String name) {
  try {
    return rt::newobj<CultureInfo>(name);
  } catch (ArgumentException) {
    return get_InvariantCulture();
  }
}

CultureInfo CultureInfo___::CreateSpecificCulture(String name) {
  CultureInfo cultureInfo;
  try {
    cultureInfo = rt::newobj<CultureInfo>(name);
  } catch (ArgumentException) {
    cultureInfo = nullptr;
    for (Int32 i = 0; i < name->get_Length(); i++) {
      if ('-' == name[i]) {
        try {
          cultureInfo = rt::newobj<CultureInfo>(name->Substring(0, i));
        } catch (ArgumentException) {
          throw;
        }
        break;
      }
    }
    if (cultureInfo == nullptr) {
      throw;
    }
  }
  if (!cultureInfo->get_IsNeutralCulture()) {
    return cultureInfo;
  }
  return rt::newobj<CultureInfo>(cultureInfo->_cultureData->get_SpecificCultureName());
}

Boolean CultureInfo___::VerifyCultureName(String cultureName, Boolean throwException) {
  for (Char&& c : *cultureName) {
    if (!Char::IsLetterOrDigit(c) && c != '-' && c != '_') {
      if (throwException) {
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidResourceCultureName(), cultureName));
      }
      return false;
    }
  }
  return true;
}

Boolean CultureInfo___::VerifyCultureName(CultureInfo culture, Boolean throwException) {
  if (!culture->_isInherited) {
    return true;
  }
  return VerifyCultureName(culture->get_Name(), throwException);
}

Array<CultureInfo> CultureInfo___::GetCultures(CultureTypes types) {
  if ((types & CultureTypes::UserCustomCulture) == CultureTypes::UserCustomCulture) {
    types |= CultureTypes::ReplacementCultures;
  }
  return CultureData::in::GetCultures(types);
}

Boolean CultureInfo___::Equals(Object value) {
  if ((CultureInfo)this == value) {
    return true;
  }
  CultureInfo cultureInfo = rt::as<CultureInfo>(value);
  if (cultureInfo != nullptr) {
    if (get_Name()->Equals(cultureInfo->get_Name())) {
      return get_CompareInfo()->Equals(cultureInfo->get_CompareInfo());
    }
    return false;
  }
  return false;
}

Int32 CultureInfo___::GetHashCode() {
  return get_Name()->GetHashCode() + get_CompareInfo()->GetHashCode();
}

String CultureInfo___::ToString() {
  return _name;
}

Object CultureInfo___::GetFormat(Type formatType) {
  if (formatType == typeof<NumberFormatInfo>()) {
    return get_NumberFormat();
  }
  if (formatType == typeof<DateTimeFormatInfo>()) {
    return get_DateTimeFormat();
  }
  return nullptr;
}

void CultureInfo___::ClearCachedData() {
  UserDefaultLocaleName = GetUserDefaultLocaleName();
  s_userDefaultCulture = GetUserDefaultCulture();
  s_userDefaultUICulture = GetUserDefaultUICulture();
  RegionInfo::in::s_currentRegionInfo = nullptr;
  TimeZone::in::ResetTimeZone();
  TimeZoneInfo::in::ClearCachedData();
  s_cachedCulturesByLcid = nullptr;
  s_cachedCulturesByName = nullptr;
  CultureData::in::ClearCachedData();
}

Calendar CultureInfo___::GetCalendarInstance(CalendarId calType) {
  if (calType == CalendarId::GREGORIAN) {
    return rt::newobj<GregorianCalendar>();
  }
  return GetCalendarInstanceRare(calType);
}

Calendar CultureInfo___::GetCalendarInstanceRare(CalendarId calType) {
  switch (calType) {
    case CalendarId::GREGORIAN_US:
    case CalendarId::GREGORIAN_ME_FRENCH:
    case CalendarId::GREGORIAN_ARABIC:
    case CalendarId::GREGORIAN_XLIT_ENGLISH:
    case CalendarId::GREGORIAN_XLIT_FRENCH:
      return rt::newobj<GregorianCalendar>((GregorianCalendarTypes)calType);
    case CalendarId::TAIWAN:
      return rt::newobj<TaiwanCalendar>();
    case CalendarId::JAPAN:
      return rt::newobj<JapaneseCalendar>();
    case CalendarId::KOREA:
      return rt::newobj<KoreanCalendar>();
    case CalendarId::THAI:
      return rt::newobj<ThaiBuddhistCalendar>();
    case CalendarId::HIJRI:
      return rt::newobj<HijriCalendar>();
    case CalendarId::HEBREW:
      return rt::newobj<HebrewCalendar>();
    case CalendarId::UMALQURA:
      return rt::newobj<UmAlQuraCalendar>();
    case CalendarId::PERSIAN:
      return rt::newobj<PersianCalendar>();
    default:
      return rt::newobj<GregorianCalendar>();
  }
}

CultureInfo CultureInfo___::GetConsoleFallbackUICulture() {
  CultureInfo cultureInfo = _consoleFallbackCulture;
  if (cultureInfo == nullptr) {
    cultureInfo = CreateSpecificCulture(_cultureData->get_SCONSOLEFALLBACKNAME());
    cultureInfo->_isReadOnly = true;
    _consoleFallbackCulture = cultureInfo;
  }
  return cultureInfo;
}

Object CultureInfo___::Clone() {
  CultureInfo cultureInfo = (CultureInfo)MemberwiseClone();
  cultureInfo->_isReadOnly = false;
  if (!_isInherited) {
    if (_dateTimeInfo != nullptr) {
      cultureInfo->_dateTimeInfo = (DateTimeFormatInfo)_dateTimeInfo->Clone();
    }
    if (_numInfo != nullptr) {
      cultureInfo->_numInfo = (NumberFormatInfo)_numInfo->Clone();
    }
  } else {
    cultureInfo->set_DateTimeFormat((DateTimeFormatInfo)get_DateTimeFormat()->Clone());
    cultureInfo->set_NumberFormat((NumberFormatInfo)get_NumberFormat()->Clone());
  }
  if (_textInfo != nullptr) {
    cultureInfo->_textInfo = (TextInfo)_textInfo->Clone();
  }
  if (_dateTimeInfo != nullptr && _dateTimeInfo->get_Calendar() == _calendar) {
    cultureInfo->_calendar = cultureInfo->get_DateTimeFormat()->set_Calendar();
  } else if (_calendar != nullptr) {
    cultureInfo->_calendar = (Calendar)_calendar->Clone();
  }

  return cultureInfo;
}

CultureInfo CultureInfo___::ReadOnly(CultureInfo ci) {
  if (ci == nullptr) {
    rt::throw_exception<ArgumentNullException>("ci");
  }
  if (ci->get_IsReadOnly()) {
    return ci;
  }
  CultureInfo cultureInfo = (CultureInfo)ci->MemberwiseClone();
  if (!ci->get_IsNeutralCulture()) {
    if (!ci->_isInherited) {
      if (ci->_dateTimeInfo != nullptr) {
        cultureInfo->_dateTimeInfo = DateTimeFormatInfo::in::ReadOnly(ci->_dateTimeInfo);
      }
      if (ci->_numInfo != nullptr) {
        cultureInfo->_numInfo = NumberFormatInfo::in::ReadOnly(ci->_numInfo);
      }
    } else {
      cultureInfo->set_DateTimeFormat(DateTimeFormatInfo::in::ReadOnly(ci->get_DateTimeFormat()));
      cultureInfo->set_NumberFormat(NumberFormatInfo::in::ReadOnly(ci->get_NumberFormat()));
    }
  }
  if (ci->_textInfo != nullptr) {
    cultureInfo->_textInfo = TextInfo::in::ReadOnly(ci->_textInfo);
  }
  if (ci->_calendar != nullptr) {
    cultureInfo->_calendar = Calendar::in::ReadOnly(ci->_calendar);
  }
  cultureInfo->_isReadOnly = true;
  return cultureInfo;
}

void CultureInfo___::VerifyWritable() {
  if (_isReadOnly) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
}

CultureInfo CultureInfo___::GetCultureInfo(Int32 culture) {
  if (culture <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("culture", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  Dictionary<Int32, CultureInfo> cachedCulturesByLcid = get_CachedCulturesByLcid();
  CultureInfo value;
  {
    rt::lock(cachedCulturesByLcid);
    if (cachedCulturesByLcid->TryGetValue(culture, value)) {
      return value;
    }
  }
  try {
    value = rt::newobj<CultureInfo>(culture, false);
  } catch (ArgumentException) {
    rt::throw_exception<CultureNotFoundException>("culture", culture, SR::get_Argument_CultureNotSupported());
  }
  {
    rt::lock(cachedCulturesByLcid);
    cachedCulturesByLcid[culture] = value;
    return value;
  }
}

CultureInfo CultureInfo___::GetCultureInfo(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  name = CultureData::in::AnsiToLower(name);
  Dictionary<String, CultureInfo> cachedCulturesByName = get_CachedCulturesByName();
  CultureInfo value;
  {
    rt::lock(cachedCulturesByName);
    if (cachedCulturesByName->TryGetValue(name, value)) {
      return value;
    }
  }
  CultureInfo cultureInfo = CreateCultureInfoNoThrow(name, false);
  if (cultureInfo == nullptr) {
    rt::throw_exception<CultureNotFoundException>("name", name, SR::get_Argument_CultureNotSupported());
  }
  value = cultureInfo;
  value->_isReadOnly = true;
  name = CultureData::in::AnsiToLower(value->_name);
  {
    rt::lock(cachedCulturesByName);
    cachedCulturesByName[name] = value;
    return value;
  }
}

CultureInfo CultureInfo___::GetCultureInfo(String name, String altName) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (altName == nullptr) {
    rt::throw_exception<ArgumentNullException>("altName");
  }
  name = CultureData::in::AnsiToLower(name);
  altName = CultureData::in::AnsiToLower(altName);
  String key = name + "�" + altName;
  Dictionary<String, CultureInfo> cachedCulturesByName = get_CachedCulturesByName();
  CultureInfo value;
  {
    rt::lock(cachedCulturesByName);
    if (cachedCulturesByName->TryGetValue(key, value)) {
      return value;
    }
  }
  try {
    value = rt::newobj<CultureInfo>(name, altName);
    value->get_TextInfo()->SetReadOnlyState(true);
  } catch (ArgumentException) {
    rt::throw_exception<CultureNotFoundException>("name/altName", SR::Format(SR::get_Argument_OneOfCulturesNotSupported(), name, altName));
  }
  {
    rt::lock(cachedCulturesByName);
    cachedCulturesByName[key] = value;
    return value;
  }
}

CultureInfo CultureInfo___::GetCultureInfo(String name, Boolean predefinedOnly) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (predefinedOnly && !GlobalizationMode::get_Invariant()) {
    if (!GlobalizationMode::get_UseNls()) {
      return IcuGetPredefinedCultureInfo(name);
    }
    return NlsGetPredefinedCultureInfo(name);
  }
  return GetCultureInfo(name);
}

CultureInfo CultureInfo___::GetCultureInfoByIetfLanguageTag(String name) {
  if (name == "zh-CHT" || name == "zh-CHS") {
    rt::throw_exception<CultureNotFoundException>("name", SR::Format(SR::get_Argument_CultureIetfNotSupported(), name));
  }
  CultureInfo cultureInfo = GetCultureInfo(name);
  if (cultureInfo->get_LCID() > 65535 || cultureInfo->get_LCID() == 1034) {
    rt::throw_exception<CultureNotFoundException>("name", SR::Format(SR::get_Argument_CultureIetfNotSupported(), name));
  }
  return cultureInfo;
}

CultureInfo CultureInfo___::IcuGetPredefinedCultureInfo(String name) {
  if (!Interop::Globalization::IsPredefinedLocale(name)) {
    rt::throw_exception<CultureNotFoundException>("name", SR::Format(SR::get_Argument_InvalidPredefinedCultureName(), name));
  }
  return GetCultureInfo(name);
}

CultureInfo CultureInfo___::NlsGetPredefinedCultureInfo(String name) {
  CultureInfo cultureInfo = GetCultureInfo(name);
  String englishName = cultureInfo->get_EnglishName();
  if (englishName->StartsWith("Unknown ", StringComparison::Ordinal) && englishName->get_Length() > 8 && (englishName->IndexOf("Locale", 8, StringComparison::Ordinal) == 8 || englishName->IndexOf("Language", 8, StringComparison::Ordinal) == 8)) {
    rt::throw_exception<CultureNotFoundException>("name", SR::Format(SR::get_Argument_InvalidPredefinedCultureName(), name));
  }
  return cultureInfo;
}

CultureInfo CultureInfo___::GetUserDefaultCulture() {
  if (GlobalizationMode::get_Invariant()) {
    return get_InvariantCulture();
  }
  String userDefaultLocaleName = UserDefaultLocaleName;
  if (userDefaultLocaleName == nullptr) {
    return get_InvariantCulture();
  }
  return GetCultureByName(userDefaultLocaleName);
}

CultureInfo CultureInfo___::GetUserDefaultUICulture() {
  if (GlobalizationMode::get_Invariant()) {
    return get_InvariantCulture();
  }
  UInt32 num = 0u;
  UInt32 num2 = 0u;
  if (Interop::Kernel32::GetUserPreferredUILanguages(8u, &num, nullptr, &num2) != 0) {
    Char as[(Int32)num2] = {};
    Span<Char> span = (num2 > 256) ? ((Span<Char>)rt::newarr<Array<Char>>(num2)) : as;
    Span<Char> span2 = span;
    {
      Char* pwszLanguagesBuffer = span2;
      if (Interop::Kernel32::GetUserPreferredUILanguages(8u, &num, pwszLanguagesBuffer, &num2) != 0) {
        return GetCultureByName(span2.ToString());
      }
    }
  }
  return InitializeUserDefaultCulture();
}

String CultureInfo___::GetUserDefaultLocaleName() {
  String text;
  if (!GlobalizationMode::get_Invariant()) {
    text = CultureData::in::GetLocaleInfoEx(nullptr, 92u);
    if (text == nullptr) {
      return CultureData::in::GetLocaleInfoEx("!x-sys-default-locale", 92u);
    }
  } else {
    text = get_InvariantCulture()->get_Name();
  }
  return text;
}

void CultureInfo___::cctor() {
  s_InvariantCultureInfo = rt::newobj<CultureInfo>(CultureData::in::get_Invariant(), true);
  UserDefaultLocaleName = GetUserDefaultLocaleName();
}

} // namespace System::Private::CoreLib::System::Globalization::CultureInfoNamespace
