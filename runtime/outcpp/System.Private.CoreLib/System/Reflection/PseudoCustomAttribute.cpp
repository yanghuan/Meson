#include "PseudoCustomAttribute-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/ModuleHandle-dep.h>
#include <System.Private.CoreLib/System/NonSerializedAttribute-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/ConstArray-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldAttributes.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
#include <System.Private.CoreLib/System/Reflection/MethodImplAttributes.h>
#include <System.Private.CoreLib/System/Reflection/PInvokeAttributes.h>
#include <System.Private.CoreLib/System/Reflection/TypeAttributes.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CallingConvention.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CharSet.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComImportAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/DllImportAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/FieldOffsetAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/InAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/LayoutKind.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MarshalAsAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/OptionalAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/OutAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/PreserveSigAttribute-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/UnmanagedType.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/VarEnum.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SerializableAttribute-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/TypeLoadException-dep.h>

namespace System::Private::CoreLib::System::Reflection::PseudoCustomAttributeNamespace {
using namespace System::Runtime::InteropServices;

Dictionary<RuntimeType, RuntimeType> PseudoCustomAttribute::CreatePseudoCustomAttributeDictionary() {
  Array<Type> array = rt::newarr<Array<Type>>(11);
  Dictionary<RuntimeType, RuntimeType> dictionary = rt::newobj<Dictionary<RuntimeType, RuntimeType>>(array->get_Length());
  Array<Type> array2 = array;
  for (Int32 i = 0; i < array2->get_Length(); i++) {
    RuntimeType runtimeType = (RuntimeType)array2[i];
    dictionary[runtimeType] = runtimeType;
  }
  return dictionary;
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeType type, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = rt::default__;
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (flag || s_pca->ContainsKey(caType)) {
    if ((flag || caType == typeof<SerializableAttribute>()) && (type->get_Attributes() & TypeAttributes::Serializable) != 0) {
      pcas.Add(rt::newobj<SerializableAttribute>());
    }
    if ((flag || caType == typeof<ComImportAttribute>()) && (type->get_Attributes() & TypeAttributes::Import) != 0) {
      pcas.Add(rt::newobj<ComImportAttribute>());
    }
  }
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeType type, RuntimeType caType) {
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return false;
  }
  if ((flag || caType == typeof<SerializableAttribute>()) && (type->get_Attributes() & TypeAttributes::Serializable) != 0) {
    return true;
  }
  if ((flag || caType == typeof<ComImportAttribute>()) && (type->get_Attributes() & TypeAttributes::Import) != 0) {
    return true;
  }
  return false;
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeMethodInfo method, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = rt::default__;
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return;
  }
  if (flag || caType == typeof<DllImportAttribute>()) {
    Attribute dllImportCustomAttribute = GetDllImportCustomAttribute(method);
    if (dllImportCustomAttribute != nullptr) {
      pcas.Add(dllImportCustomAttribute);
    }
  }
  if ((flag || caType == typeof<PreserveSigAttribute>()) && (method->GetMethodImplementationFlags() & MethodImplAttributes::PreserveSig) != 0) {
    pcas.Add(rt::newobj<PreserveSigAttribute>());
  }
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeMethodInfo method, RuntimeType caType) {
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return false;
  }
  if ((flag || caType == typeof<DllImportAttribute>()) && (method->get_Attributes() & MethodAttributes::PinvokeImpl) != 0) {
    return true;
  }
  if ((flag || caType == typeof<PreserveSigAttribute>()) && (method->GetMethodImplementationFlags() & MethodImplAttributes::PreserveSig) != 0) {
    return true;
  }
  return false;
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeParameterInfo parameter, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = rt::default__;
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return;
  }
  if ((flag || caType == typeof<InAttribute>()) && parameter->get_IsIn()) {
    pcas.Add(rt::newobj<InAttribute>());
  }
  if ((flag || caType == typeof<OutAttribute>()) && parameter->get_IsOut()) {
    pcas.Add(rt::newobj<OutAttribute>());
  }
  if ((flag || caType == typeof<OptionalAttribute>()) && parameter->get_IsOptional()) {
    pcas.Add(rt::newobj<OptionalAttribute>());
  }
  if (flag || caType == typeof<MarshalAsAttribute>()) {
    Attribute marshalAsCustomAttribute = GetMarshalAsCustomAttribute(parameter);
    if (marshalAsCustomAttribute != nullptr) {
      pcas.Add(marshalAsCustomAttribute);
    }
  }
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeParameterInfo parameter, RuntimeType caType) {
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return false;
  }
  if ((flag || caType == typeof<InAttribute>()) && parameter->get_IsIn()) {
    return true;
  }
  if ((flag || caType == typeof<OutAttribute>()) && parameter->get_IsOut()) {
    return true;
  }
  if ((flag || caType == typeof<OptionalAttribute>()) && parameter->get_IsOptional()) {
    return true;
  }
  if ((flag || caType == typeof<MarshalAsAttribute>()) && GetMarshalAsCustomAttribute(parameter) != nullptr) {
    return true;
  }
  return false;
}

void PseudoCustomAttribute::GetCustomAttributes(RuntimeFieldInfo field, RuntimeType caType, RuntimeType::in::ListBuilder<Attribute>& pcas) {
  pcas = rt::default__;
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return;
  }
  if (flag || caType == typeof<MarshalAsAttribute>()) {
    Attribute marshalAsCustomAttribute = GetMarshalAsCustomAttribute(field);
    if (marshalAsCustomAttribute != nullptr) {
      pcas.Add(marshalAsCustomAttribute);
    }
  }
  if (flag || caType == typeof<FieldOffsetAttribute>()) {
    Attribute marshalAsCustomAttribute = GetFieldOffsetCustomAttribute(field);
    if (marshalAsCustomAttribute != nullptr) {
      pcas.Add(marshalAsCustomAttribute);
    }
  }
  if ((flag || caType == typeof<NonSerializedAttribute>()) && (field->get_Attributes() & FieldAttributes::NotSerialized) != 0) {
    pcas.Add(rt::newobj<NonSerializedAttribute>());
  }
}

Boolean PseudoCustomAttribute::IsDefined(RuntimeFieldInfo field, RuntimeType caType) {
  Boolean flag = caType == typeof<Object>() || caType == typeof<Attribute>();
  if (!flag && !s_pca->ContainsKey(caType)) {
    return false;
  }
  if ((flag || caType == typeof<MarshalAsAttribute>()) && GetMarshalAsCustomAttribute(field) != nullptr) {
    return true;
  }
  if ((flag || caType == typeof<FieldOffsetAttribute>()) && GetFieldOffsetCustomAttribute(field) != nullptr) {
    return true;
  }
  if ((flag || caType == typeof<NonSerializedAttribute>()) && (field->get_Attributes() & FieldAttributes::NotSerialized) != 0) {
    return true;
  }
  return false;
}

DllImportAttribute PseudoCustomAttribute::GetDllImportCustomAttribute(RuntimeMethodInfo method) {
  if ((method->get_Attributes() & MethodAttributes::PinvokeImpl) == 0) {
    return nullptr;
  }
  MetadataImport metadataImport = ModuleHandle::GetMetadataImport(method->get_Module()->get_ModuleHandle().GetRuntimeModule());
  Int32 metadataToken = method->get_MetadataToken();
  PInvokeAttributes attributes;
  String importName;
  String importDll;
  metadataImport.GetPInvokeMap(metadataToken, attributes, importName, importDll);
  CharSet charSet = CharSet::None;
  switch (attributes & PInvokeAttributes::CharSetMask) {
    case PInvokeAttributes::CharSetNotSpec:
      charSet = CharSet::None;
      break;
    case PInvokeAttributes::CharSetAnsi:
      charSet = CharSet::Ansi;
      break;
    case PInvokeAttributes::CharSetUnicode:
      charSet = CharSet::Unicode;
      break;
    case PInvokeAttributes::CharSetMask:
      charSet = CharSet::Auto;
      break;
  }
  CallingConvention callingConvention = CallingConvention::Cdecl;
  switch (attributes & PInvokeAttributes::CallConvMask) {
    case PInvokeAttributes::CallConvWinapi:
      callingConvention = CallingConvention::Winapi;
      break;
    case PInvokeAttributes::CallConvCdecl:
      callingConvention = CallingConvention::Cdecl;
      break;
    case PInvokeAttributes::CallConvStdcall:
      callingConvention = CallingConvention::StdCall;
      break;
    case PInvokeAttributes::CallConvThiscall:
      callingConvention = CallingConvention::ThisCall;
      break;
    case PInvokeAttributes::CallConvFastcall:
      callingConvention = CallingConvention::FastCall;
      break;
  }
  DllImportAttribute dllImportAttribute = rt::newobj<DllImportAttribute>(importDll);
  dllImportAttribute->EntryPoint = importName;
  dllImportAttribute->CharSet = charSet;
  dllImportAttribute->SetLastError = ((attributes & PInvokeAttributes::SupportsLastError) != 0);
  dllImportAttribute->ExactSpelling = ((attributes & PInvokeAttributes::NoMangle) != 0);
  dllImportAttribute->PreserveSig = ((method->GetMethodImplementationFlags() & MethodImplAttributes::PreserveSig) != 0);
  dllImportAttribute->CallingConvention = callingConvention;
  dllImportAttribute->BestFitMapping = ((attributes & PInvokeAttributes::BestFitMask) == PInvokeAttributes::BestFitEnabled);
  dllImportAttribute->ThrowOnUnmappableChar = ((attributes & PInvokeAttributes::ThrowOnUnmappableCharMask) == PInvokeAttributes::ThrowOnUnmappableCharEnabled);
  return dllImportAttribute;
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(RuntimeParameterInfo parameter) {
  return GetMarshalAsCustomAttribute(parameter->get_MetadataToken(), parameter->GetRuntimeModule());
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(RuntimeFieldInfo field) {
  return GetMarshalAsCustomAttribute(field->get_MetadataToken(), field->GetRuntimeModule());
}

MarshalAsAttribute PseudoCustomAttribute::GetMarshalAsCustomAttribute(Int32 token, RuntimeModule scope) {
  ConstArray fieldMarshal = ModuleHandle::GetMetadataImport(scope->GetNativeHandle()).GetFieldMarshal(token);
  if (fieldMarshal.get_Length() == 0) {
    return nullptr;
  }
  UnmanagedType unmanagedType;
  VarEnum safeArraySubType;
  String safeArrayUserDefinedSubType;
  UnmanagedType arraySubType;
  Int32 sizeParamIndex;
  Int32 sizeConst;
  String marshalType;
  String marshalCookie;
  Int32 iidParamIndex;
  MetadataImport::GetMarshalAs(fieldMarshal, unmanagedType, safeArraySubType, safeArrayUserDefinedSubType, arraySubType, sizeParamIndex, sizeConst, marshalType, marshalCookie, iidParamIndex);
  RuntimeType safeArrayUserDefinedSubType2 = String::in::IsNullOrEmpty(safeArrayUserDefinedSubType) ? nullptr : RuntimeTypeHandle::GetTypeByNameUsingCARules(safeArrayUserDefinedSubType, scope);
  RuntimeType marshalTypeRef = nullptr;
  try {
    marshalTypeRef = ((marshalType == nullptr) ? nullptr : RuntimeTypeHandle::GetTypeByNameUsingCARules(marshalType, scope));
  } catch (TypeLoadException) {
  }
  MarshalAsAttribute marshalAsAttribute = rt::newobj<MarshalAsAttribute>(unmanagedType);
  marshalAsAttribute->SafeArraySubType = safeArraySubType;
  marshalAsAttribute->SafeArrayUserDefinedSubType = safeArrayUserDefinedSubType2;
  marshalAsAttribute->IidParameterIndex = iidParamIndex;
  marshalAsAttribute->ArraySubType = arraySubType;
  marshalAsAttribute->SizeParamIndex = (Int16)sizeParamIndex;
  marshalAsAttribute->SizeConst = sizeConst;
  marshalAsAttribute->MarshalType = marshalType;
  marshalAsAttribute->MarshalTypeRef = marshalTypeRef;
  marshalAsAttribute->MarshalCookie = marshalCookie;
  return marshalAsAttribute;
}

FieldOffsetAttribute PseudoCustomAttribute::GetFieldOffsetCustomAttribute(RuntimeFieldInfo field) {
  Int32 offset;
  if (field->get_DeclaringType() != nullptr && field->GetRuntimeModule()->get_MetadataImport().GetFieldOffset(field->get_DeclaringType()->get_MetadataToken(), field->get_MetadataToken(), offset)) {
    return rt::newobj<FieldOffsetAttribute>(offset);
  }
  return nullptr;
}

StructLayoutAttribute PseudoCustomAttribute::GetStructLayoutCustomAttribute(RuntimeType type) {
  if (type->get_IsInterface() || type->get_HasElementType() || type->get_IsGenericParameter()) {
    return nullptr;
  }
  LayoutKind layoutKind = LayoutKind::Auto;
  switch (type->get_Attributes() & TypeAttributes::LayoutMask) {
    case TypeAttributes::ExplicitLayout:
      layoutKind = LayoutKind::Explicit;
      break;
    case TypeAttributes::NotPublic:
      layoutKind = LayoutKind::Auto;
      break;
    case TypeAttributes::SequentialLayout:
      layoutKind = LayoutKind::Sequential;
      break;
  }
  CharSet charSet = CharSet::None;
  switch (type->get_Attributes() & TypeAttributes::StringFormatMask) {
    case TypeAttributes::NotPublic:
      charSet = CharSet::Ansi;
      break;
    case TypeAttributes::AutoClass:
      charSet = CharSet::Auto;
      break;
    case TypeAttributes::UnicodeClass:
      charSet = CharSet::Unicode;
      break;
  }
  Int32 packSize;
  Int32 classSize;
  type->GetRuntimeModule()->get_MetadataImport().GetClassLayout(type->get_MetadataToken(), packSize, classSize);
  if (packSize == 0) {
    packSize = 8;
  }
  StructLayoutAttribute structLayoutAttribute = rt::newobj<StructLayoutAttribute>(layoutKind);
  structLayoutAttribute->Pack = packSize;
  structLayoutAttribute->Size = classSize;
  structLayoutAttribute->CharSet = charSet;
  return structLayoutAttribute;
}

void PseudoCustomAttribute::cctor() {
  s_pca = CreatePseudoCustomAttributeDictionary();
}

} // namespace System::Private::CoreLib::System::Reflection::PseudoCustomAttributeNamespace
