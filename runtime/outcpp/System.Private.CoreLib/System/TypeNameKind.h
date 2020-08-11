#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class TypeNameKind : int32_t {
  Name = 0,
  ToString = 1,
  FullName = 2,
};
} // namespace System::Private::CoreLib::System
