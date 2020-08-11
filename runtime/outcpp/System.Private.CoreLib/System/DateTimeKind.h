#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class DateTimeKind : int32_t {
  Unspecified = 0,
  Utc = 1,
  Local = 2,
};
} // namespace System::Private::CoreLib::System
