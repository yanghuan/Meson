#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(TypeBuilder)
namespace ModuleBuilderDataNamespace {
CLASS(ModuleBuilderData) {
  public: TypeBuilder _globalTypeBuilder;
  public: String _moduleName;
  public: Boolean _hasGlobalBeenCreated;
};
} // namespace ModuleBuilderDataNamespace
using ModuleBuilderData = ModuleBuilderDataNamespace::ModuleBuilderData;
} // namespace System::Private::CoreLib::System::Reflection::Emit