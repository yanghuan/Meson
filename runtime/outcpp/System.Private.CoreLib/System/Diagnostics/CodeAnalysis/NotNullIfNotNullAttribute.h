#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace NotNullIfNotNullAttributeNamespace {
CLASS(NotNullIfNotNullAttribute) : public Attribute::in {
  public: String get_ParameterName() { return ParameterName; }
  public: void ctor(String parameterName);
  private: String ParameterName;
};
} // namespace NotNullIfNotNullAttributeNamespace
using NotNullIfNotNullAttribute = NotNullIfNotNullAttributeNamespace::NotNullIfNotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
