#include "ResourceFallbackManager-dep.h"

#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceFallbackManager-dep.h>

namespace System::Private::CoreLib::System::Resources::ResourceFallbackManagerNamespace {
CultureInfo ResourceFallbackManager___::_GetEnumerator_d__5___::get_CurrentOfCultureInfo() {
  return __2__current;
}

Object ResourceFallbackManager___::_GetEnumerator_d__5___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void ResourceFallbackManager___::_GetEnumerator_d__5___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
}

void ResourceFallbackManager___::_GetEnumerator_d__5___::DisposeOfIDisposable() {
}

Boolean ResourceFallbackManager___::_GetEnumerator_d__5___::MoveNext() {
  Int32 num = __1__state;
  ResourceFallbackManager resourceFallbackManager = __4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      __1__state = -1;
      _reachedNeutralResourcesCulture_5__2 = false;
      _currentCulture_5__3 = resourceFallbackManager->m_startingCulture;
      goto IL_0040;
    case 1:
      __1__state = -1;
      _reachedNeutralResourcesCulture_5__2 = true;
      goto IL_00ce;
    case 2:
      __1__state = -1;
      _currentCulture_5__3 = _currentCulture_5__3->get_Parent();
      if (resourceFallbackManager->m_useParents && !_currentCulture_5__3->get_HasInvariantCultureName()) {
        goto IL_0040;
      }
      goto IL_00ce;
    case 3:
      {
        __1__state = -1;
        return false;
      }
    IL_0040:
      if (resourceFallbackManager->m_neutralResourcesCulture != nullptr && _currentCulture_5__3->get_Name() == resourceFallbackManager->m_neutralResourcesCulture->get_Name()) {
        __2__current = CultureInfo::in::get_InvariantCulture();
        __1__state = 1;
        return true;
      }
      __2__current = _currentCulture_5__3;
      __1__state = 2;
      return true;

    IL_00ce:
      if (!resourceFallbackManager->m_useParents || resourceFallbackManager->m_startingCulture->get_HasInvariantCultureName()) {
        return false;
      }
      if (_reachedNeutralResourcesCulture_5__2) {
        return false;
      }
      __2__current = CultureInfo::in::get_InvariantCulture();
      __1__state = 3;
      return true;
  }
}

void ResourceFallbackManager___::_GetEnumerator_d__5___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

void ResourceFallbackManager___::ctor(CultureInfo startingCulture, CultureInfo neutralResourcesCulture, Boolean useParents) {
  if (startingCulture != nullptr) {
    m_startingCulture = startingCulture;
  } else {
    m_startingCulture = CultureInfo::in::set_CurrentUICulture();
  }
  m_neutralResourcesCulture = neutralResourcesCulture;
  m_useParents = useParents;
}

IEnumerator_ ResourceFallbackManager___::GetEnumeratorOfIEnumerable() {
  return GetEnumerator();
}

IEnumerator<CultureInfo> ResourceFallbackManager___::GetEnumerator() {
  Boolean reachedNeutralResourcesCulture = false;
  CultureInfo currentCulture = m_startingCulture;
  do {
    if (m_neutralResourcesCulture != nullptr && currentCulture->get_Name() == m_neutralResourcesCulture->get_Name()) {
    }
  } while (m_useParents && !currentCulture->get_HasInvariantCultureName());
  if (m_useParents && !m_startingCulture->get_HasInvariantCultureName() && !reachedNeutralResourcesCulture) {
  }
}

} // namespace System::Private::CoreLib::System::Resources::ResourceFallbackManagerNamespace
