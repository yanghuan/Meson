#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
namespace AppDomainSetupNamespace {
CLASS(AppDomainSetup) : public Object::in {
  public: String get_ApplicationBase();
  public: String get_TargetFrameworkName();
  public: void Ctor();
};
} // namespace AppDomainSetupNamespace
using AppDomainSetup = AppDomainSetupNamespace::AppDomainSetup;
} // namespace System::Private::CoreLib::System
