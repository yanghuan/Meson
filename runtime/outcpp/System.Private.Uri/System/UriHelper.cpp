#include "UriHelper-dep.h"

namespace System::Private::Uri::System::UriHelperNamespace {
ReadOnlySpan<Boolean> UriHelper::get_UnreservedReservedTable() {
  return ReadOnlySpan<Boolean>();
};

ReadOnlySpan<Boolean> UriHelper::get_UnreservedTable() {
  return ReadOnlySpan<Boolean>();
};

Boolean UriHelper::TestForSubPath(Char* selfPtr, Int32 selfLength, Char* otherPtr, Int32 otherLength, Boolean ignoreCase) {
  return Boolean();
};

String UriHelper::EscapeString(String stringToEscape, Boolean checkExistingEscaped, ReadOnlySpan<Boolean> unreserved, Char forceEscape1, Char forceEscape2) {
  return nullptr;
};

Array<Char> UriHelper::EscapeString(ReadOnlySpan<Char> stringToEscape, Array<Char> dest, Int32& destPos, Boolean checkExistingEscaped, Char forceEscape1, Char forceEscape2) {
  return Array<Char>();
};

void UriHelper::EscapeStringToBuilder(ReadOnlySpan<Char> stringToEscape, ValueStringBuilder& vsb, ReadOnlySpan<Boolean> noEscape, Boolean checkExistingEscaped) {
};

Array<Char> UriHelper::UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  return Array<Char>();
};

Array<Char> UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  return Array<Char>();
};

void UriHelper::UnescapeString(String input, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
};

void UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, ValueStringBuilder& dest, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
};

void UriHelper::MatchUTF8Sequence(ValueStringBuilder& dest, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing) {
};

void UriHelper::EscapeAsciiChar(Byte b, ValueStringBuilder& to) {
};

Char UriHelper::DecodeHexChars(UInt32 first, UInt32 second) {
  return Char();
};

Boolean UriHelper::IsNotSafeForUnescape(Char ch) {
  return Boolean();
};

Boolean UriHelper::IsGenDelim(Char ch) {
  return Boolean();
};

Boolean UriHelper::IsLWS(Char ch) {
  return Boolean();
};

Boolean UriHelper::IsAsciiLetter(Char character) {
  return Boolean();
};

Boolean UriHelper::IsAsciiLetterOrDigit(Char character) {
  return Boolean();
};

Boolean UriHelper::IsHexDigit(Char character) {
  return Boolean();
};

Boolean UriHelper::IsBidiControlCharacter(Char ch) {
  return Boolean();
};

String UriHelper::StripBidiControlCharacters(ReadOnlySpan<Char> strToClean, String backingString) {
  return nullptr;
};

void UriHelper::SCtor() {
};

} // namespace System::Private::Uri::System::UriHelperNamespace
