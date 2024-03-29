#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(ModuleBuilder)
FORWARD(TypeBuilder)
namespace ModuleBuilderDataNamespace {
CLASS(ModuleBuilderData) : public object {
  public: void ctor(ModuleBuilder module, String moduleName);
  public: TypeBuilder _globalTypeBuilder;
  public: String _moduleName;
  public: Boolean _hasGlobalBeenCreated;
};
} // namespace ModuleBuilderDataNamespace
using ModuleBuilderData = ModuleBuilderDataNamespace::ModuleBuilderData;
} // namespace System::Private::CoreLib::System::Reflection::Emit
