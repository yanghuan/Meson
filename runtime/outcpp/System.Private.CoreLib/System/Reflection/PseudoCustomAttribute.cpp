#include "PseudoCustomAttribute-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/Reflection/ConstArray-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/LayoutKind.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::PseudoCustomAttributeNamespace {
using namespace System::Runtime::InteropServices;

Dictionary<RuntimeType, RuntimeType> PseudoCustomAttribute::CreatePseudoCustomAttributeDictionary() {
  Array<Type> array = rt::newarr<Array<Type>>(11);
  Dictionary<RuntimeType, RuntimeType> dictionary = rt::newobj<Dictionary<RuntimeType, RuntimeType>>(array->get_Length());
  Array<Type> array2 = array;
  for (Int32 i = 0; i < array2->get_Length(); i++) {
    RuntimeType runtimeType = (RuntimeType)array2[i];
    dictionary[runtimeType] = runtimeType;
  }
  return dictionary;
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeType type, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = RuntimeType::in::ListBuilder<T>();
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeType type, RuntimeType caType) {
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = RuntimeType::in::ListBuilder<T>();
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeMethodInfo method, RuntimeType caType) {
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = RuntimeType::in::ListBuilder<T>();
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeParameterInfo parameter, RuntimeType caType) {
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = RuntimeType::in::ListBuilder<T>();
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeFieldInfo field, RuntimeType caType) {
}

DllImportAttribute PseudoCustomAttribute::GetDllImportCustomAttribute(RuntimeMethodInfo method) {
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(RuntimeParameterInfo parameter) {
  return GetMarshalAsCustomAttribute(parameter->get_MetadataToken(), parameter->GetRuntimeModule());
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(RuntimeFieldInfo field) {
  return GetMarshalAsCustomAttribute(field->get_MetadataToken(), field->GetRuntimeModule());
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(Int32 token, RuntimeModule scope) {
  ConstArray fieldMarshal = ModuleHandle::GetMetadataImport(scope->GetNativeHandle()).GetFieldMarshal(token);
  if (fieldMarshal.get_Length() == 0) {
    return nullptr;
  }
}

FieldOffsetAttribute PseudoCustomAttribute::GetFieldOffsetCustomAttribute(RuntimeFieldInfo field) {
}

StructLayoutAttribute PseudoCustomAttribute::GetStructLayoutCustomAttribute(RuntimeType type) {
  if (type->get_IsInterface() || type->get_HasElementType() || type->get_IsGenericParameter()) {
    return nullptr;
  }
  LayoutKind layoutKind = LayoutKind::Auto;
}

void PseudoCustomAttribute::cctor() {
  s_pca = CreatePseudoCustomAttributeDictionary();
}

} // namespace System::Private::CoreLib::System::Reflection::PseudoCustomAttributeNamespace
