#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
namespace InterfaceMappingNamespace {
struct InterfaceMapping {
  public: Type TargetType;
  public: Type InterfaceType;
  public: Array<MethodInfo> TargetMethods;
  public: Array<MethodInfo> InterfaceMethods;
};
} // namespace InterfaceMappingNamespace
using InterfaceMapping = InterfaceMappingNamespace::InterfaceMapping;
} // namespace System::Private::CoreLib::System::Reflection
