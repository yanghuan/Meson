#include "CustomAttributeTypedArgument-dep.h"

namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypedArgumentNamespace {
Type CustomAttributeTypedArgument::get_ArgumentType() {
  return nullptr;
};

Object CustomAttributeTypedArgument::get_Value() {
  return nullptr;
};

Type CustomAttributeTypedArgument::CustomAttributeEncodingToType(CustomAttributeEncoding encodedType) {
  return nullptr;
};

Object CustomAttributeTypedArgument::EncodedValueToRawValue(Int64 val, CustomAttributeEncoding encodedType) {
  return nullptr;
};

RuntimeType CustomAttributeTypedArgument::ResolveType(RuntimeModule scope, String typeName) {
  return nullptr;
};

Object CustomAttributeTypedArgument::CanonicalizeValue(Object value) {
  return nullptr;
};

void CustomAttributeTypedArgument::Ctor(RuntimeModule scope, CustomAttributeEncodedArgument encodedArg) {
};

Boolean CustomAttributeTypedArgument::op_Equality(CustomAttributeTypedArgument left, CustomAttributeTypedArgument right) {
  return Boolean();
};

Boolean CustomAttributeTypedArgument::op_Inequality(CustomAttributeTypedArgument left, CustomAttributeTypedArgument right) {
  return Boolean();
};

void CustomAttributeTypedArgument::Ctor(Type argumentType, Object value) {
};

void CustomAttributeTypedArgument::Ctor(Object value) {
};

String CustomAttributeTypedArgument::ToString() {
  return nullptr;
};

String CustomAttributeTypedArgument::ToString(Boolean typed) {
  return nullptr;
};

Int32 CustomAttributeTypedArgument::GetHashCode() {
  return Int32();
};

Boolean CustomAttributeTypedArgument::Equals(Object obj) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypedArgumentNamespace
