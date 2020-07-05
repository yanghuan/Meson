#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope;
namespace ResourceConsumptionAttributeNamespace {
CLASS(ResourceConsumptionAttribute) {
  public: ResourceScope get_ResourceScope() { return ResourceScope; }
  public: ResourceScope get_ConsumptionScope() { return ConsumptionScope; }
  private: ResourceScope ResourceScope;
  private: ::System::Private::CoreLib::System::Runtime::Versioning::ResourceScope ConsumptionScope;
};
} // namespace ResourceConsumptionAttributeNamespace
using ResourceConsumptionAttribute = ResourceConsumptionAttributeNamespace::ResourceConsumptionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
