#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::StubHelpers {
namespace CleanupWorkListElementNamespace {
CLASS(CleanupWorkListElement) : public object {
  protected: void DestroyCore();
  public: void Destroy();
  public: static void AddToCleanupList(CleanupWorkListElement& list, CleanupWorkListElement newElement);
  public: void ctor();
  private: CleanupWorkListElement m_Next;
};
} // namespace CleanupWorkListElementNamespace
using CleanupWorkListElement = CleanupWorkListElementNamespace::CleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
