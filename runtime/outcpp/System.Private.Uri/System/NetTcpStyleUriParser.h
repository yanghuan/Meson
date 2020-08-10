#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace NetTcpStyleUriParserNamespace {
CLASS(NetTcpStyleUriParser) : public UriParser::in {
  public: void ctor();
};
} // namespace NetTcpStyleUriParserNamespace
using NetTcpStyleUriParser = NetTcpStyleUriParserNamespace::NetTcpStyleUriParser;
} // namespace System::Private::Uri::System
