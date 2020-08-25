#include "CustomAttributeNamedArgument-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamedArgumentNamespace {
Type CustomAttributeNamedArgument::get_ArgumentType() {
  if (!rt::is<FieldInfo>(m_memberInfo)) {
    return ((PropertyInfo)m_memberInfo)->get_PropertyType();
  }
  return ((FieldInfo)m_memberInfo)->get_FieldType();
}

MemberInfo CustomAttributeNamedArgument::get_MemberInfo() {
  return m_memberInfo;
}

CustomAttributeTypedArgument CustomAttributeNamedArgument::get_TypedValue() {
  return m_value;
}

String CustomAttributeNamedArgument::get_MemberName() {
  return get_MemberInfo()->get_Name();
}

Boolean CustomAttributeNamedArgument::get_IsField() {
  return rt::is<FieldInfo>(get_MemberInfo());
}

Boolean CustomAttributeNamedArgument::op_Equality(CustomAttributeNamedArgument left, CustomAttributeNamedArgument right) {
  return left.Equals(right);
}

Boolean CustomAttributeNamedArgument::op_Inequality(CustomAttributeNamedArgument left, CustomAttributeNamedArgument right) {
  return !left.Equals(right);
}

CustomAttributeNamedArgument::CustomAttributeNamedArgument(MemberInfo memberInfo, Object value) {
  if (memberInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("memberInfo");
  }
  FieldInfo fieldInfo = rt::as<FieldInfo>(memberInfo);
  Type argumentType;
  if ((Object)fieldInfo != nullptr) {
    argumentType = fieldInfo->get_FieldType();
  } else {
    PropertyInfo propertyInfo = rt::as<PropertyInfo>(memberInfo);
    if ((Object)propertyInfo == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidMemberForNamedArgument());
    }
    argumentType = propertyInfo->get_PropertyType();
  }
  m_memberInfo = memberInfo;
  m_value = CustomAttributeTypedArgument(argumentType, value);
}

CustomAttributeNamedArgument::CustomAttributeNamedArgument(MemberInfo memberInfo, CustomAttributeTypedArgument typedArgument) {
  if ((Object)memberInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("memberInfo");
  }
  m_memberInfo = memberInfo;
  m_value = typedArgument;
}

String CustomAttributeNamedArgument::ToString() {
  if (m_memberInfo == nullptr) {
    return ValueType::in::ToString();
  }
  return String::in::Format("{0} = {1}", get_MemberInfo()->get_Name(), get_TypedValue().ToString(get_ArgumentType() != typeof<Object>()));
}

Int32 CustomAttributeNamedArgument::GetHashCode() {
  return ValueType::in::GetHashCode();
}

Boolean CustomAttributeNamedArgument::Equals(Object obj) {
  return obj == (Object)*this;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamedArgumentNamespace
