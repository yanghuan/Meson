#include "OperatingSystem-dep.h"

namespace System::Private::CoreLib::System::OperatingSystemNamespace {
PlatformID OperatingSystem___::get_Platform() {
  return PlatformID::MacOSX;
};

String OperatingSystem___::get_ServicePack() {
  return nullptr;
};

Version OperatingSystem___::get_Version() {
  return nullptr;
};

String OperatingSystem___::get_VersionString() {
  return nullptr;
};

void OperatingSystem___::GetObjectData(SerializationInfo info, StreamingContext context) {
};

Object OperatingSystem___::Clone() {
  return nullptr;
};

String OperatingSystem___::ToString() {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::OperatingSystemNamespace
