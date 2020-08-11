#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class EventAttributes : int32_t {
  None = 0,
  SpecialName = 512,
  RTSpecialName = 1024,
  ReservedMask = 1024,
};
} // namespace System::Private::CoreLib::System::Reflection
