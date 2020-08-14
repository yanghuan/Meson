#include "NeutralResourcesLanguageAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

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
  if (!Enum::in::IsDefined(rt::typeof<UltimateResourceFallbackLocation>(), location)) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_InvalidNeutralResourcesLanguage_FallbackLoc(), location));
  }
  CultureName = cultureName;
  Location = location;
}

} // namespace System::Private::CoreLib::System::Resources::NeutralResourcesLanguageAttributeNamespace
