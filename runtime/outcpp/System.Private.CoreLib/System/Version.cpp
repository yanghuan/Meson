#include "Version-dep.h"

#include <System.Private.CoreLib/System/Version-dep.h>

namespace System::Private::CoreLib::System::VersionNamespace {
Int32 Version___::get_Major() {
  return Int32();
};
Int32 Version___::get_Minor() {
  return Int32();
};
Int32 Version___::get_Build() {
  return Int32();
};
Int32 Version___::get_Revision() {
  return Int32();
};
Int16 Version___::get_MajorRevision() {
  return Int16();
};
Int16 Version___::get_MinorRevision() {
  return Int16();
};
Int32 Version___::get_DefaultFormatFieldCount() {
  return Int32();
};
Object Version___::Clone() {
  return nullptr;
};
Int32 Version___::CompareTo(Object version) {
  return Int32();
};
Int32 Version___::CompareTo(Version value) {
  return Int32();
};
Boolean Version___::Equals(Object obj) {
  return Boolean();
};
Boolean Version___::Equals(Version obj) {
  return Boolean();
};
Int32 Version___::GetHashCode() {
  return Int32();
};
String Version___::ToString() {
  return nullptr;
};
String Version___::ToString(Int32 fieldCount) {
  return nullptr;
};
Boolean Version___::TryFormat(Span<Char> destination, Int32& charsWritten) {
  return Boolean();
};
Boolean Version___::TryFormat(Span<Char> destination, Int32 fieldCount, Int32& charsWritten) {
  return Boolean();
};
StringBuilder Version___::ToCachedStringBuilder(Int32 fieldCount) {
  return nullptr;
};
Version Version___::Parse(String input) {
  return nullptr;
};
Version Version___::Parse(ReadOnlySpan<Char> input) {
  return nullptr;
};
Boolean Version___::TryParse(String input, Version& result) {
  return Boolean();
};
Boolean Version___::TryParse(ReadOnlySpan<Char> input, Version& result) {
  return Boolean();
};
Version Version___::ParseVersion(ReadOnlySpan<Char> input, Boolean throwOnFailure) {
  return nullptr;
};
Boolean Version___::TryParseComponent(ReadOnlySpan<Char> component, String componentName, Boolean throwOnFailure, Int32& parsedComponent) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::VersionNamespace