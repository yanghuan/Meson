#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class TimeZoneInfoOptions : int32_t {
  None = 1,
  NoThrowOnInvalidTime = 2,
};
} // namespace System::Private::CoreLib::System
