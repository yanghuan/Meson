#pragma once

namespace System::Private::Uri::System {
enum class UriComponents {
  Scheme = 1,
  UserInfo = 2,
  Host = 4,
  Port = 8,
  Path = 16,
  Query = 32,
  Fragment = 64,
  StrongPort = 128,
  NormalizedHost = 256,
  KeepDelimiter = 1073741824,
  SerializationInfoString = -2147483647 - 1,
  AbsoluteUri = 127,
  HostAndPort = 132,
  StrongAuthority = 134,
  SchemeAndServer = 13,
  HttpRequestUrl = 61,
  PathAndQuery = 48,
};
} // namespace System::Private::Uri::System
