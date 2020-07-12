#include "__DTString-dep.h"

namespace System::Private::CoreLib::System::__DTStringNamespace {
Int32 __DTString::get_Length() {
  return Int32();
};

CompareInfo __DTString::get_CompareInfo() {
  return nullptr;
};

Boolean __DTString::GetNext() {
  return Boolean();
};

Boolean __DTString::AtEnd() {
  return Boolean();
};

Boolean __DTString::Advance(Int32 count) {
  return Boolean();
};

void __DTString::GetRegularToken(TokenType& tokenType, Int32& tokenValue, DateTimeFormatInfo dtfi) {
};

TokenType __DTString::GetSeparatorToken(DateTimeFormatInfo dtfi, Int32& indexBeforeSeparator, Char& charBeforeSeparator) {
  return TokenType::SeparatorTokenMask;
};

Boolean __DTString::MatchSpecifiedWord(String target) {
  return Boolean();
};

Boolean __DTString::MatchSpecifiedWords(String target, Boolean checkWordBoundary, Int32& matchLength) {
  return Boolean();
};

Boolean __DTString::Match(String str) {
  return Boolean();
};

Boolean __DTString::Match(Char ch) {
  return Boolean();
};

Int32 __DTString::MatchLongestWords(Array<String> words, Int32& maxMatchStrLen) {
  return Int32();
};

Int32 __DTString::GetRepeatCount() {
  return Int32();
};

Boolean __DTString::GetNextDigit() {
  return Boolean();
};

Char __DTString::GetChar() {
  return Char();
};

Int32 __DTString::GetDigit() {
  return Int32();
};

void __DTString::SkipWhiteSpaces() {
};

Boolean __DTString::SkipWhiteSpaceCurrent() {
  return Boolean();
};

void __DTString::TrimTail() {
};

void __DTString::RemoveTrailingInQuoteSpaces() {
};

void __DTString::RemoveLeadingInQuoteSpaces() {
};

DTSubString __DTString::GetSubString() {
  return DTSubString();
};

void __DTString::ConsumeSubString(DTSubString sub) {
};

} // namespace System::Private::CoreLib::System::__DTStringNamespace
