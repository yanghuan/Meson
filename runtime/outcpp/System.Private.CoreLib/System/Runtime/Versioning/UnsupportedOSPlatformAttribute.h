#pragma once

#include <System.Private.CoreLib/System/Runtime/Versioning/OSPlatformAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace UnsupportedOSPlatformAttributeNamespace {
CLASS(UnsupportedOSPlatformAttribute) : public OSPlatformAttribute::in {
  public: void ctor(String platformName);
};
} // namespace UnsupportedOSPlatformAttributeNamespace
using UnsupportedOSPlatformAttribute = UnsupportedOSPlatformAttributeNamespace::UnsupportedOSPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
