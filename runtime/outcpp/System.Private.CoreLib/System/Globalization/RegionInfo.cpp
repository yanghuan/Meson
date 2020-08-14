#include "RegionInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureData-dep.h>
#include <System.Private.CoreLib/System/Globalization/RegionInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Globalization::RegionInfoNamespace {
RegionInfo RegionInfo___::get_CurrentRegion() {
  RegionInfo regionInfo = s_currentRegionInfo;
  if (regionInfo == nullptr) {
    regionInfo = rt::newobj<RegionInfo>(CultureData::in::GetCurrentRegionData());
    regionInfo->_name = regionInfo->_cultureData->get_RegionName();
    s_currentRegionInfo = regionInfo;
  }
  return regionInfo;
}

String RegionInfo___::get_Name() {
  return _name;
}

String RegionInfo___::get_EnglishName() {
  return _cultureData->get_EnglishCountryName();
}

String RegionInfo___::get_DisplayName() {
  return _cultureData->get_LocalizedCountryName();
}

String RegionInfo___::get_NativeName() {
  return _cultureData->get_NativeCountryName();
}

String RegionInfo___::get_TwoLetterISORegionName() {
  return _cultureData->get_TwoLetterISOCountryName();
}

String RegionInfo___::get_ThreeLetterISORegionName() {
  return _cultureData->get_ThreeLetterISOCountryName();
}

String RegionInfo___::get_ThreeLetterWindowsRegionName() {
  return get_ThreeLetterISORegionName();
}

Boolean RegionInfo___::get_IsMetric() {
  return _cultureData->get_MeasurementSystem() == 0;
}

Int32 RegionInfo___::get_GeoId() {
  return _cultureData->get_GeoId();
}

String RegionInfo___::get_CurrencyEnglishName() {
  return _cultureData->get_CurrencyEnglishName();
}

String RegionInfo___::get_CurrencyNativeName() {
  return _cultureData->get_CurrencyNativeName();
}

String RegionInfo___::get_CurrencySymbol() {
  return _cultureData->get_CurrencySymbol();
}

String RegionInfo___::get_ISOCurrencySymbol() {
  return _cultureData->get_ISOCurrencySymbol();
}

void RegionInfo___::ctor(String name) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NoRegionInvariantCulture(), "name");
  }
}

void RegionInfo___::ctor(Int32 culture) {
  switch (culture.get()) {
    case 127:
      rt::throw_exception<ArgumentException>(SR::get_Argument_NoRegionInvariantCulture());
    case 0:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_CultureIsNeutral(), culture), "culture");
    case 3072:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_CustomCultureCannotBePassedByNumber(), culture), "culture");
  }
  _cultureData = CultureData::in::GetCultureData(culture, true);
  _name = _cultureData->get_RegionName();
  if (_cultureData->get_IsNeutralCulture()) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_CultureIsNeutral(), culture), "culture");
  }
}

void RegionInfo___::ctor(CultureData cultureData) {
  _cultureData = cultureData;
  _name = _cultureData->get_RegionName();
}

Boolean RegionInfo___::Equals(Object value) {
  RegionInfo regionInfo = rt::as<RegionInfo>(value);
  if (regionInfo != nullptr) {
    return get_Name()->Equals(regionInfo->get_Name());
  }
  return false;
}

Int32 RegionInfo___::GetHashCode() {
  return get_Name()->GetHashCode();
}

String RegionInfo___::ToString() {
  return get_Name();
}

} // namespace System::Private::CoreLib::System::Globalization::RegionInfoNamespace
