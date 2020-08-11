#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Globalization {
enum class CultureTypes : int32_t {
  NeutralCultures = 1,
  SpecificCultures = 2,
  InstalledWin32Cultures = 4,
  AllCultures = 7,
  UserCustomCulture = 8,
  ReplacementCultures = 16,
  WindowsOnlyCultures = 32,
  FrameworkCultures = 64,
};
} // namespace System::Private::CoreLib::System::Globalization
