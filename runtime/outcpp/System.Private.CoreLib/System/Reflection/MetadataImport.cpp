#include "MetadataImport-dep.h"

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
}

void MetadataImport::GetFieldDefProps(Int32 mdToken, FieldAttributes& fieldAttributes) {
}

void MetadataImport::GetPropertyProps(Int32 mdToken, void*& name, PropertyAttributes& propertyAttributes, ConstArray& signature) {
  void* ptr;
}

Int32 MetadataImport::GetParentToken(Int32 tkToken) {
}

void MetadataImport::GetParamDefProps(Int32 parameterToken, Int32& sequence, ParameterAttributes& attributes) {
}

void MetadataImport::GetGenericParamProps(Int32 genericParameter, GenericParameterAttributes& attributes) {
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
  void* pStringHeap;
  void* pStringHeap2;
}

Boolean MetadataImport::IsValidToken(Int32 token) {
  return _IsValidToken(m_metadataImport2, token);
}

void MetadataImport::cctor() {
  EmptyImport = MetadataImport((IntPtr)0, nullptr);
}

} // namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace
