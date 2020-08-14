#include "Attribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Attribute-dep.h>
#include <System.Private.CoreLib/System/AttributeUsageAttribute-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/AmbiguousMatchException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MemberTypes.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::AttributeNamespace {
using namespace System::Collections::Generic;
using namespace System::Reflection;

Object Attribute___::get_TypeId() {
  return GetType();
}

Array<Attribute> Attribute___::InternalGetCustomAttributes(PropertyInfo element, Type type, Boolean inherit) {
  Array<Attribute> array = (Array<Attribute>)element->GetCustomAttributes(type, inherit);
  if (!inherit) {
    return array;
  }
  Dictionary<Type, AttributeUsageAttribute> types = rt::newobj<Dictionary<Type, AttributeUsageAttribute>>(11);
  List<Attribute> list = rt::newobj<List<Attribute>>();
  CopyToArrayList(list, array, types);
  Array<Type> indexParameterTypes = GetIndexParameterTypes(element);
  PropertyInfo parentDefinition = GetParentDefinition(element, indexParameterTypes);
  while (parentDefinition != nullptr) {
    array = GetCustomAttributes(parentDefinition, type, false);
    AddAttributesToList(list, array, types);
    parentDefinition = GetParentDefinition(parentDefinition, indexParameterTypes);
  }
  Array<Attribute> array2 = CreateAttributeArrayHelper(type, list->get_Count());
  list->CopyTo(array2, 0);
  return array2;
}

Boolean Attribute___::InternalIsDefined(PropertyInfo element, Type attributeType, Boolean inherit) {
  if (element->IsDefined(attributeType, inherit)) {
    return true;
  }
  if (inherit) {
    AttributeUsageAttribute attributeUsageAttribute = InternalGetAttributeUsage(attributeType);
    if (!attributeUsageAttribute->get_Inherited()) {
      return false;
    }
    Array<Type> indexParameterTypes = GetIndexParameterTypes(element);
    PropertyInfo parentDefinition = GetParentDefinition(element, indexParameterTypes);
    while (parentDefinition != nullptr) {
      if (parentDefinition->IsDefined(attributeType, false)) {
        return true;
      }
      parentDefinition = GetParentDefinition(parentDefinition, indexParameterTypes);
    }
  }
  return false;
}

PropertyInfo Attribute___::GetParentDefinition(PropertyInfo property, Array<Type> propertyParameters) {
  auto default = property->GetGetMethod(true);
  if (default != nullptr) default = property->GetSetMethod(true);

  MethodInfo methodInfo = default;
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(methodInfo);
  if (runtimeMethodInfo != nullptr) {
    runtimeMethodInfo = runtimeMethodInfo->GetParentDefinition();
    if (runtimeMethodInfo != nullptr) {
      return runtimeMethodInfo->get_DeclaringType()->GetProperty(property->get_Name(), BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic, nullptr, property->get_PropertyType(), propertyParameters, nullptr);
    }
  }
  return nullptr;
}

Array<Attribute> Attribute___::InternalGetCustomAttributes(EventInfo element, Type type, Boolean inherit) {
  Array<Attribute> array = (Array<Attribute>)element->GetCustomAttributes(type, inherit);
  if (inherit) {
    Dictionary<Type, AttributeUsageAttribute> types = rt::newobj<Dictionary<Type, AttributeUsageAttribute>>(11);
    List<Attribute> list = rt::newobj<List<Attribute>>();
    CopyToArrayList(list, array, types);
    EventInfo parentDefinition = GetParentDefinition(element);
    while (parentDefinition != nullptr) {
      array = GetCustomAttributes(parentDefinition, type, false);
      AddAttributesToList(list, array, types);
      parentDefinition = GetParentDefinition(parentDefinition);
    }
    Array<Attribute> array2 = CreateAttributeArrayHelper(type, list->get_Count());
    list->CopyTo(array2, 0);
    return array2;
  }
  return array;
}

EventInfo Attribute___::GetParentDefinition(EventInfo ev) {
  MethodInfo addMethod = ev->GetAddMethod(true);
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(addMethod);
  if (runtimeMethodInfo != nullptr) {
    runtimeMethodInfo = runtimeMethodInfo->GetParentDefinition();
    if (runtimeMethodInfo != nullptr) {
      return runtimeMethodInfo->get_DeclaringType()->GetEvent(ev->get_Name());
    }
  }
  return nullptr;
}

Boolean Attribute___::InternalIsDefined(EventInfo element, Type attributeType, Boolean inherit) {
  if (element->IsDefined(attributeType, inherit)) {
    return true;
  }
  if (inherit) {
    AttributeUsageAttribute attributeUsageAttribute = InternalGetAttributeUsage(attributeType);
    if (!attributeUsageAttribute->get_Inherited()) {
      return false;
    }
    EventInfo parentDefinition = GetParentDefinition(element);
    while (parentDefinition != nullptr) {
      if (parentDefinition->IsDefined(attributeType, false)) {
        return true;
      }
      parentDefinition = GetParentDefinition(parentDefinition);
    }
  }
  return false;
}

ParameterInfo Attribute___::GetParentDefinition(ParameterInfo param) {
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(param->get_Member());
  if (runtimeMethodInfo != nullptr) {
    runtimeMethodInfo = runtimeMethodInfo->GetParentDefinition();
    if (runtimeMethodInfo != nullptr) {
      Int32 position = param->get_Position();
      if (position == -1) {
        return runtimeMethodInfo->get_ReturnParameter();
      }
      Array<ParameterInfo> parameters = runtimeMethodInfo->GetParameters();
      return parameters[position];
    }
  }
  return nullptr;
}

Array<Attribute> Attribute___::InternalParamGetCustomAttributes(ParameterInfo param, Type type, Boolean inherit) {
  List<Type> list = rt::newobj<List<Type>>();
  if ((Object)type == nullptr) {
    type = rt::typeof<Attribute>();
  }
  Array<Object> customAttributes = param->GetCustomAttributes(type, false);
  for (Int32 i = 0; i < customAttributes->get_Length(); i++) {
    Type type2 = customAttributes[i]->GetType();
    AttributeUsageAttribute attributeUsageAttribute = InternalGetAttributeUsage(type2);
    if (!attributeUsageAttribute->get_AllowMultiple()) {
      list->Add(type2);
    }
  }
  Array<Attribute> array = (customAttributes->get_Length() != 0) ? ((Array<Attribute>)customAttributes) : CreateAttributeArrayHelper(type, 0);
  if ((Object)param->get_Member()->get_DeclaringType() == nullptr) {
    return array;
  }
  if (!inherit) {
    return array;
  }
  for (ParameterInfo parentDefinition = GetParentDefinition(param); parentDefinition != nullptr; parentDefinition = GetParentDefinition(parentDefinition)) {
    customAttributes = parentDefinition->GetCustomAttributes(type, false);
    Int32 num = 0;
    for (Int32 j = 0; j < customAttributes->get_Length(); j++) {
      Type type3 = customAttributes[j]->GetType();
      AttributeUsageAttribute attributeUsageAttribute2 = InternalGetAttributeUsage(type3);
      if (attributeUsageAttribute2->get_Inherited() && !list->Contains(type3)) {
        if (!attributeUsageAttribute2->get_AllowMultiple()) {
          list->Add(type3);
        }
        num++;
      } else {
        customAttributes[j] = nullptr;
      }
    }
    Array<Attribute> array2 = CreateAttributeArrayHelper(type, num);
    num = 0;
    for (Int32 k = 0; k < customAttributes->get_Length(); k++) {
      if (customAttributes[k] != nullptr) {
        array2[num] = (Attribute)customAttributes[k];
        num++;
      }
    }
    Array<Attribute> array3 = array;
    array = CreateAttributeArrayHelper(type, array3->get_Length() + num);
    Array<>::in::Copy(array3, array, array3->get_Length());
    Int32 num2 = array3->get_Length();
    for (Int32 l = 0; l < array2->get_Length(); l++) {
      array[num2 + l] = array2[l];
    }
  }
  return array;
}

Boolean Attribute___::InternalParamIsDefined(ParameterInfo param, Type type, Boolean inherit) {
  if (param->IsDefined(type, false)) {
    return true;
  }
  if ((Object)param->get_Member()->get_DeclaringType() == nullptr || !inherit) {
    return false;
  }
  for (ParameterInfo parentDefinition = GetParentDefinition(param); parentDefinition != nullptr; parentDefinition = GetParentDefinition(parentDefinition)) {
    Array<Object> customAttributes = parentDefinition->GetCustomAttributes(type, false);
    for (Int32 i = 0; i < customAttributes->get_Length(); i++) {
      Type type2 = customAttributes[i]->GetType();
      AttributeUsageAttribute attributeUsageAttribute = InternalGetAttributeUsage(type2);
      if (rt::is<Attribute>(customAttributes[i]) && attributeUsageAttribute->get_Inherited()) {
        return true;
      }
    }
  }
  return false;
}

void Attribute___::CopyToArrayList(List<Attribute> attributeList, Array<Attribute> attributes, Dictionary<Type, AttributeUsageAttribute> types) {
  for (Int32 i = 0; i < attributes->get_Length(); i++) {
    attributeList->Add(attributes[i]);
    Type type = attributes[i]->GetType();
    if (!types->ContainsKey(type)) {
      types[type] = InternalGetAttributeUsage(type);
    }
  }
}

Array<Type> Attribute___::GetIndexParameterTypes(PropertyInfo element) {
  Array<ParameterInfo> indexParameters = element->GetIndexParameters();
  if (indexParameters->get_Length() != 0) {
    Array<Type> array = rt::newarr<Array<Type>>(indexParameters->get_Length());
    for (Int32 i = 0; i < indexParameters->get_Length(); i++) {
      array[i] = indexParameters[i]->get_ParameterType();
    }
    return array;
  }
  return Array<>::in::Empty<Type>();
}

void Attribute___::AddAttributesToList(List<Attribute> attributeList, Array<Attribute> attributes, Dictionary<Type, AttributeUsageAttribute> types) {
  for (Int32 i = 0; i < attributes->get_Length(); i++) {
    Type type = attributes[i]->GetType();
    AttributeUsageAttribute value;
    types->TryGetValue(type, value);
    if (value == nullptr) {
      value = (types[type] = InternalGetAttributeUsage(type));
      if (value->get_Inherited()) {
        attributeList->Add(attributes[i]);
      }
    } else if (value->get_Inherited() && value->get_AllowMultiple()) {
      attributeList->Add(attributes[i]);
    }

  }
}

AttributeUsageAttribute Attribute___::InternalGetAttributeUsage(Type type) {
  Array<Object> customAttributes = type->GetCustomAttributes(rt::typeof<AttributeUsageAttribute>(), false);
  if (customAttributes->get_Length() == 1) {
    return (AttributeUsageAttribute)customAttributes[0];
  }
  if (customAttributes->get_Length() == 0) {
    return AttributeUsageAttribute::in::Default;
  }
  rt::throw_exception<FormatException>(SR::Format(SR::get_Format_AttributeUsage(), type));
}

Array<Attribute> Attribute___::CreateAttributeArrayHelper(Type elementType, Int32 elementCount) {
  return (Array<Attribute>)Array<>::in::CreateInstance(elementType, elementCount);
}

Array<Attribute> Attribute___::GetCustomAttributes(MemberInfo element, Type type) {
  return GetCustomAttributes(element, type, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(MemberInfo element, Type type, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (type == nullptr) {
    rt::throw_exception<ArgumentNullException>("type");
  }
  if (!type->IsSubclassOf(rt::typeof<Attribute>()) && type != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  switch (element->get_MemberType()) {
    case MemberTypes::Property:
      return InternalGetCustomAttributes((PropertyInfo)element, type, inherit);
    case MemberTypes::Event:
      return InternalGetCustomAttributes((EventInfo)element, type, inherit);
    default:
      return rt::as<Array<Attribute>>(element->GetCustomAttributes(type, inherit));
  }
}

Array<Attribute> Attribute___::GetCustomAttributes(MemberInfo element) {
  return GetCustomAttributes(element, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(MemberInfo element, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  switch (element->get_MemberType()) {
    case MemberTypes::Property:
      return InternalGetCustomAttributes((PropertyInfo)element, rt::typeof<Attribute>(), inherit);
    case MemberTypes::Event:
      return InternalGetCustomAttributes((EventInfo)element, rt::typeof<Attribute>(), inherit);
    default:
      return rt::as<Array<Attribute>>(element->GetCustomAttributes(rt::typeof<Attribute>(), inherit));
  }
}

Boolean Attribute___::IsDefined(MemberInfo element, Type attributeType) {
  return IsDefined(element, attributeType, true);
}

Boolean Attribute___::IsDefined(MemberInfo element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  switch (element->get_MemberType()) {
    case MemberTypes::Property:
      return InternalIsDefined((PropertyInfo)element, attributeType, inherit);
    case MemberTypes::Event:
      return InternalIsDefined((EventInfo)element, attributeType, inherit);
    default:
      return element->IsDefined(attributeType, inherit);
  }
}

Attribute Attribute___::GetCustomAttribute(MemberInfo element, Type attributeType) {
  return GetCustomAttribute(element, attributeType, true);
}

Attribute Attribute___::GetCustomAttribute(MemberInfo element, Type attributeType, Boolean inherit) {
  Array<Attribute> customAttributes = GetCustomAttributes(element, attributeType, inherit);
  if (customAttributes == nullptr || customAttributes->get_Length() == 0) {
    return nullptr;
  }
  if (customAttributes->get_Length() == 1) {
    return customAttributes[0];
  }
  rt::throw_exception<AmbiguousMatchException>(SR::get_RFLCT_AmbigCust());
}

Array<Attribute> Attribute___::GetCustomAttributes(ParameterInfo element) {
  return GetCustomAttributes(element, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(ParameterInfo element, Type attributeType) {
  return GetCustomAttributes(element, attributeType, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(ParameterInfo element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  if (element->get_Member() == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidParameterInfo(), "element");
  }
  MemberInfo member = element->get_Member();
  if (member->get_MemberType() == MemberTypes::Method && inherit) {
    return InternalParamGetCustomAttributes(element, attributeType, inherit);
  }
  return rt::as<Array<Attribute>>(element->GetCustomAttributes(attributeType, inherit));
}

Array<Attribute> Attribute___::GetCustomAttributes(ParameterInfo element, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (element->get_Member() == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidParameterInfo(), "element");
  }
  MemberInfo member = element->get_Member();
  if (member->get_MemberType() == MemberTypes::Method && inherit) {
    return InternalParamGetCustomAttributes(element, nullptr, inherit);
  }
  return rt::as<Array<Attribute>>(element->GetCustomAttributes(rt::typeof<Attribute>(), inherit));
}

Boolean Attribute___::IsDefined(ParameterInfo element, Type attributeType) {
  return IsDefined(element, attributeType, true);
}

Boolean Attribute___::IsDefined(ParameterInfo element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  MemberInfo member = element->get_Member();
  switch (member->get_MemberType()) {
    case MemberTypes::Method:
      return InternalParamIsDefined(element, attributeType, inherit);
    case MemberTypes::Constructor:
      return element->IsDefined(attributeType, false);
    case MemberTypes::Property:
      return element->IsDefined(attributeType, false);
    default:
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidParamInfo());
  }
}

Attribute Attribute___::GetCustomAttribute(ParameterInfo element, Type attributeType) {
  return GetCustomAttribute(element, attributeType, true);
}

Attribute Attribute___::GetCustomAttribute(ParameterInfo element, Type attributeType, Boolean inherit) {
  Array<Attribute> customAttributes = GetCustomAttributes(element, attributeType, inherit);
  if (customAttributes == nullptr || customAttributes->get_Length() == 0) {
    return nullptr;
  }
  if (customAttributes->get_Length() == 0) {
    return nullptr;
  }
  if (customAttributes->get_Length() == 1) {
    return customAttributes[0];
  }
  rt::throw_exception<AmbiguousMatchException>(SR::get_RFLCT_AmbigCust());
}

Array<Attribute> Attribute___::GetCustomAttributes(Module element, Type attributeType) {
  return GetCustomAttributes(element, attributeType, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(Module element) {
  return GetCustomAttributes(element, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(Module element, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  return (Array<Attribute>)element->GetCustomAttributes(rt::typeof<Attribute>(), inherit);
}

Array<Attribute> Attribute___::GetCustomAttributes(Module element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  return (Array<Attribute>)element->GetCustomAttributes(attributeType, inherit);
}

Boolean Attribute___::IsDefined(Module element, Type attributeType) {
  return IsDefined(element, attributeType, false);
}

Boolean Attribute___::IsDefined(Module element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  return element->IsDefined(attributeType, false);
}

Attribute Attribute___::GetCustomAttribute(Module element, Type attributeType) {
  return GetCustomAttribute(element, attributeType, true);
}

Attribute Attribute___::GetCustomAttribute(Module element, Type attributeType, Boolean inherit) {
  Array<Attribute> customAttributes = GetCustomAttributes(element, attributeType, inherit);
  if (customAttributes == nullptr || customAttributes->get_Length() == 0) {
    return nullptr;
  }
  if (customAttributes->get_Length() == 1) {
    return customAttributes[0];
  }
  rt::throw_exception<AmbiguousMatchException>(SR::get_RFLCT_AmbigCust());
}

Array<Attribute> Attribute___::GetCustomAttributes(Assembly element, Type attributeType) {
  return GetCustomAttributes(element, attributeType, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(Assembly element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  return (Array<Attribute>)element->GetCustomAttributes(attributeType, inherit);
}

Array<Attribute> Attribute___::GetCustomAttributes(Assembly element) {
  return GetCustomAttributes(element, true);
}

Array<Attribute> Attribute___::GetCustomAttributes(Assembly element, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  return (Array<Attribute>)element->GetCustomAttributes(rt::typeof<Attribute>(), inherit);
}

Boolean Attribute___::IsDefined(Assembly element, Type attributeType) {
  return IsDefined(element, attributeType, true);
}

Boolean Attribute___::IsDefined(Assembly element, Type attributeType, Boolean inherit) {
  if (element == nullptr) {
    rt::throw_exception<ArgumentNullException>("element");
  }
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (!attributeType->IsSubclassOf(rt::typeof<Attribute>()) && attributeType != rt::typeof<Attribute>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustHaveAttributeBaseClass());
  }
  return element->IsDefined(attributeType, false);
}

Attribute Attribute___::GetCustomAttribute(Assembly element, Type attributeType) {
  return GetCustomAttribute(element, attributeType, true);
}

Attribute Attribute___::GetCustomAttribute(Assembly element, Type attributeType, Boolean inherit) {
  Array<Attribute> customAttributes = GetCustomAttributes(element, attributeType, inherit);
  if (customAttributes == nullptr || customAttributes->get_Length() == 0) {
    return nullptr;
  }
  if (customAttributes->get_Length() == 1) {
    return customAttributes[0];
  }
  rt::throw_exception<AmbiguousMatchException>(SR::get_RFLCT_AmbigCust());
}

void Attribute___::ctor() {
}

Boolean Attribute___::Equals(Object obj) {
  if (obj == nullptr) {
    return false;
  }
  if (GetType() != obj->GetType()) {
    return false;
  }
  Type type = GetType();
  while (type != rt::typeof<Attribute>()) {
    Array<FieldInfo> fields = type->GetFields(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
    for (Int32 i = 0; i < fields->get_Length(); i++) {
      Object value = fields[i]->GetValue((Attribute)this);
      Object value2 = fields[i]->GetValue(obj);
      if (!AreFieldValuesEqual(value, value2)) {
        return false;
      }
    }
    type = type->get_BaseType();
  }
  return true;
}

Int32 Attribute___::GetHashCode() {
  Type type = GetType();
  while (type != rt::typeof<Attribute>()) {
    Array<FieldInfo> fields = type->GetFields(BindingFlags::DeclaredOnly | BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
    Object obj = nullptr;
    for (Int32 i = 0; i < fields->get_Length(); i++) {
      Object value = fields[i]->GetValue((Attribute)this);
      if (value != nullptr && !value->GetType()->get_IsArray()) {
        obj = value;
      }
      if (obj != nullptr) {
        break;
      }
    }
    if (obj != nullptr) {
      return obj->GetHashCode();
    }
    type = type->get_BaseType();
  }
  return type->GetHashCode();
}

Boolean Attribute___::AreFieldValuesEqual(Object thisValue, Object thatValue) {
  if (thisValue == nullptr && thatValue == nullptr) {
    return true;
  }
  if (thisValue == nullptr || thatValue == nullptr) {
    return false;
  }
  Type type = thisValue->GetType();
  if (type->get_IsArray()) {
    if (!type->Equals(thatValue->GetType())) {
      return false;
    }
    Array<> array = (Array<>)thisValue;
    Array<> array2 = (Array<>)thatValue;
    if (array->get_Length() != array2->get_Length()) {
      return false;
    }
    for (Int32 i = 0; i < array->get_Length(); i++) {
      if (!AreFieldValuesEqual(array->GetValue(i), array2->GetValue(i))) {
        return false;
      }
    }
  } else if (!thisValue->Equals(thatValue)) {
    return false;
  }

  return true;
}

Boolean Attribute___::Match(Object obj) {
  return Equals(obj);
}

Boolean Attribute___::IsDefaultAttribute() {
  return false;
}

} // namespace System::Private::CoreLib::System::AttributeNamespace
