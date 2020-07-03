#include "UriHelper-dep.h"

namespace System::Private::Uri::System::UriHelperNamespace {
Boolean UriHelper::TestForSubPath(Char* selfPtr, UInt16 selfLength, Char* otherPtr, UInt16 otherLength, Boolean ignoreCase) {
  return Boolean();
};
Array<Char> UriHelper::EscapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPos, Boolean isUriString, Char force1, Char force2, Char rsvd) {
  return Array<Char>();
};
Array<Char> UriHelper::EnsureDestinationSize(Char* pStr, Array<Char> dest, Int32 currentInputPos, Int16 charsToAdd, Int16 minReallocateChars, Int32& destPos, Int32 prevInputPos) {
  return Array<Char>();
};
Array<Char> UriHelper::UnescapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  return Array<Char>();
};
Array<Char> UriHelper::UnescapeString(Char* pStr, Int32 start, Int32 end, Array<Char> dest, Int32& destPosition, Char rsvd1, Char rsvd2, Char rsvd3, UnescapeMode unescapeMode, UriParser syntax, Boolean isQuery) {
  return Array<Char>();
};
void UriHelper::MatchUTF8Sequence(Char* pDest, Array<Char> dest, Int32& destOffset, Span<Char> unescapedChars, Int32 charCount, Array<Byte> bytes, Int32 byteCount, Boolean isQuery, Boolean iriParsing) {
};
void UriHelper::EscapeAsciiChar(Char ch, Array<Char> to, Int32& pos) {
};
Char UriHelper::EscapedAscii(Char digit, Char next) {
  return Char();
};
Boolean UriHelper::IsNotSafeForUnescape(Char ch) {
  return Boolean();
};
Boolean UriHelper::IsReservedUnreservedOrHash(Char c) {
  return Boolean();
};
Boolean UriHelper::IsUnreserved(Char c) {
  return Boolean();
};
Boolean UriHelper::Is3986Unreserved(Char c) {
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
Boolean UriHelper::IsBidiControlCharacter(Char ch) {
  return Boolean();
};
String UriHelper::StripBidiControlCharacter(Char* strToClean, Int32 start, Int32 length) {
  return nullptr;
};
} // namespace System::Private::Uri::System::UriHelperNamespace
