#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class GCHandleType : int32_t {
  Weak = 0,
  WeakTrackResurrection = 1,
  Normal = 2,
  Pinned = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
