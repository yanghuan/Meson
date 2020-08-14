#include "MethodOnTypeBuilderInstantiation-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodOnTypeBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::MethodOnTypeBuilderInstantiationNamespace {
MemberTypes MethodOnTypeBuilderInstantiation___::get_MemberType() {
  return m_method->get_MemberType();
}

String MethodOnTypeBuilderInstantiation___::get_Name() {
  return m_method->get_Name();
}

Type MethodOnTypeBuilderInstantiation___::get_DeclaringType() {
  return m_type;
}

Type MethodOnTypeBuilderInstantiation___::get_ReflectedType() {
  return m_type;
}

Module MethodOnTypeBuilderInstantiation___::get_Module() {
  return m_method->get_Module();
}

RuntimeMethodHandle MethodOnTypeBuilderInstantiation___::get_MethodHandle() {
  return m_method->get_MethodHandle();
}

MethodAttributes MethodOnTypeBuilderInstantiation___::get_Attributes() {
  return m_method->get_Attributes();
}

CallingConventions MethodOnTypeBuilderInstantiation___::get_CallingConvention() {
  return m_method->get_CallingConvention();
}

Boolean MethodOnTypeBuilderInstantiation___::get_IsGenericMethodDefinition() {
  return m_method->get_IsGenericMethodDefinition();
}

Boolean MethodOnTypeBuilderInstantiation___::get_ContainsGenericParameters() {
  return m_method->get_ContainsGenericParameters();
}

Boolean MethodOnTypeBuilderInstantiation___::get_IsGenericMethod() {
  return m_method->get_IsGenericMethod();
}

Type MethodOnTypeBuilderInstantiation___::get_ReturnType() {
  return m_method->get_ReturnType();
}

ParameterInfo MethodOnTypeBuilderInstantiation___::get_ReturnParameter() {
  rt::throw_exception<NotSupportedException>();
}

ICustomAttributeProvider MethodOnTypeBuilderInstantiation___::get_ReturnTypeCustomAttributes() {
  rt::throw_exception<NotSupportedException>();
}

MethodInfo MethodOnTypeBuilderInstantiation___::GetMethod(MethodInfo method, TypeBuilderInstantiation type) {
  return rt::newobj<MethodOnTypeBuilderInstantiation>(method, type);
}

void MethodOnTypeBuilderInstantiation___::ctor(MethodInfo method, TypeBuilderInstantiation type) {
  m_method = method;
  m_type = type;
}

Array<Type> MethodOnTypeBuilderInstantiation___::GetParameterTypes() {
  return m_method->GetParameterTypes();
}

Array<Object> MethodOnTypeBuilderInstantiation___::GetCustomAttributes(Boolean inherit) {
  return m_method->GetCustomAttributes(inherit);
}

Array<Object> MethodOnTypeBuilderInstantiation___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_method->GetCustomAttributes(attributeType, inherit);
}

Boolean MethodOnTypeBuilderInstantiation___::IsDefined(Type attributeType, Boolean inherit) {
  return m_method->IsDefined(attributeType, inherit);
}

Array<ParameterInfo> MethodOnTypeBuilderInstantiation___::GetParameters() {
  return m_method->GetParameters();
}

MethodImplAttributes MethodOnTypeBuilderInstantiation___::GetMethodImplementationFlags() {
  return m_method->GetMethodImplementationFlags();
}

Object MethodOnTypeBuilderInstantiation___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> MethodOnTypeBuilderInstantiation___::GetGenericArguments() {
  return m_method->GetGenericArguments();
}

MethodInfo MethodOnTypeBuilderInstantiation___::GetGenericMethodDefinition() {
  return m_method;
}

MethodInfo MethodOnTypeBuilderInstantiation___::MakeGenericMethod(Array<Type> typeArgs) {
  if (!get_IsGenericMethodDefinition()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_NotGenericMethodDefinition(), (MethodOnTypeBuilderInstantiation)this));
  }
  return MethodBuilderInstantiation::in::MakeGenericMethod((MethodOnTypeBuilderInstantiation)this, typeArgs);
}

MethodInfo MethodOnTypeBuilderInstantiation___::GetBaseDefinition() {
  rt::throw_exception<NotSupportedException>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::MethodOnTypeBuilderInstantiationNamespace
