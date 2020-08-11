#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class ControllerCommand : int32_t {
  Update = 0,
  SendManifest = -1,
  Enable = -2,
  Disable = -3,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
