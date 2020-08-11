#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskStatus : int32_t {
  Created = 0,
  WaitingForActivation = 1,
  WaitingToRun = 2,
  Running = 3,
  WaitingForChildrenToComplete = 4,
  RanToCompletion = 5,
  Canceled = 6,
  Faulted = 7,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
