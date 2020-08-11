#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime {
enum class GCLargeObjectHeapCompactionMode : int32_t {
  Default = 1,
  CompactOnce = 2,
};
} // namespace System::Private::CoreLib::System::Runtime
