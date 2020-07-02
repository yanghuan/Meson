#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureData)
namespace RegionInfoNamespace {
CLASS(RegionInfo) {
  public: static RegionInfo get_CurrentRegion();
  public: String get_Name();
  public: String get_EnglishName();
  public: String get_DisplayName();
  public: String get_NativeName();
  public: String get_TwoLetterISORegionName();
  public: String get_ThreeLetterISORegionName();
  public: String get_ThreeLetterWindowsRegionName();
  public: Boolean get_IsMetric();
  public: Int32 get_GeoId();
  public: String get_CurrencyEnglishName();
  public: String get_CurrencyNativeName();
  public: String get_CurrencySymbol();
  public: String get_ISOCurrencySymbol();
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: String ToString();
  private: String _name;
  private: CultureData _cultureData;
  public: static RegionInfo s_currentRegionInfo;
};
} // namespace RegionInfoNamespace
using RegionInfo = RegionInfoNamespace::RegionInfo;
} // namespace System::Private::CoreLib::System::Globalization
