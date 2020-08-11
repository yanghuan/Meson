#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class GCNotificationStatus : int32_t {
  Succeeded = 0,
  Failed = 1,
  Canceled = 2,
  Timeout = 3,
  NotApplicable = 4,
};
} // namespace System::Private::CoreLib::System
