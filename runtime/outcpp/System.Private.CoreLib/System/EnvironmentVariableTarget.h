#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class EnvironmentVariableTarget : int32_t {
  Process = 0,
  User = 1,
  Machine = 2,
};
} // namespace System::Private::CoreLib::System
