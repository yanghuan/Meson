#include "InternalsVisibleToAttribute-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::InternalsVisibleToAttributeNamespace {
void InternalsVisibleToAttribute___::ctor(String assemblyName) {
  AllInternalsVisible = true;
  Attribute::in::ctor();
  AssemblyName = assemblyName;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::InternalsVisibleToAttributeNamespace
