#include "RuntimeEventInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::RuntimeEventInfoNamespace {
BindingFlags RuntimeEventInfo___::get_BindingFlags() {
  return BindingFlags::DoNotWrapExceptions;
};
MemberTypes RuntimeEventInfo___::get_MemberType() {
  return MemberTypes::All;
};
String RuntimeEventInfo___::get_Name() {
  return nullptr;
};
Type RuntimeEventInfo___::get_DeclaringType() {
  return nullptr;
};
Type RuntimeEventInfo___::get_ReflectedType() {
  return nullptr;
};
RuntimeType RuntimeEventInfo___::get_ReflectedTypeInternal() {
  return nullptr;
};
Int32 RuntimeEventInfo___::get_MetadataToken() {
  return Int32();
};
Module RuntimeEventInfo___::get_Module() {
  return nullptr;
};
EventAttributes RuntimeEventInfo___::get_Attributes() {
  return EventAttributes::ReservedMask;
};
Boolean RuntimeEventInfo___::CacheEquals(Object o) {
  return Boolean();
};
String RuntimeEventInfo___::ToString() {
  return nullptr;
};
Array<Object> RuntimeEventInfo___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> RuntimeEventInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
Boolean RuntimeEventInfo___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
IList<CustomAttributeData> RuntimeEventInfo___::GetCustomAttributesData() {
  return nullptr;
};
Boolean RuntimeEventInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return Boolean();
};
RuntimeModule RuntimeEventInfo___::GetRuntimeModule() {
  return nullptr;
};
Array<MethodInfo> RuntimeEventInfo___::GetOtherMethods(Boolean nonPublic) {
  return Array<MethodInfo>();
};
MethodInfo RuntimeEventInfo___::GetAddMethod(Boolean nonPublic) {
  return nullptr;
};
MethodInfo RuntimeEventInfo___::GetRemoveMethod(Boolean nonPublic) {
  return nullptr;
};
MethodInfo RuntimeEventInfo___::GetRaiseMethod(Boolean nonPublic) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Reflection::RuntimeEventInfoNamespace
