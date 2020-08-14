#include "QCallAssembly-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::QCallAssemblyNamespace {
using namespace Internal::Runtime::CompilerServices;

QCallAssembly::QCallAssembly(RuntimeAssembly& assembly) {
  _ptr = Unsafe::AsPointer(assembly);
  _assembly = assembly->GetUnderlyingNativeHandle();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::QCallAssemblyNamespace
