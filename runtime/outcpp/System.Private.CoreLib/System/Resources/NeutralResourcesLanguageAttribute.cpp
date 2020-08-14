#include "NeutralResourcesLanguageAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Resources::NeutralResourcesLanguageAttributeNamespace {
void NeutralResourcesLanguageAttribute___::ctor(String cultureName) {
  if (cultureName == nullptr) {
    rt::throw_exception<ArgumentNullException>("cultureName");
  }
  CultureName = cultureName;
  Location = UltimateResourceFallbackLocation::MainAssembly;
}

void NeutralResourcesLanguageAttribute___::ctor(String cultureName, UltimateResourceFallbackLocation location) {
  if (cultureName == nullptr) {
    rt::throw_exception<ArgumentNullException>("cultureName");
  }
}

} // namespace System::Private::CoreLib::System::Resources::NeutralResourcesLanguageAttributeNamespace
