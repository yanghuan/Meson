#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventProviderType : int32_t {
  None = 0,
  ETW = 1,
  EventPipe = 2,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
