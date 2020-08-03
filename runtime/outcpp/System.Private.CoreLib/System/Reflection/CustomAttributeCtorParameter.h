#pragma once

#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeType.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Reflection {
namespace CustomAttributeCtorParameterNamespace {
struct CustomAttributeCtorParameter : public valueType<CustomAttributeCtorParameter> {
  public: CustomAttributeEncodedArgument get_CustomAttributeEncodedArgument();
  public: explicit CustomAttributeCtorParameter(CustomAttributeType type);
  public: explicit CustomAttributeCtorParameter() {}
  private: CustomAttributeType m_type;
  private: CustomAttributeEncodedArgument m_encodedArgument;
};
} // namespace CustomAttributeCtorParameterNamespace
using CustomAttributeCtorParameter = CustomAttributeCtorParameterNamespace::CustomAttributeCtorParameter;
} // namespace System::Private::CoreLib::System::Reflection
