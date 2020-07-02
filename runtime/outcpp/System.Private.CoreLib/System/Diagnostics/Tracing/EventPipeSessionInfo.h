#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
namespace EventPipeSessionInfoNamespace {
struct EventPipeSessionInfo {
  public: Int64 StartTimeAsUTCFileTime;
  public: Int64 StartTimeStamp;
  public: Int64 TimeStampFrequency;
};
} // namespace EventPipeSessionInfoNamespace
using EventPipeSessionInfo = EventPipeSessionInfoNamespace::EventPipeSessionInfo;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
