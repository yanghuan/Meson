#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::IO {
enum class FileAccess : int32_t {
  Read = 1,
  Write = 2,
  ReadWrite = 3,
};
} // namespace System::Private::CoreLib::System::IO
