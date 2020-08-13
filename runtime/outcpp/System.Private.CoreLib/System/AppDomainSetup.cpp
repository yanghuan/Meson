#include "AppDomainSetup-dep.h"

#include <System.Private.CoreLib/System/AppContext-dep.h>

namespace System::Private::CoreLib::System::AppDomainSetupNamespace {
String AppDomainSetup___::get_ApplicationBase() {
  return AppContext::get_BaseDirectory();
}

String AppDomainSetup___::get_TargetFrameworkName() {
  return AppContext::get_TargetFrameworkName();
}

void AppDomainSetup___::ctor() {
}

} // namespace System::Private::CoreLib::System::AppDomainSetupNamespace
