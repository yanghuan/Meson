#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
enum class Cer : int32_t {
  None = 0,
  MayFail = 1,
  Success = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
