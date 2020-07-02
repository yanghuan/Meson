#pragma once

namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceOnCompletedFlags {
  None = 0,
  UseSchedulingContext = 1,
  FlowExecutionContext = 2,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
