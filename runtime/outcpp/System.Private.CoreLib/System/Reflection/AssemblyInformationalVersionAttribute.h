#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyInformationalVersionAttributeNamespace {
CLASS(AssemblyInformationalVersionAttribute) : public Attribute::in {
  public: String get_InformationalVersion() { return InformationalVersion; }
  public: void ctor(String informationalVersion);
  private: String InformationalVersion;
};
} // namespace AssemblyInformationalVersionAttributeNamespace
using AssemblyInformationalVersionAttribute = AssemblyInformationalVersionAttributeNamespace::AssemblyInformationalVersionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
