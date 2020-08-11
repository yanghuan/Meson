#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComWrappersScenario : int32_t {
  Instance = 0,
  TrackerSupportGlobalInstance = 1,
  MarshallingGlobalInstance = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
