#include "TargetFrameworkAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Runtime::Versioning::TargetFrameworkAttributeNamespace {
String TargetFrameworkAttribute___::get_FrameworkName() {
  return _frameworkName;
}

String TargetFrameworkAttribute___::get_FrameworkDisplayName() {
  return _frameworkDisplayName;
}

void TargetFrameworkAttribute___::set_FrameworkDisplayName(String value) {
  _frameworkDisplayName = value;
}

void TargetFrameworkAttribute___::ctor(String frameworkName) {
  if (frameworkName == nullptr) {
    rt::throw_exception<ArgumentNullException>("frameworkName");
  }
  _frameworkName = frameworkName;
}

} // namespace System::Private::CoreLib::System::Runtime::Versioning::TargetFrameworkAttributeNamespace
