#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class PlatformID : int32_t {
  Win32S = 0,
  Win32Windows = 1,
  Win32NT = 2,
  WinCE = 3,
  Unix = 4,
  Xbox = 5,
  MacOSX = 6,
  Other = 7,
};
} // namespace System::Private::CoreLib::System
