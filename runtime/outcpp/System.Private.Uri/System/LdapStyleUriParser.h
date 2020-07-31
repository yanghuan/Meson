#pragma once

#include <rt/GCObject.h>
#include <System.Private.Uri/System/UriParser.h>

namespace System::Private::Uri::System {
namespace LdapStyleUriParserNamespace {
CLASS(LdapStyleUriParser) : public UriParser::in {
  public: void Ctor();
};
} // namespace LdapStyleUriParserNamespace
using LdapStyleUriParser = LdapStyleUriParserNamespace::LdapStyleUriParser;
} // namespace System::Private::Uri::System
