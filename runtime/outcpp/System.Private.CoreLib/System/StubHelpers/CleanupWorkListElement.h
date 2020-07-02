#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::StubHelpers {
namespace CleanupWorkListElementNamespace {
CLASS(CleanupWorkListElement) {
  protected: void DestroyCore();
  public: void Destroy();
  public: static void AddToCleanupList(CleanupWorkListElement& list, CleanupWorkListElement newElement);
  private: CleanupWorkListElement m_Next;
};
} // namespace CleanupWorkListElementNamespace
using CleanupWorkListElement = CleanupWorkListElementNamespace::CleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
