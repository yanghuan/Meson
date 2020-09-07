#include "EtwEventProvider-dep.h"

#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EtwEventProviderNamespace {
UInt32 EtwEventProvider___::EventRegisterOfIEventProvider(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback, void* callbackContext, Int64& registrationHandle) {
  Guid providerId = eventSource->get_Guid();
  return Interop::Advapi32::EventRegister(providerId, enableCallback, callbackContext, registrationHandle);
}

UInt32 EtwEventProvider___::EventUnregisterOfIEventProvider(Int64 registrationHandle) {
  return Interop::Advapi32::EventUnregister(registrationHandle);
}

EventProvider::in::WriteEventErrorCode EtwEventProvider___::EventWriteTransferOfIEventProvider(Int64 registrationHandle, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, EventProvider::in::EventData* userData) {
  switch (Interop::Advapi32::EventWriteTransfer(registrationHandle, eventDescriptor, activityId, relatedActivityId, userDataCount, userData).get()) {
    case 234:
    case 534:
      return EventProvider::in::WriteEventErrorCode::EventTooBig;
    case 8:
      return EventProvider::in::WriteEventErrorCode::NoFreeBuffers;
    default:
      return EventProvider::in::WriteEventErrorCode::NoError;
  }
}

Int32 EtwEventProvider___::EventActivityIdControlOfIEventProvider(Interop::Advapi32::ActivityControl ControlCode, Guid& ActivityId) {
  return Interop::Advapi32::EventActivityIdControl(ControlCode, ActivityId);
}

IntPtr EtwEventProvider___::DefineEventHandleOfIEventProvider(UInt32 eventID, String eventName, Int64 keywords, UInt32 eventVersion, UInt32 level, Byte* pMetadata, UInt32 metadataLength) {
  rt::throw_exception<NotSupportedException>();
}

void EtwEventProvider___::ctor() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EtwEventProviderNamespace
