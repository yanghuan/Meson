#include "ParameterBuilder-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::ParameterBuilderNamespace {
String ParameterBuilder___::get_Name() {
  return nullptr;
}

Int32 ParameterBuilder___::get_Position() {
  return Int32();
}

Int32 ParameterBuilder___::get_Attributes() {
  return Int32();
}

Boolean ParameterBuilder___::get_IsIn() {
  return Boolean();
}

Boolean ParameterBuilder___::get_IsOut() {
  return Boolean();
}

Boolean ParameterBuilder___::get_IsOptional() {
  return Boolean();
}

void ParameterBuilder___::SetConstant(Object defaultValue) {
}

void ParameterBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
}

void ParameterBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
}

void ParameterBuilder___::Ctor(MethodBuilder methodBuilder, Int32 sequence, ParameterAttributes attributes, String paramName) {
}

ParameterToken ParameterBuilder___::GetToken() {
  return ParameterToken();
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ParameterBuilderNamespace
