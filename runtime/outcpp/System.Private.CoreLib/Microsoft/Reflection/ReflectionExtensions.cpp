#include "ReflectionExtensions-dep.h"

namespace System::Private::CoreLib::Microsoft::Reflection::ReflectionExtensionsNamespace {
Boolean ReflectionExtensions::IsEnum(Type type) {
  return type->get_IsEnum();
}

Boolean ReflectionExtensions::IsAbstract(Type type) {
  return type->get_IsAbstract();
}

Boolean ReflectionExtensions::IsSealed(Type type) {
  return type->get_IsSealed();
}

Boolean ReflectionExtensions::IsValueType(Type type) {
  return type->get_IsValueType();
}

Boolean ReflectionExtensions::IsGenericType(Type type) {
  return type->get_IsGenericType();
}

Type ReflectionExtensions::BaseType(Type type) {
  return type->get_BaseType();
}

Assembly ReflectionExtensions::Assembly(Type type) {
  return type->get_Assembly();
}

TypeCode ReflectionExtensions::GetTypeCode(Type type) {
  return Type::in::GetTypeCode(type);
}

Boolean ReflectionExtensions::ReflectionOnly(::System::Private::CoreLib::System::Reflection::Assembly assm) {
  return assm->get_ReflectionOnly();
}

} // namespace System::Private::CoreLib::Microsoft::Reflection::ReflectionExtensionsNamespace
