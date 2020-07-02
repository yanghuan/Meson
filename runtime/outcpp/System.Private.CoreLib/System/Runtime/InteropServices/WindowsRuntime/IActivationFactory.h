#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IActivationFactoryNamespace {
CLASS(IActivationFactory) {
  public: Object ActivateInstance();
};
} // namespace IActivationFactoryNamespace
using IActivationFactory = IActivationFactoryNamespace::IActivationFactory;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
