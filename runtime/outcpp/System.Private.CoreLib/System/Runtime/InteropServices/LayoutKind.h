#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class LayoutKind : int32_t {
  Sequential = 0,
  Explicit = 2,
  Auto = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
