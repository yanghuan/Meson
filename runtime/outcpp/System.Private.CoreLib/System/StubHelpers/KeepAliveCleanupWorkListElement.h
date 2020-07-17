#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace KeepAliveCleanupWorkListElementNamespace {
CLASS(KeepAliveCleanupWorkListElement) {
  public: void Ctor(Object obj);
  protected: void DestroyCore();
  private: Object m_obj;
};
} // namespace KeepAliveCleanupWorkListElementNamespace
using KeepAliveCleanupWorkListElement = KeepAliveCleanupWorkListElementNamespace::KeepAliveCleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
