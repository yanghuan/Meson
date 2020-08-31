#pragma once

#include <System.Private.CoreLib/System/Runtime/Versioning/OSPlatformAttribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace TargetPlatformAttributeNamespace {
CLASS(TargetPlatformAttribute) : public OSPlatformAttribute::in {
  public: void ctor(String platformName);
};
} // namespace TargetPlatformAttributeNamespace
using TargetPlatformAttribute = TargetPlatformAttributeNamespace::TargetPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
