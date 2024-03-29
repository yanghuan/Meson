#pragma once

#include <cstdint>

namespace System::Private::Uri::System {
enum class UriPartial : int32_t {
  Scheme = 0,
  Authority = 1,
  Path = 2,
  Query = 3,
};
} // namespace System::Private::Uri::System
