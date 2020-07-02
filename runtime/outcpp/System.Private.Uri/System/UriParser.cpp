#include "UriParser-dep.h"

#include <System.Private.Uri/System/UriParser-dep.h>

namespace System::Private::Uri::System::UriParserNamespace {
String UriParser___::get_SchemeName() {
  return nullptr;
};
Int32 UriParser___::get_DefaultPort() {
  return Int32();
};
Boolean UriParser___::get_DontEnableStrictRFC3986ReservedCharacterSets() {
  return Boolean();
};
Boolean UriParser___::get_DontKeepUnicodeBidiFormattingCharacters() {
  return Boolean();
};
UriSyntaxFlags UriParser___::get_Flags() {
  return UriSyntaxFlags();
};
Boolean UriParser___::get_IsSimple() {
  return Boolean();
};
UriParser UriParser___::OnNewUri() {
  return nullptr;
};
void UriParser___::OnRegister(String schemeName, Int32 defaultPort) {
  return void();
};
void UriParser___::InitializeAndValidate(Uri uri, UriFormatException& parsingError) {
  return void();
};
String UriParser___::Resolve(Uri baseUri, Uri relativeUri, UriFormatException& parsingError) {
  return nullptr;
};
Boolean UriParser___::IsBaseOf(Uri baseUri, Uri relativeUri) {
  return Boolean();
};
String UriParser___::GetComponents(Uri uri, UriComponents components, UriFormat format) {
  return nullptr;
};
Boolean UriParser___::IsWellFormedOriginalString(Uri uri) {
  return Boolean();
};
void UriParser___::Register(UriParser uriParser, String schemeName, Int32 defaultPort) {
  return void();
};
Boolean UriParser___::IsKnownScheme(String schemeName) {
  return Boolean();
};
Boolean UriParser___::NotAny(UriSyntaxFlags flags) {
  return Boolean();
};
Boolean UriParser___::InFact(UriSyntaxFlags flags) {
  return Boolean();
};
Boolean UriParser___::IsAllSet(UriSyntaxFlags flags) {
  return Boolean();
};
Boolean UriParser___::IsFullMatch(UriSyntaxFlags flags, UriSyntaxFlags expected) {
  return Boolean();
};
void UriParser___::FetchSyntax(UriParser syntax, String lwrCaseSchemeName, Int32 defaultPort) {
  return void();
};
UriParser UriParser___::FindOrFetchAsUnknownV1Syntax(String lwrCaseScheme) {
  return nullptr;
};
UriParser UriParser___::GetSyntax(String lwrCaseScheme) {
  return nullptr;
};
void UriParser___::CheckSetIsSimpleFlag() {
  return void();
};
UriParser UriParser___::InternalOnNewUri() {
  return nullptr;
};
void UriParser___::InternalValidate(Uri thisUri, UriFormatException& parsingError) {
  return void();
};
String UriParser___::InternalResolve(Uri thisBaseUri, Uri uriLink, UriFormatException& parsingError) {
  return nullptr;
};
Boolean UriParser___::InternalIsBaseOf(Uri thisBaseUri, Uri uriLink) {
  return Boolean();
};
String UriParser___::InternalGetComponents(Uri thisUri, UriComponents uriComponents, UriFormat uriFormat) {
  return nullptr;
};
Boolean UriParser___::InternalIsWellFormedOriginalString(Uri thisUri) {
  return Boolean();
};
} // namespace System::Private::Uri::System::UriParserNamespace
