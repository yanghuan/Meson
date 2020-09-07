#include "ResourceFallbackManager-dep.h"

#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceFallbackManager-dep.h>

namespace System::Private::CoreLib::System::Resources::ResourceFallbackManagerNamespace {
CultureInfo ResourceFallbackManager___::_GetEnumerator_d__5___::get_CurrentOfCultureInfo() {
  return <>2__current;
}

Object ResourceFallbackManager___::_GetEnumerator_d__5___::get_CurrentOfIEnumerator() {
  return <>2__current;
}

void ResourceFallbackManager___::_GetEnumerator_d__5___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
}

void ResourceFallbackManager___::_GetEnumerator_d__5___::DisposeOfIDisposable() {
}

Boolean ResourceFallbackManager___::_GetEnumerator_d__5___::MoveNext() {
  Int32 num = <>1__state;
  ResourceFallbackManager resourceFallbackManager = <>4__this;
  switch (num.get()) {
    default:
      return false;
    case 0:
      <>1__state = -1;
      <reachedNeutralResourcesCulture>5__2 = false;
      <currentCulture>5__3 = resourceFallbackManager->m_startingCulture;
      goto IL_0040;
    case 1:
      <>1__state = -1;
      <reachedNeutralResourcesCulture>5__2 = true;
      goto IL_00ce;
    case 2:
      <>1__state = -1;
      <currentCulture>5__3 = <currentCulture>5__3->get_Parent();
      if (resourceFallbackManager->m_useParents && !<currentCulture>5__3->get_HasInvariantCultureName()) {
        goto IL_0040;
      }
      goto IL_00ce;
    case 3:
      {
        <>1__state = -1;
        return false;
      }
    IL_0040:
      if (resourceFallbackManager->m_neutralResourcesCulture != nullptr && <currentCulture>5__3->get_Name() == resourceFallbackManager->m_neutralResourcesCulture->get_Name()) {
        <>2__current = CultureInfo::in::get_InvariantCulture();
        <>1__state = 1;
        return true;
      }
      <>2__current = <currentCulture>5__3;
      <>1__state = 2;
      return true;

    IL_00ce:
      if (!resourceFallbackManager->m_useParents || resourceFallbackManager->m_startingCulture->get_HasInvariantCultureName()) {
        return false;
      }
      if (<reachedNeutralResourcesCulture>5__2) {
        return false;
      }
      <>2__current = CultureInfo::in::get_InvariantCulture();
      <>1__state = 3;
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
  } while (m_useParents && !currentCulture->get_HasInvariantCultureName())
  if (m_useParents && !m_startingCulture->get_HasInvariantCultureName() && !reachedNeutralResourcesCulture) {
  }
}

} // namespace System::Private::CoreLib::System::Resources::ResourceFallbackManagerNamespace
