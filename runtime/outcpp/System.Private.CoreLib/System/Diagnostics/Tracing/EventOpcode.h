#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventOpcode : int32_t {
  Info = 0,
  Start = 1,
  Stop = 2,
  DataCollectionStart = 3,
  DataCollectionStop = 4,
  Extension = 5,
  Reply = 6,
  Resume = 7,
  Suspend = 8,
  Send = 9,
  Receive = 240,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
