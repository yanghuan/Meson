#include "AssemblyFileVersionAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyFileVersionAttributeNamespace {
void AssemblyFileVersionAttribute___::ctor(String version) {
  if (version == nullptr) {
    rt::throw_exception<ArgumentNullException>("version");
  }
  Version = version;
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyFileVersionAttributeNamespace
