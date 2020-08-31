#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class AsyncCausalityStatus : int32_t {
  Started = 0,
  Completed = 1,
  Canceled = 2,
  Error = 3,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
