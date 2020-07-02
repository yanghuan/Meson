#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace DefaultInterfaceAttributeNamespace {
CLASS(DefaultInterfaceAttribute) {
  public: Type get_DefaultInterface();
  private: Type m_defaultInterface;
};
} // namespace DefaultInterfaceAttributeNamespace
using DefaultInterfaceAttribute = DefaultInterfaceAttributeNamespace::DefaultInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
