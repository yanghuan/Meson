#include "MetadataImport-dep.h"

namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace {
Int32 MetadataImport::GetHashCode() {
  return Int32();
}

Boolean MetadataImport::Equals(Object obj) {
  return Boolean();
}

Boolean MetadataImport::Equals(MetadataImport import) {
  return Boolean();
}

void MetadataImport::GetMarshalAs(ConstArray nativeType, UnmanagedType& unmanagedType, VarEnum& safeArraySubType, String& safeArrayUserDefinedSubType, UnmanagedType& arraySubType, Int32& sizeParamIndex, Int32& sizeConst, String& marshalType, String& marshalCookie, Int32& iidParamIndex) {
}

void MetadataImport::ThrowError(Int32 hResult) {
}

MetadataImport::MetadataImport(IntPtr metadataImport2, Object keepalive) {
}

void MetadataImport::Enum(MetadataTokenType type, Int32 parent, MetadataEnumResult& result) {
}

void MetadataImport::EnumNestedTypes(Int32 mdTypeDef, MetadataEnumResult& result) {
}

void MetadataImport::EnumCustomAttributes(Int32 mdToken, MetadataEnumResult& result) {
}

void MetadataImport::EnumParams(Int32 mdMethodDef, MetadataEnumResult& result) {
}

void MetadataImport::EnumFields(Int32 mdTypeDef, MetadataEnumResult& result) {
}

void MetadataImport::EnumProperties(Int32 mdTypeDef, MetadataEnumResult& result) {
}

void MetadataImport::EnumEvents(Int32 mdTypeDef, MetadataEnumResult& result) {
}

String MetadataImport::GetDefaultValue(Int32 mdToken, Int64& value, Int32& length, CorElementType& corElementType) {
  return nullptr;
}

String MetadataImport::GetUserString(Int32 mdToken) {
  return nullptr;
}

MdUtf8String MetadataImport::GetName(Int32 mdToken) {
  return MdUtf8String();
}

MdUtf8String MetadataImport::GetNamespace(Int32 mdToken) {
  return MdUtf8String();
}

void MetadataImport::GetEventProps(Int32 mdToken, void*& name, EventAttributes& eventAttributes) {
}

void MetadataImport::GetFieldDefProps(Int32 mdToken, FieldAttributes& fieldAttributes) {
}

void MetadataImport::GetPropertyProps(Int32 mdToken, void*& name, PropertyAttributes& propertyAttributes, ConstArray& signature) {
}

Int32 MetadataImport::GetParentToken(Int32 tkToken) {
  return Int32();
}

void MetadataImport::GetParamDefProps(Int32 parameterToken, Int32& sequence, ParameterAttributes& attributes) {
}

void MetadataImport::GetGenericParamProps(Int32 genericParameter, GenericParameterAttributes& attributes) {
}

void MetadataImport::GetScopeProps(Guid& mvid) {
}

ConstArray MetadataImport::GetMethodSignature(MetadataToken token) {
  return ConstArray();
}

ConstArray MetadataImport::GetSigOfMethodDef(Int32 methodToken) {
  return ConstArray();
}

ConstArray MetadataImport::GetSignatureFromToken(Int32 token) {
  return ConstArray();
}

ConstArray MetadataImport::GetMemberRefProps(Int32 memberTokenRef) {
  return ConstArray();
}

void MetadataImport::GetCustomAttributeProps(Int32 customAttributeToken, Int32& constructorToken, ConstArray& signature) {
}

void MetadataImport::GetClassLayout(Int32 typeTokenDef, Int32& packSize, Int32& classSize) {
}

Boolean MetadataImport::GetFieldOffset(Int32 typeTokenDef, Int32 fieldTokenDef, Int32& offset) {
  return Boolean();
}

ConstArray MetadataImport::GetSigOfFieldDef(Int32 fieldToken) {
  return ConstArray();
}

ConstArray MetadataImport::GetFieldMarshal(Int32 fieldToken) {
  return ConstArray();
}

void MetadataImport::GetPInvokeMap(Int32 token, PInvokeAttributes& attributes, String& importName, String& importDll) {
}

Boolean MetadataImport::IsValidToken(Int32 token) {
  return Boolean();
}

void MetadataImport::SCtor() {
}

} // namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace
