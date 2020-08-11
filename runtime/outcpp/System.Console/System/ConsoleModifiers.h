#pragma once

#include <cstdint>

namespace System::Console::System {
enum class ConsoleModifiers : int32_t {
  Alt = 1,
  Shift = 2,
  Control = 4,
};
} // namespace System::Console::System
