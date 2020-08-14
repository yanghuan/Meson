#include "ResourceFallbackManager-dep.h"

namespace System::Private::CoreLib::System::Resources::ResourceFallbackManagerNamespace {
void ResourceFallbackManager___::ctor(CultureInfo startingCulture, CultureInfo neutralResourcesCulture, Boolean useParents) {
  if (startingCulture != nullptr) {
    m_startingCulture = startingCulture;
  } else {
    m_startingCulture = CultureInfo::in::set_CurrentUICulture;
  }
  m_neutralResourcesCulture = neutralResourcesCulture;
  m_useParents = useParents;
}

IEnumerator<CultureInfo> ResourceFallbackManager___::GetEnumerator() {
  Boolean reachedNeutralResourcesCulture = false;
  CultureInfo currentCulture = m_startingCulture;
}

} // namespace System::Private::CoreLib::System::Resources::ResourceFallbackManagerNamespace
