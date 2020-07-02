#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannel : uint8_t {
  None = 0,
  Admin = 16,
  Operational = 17,
  Analytic = 18,
  Debug = 19,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
