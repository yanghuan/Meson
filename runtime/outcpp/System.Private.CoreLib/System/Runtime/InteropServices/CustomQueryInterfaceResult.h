#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CustomQueryInterfaceResult : int32_t {
  Handled = 0,
  NotHandled = 1,
  Failed = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
