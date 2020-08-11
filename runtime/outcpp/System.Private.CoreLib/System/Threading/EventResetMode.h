#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading {
enum class EventResetMode : int32_t {
  AutoReset = 0,
  ManualReset = 1,
};
} // namespace System::Private::CoreLib::System::Threading
