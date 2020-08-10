#pragma once

#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace FtpStyleUriParserNamespace {
CLASS(FtpStyleUriParser) : public UriParser::in {
  public: void ctor();
};
} // namespace FtpStyleUriParserNamespace
using FtpStyleUriParser = FtpStyleUriParserNamespace::FtpStyleUriParser;
} // namespace System::Private::Uri::System
