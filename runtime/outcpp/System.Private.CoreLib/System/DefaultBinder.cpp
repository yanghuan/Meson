#include "DefaultBinder-dep.h"

namespace System::Private::CoreLib::System::DefaultBinderNamespace {
void DefaultBinder___::BinderState___::Ctor(Array<Int32> argsMap, Int32 originalSize, Boolean isParamArray) {
};

MethodBase DefaultBinder___::BindToMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Object>& args, Array<ParameterModifier> modifiers, CultureInfo cultureInfo, Array<String> names, Object& state) {
  return nullptr;
};

FieldInfo DefaultBinder___::BindToField(BindingFlags bindingAttr, Array<FieldInfo> match, Object value, CultureInfo cultureInfo) {
  return nullptr;
};

MethodBase DefaultBinder___::SelectMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};

PropertyInfo DefaultBinder___::SelectProperty(BindingFlags bindingAttr, Array<PropertyInfo> match, Type returnType, Array<Type> indexes, Array<ParameterModifier> modifiers) {
  return nullptr;
};

Object DefaultBinder___::ChangeType(Object value, Type type, CultureInfo cultureInfo) {
  return nullptr;
};

void DefaultBinder___::ReorderArgumentArray(Array<Object>& args, Object state) {
};

MethodBase DefaultBinder___::ExactBinding(Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};

PropertyInfo DefaultBinder___::ExactPropertyBinding(Array<PropertyInfo> match, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};

Int32 DefaultBinder___::FindMostSpecific(Array<ParameterInfo> p1, Array<Int32> paramOrder1, Type paramArrayType1, Array<ParameterInfo> p2, Array<Int32> paramOrder2, Type paramArrayType2, Array<Type> types, Array<Object> args) {
  return Int32();
};

Int32 DefaultBinder___::FindMostSpecificType(Type c1, Type c2, Type t) {
  return Int32();
};

Int32 DefaultBinder___::FindMostSpecificMethod(MethodBase m1, Array<Int32> paramOrder1, Type paramArrayType1, MethodBase m2, Array<Int32> paramOrder2, Type paramArrayType2, Array<Type> types, Array<Object> args) {
  return Int32();
};

Int32 DefaultBinder___::FindMostSpecificField(FieldInfo cur1, FieldInfo cur2) {
  return Int32();
};

Int32 DefaultBinder___::FindMostSpecificProperty(PropertyInfo cur1, PropertyInfo cur2) {
  return Int32();
};

Boolean DefaultBinder___::CompareMethodSig(MethodBase m1, MethodBase m2) {
  return Boolean();
};

Int32 DefaultBinder___::GetHierarchyDepth(Type t) {
  return Int32();
};

MethodBase DefaultBinder___::FindMostDerivedNewSlotMeth(Array<MethodBase> match, Int32 cMatches) {
  return nullptr;
};

void DefaultBinder___::ReorderParams(Array<Int32> paramOrder, Array<Object> vars) {
};

Boolean DefaultBinder___::CreateParamOrder(Array<Int32> paramOrder, Array<ParameterInfo> pars, Array<String> names) {
  return Boolean();
};

Boolean DefaultBinder___::CanChangePrimitive(Type source, Type target) {
  return Boolean();
};

void DefaultBinder___::Ctor() {
};

void DefaultBinder___::SCtor() {
};

} // namespace System::Private::CoreLib::System::DefaultBinderNamespace
