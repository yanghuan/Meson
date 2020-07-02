#include "TextInfo-dep.h"

#include <System.Private.CoreLib/System/Globalization/TextInfo-dep.h>

namespace System::Private::CoreLib::System::Globalization::TextInfoNamespace {
TextInfo TextInfo___::get_Invariant() {
  return nullptr;
};
Int32 TextInfo___::get_ANSICodePage() {
  return Int32();
};
Int32 TextInfo___::get_OEMCodePage() {
  return Int32();
};
Int32 TextInfo___::get_MacCodePage() {
  return Int32();
};
Int32 TextInfo___::get_EBCDICCodePage() {
  return Int32();
};
Int32 TextInfo___::get_LCID() {
  return Int32();
};
String TextInfo___::get_CultureName() {
  return nullptr;
};
Boolean TextInfo___::get_IsReadOnly() {
  return Boolean();
};
String TextInfo___::get_ListSeparator() {
  return nullptr;
};
void TextInfo___::set_ListSeparator(String value) {
  return void();
};
Boolean TextInfo___::get_IsAsciiCasingSameAsInvariant() {
  return Boolean();
};
Boolean TextInfo___::get_IsRightToLeft() {
  return Boolean();
};
Object TextInfo___::Clone() {
  return nullptr;
};
TextInfo TextInfo___::ReadOnly(TextInfo textInfo) {
  return nullptr;
};
void TextInfo___::VerifyWritable() {
  return void();
};
void TextInfo___::SetReadOnlyState(Boolean readOnly) {
  return void();
};
Char TextInfo___::ToLower(Char c) {
  return Char();
};
String TextInfo___::ToLower(String str) {
  return nullptr;
};
Char TextInfo___::ChangeCase(Char c, Boolean toUpper) {
  return Char();
};
void TextInfo___::ChangeCaseToLower(ReadOnlySpan<Char> source, Span<Char> destination) {
  return void();
};
void TextInfo___::ChangeCaseToUpper(ReadOnlySpan<Char> source, Span<Char> destination) {
  return void();
};
String TextInfo___::ToLowerAsciiInvariant(String s) {
  return nullptr;
};
void TextInfo___::ToLowerAsciiInvariant(ReadOnlySpan<Char> source, Span<Char> destination) {
  return void();
};
String TextInfo___::ToUpperAsciiInvariant(String s) {
  return nullptr;
};
void TextInfo___::ToUpperAsciiInvariant(ReadOnlySpan<Char> source, Span<Char> destination) {
  return void();
};
Char TextInfo___::ToLowerAsciiInvariant(Char c) {
  return Char();
};
Char TextInfo___::ToUpper(Char c) {
  return Char();
};
String TextInfo___::ToUpper(String str) {
  return nullptr;
};
Char TextInfo___::ToUpperAsciiInvariant(Char c) {
  return Char();
};
Boolean TextInfo___::IsAscii(Char c) {
  return Boolean();
};
void TextInfo___::PopulateIsAsciiCasingSameAsInvariant() {
  return void();
};
Boolean TextInfo___::Equals(Object obj) {
  return Boolean();
};
Int32 TextInfo___::GetHashCode() {
  return Int32();
};
String TextInfo___::ToString() {
  return nullptr;
};
String TextInfo___::ToTitleCase(String str) {
  return nullptr;
};
Int32 TextInfo___::AddNonLetter(StringBuilder& result, String& input, Int32 inputIndex, Int32 charLen) {
  return Int32();
};
Int32 TextInfo___::AddTitlecaseLetter(StringBuilder& result, String& input, Int32 inputIndex, Int32 charLen) {
  return Int32();
};
Boolean TextInfo___::IsWordSeparator(UnicodeCategory category) {
  return Boolean();
};
Boolean TextInfo___::IsLetterCategory(UnicodeCategory uc) {
  return Boolean();
};
void TextInfo___::FinishInitialization() {
  return void();
};
void TextInfo___::ChangeCase(Char* pSource, Int32 pSourceLen, Char* pResult, Int32 pResultLen, Boolean toUpper) {
  return void();
};
Boolean TextInfo___::IsInvariantLocale(String localeName) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Globalization::TextInfoNamespace
