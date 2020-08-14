#include "RuntimeConstructorInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/MemberAccessException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodBody-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeConstructorInfoNamespace {
using namespace System::Text;

INVOCATION_FLAGS RuntimeConstructorInfo___::get_InvocationFlags() {
}

RuntimeMethodHandleInternal RuntimeConstructorInfo___::get_ValueOfIRuntimeMethodInfo() {
  return RuntimeMethodHandleInternal(m_handle);
}

Signature RuntimeConstructorInfo___::get_Signature() {
}

RuntimeType RuntimeConstructorInfo___::get_ReflectedTypeInternal() {
  return m_reflectedTypeCache->GetRuntimeType();
}

BindingFlags RuntimeConstructorInfo___::get_BindingFlags() {
  return m_bindingFlags;
}

String RuntimeConstructorInfo___::get_Name() {
  return RuntimeMethodHandle::GetName((RuntimeConstructorInfo)this);
}

MemberTypes RuntimeConstructorInfo___::get_MemberType() {
  return MemberTypes::Constructor;
}

Type RuntimeConstructorInfo___::get_DeclaringType() {
  if (!m_reflectedTypeCache->get_IsGlobal()) {
    return m_declaringType;
  }
  return nullptr;
}

Type RuntimeConstructorInfo___::get_ReflectedType() {
  if (!m_reflectedTypeCache->get_IsGlobal()) {
    return get_ReflectedTypeInternal();
  }
  return nullptr;
}

Int32 RuntimeConstructorInfo___::get_MetadataToken() {
  return RuntimeMethodHandle::GetMethodDef((RuntimeConstructorInfo)this);
}

Module RuntimeConstructorInfo___::get_Module() {
  return GetRuntimeModule();
}

RuntimeMethodHandle RuntimeConstructorInfo___::get_MethodHandle() {
  return RuntimeMethodHandle((RuntimeConstructorInfo)this);
}

MethodAttributes RuntimeConstructorInfo___::get_Attributes() {
  return m_methodAttributes;
}

CallingConventions RuntimeConstructorInfo___::get_CallingConvention() {
  return get_Signature()->get_CallingConvention();
}

Boolean RuntimeConstructorInfo___::get_IsSecurityCritical() {
  return true;
}

Boolean RuntimeConstructorInfo___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean RuntimeConstructorInfo___::get_IsSecurityTransparent() {
  return false;
}

Boolean RuntimeConstructorInfo___::get_ContainsGenericParameters() {
  if (get_DeclaringType() != nullptr) {
    return get_DeclaringType()->get_ContainsGenericParameters();
  }
  return false;
}

void RuntimeConstructorInfo___::ctor(RuntimeMethodHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, MethodAttributes methodAttributes, BindingFlags bindingFlags) {
  m_bindingFlags = bindingFlags;
  m_reflectedTypeCache = reflectedTypeCache;
  m_declaringType = declaringType;
  m_handle = handle.get_Value();
  m_methodAttributes = methodAttributes;
}

Boolean RuntimeConstructorInfo___::CacheEquals(Object o) {
  RuntimeConstructorInfo runtimeConstructorInfo = rt::as<RuntimeConstructorInfo>(o);
  if ((Object)runtimeConstructorInfo != nullptr) {
    return runtimeConstructorInfo->m_handle == m_handle;
  }
  return false;
}

void RuntimeConstructorInfo___::CheckConsistency(Object target) {
}

String RuntimeConstructorInfo___::ToString() {
  if (m_toString == nullptr) {
    ValueStringBuilder sbParamList = ValueStringBuilder(100);
    sbParamList.Append("Void ");
    sbParamList.Append(get_Name());
    sbParamList.Append(40);
    MethodBase::in::AppendParameters(sbParamList, GetParameterTypes(), get_CallingConvention());
    sbParamList.Append(41);
    m_toString = sbParamList.ToString();
  }
  return m_toString;
}

Array<Object> RuntimeConstructorInfo___::GetCustomAttributes(Boolean inherit) {
}

Array<Object> RuntimeConstructorInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeConstructorInfo)this, runtimeType);
}

Boolean RuntimeConstructorInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeConstructorInfo)this, runtimeType);
}

IList<CustomAttributeData> RuntimeConstructorInfo___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeConstructorInfo)this);
}

Boolean RuntimeConstructorInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return HasSameMetadataDefinitionAsCore<RuntimeConstructorInfo>(other);
}

RuntimeType RuntimeConstructorInfo___::GetRuntimeType() {
  return m_declaringType;
}

RuntimeModule RuntimeConstructorInfo___::GetRuntimeModule() {
  return RuntimeTypeHandle::GetModule(m_declaringType);
}

Type RuntimeConstructorInfo___::GetReturnType() {
  return get_Signature()->get_ReturnType();
}

Array<ParameterInfo> RuntimeConstructorInfo___::GetParametersNoCopy() {
}

Array<ParameterInfo> RuntimeConstructorInfo___::GetParameters() {
  Array<ParameterInfo> parametersNoCopy = GetParametersNoCopy();
  if (parametersNoCopy->get_Length() == 0) {
    return parametersNoCopy;
  }
  Array<ParameterInfo> array = rt::newarr<Array<ParameterInfo>>(parametersNoCopy->get_Length());
  Array<>::in::Copy(parametersNoCopy, array, parametersNoCopy->get_Length());
  return array;
}

MethodImplAttributes RuntimeConstructorInfo___::GetMethodImplementationFlags() {
  return RuntimeMethodHandle::GetImplAttributes((RuntimeConstructorInfo)this);
}

void RuntimeConstructorInfo___::CheckCanCreateInstance(Type declaringType, Boolean isVarArg) {
  if (declaringType == nullptr) {
    rt::throw_exception<ArgumentNullException>("declaringType");
  }
  if (declaringType->get_IsInterface()) {
    rt::throw_exception<MemberAccessException>(SR::Format(SR::get_Acc_CreateInterfaceEx(), declaringType));
  }
  if (declaringType->get_IsAbstract()) {
    rt::throw_exception<MemberAccessException>(SR::Format(SR::get_Acc_CreateAbstEx(), declaringType));
  }
}

void RuntimeConstructorInfo___::ThrowNoInvokeException() {
}

Object RuntimeConstructorInfo___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  INVOCATION_FLAGS invocationFlags = get_InvocationFlags();
}

MethodBody RuntimeConstructorInfo___::GetMethodBody() {
  RuntimeMethodBody methodBody = RuntimeMethodHandle::GetMethodBody((RuntimeConstructorInfo)this, get_ReflectedTypeInternal());
  if (methodBody != nullptr) {
    methodBody->_methodBase = (RuntimeConstructorInfo)this;
  }
  return methodBody;
}

Object RuntimeConstructorInfo___::Invoke(BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  INVOCATION_FLAGS invocationFlags = get_InvocationFlags();
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeConstructorInfoNamespace
