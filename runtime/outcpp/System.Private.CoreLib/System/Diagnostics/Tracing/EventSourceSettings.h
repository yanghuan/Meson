#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventSourceSettings : int32_t {
  Default = 0,
  ThrowOnEventWriteErrors = 1,
  EtwManifestEventFormat = 4,
  EtwSelfDescribingEventFormat = 8,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
