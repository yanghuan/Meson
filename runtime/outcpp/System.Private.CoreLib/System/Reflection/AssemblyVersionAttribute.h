#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyVersionAttributeNamespace {
CLASS(AssemblyVersionAttribute) : public Attribute::in {
  public: String get_Version() { return Version; }
  public: void ctor(String version);
  private: String Version;
};
} // namespace AssemblyVersionAttributeNamespace
using AssemblyVersionAttribute = AssemblyVersionAttributeNamespace::AssemblyVersionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
