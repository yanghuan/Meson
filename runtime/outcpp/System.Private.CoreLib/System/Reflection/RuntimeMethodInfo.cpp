#include "RuntimeMethodInfo-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/DelegateBindingFlags.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/MemberAccessException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilderInstantiation-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodBody-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetException-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetParameterCountException-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/Security/VerificationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/ValueStringBuilder-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeNameFormatFlags.h>
#include <System.Private.CoreLib/System/ValueType-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeMethodInfoNamespace {
using namespace System::Reflection::Emit;
using namespace System::Security;
using namespace System::Text;

INVOCATION_FLAGS RuntimeMethodInfo___::get_InvocationFlags() {
  if ((m_invocationFlags & INVOCATION_FLAGS::INVOCATION_FLAGS_INITIALIZED) == 0) {
    INVOCATION_FLAGS iNVOCATION_FLAGS = INVOCATION_FLAGS::INVOCATION_FLAGS_UNKNOWN;
    Type declaringType = get_DeclaringType();
    if (get_ContainsGenericParameters() || IsDisallowedByRefType(get_ReturnType()) || (declaringType != nullptr && declaringType->get_ContainsGenericParameters()) || (get_CallingConvention() & CallingConventions::VarArgs) == CallingConventions::VarArgs) {
      iNVOCATION_FLAGS = INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE;
    } else if ((declaringType != nullptr && declaringType->get_IsByRefLike()) || get_ReturnType()->get_IsByRefLike()) {
      iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_CONTAINS_STACK_POINTERS;
    }

    m_invocationFlags = (iNVOCATION_FLAGS | INVOCATION_FLAGS::INVOCATION_FLAGS_INITIALIZED);
  }
  return m_invocationFlags;
}

RuntimeMethodHandleInternal RuntimeMethodInfo___::get_ValueOfIRuntimeMethodInfo() {
  return RuntimeMethodHandleInternal(m_handle);
}

RuntimeType RuntimeMethodInfo___::get_ReflectedTypeInternal() {
  return m_reflectedTypeCache->GetRuntimeType();
}

Signature RuntimeMethodInfo___::get_Signature() {
  auto& as = m_signature;
  return as != nullptr ? as : (m_signature = rt::newobj<Signature>((RuntimeMethodInfo)this, m_declaringType));
}

BindingFlags RuntimeMethodInfo___::get_BindingFlags() {
  return m_bindingFlags;
}

Int32 RuntimeMethodInfo___::get_GenericParameterCount() {
  return RuntimeMethodHandle::GetGenericParameterCount((RuntimeMethodInfo)this);
}

String RuntimeMethodInfo___::get_Name() {
  auto& as = m_name;
  return as != nullptr ? as : (m_name = RuntimeMethodHandle::GetName((RuntimeMethodInfo)this));
}

Type RuntimeMethodInfo___::get_DeclaringType() {
  if (m_reflectedTypeCache->get_IsGlobal()) {
    return nullptr;
  }
  return m_declaringType;
}

Type RuntimeMethodInfo___::get_ReflectedType() {
  if (m_reflectedTypeCache->get_IsGlobal()) {
    return nullptr;
  }
  return m_reflectedTypeCache->GetRuntimeType();
}

MemberTypes RuntimeMethodInfo___::get_MemberType() {
  return MemberTypes::Method;
}

Int32 RuntimeMethodInfo___::get_MetadataToken() {
  return RuntimeMethodHandle::GetMethodDef((RuntimeMethodInfo)this);
}

Module RuntimeMethodInfo___::get_Module() {
  return GetRuntimeModule();
}

Boolean RuntimeMethodInfo___::get_IsSecurityCritical() {
  return true;
}

Boolean RuntimeMethodInfo___::get_IsSecuritySafeCritical() {
  return false;
}

Boolean RuntimeMethodInfo___::get_IsSecurityTransparent() {
  return false;
}

RuntimeMethodHandle RuntimeMethodInfo___::get_MethodHandle() {
  return RuntimeMethodHandle((RuntimeMethodInfo)this);
}

MethodAttributes RuntimeMethodInfo___::get_Attributes() {
  return m_methodAttributes;
}

CallingConventions RuntimeMethodInfo___::get_CallingConvention() {
  return get_Signature()->get_CallingConvention();
}

Type RuntimeMethodInfo___::get_ReturnType() {
  return get_Signature()->get_ReturnType();
}

ICustomAttributeProvider RuntimeMethodInfo___::get_ReturnTypeCustomAttributes() {
  return get_ReturnParameter();
}

ParameterInfo RuntimeMethodInfo___::get_ReturnParameter() {
  return FetchReturnParameter();
}

Boolean RuntimeMethodInfo___::get_IsCollectible() {
  return RuntimeMethodHandle::GetIsCollectible(RuntimeMethodHandleInternal(m_handle)) != Interop::BOOL::FALSE;
}

Boolean RuntimeMethodInfo___::get_IsGenericMethod() {
  return RuntimeMethodHandle::HasMethodInstantiation((RuntimeMethodInfo)this);
}

Boolean RuntimeMethodInfo___::get_IsGenericMethodDefinition() {
  return RuntimeMethodHandle::IsGenericMethodDefinition((RuntimeMethodInfo)this);
}

Boolean RuntimeMethodInfo___::get_ContainsGenericParameters() {
  if (get_DeclaringType() != nullptr && get_DeclaringType()->get_ContainsGenericParameters()) {
    return true;
  }
  if (!get_IsGenericMethod()) {
    return false;
  }
  Array<Type> genericArguments = GetGenericArguments();
  for (Int32 i = 0; i < genericArguments->get_Length(); i++) {
    if (genericArguments[i]->get_ContainsGenericParameters()) {
      return true;
    }
  }
  return false;
}

Boolean RuntimeMethodInfo___::IsDisallowedByRefType(Type type) {
  if (!type->get_IsByRef()) {
    return false;
  }
  Type elementType = type->GetElementType();
  if (!elementType->get_IsByRefLike()) {
    return elementType == rt::typeof<void>();
  }
  return true;
}

void RuntimeMethodInfo___::ctor(RuntimeMethodHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, MethodAttributes methodAttributes, BindingFlags bindingFlags, Object keepalive) {
  m_bindingFlags = bindingFlags;
  m_declaringType = declaringType;
  m_keepalive = keepalive;
  m_handle = handle.get_Value();
  m_reflectedTypeCache = reflectedTypeCache;
  m_methodAttributes = methodAttributes;
}

Array<ParameterInfo> RuntimeMethodInfo___::FetchNonReturnParameters() {
  auto& as = m_parameters;
  return as != nullptr ? as : (m_parameters = RuntimeParameterInfo::in::GetParameters((RuntimeMethodInfo)this, (RuntimeMethodInfo)this, get_Signature()));
}

ParameterInfo RuntimeMethodInfo___::FetchReturnParameter() {
  auto& as = m_returnParameter;
  return as != nullptr ? as : (m_returnParameter = RuntimeParameterInfo::in::GetReturnParameter((RuntimeMethodInfo)this, (RuntimeMethodInfo)this, get_Signature()));
}

Boolean RuntimeMethodInfo___::CacheEquals(Object o) {
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(o);
  if ((Object)runtimeMethodInfo != nullptr) {
    return runtimeMethodInfo->m_handle == m_handle;
  }
  return false;
}

RuntimeMethodInfo RuntimeMethodInfo___::GetParentDefinition() {
  if (!MethodBase::in::get_IsVirtual() || m_declaringType->get_IsInterface()) {
    return nullptr;
  }
  RuntimeType runtimeType = (RuntimeType)m_declaringType->get_BaseType();
  if (runtimeType == nullptr) {
    return nullptr;
  }
  Int32 slot = RuntimeMethodHandle::GetSlot((RuntimeMethodInfo)this);
  if (RuntimeTypeHandle::GetNumVirtuals(runtimeType) <= slot) {
    return nullptr;
  }
  return (RuntimeMethodInfo)RuntimeType::in::GetMethodBase(runtimeType, RuntimeTypeHandle::GetMethodAt(runtimeType, slot));
}

RuntimeType RuntimeMethodInfo___::GetDeclaringTypeInternal() {
  return m_declaringType;
}

String RuntimeMethodInfo___::ToString() {
  if (m_toString == nullptr) {
    ValueStringBuilder sbParamList = ValueStringBuilder(100);
    sbParamList.Append(get_ReturnType()->FormatTypeName());
    sbParamList.Append(32);
    sbParamList.Append(get_Name());
    if (get_IsGenericMethod()) {
      sbParamList.Append(RuntimeMethodHandle::ConstructInstantiation((RuntimeMethodInfo)this, TypeNameFormatFlags::FormatBasic));
    }
    sbParamList.Append(40);
    MethodBase::in::AppendParameters(sbParamList, GetParameterTypes(), get_CallingConvention());
    sbParamList.Append(41);
    m_toString = sbParamList.ToString();
  }
  return m_toString;
}

Int32 RuntimeMethodInfo___::GetHashCode() {
  if (get_IsGenericMethod()) {
    return ValueType::in::GetHashCodeOfPtr(m_handle);
  }
  return MethodInfo::in::GetHashCode();
}

Boolean RuntimeMethodInfo___::Equals(Object obj) {
  if (!get_IsGenericMethod()) {
    return obj == (RuntimeMethodInfo)this;
  }
  RuntimeMethodInfo runtimeMethodInfo = rt::as<RuntimeMethodInfo>(obj);
  if (runtimeMethodInfo == nullptr || !runtimeMethodInfo->get_IsGenericMethod()) {
    return false;
  }
  IRuntimeMethodInfo runtimeMethodInfo2 = RuntimeMethodHandle::StripMethodInstantiation((RuntimeMethodInfo)this);
  IRuntimeMethodInfo runtimeMethodInfo3 = RuntimeMethodHandle::StripMethodInstantiation(runtimeMethodInfo);
  if (runtimeMethodInfo2->get_Value().get_Value() != runtimeMethodInfo3->get_Value().get_Value()) {
    return false;
  }
  Array<Type> genericArguments = GetGenericArguments();
  Array<Type> genericArguments2 = runtimeMethodInfo->GetGenericArguments();
  if (genericArguments->get_Length() != genericArguments2->get_Length()) {
    return false;
  }
  for (Int32 i = 0; i < genericArguments->get_Length(); i++) {
    if (genericArguments[i] != genericArguments2[i]) {
      return false;
    }
  }
  if (get_DeclaringType() != runtimeMethodInfo->get_DeclaringType()) {
    return false;
  }
  if (get_ReflectedType() != runtimeMethodInfo->get_ReflectedType()) {
    return false;
  }
  return true;
}

Array<Object> RuntimeMethodInfo___::GetCustomAttributes(Boolean inherit) {
  return CustomAttribute::GetCustomAttributes((RuntimeMethodInfo)this, rt::as<RuntimeType>(rt::typeof<Object>()), inherit);
}

Array<Object> RuntimeMethodInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeMethodInfo)this, runtimeType, inherit);
}

Boolean RuntimeMethodInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeMethodInfo)this, runtimeType, inherit);
}

IList<CustomAttributeData> RuntimeMethodInfo___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeMethodInfo)this);
}

Boolean RuntimeMethodInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return HasSameMetadataDefinitionAsCore<RuntimeMethodInfo>(other);
}

RuntimeType RuntimeMethodInfo___::GetRuntimeType() {
  return m_declaringType;
}

RuntimeModule RuntimeMethodInfo___::GetRuntimeModule() {
  return m_declaringType->GetRuntimeModule();
}

Array<ParameterInfo> RuntimeMethodInfo___::GetParametersNoCopy() {
  return FetchNonReturnParameters();
}

Array<ParameterInfo> RuntimeMethodInfo___::GetParameters() {
  Array<ParameterInfo> array = FetchNonReturnParameters();
  if (array->get_Length() == 0) {
    return array;
  }
  Array<ParameterInfo> array2 = rt::newarr<Array<ParameterInfo>>(array->get_Length());
  Array<>::in::Copy(array, array2, array->get_Length());
  return array2;
}

MethodImplAttributes RuntimeMethodInfo___::GetMethodImplementationFlags() {
  return RuntimeMethodHandle::GetImplAttributes((RuntimeMethodInfo)this);
}

MethodBody RuntimeMethodInfo___::GetMethodBody() {
  RuntimeMethodBody methodBody = RuntimeMethodHandle::GetMethodBody((RuntimeMethodInfo)this, get_ReflectedTypeInternal());
  if (methodBody != nullptr) {
    methodBody->_methodBase = (RuntimeMethodInfo)this;
  }
  return methodBody;
}

void RuntimeMethodInfo___::CheckConsistency(Object target) {
  if ((m_methodAttributes & MethodAttributes::Static) != MethodAttributes::Static && !m_declaringType->IsInstanceOfType(target)) {
    if (target == nullptr) {
      rt::throw_exception<TargetException>(SR::get_RFLCT_Targ_StatMethReqTarg());
    }
    rt::throw_exception<TargetException>(SR::get_RFLCT_Targ_ITargMismatch());
  }
}

void RuntimeMethodInfo___::ThrowNoInvokeException() {
  if ((get_InvocationFlags() & INVOCATION_FLAGS::INVOCATION_FLAGS_CONTAINS_STACK_POINTERS) != 0) {
    rt::throw_exception<NotSupportedException>();
  }
  if ((get_CallingConvention() & CallingConventions::VarArgs) == CallingConventions::VarArgs) {
    rt::throw_exception<NotSupportedException>();
  }
  if (get_DeclaringType()->get_ContainsGenericParameters() || get_ContainsGenericParameters()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_UnboundGenParam());
  }
  if (MethodBase::in::get_IsAbstract()) {
    rt::throw_exception<MemberAccessException>();
  }
  if (get_ReturnType()->get_IsByRef()) {
    Type elementType = get_ReturnType()->GetElementType();
    if (elementType->get_IsByRefLike()) {
      rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ByRefToByRefLikeReturn());
    }
    if (elementType == rt::typeof<void>()) {
      rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ByRefToVoidReturn());
    }
  }
  rt::throw_exception<TargetException>();
}

Object RuntimeMethodInfo___::Invoke(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  Array<Object> array = InvokeArgumentsCheck(obj, invokeAttr, binder, parameters, culture);
  Boolean wrapExceptions = (invokeAttr & BindingFlags::DoNotWrapExceptions) == 0;
  if (array == nullptr || array->get_Length() == 0) {
    return RuntimeMethodHandle::InvokeMethod(obj, nullptr, get_Signature(), false, wrapExceptions);
  }
  Object result = RuntimeMethodHandle::InvokeMethod(obj, array, get_Signature(), false, wrapExceptions);
  for (Int32 i = 0; i < array->get_Length(); i++) {
    parameters[i] = array[i];
  }
  return result;
}

Array<Object> RuntimeMethodInfo___::InvokeArgumentsCheck(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> parameters, CultureInfo culture) {
  Signature signature = get_Signature();
  Int32 num = signature->get_Arguments()->get_Length();
  Int32 num2 = (parameters != nullptr) ? parameters->get_Length() : 0;
  INVOCATION_FLAGS invocationFlags = get_InvocationFlags();
  if ((invocationFlags & (INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE | INVOCATION_FLAGS::INVOCATION_FLAGS_CONTAINS_STACK_POINTERS)) != 0) {
    ThrowNoInvokeException();
  }
  CheckConsistency(obj);
  if (num != num2) {
    rt::throw_exception<TargetParameterCountException>(SR::get_Arg_ParmCnt());
  }
  if (num2 != 0) {
    return CheckArguments(parameters, binder, invokeAttr, culture, signature);
  }
  return nullptr;
}

MethodInfo RuntimeMethodInfo___::GetBaseDefinition() {
  if (!MethodBase::in::get_IsVirtual() || MethodBase::in::get_IsStatic() || m_declaringType == nullptr || m_declaringType->get_IsInterface()) {
    return (RuntimeMethodInfo)this;
  }
  Int32 slot = RuntimeMethodHandle::GetSlot((RuntimeMethodInfo)this);
  RuntimeType runtimeType = (RuntimeType)get_DeclaringType();
  RuntimeType reflectedType = runtimeType;
  RuntimeMethodHandleInternal methodHandle = RuntimeMethodHandleInternal();
  do {
    Int32 numVirtuals = RuntimeTypeHandle::GetNumVirtuals(runtimeType);
    if (numVirtuals <= slot) {
      break;
    }
    methodHandle = RuntimeTypeHandle::GetMethodAt(runtimeType, slot);
    reflectedType = runtimeType;
    runtimeType = (RuntimeType)runtimeType->get_BaseType();
  } while (runtimeType != nullptr)
  return (MethodInfo)RuntimeType::in::GetMethodBase(reflectedType, methodHandle);
}

Delegate RuntimeMethodInfo___::CreateDelegate(Type delegateType) {
  return CreateDelegateInternal(delegateType, nullptr, (DelegateBindingFlags)68);
}

Delegate RuntimeMethodInfo___::CreateDelegate(Type delegateType, Object target) {
  return CreateDelegateInternal(delegateType, target, DelegateBindingFlags::RelaxedSignature);
}

Delegate RuntimeMethodInfo___::CreateDelegateInternal(Type delegateType, Object firstArgument, DelegateBindingFlags bindingFlags) {
  if (delegateType == nullptr) {
    rt::throw_exception<ArgumentNullException>("delegateType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(delegateType);
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MustBeRuntimeType(), "delegateType");
  }
  if (!runtimeType->IsDelegate()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeDelegate(), "delegateType");
  }
  Delegate delegate = Delegate::in::CreateDelegateInternal(runtimeType, (RuntimeMethodInfo)this, firstArgument, bindingFlags);
  if ((Object)delegate == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_DlgtTargMeth());
  }
  return delegate;
}

MethodInfo RuntimeMethodInfo___::MakeGenericMethod(Array<Type> methodInstantiation) {
  if (methodInstantiation == nullptr) {
    rt::throw_exception<ArgumentNullException>("methodInstantiation");
  }
  Array<RuntimeType> array = rt::newarr<Array<RuntimeType>>(methodInstantiation->get_Length());
  if (!get_IsGenericMethodDefinition()) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_NotGenericMethodDefinition(), (RuntimeMethodInfo)this));
  }
  for (Int32 i = 0; i < methodInstantiation->get_Length(); i++) {
    Type type = methodInstantiation[i];
    if (type == nullptr) {
      rt::throw_exception<ArgumentNullException>();
    }
    RuntimeType runtimeType = rt::as<RuntimeType>(type);
    if (runtimeType == nullptr) {
      Array<Type> array2 = rt::newarr<Array<Type>>(methodInstantiation->get_Length());
      for (Int32 j = 0; j < methodInstantiation->get_Length(); j++) {
        array2[j] = methodInstantiation[j];
      }
      methodInstantiation = array2;
      return MethodBuilderInstantiation::in::MakeGenericMethod((RuntimeMethodInfo)this, methodInstantiation);
    }
    array[i] = runtimeType;
  }
  Array<RuntimeType> genericArgumentsInternal = GetGenericArgumentsInternal();
  RuntimeType::in::SanityCheckGenericArguments(array, genericArgumentsInternal);
  MethodInfo methodInfo = nullptr;
  try {
    return rt::as<MethodInfo>(RuntimeType::in::GetMethodBase(get_ReflectedTypeInternal(), RuntimeMethodHandle::GetStubIfNeeded(RuntimeMethodHandleInternal(m_handle), m_declaringType, array)));
  } catch (VerificationException e) {
  }
}

Array<RuntimeType> RuntimeMethodInfo___::GetGenericArgumentsInternal() {
  return RuntimeMethodHandle::GetMethodInstantiationInternal((RuntimeMethodInfo)this);
}

Array<Type> RuntimeMethodInfo___::GetGenericArguments() {
  auto& as = RuntimeMethodHandle::GetMethodInstantiationPublic((RuntimeMethodInfo)this);
  return as != nullptr ? as : Array<>::in::Empty<Type>();
}

MethodInfo RuntimeMethodInfo___::GetGenericMethodDefinition() {
  if (!get_IsGenericMethod()) {
    rt::throw_exception<InvalidOperationException>();
  }
  return rt::as<MethodInfo>(RuntimeType::in::GetMethodBase(m_declaringType, RuntimeMethodHandle::StripMethodInstantiation((RuntimeMethodInfo)this)));
}

MethodBase RuntimeMethodInfo___::InternalGetCurrentMethod(StackCrawlMark& stackMark) {
  IRuntimeMethodInfo currentMethod = RuntimeMethodHandle::GetCurrentMethod(stackMark);
  if (currentMethod == nullptr) {
    return nullptr;
  }
  return RuntimeType::in::GetMethodBase(currentMethod);
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeMethodInfoNamespace
