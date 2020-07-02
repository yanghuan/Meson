#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventChannelType {
  Admin = 1,
  Operational = 2,
  Analytic = 3,
  Debug = 4,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
