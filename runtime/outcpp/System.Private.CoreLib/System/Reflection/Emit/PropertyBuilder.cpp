#include "PropertyBuilder-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::PropertyBuilderNamespace {
PropertyToken PropertyBuilder___::get_PropertyToken() {
  return PropertyToken();
};
Module PropertyBuilder___::get_Module() {
  return nullptr;
};
Type PropertyBuilder___::get_PropertyType() {
  return nullptr;
};
PropertyAttributes PropertyBuilder___::get_Attributes() {
  return PropertyAttributes();
};
Boolean PropertyBuilder___::get_CanRead() {
  return Boolean();
};
Boolean PropertyBuilder___::get_CanWrite() {
  return Boolean();
};
String PropertyBuilder___::get_Name() {
  return nullptr;
};
Type PropertyBuilder___::get_DeclaringType() {
  return nullptr;
};
Type PropertyBuilder___::get_ReflectedType() {
  return nullptr;
};
void PropertyBuilder___::SetConstant(Object defaultValue) {
  return void();
};
void PropertyBuilder___::SetMethodSemantics(MethodBuilder mdBuilder, MethodSemanticsAttributes semantics) {
  return void();
};
void PropertyBuilder___::SetGetMethod(MethodBuilder mdBuilder) {
  return void();
};
void PropertyBuilder___::SetSetMethod(MethodBuilder mdBuilder) {
  return void();
};
void PropertyBuilder___::AddOtherMethod(MethodBuilder mdBuilder) {
  return void();
};
void PropertyBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  return void();
};
void PropertyBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  return void();
};
Object PropertyBuilder___::GetValue(Object obj, Array<Object> index) {
  return nullptr;
};
Object PropertyBuilder___::GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  return nullptr;
};
void PropertyBuilder___::SetValue(Object obj, Object value, Array<Object> index) {
  return void();
};
void PropertyBuilder___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  return void();
};
Array<MethodInfo> PropertyBuilder___::GetAccessors(Boolean nonPublic) {
  return Array<MethodInfo>();
};
MethodInfo PropertyBuilder___::GetGetMethod(Boolean nonPublic) {
  return nullptr;
};
MethodInfo PropertyBuilder___::GetSetMethod(Boolean nonPublic) {
  return nullptr;
};
Array<ParameterInfo> PropertyBuilder___::GetIndexParameters() {
  return Array<ParameterInfo>();
};
Array<Object> PropertyBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> PropertyBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
Boolean PropertyBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::PropertyBuilderNamespace