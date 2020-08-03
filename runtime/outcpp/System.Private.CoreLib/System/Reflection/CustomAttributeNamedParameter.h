#pragma once

#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeType.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CustomAttributeEncoding;
namespace CustomAttributeNamedParameterNamespace {
struct CustomAttributeNamedParameter : public valueType<CustomAttributeNamedParameter> {
  public: CustomAttributeEncodedArgument get_EncodedArgument();
  public: explicit CustomAttributeNamedParameter(String argumentName, CustomAttributeEncoding fieldOrProperty, CustomAttributeType type);
  public: explicit CustomAttributeNamedParameter() {}
  private: String m_argumentName;
  private: CustomAttributeEncoding m_fieldOrProperty;
  private: CustomAttributeEncoding m_padding;
  private: CustomAttributeType m_type;
  private: CustomAttributeEncodedArgument m_encodedArgument;
};
} // namespace CustomAttributeNamedParameterNamespace
using CustomAttributeNamedParameter = CustomAttributeNamedParameterNamespace::CustomAttributeNamedParameter;
} // namespace System::Private::CoreLib::System::Reflection
