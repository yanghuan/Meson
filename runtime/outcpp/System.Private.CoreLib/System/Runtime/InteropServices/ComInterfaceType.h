#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComInterfaceType : int32_t {
  InterfaceIsDual = 0,
  InterfaceIsIUnknown = 1,
  InterfaceIsIDispatch = 2,
  InterfaceIsIInspectable = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
