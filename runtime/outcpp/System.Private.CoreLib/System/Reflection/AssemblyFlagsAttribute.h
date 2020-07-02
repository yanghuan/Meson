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
  private: AssemblyNameFlags _flags;
};
} // namespace AssemblyFlagsAttributeNamespace
using AssemblyFlagsAttribute = AssemblyFlagsAttributeNamespace::AssemblyFlagsAttribute;
} // namespace System::Private::CoreLib::System::Reflection
