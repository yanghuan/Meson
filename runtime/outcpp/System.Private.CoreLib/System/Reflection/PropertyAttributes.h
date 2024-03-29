#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class PropertyAttributes : int32_t {
  None = 0,
  SpecialName = 512,
  RTSpecialName = 1024,
  HasDefault = 4096,
  Reserved2 = 8192,
  Reserved3 = 16384,
  Reserved4 = 32768,
  ReservedMask = 62464,
};
} // namespace System::Private::CoreLib::System::Reflection
