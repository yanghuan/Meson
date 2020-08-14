#include "SymbolMethod-dep.h"

#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EmptyCAHolder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolMethod-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SymbolMethodNamespace {
Module SymbolMethod___::get_Module() {
  return m_module;
}

Type SymbolMethod___::get_ReflectedType() {
  return m_containingType;
}

String SymbolMethod___::get_Name() {
  return m_name;
}

Type SymbolMethod___::get_DeclaringType() {
  return m_containingType;
}

MethodAttributes SymbolMethod___::get_Attributes() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

CallingConventions SymbolMethod___::get_CallingConvention() {
  return m_callingConvention;
}

RuntimeMethodHandle SymbolMethod___::get_MethodHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

Type SymbolMethod___::get_ReturnType() {
  return m_returnType;
}

ICustomAttributeProvider SymbolMethod___::get_ReturnTypeCustomAttributes() {
  return rt::newobj<EmptyCAHolder>();
}

void SymbolMethod___::ctor(ModuleBuilder mod, MethodToken token, Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  m_mdMethod = token;
  auto default = returnType;
  if (default != nullptr) default = rt::typeof<void>();

  m_returnType = (default);
  if (parameterTypes != nullptr) {
    m_parameterTypes = rt::newarr<Array<Type>>(parameterTypes->get_Length());
    Array<>::in::Copy(parameterTypes, m_parameterTypes, parameterTypes->get_Length());
  } else {
    m_parameterTypes = Array<>::in::Empty<Type>();
  }
  m_module = mod;
  m_containingType = arrayClass;
  m_name = methodName;
  m_callingConvention = callingConvention;
  m_signature = SignatureHelper::in::GetMethodSigHelper(mod, callingConvention, returnType, nullptr, nullptr, parameterTypes, nullptr, nullptr);
}

Array<Type> SymbolMethod___::GetParameterTypes() {
  return m_parameterTypes;
}

MethodToken SymbolMethod___::GetToken(ModuleBuilder mod) {
  return mod->GetArrayMethodToken(m_containingType, m_name, m_callingConvention, m_returnType, m_parameterTypes);
}

Array<ParameterInfo> SymbolMethod___::GetParameters() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

MethodImplAttributes SymbolMethod___::GetMethodImplementationFlags() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

Object SymbolMethod___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

MethodInfo SymbolMethod___::GetBaseDefinition() {
  return (SymbolMethod)this;
}

Array<Object> SymbolMethod___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

Array<Object> SymbolMethod___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

Boolean SymbolMethod___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SymbolMethod());
}

Module SymbolMethod___::GetModule() {
  return m_module;
}

MethodToken SymbolMethod___::GetToken() {
  return m_mdMethod;
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SymbolMethodNamespace
