#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class GCKind : int32_t {
  Any = 0,
  Ephemeral = 1,
  FullBlocking = 2,
  Background = 3,
};
} // namespace System::Private::CoreLib::System
