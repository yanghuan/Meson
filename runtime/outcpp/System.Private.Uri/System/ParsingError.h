#pragma once

#include <cstdint>

namespace System::Private::Uri::System {
enum class ParsingError : int32_t {
  None = 0,
  BadFormat = 1,
  BadScheme = 2,
  BadAuthority = 3,
  EmptyUriString = 4,
  LastRelativeUriOkErrIndex = 4,
  SchemeLimit = 5,
  SizeLimit = 6,
  MustRootedPath = 7,
  BadHostName = 8,
  NonEmptyHost = 9,
  BadPort = 10,
  BadAuthorityTerminator = 11,
  CannotCreateRelative = 12,
};
} // namespace System::Private::Uri::System
