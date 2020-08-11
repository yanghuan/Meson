#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CreateComInterfaceFlags : int32_t {
  None = 0,
  CallerDefinedIUnknown = 1,
  TrackerSupport = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
