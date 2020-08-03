#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace HttpStyleUriParserNamespace {
CLASS(HttpStyleUriParser) : public UriParser::in {
  public: void Ctor();
};
} // namespace HttpStyleUriParserNamespace
using HttpStyleUriParser = HttpStyleUriParserNamespace::HttpStyleUriParser;
} // namespace System::Private::Uri::System
