#include "MethodBuilderInstantiation-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::MethodBuilderInstantiationNamespace {
MemberTypes MethodBuilderInstantiation___::get_MemberType() {
  return m_method->get_MemberType();
}

String MethodBuilderInstantiation___::get_Name() {
  return m_method->get_Name();
}

Type MethodBuilderInstantiation___::get_DeclaringType() {
  return m_method->get_DeclaringType();
}

Type MethodBuilderInstantiation___::get_ReflectedType() {
  return m_method->get_ReflectedType();
}

Module MethodBuilderInstantiation___::get_Module() {
  return m_method->get_Module();
}

RuntimeMethodHandle MethodBuilderInstantiation___::get_MethodHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

MethodAttributes MethodBuilderInstantiation___::get_Attributes() {
  return m_method->get_Attributes();
}

CallingConventions MethodBuilderInstantiation___::get_CallingConvention() {
  return m_method->get_CallingConvention();
}

Boolean MethodBuilderInstantiation___::get_IsGenericMethodDefinition() {
  return false;
}

Boolean MethodBuilderInstantiation___::get_ContainsGenericParameters() {
  for (Int32 i = 0; i < m_inst->get_Length(); i++) {
    if (m_inst[i]->get_ContainsGenericParameters()) {
      return true;
    }
  }
  if (get_DeclaringType() != nullptr && get_DeclaringType()->get_ContainsGenericParameters()) {
    return true;
  }
  return false;
}

Boolean MethodBuilderInstantiation___::get_IsGenericMethod() {
  return true;
}

Type MethodBuilderInstantiation___::get_ReturnType() {
  return m_method->get_ReturnType();
}

ParameterInfo MethodBuilderInstantiation___::get_ReturnParameter() {
  rt::throw_exception<NotSupportedException>();
}

ICustomAttributeProvider MethodBuilderInstantiation___::get_ReturnTypeCustomAttributes() {
  rt::throw_exception<NotSupportedException>();
}

MethodInfo MethodBuilderInstantiation___::MakeGenericMethod(MethodInfo method, Array<Type> inst) {
  if (!method->get_IsGenericMethodDefinition()) {
    rt::throw_exception<InvalidOperationException>();
  }
  return rt::newobj<MethodBuilderInstantiation>(method, inst);
}

void MethodBuilderInstantiation___::ctor(MethodInfo method, Array<Type> inst) {
  m_method = method;
  m_inst = inst;
}

Array<Type> MethodBuilderInstantiation___::GetParameterTypes() {
  return m_method->GetParameterTypes();
}

Array<Object> MethodBuilderInstantiation___::GetCustomAttributes(Boolean inherit) {
  return m_method->GetCustomAttributes(inherit);
}

Array<Object> MethodBuilderInstantiation___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_method->GetCustomAttributes(attributeType, inherit);
}

Boolean MethodBuilderInstantiation___::IsDefined(Type attributeType, Boolean inherit) {
  return m_method->IsDefined(attributeType, inherit);
}

Array<ParameterInfo> MethodBuilderInstantiation___::GetParameters() {
  rt::throw_exception<NotSupportedException>();
}

MethodImplAttributes MethodBuilderInstantiation___::GetMethodImplementationFlags() {
  return m_method->GetMethodImplementationFlags();
}

Object MethodBuilderInstantiation___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>();
}

Array<Type> MethodBuilderInstantiation___::GetGenericArguments() {
  return m_inst;
}

MethodInfo MethodBuilderInstantiation___::GetGenericMethodDefinition() {
  return m_method;
}

MethodInfo MethodBuilderInstantiation___::MakeGenericMethod(Array<Type> arguments) {
  rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_NotGenericMethodDefinition(), (MethodBuilderInstantiation)this));
}

MethodInfo MethodBuilderInstantiation___::GetBaseDefinition() {
  rt::throw_exception<NotSupportedException>();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::MethodBuilderInstantiationNamespace
