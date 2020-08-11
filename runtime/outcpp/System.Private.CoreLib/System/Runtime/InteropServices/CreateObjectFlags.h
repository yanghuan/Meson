#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CreateObjectFlags : int32_t {
  None = 0,
  TrackerObject = 1,
  UniqueInstance = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
