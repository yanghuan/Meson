#include "NoOpEventProvider-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NoOpEventProviderNamespace {
UInt32 NoOpEventProvider___::EventRegisterOfIEventProvider(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback, void* callbackContext, Int64& registrationHandle) {
  return 0u;
}

UInt32 NoOpEventProvider___::EventUnregisterOfIEventProvider(Int64 registrationHandle) {
  return 0u;
}

EventProvider::in::WriteEventErrorCode NoOpEventProvider___::EventWriteTransferOfIEventProvider(Int64 registrationHandle, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityId, Guid* relatedActivityId, Int32 userDataCount, EventProvider::in::EventData* userData) {
  return EventProvider::in::WriteEventErrorCode::NoError;
}

Int32 NoOpEventProvider___::EventActivityIdControlOfIEventProvider(Interop::Advapi32::ActivityControl ControlCode, Guid& ActivityId) {
  return 0;
}

IntPtr NoOpEventProvider___::DefineEventHandleOfIEventProvider(UInt32 eventID, String eventName, Int64 keywords, UInt32 eventVersion, UInt32 level, Byte* pMetadata, UInt32 metadataLength) {
  return IntPtr::Zero;
}

void NoOpEventProvider___::ctor() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::NoOpEventProviderNamespace
