#include "VersioningHelper-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>

namespace System::Private::CoreLib::System::Runtime::Versioning::VersioningHelperNamespace {
using namespace System::Globalization;

String VersioningHelper::MakeVersionSafeName(String name, ResourceScope from, ResourceScope to) {
  return MakeVersionSafeName(name, from, to, nullptr);
}

String VersioningHelper::MakeVersionSafeName(String name, ResourceScope from, ResourceScope to, Type type) {
}

String VersioningHelper::GetCLRInstanceString() {
  return 3.ToString(CultureInfo::in::get_InvariantCulture());
}

SxSRequirements VersioningHelper::GetRequirements(ResourceScope consumeAsScope, ResourceScope calleeScope) {
  SxSRequirements sxSRequirements = SxSRequirements::None;
}

Int32 VersioningHelper::GetCurrentProcessId() {
  return (Int32)Interop::Kernel32::GetCurrentProcessId();
}

} // namespace System::Private::CoreLib::System::Runtime::Versioning::VersioningHelperNamespace
