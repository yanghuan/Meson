#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Buffers {
enum class OperationStatus : int32_t {
  Done = 0,
  DestinationTooSmall = 1,
  NeedMoreData = 2,
  InvalidData = 3,
};
} // namespace System::Private::CoreLib::System::Buffers
