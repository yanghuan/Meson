#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace ManagedActivationFactoryNamespace {
CLASS(ManagedActivationFactory) {
  public: Object ActivateInstance();
  private: Type m_type;
};
} // namespace ManagedActivationFactoryNamespace
using ManagedActivationFactory = ManagedActivationFactoryNamespace::ManagedActivationFactory;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
