#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security {
enum class SecurityCriticalScope : int32_t {
  Explicit = 0,
  Everything = 1,
};
} // namespace System::Private::CoreLib::System::Security
