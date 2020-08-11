#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::IO {
enum class SeekOrigin : int32_t {
  Begin = 0,
  Current = 1,
  End = 2,
};
} // namespace System::Private::CoreLib::System::IO
