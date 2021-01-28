#include "OperatingSystem-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/OperatingSystem-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

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
  if (platform < PlatformID::Win32S || platform > PlatformID::MacOSX) {
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

} // namespace System::Private::CoreLib::System::OperatingSystemNamespace
