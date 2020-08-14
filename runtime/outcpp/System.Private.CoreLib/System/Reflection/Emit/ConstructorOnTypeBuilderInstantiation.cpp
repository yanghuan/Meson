#include "ConstructorOnTypeBuilderInstantiation-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ConstructorBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ConstructorOnTypeBuilderInstantiation-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ConstructorOnTypeBuilderInstantiationNamespace {
MemberTypes ConstructorOnTypeBuilderInstantiation___::get_MemberType() {
  return m_ctor->get_MemberType();
}

String ConstructorOnTypeBuilderInstantiation___::get_Name() {
  return m_ctor->get_Name();
}

Type ConstructorOnTypeBuilderInstantiation___::get_DeclaringType() {
  return m_type;
}

Type ConstructorOnTypeBuilderInstantiation___::get_ReflectedType() {
  return m_type;
}

Int32 ConstructorOnTypeBuilderInstantiation___::get_MetadataTokenInternal() {
  ConstructorBuilder constructorBuilder = rt::as<ConstructorBuilder>(m_ctor);
  if (constructorBuilder != nullptr) {
    return constructorBuilder->get_MetadataTokenInternal();
  }
  return m_ctor->get_MetadataToken();
}

Module ConstructorOnTypeBuilderInstantiation___::get_Module() {
  return m_ctor->get_Module();
}

RuntimeMethodHandle ConstructorOnTypeBuilderInstantiation___::get_MethodHandle() {
  return m_ctor->get_MethodHandle();
}

MethodAttributes ConstructorOnTypeBuilderInstantiation___::get_Attributes() {
  return m_ctor->get_Attributes();
}

CallingConventions ConstructorOnTypeBuilderInstantiation___::get_CallingConvention() {
  return m_ctor->get_CallingConvention();
}

Boolean ConstructorOnTypeBuilderInstantiation___::get_IsGenericMethodDefinition() {
  return false;
}

Boolean ConstructorOnTypeBuilderInstantiation___::get_ContainsGenericParameters() {
  return false;
}

Boolean ConstructorOnTypeBuilderInstantiation___::get_IsGenericMethod() {
  return false;
}

ConstructorInfo ConstructorOnTypeBuilderInstantiation___::GetConstructor(ConstructorInfo Constructor, TypeBuilderInstantiation type) {
  return rt::newobj<ConstructorOnTypeBuilderInstantiation>(Constructor, type);
}

void ConstructorOnTypeBuilderInstantiation___::ctor(ConstructorInfo constructor, TypeBuilderInstantiation type) {
  m_ctor = constructor;
  m_type = type;
}

Array<Type> ConstructorOnTypeBuilderInstantiation___::GetParameterTypes() {
  return m_ctor->GetParameterTypes();
}

Type ConstructorOnTypeBuilderInstantiation___::GetReturnType() {
  return m_type;
}

Array<Object> ConstructorOnTypeBuilderInstantiation___::GetCustomAttributes(Boolean inherit) {
  return m_ctor->GetCustomAttributes(inherit);
}

Array<Object> ConstructorOnTypeBuilderInstantiation___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_ctor->GetCustomAttributes(attributeType, inherit);
}

Boolean ConstructorOnTypeBuilderInstantiation___::IsDefined(Type attributeType, Boolean inherit) {
  return m_ctor->IsDefined(attributeType, inherit);
}

Array<ParameterInfo> ConstructorOnTypeBuilderInstantiation___::GetParameters() {
  return m_ctor->GetParameters();
}

MethodImplAttributes ConstructorOnTypeBuilderInstantiation___::GetMethodImplementationFlags() {
  return m_ctor->GetMethodImplementationFlags();
}

Object ConstructorOnTypeBuilderInstantiation___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> ConstructorOnTypeBuilderInstantiation___::GetGenericArguments() {
  return m_ctor->GetGenericArguments();
}

Object ConstructorOnTypeBuilderInstantiation___::Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<InvalidOperationException>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ConstructorOnTypeBuilderInstantiationNamespace
