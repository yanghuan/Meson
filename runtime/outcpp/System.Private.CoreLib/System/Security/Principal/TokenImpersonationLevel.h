#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security::Principal {
enum class TokenImpersonationLevel : int32_t {
  None = 0,
  Anonymous = 1,
  Identification = 2,
  Impersonation = 3,
  Delegation = 4,
};
} // namespace System::Private::CoreLib::System::Security::Principal
