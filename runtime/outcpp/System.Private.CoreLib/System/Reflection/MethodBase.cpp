#include "MethodBase-dep.h"

#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>

namespace System::Private::CoreLib::System::Reflection::MethodBaseNamespace {
MethodImplAttributes MethodBase___::get_MethodImplementationFlags() {
  return MethodImplAttributes::MaxMethodImplVal;
};
CallingConventions MethodBase___::get_CallingConvention() {
  return CallingConventions::ExplicitThis;
};
Boolean MethodBase___::get_IsAbstract() {
  return Boolean();
};
Boolean MethodBase___::get_IsConstructor() {
  return Boolean();
};
Boolean MethodBase___::get_IsFinal() {
  return Boolean();
};
Boolean MethodBase___::get_IsHideBySig() {
  return Boolean();
};
Boolean MethodBase___::get_IsSpecialName() {
  return Boolean();
};
Boolean MethodBase___::get_IsStatic() {
  return Boolean();
};
Boolean MethodBase___::get_IsVirtual() {
  return Boolean();
};
Boolean MethodBase___::get_IsAssembly() {
  return Boolean();
};
Boolean MethodBase___::get_IsFamily() {
  return Boolean();
};
Boolean MethodBase___::get_IsFamilyAndAssembly() {
  return Boolean();
};
Boolean MethodBase___::get_IsFamilyOrAssembly() {
  return Boolean();
};
Boolean MethodBase___::get_IsPrivate() {
  return Boolean();
};
Boolean MethodBase___::get_IsPublic() {
  return Boolean();
};
Boolean MethodBase___::get_IsConstructedGenericMethod() {
  return Boolean();
};
Boolean MethodBase___::get_IsGenericMethod() {
  return Boolean();
};
Boolean MethodBase___::get_IsGenericMethodDefinition() {
  return Boolean();
};
Boolean MethodBase___::get_ContainsGenericParameters() {
  return Boolean();
};
Boolean MethodBase___::get_IsSecurityCritical() {
  return Boolean();
};
Boolean MethodBase___::get_IsSecuritySafeCritical() {
  return Boolean();
};
Boolean MethodBase___::get_IsSecurityTransparent() {
  return Boolean();
};
MethodBase MethodBase___::GetMethodFromHandle(RuntimeMethodHandle handle) {
  return nullptr;
};
MethodBase MethodBase___::GetMethodFromHandle(RuntimeMethodHandle handle, RuntimeTypeHandle declaringType) {
  return nullptr;
};
MethodBase MethodBase___::GetCurrentMethod() {
  return nullptr;
};
IntPtr MethodBase___::GetMethodDesc() {
  return IntPtr();
};
Array<ParameterInfo> MethodBase___::GetParametersNoCopy() {
  return Array<ParameterInfo>();
};
Array<Type> MethodBase___::GetParameterTypes() {
  return Array<Type>();
};
Array<Object> MethodBase___::CheckArguments(Array<Object> parameters, Binder binder, BindingFlags invokeAttr, CultureInfo culture, Signature sig) {
  return Array<Object>();
};
MethodBody MethodBase___::GetMethodBody() {
  return nullptr;
};
Array<Type> MethodBase___::GetGenericArguments() {
  return Array<Type>();
};
Object MethodBase___::Invoke(Object obj, Array<Object> parameters) {
  return nullptr;
};
Boolean MethodBase___::Equals(Object obj) {
  return Boolean();
};
Int32 MethodBase___::GetHashCode() {
  return Int32();
};
Boolean MethodBase___::op_Equality(MethodBase left, MethodBase right) {
  return Boolean();
};
Boolean MethodBase___::op_Inequality(MethodBase left, MethodBase right) {
  return Boolean();
};
void MethodBase___::AppendParameters(ValueStringBuilder& sbParamList, Array<Type> parameterTypes, CallingConventions callingConvention) {
};
} // namespace System::Private::CoreLib::System::Reflection::MethodBaseNamespace
