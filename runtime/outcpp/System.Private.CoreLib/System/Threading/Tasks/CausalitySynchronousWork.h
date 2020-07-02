#pragma once

namespace System::Private::CoreLib::System::Threading::Tasks {
enum class CausalitySynchronousWork {
  CompletionNotification = 0,
  ProgressNotification = 1,
  Execution = 2,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks
