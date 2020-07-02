#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventSourceSettings {
  Default = 0,
  ThrowOnEventWriteErrors = 1,
  EtwManifestEventFormat = 4,
  EtwSelfDescribingEventFormat = 8,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
