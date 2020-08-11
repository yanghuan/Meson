#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceOnCompletedFlags : int32_t {
  None = 0,
  UseSchedulingContext = 1,
  FlowExecutionContext = 2,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
