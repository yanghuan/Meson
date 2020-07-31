#pragma once

#include <rt/GCObject.h>
#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace FileStyleUriParserNamespace {
CLASS(FileStyleUriParser) : public UriParser::in {
  public: void Ctor();
};
} // namespace FileStyleUriParserNamespace
using FileStyleUriParser = FileStyleUriParserNamespace::FileStyleUriParser;
} // namespace System::Private::Uri::System
