#include "RuntimeParameterInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/BadImageFormatException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IList.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeData-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeNamedArgument-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeTypedArgument-dep.h>
#include <System.Private.CoreLib/System/Reflection/MdConstant-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataEnumResult-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterAttributes.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CustomConstantAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/DateTimeConstantAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/DecimalConstantAttribute-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeParameterInfoNamespace {
using namespace System::Collections::Generic;
using namespace System::Runtime::CompilerServices;

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
  ParameterInfo returnParameter;
  GetParameters(method, member, sig, returnParameter, true);
  return returnParameter;
}

Array<ParameterInfo> RuntimeParameterInfo___::GetParameters(IRuntimeMethodInfo methodHandle, MemberInfo member, Signature sig, ParameterInfo& returnParameter, Boolean fetchReturnParameter) {
  returnParameter = nullptr;
  Int32 num = sig->get_Arguments()->get_Length();
  Array<ParameterInfo> array = fetchReturnParameter ? nullptr : rt::newarr<Array<ParameterInfo>>(num);
  Int32 methodDef = RuntimeMethodHandle::GetMethodDef(methodHandle);
  Int32 num2 = 0;
  if (!MetadataToken::IsNullToken(methodDef)) {
    MetadataImport metadataImport = RuntimeTypeHandle::GetMetadataImport(RuntimeMethodHandle::GetDeclaringType(methodHandle));
    MetadataEnumResult result;
    metadataImport.EnumParams(methodDef, result);
    num2 = result.get_Length();
    if (num2 > num + 1) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ParameterSignatureMismatch());
    }
    for (Int32 i = 0; i < num2; i++) {
      Int32 num3 = result[i];
      Int32 sequence;
      ParameterAttributes attributes;
      metadataImport.GetParamDefProps(num3, sequence, attributes);
      sequence--;
      if (fetchReturnParameter && sequence == -1) {
        if (returnParameter != nullptr) {
          rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ParameterSignatureMismatch());
        }
        returnParameter = rt::newobj<RuntimeParameterInfo>(sig, metadataImport, num3, sequence, attributes, member);
      } else if (!fetchReturnParameter && sequence >= 0) {
        if (sequence >= num) {
          rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ParameterSignatureMismatch());
        }
        array[sequence] = rt::newobj<RuntimeParameterInfo>(sig, metadataImport, num3, sequence, attributes, member);
      }

    }
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
  if (obj == DBNull::in::Value && ParameterInfo::in::get_IsOptional()) {
    obj = Type::in::Missing;
  }
  return obj;
}

Object RuntimeParameterInfo___::GetDefaultValueInternal(Boolean raw) {
  if (m_noDefaultValue) {
    return DBNull::in::Value;
  }
  Object obj = nullptr;
  if (get_ParameterType() == typeof<DateTime>()) {
    if (raw) {
      CustomAttributeTypedArgument customAttributeTypedArgument = CustomAttributeData::in::Filter(CustomAttributeData::in::GetCustomAttributes((RuntimeParameterInfo)this), typeof<DateTimeConstantAttribute>(), 0);
      if (customAttributeTypedArgument.get_ArgumentType() != nullptr) {
        return DateTime((Int64)customAttributeTypedArgument.get_Value());
      }
    } else {
      Array<Object> customAttributes = GetCustomAttributes(typeof<DateTimeConstantAttribute>(), false);
      if (customAttributes != nullptr && customAttributes->get_Length() != 0) {
        return ((DateTimeConstantAttribute)customAttributes[0])->get_Value();
      }
    }
  }
  if (!MetadataToken::IsNullToken(m_tkParamDef)) {
    obj = MdConstant::GetValue(m_scope, m_tkParamDef, get_ParameterType()->GetTypeHandleInternal(), raw);
  }
  if (obj == DBNull::in::Value) {
    if (raw) {
      for (CustomAttributeData& customAttribute : CustomAttributeData::in::GetCustomAttributes((RuntimeParameterInfo)this)) {
        Type declaringType = customAttribute->get_Constructor()->get_DeclaringType();
        if (declaringType == typeof<DateTimeConstantAttribute>()) {
          obj = GetRawDateTimeConstant(customAttribute);
        } else if (declaringType == typeof<DecimalConstantAttribute>()) {
          obj = GetRawDecimalConstant(customAttribute);
        } else if (declaringType->IsSubclassOf(s_CustomConstantAttributeType)) {
          obj = GetRawConstant(customAttribute);
        }


      }
    } else {
      Array<Object> customAttributes2 = GetCustomAttributes(s_CustomConstantAttributeType, false);
      if (customAttributes2->get_Length() != 0) {
        obj = ((CustomConstantAttribute)customAttributes2[0])->get_Value();
      } else {
        customAttributes2 = GetCustomAttributes(s_DecimalConstantAttributeType, false);
        if (customAttributes2->get_Length() != 0) {
          obj = ((DecimalConstantAttribute)customAttributes2[0])->get_Value();
        }
      }
    }
  }
  if (obj == DBNull::in::Value) {
    m_noDefaultValue = true;
  }
  return obj;
}

Decimal RuntimeParameterInfo___::GetRawDecimalConstant(CustomAttributeData attr) {
  for (CustomAttributeNamedArgument& namedArgument : attr->get_NamedArguments()) {
    if (namedArgument.get_MemberInfo()->get_Name()->Equals("Value")) {
      return (Decimal)namedArgument.get_TypedValue().get_Value();
    }
  }
  Array<ParameterInfo> parameters = attr->get_Constructor()->GetParameters();
  IList<CustomAttributeTypedArgument> constructorArguments = attr->get_ConstructorArguments();
  if (parameters[2]->get_ParameterType() == typeof<UInt32>()) {
    Int32 lo = (Int32)(UInt32)constructorArguments[4].get_Value();
    Int32 mid = (Int32)(UInt32)constructorArguments[3].get_Value();
    Int32 hi = (Int32)(UInt32)constructorArguments[2].get_Value();
    Byte b = (Byte)constructorArguments[1].get_Value();
    Byte scale = (Byte)constructorArguments[0].get_Value();
    return Decimal(lo, mid, hi, b != 0, scale);
  }
  Int32 lo2 = (Int32)constructorArguments[4].get_Value();
  Int32 mid2 = (Int32)constructorArguments[3].get_Value();
  Int32 hi2 = (Int32)constructorArguments[2].get_Value();
  Byte b2 = (Byte)constructorArguments[1].get_Value();
  Byte scale2 = (Byte)constructorArguments[0].get_Value();
  return Decimal(lo2, mid2, hi2, b2 != 0, scale2);
}

DateTime RuntimeParameterInfo___::GetRawDateTimeConstant(CustomAttributeData attr) {
  for (CustomAttributeNamedArgument& namedArgument : attr->get_NamedArguments()) {
    if (namedArgument.get_MemberInfo()->get_Name()->Equals("Value")) {
      return DateTime((Int64)namedArgument.get_TypedValue().get_Value());
    }
  }
  return DateTime((Int64)attr->get_ConstructorArguments()[0].get_Value());
}

Object RuntimeParameterInfo___::GetRawConstant(CustomAttributeData attr) {
  for (CustomAttributeNamedArgument& namedArgument : attr->get_NamedArguments()) {
    if (namedArgument.get_MemberInfo()->get_Name()->Equals("Value")) {
      return namedArgument.get_TypedValue().get_Value();
    }
  }
  return DBNull::in::Value;
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
  return CustomAttribute::GetCustomAttributes((RuntimeParameterInfo)this, rt::as<RuntimeType>(typeof<Object>()));
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
  s_DecimalConstantAttributeType = typeof<DecimalConstantAttribute>();
  s_CustomConstantAttributeType = typeof<CustomConstantAttribute>();
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeParameterInfoNamespace
