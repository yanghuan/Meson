#pragma once

#include <rt/GCObject.h>

namespace System::Private::Uri::System {
namespace HttpStyleUriParserNamespace {
CLASS(HttpStyleUriParser) {
  public: void Ctor();
};
} // namespace HttpStyleUriParserNamespace
using HttpStyleUriParser = HttpStyleUriParserNamespace::HttpStyleUriParser;
} // namespace System::Private::Uri::System
