#include "MetadataImport-dep.h"

#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataException-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataImport-dep.h>

namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace {
Int32 MetadataImport::GetHashCode() {
  return ValueType::in::GetHashCodeOfPtr(m_metadataImport2);
}

Boolean MetadataImport::Equals(Object obj) {
  if (!rt::is<MetadataImport>(obj)) {
    return false;
  }
  return Equals((MetadataImport)obj);
}

Boolean MetadataImport::Equals(MetadataImport import) {
  return import.m_metadataImport2 == m_metadataImport2;
}

void MetadataImport::GetMarshalAs(ConstArray nativeType, UnmanagedType& unmanagedType, VarEnum& safeArraySubType, String& safeArrayUserDefinedSubType, UnmanagedType& arraySubType, Int32& sizeParamIndex, Int32& sizeConst, String& marshalType, String& marshalCookie, Int32& iidParamIndex) {
  Int32 unmanagedType2;
  Int32 safeArraySubType2;
  Int32 arraySubType2;
  _GetMarshalAs(nativeType.get_Signature(), nativeType.get_Length(), unmanagedType2, safeArraySubType2, safeArrayUserDefinedSubType, arraySubType2, sizeParamIndex, sizeConst, marshalType, marshalCookie, iidParamIndex);
  unmanagedType = (UnmanagedType)unmanagedType2;
  safeArraySubType = (VarEnum)safeArraySubType2;
  arraySubType = (UnmanagedType)arraySubType2;
}

void MetadataImport::ThrowError(Int32 hResult) {
  rt::throw_exception<MetadataException>(hResult);
}

MetadataImport::MetadataImport(IntPtr metadataImport2, Object keepalive) {
  m_metadataImport2 = metadataImport2;
  m_keepalive = keepalive;
}

void MetadataImport::Enum(MetadataTokenType type, Int32 parent, MetadataEnumResult& result) {
  _Enum(m_metadataImport2, (Int32)type, parent, result);
}

void MetadataImport::EnumNestedTypes(Int32 mdTypeDef, MetadataEnumResult& result) {
  Enum(MetadataTokenType::TypeDef, mdTypeDef, result);
}

void MetadataImport::EnumCustomAttributes(Int32 mdToken, MetadataEnumResult& result) {
  Enum(MetadataTokenType::CustomAttribute, mdToken, result);
}

void MetadataImport::EnumParams(Int32 mdMethodDef, MetadataEnumResult& result) {
  Enum(MetadataTokenType::ParamDef, mdMethodDef, result);
}

void MetadataImport::EnumFields(Int32 mdTypeDef, MetadataEnumResult& result) {
  Enum(MetadataTokenType::FieldDef, mdTypeDef, result);
}

void MetadataImport::EnumProperties(Int32 mdTypeDef, MetadataEnumResult& result) {
  Enum(MetadataTokenType::Property, mdTypeDef, result);
}

void MetadataImport::EnumEvents(Int32 mdTypeDef, MetadataEnumResult& result) {
  Enum(MetadataTokenType::Event, mdTypeDef, result);
}

String MetadataImport::GetDefaultValue(Int32 mdToken, Int64& value, Int32& length, CorElementType& corElementType) {
  Int32 corElementType2;
  String result = _GetDefaultValue(m_metadataImport2, mdToken, value, length, corElementType2);
  corElementType = (CorElementType)corElementType2;
  return result;
}

String MetadataImport::GetUserString(Int32 mdToken) {
  void* ptr;
  Int32 length;
  _GetUserString(m_metadataImport2, mdToken, &ptr, length);
  if (ptr == nullptr) {
    return nullptr;
  }
  return rt::newobj<String>((Char*)ptr, 0, length);
}

MdUtf8String MetadataImport::GetName(Int32 mdToken) {
  void* pStringHeap;
  _GetName(m_metadataImport2, mdToken, &pStringHeap);
  return MdUtf8String(pStringHeap);
}

MdUtf8String MetadataImport::GetNamespace(Int32 mdToken) {
  void* pStringHeap;
  _GetNamespace(m_metadataImport2, mdToken, &pStringHeap);
  return MdUtf8String(pStringHeap);
}

void MetadataImport::GetEventProps(Int32 mdToken, void*& name, EventAttributes& eventAttributes) {
  void* ptr;
  Int32 eventAttributes2;
  _GetEventProps(m_metadataImport2, mdToken, &ptr, eventAttributes2);
  name = ptr;
  eventAttributes = (EventAttributes)eventAttributes2;
}

void MetadataImport::GetFieldDefProps(Int32 mdToken, FieldAttributes& fieldAttributes) {
  Int32 fieldAttributes2;
  _GetFieldDefProps(m_metadataImport2, mdToken, fieldAttributes2);
  fieldAttributes = (FieldAttributes)fieldAttributes2;
}

void MetadataImport::GetPropertyProps(Int32 mdToken, void*& name, PropertyAttributes& propertyAttributes, ConstArray& signature) {
  void* ptr;
  Int32 propertyAttributes2;
  _GetPropertyProps(m_metadataImport2, mdToken, &ptr, propertyAttributes2, signature);
  name = ptr;
  propertyAttributes = (PropertyAttributes)propertyAttributes2;
}

Int32 MetadataImport::GetParentToken(Int32 tkToken) {
  Int32 tkParent;
  _GetParentToken(m_metadataImport2, tkToken, tkParent);
  return tkParent;
}

void MetadataImport::GetParamDefProps(Int32 parameterToken, Int32& sequence, ParameterAttributes& attributes) {
  Int32 attributes2;
  _GetParamDefProps(m_metadataImport2, parameterToken, sequence, attributes2);
  attributes = (ParameterAttributes)attributes2;
}

void MetadataImport::GetGenericParamProps(Int32 genericParameter, GenericParameterAttributes& attributes) {
  Int32 flags;
  _GetGenericParamProps(m_metadataImport2, genericParameter, flags);
  attributes = (GenericParameterAttributes)flags;
}

void MetadataImport::GetScopeProps(Guid& mvid) {
  _GetScopeProps(m_metadataImport2, mvid);
}

ConstArray MetadataImport::GetMethodSignature(MetadataToken token) {
  if (token.get_IsMemberRef()) {
    return GetMemberRefProps(token);
  }
  return GetSigOfMethodDef(token);
}

ConstArray MetadataImport::GetSigOfMethodDef(Int32 methodToken) {
  ConstArray signature = ConstArray();
  _GetSigOfMethodDef(m_metadataImport2, methodToken, signature);
  return signature;
}

ConstArray MetadataImport::GetSignatureFromToken(Int32 token) {
  ConstArray signature = ConstArray();
  _GetSignatureFromToken(m_metadataImport2, token, signature);
  return signature;
}

ConstArray MetadataImport::GetMemberRefProps(Int32 memberTokenRef) {
  ConstArray signature;
  _GetMemberRefProps(m_metadataImport2, memberTokenRef, signature);
  return signature;
}

void MetadataImport::GetCustomAttributeProps(Int32 customAttributeToken, Int32& constructorToken, ConstArray& signature) {
  _GetCustomAttributeProps(m_metadataImport2, customAttributeToken, constructorToken, signature);
}

void MetadataImport::GetClassLayout(Int32 typeTokenDef, Int32& packSize, Int32& classSize) {
  _GetClassLayout(m_metadataImport2, typeTokenDef, packSize, classSize);
}

Boolean MetadataImport::GetFieldOffset(Int32 typeTokenDef, Int32 fieldTokenDef, Int32& offset) {
  return _GetFieldOffset(m_metadataImport2, typeTokenDef, fieldTokenDef, offset);
}

ConstArray MetadataImport::GetSigOfFieldDef(Int32 fieldToken) {
  ConstArray fieldMarshal = ConstArray();
  _GetSigOfFieldDef(m_metadataImport2, fieldToken, fieldMarshal);
  return fieldMarshal;
}

ConstArray MetadataImport::GetFieldMarshal(Int32 fieldToken) {
  ConstArray fieldMarshal = ConstArray();
  _GetFieldMarshal(m_metadataImport2, fieldToken, fieldMarshal);
  return fieldMarshal;
}

void MetadataImport::GetPInvokeMap(Int32 token, PInvokeAttributes& attributes, String& importName, String& importDll) {
  Int32 attributes2;
  void* pStringHeap;
  void* pStringHeap2;
  _GetPInvokeMap(m_metadataImport2, token, attributes2, &pStringHeap, &pStringHeap2);
  importName = MdUtf8String(pStringHeap).ToString();
  importDll = MdUtf8String(pStringHeap2).ToString();
  attributes = (PInvokeAttributes)attributes2;
}

Boolean MetadataImport::IsValidToken(Int32 token) {
  return _IsValidToken(m_metadataImport2, token);
}

void MetadataImport::cctor() {
  EmptyImport = MetadataImport((IntPtr)0, nullptr);
}

} // namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace
