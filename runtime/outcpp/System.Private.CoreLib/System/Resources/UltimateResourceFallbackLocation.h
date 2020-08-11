#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Resources {
enum class UltimateResourceFallbackLocation : int32_t {
  MainAssembly = 0,
  Satellite = 1,
};
} // namespace System::Private::CoreLib::System::Resources
