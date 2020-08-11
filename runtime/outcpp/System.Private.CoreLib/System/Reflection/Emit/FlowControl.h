#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class FlowControl : int32_t {
  Branch = 0,
  Break = 1,
  Call = 2,
  Cond_Branch = 3,
  Meta = 4,
  Next = 5,
  Phi = 6,
  Return = 7,
  Throw = 8,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
