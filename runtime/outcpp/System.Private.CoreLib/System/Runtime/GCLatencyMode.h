#pragma once

namespace System::Private::CoreLib::System::Runtime {
enum class GCLatencyMode {
  Batch = 0,
  Interactive = 1,
  LowLatency = 2,
  SustainedLowLatency = 3,
  NoGCRegion = 4,
};
} // namespace System::Private::CoreLib::System::Runtime
