#include "CleanupWorkListElement-dep.h"

#include <System.Private.CoreLib/System/StubHelpers/CleanupWorkListElement-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::CleanupWorkListElementNamespace {
void CleanupWorkListElement___::Destroy() {
  DestroyCore();
  for (CleanupWorkListElement next = m_Next; next != nullptr; next = next->m_Next) {
    next->DestroyCore();
  }
}

void CleanupWorkListElement___::AddToCleanupList(CleanupWorkListElement& list, CleanupWorkListElement newElement) {
  if (list == nullptr) {
    list = newElement;
    return;
  }
  newElement->m_Next = list;
  list = newElement;
}

void CleanupWorkListElement___::ctor() {
}

} // namespace System::Private::CoreLib::System::StubHelpers::CleanupWorkListElementNamespace
