#include "RuntimeReflectionExtensions-dep.h"

namespace System::Private::CoreLib::System::Reflection::RuntimeReflectionExtensionsNamespace {
IEnumerable<FieldInfo> RuntimeReflectionExtensions::GetRuntimeFields(Type type) {
  return nullptr;
};

IEnumerable<MethodInfo> RuntimeReflectionExtensions::GetRuntimeMethods(Type type) {
  return nullptr;
};

IEnumerable<PropertyInfo> RuntimeReflectionExtensions::GetRuntimeProperties(Type type) {
  return nullptr;
};

IEnumerable<EventInfo> RuntimeReflectionExtensions::GetRuntimeEvents(Type type) {
  return nullptr;
};

FieldInfo RuntimeReflectionExtensions::GetRuntimeField(Type type, String name) {
  return nullptr;
};

MethodInfo RuntimeReflectionExtensions::GetRuntimeMethod(Type type, String name, Array<Type> parameters) {
  return nullptr;
};

PropertyInfo RuntimeReflectionExtensions::GetRuntimeProperty(Type type, String name) {
  return nullptr;
};

EventInfo RuntimeReflectionExtensions::GetRuntimeEvent(Type type, String name) {
  return nullptr;
};

MethodInfo RuntimeReflectionExtensions::GetRuntimeBaseDefinition(MethodInfo method) {
  return nullptr;
};

InterfaceMapping RuntimeReflectionExtensions::GetRuntimeInterfaceMap(TypeInfo typeInfo, Type interfaceType) {
  return InterfaceMapping();
};

MethodInfo RuntimeReflectionExtensions::GetMethodInfo(Delegate del) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Reflection::RuntimeReflectionExtensionsNamespace
