#include "MethodBuilder-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::MethodBuilderNamespace {
Int32 MethodBuilder___::get_ExceptionHandlerCount() {
  return Int32();
};
String MethodBuilder___::get_Name() {
  return nullptr;
};
Int32 MethodBuilder___::get_MetadataTokenInternal() {
  return Int32();
};
Module MethodBuilder___::get_Module() {
  return nullptr;
};
Type MethodBuilder___::get_DeclaringType() {
  return nullptr;
};
ICustomAttributeProvider MethodBuilder___::get_ReturnTypeCustomAttributes() {
  return nullptr;
};
Type MethodBuilder___::get_ReflectedType() {
  return nullptr;
};
MethodAttributes MethodBuilder___::get_Attributes() {
  return MethodAttributes();
};
CallingConventions MethodBuilder___::get_CallingConvention() {
  return CallingConventions();
};
RuntimeMethodHandle MethodBuilder___::get_MethodHandle() {
  return RuntimeMethodHandle();
};
Boolean MethodBuilder___::get_IsSecurityCritical() {
  return Boolean();
};
Boolean MethodBuilder___::get_IsSecuritySafeCritical() {
  return Boolean();
};
Boolean MethodBuilder___::get_IsSecurityTransparent() {
  return Boolean();
};
Type MethodBuilder___::get_ReturnType() {
  return nullptr;
};
ParameterInfo MethodBuilder___::get_ReturnParameter() {
  return nullptr;
};
Boolean MethodBuilder___::get_IsGenericMethodDefinition() {
  return Boolean();
};
Boolean MethodBuilder___::get_ContainsGenericParameters() {
  return Boolean();
};
Boolean MethodBuilder___::get_IsGenericMethod() {
  return Boolean();
};
Boolean MethodBuilder___::get_InitLocals() {
  return Boolean();
};
void MethodBuilder___::set_InitLocals(Boolean value) {
};
String MethodBuilder___::get_Signature() {
  return nullptr;
};
void MethodBuilder___::CheckContext(Array<Array<Type>> typess) {
};
void MethodBuilder___::CheckContext(Array<Type> types) {
};
void MethodBuilder___::CreateMethodBodyHelper(ILGenerator il) {
};
void MethodBuilder___::ReleaseBakedStructures() {
};
Array<Type> MethodBuilder___::GetParameterTypes() {
  return Array<Type>();
};
Type MethodBuilder___::GetMethodBaseReturnType(MethodBase method) {
  return nullptr;
};
void MethodBuilder___::SetToken(MethodToken token) {
};
Array<Byte> MethodBuilder___::GetBody() {
  return Array<Byte>();
};
Array<Int32> MethodBuilder___::GetTokenFixups() {
  return Array<Int32>();
};
SignatureHelper MethodBuilder___::GetMethodSignature() {
  return nullptr;
};
Array<Byte> MethodBuilder___::GetLocalSignature(Int32& signatureLength) {
  return Array<Byte>();
};
Int32 MethodBuilder___::GetMaxStack() {
  return Int32();
};
Array<ExceptionHandler> MethodBuilder___::GetExceptionHandlers() {
  return Array<ExceptionHandler>();
};
Int32 MethodBuilder___::CalculateNumberOfExceptions(Array<__ExceptionInfo> excp) {
  return Int32();
};
Boolean MethodBuilder___::IsTypeCreated() {
  return Boolean();
};
TypeBuilder MethodBuilder___::GetTypeBuilder() {
  return nullptr;
};
ModuleBuilder MethodBuilder___::GetModuleBuilder() {
  return nullptr;
};
Boolean MethodBuilder___::Equals(Object obj) {
  return Boolean();
};
Int32 MethodBuilder___::GetHashCode() {
  return Int32();
};
String MethodBuilder___::ToString() {
  return nullptr;
};
Object MethodBuilder___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  return nullptr;
};
MethodImplAttributes MethodBuilder___::GetMethodImplementationFlags() {
  return MethodImplAttributes();
};
MethodInfo MethodBuilder___::GetBaseDefinition() {
  return nullptr;
};
Array<ParameterInfo> MethodBuilder___::GetParameters() {
  return Array<ParameterInfo>();
};
Array<Object> MethodBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> MethodBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
Boolean MethodBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
MethodInfo MethodBuilder___::GetGenericMethodDefinition() {
  return nullptr;
};
Array<Type> MethodBuilder___::GetGenericArguments() {
  return Array<Type>();
};
MethodInfo MethodBuilder___::MakeGenericMethod(Array<Type> typeArguments) {
  return nullptr;
};
Array<GenericTypeParameterBuilder> MethodBuilder___::DefineGenericParameters(Array<String> names) {
  return Array<GenericTypeParameterBuilder>();
};
void MethodBuilder___::ThrowIfGeneric() {
};
MethodToken MethodBuilder___::GetToken() {
  return MethodToken();
};
MethodToken MethodBuilder___::GetTokenNoLock() {
  return MethodToken();
};
void MethodBuilder___::SetParameters(Array<Type> parameterTypes) {
};
void MethodBuilder___::SetReturnType(Type returnType) {
};
void MethodBuilder___::SetSignature(Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
};
ParameterBuilder MethodBuilder___::DefineParameter(Int32 position, ParameterAttributes attributes, String strParamName) {
  return nullptr;
};
void MethodBuilder___::SetImplementationFlags(MethodImplAttributes attributes) {
};
ILGenerator MethodBuilder___::GetILGenerator() {
  return nullptr;
};
ILGenerator MethodBuilder___::GetILGenerator(Int32 size) {
  return nullptr;
};
void MethodBuilder___::ThrowIfShouldNotHaveBody() {
};
Module MethodBuilder___::GetModule() {
  return nullptr;
};
void MethodBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
};
void MethodBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
};
Boolean MethodBuilder___::IsKnownCA(ConstructorInfo con) {
  return Boolean();
};
void MethodBuilder___::ParseCA(ConstructorInfo con, Array<Byte> blob) {
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::MethodBuilderNamespace
