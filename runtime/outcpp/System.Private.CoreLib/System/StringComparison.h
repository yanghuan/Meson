#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class StringComparison : int32_t {
  CurrentCulture = 0,
  CurrentCultureIgnoreCase = 1,
  InvariantCulture = 2,
  InvariantCultureIgnoreCase = 3,
  Ordinal = 4,
  OrdinalIgnoreCase = 5,
};
} // namespace System::Private::CoreLib::System
