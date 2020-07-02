#pragma once

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class InternalTaskOptions {
  None = 0,
  InternalOptionsMask = 65280,
  ContinuationTask = 512,
  PromiseTask = 1024,
  LazyCancellation = 4096,
  QueuedByRuntime = 8192,
  DoNotDispose = 16384,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
