#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class ControllerCommand {
  Update = 0,
  SendManifest = -1,
  Enable = -2,
  Disable = -3,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing