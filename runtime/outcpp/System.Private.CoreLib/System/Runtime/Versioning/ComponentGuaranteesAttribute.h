#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ComponentGuaranteesOptions;
namespace ComponentGuaranteesAttributeNamespace {
CLASS(ComponentGuaranteesAttribute) : public Attribute::in {
  public: ComponentGuaranteesOptions get_Guarantees() { return Guarantees; }
  public: void Ctor(ComponentGuaranteesOptions guarantees);
  private: ComponentGuaranteesOptions Guarantees;
};
} // namespace ComponentGuaranteesAttributeNamespace
using ComponentGuaranteesAttribute = ComponentGuaranteesAttributeNamespace::ComponentGuaranteesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
