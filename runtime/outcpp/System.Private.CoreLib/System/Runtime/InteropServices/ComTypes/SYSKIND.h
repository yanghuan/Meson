#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class SYSKIND : int32_t {
  SYS_WIN16 = 0,
  SYS_WIN32 = 1,
  SYS_MAC = 2,
  SYS_WIN64 = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
