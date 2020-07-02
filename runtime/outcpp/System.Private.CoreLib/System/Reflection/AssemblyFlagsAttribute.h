#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Int32)
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
