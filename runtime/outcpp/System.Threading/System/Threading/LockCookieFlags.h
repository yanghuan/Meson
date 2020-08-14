#pragma once

#include <cstdint>

namespace System::Threading::System::Threading {
enum class LockCookieFlags : int32_t {
  Upgrade = 8192,
  Release = 16384,
  OwnedNone = 65536,
  OwnedWriter = 131072,
  OwnedReader = 262144,
  Invalid = -483329,
};
} // namespace System::Threading::System::Threading
