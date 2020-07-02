#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventManifestOptions {
  None = 0,
  Strict = 1,
  AllCultures = 2,
  OnlyIfNeededForRegistration = 4,
  AllowEventSourceOverride = 8,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
