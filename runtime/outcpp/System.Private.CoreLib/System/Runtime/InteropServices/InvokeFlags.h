#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class InvokeFlags : int16_t {
  DISPATCH_METHOD = 1,
  DISPATCH_PROPERTYGET = 2,
  DISPATCH_PROPERTYPUT = 4,
  DISPATCH_PROPERTYPUTREF = 8,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
