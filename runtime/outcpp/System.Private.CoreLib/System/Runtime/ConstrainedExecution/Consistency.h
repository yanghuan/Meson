#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
enum class Consistency : int32_t {
  MayCorruptProcess = 0,
  MayCorruptAppDomain = 1,
  MayCorruptInstance = 2,
  WillNotCorruptState = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
