#include "RuntimeConstructorInfo-dep.h"

#include <System.Private.CoreLib/System/ArgIterator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Delegate-dep.h>
#include <System.Private.CoreLib/System/MemberAccessException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodBody-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetException-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetParameterCountException-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeConstructorInfoNamespace {
using namespace System::Text;

INVOCATION_FLAGS RuntimeConstructorInfo___::get_InvocationFlags() {
  if ((m_invocationFlags & INVOCATION_FLAGS::INVOCATION_FLAGS_INITIALIZED) == 0) {
    INVOCATION_FLAGS iNVOCATION_FLAGS = INVOCATION_FLAGS::INVOCATION_FLAGS_IS_CTOR;
    Type declaringType = get_DeclaringType();
    if (declaringType == rt::typeof<void>() || (declaringType != nullptr && declaringType->get_ContainsGenericParameters()) || (get_CallingConvention() & CallingConventions::VarArgs) == CallingConventions::VarArgs) {
      iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE;
    } else if (MethodBase::get_IsStatic() || (declaringType != nullptr && declaringType->get_IsAbstract())) {
      iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_NO_CTOR_INVOKE;
    } else {
      if (declaringType != nullptr && declaringType->get_IsByRefLike()) {
        iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_CONTAINS_STACK_POINTERS;
      }
      if (rt::typeof<Delegate>()->IsAssignableFrom(get_DeclaringType())) {
        iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_IS_DELEGATE_CTOR;
      }
    }

    m_invocationFlags = (iNVOCATION_FLAGS | INVOCATION_FLAGS::INVOCATION_FLAGS_INITIALIZED);
  }
  return m_invocationFlags;
}

RuntimeMethodHandleInternal RuntimeConstructorInfo___::get_ValueOfIRuntimeMethodInfo() {
  return RuntimeMethodHandleInternal(m_handle);
}

Signature RuntimeConstructorInfo___::get_Signature() {
  auto default = m_signature;
  if (default != nullptr) default = (m_signature = rt::newobj<Signature>((RuntimeConstructorInfo)this, m_declaringType));

  return default;
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
  if ((target != nullptr || !MethodBase::get_IsStatic()) && !m_declaringType->IsInstanceOfType(target)) {
    if (target == nullptr) {
      rt::throw_exception<TargetException>(SR::get_RFLCT_Targ_StatMethReqTarg());
    }
    rt::throw_exception<TargetException>(SR::get_RFLCT_Targ_ITargMismatch());
  }
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
  return CustomAttribute::GetCustomAttributes((RuntimeConstructorInfo)this, rt::as<RuntimeType>(rt::typeof<Object>()));
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
  auto default = m_parameters;
  if (default != nullptr) default = (m_parameters = RuntimeParameterInfo::in::GetParameters((RuntimeConstructorInfo)this, (RuntimeConstructorInfo)this, get_Signature()));

  return default;
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
  if (declaringType->GetRootElementType() == rt::typeof<ArgIterator>()) {
    rt::throw_exception<NotSupportedException>();
  }
  if (isVarArg) {
    rt::throw_exception<NotSupportedException>();
  }
  if (declaringType->get_ContainsGenericParameters()) {
    rt::throw_exception<MemberAccessException>(SR::Format(SR::get_Acc_CreateGenericEx(), declaringType));
  }
  if (declaringType == rt::typeof<void>()) {
    rt::throw_exception<MemberAccessException>(SR::get_Access_Void());
  }
}

void RuntimeConstructorInfo___::ThrowNoInvokeException() {
  CheckCanCreateInstance(get_DeclaringType(), (get_CallingConvention() & CallingConventions::VarArgs) == CallingConventions::VarArgs);
  if ((get_Attributes() & MethodAttributes::Static) == MethodAttributes::Static) {
    rt::throw_exception<MemberAccessException>(SR::get_Acc_NotClassInit());
  }
  rt::throw_exception<TargetException>();
}

Object RuntimeConstructorInfo___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  INVOCATION_FLAGS invocationFlags = get_InvocationFlags();
  if ((invocationFlags & INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE) != 0) {
    ThrowNoInvokeException();
  }
  CheckConsistency(obj);
  Signature signature = get_Signature();
  Int32 num = signature->get_Arguments()->get_Length();
  Int32 num2 = (parameters != nullptr) ? parameters->get_Length() : 0;
  if (num != num2) {
    rt::throw_exception<TargetParameterCountException>(SR::get_Arg_ParmCnt());
  }
  Boolean wrapExceptions = (invokeAttr & BindingFlags::DoNotWrapExceptions) == 0;
  if (num2 > 0) {
    Array<Object> array = CheckArguments(parameters, binder, invokeAttr, culture, signature);
    Object result = RuntimeMethodHandle::InvokeMethod(obj, array, signature, false, wrapExceptions);
    for (Int32 i = 0; i < array->get_Length(); i++) {
      parameters[i] = array[i];
    }
    return result;
  }
  return RuntimeMethodHandle::InvokeMethod(obj, nullptr, signature, false, wrapExceptions);
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
  if ((invocationFlags & (INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE | INVOCATION_FLAGS::INVOCATION_FLAGS_NO_CTOR_INVOKE | INVOCATION_FLAGS::INVOCATION_FLAGS_CONTAINS_STACK_POINTERS)) != 0) {
    ThrowNoInvokeException();
  }
  Signature signature = get_Signature();
  Int32 num = signature->get_Arguments()->get_Length();
  Int32 num2 = (parameters != nullptr) ? parameters->get_Length() : 0;
  if (num != num2) {
    rt::throw_exception<TargetParameterCountException>(SR::get_Arg_ParmCnt());
  }
  Boolean wrapExceptions = (invokeAttr & BindingFlags::DoNotWrapExceptions) == 0;
  if (num2 > 0) {
    Array<Object> array = CheckArguments(parameters, binder, invokeAttr, culture, signature);
    Object result = RuntimeMethodHandle::InvokeMethod(nullptr, array, signature, true, wrapExceptions);
    for (Int32 i = 0; i < array->get_Length(); i++) {
      parameters[i] = array[i];
    }
    return result;
  }
  return RuntimeMethodHandle::InvokeMethod(nullptr, nullptr, signature, true, wrapExceptions);
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeConstructorInfoNamespace
