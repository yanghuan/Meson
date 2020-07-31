#include "PseudoCustomAttribute-dep.h"

namespace System::Private::CoreLib::System::Reflection::PseudoCustomAttributeNamespace {
Dictionary<RuntimeType, RuntimeType> PseudoCustomAttribute::CreatePseudoCustomAttributeDictionary() {
  return nullptr;
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeType type, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeType type, RuntimeType caType) {
  return Boolean();
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeMethodInfo method, RuntimeType caType) {
  return Boolean();
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeParameterInfo parameter, RuntimeType caType) {
  return Boolean();
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeFieldInfo field, RuntimeType caType) {
  return Boolean();
}

DllImportAttribute PseudoCustomAttribute::GetDllImportCustomAttribute(RuntimeMethodInfo method) {
  return nullptr;
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(RuntimeParameterInfo parameter) {
  return nullptr;
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(RuntimeFieldInfo field) {
  return nullptr;
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(Int32 token, RuntimeModule scope) {
  return nullptr;
}

FieldOffsetAttribute PseudoCustomAttribute::GetFieldOffsetCustomAttribute(RuntimeFieldInfo field) {
  return nullptr;
}

StructLayoutAttribute PseudoCustomAttribute::GetStructLayoutCustomAttribute(RuntimeType type) {
  return nullptr;
}

void PseudoCustomAttribute::SCtor() {
}

} // namespace System::Private::CoreLib::System::Reflection::PseudoCustomAttributeNamespace
