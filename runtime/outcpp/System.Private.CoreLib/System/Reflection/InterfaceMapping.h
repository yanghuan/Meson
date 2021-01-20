#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
namespace InterfaceMappingNamespace {
struct InterfaceMapping : public valueType<InterfaceMapping> {
  public: Type TargetType;
  public: Type InterfaceType;
  public: Array<MethodInfo> TargetMethods;
  public: Array<MethodInfo> InterfaceMethods;
};
} // namespace InterfaceMappingNamespace
using InterfaceMapping = InterfaceMappingNamespace::InterfaceMapping;
} // namespace System::Private::CoreLib::System::Reflection
