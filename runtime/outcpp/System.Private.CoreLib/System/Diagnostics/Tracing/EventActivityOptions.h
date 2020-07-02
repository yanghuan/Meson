#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventActivityOptions {
  None = 0,
  Disable = 2,
  Recursive = 4,
  Detachable = 8,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
