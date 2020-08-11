#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security::Principal {
enum class PrincipalPolicy : int32_t {
  UnauthenticatedPrincipal = 0,
  NoPrincipal = 1,
  WindowsPrincipal = 2,
};
} // namespace System::Private::CoreLib::System::Security::Principal
