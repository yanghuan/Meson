#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace NotNullIfNotNullAttributeNamespace {
CLASS(NotNullIfNotNullAttribute) {
  public: String get_ParameterName() { return ParameterName; }
  private: String ParameterName;
};
} // namespace NotNullIfNotNullAttributeNamespace
using NotNullIfNotNullAttribute = NotNullIfNotNullAttributeNamespace::NotNullIfNotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
