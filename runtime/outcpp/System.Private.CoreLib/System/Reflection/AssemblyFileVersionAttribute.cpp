#include "AssemblyFileVersionAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyFileVersionAttributeNamespace {
void AssemblyFileVersionAttribute___::ctor(String version) {
  auto& default = version;
  Version = (default != nullptr ? default : rt::throw_exception(rt::newobj<ArgumentNullException>("version")));
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyFileVersionAttributeNamespace
