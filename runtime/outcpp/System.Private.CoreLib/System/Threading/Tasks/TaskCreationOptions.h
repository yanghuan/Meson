#pragma once

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class TaskCreationOptions {
  None = 0,
  PreferFairness = 1,
  LongRunning = 2,
  AttachedToParent = 4,
  DenyChildAttach = 8,
  HideScheduler = 16,
  RunContinuationsAsynchronously = 64,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
