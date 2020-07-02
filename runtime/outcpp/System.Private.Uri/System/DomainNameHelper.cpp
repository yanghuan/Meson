#include "DomainNameHelper-dep.h"

namespace System::Private::Uri::System::DomainNameHelperNamespace {
String DomainNameHelper::ParseCanonicalName(String str, Int32 start, Int32 end, Boolean& loopback) {
  return nullptr;
};
Boolean DomainNameHelper::IsValid(Char* name, UInt16 pos, Int32& returnedEnd, Boolean& notCanonical, Boolean notImplicitFile) {
  return Boolean();
};
Boolean DomainNameHelper::IsValidByIri(Char* name, UInt16 pos, Int32& returnedEnd, Boolean& notCanonical, Boolean notImplicitFile) {
  return Boolean();
};
String DomainNameHelper::IdnEquivalent(String hostname) {
  return nullptr;
};
String DomainNameHelper::IdnEquivalent(Char* hostname, Int32 start, Int32 end, Boolean& allAscii, Boolean& atLeastOneValidIdn) {
  return nullptr;
};
String DomainNameHelper::IdnEquivalent(Char* hostname, Int32 start, Int32 end, Boolean& allAscii, String& bidiStrippedHost) {
  return nullptr;
};
Boolean DomainNameHelper::IsIdnAce(String input, Int32 index) {
  return Boolean();
};
Boolean DomainNameHelper::IsIdnAce(Char* input, Int32 index) {
  return Boolean();
};
String DomainNameHelper::UnicodeEquivalent(String idnHost, Char* hostname, Int32 start, Int32 end) {
  return nullptr;
};
String DomainNameHelper::UnicodeEquivalent(Char* hostname, Int32 start, Int32 end, Boolean& allAscii, Boolean& atLeastOneValidIdn) {
  return nullptr;
};
Boolean DomainNameHelper::IsASCIILetterOrDigit(Char character, Boolean& notCanonical) {
  return Boolean();
};
Boolean DomainNameHelper::IsValidDomainLabelCharacter(Char character, Boolean& notCanonical) {
  return Boolean();
};
Boolean DomainNameHelper::ContainsCharactersUnsafeForNormalizedHost(String host) {
  return Boolean();
};
} // namespace System::Private::Uri::System::DomainNameHelperNamespace
