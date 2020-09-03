#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class StringSplitOptions : int32_t {
  None = 0,
  RemoveEmptyEntries = 1,
};
} // namespace System::Private::CoreLib::System
