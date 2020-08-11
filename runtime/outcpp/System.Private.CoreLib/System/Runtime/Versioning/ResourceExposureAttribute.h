#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope : int32_t;
namespace ResourceExposureAttributeNamespace {
CLASS(ResourceExposureAttribute) : public Attribute::in {
  public: ResourceScope get_ResourceExposureLevel() { return ResourceExposureLevel; }
  public: void ctor(ResourceScope exposureLevel);
  private: ResourceScope ResourceExposureLevel;
};
} // namespace ResourceExposureAttributeNamespace
using ResourceExposureAttribute = ResourceExposureAttributeNamespace::ResourceExposureAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
