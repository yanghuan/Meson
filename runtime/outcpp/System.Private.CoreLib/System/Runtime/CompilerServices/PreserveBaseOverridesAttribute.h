#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace PreserveBaseOverridesAttributeNamespace {
CLASS(PreserveBaseOverridesAttribute) {
  public: void Ctor();
};
} // namespace PreserveBaseOverridesAttributeNamespace
using PreserveBaseOverridesAttribute = PreserveBaseOverridesAttributeNamespace::PreserveBaseOverridesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
