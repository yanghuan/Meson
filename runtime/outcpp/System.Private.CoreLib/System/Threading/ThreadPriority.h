#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading {
enum class ThreadPriority : int32_t {
  Lowest = 0,
  BelowNormal = 1,
  Normal = 2,
  AboveNormal = 3,
  Highest = 4,
};
} // namespace System::Private::CoreLib::System::Threading
