#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace NewsStyleUriParserNamespace {
CLASS(NewsStyleUriParser) : public UriParser::in {
  public: void ctor();
};
} // namespace NewsStyleUriParserNamespace
using NewsStyleUriParser = NewsStyleUriParserNamespace::NewsStyleUriParser;
} // namespace System::Private::Uri::System
