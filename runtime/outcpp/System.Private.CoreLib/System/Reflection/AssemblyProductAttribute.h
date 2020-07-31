#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyProductAttributeNamespace {
CLASS(AssemblyProductAttribute) : public Attribute::in {
  public: String get_Product() { return Product; }
  public: void Ctor(String product);
  private: String Product;
};
} // namespace AssemblyProductAttributeNamespace
using AssemblyProductAttribute = AssemblyProductAttributeNamespace::AssemblyProductAttribute;
} // namespace System::Private::CoreLib::System::Reflection
