#include "MetadataImport-dep.h"

namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace {
Int32 MetadataImport::GetHashCode() {
  return Int32();
};
Boolean MetadataImport::Equals(Object obj) {
  return Boolean();
};
Boolean MetadataImport::Equals(MetadataImport import) {
  return Boolean();
};
void MetadataImport::GetMarshalAs(ConstArray nativeType, UnmanagedType& unmanagedType, VarEnum& safeArraySubType, String& safeArrayUserDefinedSubType, UnmanagedType& arraySubType, Int32& sizeParamIndex, Int32& sizeConst, String& marshalType, String& marshalCookie, Int32& iidParamIndex) {
  return void();
};
void MetadataImport::ThrowError(Int32 hResult) {
  return void();
};
void MetadataImport::Enum(MetadataTokenType type, Int32 parent, MetadataEnumResult& result) {
  return void();
};
void MetadataImport::EnumNestedTypes(Int32 mdTypeDef, MetadataEnumResult& result) {
  return void();
};
void MetadataImport::EnumCustomAttributes(Int32 mdToken, MetadataEnumResult& result) {
  return void();
};
void MetadataImport::EnumParams(Int32 mdMethodDef, MetadataEnumResult& result) {
  return void();
};
void MetadataImport::EnumFields(Int32 mdTypeDef, MetadataEnumResult& result) {
  return void();
};
void MetadataImport::EnumProperties(Int32 mdTypeDef, MetadataEnumResult& result) {
  return void();
};
void MetadataImport::EnumEvents(Int32 mdTypeDef, MetadataEnumResult& result) {
  return void();
};
String MetadataImport::GetDefaultValue(Int32 mdToken, Int64& value, Int32& length, CorElementType& corElementType) {
  return nullptr;
};
String MetadataImport::GetUserString(Int32 mdToken) {
  return nullptr;
};
MdUtf8String MetadataImport::GetName(Int32 mdToken) {
  return MdUtf8String();
};
MdUtf8String MetadataImport::GetNamespace(Int32 mdToken) {
  return MdUtf8String();
};
void MetadataImport::GetEventProps(Int32 mdToken, void*& name, EventAttributes& eventAttributes) {
  return void();
};
void MetadataImport::GetFieldDefProps(Int32 mdToken, FieldAttributes& fieldAttributes) {
  return void();
};
void MetadataImport::GetPropertyProps(Int32 mdToken, void*& name, PropertyAttributes& propertyAttributes, ConstArray& signature) {
  return void();
};
Int32 MetadataImport::GetParentToken(Int32 tkToken) {
  return Int32();
};
void MetadataImport::GetParamDefProps(Int32 parameterToken, Int32& sequence, ParameterAttributes& attributes) {
  return void();
};
void MetadataImport::GetGenericParamProps(Int32 genericParameter, GenericParameterAttributes& attributes) {
  return void();
};
void MetadataImport::GetScopeProps(Guid& mvid) {
  return void();
};
ConstArray MetadataImport::GetMethodSignature(MetadataToken token) {
  return ConstArray();
};
ConstArray MetadataImport::GetSigOfMethodDef(Int32 methodToken) {
  return ConstArray();
};
ConstArray MetadataImport::GetSignatureFromToken(Int32 token) {
  return ConstArray();
};
ConstArray MetadataImport::GetMemberRefProps(Int32 memberTokenRef) {
  return ConstArray();
};
void MetadataImport::GetCustomAttributeProps(Int32 customAttributeToken, Int32& constructorToken, ConstArray& signature) {
  return void();
};
void MetadataImport::GetClassLayout(Int32 typeTokenDef, Int32& packSize, Int32& classSize) {
  return void();
};
Boolean MetadataImport::GetFieldOffset(Int32 typeTokenDef, Int32 fieldTokenDef, Int32& offset) {
  return Boolean();
};
ConstArray MetadataImport::GetSigOfFieldDef(Int32 fieldToken) {
  return ConstArray();
};
ConstArray MetadataImport::GetFieldMarshal(Int32 fieldToken) {
  return ConstArray();
};
void MetadataImport::GetPInvokeMap(Int32 token, PInvokeAttributes& attributes, String& importName, String& importDll) {
  return void();
};
Boolean MetadataImport::IsValidToken(Int32 token) {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Reflection::MetadataImportNamespace
