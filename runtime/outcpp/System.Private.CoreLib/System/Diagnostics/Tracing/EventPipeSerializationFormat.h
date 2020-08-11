#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventPipeSerializationFormat : int32_t {
  NetPerf = 0,
  NetTrace = 1,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
