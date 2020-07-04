#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ComponentGuaranteesOptions;
namespace ComponentGuaranteesAttributeNamespace {
CLASS(ComponentGuaranteesAttribute) {
  public: ComponentGuaranteesOptions get_Guarantees() { return Guarantees; }
  private: ComponentGuaranteesOptions Guarantees;
};
} // namespace ComponentGuaranteesAttributeNamespace
using ComponentGuaranteesAttribute = ComponentGuaranteesAttributeNamespace::ComponentGuaranteesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
