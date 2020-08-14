#include "AssemblyFlagsAttribute-dep.h"

#include <System.Private.CoreLib/System/Reflection/AssemblyNameFlags.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyFlagsAttributeNamespace {
UInt32 AssemblyFlagsAttribute___::get_Flags() {
  return (UInt32)_flags;
}

Int32 AssemblyFlagsAttribute___::get_AssemblyFlags() {
  return (Int32)_flags;
}

void AssemblyFlagsAttribute___::ctor(UInt32 flags) {
  _flags = (AssemblyNameFlags)flags;
}

void AssemblyFlagsAttribute___::ctor(Int32 assemblyFlags) {
  _flags = (AssemblyNameFlags)assemblyFlags;
}

void AssemblyFlagsAttribute___::ctor(AssemblyNameFlags assemblyFlags) {
  _flags = assemblyFlags;
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyFlagsAttributeNamespace
