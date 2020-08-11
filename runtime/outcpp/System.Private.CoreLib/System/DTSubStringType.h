#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class DTSubStringType : int32_t {
  Unknown = 0,
  Invalid = 1,
  Number = 2,
  End = 3,
  Other = 4,
};
} // namespace System::Private::CoreLib::System
