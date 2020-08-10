#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ReferenceAssemblyAttributeNamespace {
CLASS(ReferenceAssemblyAttribute) : public Attribute::in {
  public: String get_Description() { return Description; }
  public: void ctor();
  public: void ctor(String description);
  private: String Description;
};
} // namespace ReferenceAssemblyAttributeNamespace
using ReferenceAssemblyAttribute = ReferenceAssemblyAttributeNamespace::ReferenceAssemblyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
