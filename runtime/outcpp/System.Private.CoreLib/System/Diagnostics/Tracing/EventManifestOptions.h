#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventManifestOptions : int32_t {
  None = 0,
  Strict = 1,
  AllCultures = 2,
  OnlyIfNeededForRegistration = 4,
  AllowEventSourceOverride = 8,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
