#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Versioning {
namespace OSPlatformAttributeNamespace {
CLASS(OSPlatformAttribute) : public Attribute::in {
  public: String get_PlatformName() { return PlatformName; }
  public: void ctor(String platformName);
  private: String PlatformName;
};
} // namespace OSPlatformAttributeNamespace
using OSPlatformAttribute = OSPlatformAttributeNamespace::OSPlatformAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
