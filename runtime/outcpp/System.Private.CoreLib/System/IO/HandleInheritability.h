#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::IO {
enum class HandleInheritability : int32_t {
  None = 0,
  Inheritable = 1,
};
} // namespace System::Private::CoreLib::System::IO
