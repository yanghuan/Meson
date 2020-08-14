#include "TypeForwardedFromAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::TypeForwardedFromAttributeNamespace {
void TypeForwardedFromAttribute___::ctor(String assemblyFullName) {
  if (String::in::IsNullOrEmpty(assemblyFullName)) {
    rt::throw_exception<ArgumentNullException>("assemblyFullName");
  }
  AssemblyFullName = assemblyFullName;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::TypeForwardedFromAttributeNamespace
