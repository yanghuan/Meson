#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading {
enum class StackCrawlMark : int32_t {
  LookForMe = 0,
  LookForMyCaller = 1,
  LookForMyCallersCaller = 2,
  LookForThread = 3,
};
} // namespace System::Private::CoreLib::System::Threading
