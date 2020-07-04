#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope;
namespace ResourceExposureAttributeNamespace {
CLASS(ResourceExposureAttribute) {
  public: ResourceScope get_ResourceExposureLevel() { return ResourceExposureLevel; }
  private: ResourceScope ResourceExposureLevel;
};
} // namespace ResourceExposureAttributeNamespace
using ResourceExposureAttribute = ResourceExposureAttributeNamespace::ResourceExposureAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
