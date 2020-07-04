#include "PathInternal-dep.h"

namespace System::Private::CoreLib::System::IO::PathInternalNamespace {
Boolean PathInternal::StartsWithDirectorySeparator(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean PathInternal::IsRoot(ReadOnlySpan<Char> path) {
  return Boolean();
};
Int32 PathInternal::GetCommonPathLength(String first, String second, Boolean ignoreCase) {
  return Int32();
};
Int32 PathInternal::EqualStartingCharacterCount(String first, String second, Boolean ignoreCase) {
  return Int32();
};
Boolean PathInternal::AreRootsEqual(String first, String second, StringComparison comparisonType) {
  return Boolean();
};
String PathInternal::RemoveRelativeSegments(String path, Int32 rootLength) {
  return nullptr;
};
Boolean PathInternal::RemoveRelativeSegments(ReadOnlySpan<Char> path, Int32 rootLength, ValueStringBuilder& sb) {
  return Boolean();
};
String PathInternal::TrimEndingDirectorySeparator(String path) {
  return nullptr;
};
Boolean PathInternal::EndsInDirectorySeparator(String path) {
  return Boolean();
};
ReadOnlySpan<Char> PathInternal::TrimEndingDirectorySeparator(ReadOnlySpan<Char> path) {
  return ReadOnlySpan<Char>();
};
Boolean PathInternal::EndsInDirectorySeparator(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean PathInternal::IsValidDriveChar(Char value) {
  return Boolean();
};
Boolean PathInternal::EndsWithPeriodOrSpace(String path) {
  return Boolean();
};
String PathInternal::EnsureExtendedPrefixIfNeeded(String path) {
  return nullptr;
};
String PathInternal::EnsureExtendedPrefix(String path) {
  return nullptr;
};
Boolean PathInternal::IsDevice(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean PathInternal::IsDeviceUNC(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean PathInternal::IsExtended(ReadOnlySpan<Char> path) {
  return Boolean();
};
Int32 PathInternal::GetRootLength(ReadOnlySpan<Char> path) {
  return Int32();
};
Boolean PathInternal::IsPartiallyQualified(ReadOnlySpan<Char> path) {
  return Boolean();
};
Boolean PathInternal::IsDirectorySeparator(Char c) {
  return Boolean();
};
String PathInternal::NormalizeDirectorySeparators(String path) {
  return nullptr;
};
Boolean PathInternal::IsEffectivelyEmpty(ReadOnlySpan<Char> path) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::IO::PathInternalNamespace
