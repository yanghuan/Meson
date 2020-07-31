#include "VersioningHelper-dep.h"

namespace System::Private::CoreLib::System::Runtime::Versioning::VersioningHelperNamespace {
String VersioningHelper::MakeVersionSafeName(String name, ResourceScope from, ResourceScope to) {
  return nullptr;
}

String VersioningHelper::MakeVersionSafeName(String name, ResourceScope from, ResourceScope to, Type type) {
  return nullptr;
}

String VersioningHelper::GetCLRInstanceString() {
  return nullptr;
}

SxSRequirements VersioningHelper::GetRequirements(ResourceScope consumeAsScope, ResourceScope calleeScope) {
  return SxSRequirements::TypeName;
}

Int32 VersioningHelper::GetCurrentProcessId() {
  return Int32();
}

} // namespace System::Private::CoreLib::System::Runtime::Versioning::VersioningHelperNamespace
