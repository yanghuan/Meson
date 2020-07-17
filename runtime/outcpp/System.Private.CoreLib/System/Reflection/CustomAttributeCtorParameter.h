#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeEncodedArgument.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeType.h>

namespace System::Private::CoreLib::System::Reflection {
namespace CustomAttributeCtorParameterNamespace {
struct CustomAttributeCtorParameter {
  public: CustomAttributeEncodedArgument get_CustomAttributeEncodedArgument();
  public: void Ctor(CustomAttributeType type);
  public: void Ctor();
  private: CustomAttributeType m_type;
  private: CustomAttributeEncodedArgument m_encodedArgument;
};
} // namespace CustomAttributeCtorParameterNamespace
using CustomAttributeCtorParameter = CustomAttributeCtorParameterNamespace::CustomAttributeCtorParameter;
} // namespace System::Private::CoreLib::System::Reflection
