#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class GCCollectionMode : int32_t {
  Default = 0,
  Forced = 1,
  Optimized = 2,
};
} // namespace System::Private::CoreLib::System
