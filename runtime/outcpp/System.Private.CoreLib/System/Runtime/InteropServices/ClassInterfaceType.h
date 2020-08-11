#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ClassInterfaceType : int32_t {
  None = 0,
  AutoDispatch = 1,
  AutoDual = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
