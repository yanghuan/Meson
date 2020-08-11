#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security {
enum class PartialTrustVisibilityLevel : int32_t {
  VisibleToAllHosts = 0,
  NotVisibleByDefault = 1,
};
} // namespace System::Private::CoreLib::System::Security
