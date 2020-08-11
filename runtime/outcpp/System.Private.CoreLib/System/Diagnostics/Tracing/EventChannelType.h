#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannelType : int32_t {
  Admin = 1,
  Operational = 2,
  Analytic = 3,
  Debug = 4,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
