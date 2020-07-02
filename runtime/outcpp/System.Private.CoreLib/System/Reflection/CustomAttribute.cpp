#include "CustomAttribute-dep.h"

namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamespace {
Boolean CustomAttribute::IsDefined(RuntimeType type, RuntimeType caType, Boolean inherit) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeMethodInfo method, RuntimeType caType, Boolean inherit) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeConstructorInfo ctor, RuntimeType caType) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimePropertyInfo property, RuntimeType caType) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeEventInfo e, RuntimeType caType) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeFieldInfo field, RuntimeType caType) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeParameterInfo parameter, RuntimeType caType) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeAssembly assembly, RuntimeType caType) {
  return Boolean();
};
Boolean CustomAttribute::IsDefined(RuntimeModule module, RuntimeType caType) {
  return Boolean();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeType type, RuntimeType caType, Boolean inherit) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, Boolean inherit) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeConstructorInfo ctor, RuntimeType caType) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimePropertyInfo property, RuntimeType caType) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeEventInfo e, RuntimeType caType) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeAssembly assembly, RuntimeType caType) {
  return Array<Object>();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeModule module, RuntimeType caType) {
  return Array<Object>();
};
Boolean CustomAttribute::IsCustomAttributeDefined(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType) {
  return Boolean();
};
Boolean CustomAttribute::IsCustomAttributeDefined(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType, Int32 attributeCtorToken, Boolean mustBeInheritable) {
  return Boolean();
};
Array<Object> CustomAttribute::GetCustomAttributes(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, Int32 pcaCount, RuntimeType attributeFilterType) {
  return Array<Object>();
};
void CustomAttribute::AddCustomAttributes(RuntimeType::in::ListBuilder<Object>& attributes, RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object> derivedAttributes) {
  return void();
};
Boolean CustomAttribute::FilterCustomAttributeRecord(MetadataToken caCtorToken, MetadataImport& scope, RuntimeModule decoratedModule, MetadataToken decoratedToken, RuntimeType attributeFilterType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object>& derivedAttributes, RuntimeType& attributeType, IRuntimeMethodInfo& ctor, Boolean& ctorHasParameters, Boolean& isVarArg) {
  return Boolean();
};
Boolean CustomAttribute::AttributeUsageCheck(RuntimeType attributeType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object>& derivedAttributes) {
  return Boolean();
};
AttributeUsageAttribute CustomAttribute::GetAttributeUsage(RuntimeType decoratedAttribute) {
  return nullptr;
};
void CustomAttribute::ParseAttributeUsageAttribute(ConstArray ca, AttributeTargets& targets, Boolean& inherited, Boolean& allowMultiple) {
  return void();
};
Object CustomAttribute::CreateCaObject(RuntimeModule module, RuntimeType type, IRuntimeMethodInfo ctor, IntPtr& blob, IntPtr blobEnd, Int32& namedArgs) {
  return nullptr;
};
void CustomAttribute::GetPropertyOrFieldData(RuntimeModule module, IntPtr& blobStart, IntPtr blobEnd, String& name, Boolean& isProperty, RuntimeType& type, Object& value) {
  return void();
};
Array<Object> CustomAttribute::CreateAttributeArrayHelper(RuntimeType elementType, Int32 elementCount) {
  return Array<Object>();
};
} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamespace
