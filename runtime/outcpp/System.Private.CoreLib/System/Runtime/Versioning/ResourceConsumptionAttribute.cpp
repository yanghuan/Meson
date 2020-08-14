#include "ResourceConsumptionAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::Versioning::ResourceConsumptionAttributeNamespace {
void ResourceConsumptionAttribute___::ctor(Versioning::ResourceScope resourceScope) {
  ResourceScope = resourceScope;
  ConsumptionScope = resourceScope;
}

void ResourceConsumptionAttribute___::ctor(Versioning::ResourceScope resourceScope, Versioning::ResourceScope consumptionScope) {
  ResourceScope = resourceScope;
  ConsumptionScope = consumptionScope;
}

} // namespace System::Private::CoreLib::System::Runtime::Versioning::ResourceConsumptionAttributeNamespace
