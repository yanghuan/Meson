#include "MetadataToken-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::MetadataTokenNamespace {
using namespace System::Globalization;

Boolean MetadataToken::get_IsGlobalTypeDefToken() {
  return Value == 33554433;
}

MetadataTokenType MetadataToken::get_TokenType() {
}

Boolean MetadataToken::get_IsTypeRef() {
  return get_TokenType() == MetadataTokenType::TypeRef;
}

Boolean MetadataToken::get_IsTypeDef() {
  return get_TokenType() == MetadataTokenType::TypeDef;
}

Boolean MetadataToken::get_IsFieldDef() {
  return get_TokenType() == MetadataTokenType::FieldDef;
}

Boolean MetadataToken::get_IsMethodDef() {
  return get_TokenType() == MetadataTokenType::MethodDef;
}

Boolean MetadataToken::get_IsMemberRef() {
  return get_TokenType() == MetadataTokenType::MemberRef;
}

Boolean MetadataToken::get_IsEvent() {
  return get_TokenType() == MetadataTokenType::Event;
}

Boolean MetadataToken::get_IsProperty() {
  return get_TokenType() == MetadataTokenType::Property;
}

Boolean MetadataToken::get_IsParamDef() {
  return get_TokenType() == MetadataTokenType::ParamDef;
}

Boolean MetadataToken::get_IsTypeSpec() {
  return get_TokenType() == MetadataTokenType::TypeSpec;
}

Boolean MetadataToken::get_IsMethodSpec() {
  return get_TokenType() == MetadataTokenType::MethodSpec;
}

Boolean MetadataToken::get_IsString() {
  return get_TokenType() == MetadataTokenType::String;
}

Boolean MetadataToken::get_IsSignature() {
  return get_TokenType() == MetadataTokenType::Signature;
}

Boolean MetadataToken::get_IsGenericPar() {
  return get_TokenType() == MetadataTokenType::GenericPar;
}

Int32 MetadataToken::op_Implicit(MetadataToken token) {
  return token.Value;
}

MetadataToken MetadataToken::op_Implicit(Int32 token) {
  return MetadataToken(token);
}

Boolean MetadataToken::IsNullToken(Int32 token) {
}

MetadataToken::MetadataToken(Int32 token) {
  Value = token;
}

String MetadataToken::ToString() {
  return String::in::Format(CultureInfo::in::get_InvariantCulture(), "0x{0:x8}", Value);
}

} // namespace System::Private::CoreLib::System::Reflection::MetadataTokenNamespace
