#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace NotNullAttributeNamespace {
CLASS(NotNullAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace NotNullAttributeNamespace
using NotNullAttribute = NotNullAttributeNamespace::NotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
