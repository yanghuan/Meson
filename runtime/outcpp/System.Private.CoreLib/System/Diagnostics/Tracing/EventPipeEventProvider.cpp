#include "EventPipeEventProvider-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipeInternal-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeEventProviderNamespace {
UInt32 EventPipeEventProvider___::EventRegisterOfIEventProvider(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback, void* callbackContext, Int64& registrationHandle) {
  UInt32 result = 0u;
  m_provHandle = EventPipeInternal::CreateProvider(eventSource->get_Name(), enableCallback);
  if (m_provHandle != IntPtr::Zero) {
    registrationHandle = 1;
  } else {
    result = 1u;
  }
  return result;
}

UInt32 EventPipeEventProvider___::EventUnregisterOfIEventProvider(Int64 registrationHandle) {
  EventPipeInternal::DeleteProvider(m_provHandle);
  return 0u;
}

EventProvider::in::WriteEventErrorCode EventPipeEventProvider___::EventWriteTransferOfIEventProvider(Int64 registrationHandle, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, EventProvider::in::EventData* userData) {
  if (eventHandle != IntPtr::Zero) {
    if (userDataCount == 0) {
      EventPipeInternal::WriteEventData(eventHandle, nullptr, 0u, activityId, relatedActivityId);
      return EventProvider::in::WriteEventErrorCode::NoError;
    }
    if (eventDescriptor.get_Channel() == 11) {
      userData += 3;
      userDataCount -= 3;
    }
    EventPipeInternal::WriteEventData(eventHandle, userData, (UInt32)userDataCount, activityId, relatedActivityId);
  }
  return EventProvider::in::WriteEventErrorCode::NoError;
}

Int32 EventPipeEventProvider___::EventActivityIdControlOfIEventProvider(Interop::Advapi32::ActivityControl ControlCode, Guid& ActivityId) {
  return EventPipeInternal::EventActivityIdControl((UInt32)ControlCode, ActivityId);
}

IntPtr EventPipeEventProvider___::DefineEventHandleOfIEventProvider(UInt32 eventID, String eventName, Int64 keywords, UInt32 eventVersion, UInt32 level, Byte* pMetadata, UInt32 metadataLength) {
  return EventPipeInternal::DefineEvent(m_provHandle, eventID, keywords, eventVersion, level, pMetadata, metadataLength);
}

void EventPipeEventProvider___::ctor() {
  m_provHandle = IntPtr::Zero;
  Object::in::ctor();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipeEventProviderNamespace
