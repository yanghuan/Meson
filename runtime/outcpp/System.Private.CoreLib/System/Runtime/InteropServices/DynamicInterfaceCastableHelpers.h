#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(RuntimeType)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(IDynamicInterfaceCastable)
namespace DynamicInterfaceCastableHelpersNamespace {
class DynamicInterfaceCastableHelpers {
  public: static Boolean IsInterfaceImplemented(IDynamicInterfaceCastable castable, RuntimeType interfaceType, Boolean throwIfNotImplemented);
  public: static RuntimeType GetInterfaceImplementation(IDynamicInterfaceCastable castable, RuntimeType interfaceType);
};
} // namespace DynamicInterfaceCastableHelpersNamespace
using DynamicInterfaceCastableHelpers = DynamicInterfaceCastableHelpersNamespace::DynamicInterfaceCastableHelpers;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
