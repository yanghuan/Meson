#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class AssemblyNameFlags : int32_t;
namespace AssemblyFlagsAttributeNamespace {
CLASS(AssemblyFlagsAttribute) : public Attribute::in {
  public: UInt32 get_Flags();
  public: Int32 get_AssemblyFlags();
  public: void ctor(UInt32 flags);
  public: void ctor(Int32 assemblyFlags);
  public: void ctor(AssemblyNameFlags assemblyFlags);
  private: AssemblyNameFlags _flags;
};
} // namespace AssemblyFlagsAttributeNamespace
using AssemblyFlagsAttribute = AssemblyFlagsAttributeNamespace::AssemblyFlagsAttribute;
} // namespace System::Private::CoreLib::System::Reflection
