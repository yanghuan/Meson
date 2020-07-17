#include "ApplicationId-dep.h"

#include <System.Private.CoreLib/System/ApplicationId-dep.h>

namespace System::Private::CoreLib::System::ApplicationIdNamespace {
Array<Byte> ApplicationId___::get_PublicKeyToken() {
  return Array<Byte>();
};

void ApplicationId___::Ctor(Array<Byte> publicKeyToken, String name, System::Version version, String processorArchitecture, String culture) {
};

ApplicationId ApplicationId___::Copy() {
  return nullptr;
};

String ApplicationId___::ToString() {
  return nullptr;
};

void ApplicationId___::EncodeHexString(Array<Byte> sArray, ValueStringBuilder& stringBuilder) {
};

Boolean ApplicationId___::Equals(Object o) {
  return Boolean();
};

Int32 ApplicationId___::GetHashCode() {
  return Int32();
};

} // namespace System::Private::CoreLib::System::ApplicationIdNamespace
