#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
namespace InterfaceMappingNamespace {
struct InterfaceMapping {
  public: void Ctor();
  public: Type TargetType;
  public: Type InterfaceType;
  public: Array<MethodInfo> TargetMethods;
  public: Array<MethodInfo> InterfaceMethods;
};
} // namespace InterfaceMappingNamespace
using InterfaceMapping = InterfaceMappingNamespace::InterfaceMapping;
} // namespace System::Private::CoreLib::System::Reflection
