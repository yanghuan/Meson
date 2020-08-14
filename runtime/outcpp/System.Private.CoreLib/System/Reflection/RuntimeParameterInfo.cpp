#include "RuntimeParameterInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterAttributes.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeParameterInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeParameterInfoNamespace {
Type RuntimeParameterInfo___::get_ParameterType() {
  if (ClassImpl == nullptr) {
    RuntimeType runtimeType = (RuntimeType)(ClassImpl = ((PositionImpl != -1) ? m_signature->get_Arguments()[PositionImpl] : m_signature->get_ReturnType()));
  }
  return ClassImpl;
}

String RuntimeParameterInfo___::get_Name() {
  if (!m_nameIsCached) {
    if (!MetadataToken::IsNullToken(m_tkParamDef)) {
      String text = NameImpl = m_scope.GetName(m_tkParamDef).ToString();
    }
    m_nameIsCached = true;
  }
  return NameImpl;
}

Boolean RuntimeParameterInfo___::get_HasDefaultValue() {
  if (m_noMetadata || m_noDefaultValue) {
    return false;
  }
  Object defaultValueInternal = GetDefaultValueInternal(false);
  return defaultValueInternal != DBNull::in::Value;
}

Object RuntimeParameterInfo___::get_DefaultValue() {
  return GetDefaultValue(false);
}

Object RuntimeParameterInfo___::get_RawDefaultValue() {
  return GetDefaultValue(true);
}

Int32 RuntimeParameterInfo___::get_MetadataToken() {
  return m_tkParamDef;
}

Array<ParameterInfo> RuntimeParameterInfo___::GetParameters(IRuntimeMethodInfo method, MemberInfo member, Signature sig) {
  ParameterInfo returnParameter;
  return GetParameters(method, member, sig, returnParameter, false);
}

ParameterInfo RuntimeParameterInfo___::GetReturnParameter(IRuntimeMethodInfo method, MemberInfo member, Signature sig) {
}

Array<ParameterInfo> RuntimeParameterInfo___::GetParameters(IRuntimeMethodInfo methodHandle, MemberInfo member, Signature sig, ParameterInfo& returnParameter, Boolean fetchReturnParameter) {
  returnParameter = nullptr;
  Int32 num = sig->get_Arguments()->get_Length();
  Array<ParameterInfo> array = fetchReturnParameter ? nullptr : rt::newarr<Array<ParameterInfo>>(num);
  Int32 methodDef = RuntimeMethodHandle::GetMethodDef(methodHandle);
  Int32 num2 = 0;
  if (!MetadataToken::IsNullToken(methodDef)) {
    MetadataImport metadataImport = RuntimeTypeHandle::GetMetadataImport(RuntimeMethodHandle::GetDeclaringType(methodHandle));
  }
  if (fetchReturnParameter) {
    if (returnParameter == nullptr) {
      returnParameter = rt::newobj<RuntimeParameterInfo>(sig, MetadataImport::EmptyImport, 0, -1, ParameterAttributes::None, member);
    }
  } else if (num2 < array->get_Length() + 1) {
    for (Int32 j = 0; j < array->get_Length(); j++) {
      if (array[j] == nullptr) {
        array[j] = rt::newobj<RuntimeParameterInfo>(sig, MetadataImport::EmptyImport, 0, j, ParameterAttributes::None, member);
      }
    }
  }

  return array;
}

void RuntimeParameterInfo___::SetName(String name) {
  NameImpl = name;
}

void RuntimeParameterInfo___::SetAttributes(ParameterAttributes attributes) {
  AttrsImpl = attributes;
}

void RuntimeParameterInfo___::ctor(RuntimeParameterInfo accessor, RuntimePropertyInfo property) {
  m_signature = property->get_Signature();
}

void RuntimeParameterInfo___::ctor(RuntimeParameterInfo accessor, MemberInfo member) {
  MemberImpl = member;
  m_originalMember = (rt::as<MethodBase>(accessor->MemberImpl));
  NameImpl = accessor->get_Name();
  m_nameIsCached = true;
  ClassImpl = accessor->get_ParameterType();
  PositionImpl = accessor->get_Position();
  AttrsImpl = accessor->get_Attributes();
  m_tkParamDef = (MetadataToken::IsNullToken(accessor->get_MetadataToken()) ? 134217728 : accessor->get_MetadataToken());
  m_scope = accessor->m_scope;
}

void RuntimeParameterInfo___::ctor(Signature signature, MetadataImport scope, Int32 tkParamDef, Int32 position, ParameterAttributes attributes, MemberInfo member) {
  PositionImpl = position;
  MemberImpl = member;
  m_signature = signature;
  m_tkParamDef = (MetadataToken::IsNullToken(tkParamDef) ? 134217728 : tkParamDef);
  m_scope = scope;
  AttrsImpl = attributes;
  ClassImpl = nullptr;
  NameImpl = nullptr;
}

void RuntimeParameterInfo___::ctor(MethodInfo owner, String name, Type parameterType, Int32 position) {
  MemberImpl = owner;
  NameImpl = name;
  m_nameIsCached = true;
  m_noMetadata = true;
  ClassImpl = parameterType;
  PositionImpl = position;
  AttrsImpl = ParameterAttributes::None;
  m_tkParamDef = 134217728;
  m_scope = MetadataImport::EmptyImport;
}

Object RuntimeParameterInfo___::GetDefaultValue(Boolean raw) {
  if (m_noMetadata) {
    return nullptr;
  }
  Object obj = GetDefaultValueInternal(raw);
}

Object RuntimeParameterInfo___::GetDefaultValueInternal(Boolean raw) {
  if (m_noDefaultValue) {
    return DBNull::in::Value;
  }
  Object obj = nullptr;
}

Decimal RuntimeParameterInfo___::GetRawDecimalConstant(CustomAttributeData attr) {
}

DateTime RuntimeParameterInfo___::GetRawDateTimeConstant(CustomAttributeData attr) {
}

Object RuntimeParameterInfo___::GetRawConstant(CustomAttributeData attr) {
}

RuntimeModule RuntimeParameterInfo___::GetRuntimeModule() {
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(get_Member());
  RuntimeConstructorInfo runtimeConstructorInfo = rt::as<RuntimeConstructorInfo>(get_Member());
  RuntimePropertyInfo runtimePropertyInfo = rt::as<RuntimePropertyInfo>(get_Member());
  if (runtimeMethodInfo != nullptr) {
    return runtimeMethodInfo->GetRuntimeModule();
  }
  if (runtimeConstructorInfo != nullptr) {
    return runtimeConstructorInfo->GetRuntimeModule();
  }
  if (runtimePropertyInfo != nullptr) {
    return runtimePropertyInfo->GetRuntimeModule();
  }
  return nullptr;
}

Array<Type> RuntimeParameterInfo___::GetRequiredCustomModifiers() {
  if (m_signature != nullptr) {
    return m_signature->GetCustomModifiers(PositionImpl + 1, true);
  }
  return Type::in::EmptyTypes;
}

Array<Type> RuntimeParameterInfo___::GetOptionalCustomModifiers() {
  if (m_signature != nullptr) {
    return m_signature->GetCustomModifiers(PositionImpl + 1, false);
  }
  return Type::in::EmptyTypes;
}

Array<Object> RuntimeParameterInfo___::GetCustomAttributes(Boolean inherit) {
  if (MetadataToken::IsNullToken(m_tkParamDef)) {
    return Array<>::in::Empty<Object>();
  }
}

Array<Object> RuntimeParameterInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (MetadataToken::IsNullToken(m_tkParamDef)) {
    return Array<>::in::Empty<Object>();
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeParameterInfo)this, runtimeType);
}

Boolean RuntimeParameterInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  if (MetadataToken::IsNullToken(m_tkParamDef)) {
    return false;
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeParameterInfo)this, runtimeType);
}

IList<CustomAttributeData> RuntimeParameterInfo___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeParameterInfo)this);
}

void RuntimeParameterInfo___::cctor() {
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeParameterInfoNamespace
