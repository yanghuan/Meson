#include "UriParser-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Collections/Hashtable-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.Uri/System/FileStyleUriParser-dep.h>
#include <System.Private.Uri/System/FtpStyleUriParser-dep.h>
#include <System.Private.Uri/System/GenericUriParser-dep.h>
#include <System.Private.Uri/System/GopherStyleUriParser-dep.h>
#include <System.Private.Uri/System/HttpStyleUriParser-dep.h>
#include <System.Private.Uri/System/LdapStyleUriParser-dep.h>
#include <System.Private.Uri/System/NetPipeStyleUriParser-dep.h>
#include <System.Private.Uri/System/NetTcpStyleUriParser-dep.h>
#include <System.Private.Uri/System/NewsStyleUriParser-dep.h>
#include <System.Private.Uri/System/SR-dep.h>
#include <System.Private.Uri/System/UriParser-dep.h>

namespace System::Private::Uri::System::UriParserNamespace {
using namespace ::System::Private::CoreLib::Internal::Runtime::CompilerServices;
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections;
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
  if ((num & 4611686018427387904) != 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_InitializeCalledAlreadyOrTooLate());
  }
  parsingError = uri->ParseMinimal();
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
  if ((components & UriComponents::SerializationInfoString) != 0 && components != UriComponents::SerializationInfoString) {
    rt::throw_exception<ArgumentOutOfRangeException>("components", components, SR::get_net_uri_NotJustSerialization());
  }
  if ((format & (UriFormat)(-4)) != 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("format");
  }
  if (uri->get_UserDrivenParsing()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_UserDrivenParsing(), GetType()));
  }
  if (!uri->get_IsAbsoluteUri()) {
    rt::throw_exception<InvalidOperationException>(SR::get_net_uri_NotAbsolute());
  }
  return uri->GetComponentsHelper(components, format);
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
  UriParser syntax = GetSyntax(schemeName->ToLowerInvariant());
  if (syntax != nullptr) {
    return syntax->NotAny(UriSyntaxFlags::V1_UnknownUri);
  }
  return false;
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
  return (_flags & flags) == expected;
}

void UriParser___::ctor(UriSyntaxFlags flags) {
  _flags = flags;
  _scheme = String::in::Empty;
}

void UriParser___::FetchSyntax(UriParser syntax, String lwrCaseSchemeName, Int32 defaultPort) {
  if (syntax->get_SchemeName()->get_Length() != 0) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_NeedFreshParser(), syntax->get_SchemeName()));
  }
  {
    rt::lock(s_table);
    syntax->_flags &= ~UriSyntaxFlags::V1_UnknownUri;
    UriParser uriParser = (UriParser)s_table[lwrCaseSchemeName];
    if (uriParser != nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_net_uri_AlreadyRegistered(), uriParser->get_SchemeName()));
    }
    uriParser = (UriParser)s_tempTable[syntax->get_SchemeName()];
    if (uriParser != nullptr) {
      lwrCaseSchemeName = uriParser->_scheme;
      s_tempTable->Remove(lwrCaseSchemeName);
    }
    syntax->OnRegister(lwrCaseSchemeName, defaultPort);
    syntax->_scheme = lwrCaseSchemeName;
    syntax->CheckSetIsSimpleFlag();
    syntax->_port = defaultPort;
    s_table[syntax->get_SchemeName()] = syntax;
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
  {
    rt::lock(s_table);
    if (s_tempTable->get_Count() >= 512) {
      s_tempTable = rt::newobj<Hashtable>(25);
    }
    uriParser = rt::newobj<BuiltInUriParser>(lwrCaseScheme, -1, UriSyntaxFlags::OptionalAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::V1_UnknownUri | UriSyntaxFlags::AllowDOSPath | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
    s_tempTable[lwrCaseScheme] = uriParser;
    return uriParser;
  }
}

UriParser UriParser___::GetSyntax(String lwrCaseScheme) {
  Object as = s_table[lwrCaseScheme];
  return (UriParser)(as != nullptr ? as : s_tempTable[lwrCaseScheme]);
}

void UriParser___::CheckSetIsSimpleFlag() {
  Type type = GetType();
  if (type == typeof<GenericUriParser>() || type == typeof<HttpStyleUriParser>() || type == typeof<FtpStyleUriParser>() || type == typeof<FileStyleUriParser>() || type == typeof<NewsStyleUriParser>() || type == typeof<GopherStyleUriParser>() || type == typeof<NetPipeStyleUriParser>() || type == typeof<NetTcpStyleUriParser>() || type == typeof<LdapStyleUriParser>()) {
    _flags |= UriSyntaxFlags::SimpleUserSyntax;
  }
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
  HttpUri = rt::newobj<BuiltInUriParser>("http", 80, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  HttpsUri = rt::newobj<BuiltInUriParser>("https", 443, HttpUri->_flags);
  WsUri = rt::newobj<BuiltInUriParser>("ws", 80, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  WssUri = rt::newobj<BuiltInUriParser>("wss", 443, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  FtpUri = rt::newobj<BuiltInUriParser>("ftp", 21, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  FileUri = rt::newobj<BuiltInUriParser>("file", -1, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::FileLikeUri | UriSyntaxFlags::AllowDOSPath | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::UnEscapeDotsAndSlashes | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  UnixFileUri = rt::newobj<BuiltInUriParser>("file", -1, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::FileLikeUri | UriSyntaxFlags::AllowDOSPath | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::UnEscapeDotsAndSlashes | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  GopherUri = rt::newobj<BuiltInUriParser>("gopher", 70, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  NntpUri = rt::newobj<BuiltInUriParser>("nntp", 119, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  NewsUri = rt::newobj<BuiltInUriParser>("news", -1, UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowIriParsing);
  MailToUri = rt::newobj<BuiltInUriParser>("mailto", 25, UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::MailToLikeUri | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  UuidUri = rt::newobj<BuiltInUriParser>("uuid", -1, NewsUri->_flags);
  TelnetUri = rt::newobj<BuiltInUriParser>("telnet", 23, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  LdapUri = rt::newobj<BuiltInUriParser>("ldap", 389, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  NetTcpUri = rt::newobj<BuiltInUriParser>("net.tcp", 808, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::UnEscapeDotsAndSlashes | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  NetPipeUri = rt::newobj<BuiltInUriParser>("net.pipe", -1, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::UnEscapeDotsAndSlashes | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  VsMacrosUri = rt::newobj<BuiltInUriParser>("vsmacros", -1, UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowEmptyHost | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::FileLikeUri | UriSyntaxFlags::AllowDOSPath | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::UnEscapeDotsAndSlashes | UriSyntaxFlags::AllowIdn | UriSyntaxFlags::AllowIriParsing);
  s_table = rt::newobj<Hashtable>(16);
  s_tempTable = rt::newobj<Hashtable>(25);
}

} // namespace System::Private::Uri::System::UriParserNamespace
