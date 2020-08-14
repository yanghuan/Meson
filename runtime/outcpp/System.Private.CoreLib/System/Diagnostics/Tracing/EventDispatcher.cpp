#include "EventDispatcher-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDispatcherNamespace {
void EventDispatcher___::ctor(EventDispatcher next, Array<Boolean> eventEnabled, EventListener listener) {
  m_Next = next;
  m_EventEnabled = eventEnabled;
  m_Listener = listener;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventDispatcherNamespace
