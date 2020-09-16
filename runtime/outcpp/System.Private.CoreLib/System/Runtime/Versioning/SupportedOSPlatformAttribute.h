#pragma once

#include <System.Private.CoreLib/System/Runtime/Versioning/OSPlatformAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace SupportedOSPlatformAttributeNamespace {
CLASS(SupportedOSPlatformAttribute) : public OSPlatformAttribute::in {
  public: void ctor(String platformName);
};
} // namespace SupportedOSPlatformAttributeNamespace
using SupportedOSPlatformAttribute = SupportedOSPlatformAttributeNamespace::SupportedOSPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
