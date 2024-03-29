#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ComponentGuaranteesOptions : int32_t;
namespace ComponentGuaranteesAttributeNamespace {
CLASS(ComponentGuaranteesAttribute) : public Attribute::in {
  public: ComponentGuaranteesOptions get_Guarantees() { return Guarantees; }
  public: void ctor(ComponentGuaranteesOptions guarantees);
  private: ComponentGuaranteesOptions Guarantees;
};
} // namespace ComponentGuaranteesAttributeNamespace
using ComponentGuaranteesAttribute = ComponentGuaranteesAttributeNamespace::ComponentGuaranteesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::Versioning
