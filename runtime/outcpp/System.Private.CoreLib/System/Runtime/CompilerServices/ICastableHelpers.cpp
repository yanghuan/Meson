#include "ICastableHelpers-dep.h"

#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ICastableHelpersNamespace {
Boolean ICastableHelpers::IsInstanceOfInterface(ICastable castable, RuntimeType type, Exception& castError) {
  return castable->IsInstanceOfInterface(RuntimeTypeHandle(type), castError);
}

RuntimeType ICastableHelpers::GetImplType(ICastable castable, RuntimeType interfaceType) {
  return castable->GetImplType(RuntimeTypeHandle(interfaceType)).GetRuntimeType();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ICastableHelpersNamespace
