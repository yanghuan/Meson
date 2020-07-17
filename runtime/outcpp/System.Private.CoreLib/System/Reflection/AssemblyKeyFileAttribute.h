#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyKeyFileAttributeNamespace {
CLASS(AssemblyKeyFileAttribute) {
  public: String get_KeyFile() { return KeyFile; }
  public: void Ctor(String keyFile);
  private: String KeyFile;
};
} // namespace AssemblyKeyFileAttributeNamespace
using AssemblyKeyFileAttribute = AssemblyKeyFileAttributeNamespace::AssemblyKeyFileAttribute;
} // namespace System::Private::CoreLib::System::Reflection
