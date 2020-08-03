#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
FORWARD(EventListener)
namespace EventDispatcherNamespace {
CLASS(EventDispatcher) : public Object::in {
  public: void Ctor(EventDispatcher next, Array<Boolean> eventEnabled, EventListener listener);
  public: EventListener m_Listener;
  public: Array<Boolean> m_EventEnabled;
  public: EventDispatcher m_Next;
};
} // namespace EventDispatcherNamespace
using EventDispatcher = EventDispatcherNamespace::EventDispatcher;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
