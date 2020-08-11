#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class ProcessorArchitecture : int32_t {
  None = 0,
  MSIL = 1,
  X86 = 2,
  IA64 = 3,
  Amd64 = 4,
  Arm = 5,
};
} // namespace System::Private::CoreLib::System::Reflection
