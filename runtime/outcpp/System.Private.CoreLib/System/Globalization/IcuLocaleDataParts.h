#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class IcuLocaleDataParts : int32_t {
  Lcid = 0,
  AnsiCodePage = 1,
  OemCodePage = 2,
  MacCodePage = 3,
  EbcdicCodePage = 4,
  GeoId = 5,
  DigitSubstitution = 6,
  SpecificLocaleIndex = 7,
  ConsoleLocaleIndex = 8,
};
} // namespace System::Private::CoreLib::System::Globalization
