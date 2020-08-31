#pragma once

#include <System.Private.CoreLib/System/Runtime/Versioning/OSPlatformAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace RemovedInOSPlatformAttributeNamespace {
CLASS(RemovedInOSPlatformAttribute) : public OSPlatformAttribute::in {
  public: void ctor(String platformName);
};
} // namespace RemovedInOSPlatformAttributeNamespace
using RemovedInOSPlatformAttribute = RemovedInOSPlatformAttributeNamespace::RemovedInOSPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
