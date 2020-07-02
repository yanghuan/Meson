#include "CustomAttributeType-dep.h"

namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypeNamespace {
CustomAttributeEncoding CustomAttributeType::get_EncodedType() {
  return CustomAttributeEncoding();
};
CustomAttributeEncoding CustomAttributeType::get_EncodedEnumType() {
  return CustomAttributeEncoding();
};
CustomAttributeEncoding CustomAttributeType::get_EncodedArrayType() {
  return CustomAttributeEncoding();
};
String CustomAttributeType::get_EnumName() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypeNamespace
