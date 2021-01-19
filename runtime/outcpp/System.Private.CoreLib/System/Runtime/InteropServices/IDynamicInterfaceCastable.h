#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(RuntimeTypeHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace IDynamicInterfaceCastableNamespace {
CLASS(IDynamicInterfaceCastable) : public object {
  public: Boolean IsInterfaceImplemented(RuntimeTypeHandle interfaceType, Boolean throwIfNotImplemented);
  public: RuntimeTypeHandle GetInterfaceImplementation(RuntimeTypeHandle interfaceType);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDynamicInterfaceCastableNamespace
using IDynamicInterfaceCastable = IDynamicInterfaceCastableNamespace::IDynamicInterfaceCastable;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
