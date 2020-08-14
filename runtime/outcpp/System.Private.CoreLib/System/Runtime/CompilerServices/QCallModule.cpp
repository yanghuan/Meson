#include "QCallModule-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::QCallModuleNamespace {
using namespace Internal::Runtime::CompilerServices;

QCallModule::QCallModule(RuntimeModule& module) {
  _ptr = Unsafe::AsPointer(module);
  _module = module->GetUnderlyingNativeHandle();
}

QCallModule::QCallModule(ModuleBuilder& module) {
  _ptr = Unsafe::AsPointer(module);
  _module = module->GetNativeHandle()->GetUnderlyingNativeHandle();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::QCallModuleNamespace
