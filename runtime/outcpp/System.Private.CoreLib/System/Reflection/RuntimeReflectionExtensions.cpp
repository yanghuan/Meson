#include "RuntimeReflectionExtensions-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeReflectionExtensionsNamespace {
IEnumerable<FieldInfo> RuntimeReflectionExtensions::GetRuntimeFields(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
}

IEnumerable<MethodInfo> RuntimeReflectionExtensions::GetRuntimeMethods(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
}

IEnumerable<PropertyInfo> RuntimeReflectionExtensions::GetRuntimeProperties(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
}

IEnumerable<EventInfo> RuntimeReflectionExtensions::GetRuntimeEvents(Type type) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
}

FieldInfo RuntimeReflectionExtensions::GetRuntimeField(Type type, String name) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  return type->GetField(name);
}

MethodInfo RuntimeReflectionExtensions::GetRuntimeMethod(Type type, String name, Array<Type> parameters) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  return type->GetMethod(name, parameters);
}

PropertyInfo RuntimeReflectionExtensions::GetRuntimeProperty(Type type, String name) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  return type->GetProperty(name);
}

EventInfo RuntimeReflectionExtensions::GetRuntimeEvent(Type type, String name) {
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  return type->GetEvent(name);
}

MethodInfo RuntimeReflectionExtensions::GetRuntimeBaseDefinition(MethodInfo method) {
  if (method == nullptr) {
    rt::throw_exception<ArgumentNullException>("method");
  }
  return method->GetBaseDefinition();
}

InterfaceMapping RuntimeReflectionExtensions::GetRuntimeInterfaceMap(TypeInfo typeInfo, Type interfaceType) {
  if (typeInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeInfo");
  }
  return typeInfo->GetInterfaceMap(interfaceType);
}

MethodInfo RuntimeReflectionExtensions::GetMethodInfo(Delegate del) {
  if ((Object)del == nullptr) {
    rt::throw_exception<ArgumentNullException>("del");
  }
  return del->get_Method();
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeReflectionExtensionsNamespace
