#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace GlobalizationModeNamespace {
class GlobalizationMode {
  public: static Boolean get_Invariant() { return Invariant; }
  public: static Boolean get_UseNls() { return UseNls; }
  private: static Boolean GetInvariantSwitchValue();
  private: static Boolean TryGetAppLocalIcuSwitchValue(String& value);
  private: static Boolean GetSwitchValue(String switchName, String envVariable);
  private: static Boolean TryGetStringValue(String switchName, String envVariable, String& value);
  private: static void LoadAppLocalIcu(String icuSuffixAndVersion, Boolean suffixWithSeparator);
  private: static String CreateLibraryName(ReadOnlySpan<Char> baseName, ReadOnlySpan<Char> suffix, ReadOnlySpan<Char> extension, ReadOnlySpan<Char> version, Boolean versionAtEnd);
  private: static IntPtr LoadLibrary(String library, Boolean failOnLoadFailure);
  private: static Boolean LoadIcu();
  private: static void LoadAppLocalIcuCore(ReadOnlySpan<Char> version, ReadOnlySpan<Char> suffix);
  private: static Boolean Invariant;
  private: static Boolean UseNls;
};
} // namespace GlobalizationModeNamespace
using GlobalizationMode = GlobalizationModeNamespace::GlobalizationMode;
} // namespace System::Private::CoreLib::System::Globalization
