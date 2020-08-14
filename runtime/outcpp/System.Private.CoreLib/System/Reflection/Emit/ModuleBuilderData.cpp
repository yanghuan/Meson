#include "ModuleBuilderData-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ModuleBuilderDataNamespace {
void ModuleBuilderData___::ctor(ModuleBuilder module, String moduleName) {
  _globalTypeBuilder = rt::newobj<TypeBuilder>(module);
  _moduleName = moduleName;
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ModuleBuilderDataNamespace
