#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::StubHelpers {
namespace CleanupWorkListElementNamespace {
CLASS(CleanupWorkListElement) : public Object::in {
  protected: void DestroyCore();
  public: void Destroy();
  public: static void AddToCleanupList(CleanupWorkListElement& list, CleanupWorkListElement newElement);
  protected: void Ctor();
  private: CleanupWorkListElement m_Next;
};
} // namespace CleanupWorkListElementNamespace
using CleanupWorkListElement = CleanupWorkListElementNamespace::CleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
