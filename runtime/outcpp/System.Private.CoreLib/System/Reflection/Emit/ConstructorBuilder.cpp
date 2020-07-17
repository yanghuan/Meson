#include "ConstructorBuilder-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::ConstructorBuilderNamespace {
Int32 ConstructorBuilder___::get_MetadataTokenInternal() {
  return Int32();
};

Module ConstructorBuilder___::get_Module() {
  return nullptr;
};

Type ConstructorBuilder___::get_ReflectedType() {
  return nullptr;
};

Type ConstructorBuilder___::get_DeclaringType() {
  return nullptr;
};

String ConstructorBuilder___::get_Name() {
  return nullptr;
};

MethodAttributes ConstructorBuilder___::get_Attributes() {
  return MethodAttributes::ReservedMask;
};

RuntimeMethodHandle ConstructorBuilder___::get_MethodHandle() {
  return RuntimeMethodHandle();
};

CallingConventions ConstructorBuilder___::get_CallingConvention() {
  return CallingConventions::ExplicitThis;
};

String ConstructorBuilder___::get_Signature() {
  return nullptr;
};

Boolean ConstructorBuilder___::get_InitLocals() {
  return Boolean();
};

void ConstructorBuilder___::set_InitLocals(Boolean value) {
};

void ConstructorBuilder___::Ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers, ModuleBuilder mod, TypeBuilder type) {
};

void ConstructorBuilder___::Ctor(String name, MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, ModuleBuilder mod, TypeBuilder type) {
};

Array<Type> ConstructorBuilder___::GetParameterTypes() {
  return Array<Type>();
};

TypeBuilder ConstructorBuilder___::GetTypeBuilder() {
  return nullptr;
};

String ConstructorBuilder___::ToString() {
  return nullptr;
};

Object ConstructorBuilder___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  return nullptr;
};

Array<ParameterInfo> ConstructorBuilder___::GetParameters() {
  return Array<ParameterInfo>();
};

MethodImplAttributes ConstructorBuilder___::GetMethodImplementationFlags() {
  return MethodImplAttributes::MaxMethodImplVal;
};

Object ConstructorBuilder___::Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  return nullptr;
};

Array<Object> ConstructorBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};

Array<Object> ConstructorBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};

Boolean ConstructorBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};

MethodToken ConstructorBuilder___::GetToken() {
  return MethodToken();
};

ParameterBuilder ConstructorBuilder___::DefineParameter(Int32 iSequence, ParameterAttributes attributes, String strParamName) {
  return nullptr;
};

ILGenerator ConstructorBuilder___::GetILGenerator() {
  return nullptr;
};

ILGenerator ConstructorBuilder___::GetILGenerator(Int32 streamSize) {
  return nullptr;
};

Module ConstructorBuilder___::GetModule() {
  return nullptr;
};

Type ConstructorBuilder___::GetReturnType() {
  return nullptr;
};

void ConstructorBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
};

void ConstructorBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
};

void ConstructorBuilder___::SetImplementationFlags(MethodImplAttributes attributes) {
};

} // namespace System::Private::CoreLib::System::Reflection::Emit::ConstructorBuilderNamespace
