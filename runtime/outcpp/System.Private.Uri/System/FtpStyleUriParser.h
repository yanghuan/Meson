#pragma once

#include <rt/GCObject.h>

namespace System::Private::Uri::System {
namespace FtpStyleUriParserNamespace {
CLASS(FtpStyleUriParser) {
  public: void Ctor();
};
} // namespace FtpStyleUriParserNamespace
using FtpStyleUriParser = FtpStyleUriParserNamespace::FtpStyleUriParser;
} // namespace System::Private::Uri::System
