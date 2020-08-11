#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Security::Permissions {
enum class PermissionState : int32_t {
  None = 0,
  Unrestricted = 1,
};
} // namespace System::Private::CoreLib::System::Security::Permissions
