#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class GregorianCalendarTypes : int32_t {
  Localized = 1,
  USEnglish = 2,
  MiddleEastFrench = 9,
  Arabic = 10,
  TransliteratedEnglish = 11,
  TransliteratedFrench = 12,
};
} // namespace System::Private::CoreLib::System::Globalization
