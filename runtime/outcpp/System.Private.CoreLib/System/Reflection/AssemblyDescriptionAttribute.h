#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDescriptionAttributeNamespace {
CLASS(AssemblyDescriptionAttribute) : public Attribute::in {
  public: String get_Description() { return Description; }
  public: void Ctor(String description);
  private: String Description;
};
} // namespace AssemblyDescriptionAttributeNamespace
using AssemblyDescriptionAttribute = AssemblyDescriptionAttributeNamespace::AssemblyDescriptionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
