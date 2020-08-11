#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskCreationOptions : int32_t {
  None = 0,
  PreferFairness = 1,
  LongRunning = 2,
  AttachedToParent = 4,
  DenyChildAttach = 8,
  HideScheduler = 16,
  RunContinuationsAsynchronously = 64,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
