#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ReferenceAssemblyAttributeNamespace {
CLASS(ReferenceAssemblyAttribute) {
  public: String get_Description() { return Description; }
  private: String Description;
};
} // namespace ReferenceAssemblyAttributeNamespace
using ReferenceAssemblyAttribute = ReferenceAssemblyAttributeNamespace::ReferenceAssemblyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
