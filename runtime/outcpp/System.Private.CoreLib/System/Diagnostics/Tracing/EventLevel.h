#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventLevel {
  LogAlways = 0,
  Critical = 1,
  Error = 2,
  Warning = 3,
  Informational = 4,
  Verbose = 5,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
