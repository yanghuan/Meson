#pragma once

namespace System::Private::CoreLib::Windows::Foundation::Diagnostics {
enum class AsyncCausalityStatus {
  Canceled = 2,
  Completed = 1,
  Error = 3,
  Started = 0,
};
} // namespace System::Private::CoreLib::Windows::Foundation::Diagnostics
