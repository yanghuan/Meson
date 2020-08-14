#include "CustomAttributeType-dep.h"

namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypeNamespace {
CustomAttributeEncoding CustomAttributeType::get_EncodedType() {
  return m_encodedType;
}

CustomAttributeEncoding CustomAttributeType::get_EncodedEnumType() {
  return m_encodedEnumType;
}

CustomAttributeEncoding CustomAttributeType::get_EncodedArrayType() {
  return m_encodedArrayType;
}

String CustomAttributeType::get_EnumName() {
  return m_enumName;
}

CustomAttributeType::CustomAttributeType(CustomAttributeEncoding encodedType, CustomAttributeEncoding encodedArrayType, CustomAttributeEncoding encodedEnumType, String enumName) {
  m_encodedType = encodedType;
  m_encodedArrayType = encodedArrayType;
  m_encodedEnumType = encodedEnumType;
  m_enumName = enumName;
  m_padding = m_encodedType;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypeNamespace
