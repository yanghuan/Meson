#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode : int32_t {
  None = 0,
  PublicationOnly = 1,
  ExecutionAndPublication = 2,
};
} // namespace System::Private::CoreLib::System::Threading
