#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class CausalitySynchronousWork : int32_t {
  CompletionNotification = 0,
  ProgressNotification = 1,
  Execution = 2,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
