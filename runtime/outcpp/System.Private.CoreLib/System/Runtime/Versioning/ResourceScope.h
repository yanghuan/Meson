#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope : int32_t {
  None = 0,
  Machine = 1,
  Process = 2,
  AppDomain = 4,
  Library = 8,
  Private = 16,
  Assembly = 32,
};
} // namespace System::Private::CoreLib::System::Runtime::Versioning
