#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyProductAttributeNamespace {
CLASS(AssemblyProductAttribute) {
  public: String get_Product() { return Product; }
  public: void Ctor(String product);
  private: String Product;
};
} // namespace AssemblyProductAttributeNamespace
using AssemblyProductAttribute = AssemblyProductAttributeNamespace::AssemblyProductAttribute;
} // namespace System::Private::CoreLib::System::Reflection
