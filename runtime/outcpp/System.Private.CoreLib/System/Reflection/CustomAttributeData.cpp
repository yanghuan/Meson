#include "CustomAttributeData-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeCtorParameter-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeData-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeNamedParameter-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeRecord-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/PropertyInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/TypeForwardedToAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DllImportAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/FieldOffsetAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MarshalAsAttribute-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeDataNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;

Type CustomAttributeData___::get_AttributeType() {
  return get_Constructor()->get_DeclaringType();
}

ConstructorInfo CustomAttributeData___::get_Constructor() {
  return m_ctor;
}

IList<CustomAttributeTypedArgument> CustomAttributeData___::get_ConstructorArguments() {
  if (m_typedCtorArgs == nullptr) {
    Array<CustomAttributeTypedArgument> array = rt::newarr<Array<CustomAttributeTypedArgument>>(m_ctorParams->get_Length());
    for (Int32 i = 0; i < array->get_Length(); i++) {
      CustomAttributeEncodedArgument customAttributeEncodedArgument = m_ctorParams[i].get_CustomAttributeEncodedArgument();
      array[i] = CustomAttributeTypedArgument(m_scope, customAttributeEncodedArgument);
    }
    m_typedCtorArgs = Array<>::in::AsReadOnly(array);
  }
  return m_typedCtorArgs;
}

IList<CustomAttributeNamedArgument> CustomAttributeData___::get_NamedArguments() {
  if (m_namedArgs == nullptr) {
    if (m_namedParams == nullptr) {
      return nullptr;
    }
    Int32 num = 0;
    for (Int32 i = 0; i < m_namedParams->get_Length(); i++) {
      if (m_namedParams[i].get_EncodedArgument().get_CustomAttributeType().get_EncodedType() != 0) {
        num++;
      }
    }
    Array<CustomAttributeNamedArgument> array = rt::newarr<Array<CustomAttributeNamedArgument>>(num);
    Int32 j = 0;
    Int32 num2 = 0;
    for (; j < m_namedParams->get_Length(); j++) {
      if (m_namedParams[j].get_EncodedArgument().get_CustomAttributeType().get_EncodedType() != 0) {
        array[num2++] = CustomAttributeNamedArgument(m_members[j], CustomAttributeTypedArgument(m_scope, m_namedParams[j].get_EncodedArgument()));
      }
    }
    m_namedArgs = Array<>::in::AsReadOnly(array);
  }
  return m_namedArgs;
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributes(MemberInfo target) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  return target->GetCustomAttributesData();
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributes(Module target) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  return target->GetCustomAttributesData();
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributes(Assembly target) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  return target->GetCustomAttributesData();
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributes(ParameterInfo target) {
  if (target == nullptr) {
    rt::throw_exception<ArgumentNullException>("target");
  }
  return target->GetCustomAttributesData();
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeType target) {
  IList<CustomAttributeData> customAttributes = GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeFieldInfo target) {
  IList<CustomAttributeData> customAttributes = GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeMethodInfo target) {
  IList<CustomAttributeData> customAttributes = GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeConstructorInfo target) {
  return GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeEventInfo target) {
  return GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimePropertyInfo target) {
  return GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeModule target) {
  if (target->IsResource()) {
    return rt::newobj<List<CustomAttributeData>>();
  }
  return GetCustomAttributes(target, target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeAssembly target) {
  return GetCustomAttributes((RuntimeModule)target->get_ManifestModule(), RuntimeAssembly::in::GetToken(target->GetNativeHandle()));
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributesInternal(RuntimeParameterInfo target) {
  IList<CustomAttributeData> customAttributes = GetCustomAttributes(target->GetRuntimeModule(), target->get_MetadataToken());
}

IList<CustomAttributeData> CustomAttributeData___::GetCombinedList(IList<CustomAttributeData> customAttributes, RuntimeType::in::ListBuilder<Attribute>& pseudoAttributes) {
  if (pseudoAttributes.get_Count() == 0) {
    return customAttributes;
  }
  Array<CustomAttributeData> array = rt::newarr<Array<CustomAttributeData>>(customAttributes->get_Count() + pseudoAttributes.get_Count());
  customAttributes->CopyTo(array, pseudoAttributes.get_Count());
  for (Int32 i = 0; i < pseudoAttributes.get_Count(); i++) {
    array[i] = rt::newobj<CustomAttributeData>(pseudoAttributes[i]);
  }
  return Array<>::in::AsReadOnly(array);
}

CustomAttributeEncoding CustomAttributeData___::TypeToCustomAttributeEncoding(RuntimeType type) {
}

CustomAttributeType CustomAttributeData___::InitCustomAttributeType(RuntimeType parameterType) {
  CustomAttributeEncoding customAttributeEncoding = TypeToCustomAttributeEncoding(parameterType);
  CustomAttributeEncoding customAttributeEncoding2 = CustomAttributeEncoding::Undefined;
  CustomAttributeEncoding encodedEnumType = CustomAttributeEncoding::Undefined;
  String enumName = nullptr;
  if (customAttributeEncoding == CustomAttributeEncoding::Array) {
    parameterType = (RuntimeType)parameterType->GetElementType();
    customAttributeEncoding2 = TypeToCustomAttributeEncoding(parameterType);
  }
  if (customAttributeEncoding == CustomAttributeEncoding::Enum || customAttributeEncoding2 == CustomAttributeEncoding::Enum) {
    encodedEnumType = TypeToCustomAttributeEncoding((RuntimeType)Enum::in::GetUnderlyingType(parameterType));
    enumName = parameterType->get_AssemblyQualifiedName();
  }
  return CustomAttributeType(customAttributeEncoding, customAttributeEncoding2, encodedEnumType, enumName);
}

IList<CustomAttributeData> CustomAttributeData___::GetCustomAttributes(RuntimeModule module, Int32 tkTarget) {
  Array<CustomAttributeRecord> customAttributeRecords = GetCustomAttributeRecords(module, tkTarget);
  Array<CustomAttributeData> array = rt::newarr<Array<CustomAttributeData>>(customAttributeRecords->get_Length());
  for (Int32 i = 0; i < customAttributeRecords->get_Length(); i++) {
    array[i] = rt::newobj<CustomAttributeData>(module, customAttributeRecords[i].tkCtor, customAttributeRecords[i].blob);
  }
  return Array<>::in::AsReadOnly(array);
}

Array<CustomAttributeRecord> CustomAttributeData___::GetCustomAttributeRecords(RuntimeModule module, Int32 targetToken) {
  MetadataImport metadataImport = module->get_MetadataImport();
}

CustomAttributeTypedArgument CustomAttributeData___::Filter(IList<CustomAttributeData> attrs, Type caType, Int32 parameter) {
  for (Int32 i = 0; i < attrs->get_Count(); i++) {
    if (attrs[i]->get_Constructor()->get_DeclaringType() == caType) {
      return attrs[i]->get_ConstructorArguments()[parameter];
    }
  }
  return CustomAttributeTypedArgument();
}

void CustomAttributeData___::ctor() {
}

void CustomAttributeData___::ctor(RuntimeModule scope, MetadataToken caCtorToken, ConstArray& blob) {
  m_scope = scope;
  m_ctor = (RuntimeConstructorInfo)RuntimeType::in::GetMethodBase(scope, caCtorToken);
  Array<ParameterInfo> parametersNoCopy = m_ctor->GetParametersNoCopy();
  m_ctorParams = rt::newarr<Array<CustomAttributeCtorParameter>>(parametersNoCopy->get_Length());
  for (Int32 i = 0; i < parametersNoCopy->get_Length(); i++) {
    m_ctorParams[i] = CustomAttributeCtorParameter(InitCustomAttributeType((RuntimeType)parametersNoCopy[i]->get_ParameterType()));
  }
  Array<FieldInfo> fields = m_ctor->get_DeclaringType()->GetFields(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
  Array<PropertyInfo> properties = m_ctor->get_DeclaringType()->GetProperties(BindingFlags::Instance | BindingFlags::Public | BindingFlags::NonPublic);
  m_namedParams = rt::newarr<Array<CustomAttributeNamedParameter>>(properties->get_Length() + fields->get_Length());
  for (Int32 j = 0; j < fields->get_Length(); j++) {
    m_namedParams[j] = CustomAttributeNamedParameter(fields[j]->get_Name(), CustomAttributeEncoding::Field, InitCustomAttributeType((RuntimeType)fields[j]->get_FieldType()));
  }
  for (Int32 k = 0; k < properties->get_Length(); k++) {
    m_namedParams[k + fields->get_Length()] = CustomAttributeNamedParameter(properties[k]->get_Name(), CustomAttributeEncoding::Property, InitCustomAttributeType((RuntimeType)properties[k]->get_PropertyType()));
  }
  m_members = rt::newarr<Array<MemberInfo>>(fields->get_Length() + properties->get_Length());
  fields->CopyTo(m_members, 0);
  properties->CopyTo(m_members, fields->get_Length());
  CustomAttributeEncodedArgument::ParseAttributeArguments(blob, m_ctorParams, m_namedParams, m_scope);
}

void CustomAttributeData___::ctor(Attribute attribute) {
  DllImportAttribute dllImportAttribute = rt::as<DllImportAttribute>(attribute);
  if (dllImportAttribute != nullptr) {
    Init(dllImportAttribute);
    return;
  }
  FieldOffsetAttribute fieldOffsetAttribute = rt::as<FieldOffsetAttribute>(attribute);
  if (fieldOffsetAttribute != nullptr) {
    Init(fieldOffsetAttribute);
    return;
  }
  MarshalAsAttribute marshalAsAttribute = rt::as<MarshalAsAttribute>(attribute);
  if (marshalAsAttribute != nullptr) {
    Init(marshalAsAttribute);
    return;
  }
  TypeForwardedToAttribute typeForwardedToAttribute = rt::as<TypeForwardedToAttribute>(attribute);
  if (typeForwardedToAttribute != nullptr) {
    Init(typeForwardedToAttribute);
  } else {
    Init(attribute);
  }
}

void CustomAttributeData___::Init(DllImportAttribute dllImport) {
}

void CustomAttributeData___::Init(FieldOffsetAttribute fieldOffset) {
}

void CustomAttributeData___::Init(MarshalAsAttribute marshalAs) {
}

void CustomAttributeData___::Init(TypeForwardedToAttribute forwardedTo) {
}

void CustomAttributeData___::Init(Object pca) {
  m_ctor = pca->GetType()->GetConstructors(BindingFlags::Instance | BindingFlags::Public)[0];
  m_typedCtorArgs = Array<>::in::AsReadOnly(Array<>::in::Empty<CustomAttributeTypedArgument>());
  m_namedArgs = Array<>::in::AsReadOnly(Array<>::in::Empty<CustomAttributeNamedArgument>());
}

String CustomAttributeData___::ToString() {
  String text = "";
  for (Int32 i = 0; i < get_ConstructorArguments()->get_Count(); i++) {
    text += String::in::Format((i == 0) ? "{0}" : ", {0}", get_ConstructorArguments()[i]);
  }
  String text2 = "";
  for (Int32 j = 0; j < get_NamedArguments()->get_Count(); j++) {
    text2 += String::in::Format((j == 0 && text->get_Length() == 0) ? "{0}" : ", {0}", get_NamedArguments()[j]);
  }
}

Int32 CustomAttributeData___::GetHashCode() {
}

Boolean CustomAttributeData___::Equals(Object obj) {
  return obj == (CustomAttributeData)this;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeDataNamespace
