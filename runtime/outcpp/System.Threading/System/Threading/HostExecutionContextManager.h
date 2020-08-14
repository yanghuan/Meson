#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(AsyncLocal, T)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Threading::System::Threading {
FORWARD(HostExecutionContext)
namespace HostExecutionContextManagerNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(HostExecutionContextManager) : public Object::in {
  private: CLASS(HostExecutionContextSwitcher) : public Object::in {
    public: void ctor(HostExecutionContext currentContext);
    public: HostExecutionContext _currentContext;
    public: AsyncLocal<Boolean> _asyncLocal;
  };
  public: HostExecutionContext Capture();
  public: Object SetHostExecutionContext(HostExecutionContext hostExecutionContext);
  public: void Revert(Object previousState);
  public: void ctor();
  private: static HostExecutionContext t_currentContext;
};
} // namespace HostExecutionContextManagerNamespace
using HostExecutionContextManager = HostExecutionContextManagerNamespace::HostExecutionContextManager;
} // namespace System::Threading::System::Threading
