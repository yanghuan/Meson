#include "AssemblyFileVersionAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyFileVersionAttributeNamespace {
void AssemblyFileVersionAttribute___::ctor(String version) {
  auto& default = version;
  if (default == nullptr) rt::throw_exception(rt::newobj<ArgumentNullException>("version"));
  Version = (default);
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyFileVersionAttributeNamespace
