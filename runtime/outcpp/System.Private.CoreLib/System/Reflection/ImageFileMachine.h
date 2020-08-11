#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class ImageFileMachine : int32_t {
  I386 = 332,
  IA64 = 512,
  AMD64 = 34404,
  ARM = 452,
};
} // namespace System::Private::CoreLib::System::Reflection
