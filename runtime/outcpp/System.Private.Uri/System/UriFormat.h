#pragma once

#include <cstdint>

namespace System::Private::Uri::System {
enum class UriFormat : int32_t {
  UriEscaped = 1,
  Unescaped = 2,
  SafeUnescaped = 3,
};
} // namespace System::Private::Uri::System
