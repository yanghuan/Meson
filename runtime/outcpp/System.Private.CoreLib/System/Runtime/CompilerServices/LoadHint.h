#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint : int32_t {
  Default = 0,
  Always = 1,
  Sometimes = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
