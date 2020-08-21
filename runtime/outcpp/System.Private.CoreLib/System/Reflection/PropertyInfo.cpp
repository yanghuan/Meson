#include "PropertyInfo-dep.h"

#include <System.Private.CoreLib/System/NotImplemented-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>

namespace System::Private::CoreLib::System::Reflection::PropertyInfoNamespace {
MemberTypes PropertyInfo___::get_MemberType() {
  return MemberTypes::Property;
}

Boolean PropertyInfo___::get_IsSpecialName() {
  return (get_Attributes() & PropertyAttributes::SpecialName) != 0;
}

MethodInfo PropertyInfo___::get_GetMethod() {
  return GetGetMethod(true);
}

MethodInfo PropertyInfo___::get_SetMethod() {
  return GetSetMethod(true);
}

void PropertyInfo___::ctor() {
}

Array<MethodInfo> PropertyInfo___::GetAccessors() {
  return GetAccessors(false);
}

MethodInfo PropertyInfo___::GetGetMethod() {
  return GetGetMethod(false);
}

MethodInfo PropertyInfo___::GetSetMethod() {
  return GetSetMethod(false);
}

Array<Type> PropertyInfo___::GetOptionalCustomModifiers() {
  return Array<>::in::Empty<Type>();
}

Array<Type> PropertyInfo___::GetRequiredCustomModifiers() {
  return Array<>::in::Empty<Type>();
}

Object PropertyInfo___::GetValue(Object obj) {
  return GetValue(obj, nullptr);
}

Object PropertyInfo___::GetValue(Object obj, Array<Object> index) {
  return GetValue(obj, BindingFlags::Default, nullptr, index, nullptr);
}

Object PropertyInfo___::GetConstantValue() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

Object PropertyInfo___::GetRawConstantValue() {
  rt::throw_exception(NotImplemented::get_ByDesign());
}

void PropertyInfo___::SetValue(Object obj, Object value) {
  SetValue(obj, value, nullptr);
}

void PropertyInfo___::SetValue(Object obj, Object value, Array<Object> index) {
  SetValue(obj, value, BindingFlags::Default, nullptr, index, nullptr);
}

Boolean PropertyInfo___::Equals(Object obj) {
  return MemberInfo::in::Equals(obj);
}

Int32 PropertyInfo___::GetHashCode() {
  return MemberInfo::in::GetHashCode();
}

Boolean PropertyInfo___::op_Equality(PropertyInfo left, PropertyInfo right) {
  if ((Object)right == nullptr) {
    if ((Object)left != nullptr) {
      return false;
    }
    return true;
  }
  if ((Object)left == right) {
    return true;
  }
  if ((Object)left != nullptr) {
    return left->Equals(right);
  }
  return false;
}

Boolean PropertyInfo___::op_Inequality(PropertyInfo left, PropertyInfo right) {
  return !(left == right);
}

} // namespace System::Private::CoreLib::System::Reflection::PropertyInfoNamespace
