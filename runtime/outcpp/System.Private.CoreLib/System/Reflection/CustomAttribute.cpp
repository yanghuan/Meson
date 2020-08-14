#include "CustomAttribute-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/AttributeUsageAttribute-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/Reflection/ConstArray-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeData-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeRecord-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/PseudoCustomAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Reflection/TypeAttributes.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallTypeHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandle-dep.h>
#include <System.Private.CoreLib/System/RuntimeMethodHandleInternal-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamespace {
using namespace System::Runtime::CompilerServices;

Boolean CustomAttribute::IsDefined(RuntimeType type, RuntimeType caType, Boolean inherit) {
  if (type->GetElementType() != nullptr) {
    return false;
  }
  if (PseudoCustomAttribute::IsDefined(type, caType)) {
    return true;
  }
  if (IsCustomAttributeDefined(type->GetRuntimeModule(), type->get_MetadataToken(), caType)) {
    return true;
  }
  if (!inherit) {
    return false;
  }
  type = (rt::as<RuntimeType>(type->get_BaseType()));
  while (type != nullptr) {
    if (IsCustomAttributeDefined(type->GetRuntimeModule(), type->get_MetadataToken(), caType, 0, inherit)) {
      return true;
    }
    type = (rt::as<RuntimeType>(type->get_BaseType()));
  }
  return false;
}

Boolean CustomAttribute::IsDefined(RuntimeMethodInfo method, RuntimeType caType, Boolean inherit) {
  if (PseudoCustomAttribute::IsDefined(method, caType)) {
    return true;
  }
  if (IsCustomAttributeDefined(method->GetRuntimeModule(), method->get_MetadataToken(), caType)) {
    return true;
  }
  if (!inherit) {
    return false;
  }
  method = method->GetParentDefinition();
  while (method != nullptr) {
    if (IsCustomAttributeDefined(method->GetRuntimeModule(), method->get_MetadataToken(), caType, 0, inherit)) {
      return true;
    }
    method = method->GetParentDefinition();
  }
  return false;
}

Boolean CustomAttribute::IsDefined(RuntimeConstructorInfo ctor, RuntimeType caType) {
  return IsCustomAttributeDefined(ctor->GetRuntimeModule(), ctor->get_MetadataToken(), caType);
}

Boolean CustomAttribute::IsDefined(RuntimePropertyInfo property, RuntimeType caType) {
  return IsCustomAttributeDefined(property->GetRuntimeModule(), property->get_MetadataToken(), caType);
}

Boolean CustomAttribute::IsDefined(RuntimeEventInfo e, RuntimeType caType) {
  return IsCustomAttributeDefined(e->GetRuntimeModule(), e->get_MetadataToken(), caType);
}

Boolean CustomAttribute::IsDefined(RuntimeFieldInfo field, RuntimeType caType) {
  if (PseudoCustomAttribute::IsDefined(field, caType)) {
    return true;
  }
  return IsCustomAttributeDefined(field->GetRuntimeModule(), field->get_MetadataToken(), caType);
}

Boolean CustomAttribute::IsDefined(RuntimeParameterInfo parameter, RuntimeType caType) {
  if (PseudoCustomAttribute::IsDefined(parameter, caType)) {
    return true;
  }
  return IsCustomAttributeDefined(parameter->GetRuntimeModule(), parameter->get_MetadataToken(), caType);
}

Boolean CustomAttribute::IsDefined(RuntimeAssembly assembly, RuntimeType caType) {
  return IsCustomAttributeDefined(rt::as<RuntimeModule>(assembly->get_ManifestModule()), RuntimeAssembly::in::GetToken(assembly->GetNativeHandle()), caType);
}

Boolean CustomAttribute::IsDefined(RuntimeModule module, RuntimeType caType) {
  return IsCustomAttributeDefined(module, module->get_MetadataToken(), caType);
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeType type, RuntimeType caType, Boolean inherit) {
  if (type->GetElementType() != nullptr) {
    if (!caType->get_IsValueType()) {
      return CreateAttributeArrayHelper(caType, 0);
    }
    return Array<>::in::Empty<Object>();
  }
  if (type->get_IsGenericType() && !type->get_IsGenericTypeDefinition()) {
    type = (rt::as<RuntimeType>(type->GetGenericTypeDefinition()));
  }
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, Boolean inherit) {
  if (method->get_IsGenericMethod() && !method->get_IsGenericMethodDefinition()) {
    method = (rt::as<RuntimeMethodInfo>(method->GetGenericMethodDefinition()));
  }
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeConstructorInfo ctor, RuntimeType caType) {
  return GetCustomAttributes(ctor->GetRuntimeModule(), ctor->get_MetadataToken(), 0, caType);
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimePropertyInfo property, RuntimeType caType) {
  return GetCustomAttributes(property->GetRuntimeModule(), property->get_MetadataToken(), 0, caType);
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeEventInfo e, RuntimeType caType) {
  return GetCustomAttributes(e->GetRuntimeModule(), e->get_MetadataToken(), 0, caType);
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType) {
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType) {
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeAssembly assembly, RuntimeType caType) {
  Int32 token = RuntimeAssembly::in::GetToken(assembly->GetNativeHandle());
  return GetCustomAttributes(rt::as<RuntimeModule>(assembly->get_ManifestModule()), token, 0, caType);
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeModule module, RuntimeType caType) {
  return GetCustomAttributes(module, module->get_MetadataToken(), 0, caType);
}

Boolean CustomAttribute::IsCustomAttributeDefined(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType) {
  return IsCustomAttributeDefined(decoratedModule, decoratedMetadataToken, attributeFilterType, 0, false);
}

Boolean CustomAttribute::IsCustomAttributeDefined(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType, Int32 attributeCtorToken, Boolean mustBeInheritable) {
  Array<CustomAttributeRecord> customAttributeRecords = CustomAttributeData::in::GetCustomAttributeRecords(decoratedModule, decoratedMetadataToken);
  if (attributeFilterType != nullptr) {
    MetadataImport scope = decoratedModule->get_MetadataImport();
    RuntimeType::in::ListBuilder<T> derivedAttributes = RuntimeType::in::ListBuilder<T>();
    for (Int32 i = 0; i < customAttributeRecords->get_Length(); i++) {
    }
  } else {
    for (Int32 j = 0; j < customAttributeRecords->get_Length(); j++) {
      if ((Int32)customAttributeRecords[j].tkCtor == attributeCtorToken) {
        return true;
      }
    }
  }
  return false;
}

Array<Object> CustomAttribute::GetCustomAttributes(RuntimeModule decoratedModule, Int32 decoratedMetadataToken, Int32 pcaCount, RuntimeType attributeFilterType) {
  RuntimeType::in::ListBuilder<T> attributes = RuntimeType::in::ListBuilder<T>();
  AddCustomAttributes(attributes, decoratedModule, decoratedMetadataToken, attributeFilterType, false, RuntimeType::in::ListBuilder<T>());
}

void CustomAttribute::AddCustomAttributes(RuntimeType::in::ListBuilder<Object>& attributes, RuntimeModule decoratedModule, Int32 decoratedMetadataToken, RuntimeType attributeFilterType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object> derivedAttributes) {
  Array<CustomAttributeRecord> customAttributeRecords = CustomAttributeData::in::GetCustomAttributeRecords(decoratedModule, decoratedMetadataToken);
  if ((Object)attributeFilterType == nullptr && customAttributeRecords->get_Length() == 0) {
    return;
  }
  MetadataImport scope = decoratedModule->get_MetadataImport();
  for (Int32 i = 0; i < customAttributeRecords->get_Length(); i++) {
    CustomAttributeRecord& reference = customAttributeRecords[i];
    IntPtr blob = reference.blob.get_Signature();
    IntPtr intPtr = (IntPtr)(void*)((Byte*)(void*)blob + reference.blob.get_Length());
  }
}

Boolean CustomAttribute::FilterCustomAttributeRecord(MetadataToken caCtorToken, MetadataImport& scope, RuntimeModule decoratedModule, MetadataToken decoratedToken, RuntimeType attributeFilterType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object>& derivedAttributes, RuntimeType& attributeType, IRuntimeMethodInfo& ctorWithParameters, Boolean& isVarArg) {
  ctorWithParameters = nullptr;
  isVarArg = false;
  attributeType = (rt::as<RuntimeType>(decoratedModule->ResolveType(scope.GetParentToken(caCtorToken), nullptr, nullptr)));
  if (!attributeFilterType->IsAssignableFrom(attributeType)) {
    return false;
  }
  if (!AttributeUsageCheck(attributeType, mustBeInheritable, derivedAttributes)) {
    return false;
  }
  if ((attributeType->get_Attributes() & TypeAttributes::WindowsRuntime) == TypeAttributes::WindowsRuntime) {
    return false;
  }
  ConstArray methodSignature = scope.GetMethodSignature(caCtorToken);
  isVarArg = ((methodSignature[0] & 5) != 0);
  if (methodSignature[1] != 0) {
    if (attributeType->get_IsGenericType()) {
      ctorWithParameters = decoratedModule->ResolveMethod(caCtorToken, attributeType->get_GenericTypeArguments(), nullptr)->get_MethodHandle().GetMethodInfo();
    } else {
      ctorWithParameters = ModuleHandle::ResolveMethodHandleInternal(decoratedModule->GetNativeHandle(), caCtorToken);
    }
  }
  MetadataToken token = MetadataToken();
  if (decoratedToken.get_IsParamDef()) {
    token = MetadataToken(scope.GetParentToken(decoratedToken));
    token = MetadataToken(scope.GetParentToken(token));
  } else if (decoratedToken.get_IsMethodDef() || decoratedToken.get_IsProperty() || decoratedToken.get_IsEvent() || decoratedToken.get_IsFieldDef()) {
    token = MetadataToken(scope.GetParentToken(decoratedToken));
  } else if (decoratedToken.get_IsTypeDef()) {
    token = decoratedToken;
  } else if (decoratedToken.get_IsGenericPar()) {
    token = MetadataToken(scope.GetParentToken(decoratedToken));
    if (token.get_IsMethodDef()) {
      token = MetadataToken(scope.GetParentToken(token));
    }
  }



  RuntimeTypeHandle rth = token.get_IsTypeDef() ? decoratedModule->get_ModuleHandle().ResolveTypeHandle(token) : RuntimeTypeHandle();
  RuntimeTypeHandle rth2 = attributeType->get_TypeHandle();
  Boolean result = RuntimeMethodHandle::IsCAVisibleFromDecoratedType(QCallTypeHandle(rth2), (ctorWithParameters != nullptr) ? ctorWithParameters->get_Value() : RuntimeMethodHandleInternal::get_EmptyHandle(), QCallTypeHandle(rth), QCallModule(decoratedModule)) != Interop::BOOL::FALSE;
  GC::KeepAlive(ctorWithParameters);
  return result;
}

Boolean CustomAttribute::AttributeUsageCheck(RuntimeType attributeType, Boolean mustBeInheritable, RuntimeType::in::ListBuilder<Object>& derivedAttributes) {
  AttributeUsageAttribute attributeUsageAttribute = nullptr;
  if (mustBeInheritable) {
    attributeUsageAttribute = GetAttributeUsage(attributeType);
    if (!attributeUsageAttribute->get_Inherited()) {
      return false;
    }
  }
  if (derivedAttributes.get_Count() == 0) {
    return true;
  }
  for (Int32 i = 0; i < derivedAttributes.get_Count(); i++) {
    if (derivedAttributes[i]->GetType() == attributeType) {
      if (attributeUsageAttribute == nullptr) {
        attributeUsageAttribute = GetAttributeUsage(attributeType);
      }
      return attributeUsageAttribute->get_AllowMultiple();
    }
  }
  return true;
}

AttributeUsageAttribute CustomAttribute::GetAttributeUsage(RuntimeType decoratedAttribute) {
  RuntimeModule runtimeModule = decoratedAttribute->GetRuntimeModule();
  MetadataImport metadataImport = runtimeModule->get_MetadataImport();
  Array<CustomAttributeRecord> customAttributeRecords = CustomAttributeData::in::GetCustomAttributeRecords(runtimeModule, decoratedAttribute->get_MetadataToken());
  AttributeUsageAttribute attributeUsageAttribute = nullptr;
  for (Int32 i = 0; i < customAttributeRecords->get_Length(); i++) {
    CustomAttributeRecord& reference = customAttributeRecords[i];
    RuntimeType runtimeType = rt::as<RuntimeType>(runtimeModule->ResolveType(metadataImport.GetParentToken(reference.tkCtor), nullptr, nullptr));
  }
}

void CustomAttribute::ParseAttributeUsageAttribute(ConstArray ca, AttributeTargets& targets, Boolean& inherited, Boolean& allowMultiple) {
}

Object CustomAttribute::CreateCaObject(RuntimeModule module, RuntimeType type, IRuntimeMethodInfo ctor, IntPtr& blob, IntPtr blobEnd, Int32& namedArgs) {
  Byte* value = (Byte*)(void*)blob;
  Byte* pEndBlob = (Byte*)(void*)blobEnd;
  Int32 num;
  Object result = _CreateCaObject(module, type, ctor, &value, pEndBlob, &num);
  blob = (IntPtr)(void*)value;
  namedArgs = num;
  return result;
}

void CustomAttribute::GetPropertyOrFieldData(RuntimeModule module, IntPtr& blobStart, IntPtr blobEnd, String& name, Boolean& isProperty, RuntimeType& type, Object& value) {
  Byte* value2 = (Byte*)(void*)blobStart;
  _GetPropertyOrFieldData(module->GetNativeHandle(), &value2, (Byte*)(void*)blobEnd, name, isProperty, type, value);
  blobStart = (IntPtr)(void*)value2;
}

Array<Object> CustomAttribute::CreateAttributeArrayHelper(RuntimeType elementType, Int32 elementCount) {
  if (elementCount == 0) {
    return elementType->GetEmptyArray();
  }
  return (Array<Object>)Array<>::in::CreateInstance(elementType, elementCount);
}

void CustomAttribute::cctor() {
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeNamespace
