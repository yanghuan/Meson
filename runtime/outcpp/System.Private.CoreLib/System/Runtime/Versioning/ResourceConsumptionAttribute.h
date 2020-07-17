#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ResourceScope;
namespace ResourceConsumptionAttributeNamespace {
CLASS(ResourceConsumptionAttribute) {
  public: ResourceScope get_ResourceScope() { return ResourceScope; }
  public: ResourceScope get_ConsumptionScope() { return ConsumptionScope; }
  public: void Ctor(ResourceScope resourceScope);
  public: void Ctor(ResourceScope resourceScope, ResourceScope consumptionScope);
  private: ResourceScope ResourceScope;
  private: Versioning::ResourceScope ConsumptionScope;
};
} // namespace ResourceConsumptionAttributeNamespace
using ResourceConsumptionAttribute = ResourceConsumptionAttributeNamespace::ResourceConsumptionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
