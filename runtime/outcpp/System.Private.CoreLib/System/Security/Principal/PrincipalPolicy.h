#pragma once

namespace System::Private::CoreLib::System::Security::Principal {
enum class PrincipalPolicy {
  UnauthenticatedPrincipal = 0,
  NoPrincipal = 1,
  WindowsPrincipal = 2,
};
} // namespace System::Private::CoreLib::System::Security::Principal
