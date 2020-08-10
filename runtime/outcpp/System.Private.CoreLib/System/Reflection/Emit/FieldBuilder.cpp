#include "FieldBuilder-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::FieldBuilderNamespace {
Int32 FieldBuilder___::get_MetadataTokenInternal() {
  return Int32();
}

Module FieldBuilder___::get_Module() {
  return nullptr;
}

String FieldBuilder___::get_Name() {
  return nullptr;
}

Type FieldBuilder___::get_DeclaringType() {
  return nullptr;
}

Type FieldBuilder___::get_ReflectedType() {
  return nullptr;
}

Type FieldBuilder___::get_FieldType() {
  return nullptr;
}

RuntimeFieldHandle FieldBuilder___::get_FieldHandle() {
  return RuntimeFieldHandle();
}

FieldAttributes FieldBuilder___::get_Attributes() {
  return FieldAttributes::ReservedMask;
}

void FieldBuilder___::ctor(TypeBuilder typeBuilder, String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes) {
}

void FieldBuilder___::SetData(Array<Byte> data, Int32 size) {
}

Object FieldBuilder___::GetValue(Object obj) {
  return nullptr;
}

void FieldBuilder___::SetValue(Object obj, Object val, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
}

Array<Object> FieldBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
}

Array<Object> FieldBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
}

Boolean FieldBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
}

FieldToken FieldBuilder___::GetToken() {
  return FieldToken();
}

void FieldBuilder___::SetOffset(Int32 iOffset) {
}

void FieldBuilder___::SetConstant(Object defaultValue) {
}

void FieldBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
}

void FieldBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::FieldBuilderNamespace
