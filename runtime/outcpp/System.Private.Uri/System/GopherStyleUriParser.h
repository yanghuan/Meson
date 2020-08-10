#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace GopherStyleUriParserNamespace {
CLASS(GopherStyleUriParser) : public UriParser::in {
  public: void ctor();
};
} // namespace GopherStyleUriParserNamespace
using GopherStyleUriParser = GopherStyleUriParserNamespace::GopherStyleUriParser;
} // namespace System::Private::Uri::System
