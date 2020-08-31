#include "DynamicInterfaceCastableHelpers-dep.h"

#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DynamicInterfaceCastableImplementationAttribute-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::DynamicInterfaceCastableHelpersNamespace {
Boolean DynamicInterfaceCastableHelpers::IsInterfaceImplemented(IDynamicInterfaceCastable castable, RuntimeType interfaceType, Boolean throwIfNotImplemented) {
  Boolean flag = castable->IsInterfaceImplemented(RuntimeTypeHandle(interfaceType), throwIfNotImplemented);
  if (!flag && throwIfNotImplemented) {
    rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), castable->GetType(), interfaceType));
  }
  return flag;
}

RuntimeType DynamicInterfaceCastableHelpers::GetInterfaceImplementation(IDynamicInterfaceCastable castable, RuntimeType interfaceType) {
  RuntimeTypeHandle interfaceImplementation = castable->GetInterfaceImplementation(RuntimeTypeHandle(interfaceType));
  if (interfaceImplementation.Equals(RuntimeTypeHandle())) {
    rt::throw_exception<InvalidCastException>(SR::Format(SR::get_InvalidCast_FromTo(), castable->GetType(), interfaceType));
  }
  RuntimeType runtimeType = interfaceImplementation.GetRuntimeType();
  if (!runtimeType->get_IsInterface()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_IDynamicInterfaceCastable_NotInterface(), runtimeType->ToString()));
  }
  if (!runtimeType->IsDefined(typeof<DynamicInterfaceCastableImplementationAttribute>(), false)) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_IDynamicInterfaceCastable_MissingImplementationAttribute(), runtimeType, "DynamicInterfaceCastableImplementationAttribute"));
  }
  if (!runtimeType->ImplementInterface(interfaceType)) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_IDynamicInterfaceCastable_DoesNotImplementRequested(), runtimeType, interfaceType));
  }
  return runtimeType;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::DynamicInterfaceCastableHelpersNamespace
