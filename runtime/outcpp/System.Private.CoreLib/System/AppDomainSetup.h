#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace AppDomainSetupNamespace {
CLASS(AppDomainSetup) {
  public: String get_ApplicationBase();
  public: String get_TargetFrameworkName();
};
} // namespace AppDomainSetupNamespace
using AppDomainSetup = AppDomainSetupNamespace::AppDomainSetup;
} // namespace System::Private::CoreLib::System
