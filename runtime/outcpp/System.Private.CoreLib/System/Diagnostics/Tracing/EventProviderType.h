#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventProviderType {
  None = 0,
  ETW = 1,
  EventPipe = 2,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
