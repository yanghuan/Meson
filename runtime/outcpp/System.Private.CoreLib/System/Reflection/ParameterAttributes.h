#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class ParameterAttributes : int32_t {
  None = 0,
  In = 1,
  Out = 2,
  Lcid = 4,
  Retval = 8,
  Optional = 16,
  HasDefault = 4096,
  HasFieldMarshal = 8192,
  Reserved3 = 16384,
  Reserved4 = 32768,
  ReservedMask = 61440,
};
} // namespace System::Private::CoreLib::System::Reflection
