#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace PreserveBaseOverridesAttributeNamespace {
CLASS(PreserveBaseOverridesAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace PreserveBaseOverridesAttributeNamespace
using PreserveBaseOverridesAttribute = PreserveBaseOverridesAttributeNamespace::PreserveBaseOverridesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
