#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CustomAttributeEncoding;
namespace CustomAttributeTypeNamespace {
struct CustomAttributeType {
  public: CustomAttributeEncoding get_EncodedType();
  public: CustomAttributeEncoding get_EncodedEnumType();
  public: CustomAttributeEncoding get_EncodedArrayType();
  public: String get_EnumName();
  private: String m_enumName;
  private: CustomAttributeEncoding m_encodedType;
  private: CustomAttributeEncoding m_encodedEnumType;
  private: CustomAttributeEncoding m_encodedArrayType;
  private: CustomAttributeEncoding m_padding;
};
} // namespace CustomAttributeTypeNamespace
using CustomAttributeType = CustomAttributeTypeNamespace::CustomAttributeType;
} // namespace System::Private::CoreLib::System::Reflection
