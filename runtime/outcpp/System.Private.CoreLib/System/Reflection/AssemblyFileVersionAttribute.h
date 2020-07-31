#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyFileVersionAttributeNamespace {
CLASS(AssemblyFileVersionAttribute) : public Attribute::in {
  public: String get_Version() { return Version; }
  public: void Ctor(String version);
  private: String Version;
};
} // namespace AssemblyFileVersionAttributeNamespace
using AssemblyFileVersionAttribute = AssemblyFileVersionAttributeNamespace::AssemblyFileVersionAttribute;
} // namespace System::Private::CoreLib::System::Reflection
