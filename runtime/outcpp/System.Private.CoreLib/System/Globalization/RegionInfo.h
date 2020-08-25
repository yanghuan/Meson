#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureData)
namespace RegionInfoNamespace {
CLASS(RegionInfo) : public object {
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
  public: void ctor(String name);
  public: void ctor(Int32 culture);
  public: void ctor(CultureData cultureData);
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
