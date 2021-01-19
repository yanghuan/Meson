#include "RtFieldInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/FieldAccessException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Reflection/RtFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/TargetException-dep.h>
#include <System.Private.CoreLib/System/RuntimeFieldHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/Signature-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::RtFieldInfoNamespace {
INVOCATION_FLAGS RtFieldInfo___::get_InvocationFlags() {
  if ((m_invocationFlags & INVOCATION_FLAGS::INVOCATION_FLAGS_INITIALIZED) == 0) {
    return InitializeInvocationFlags();
  }
  return m_invocationFlags;
}

RuntimeFieldHandleInternal RtFieldInfo___::get_ValueOfIRuntimeFieldInfo() {
  return RuntimeFieldHandleInternal(m_fieldHandle);
}

String RtFieldInfo___::get_Name() {
  String as = m_name;
  return as != nullptr ? as : (m_name = RuntimeFieldHandle::GetName((RtFieldInfo)this));
}

Int32 RtFieldInfo___::get_MetadataToken() {
  return RuntimeFieldHandle::GetToken((RtFieldInfo)this);
}

RuntimeFieldHandle RtFieldInfo___::get_FieldHandle() {
  return RuntimeFieldHandle((RtFieldInfo)this);
}

FieldAttributes RtFieldInfo___::get_Attributes() {
  return m_fieldAttributes;
}

Type RtFieldInfo___::get_FieldType() {
  RuntimeType as = m_fieldType;
  return as != nullptr ? as : InitializeFieldType();
}

INVOCATION_FLAGS RtFieldInfo___::InitializeInvocationFlags() {
  Type declaringType = get_DeclaringType();
  INVOCATION_FLAGS iNVOCATION_FLAGS = INVOCATION_FLAGS::INVOCATION_FLAGS_UNKNOWN;
  if (declaringType != nullptr && declaringType->get_ContainsGenericParameters()) {
    iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE;
  }
  if (iNVOCATION_FLAGS == INVOCATION_FLAGS::INVOCATION_FLAGS_UNKNOWN) {
    if ((m_fieldAttributes & FieldAttributes::InitOnly) != 0) {
      iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_IS_CTOR;
    }
    if ((m_fieldAttributes & FieldAttributes::HasFieldRVA) != 0) {
      iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_IS_CTOR;
    }
    Type fieldType = get_FieldType();
    if (fieldType->get_IsPointer() || fieldType->get_IsEnum() || fieldType->get_IsPrimitive()) {
      iNVOCATION_FLAGS |= INVOCATION_FLAGS::INVOCATION_FLAGS_FIELD_SPECIAL_CAST;
    }
  }
  return m_invocationFlags = iNVOCATION_FLAGS | INVOCATION_FLAGS::INVOCATION_FLAGS_INITIALIZED;
}

void RtFieldInfo___::ctor(RuntimeFieldHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, BindingFlags bindingFlags) {
  m_fieldHandle = handle.get_Value();
  m_fieldAttributes = RuntimeFieldHandle::GetAttributes(handle);
}

void RtFieldInfo___::CheckConsistency(Object target) {
  if ((m_fieldAttributes & FieldAttributes::Static) != FieldAttributes::Static && !m_declaringType->IsInstanceOfType(target)) {
    if (target == nullptr) {
      rt::throw_exception<TargetException>(SR::get_RFLCT_Targ_StatFldReqTarg());
    }
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_FieldDeclTarget(), get_Name(), m_declaringType, target->GetType()));
  }
}

Boolean RtFieldInfo___::CacheEquals(Object o) {
  RtFieldInfo rtFieldInfo = rt::as<RtFieldInfo>(o);
  if ((Object)rtFieldInfo != nullptr) {
    return rtFieldInfo->m_fieldHandle == m_fieldHandle;
  }
  return false;
}

RuntimeModule RtFieldInfo___::GetRuntimeModule() {
  return RuntimeTypeHandle::GetModule(RuntimeFieldHandle::GetApproxDeclaringType((RtFieldInfo)this));
}

Object RtFieldInfo___::GetValue(Object obj) {
  INVOCATION_FLAGS invocationFlags = get_InvocationFlags();
  RuntimeType runtimeType = rt::as<RuntimeType>(get_DeclaringType());
  if ((invocationFlags & INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE) != 0) {
    if (runtimeType != nullptr && get_DeclaringType()->get_ContainsGenericParameters()) {
      rt::throw_exception<InvalidOperationException>(SR::get_Arg_UnboundGenField());
    }
    rt::throw_exception<FieldAccessException>();
  }
  CheckConsistency(obj);
  RuntimeType fieldType = (RuntimeType)get_FieldType();
  Boolean domainInitialized = false;
  if (runtimeType == nullptr) {
    return RuntimeFieldHandle::GetValue((RtFieldInfo)this, obj, fieldType, nullptr, domainInitialized);
  }
  domainInitialized = runtimeType->set_DomainInitialized();
  Object value = RuntimeFieldHandle::GetValue((RtFieldInfo)this, obj, fieldType, runtimeType, domainInitialized);
  runtimeType->set_DomainInitialized(domainInitialized);
  return value;
}

Object RtFieldInfo___::GetRawConstantValue() {
  rt::throw_exception<InvalidOperationException>();
}

Object RtFieldInfo___::GetValueDirect(TypedReference obj) {
  if (obj.get_IsNull()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_TypedReference_Null());
  }
  return RuntimeFieldHandle::GetValueDirect((RtFieldInfo)this, (RuntimeType)get_FieldType(), &obj, (RuntimeType)get_DeclaringType());
}

void RtFieldInfo___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
  INVOCATION_FLAGS invocationFlags = get_InvocationFlags();
  RuntimeType runtimeType = rt::as<RuntimeType>(get_DeclaringType());
  if ((invocationFlags & INVOCATION_FLAGS::INVOCATION_FLAGS_NO_INVOKE) != 0) {
    if (runtimeType != nullptr && runtimeType->get_ContainsGenericParameters()) {
      rt::throw_exception<InvalidOperationException>(SR::get_Arg_UnboundGenField());
    }
    rt::throw_exception<FieldAccessException>();
  }
  CheckConsistency(obj);
  RuntimeType runtimeType2 = (RuntimeType)get_FieldType();
  value = runtimeType2->CheckValue(value, binder, culture, invokeAttr);
  Boolean domainInitialized = false;
  if (runtimeType == nullptr) {
    RuntimeFieldHandle::SetValue((RtFieldInfo)this, obj, value, runtimeType2, m_fieldAttributes, nullptr, domainInitialized);
    return;
  }
  domainInitialized = runtimeType->set_DomainInitialized();
  RuntimeFieldHandle::SetValue((RtFieldInfo)this, obj, value, runtimeType2, m_fieldAttributes, runtimeType, domainInitialized);
  runtimeType->set_DomainInitialized(domainInitialized);
}

void RtFieldInfo___::SetValueDirect(TypedReference obj, Object value) {
  if (obj.get_IsNull()) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_TypedReference_Null());
  }
  RuntimeFieldHandle::SetValueDirect((RtFieldInfo)this, (RuntimeType)get_FieldType(), &obj, value, (RuntimeType)get_DeclaringType());
}

IntPtr RtFieldInfo___::GetFieldHandle() {
  return m_fieldHandle;
}

RuntimeType RtFieldInfo___::InitializeFieldType() {
  return m_fieldType = rt::newobj<Signature>((RtFieldInfo)this, m_declaringType)->get_FieldType();
}

Array<Type> RtFieldInfo___::GetRequiredCustomModifiers() {
  return rt::newobj<Signature>((RtFieldInfo)this, m_declaringType)->GetCustomModifiers(1, true);
}

Array<Type> RtFieldInfo___::GetOptionalCustomModifiers() {
  return rt::newobj<Signature>((RtFieldInfo)this, m_declaringType)->GetCustomModifiers(1, false);
}

} // namespace System::Private::CoreLib::System::Reflection::RtFieldInfoNamespace
