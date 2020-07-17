#pragma once

#include <rt/GCObject.h>

namespace System::Private::Uri::System {
namespace LdapStyleUriParserNamespace {
CLASS(LdapStyleUriParser) {
  public: void Ctor();
};
} // namespace LdapStyleUriParserNamespace
using LdapStyleUriParser = LdapStyleUriParserNamespace::LdapStyleUriParser;
} // namespace System::Private::Uri::System
