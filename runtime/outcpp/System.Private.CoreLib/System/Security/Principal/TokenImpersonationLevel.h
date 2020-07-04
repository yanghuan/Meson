#pragma once

namespace System::Private::CoreLib::System::Security::Principal {
enum class TokenImpersonationLevel {
  None = 0,
  Anonymous = 1,
  Identification = 2,
  Impersonation = 3,
  Delegation = 4,
};
} // namespace System::Private::CoreLib::System::Security::Principal
