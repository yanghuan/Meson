#include "EraInfo-dep.h"

#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Globalization/EraInfo-dep.h>

namespace System::Private::CoreLib::System::Globalization::EraInfoNamespace {
void EraInfo___::ctor(Int32 era, Int32 startYear, Int32 startMonth, Int32 startDay, Int32 yearOffset, Int32 minEraYear, Int32 maxEraYear) {
  this->era = era;
  this->yearOffset = yearOffset;
  this->minEraYear = minEraYear;
  this->maxEraYear = maxEraYear;
  ticks = DateTime(startYear, startMonth, startDay).get_Ticks();
}

void EraInfo___::ctor(Int32 era, Int32 startYear, Int32 startMonth, Int32 startDay, Int32 yearOffset, Int32 minEraYear, Int32 maxEraYear, String eraName, String abbrevEraName, String englishEraName) {
  this->era = era;
  this->yearOffset = yearOffset;
  this->minEraYear = minEraYear;
  this->maxEraYear = maxEraYear;
  ticks = DateTime(startYear, startMonth, startDay).get_Ticks();
  this->eraName = eraName;
  this->abbrevEraName = abbrevEraName;
  this->englishEraName = englishEraName;
}

} // namespace System::Private::CoreLib::System::Globalization::EraInfoNamespace
