#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Collections::Generic {
enum class InsertionBehavior : uint8_t {
  None = 0,
  OverwriteExisting = 1,
  ThrowOnExisting = 2,
};
} // namespace System::Private::CoreLib::System::Collections::Generic
