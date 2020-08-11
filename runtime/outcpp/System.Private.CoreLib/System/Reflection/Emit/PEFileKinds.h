#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class PEFileKinds : int32_t {
  Dll = 1,
  ConsoleApplication = 2,
  WindowApplication = 3,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
