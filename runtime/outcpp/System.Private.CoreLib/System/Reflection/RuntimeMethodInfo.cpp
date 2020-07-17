#include "RuntimeMethodInfo-dep.h"

#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeMethodInfoNamespace {
INVOCATION_FLAGS RuntimeMethodInfo___::get_InvocationFlags() {
  return INVOCATION_FLAGS::INVOCATION_FLAGS_CONSTRUCTOR_INVOKE;
};

RuntimeMethodHandleInternal RuntimeMethodInfo___::get_ValueOfIRuntimeMethodInfo() {
  return RuntimeMethodHandleInternal();
};

RuntimeType RuntimeMethodInfo___::get_ReflectedTypeInternal() {
  return nullptr;
};

Signature RuntimeMethodInfo___::get_Signature() {
  return nullptr;
};

BindingFlags RuntimeMethodInfo___::get_BindingFlags() {
  return BindingFlags::DoNotWrapExceptions;
};

Int32 RuntimeMethodInfo___::get_GenericParameterCount() {
  return Int32();
};

String RuntimeMethodInfo___::get_Name() {
  return nullptr;
};

Type RuntimeMethodInfo___::get_DeclaringType() {
  return nullptr;
};

Type RuntimeMethodInfo___::get_ReflectedType() {
  return nullptr;
};

MemberTypes RuntimeMethodInfo___::get_MemberType() {
  return MemberTypes::All;
};

Int32 RuntimeMethodInfo___::get_MetadataToken() {
  return Int32();
};

Module RuntimeMethodInfo___::get_Module() {
  return nullptr;
};

Boolean RuntimeMethodInfo___::get_IsSecurityCritical() {
  return Boolean();
};

Boolean RuntimeMethodInfo___::get_IsSecuritySafeCritical() {
  return Boolean();
};

Boolean RuntimeMethodInfo___::get_IsSecurityTransparent() {
  return Boolean();
};

RuntimeMethodHandle RuntimeMethodInfo___::get_MethodHandle() {
  return RuntimeMethodHandle();
};

MethodAttributes RuntimeMethodInfo___::get_Attributes() {
  return MethodAttributes::ReservedMask;
};

CallingConventions RuntimeMethodInfo___::get_CallingConvention() {
  return CallingConventions::ExplicitThis;
};

Type RuntimeMethodInfo___::get_ReturnType() {
  return nullptr;
};

ICustomAttributeProvider RuntimeMethodInfo___::get_ReturnTypeCustomAttributes() {
  return nullptr;
};

ParameterInfo RuntimeMethodInfo___::get_ReturnParameter() {
  return nullptr;
};

Boolean RuntimeMethodInfo___::get_IsCollectible() {
  return Boolean();
};

Boolean RuntimeMethodInfo___::get_IsGenericMethod() {
  return Boolean();
};

Boolean RuntimeMethodInfo___::get_IsGenericMethodDefinition() {
  return Boolean();
};

Boolean RuntimeMethodInfo___::get_ContainsGenericParameters() {
  return Boolean();
};

Boolean RuntimeMethodInfo___::IsDisallowedByRefType(Type type) {
  return Boolean();
};

void RuntimeMethodInfo___::Ctor(RuntimeMethodHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, MethodAttributes methodAttributes, BindingFlags bindingFlags, Object keepalive) {
};

Array<ParameterInfo> RuntimeMethodInfo___::FetchNonReturnParameters() {
  return Array<ParameterInfo>();
};

ParameterInfo RuntimeMethodInfo___::FetchReturnParameter() {
  return nullptr;
};

Boolean RuntimeMethodInfo___::CacheEquals(Object o) {
  return Boolean();
};

RuntimeMethodInfo RuntimeMethodInfo___::GetParentDefinition() {
  return nullptr;
};

RuntimeType RuntimeMethodInfo___::GetDeclaringTypeInternal() {
  return nullptr;
};

String RuntimeMethodInfo___::ToString() {
  return nullptr;
};

Int32 RuntimeMethodInfo___::GetHashCode() {
  return Int32();
};

Boolean RuntimeMethodInfo___::Equals(Object obj) {
  return Boolean();
};

Array<Object> RuntimeMethodInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};

Array<Object> RuntimeMethodInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};

Boolean RuntimeMethodInfo___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};

IList<CustomAttributeData> RuntimeMethodInfo___::GetCustomAttributesData() {
  return nullptr;
};

Boolean RuntimeMethodInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return Boolean();
};

RuntimeType RuntimeMethodInfo___::GetRuntimeType() {
  return nullptr;
};

RuntimeModule RuntimeMethodInfo___::GetRuntimeModule() {
  return nullptr;
};

Array<ParameterInfo> RuntimeMethodInfo___::GetParametersNoCopy() {
  return Array<ParameterInfo>();
};

Array<ParameterInfo> RuntimeMethodInfo___::GetParameters() {
  return Array<ParameterInfo>();
};

MethodImplAttributes RuntimeMethodInfo___::GetMethodImplementationFlags() {
  return MethodImplAttributes::MaxMethodImplVal;
};

MethodBody RuntimeMethodInfo___::GetMethodBody() {
  return nullptr;
};

void RuntimeMethodInfo___::CheckConsistency(Object target) {
};

void RuntimeMethodInfo___::ThrowNoInvokeException() {
};

Object RuntimeMethodInfo___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  return nullptr;
};

Array<Object> RuntimeMethodInfo___::InvokeArgumentsCheck(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  return Array<Object>();
};

MethodInfo RuntimeMethodInfo___::GetBaseDefinition() {
  return nullptr;
};

Delegate RuntimeMethodInfo___::CreateDelegate(Type delegateType) {
  return nullptr;
};

Delegate RuntimeMethodInfo___::CreateDelegate(Type delegateType, Object target) {
  return nullptr;
};

Delegate RuntimeMethodInfo___::CreateDelegateInternal(Type delegateType, Object firstArgument, DelegateBindingFlags bindingFlags) {
  return nullptr;
};

MethodInfo RuntimeMethodInfo___::MakeGenericMethod(Array<Type> methodInstantiation) {
  return nullptr;
};

Array<RuntimeType> RuntimeMethodInfo___::GetGenericArgumentsInternal() {
  return Array<RuntimeType>();
};

Array<Type> RuntimeMethodInfo___::GetGenericArguments() {
  return Array<Type>();
};

MethodInfo RuntimeMethodInfo___::GetGenericMethodDefinition() {
  return nullptr;
};

MethodBase RuntimeMethodInfo___::InternalGetCurrentMethod(StackCrawlMark& stackMark) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Reflection::RuntimeMethodInfoNamespace
