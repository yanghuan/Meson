#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t {
  None = 0,
  All = -1,
  MicrosoftTelemetry = 562949953421312,
  WdiContext = 562949953421312,
  WdiDiagnostic = 1125899906842624,
  Sqm = 2251799813685248,
  AuditFailure = 4503599627370496,
  AuditSuccess = 9007199254740992,
  CorrelationHint = 4503599627370496,
  EventLogClassic = 36028797018963968,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
