#include "OperatingSystem-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/OperatingSystem-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::OperatingSystemNamespace {
PlatformID OperatingSystem___::get_Platform() {
  return _platform;
}

String OperatingSystem___::get_ServicePack() {
  String as = _servicePack;
  return as != nullptr ? as : String::in::Empty;
}

Version OperatingSystem___::get_Version() {
  return _version;
}

String OperatingSystem___::get_VersionString() {
  if (_versionString == nullptr) {
  }
  return _versionString;
}

void OperatingSystem___::ctor(PlatformID platform, Version version) {
}

void OperatingSystem___::ctor(PlatformID platform, Version version, String servicePack) {
  if (platform < PlatformID::Win32S || platform > PlatformID::Other) {
    rt::throw_exception<ArgumentOutOfRangeException>("platform", platform, SR::Format(SR::get_Arg_EnumIllegalVal(), platform));
  }
  if (version == nullptr) {
    rt::throw_exception<ArgumentNullException>("version");
  }
  _platform = platform;
  _version = version;
  _servicePack = servicePack;
}

void OperatingSystem___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Object OperatingSystem___::Clone() {
  return rt::newobj<OperatingSystem>(_platform, _version, _servicePack);
}

String OperatingSystem___::ToString() {
  return get_VersionString();
}

Boolean OperatingSystem___::IsOSPlatform(String platform) {
  if (platform == nullptr) {
    rt::throw_exception<ArgumentNullException>("platform");
  }
  return platform->Equals("WINDOWS", StringComparison::OrdinalIgnoreCase);
}

Boolean OperatingSystem___::IsOSPlatformVersionAtLeast(String platform, Int32 major, Int32 minor, Int32 build, Int32 revision) {
  if (IsOSPlatform(platform)) {
    return IsOSVersionAtLeast(major, minor, build, revision);
  }
  return false;
}

Boolean OperatingSystem___::IsBrowser() {
  return false;
}

Boolean OperatingSystem___::IsLinux() {
  return false;
}

Boolean OperatingSystem___::IsFreeBSD() {
  return false;
}

Boolean OperatingSystem___::IsFreeBSDVersionAtLeast(Int32 major, Int32 minor, Int32 build, Int32 revision) {
  if (IsFreeBSD()) {
  }
  return false;
}

Boolean OperatingSystem___::IsAndroid() {
  return false;
}

Boolean OperatingSystem___::IsAndroidVersionAtLeast(Int32 major, Int32 minor, Int32 build, Int32 revision) {
  if (IsAndroid()) {
  }
  return false;
}

Boolean OperatingSystem___::IsIOS() {
  return false;
}

Boolean OperatingSystem___::IsIOSVersionAtLeast(Int32 major, Int32 minor, Int32 build) {
  if (IsIOS()) {
  }
  return false;
}

Boolean OperatingSystem___::IsMacOS() {
  return false;
}

Boolean OperatingSystem___::IsMacOSVersionAtLeast(Int32 major, Int32 minor, Int32 build) {
  if (IsMacOS()) {
  }
  return false;
}

Boolean OperatingSystem___::IsTvOS() {
  return false;
}

Boolean OperatingSystem___::IsTvOSVersionAtLeast(Int32 major, Int32 minor, Int32 build) {
  if (IsTvOS()) {
  }
  return false;
}

Boolean OperatingSystem___::IsWatchOS() {
  return false;
}

Boolean OperatingSystem___::IsWatchOSVersionAtLeast(Int32 major, Int32 minor, Int32 build) {
  if (IsWatchOS()) {
  }
  return false;
}

Boolean OperatingSystem___::IsWindows() {
  return true;
}

Boolean OperatingSystem___::IsWindowsVersionAtLeast(Int32 major, Int32 minor, Int32 build, Int32 revision) {
  IsWindows();
  return IsOSVersionAtLeast(major, minor, build, revision);
}

Boolean OperatingSystem___::IsOSVersionAtLeast(Int32 major, Int32 minor, Int32 build, Int32 revision) {
  Version version = Environment::get_OSVersion()->get_Version();
  if (version->get_Major() != major) {
    return version->get_Major() > major;
  }
  if (version->get_Minor() != minor) {
    return version->get_Minor() > minor;
  }
  if (version->get_Build() != build) {
    return version->get_Build() > build;
  }
  if (version->get_Revision() < revision) {
    if (version->get_Revision() == -1) {
      return revision == 0;
    }
    return false;
  }
  return true;
}

} // namespace System::Private::CoreLib::System::OperatingSystemNamespace
