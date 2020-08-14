#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Threading::System::Threading {
namespace HostExecutionContextNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(HostExecutionContext) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Object get_State() { return State; }
  public: void set_State(Object value) { State = value; }
  public: void ctor();
  public: void ctor(Object state);
  public: HostExecutionContext CreateCopy();
  public: void Dispose();
  public: void Dispose(Boolean disposing);
  private: Object State;
};
} // namespace HostExecutionContextNamespace
using HostExecutionContext = HostExecutionContextNamespace::HostExecutionContext;
} // namespace System::Threading::System::Threading
