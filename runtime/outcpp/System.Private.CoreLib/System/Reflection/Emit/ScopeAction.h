#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class ScopeAction : int8_t {
  Open = -1,
  Close = 1,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
