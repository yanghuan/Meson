#include "GlobalizationMode-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/AppContext-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DllImportSearchPath.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/NativeLibrary-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Globalization::GlobalizationModeNamespace {
using namespace System::Runtime::InteropServices;

Boolean GlobalizationMode::get_Invariant() {
  return Invariant;
}

Boolean GlobalizationMode::get_UseNls() {
  return UseNls;
}

Boolean GlobalizationMode::GetInvariantSwitchValue() {
  return GetSwitchValue("System.Globalization.Invariant", "DOTNET_SYSTEM_GLOBALIZATION_INVARIANT");
}

Boolean GlobalizationMode::TryGetAppLocalIcuSwitchValue(String& value) {
  return TryGetStringValue("System.Globalization.AppLocalIcu", "DOTNET_SYSTEM_GLOBALIZATION_APPLOCALICU", value);
}

Boolean GlobalizationMode::GetSwitchValue(String switchName, String envVariable) {
  Boolean isEnabled;
  if (!AppContext::TryGetSwitch(switchName, isEnabled)) {
    String environmentVariable = Environment::GetEnvironmentVariable(envVariable);
    if (environmentVariable != nullptr) {
      return Boolean::IsTrueStringIgnoreCase(environmentVariable) || environmentVariable->Equals("1");
    }
  }
  return isEnabled;
}

Boolean GlobalizationMode::TryGetStringValue(String switchName, String envVariable, String& value) {
  value = (rt::as<String>(AppContext::GetData(switchName)));
  if (String::in::IsNullOrEmpty(value)) {
    value = Environment::GetEnvironmentVariable(envVariable);
    if (String::in::IsNullOrEmpty(value)) {
      return false;
    }
  }
  return true;
}

void GlobalizationMode::LoadAppLocalIcu(String icuSuffixAndVersion) {
  ReadOnlySpan<Char> suffix = rt::default__;
  Int32 num = icuSuffixAndVersion->IndexOf(58);
  ReadOnlySpan<Char> version;
  if (num >= 0) {
    ReadOnlySpan<Char> readOnlySpan = MemoryExtensions::AsSpan(icuSuffixAndVersion);
    suffix = readOnlySpan.Slice(0, num);
    readOnlySpan = MemoryExtensions::AsSpan(icuSuffixAndVersion);
    version = readOnlySpan.Slice(suffix.get_Length() + 1);
  } else {
    version = icuSuffixAndVersion;
  }
  LoadAppLocalIcuCore(version, suffix);
}

String GlobalizationMode::CreateLibraryName(ReadOnlySpan<Char> baseName, ReadOnlySpan<Char> suffix, ReadOnlySpan<Char> extension, ReadOnlySpan<Char> version, Boolean versionAtEnd) {
  if (!versionAtEnd) {
    return String::in::Concat(baseName, suffix, version, extension);
  }
  return String::in::Concat(baseName, suffix, extension, version);
}

IntPtr GlobalizationMode::LoadLibrary(String library, Boolean failOnLoadFailure) {
  IntPtr handle;
  if (!NativeLibrary::TryLoad(library, typeof<Object>()->get_Assembly(), DllImportSearchPath::ApplicationDirectory | DllImportSearchPath::System32, handle) && failOnLoadFailure) {
    Environment::FailFast("Failed to load app-local ICU: " + library);
  }
  return handle;
}

Boolean GlobalizationMode::LoadIcu() {
  String value;
  if (!TryGetAppLocalIcuSwitchValue(value)) {
    return Interop::Globalization::LoadICU() != 0;
  }
  LoadAppLocalIcu(value);
  return true;
}

void GlobalizationMode::LoadAppLocalIcuCore(ReadOnlySpan<Char> version, ReadOnlySpan<Char> suffix) {
  IntPtr intPtr = IntPtr::Zero;
  IntPtr intPtr2 = IntPtr::Zero;
  Int32 num = MemoryExtensions::IndexOf(version, 46);
  if (num > 0) {
    ReadOnlySpan<Char> version2 = version.Slice(0, num);
    intPtr = LoadLibrary(CreateLibraryName("icuuc", suffix, ".dll", version2), false);
    if (intPtr != IntPtr::Zero) {
      intPtr2 = LoadLibrary(CreateLibraryName("icuin", suffix, ".dll", version2), false);
    }
  }
  if (intPtr == IntPtr::Zero) {
    intPtr = LoadLibrary(CreateLibraryName("icuuc", suffix, ".dll", version), true);
  }
  if (intPtr2 == IntPtr::Zero) {
    intPtr2 = LoadLibrary(CreateLibraryName("icuin", suffix, ".dll", version), true);
  }
  Interop::Globalization::InitICUFunctions(intPtr, intPtr2, version, suffix);
}

void GlobalizationMode::cctor() {
  Invariant = GetInvariantSwitchValue();
  UseNls = (!Invariant && (GetSwitchValue("System.Globalization.UseNls", "DOTNET_SYSTEM_GLOBALIZATION_USENLS") || !LoadIcu()));
}

} // namespace System::Private::CoreLib::System::Globalization::GlobalizationModeNamespace
