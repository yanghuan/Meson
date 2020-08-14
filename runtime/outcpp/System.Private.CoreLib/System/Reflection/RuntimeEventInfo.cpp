#include "RuntimeEventInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Associates-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeEventInfo-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeEventInfoNamespace {
using namespace System::Collections::Generic;

BindingFlags RuntimeEventInfo___::get_BindingFlags() {
  return m_bindingFlags;
}

MemberTypes RuntimeEventInfo___::get_MemberType() {
  return MemberTypes::Event;
}

String RuntimeEventInfo___::get_Name() {
}

Type RuntimeEventInfo___::get_DeclaringType() {
  return m_declaringType;
}

Type RuntimeEventInfo___::get_ReflectedType() {
  return get_ReflectedTypeInternal();
}

RuntimeType RuntimeEventInfo___::get_ReflectedTypeInternal() {
  return m_reflectedTypeCache->GetRuntimeType();
}

Int32 RuntimeEventInfo___::get_MetadataToken() {
  return m_token;
}

Module RuntimeEventInfo___::get_Module() {
  return GetRuntimeModule();
}

EventAttributes RuntimeEventInfo___::get_Attributes() {
  return m_flags;
}

void RuntimeEventInfo___::ctor(Int32 tkEvent, RuntimeType declaredType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, Boolean& isPrivate) {
  MetadataImport metadataImport = declaredType->GetRuntimeModule()->get_MetadataImport();
  m_token = tkEvent;
  m_reflectedTypeCache = reflectedTypeCache;
  m_declaringType = declaredType;
  RuntimeType runtimeType = reflectedTypeCache->GetRuntimeType();
  metadataImport.GetEventProps(tkEvent, m_utf8name, m_flags);
}

Boolean RuntimeEventInfo___::CacheEquals(Object o) {
  RuntimeEventInfo runtimeEventInfo = rt::as<RuntimeEventInfo>(o);
  if ((Object)runtimeEventInfo != nullptr && runtimeEventInfo->m_token == m_token) {
    return RuntimeTypeHandle::GetModule(m_declaringType)->Equals(RuntimeTypeHandle::GetModule(runtimeEventInfo->m_declaringType));
  }
  return false;
}

String RuntimeEventInfo___::ToString() {
  if (m_addMethod == nullptr || m_addMethod->GetParametersNoCopy()->get_Length() == 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NoPublicAddMethod());
  }
  return m_addMethod->GetParametersNoCopy()[0]->get_ParameterType()->FormatTypeName() + " " + get_Name();
}

Array<Object> RuntimeEventInfo___::GetCustomAttributes(Boolean inherit) {
}

Array<Object> RuntimeEventInfo___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::GetCustomAttributes((RuntimeEventInfo)this, runtimeType);
}

Boolean RuntimeEventInfo___::IsDefined(Type attributeType, Boolean inherit) {
  if (attributeType == nullptr) {
    rt::throw_exception<ArgumentNullException>("attributeType");
  }
  RuntimeType runtimeType = rt::as<RuntimeType>(attributeType->get_UnderlyingSystemType());
  if (runtimeType == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "attributeType");
  }
  return CustomAttribute::IsDefined((RuntimeEventInfo)this, runtimeType);
}

IList<CustomAttributeData> RuntimeEventInfo___::GetCustomAttributesData() {
  return CustomAttributeData::in::GetCustomAttributesInternal((RuntimeEventInfo)this);
}

Boolean RuntimeEventInfo___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return HasSameMetadataDefinitionAsCore<RuntimeEventInfo>(other);
}

RuntimeModule RuntimeEventInfo___::GetRuntimeModule() {
  return m_declaringType->GetRuntimeModule();
}

Array<MethodInfo> RuntimeEventInfo___::GetOtherMethods(Boolean nonPublic) {
  List<MethodInfo> list = rt::newobj<List<MethodInfo>>();
  if (m_otherMethod == nullptr) {
    return Array<>::in::Empty<MethodInfo>();
  }
  for (Int32 i = 0; i < m_otherMethod->get_Length(); i++) {
    if (Associates::IncludeAccessor(m_otherMethod[i], nonPublic)) {
      list->Add(m_otherMethod[i]);
    }
  }
  return list->ToArray();
}

MethodInfo RuntimeEventInfo___::GetAddMethod(Boolean nonPublic) {
  if (!Associates::IncludeAccessor(m_addMethod, nonPublic)) {
    return nullptr;
  }
  return m_addMethod;
}

MethodInfo RuntimeEventInfo___::GetRemoveMethod(Boolean nonPublic) {
  if (!Associates::IncludeAccessor(m_removeMethod, nonPublic)) {
    return nullptr;
  }
  return m_removeMethod;
}

MethodInfo RuntimeEventInfo___::GetRaiseMethod(Boolean nonPublic) {
  if (!Associates::IncludeAccessor(m_raiseMethod, nonPublic)) {
    return nullptr;
  }
  return m_raiseMethod;
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeEventInfoNamespace
