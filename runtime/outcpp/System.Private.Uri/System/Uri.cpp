#include "Uri-dep.h"

#include <System.Private.Uri/System/Uri-dep.h>

namespace System::Private::Uri::System::UriNamespace {
Boolean Uri___::get_IsImplicitFile() {
  return Boolean();
};
Boolean Uri___::get_IsUncOrDosPath() {
  return Boolean();
};
Boolean Uri___::get_IsDosPath() {
  return Boolean();
};
Boolean Uri___::get_IsUncPath() {
  return Boolean();
};
Uri::in::Flags Uri___::get_HostType() {
  return Uri::in::Flags();
};
UriParser Uri___::get_Syntax() {
  return nullptr;
};
Boolean Uri___::get_IsNotAbsoluteUri() {
  return Boolean();
};
Boolean Uri___::get_AllowIdn() {
  return Boolean();
};
Boolean Uri___::get_UserDrivenParsing() {
  return Boolean();
};
UInt16 Uri___::get_SecuredPathIndex() {
  return UInt16();
};
String Uri___::get_AbsolutePath() {
  return nullptr;
};
String Uri___::get_PrivateAbsolutePath() {
  return nullptr;
};
String Uri___::get_AbsoluteUri() {
  return nullptr;
};
String Uri___::get_LocalPath() {
  return nullptr;
};
String Uri___::get_Authority() {
  return nullptr;
};
UriHostNameType Uri___::get_HostNameType() {
  return UriHostNameType();
};
Boolean Uri___::get_IsDefaultPort() {
  return Boolean();
};
Boolean Uri___::get_IsFile() {
  return Boolean();
};
Boolean Uri___::get_IsLoopback() {
  return Boolean();
};
String Uri___::get_PathAndQuery() {
  return nullptr;
};
Array<String> Uri___::get_Segments() {
  return Array<String>();
};
Boolean Uri___::get_IsUnc() {
  return Boolean();
};
String Uri___::get_Host() {
  return nullptr;
};
Int32 Uri___::get_Port() {
  return Int32();
};
String Uri___::get_Query() {
  return nullptr;
};
String Uri___::get_Fragment() {
  return nullptr;
};
String Uri___::get_Scheme() {
  return nullptr;
};
Boolean Uri___::get_OriginalStringSwitched() {
  return Boolean();
};
String Uri___::get_OriginalString() {
  return nullptr;
};
String Uri___::get_DnsSafeHost() {
  return nullptr;
};
String Uri___::get_IdnHost() {
  return nullptr;
};
Boolean Uri___::get_IsAbsoluteUri() {
  return Boolean();
};
Boolean Uri___::get_UserEscaped() {
  return Boolean();
};
String Uri___::get_UserInfo() {
  return nullptr;
};
Boolean Uri___::get_HasAuthority() {
  return Boolean();
};
Boolean Uri___::IriParsingStatic(UriParser syntax) {
  return Boolean();
};
Boolean Uri___::AllowIdnStatic(UriParser syntax, Flags flags) {
  return Boolean();
};
Boolean Uri___::IsIntranet(String schemeHost) {
  return Boolean();
};
void Uri___::SetUserDrivenParsing() {
};
Boolean Uri___::NotAny(Flags flags) {
  return Boolean();
};
Boolean Uri___::InFact(Flags flags) {
  return Boolean();
};
Boolean Uri___::StaticNotAny(Flags allFlags, Flags checkFlags) {
  return Boolean();
};
Boolean Uri___::StaticInFact(Flags allFlags, Flags checkFlags) {
  return Boolean();
};
Uri::in::UriInfo Uri___::EnsureUriInfo() {
  return nullptr;
};
void Uri___::EnsureParseRemaining() {
};
void Uri___::EnsureHostString(Boolean allowDnsOptimization) {
};
void Uri___::GetObjectData(SerializationInfo serializationInfo, StreamingContext streamingContext) {
};
void Uri___::CreateUri(Uri baseUri, String relativeUri, Boolean dontEscape) {
};
ParsingError Uri___::GetCombinedString(Uri baseUri, String relativeStr, Boolean dontEscape, String& result) {
  return ParsingError();
};
UriFormatException Uri___::GetException(ParsingError err) {
  return nullptr;
};
Boolean Uri___::StaticIsFile(UriParser syntax) {
  return Boolean();
};
String Uri___::GetLocalPath() {
  return nullptr;
};
UriHostNameType Uri___::CheckHostName(String name) {
  return UriHostNameType();
};
String Uri___::GetLeftPart(UriPartial part) {
  return nullptr;
};
String Uri___::HexEscape(Char character) {
  return nullptr;
};
Char Uri___::HexUnescape(String pattern, Int32& index) {
  return Char();
};
Boolean Uri___::IsHexEncoding(String pattern, Int32 index) {
  return Boolean();
};
Boolean Uri___::CheckSchemeName(String schemeName) {
  return Boolean();
};
Boolean Uri___::IsHexDigit(Char character) {
  return Boolean();
};
Int32 Uri___::FromHex(Char digit) {
  return Int32();
};
Int32 Uri___::GetHashCode() {
  return Int32();
};
String Uri___::ToString() {
  return nullptr;
};
Boolean Uri___::Equals(Object comparand) {
  return Boolean();
};
Uri Uri___::MakeRelativeUri(Uri uri) {
  return nullptr;
};
Boolean Uri___::CheckForColonInFirstPathSegment(String uriString) {
  return Boolean();
};
String Uri___::InternalEscapeString(String rawString) {
  return nullptr;
};
ParsingError Uri___::ParseScheme(String uriString, Flags& flags, UriParser& syntax) {
  return ParsingError();
};
UriFormatException Uri___::ParseMinimal() {
  return nullptr;
};
ParsingError Uri___::PrivateParseMinimal() {
  return ParsingError();
};
void Uri___::PrivateParseMinimalIri(String newHost, UInt16 idx) {
};
void Uri___::CreateUriInfo(Flags cF) {
};
void Uri___::CreateHostString() {
};
String Uri___::CreateHostStringHelper(String str, UInt16 idx, UInt16 end, Flags& flags, String& scopeId) {
  return nullptr;
};
void Uri___::GetHostViaCustomSyntax() {
};
String Uri___::GetParts(UriComponents uriParts, UriFormat formatAs) {
  return nullptr;
};
String Uri___::GetEscapedParts(UriComponents uriParts) {
  return nullptr;
};
String Uri___::GetUnescapedParts(UriComponents uriParts, UriFormat formatAs) {
  return nullptr;
};
String Uri___::ReCreateParts(UriComponents parts, UInt16 nonCanonical, UriFormat formatAs) {
  return nullptr;
};
String Uri___::GetUriPartsFromUserString(UriComponents uriParts) {
  return nullptr;
};
void Uri___::GetLengthWithoutTrailingSpaces(String str, UInt16& length, Int32 idx) {
};
void Uri___::ParseRemaining() {
};
UInt16 Uri___::ParseSchemeCheckImplicitFile(Char* uriString, UInt16 length, ParsingError& err, Flags& flags, UriParser& syntax) {
  return UInt16();
};
Boolean Uri___::CheckKnownSchemes(Int64* lptr, UInt16 nChars, UriParser& syntax) {
  return Boolean();
};
ParsingError Uri___::CheckSchemeSyntax(ReadOnlySpan<Char> span, UriParser& syntax) {
  return ParsingError();
};
UInt16 Uri___::CheckAuthorityHelper(Char* pString, UInt16 idx, UInt16 length, ParsingError& err, Flags& flags, UriParser syntax, String& newHost) {
  return UInt16();
};
void Uri___::CheckAuthorityHelperHandleDnsIri(Char* pString, UInt16 start, Int32 end, Int32 startInput, Boolean iriParsing, Boolean hasUnicode, UriParser syntax, String userInfoString, Flags& flags, Boolean& justNormalized, String& newHost, ParsingError& err) {
};
void Uri___::CheckAuthorityHelperHandleAnyHostIri(Char* pString, Int32 startInput, Int32 end, Boolean iriParsing, Boolean hasUnicode, UriParser syntax, Flags& flags, String& newHost, ParsingError& err) {
};
void Uri___::FindEndOfComponent(String input, UInt16& idx, UInt16 end, Char delim) {
};
void Uri___::FindEndOfComponent(Char* str, UInt16& idx, UInt16 end, Char delim) {
};
Uri::in::Check Uri___::CheckCanonical(Char* str, UInt16& idx, UInt16 end, Char delim) {
  return Uri::in::Check();
};
Array<Char> Uri___::GetCanonicalPath(Array<Char> dest, Int32& pos, UriFormat formatAs) {
  return Array<Char>();
};
void Uri___::UnescapeOnly(Char* pch, Int32 start, Int32& end, Char ch1, Char ch2, Char ch3) {
};
Array<Char> Uri___::Compress(Array<Char> dest, UInt16 start, Int32& destLength, UriParser syntax) {
  return Array<Char>();
};
Int32 Uri___::CalculateCaseInsensitiveHashCode(String text) {
  return Int32();
};
String Uri___::CombineUri(Uri basePart, String relativePart, UriFormat uriFormat) {
  return nullptr;
};
String Uri___::PathDifference(String path1, String path2, Boolean compareCase) {
  return nullptr;
};
String Uri___::MakeRelative(Uri toUri) {
  return nullptr;
};
void Uri___::Canonicalize() {
};
void Uri___::Parse() {
};
void Uri___::Escape() {
};
String Uri___::Unescape(String path) {
  return nullptr;
};
String Uri___::EscapeString(String str) {
  return nullptr;
};
void Uri___::CheckSecurity() {
};
Boolean Uri___::IsReservedCharacter(Char character) {
  return Boolean();
};
Boolean Uri___::IsExcludedCharacter(Char character) {
  return Boolean();
};
Boolean Uri___::IsBadFileSystemCharacter(Char character) {
  return Boolean();
};
void Uri___::CreateThis(String uri, Boolean dontEscape, UriKind uriKind) {
};
void Uri___::InitializeUri(ParsingError err, UriKind uriKind, UriFormatException& e) {
};
Boolean Uri___::CheckForUnicode(String data) {
  return Boolean();
};
Boolean Uri___::CheckForEscapedUnreserved(String data) {
  return Boolean();
};
Boolean Uri___::TryCreate(String uriString, UriKind uriKind, Uri& result) {
  return Boolean();
};
Boolean Uri___::TryCreate(Uri baseUri, String relativeUri, Uri& result) {
  return Boolean();
};
Boolean Uri___::TryCreate(Uri baseUri, Uri relativeUri, Uri& result) {
  return Boolean();
};
String Uri___::GetComponents(UriComponents components, UriFormat format) {
  return nullptr;
};
Int32 Uri___::Compare(Uri uri1, Uri uri2, UriComponents partsToCompare, UriFormat compareFormat, StringComparison comparisonType) {
  return Int32();
};
Boolean Uri___::IsWellFormedOriginalString() {
  return Boolean();
};
Boolean Uri___::IsWellFormedUriString(String uriString, UriKind uriKind) {
  return Boolean();
};
Boolean Uri___::InternalIsWellFormedOriginalString() {
  return Boolean();
};
String Uri___::UnescapeDataString(String stringToUnescape) {
  return nullptr;
};
String Uri___::EscapeUriString(String stringToEscape) {
  return nullptr;
};
String Uri___::EscapeDataString(String stringToEscape) {
  return nullptr;
};
String Uri___::EscapeUnescapeIri(String input, Int32 start, Int32 end, UriComponents component) {
  return nullptr;
};
Uri Uri___::CreateHelper(String uriString, Boolean dontEscape, UriKind uriKind, UriFormatException& e) {
  return nullptr;
};
Uri Uri___::ResolveHelper(Uri baseUri, Uri relativeUri, String& newUriString, Boolean& userEscaped, UriFormatException& e) {
  return nullptr;
};
String Uri___::GetRelativeSerializationString(UriFormat format) {
  return nullptr;
};
String Uri___::GetComponentsHelper(UriComponents uriComponents, UriFormat uriFormat) {
  return nullptr;
};
Boolean Uri___::IsBaseOf(Uri uri) {
  return Boolean();
};
Boolean Uri___::IsBaseOfHelper(Uri uriLink) {
  return Boolean();
};
void Uri___::CreateThisFromUri(Uri otherUri) {
};
} // namespace System::Private::Uri::System::UriNamespace
