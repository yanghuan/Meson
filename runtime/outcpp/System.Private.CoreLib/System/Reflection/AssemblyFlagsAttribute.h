#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class AssemblyNameFlags;
namespace AssemblyFlagsAttributeNamespace {
CLASS(AssemblyFlagsAttribute) {
  public: UInt32 get_Flags();
  public: Int32 get_AssemblyFlags();
  public: void Ctor(UInt32 flags);
  public: void Ctor(Int32 assemblyFlags);
  public: void Ctor(AssemblyNameFlags assemblyFlags);
  private: AssemblyNameFlags _flags;
};
} // namespace AssemblyFlagsAttributeNamespace
using AssemblyFlagsAttribute = AssemblyFlagsAttributeNamespace::AssemblyFlagsAttribute;
} // namespace System::Private::CoreLib::System::Reflection
