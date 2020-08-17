#include "ConstructorBuilder-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilder-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ConstructorBuilderNamespace {
Int32 ConstructorBuilder___::get_MetadataTokenInternal() {
  return m_methodBuilder->get_MetadataTokenInternal();
}

Module ConstructorBuilder___::get_Module() {
  return m_methodBuilder->get_Module();
}

Type ConstructorBuilder___::get_ReflectedType() {
  return m_methodBuilder->get_ReflectedType();
}

Type ConstructorBuilder___::get_DeclaringType() {
  return m_methodBuilder->get_DeclaringType();
}

String ConstructorBuilder___::get_Name() {
  return m_methodBuilder->get_Name();
}

MethodAttributes ConstructorBuilder___::get_Attributes() {
  return m_methodBuilder->get_Attributes();
}

RuntimeMethodHandle ConstructorBuilder___::get_MethodHandle() {
  return m_methodBuilder->get_MethodHandle();
}

CallingConventions ConstructorBuilder___::get_CallingConvention() {
  if (get_DeclaringType()->get_IsGenericType()) {
    return CallingConventions::HasThis;
  }
  return CallingConventions::Standard;
}

String ConstructorBuilder___::get_Signature() {
  return m_methodBuilder->get_Signature();
}

Boolean ConstructorBuilder___::get_InitLocals() {
  return m_methodBuilder->get_InitLocals();
}

void ConstructorBuilder___::set_InitLocals(Boolean value) {
  m_methodBuilder->set_InitLocals(value);
}

void ConstructorBuilder___::ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers, ModuleBuilder mod, TypeBuilder type) {
  m_methodBuilder = rt::newobj<MethodBuilder>(name, attributes, callingConvention, nullptr, nullptr, nullptr, parameterTypes, requiredCustomModifiers, optionalCustomModifiers, mod, type);
  type->m_listMethods->Add(m_methodBuilder);
  Int32 _;
  m_methodBuilder->GetMethodSignature()->InternalGetSignature(_);
  m_methodBuilder->GetToken();
}

void ConstructorBuilder___::ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, ModuleBuilder mod, TypeBuilder type) {
}

Array<Type> ConstructorBuilder___::GetParameterTypes() {
  return m_methodBuilder->GetParameterTypes();
}

TypeBuilder ConstructorBuilder___::GetTypeBuilder() {
  return m_methodBuilder->GetTypeBuilder();
}

String ConstructorBuilder___::ToString() {
  return m_methodBuilder->ToString();
}

Object ConstructorBuilder___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<ParameterInfo> ConstructorBuilder___::GetParameters() {
  ConstructorInfo constructor = GetTypeBuilder()->GetConstructor(m_methodBuilder->m_parameterTypes);
  return constructor->GetParameters();
}

MethodImplAttributes ConstructorBuilder___::GetMethodImplementationFlags() {
  return m_methodBuilder->GetMethodImplementationFlags();
}

Object ConstructorBuilder___::Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<Object> ConstructorBuilder___::GetCustomAttributes(Boolean inherit) {
  return m_methodBuilder->GetCustomAttributes(inherit);
}

Array<Object> ConstructorBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return m_methodBuilder->GetCustomAttributes(attributeType, inherit);
}

Boolean ConstructorBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return m_methodBuilder->IsDefined(attributeType, inherit);
}

MethodToken ConstructorBuilder___::GetToken() {
  return m_methodBuilder->GetToken();
}

ParameterBuilder ConstructorBuilder___::DefineParameter(Int32 iSequence, ParameterAttributes attributes, String strParamName) {
  attributes &= ~(ParameterAttributes::HasDefault | ParameterAttributes::HasFieldMarshal | ParameterAttributes::Reserved3 | ParameterAttributes::Reserved4);
  return m_methodBuilder->DefineParameter(iSequence, attributes, strParamName);
}

ILGenerator ConstructorBuilder___::GetILGenerator() {
  if (m_isDefaultConstructor) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_DefaultConstructorILGen());
  }
  return m_methodBuilder->GetILGenerator();
}

ILGenerator ConstructorBuilder___::GetILGenerator(Int32 streamSize) {
  if (m_isDefaultConstructor) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_DefaultConstructorILGen());
  }
  return m_methodBuilder->GetILGenerator(streamSize);
}

Module ConstructorBuilder___::GetModule() {
  return m_methodBuilder->GetModule();
}

Type ConstructorBuilder___::GetReturnType() {
  return m_methodBuilder->get_ReturnType();
}

void ConstructorBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  m_methodBuilder->SetCustomAttribute(con, binaryAttribute);
}

void ConstructorBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  m_methodBuilder->SetCustomAttribute(customBuilder);
}

void ConstructorBuilder___::SetImplementationFlags(MethodImplAttributes attributes) {
  m_methodBuilder->SetImplementationFlags(attributes);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ConstructorBuilderNamespace
