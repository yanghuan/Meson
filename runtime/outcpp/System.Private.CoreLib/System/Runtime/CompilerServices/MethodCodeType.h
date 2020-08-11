#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class MethodCodeType : int32_t {
  IL = 0,
  Native = 1,
  OPTIL = 2,
  Runtime = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
