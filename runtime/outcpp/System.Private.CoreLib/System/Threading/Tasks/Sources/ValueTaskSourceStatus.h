#pragma once

namespace System::Private::CoreLib::System::Threading::Tasks::Sources {
enum class ValueTaskSourceStatus {
  Pending = 0,
  Succeeded = 1,
  Faulted = 2,
  Canceled = 3,
};
} // namespace System::Private::CoreLib::System::Threading::Tasks::Sources
