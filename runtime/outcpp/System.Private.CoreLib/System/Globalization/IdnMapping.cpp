#include "IdnMapping-dep.h"

namespace System::Private::CoreLib::System::Globalization::IdnMappingNamespace {
Boolean IdnMapping___::get_AllowUnassigned() {
  return Boolean();
}

void IdnMapping___::set_AllowUnassigned(Boolean value) {
}

Boolean IdnMapping___::get_UseStd3AsciiRules() {
  return Boolean();
}

void IdnMapping___::set_UseStd3AsciiRules(Boolean value) {
}

UInt32 IdnMapping___::get_IcuFlags() {
  return UInt32();
}

UInt32 IdnMapping___::get_NlsFlags() {
  return UInt32();
}

void IdnMapping___::Ctor() {
}

String IdnMapping___::GetAscii(String unicode) {
  return nullptr;
}

String IdnMapping___::GetAscii(String unicode, Int32 index) {
  return nullptr;
}

String IdnMapping___::GetAscii(String unicode, Int32 index, Int32 count) {
  return nullptr;
}

String IdnMapping___::GetUnicode(String ascii) {
  return nullptr;
}

String IdnMapping___::GetUnicode(String ascii, Int32 index) {
  return nullptr;
}

String IdnMapping___::GetUnicode(String ascii, Int32 index, Int32 count) {
  return nullptr;
}

Boolean IdnMapping___::Equals(Object obj) {
  return Boolean();
}

Int32 IdnMapping___::GetHashCode() {
  return Int32();
}

String IdnMapping___::GetStringForOutput(String originalString, Char* input, Int32 inputLength, Char* output, Int32 outputLength) {
  return nullptr;
}

String IdnMapping___::GetAsciiInvariant(String unicode, Int32 index, Int32 count) {
  return nullptr;
}

Boolean IdnMapping___::ValidateStd3AndAscii(String unicode, Boolean bUseStd3, Boolean bCheckAscii) {
  return Boolean();
}

String IdnMapping___::PunycodeEncode(String unicode) {
  return nullptr;
}

Boolean IdnMapping___::IsDot(Char c) {
  return Boolean();
}

Boolean IdnMapping___::IsSupplementary(Int32 cTest) {
  return Boolean();
}

Boolean IdnMapping___::Basic(UInt32 cp) {
  return Boolean();
}

void IdnMapping___::ValidateStd3(Char c, Boolean bNextToDot) {
}

String IdnMapping___::GetUnicodeInvariant(String ascii, Int32 index, Int32 count) {
  return nullptr;
}

String IdnMapping___::PunycodeDecode(String ascii) {
  return nullptr;
}

Int32 IdnMapping___::DecodeDigit(Char cp) {
  return Int32();
}

Int32 IdnMapping___::Adapt(Int32 delta, Int32 numpoints, Boolean firsttime) {
  return Int32();
}

Char IdnMapping___::EncodeBasic(Char bcp) {
  return Char();
}

Boolean IdnMapping___::HasUpperCaseFlag(Char punychar) {
  return Boolean();
}

Char IdnMapping___::EncodeDigit(Int32 d) {
  return Char();
}

String IdnMapping___::IcuGetAsciiCore(String unicodeString, Char* unicode, Int32 count) {
  return nullptr;
}

String IdnMapping___::IcuGetUnicodeCore(String asciiString, Char* ascii, Int32 count) {
  return nullptr;
}

String IdnMapping___::IcuGetUnicodeCore(String asciiString, Char* ascii, Int32 count, UInt32 flags, Char* output, Int32 outputLength, Boolean reattempt) {
  return nullptr;
}

void IdnMapping___::CheckInvalidIdnCharacters(Char* s, Int32 count, UInt32 flags, String paramName) {
}

String IdnMapping___::NlsGetAsciiCore(String unicodeString, Char* unicode, Int32 count) {
  return nullptr;
}

String IdnMapping___::NlsGetAsciiCore(String unicodeString, Char* unicode, Int32 count, UInt32 flags, Char* output, Int32 outputLength) {
  return nullptr;
}

String IdnMapping___::NlsGetUnicodeCore(String asciiString, Char* ascii, Int32 count) {
  return nullptr;
}

String IdnMapping___::NlsGetUnicodeCore(String asciiString, Char* ascii, Int32 count, UInt32 flags, Char* output, Int32 outputLength) {
  return nullptr;
}

void IdnMapping___::ThrowForZeroLength(Boolean unicode) {
}

void IdnMapping___::SCtor() {
}

} // namespace System::Private::CoreLib::System::Globalization::IdnMappingNamespace
