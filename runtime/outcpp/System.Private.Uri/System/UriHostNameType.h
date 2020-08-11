#pragma once

#include <cstdint>

namespace System::Private::Uri::System {
enum class UriHostNameType : int32_t {
  Unknown = 0,
  Basic = 1,
  Dns = 2,
  IPv4 = 3,
  IPv6 = 4,
};
} // namespace System::Private::Uri::System
