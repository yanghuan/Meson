#include "GenericUriParser-dep.h"

namespace System::Private::Uri::System::GenericUriParserNamespace {
void GenericUriParser___::ctor(GenericUriParserOptions options) {
}

UriSyntaxFlags GenericUriParser___::MapGenericParserOptions(GenericUriParserOptions options) {
  UriSyntaxFlags uriSyntaxFlags = UriSyntaxFlags::MustHaveAuthority | UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::MayHavePath | UriSyntaxFlags::MayHaveQuery | UriSyntaxFlags::MayHaveFragment | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host | UriSyntaxFlags::PathIsRooted | UriSyntaxFlags::ConvertPathSlashes | UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath | UriSyntaxFlags::UnEscapeDotsAndSlashes;
  if ((options & GenericUriParserOptions::GenericAuthority) != 0) {
    uriSyntaxFlags &= ~(UriSyntaxFlags::MayHaveUserInfo | UriSyntaxFlags::MayHavePort | UriSyntaxFlags::AllowUncHost | UriSyntaxFlags::AllowDnsHost | UriSyntaxFlags::AllowIPv4Host | UriSyntaxFlags::AllowIPv6Host);
    uriSyntaxFlags |= UriSyntaxFlags::AllowAnyOtherHost;
  }
  if ((options & GenericUriParserOptions::AllowEmptyAuthority) != 0) {
    uriSyntaxFlags |= UriSyntaxFlags::AllowEmptyHost;
  }
  if ((options & GenericUriParserOptions::NoUserInfo) != 0) {
    uriSyntaxFlags &= ~UriSyntaxFlags::MayHaveUserInfo;
  }
  if ((options & GenericUriParserOptions::NoPort) != 0) {
    uriSyntaxFlags &= ~UriSyntaxFlags::MayHavePort;
  }
  if ((options & GenericUriParserOptions::NoQuery) != 0) {
    uriSyntaxFlags &= ~UriSyntaxFlags::MayHaveQuery;
  }
  if ((options & GenericUriParserOptions::NoFragment) != 0) {
    uriSyntaxFlags &= ~UriSyntaxFlags::MayHaveFragment;
  }
  if ((options & GenericUriParserOptions::DontConvertPathBackslashes) != 0) {
    uriSyntaxFlags &= ~UriSyntaxFlags::ConvertPathSlashes;
  }
  if ((options & GenericUriParserOptions::DontCompressPath) != 0) {
    uriSyntaxFlags &= ~(UriSyntaxFlags::CompressPath | UriSyntaxFlags::CanonicalizeAsFilePath);
  }
  if ((options & GenericUriParserOptions::DontUnescapePathDotsAndSlashes) != 0) {
    uriSyntaxFlags &= ~UriSyntaxFlags::UnEscapeDotsAndSlashes;
  }
  if ((options & GenericUriParserOptions::Idn) != 0) {
    uriSyntaxFlags |= UriSyntaxFlags::AllowIdn;
  }
  if ((options & GenericUriParserOptions::IriParsing) != 0) {
    uriSyntaxFlags |= UriSyntaxFlags::AllowIriParsing;
  }
  return uriSyntaxFlags;
}

} // namespace System::Private::Uri::System::GenericUriParserNamespace
