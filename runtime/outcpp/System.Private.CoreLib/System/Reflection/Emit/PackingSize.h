#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class PackingSize : int32_t {
  Unspecified = 0,
  Size1 = 1,
  Size2 = 2,
  Size4 = 4,
  Size8 = 8,
  Size16 = 16,
  Size32 = 32,
  Size64 = 64,
  Size128 = 128,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
