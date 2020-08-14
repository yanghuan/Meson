#include "UriParser-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/UriParser-dep.h>

namespace System::Private::Uri::System::UriParserNamespace {
using namespace ::System::Private::CoreLib::Internal::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;

void BuiltInUriParser___::ctor(String lwrCaseScheme, Int32 defaultPort, UriSyntaxFlags syntaxFlags) {
  _scheme = lwrCaseScheme;
  _port = defaultPort;
}

String UriParser___::get_SchemeName() {
  return _scheme;
}

Int32 UriParser___::get_DefaultPort() {
  return _port;
}

UriSyntaxFlags UriParser___::get_Flags() {
  return _flags;
}

Boolean UriParser___::get_IsSimple() {
  return InFact(UriSyntaxFlags::SimpleUserSyntax);
}

void UriParser___::ctor() {
}

UriParser UriParser___::OnNewUri() {
  return (UriParser)this;
}

void UriParser___::OnRegister(String schemeName, Int32 defaultPort) {
}

void UriParser___::InitializeAndValidate(Uri uri, UriFormatException& parsingError) {
  if (uri->_syntax == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  if (uri->_syntax != (UriParser)this) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_UserDrivenParsing(), uri->_syntax->GetType()));
  }
  UInt64 num = Interlocked::Or(Unsafe::As<Uri::in::Flags, UInt64>(uri->_flags), 4611686018427387904);
}

String UriParser___::Resolve(Uri baseUri, Uri relativeUri, UriFormatException& parsingError) {
  if (baseUri->get_UserDrivenParsing()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_UserDrivenParsing(), GetType()));
  }
  if (!baseUri->get_IsAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  String newUriString = nullptr;
  Boolean userEscaped = false;
  parsingError = nullptr;
  Uri uri = Uri::in::ResolveHelper(baseUri, relativeUri, newUriString, userEscaped);
  if (uri != nullptr) {
    return uri->get_OriginalString();
  }
  return newUriString;
}

Boolean UriParser___::IsBaseOf(Uri baseUri, Uri relativeUri) {
  return baseUri->IsBaseOfHelper(relativeUri);
}

String UriParser___::GetComponents(Uri uri, UriComponents components, UriFormat format) {
}

Boolean UriParser___::IsWellFormedOriginalString(Uri uri) {
  return uri->InternalIsWellFormedOriginalString();
}

void UriParser___::Register(UriParser uriParser, String schemeName, Int32 defaultPort) {
  if (uriParser == nullptr) {
    rt::throw_exception<ArgumentNullException>("uriParser");
  }
  if (schemeName == nullptr) {
    rt::throw_exception<ArgumentNullException>("schemeName");
  }
  if (schemeName->get_Length() == 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("schemeName");
  }
  if (!Uri::in::CheckSchemeName(schemeName)) {
    rt::throw_exception<ArgumentOutOfRangeException>("schemeName");
  }
  if ((defaultPort >= 65535 || defaultPort < 0) && defaultPort != -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("defaultPort");
  }
  schemeName = schemeName->ToLowerInvariant();
  FetchSyntax(uriParser, schemeName, defaultPort);
}

Boolean UriParser___::IsKnownScheme(String schemeName) {
  if (schemeName == nullptr) {
    rt::throw_exception<ArgumentNullException>("schemeName");
  }
  if (!Uri::in::CheckSchemeName(schemeName)) {
    rt::throw_exception<ArgumentOutOfRangeException>("schemeName");
  }
}

Boolean UriParser___::NotAny(UriSyntaxFlags flags) {
  return IsFullMatch(flags, UriSyntaxFlags::None);
}

Boolean UriParser___::InFact(UriSyntaxFlags flags) {
  return !IsFullMatch(flags, UriSyntaxFlags::None);
}

Boolean UriParser___::IsAllSet(UriSyntaxFlags flags) {
  return IsFullMatch(flags, flags);
}

Boolean UriParser___::IsFullMatch(UriSyntaxFlags flags, UriSyntaxFlags expected) {
}

void UriParser___::ctor(UriSyntaxFlags flags) {
  _flags = flags;
  _scheme = String::in::Empty;
}

void UriParser___::FetchSyntax(UriParser syntax, String lwrCaseSchemeName, Int32 defaultPort) {
  if (syntax->get_SchemeName()->get_Length() != 0) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_NeedFreshParser(), syntax->get_SchemeName()));
  }
}

UriParser UriParser___::FindOrFetchAsUnknownV1Syntax(String lwrCaseScheme) {
  UriParser uriParser = (UriParser)s_table[lwrCaseScheme];
  if (uriParser != nullptr) {
    return uriParser;
  }
  uriParser = (UriParser)s_tempTable[lwrCaseScheme];
  if (uriParser != nullptr) {
    return uriParser;
  }
}

UriParser UriParser___::GetSyntax(String lwrCaseScheme) {
}

void UriParser___::CheckSetIsSimpleFlag() {
  Type type = GetType();
}

UriParser UriParser___::InternalOnNewUri() {
  UriParser uriParser = OnNewUri();
  if ((UriParser)this != uriParser) {
    uriParser->_scheme = _scheme;
    uriParser->_port = _port;
    uriParser->_flags = _flags;
  }
  return uriParser;
}

void UriParser___::InternalValidate(Uri thisUri, UriFormatException& parsingError) {
  InitializeAndValidate(thisUri, parsingError);
  Interlocked::Or(Unsafe::As<Uri::in::Flags, UInt64>(thisUri->_flags), 4611686018427387904);
}

String UriParser___::InternalResolve(Uri thisBaseUri, Uri uriLink, UriFormatException& parsingError) {
  return Resolve(thisBaseUri, uriLink, parsingError);
}

Boolean UriParser___::InternalIsBaseOf(Uri thisBaseUri, Uri uriLink) {
  return IsBaseOf(thisBaseUri, uriLink);
}

String UriParser___::InternalGetComponents(Uri thisUri, UriComponents uriComponents, UriFormat uriFormat) {
  return GetComponents(thisUri, uriComponents, uriFormat);
}

Boolean UriParser___::InternalIsWellFormedOriginalString(Uri thisUri) {
  return IsWellFormedOriginalString(thisUri);
}

void UriParser___::cctor() {
}

} // namespace System::Private::Uri::System::UriParserNamespace
