#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeType.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CustomAttributeEncoding;
namespace CustomAttributeNamedParameterNamespace {
struct CustomAttributeNamedParameter {
  public: CustomAttributeEncodedArgument get_EncodedArgument();
  public: void Ctor(String argumentName, CustomAttributeEncoding fieldOrProperty, CustomAttributeType type);
  public: void Ctor();
  private: String m_argumentName;
  private: CustomAttributeEncoding m_fieldOrProperty;
  private: CustomAttributeEncoding m_padding;
  private: CustomAttributeType m_type;
  private: CustomAttributeEncodedArgument m_encodedArgument;
};
} // namespace CustomAttributeNamedParameterNamespace
using CustomAttributeNamedParameter = CustomAttributeNamedParameterNamespace::CustomAttributeNamedParameter;
} // namespace System::Private::CoreLib::System::Reflection
