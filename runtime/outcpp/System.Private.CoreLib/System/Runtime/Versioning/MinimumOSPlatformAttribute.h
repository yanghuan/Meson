#pragma once

#include <System.Private.CoreLib/System/Runtime/Versioning/OSPlatformAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace MinimumOSPlatformAttributeNamespace {
CLASS(MinimumOSPlatformAttribute) : public OSPlatformAttribute::in {
  public: void ctor(String platformName);
};
} // namespace MinimumOSPlatformAttributeNamespace
using MinimumOSPlatformAttribute = MinimumOSPlatformAttributeNamespace::MinimumOSPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
