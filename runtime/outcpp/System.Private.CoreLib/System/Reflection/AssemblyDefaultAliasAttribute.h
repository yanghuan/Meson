#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDefaultAliasAttributeNamespace {
CLASS(AssemblyDefaultAliasAttribute) {
  public: String get_DefaultAlias() { return DefaultAlias; }
  public: void Ctor(String defaultAlias);
  private: String DefaultAlias;
};
} // namespace AssemblyDefaultAliasAttributeNamespace
using AssemblyDefaultAliasAttribute = AssemblyDefaultAliasAttributeNamespace::AssemblyDefaultAliasAttribute;
} // namespace System::Private::CoreLib::System::Reflection
