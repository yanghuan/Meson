#pragma once

#include <cstdint>

namespace System::Private::Uri::System {
enum class UnescapeMode : int32_t {
  CopyOnly = 0,
  Escape = 1,
  Unescape = 2,
  EscapeUnescape = 3,
  V1ToStringFlag = 4,
  UnescapeAll = 8,
  UnescapeAllOrThrow = 24,
};
} // namespace System::Private::Uri::System
