#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet : int32_t {
  None = 1,
  Ansi = 2,
  Unicode = 3,
  Auto = 4,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
