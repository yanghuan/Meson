#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace AllowNullAttributeNamespace {
CLASS(AllowNullAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace AllowNullAttributeNamespace
using AllowNullAttribute = AllowNullAttributeNamespace::AllowNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
