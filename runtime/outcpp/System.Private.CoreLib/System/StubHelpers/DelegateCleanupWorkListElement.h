#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace DelegateCleanupWorkListElementNamespace {
CLASS(DelegateCleanupWorkListElement) {
  protected: void DestroyCore();
  private: Delegate m_del;
};
} // namespace DelegateCleanupWorkListElementNamespace
using DelegateCleanupWorkListElement = DelegateCleanupWorkListElementNamespace::DelegateCleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
