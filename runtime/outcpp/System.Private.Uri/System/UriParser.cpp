#include "UriParser-dep.h"

#include <System.Private.Uri/System/UriParser-dep.h>

namespace System::Private::Uri::System::UriParserNamespace {
void BuiltInUriParser___::ctor(String lwrCaseScheme, Int32 defaultPort, UriSyntaxFlags syntaxFlags) {
}

String UriParser___::get_SchemeName() {
  return nullptr;
}

Int32 UriParser___::get_DefaultPort() {
  return Int32();
}

UriSyntaxFlags UriParser___::get_Flags() {
  return UriSyntaxFlags::AllowIriParsing;
}

Boolean UriParser___::get_IsSimple() {
  return Boolean();
}

void UriParser___::ctor() {
}

UriParser UriParser___::OnNewUri() {
  return nullptr;
}

void UriParser___::OnRegister(String schemeName, Int32 defaultPort) {
}

void UriParser___::InitializeAndValidate(Uri uri, UriFormatException& parsingError) {
}

String UriParser___::Resolve(Uri baseUri, Uri relativeUri, UriFormatException& parsingError) {
  return nullptr;
}

Boolean UriParser___::IsBaseOf(Uri baseUri, Uri relativeUri) {
  return Boolean();
}

String UriParser___::GetComponents(Uri uri, UriComponents components, UriFormat format) {
  return nullptr;
}

Boolean UriParser___::IsWellFormedOriginalString(Uri uri) {
  return Boolean();
}

void UriParser___::Register(UriParser uriParser, String schemeName, Int32 defaultPort) {
}

Boolean UriParser___::IsKnownScheme(String schemeName) {
  return Boolean();
}

Boolean UriParser___::NotAny(UriSyntaxFlags flags) {
  return Boolean();
}

Boolean UriParser___::InFact(UriSyntaxFlags flags) {
  return Boolean();
}

Boolean UriParser___::IsAllSet(UriSyntaxFlags flags) {
  return Boolean();
}

Boolean UriParser___::IsFullMatch(UriSyntaxFlags flags, UriSyntaxFlags expected) {
  return Boolean();
}

void UriParser___::ctor(UriSyntaxFlags flags) {
}

void UriParser___::FetchSyntax(UriParser syntax, String lwrCaseSchemeName, Int32 defaultPort) {
}

UriParser UriParser___::FindOrFetchAsUnknownV1Syntax(String lwrCaseScheme) {
  return nullptr;
}

UriParser UriParser___::GetSyntax(String lwrCaseScheme) {
  return nullptr;
}

void UriParser___::CheckSetIsSimpleFlag() {
}

UriParser UriParser___::InternalOnNewUri() {
  return nullptr;
}

void UriParser___::InternalValidate(Uri thisUri, UriFormatException& parsingError) {
}

String UriParser___::InternalResolve(Uri thisBaseUri, Uri uriLink, UriFormatException& parsingError) {
  return nullptr;
}

Boolean UriParser___::InternalIsBaseOf(Uri thisBaseUri, Uri uriLink) {
  return Boolean();
}

String UriParser___::InternalGetComponents(Uri thisUri, UriComponents uriComponents, UriFormat uriFormat) {
  return nullptr;
}

Boolean UriParser___::InternalIsWellFormedOriginalString(Uri thisUri) {
  return Boolean();
}

void UriParser___::ctor_static() {
}

} // namespace System::Private::Uri::System::UriParserNamespace
