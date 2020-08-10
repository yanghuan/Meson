#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace NetPipeStyleUriParserNamespace {
CLASS(NetPipeStyleUriParser) : public UriParser::in {
  public: void ctor();
};
} // namespace NetPipeStyleUriParserNamespace
using NetPipeStyleUriParser = NetPipeStyleUriParserNamespace::NetPipeStyleUriParser;
} // namespace System::Private::Uri::System
