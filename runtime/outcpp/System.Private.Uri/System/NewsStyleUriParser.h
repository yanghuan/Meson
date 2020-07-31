#pragma once

#include <rt/GCObject.h>
#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace NewsStyleUriParserNamespace {
CLASS(NewsStyleUriParser) : public UriParser::in {
  public: void Ctor();
};
} // namespace NewsStyleUriParserNamespace
using NewsStyleUriParser = NewsStyleUriParserNamespace::NewsStyleUriParser;
} // namespace System::Private::Uri::System
