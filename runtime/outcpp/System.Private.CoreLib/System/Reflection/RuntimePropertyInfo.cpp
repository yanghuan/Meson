#include "RuntimePropertyInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Associates-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MdConstant-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimePropertyInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimePropertyInfoNamespace {
using namespace System::Collections::Generic;
using namespace System::Text;

Signature RuntimePropertyInfo___::get_Signature() {
  if (m_signature == nullptr) {
  }
  return m_signature;
}

BindingFlags RuntimePropertyInfo___::get_BindingFlags() {
  return m_bindingFlags;
}

MemberTypes RuntimePropertyInfo___::get_MemberType() {
  return MemberTypes::Property;
}

String RuntimePropertyInfo___::get_Name() {
}

Type RuntimePropertyInfo___::get_DeclaringType() {
  return m_declaringType;
}

Type RuntimePropertyInfo___::get_ReflectedType() {
  return get_ReflectedTypeInternal();
}

RuntimeType RuntimePropertyInfo___::get_ReflectedTypeInternal() {
  return m_reflectedTypeCache->GetRuntimeType();
}

Int32 RuntimePropertyInfo___::get_MetadataToken() {
  return m_token;
}

Module RuntimePropertyInfo___::get_Module() {
  return GetRuntimeModule();
}

Boolean RuntimePropertyInfo___::get_IsCollectible() {
  return m_declaringType->get_IsCollectible();
}

Type RuntimePropertyInfo___::get_PropertyType() {
  return get_Signature()->get_ReturnType();
}

PropertyAttributes RuntimePropertyInfo___::get_Attributes() {
  return m_flags;
}

Boolean RuntimePropertyInfo___::get_CanRead() {
  return m_getterMethod != nullptr;
}

Boolean RuntimePropertyInfo___::get_CanWrite() {
  return m_setterMethod != nullptr;
}

void RuntimePropertyInfo___::ctor(Int32 tkProperty, RuntimeType declaredType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, Boolean& isPrivate) {
  MetadataImport metadataImport = declaredType->GetRuntimeModule()->get_MetadataImport();
  m_token = tkProperty;
  m_reflectedTypeCache = reflectedTypeCache;
  m_declaringType = declaredType;
}

Boolean RuntimePropertyInfo___::CacheEquals(Object o) {
  RuntimePropertyInfo runtimePropertyInfo = rt::as<RuntimePropertyInfo>(o);
  if ((Object)runtimePropertyInfo != nullptr && runtimePropertyInfo->m_token == m_token) {
    return RuntimeTypeHandle::GetModule(m_declaringType)->Equals(RuntimeTypeHandle::GetModule(runtimePropertyInfo->m_declaringType));
  }
  return false;
}

Boolean RuntimePropertyInfo___::EqualsSig(RuntimePropertyInfo target) {
  return Signature::in::CompareSig(get_Signature(), target->get_Signature());
}

String RuntimePropertyInfo___::ToString() {
  ValueStringBuilder sbParamList = ValueStringBuilder(100);
  sbParamList.Append(get_PropertyType()->FormatTypeName());
  sbParamList.Append(32);
  sbParamList.Append(get_Name());
  Array<RuntimeType> arguments = get_Signature()->get_Arguments();
  if (arguments->get_Length() != 0) {
    sbParamList.Append(" [");
    Array<Type> parameterTypes = arguments;
    MethodBase::in::AppendParameters(sbParamList, parameterTypes, get_Signature()->get_CallingConvention());
    sbParamList.Append(93);
  }
  return sbParamList.ToString();
}

Array<Object> RuntimePropertyInfo___::GetCustomAttributes(Boolean inherit) {
}

Array<Object> RuntimePropertyInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimePropertyInfo)this, runtimeType);
}

Boolean RuntimePropertyInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimePropertyInfo)this, runtimeType);
}

IList<CustomAttributeData> RuntimePropertyInfo___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimePropertyInfo)this);
}

Boolean RuntimePropertyInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return HasSameMetadataDefinitionAsCore<RuntimePropertyInfo>(other);
}

RuntimeModule RuntimePropertyInfo___::GetRuntimeModule() {
  return m_declaringType->GetRuntimeModule();
}

Array<Type> RuntimePropertyInfo___::GetRequiredCustomModifiers() {
  return get_Signature()->GetCustomModifiers(0, true);
}

Array<Type> RuntimePropertyInfo___::GetOptionalCustomModifiers() {
  return get_Signature()->GetCustomModifiers(0, false);
}

Object RuntimePropertyInfo___::GetConstantValue(Boolean raw) {
  Object value = MdConstant::GetValue(GetRuntimeModule()->get_MetadataImport(), m_token, get_PropertyType()->GetTypeHandleInternal(), raw);
  if (value == DBNull::in::Value) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_EnumLitValueNotFound());
  }
  return value;
}

Object RuntimePropertyInfo___::GetConstantValue() {
  return GetConstantValue(false);
}

Object RuntimePropertyInfo___::GetRawConstantValue() {
  return GetConstantValue(true);
}

Array<MethodInfo> RuntimePropertyInfo___::GetAccessors(Boolean nonPublic) {
  List<MethodInfo> list = rt::newobj<List<MethodInfo>>();
  if (Associates::IncludeAccessor(m_getterMethod, nonPublic)) {
    list->Add(m_getterMethod);
  }
  if (Associates::IncludeAccessor(m_setterMethod, nonPublic)) {
    list->Add(m_setterMethod);
  }
  if (m_otherMethod != nullptr) {
    for (Int32 i = 0; i < m_otherMethod->get_Length(); i++) {
      if (Associates::IncludeAccessor(m_otherMethod[i], nonPublic)) {
        list->Add(m_otherMethod[i]);
      }
    }
  }
  return list->ToArray();
}

MethodInfo RuntimePropertyInfo___::GetGetMethod(Boolean nonPublic) {
  if (!Associates::IncludeAccessor(m_getterMethod, nonPublic)) {
    return nullptr;
  }
  return m_getterMethod;
}

MethodInfo RuntimePropertyInfo___::GetSetMethod(Boolean nonPublic) {
  if (!Associates::IncludeAccessor(m_setterMethod, nonPublic)) {
    return nullptr;
  }
  return m_setterMethod;
}

Array<ParameterInfo> RuntimePropertyInfo___::GetIndexParameters() {
  Array<ParameterInfo> indexParametersNoCopy = GetIndexParametersNoCopy();
  Int32 num = indexParametersNoCopy->get_Length();
  if (num == 0) {
    return indexParametersNoCopy;
  }
  Array<ParameterInfo> array = rt::newarr<Array<ParameterInfo>>(num);
  Array<>::in::Copy(indexParametersNoCopy, array, num);
  return array;
}

Array<ParameterInfo> RuntimePropertyInfo___::GetIndexParametersNoCopy() {
  if (m_parameters == nullptr) {
    Int32 num = 0;
    Array<ParameterInfo> array = nullptr;
    MethodInfo getMethod = GetGetMethod(true);
    if (getMethod != nullptr) {
      array = getMethod->GetParametersNoCopy();
      num = array->get_Length();
    } else {
      getMethod = GetSetMethod(true);
      if (getMethod != nullptr) {
        array = getMethod->GetParametersNoCopy();
        num = array->get_Length() - 1;
      }
    }
    Array<ParameterInfo> array2 = rt::newarr<Array<ParameterInfo>>(num);
    for (Int32 i = 0; i < num; i++) {
      array2[i] = rt::newobj<RuntimeParameterInfo>((RuntimeParameterInfo)array[i], (RuntimePropertyInfo)this);
    }
    m_parameters = array2;
  }
  return m_parameters;
}

Object RuntimePropertyInfo___::GetValue(Object obj, Array<Object> index) {
}

Object RuntimePropertyInfo___::GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  MethodInfo getMethod = GetGetMethod(true);
  if (getMethod == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_GetMethNotFnd());
  }
  return getMethod->Invoke(obj, invokeAttr, binder, index, nullptr);
}

void RuntimePropertyInfo___::SetValue(Object obj, Object value, Array<Object> index) {
}

void RuntimePropertyInfo___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  MethodInfo setMethod = GetSetMethod(true);
  if (setMethod == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_SetMethNotFnd());
  }
  Array<Object> array;
  if (index == nullptr) {
    array = rt::newarr<Array<Object>>(1);
  } else {
    array = rt::newarr<Array<Object>>(index->get_Length() + 1);
    for (Int32 i = 0; i < index->get_Length(); i++) {
      array[i] = index[i];
    }
    array[index->get_Length()] = value;
  }
  setMethod->Invoke(obj, invokeAttr, binder, array, culture);
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimePropertyInfoNamespace
