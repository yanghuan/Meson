#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention : int32_t {
  Winapi = 1,
  Cdecl = 2,
  StdCall = 3,
  ThisCall = 4,
  FastCall = 5,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
