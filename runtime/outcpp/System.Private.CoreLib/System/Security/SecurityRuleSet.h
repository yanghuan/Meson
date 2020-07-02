#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security {
enum class SecurityRuleSet : uint8_t {
  None = 0,
  Level1 = 1,
  Level2 = 2,
};
} // namespace System::Private::CoreLib::System::Security
