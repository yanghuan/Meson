#include "ParameterBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ParameterToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ParameterBuilderNamespace {
using namespace System::Runtime::CompilerServices;

String ParameterBuilder___::get_Name() {
  return _name;
}

Int32 ParameterBuilder___::get_Position() {
  return _position;
}

Int32 ParameterBuilder___::get_Attributes() {
  return (Int32)_attributes;
}

Boolean ParameterBuilder___::get_IsIn() {
}

Boolean ParameterBuilder___::get_IsOut() {
}

Boolean ParameterBuilder___::get_IsOptional() {
}

void ParameterBuilder___::SetConstant(Object defaultValue) {
  TypeBuilder::in::SetConstantValue(_methodBuilder->GetModuleBuilder(), _token.get_Token(), (_position == 0) ? _methodBuilder->get_ReturnType() : _methodBuilder->m_parameterTypes[_position - 1], defaultValue);
}

void ParameterBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  TypeBuilder::in::DefineCustomAttribute(_methodBuilder->GetModuleBuilder(), _token.get_Token(), ((ModuleBuilder)_methodBuilder->GetModule())->GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
}

void ParameterBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  customBuilder->CreateCustomAttribute((ModuleBuilder)_methodBuilder->GetModule(), _token.get_Token());
}

void ParameterBuilder___::ctor(MethodBuilder methodBuilder, Int32 sequence, ParameterAttributes attributes, String paramName) {
  _position = sequence;
  _name = paramName;
  _methodBuilder = methodBuilder;
  _attributes = attributes;
  ModuleBuilder module = _methodBuilder->GetModuleBuilder();
  _token = ParameterToken(TypeBuilder::in::SetParamInfo(QCallModule(module), _methodBuilder->GetToken().get_Token(), sequence, attributes, paramName));
}

ParameterToken ParameterBuilder___::GetToken() {
  return _token;
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ParameterBuilderNamespace
