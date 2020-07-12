#include "GlobalizationMode-dep.h"

namespace System::Private::CoreLib::System::Globalization::GlobalizationModeNamespace {
Boolean GlobalizationMode::GetInvariantSwitchValue() {
  return Boolean();
};

Boolean GlobalizationMode::TryGetAppLocalIcuSwitchValue(String& value) {
  return Boolean();
};

Boolean GlobalizationMode::GetSwitchValue(String switchName, String envVariable) {
  return Boolean();
};

Boolean GlobalizationMode::TryGetStringValue(String switchName, String envVariable, String& value) {
  return Boolean();
};

void GlobalizationMode::LoadAppLocalIcu(String icuSuffixAndVersion, Boolean suffixWithSeparator) {
};

String GlobalizationMode::CreateLibraryName(ReadOnlySpan<Char> baseName, ReadOnlySpan<Char> suffix, ReadOnlySpan<Char> extension, ReadOnlySpan<Char> version, Boolean versionAtEnd) {
  return nullptr;
};

IntPtr GlobalizationMode::LoadLibrary(String library, Boolean failOnLoadFailure) {
  return IntPtr();
};

Boolean GlobalizationMode::LoadIcu() {
  return Boolean();
};

void GlobalizationMode::LoadAppLocalIcuCore(ReadOnlySpan<Char> version, ReadOnlySpan<Char> suffix) {
};

} // namespace System::Private::CoreLib::System::Globalization::GlobalizationModeNamespace
