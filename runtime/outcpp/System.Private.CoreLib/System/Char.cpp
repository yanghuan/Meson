#include "Char-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>

namespace System::Private::CoreLib::System::CharNamespace {
ReadOnlySpan<Byte> Char::get_CategoryForLatin1() {
  return ReadOnlySpan<Byte>();
};
Boolean Char::IsLatin1(Char ch) {
  return Boolean();
};
Boolean Char::IsAscii(Char ch) {
  return Boolean();
};
UnicodeCategory Char::GetLatin1UnicodeCategory(Char ch) {
  return UnicodeCategory();
};
Int32 Char::GetHashCode() {
  return Int32();
};
Boolean Char::Equals(Object obj) {
  return Boolean();
};
Boolean Char::Equals(Char obj) {
  return Boolean();
};
Int32 Char::CompareTo(Object value) {
  return Int32();
};
Int32 Char::CompareTo(Char value) {
  return Int32();
};
String Char::ToString() {
  return nullptr;
};
String Char::ToString(IFormatProvider provider) {
  return nullptr;
};
String Char::ToString(Char c) {
  return nullptr;
};
Char Char::Parse(String s) {
  return Char();
};
Boolean Char::TryParse(String s, Char& result) {
  return Boolean();
};
Boolean Char::IsDigit(Char c) {
  return Boolean();
};
Boolean Char::IsInRange(Char c, Char min, Char max) {
  return Boolean();
};
Boolean Char::IsInRange(UnicodeCategory c, UnicodeCategory min, UnicodeCategory max) {
  return Boolean();
};
Boolean Char::CheckLetter(UnicodeCategory uc) {
  return Boolean();
};
Boolean Char::IsLetter(Char c) {
  return Boolean();
};
Boolean Char::IsWhiteSpaceLatin1(Char c) {
  return Boolean();
};
Boolean Char::IsWhiteSpace(Char c) {
  return Boolean();
};
Boolean Char::IsUpper(Char c) {
  return Boolean();
};
Boolean Char::IsLower(Char c) {
  return Boolean();
};
Boolean Char::CheckPunctuation(UnicodeCategory uc) {
  return Boolean();
};
Boolean Char::IsPunctuation(Char c) {
  return Boolean();
};
Boolean Char::CheckLetterOrDigit(UnicodeCategory uc) {
  return Boolean();
};
Boolean Char::IsLetterOrDigit(Char c) {
  return Boolean();
};
Char Char::ToUpper(Char c, CultureInfo culture) {
  return Char();
};
Char Char::ToUpper(Char c) {
  return Char();
};
Char Char::ToUpperInvariant(Char c) {
  return Char();
};
Char Char::ToLower(Char c, CultureInfo culture) {
  return Char();
};
Char Char::ToLower(Char c) {
  return Char();
};
Char Char::ToLowerInvariant(Char c) {
  return Char();
};
TypeCode Char::GetTypeCode() {
  return TypeCode();
};
Boolean Char::IsControl(Char c) {
  return Boolean();
};
Boolean Char::IsControl(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsDigit(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsLetter(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsLetterOrDigit(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsLower(String s, Int32 index) {
  return Boolean();
};
Boolean Char::CheckNumber(UnicodeCategory uc) {
  return Boolean();
};
Boolean Char::IsNumber(Char c) {
  return Boolean();
};
Boolean Char::IsNumber(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsPunctuation(String s, Int32 index) {
  return Boolean();
};
Boolean Char::CheckSeparator(UnicodeCategory uc) {
  return Boolean();
};
Boolean Char::IsSeparatorLatin1(Char c) {
  return Boolean();
};
Boolean Char::IsSeparator(Char c) {
  return Boolean();
};
Boolean Char::IsSeparator(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsSurrogate(Char c) {
  return Boolean();
};
Boolean Char::IsSurrogate(String s, Int32 index) {
  return Boolean();
};
Boolean Char::CheckSymbol(UnicodeCategory uc) {
  return Boolean();
};
Boolean Char::IsSymbol(Char c) {
  return Boolean();
};
Boolean Char::IsSymbol(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsUpper(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsWhiteSpace(String s, Int32 index) {
  return Boolean();
};
UnicodeCategory Char::GetUnicodeCategory(Char c) {
  return UnicodeCategory();
};
UnicodeCategory Char::GetUnicodeCategory(String s, Int32 index) {
  return UnicodeCategory();
};
Double Char::GetNumericValue(Char c) {
  return Double();
};
Double Char::GetNumericValue(String s, Int32 index) {
  return Double();
};
Boolean Char::IsHighSurrogate(Char c) {
  return Boolean();
};
Boolean Char::IsHighSurrogate(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsLowSurrogate(Char c) {
  return Boolean();
};
Boolean Char::IsLowSurrogate(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsSurrogatePair(String s, Int32 index) {
  return Boolean();
};
Boolean Char::IsSurrogatePair(Char highSurrogate, Char lowSurrogate) {
  return Boolean();
};
String Char::ConvertFromUtf32(Int32 utf32) {
  return nullptr;
};
Int32 Char::ConvertToUtf32(Char highSurrogate, Char lowSurrogate) {
  return Int32();
};
void Char::ConvertToUtf32_ThrowInvalidArgs(UInt32 highSurrogateOffset) {
  return void();
};
Int32 Char::ConvertToUtf32(String s, Int32 index) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::CharNamespace
