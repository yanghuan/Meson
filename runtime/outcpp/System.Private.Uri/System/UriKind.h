#pragma once

#include <cstdint>

namespace System::Private::Uri::System {
enum class UriKind : int32_t {
  RelativeOrAbsolute = 0,
  Absolute = 1,
  Relative = 2,
};
} // namespace System::Private::Uri::System
