#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading {
enum class LockRecursionPolicy : int32_t {
  NoRecursion = 0,
  SupportsRecursion = 1,
};
} // namespace System::Private::CoreLib::System::Threading
