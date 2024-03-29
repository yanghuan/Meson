#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace AppDomainSetupNamespace {
CLASS(AppDomainSetup) : public object {
  public: String get_ApplicationBase();
  public: String get_TargetFrameworkName();
  public: void ctor();
};
} // namespace AppDomainSetupNamespace
using AppDomainSetup = AppDomainSetupNamespace::AppDomainSetup;
} // namespace System::Private::CoreLib::System
