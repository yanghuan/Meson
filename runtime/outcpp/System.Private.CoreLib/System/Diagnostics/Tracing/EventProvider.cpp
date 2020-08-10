#include "EventProvider-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventProviderNamespace {
EventProvider___::SessionInfo::SessionInfo(Int32 sessionIdBit_, Int32 etwSessionId_) {
}

EventLevel EventProvider___::get_Level() {
  return EventLevel::Verbose;
}

EventKeywords EventProvider___::get_MatchAnyKeyword() {
  return EventKeywords::EventLogClassic;
}

void EventProvider___::ctor(EventProviderType providerType) {
}

void EventProvider___::Register(EventSource eventSource) {
}

void EventProvider___::Dispose() {
}

void EventProvider___::Dispose(Boolean disposing) {
}

void EventProvider___::Finalize() {
}

void EventProvider___::EtwEnableCallBack(Guid& sourceId, Int32 controlCode, Byte setLevel, Int64 anyKeyword, Int64 allKeyword, Interop::Advapi32::EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext) {
}

void EventProvider___::OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 sessionId, Int32 etwSessionId) {
}

Int32 EventProvider___::FindNull(Array<Byte> buffer, Int32 idx) {
  return Int32();
}

List<Tuple<EventProvider::in::SessionInfo, Boolean>> EventProvider___::GetSessions() {
  return nullptr;
}

void EventProvider___::GetSessionInfoCallback(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList) {
}

void EventProvider___::GetSessionInfo(SessionInfoCallback action, List<SessionInfo>& sessionList) {
}

Int32 EventProvider___::IndexOfSessionInList(List<SessionInfo> sessions, Int32 etwSessionId) {
  return Int32();
}

Boolean EventProvider___::GetDataFromController(Int32 etwSessionId, Interop::Advapi32::EVENT_FILTER_DESCRIPTOR* filterData, ControllerCommand& command, Array<Byte>& data, Int32& dataStart) {
  return Boolean();
}

Boolean EventProvider___::IsEnabled() {
  return Boolean();
}

Boolean EventProvider___::IsEnabled(Byte level, Int64 keywords) {
  return Boolean();
}

EventProvider::in::WriteEventErrorCode EventProvider___::GetLastWriteEventError() {
  return EventProvider::in::WriteEventErrorCode::Other;
}

void EventProvider___::SetLastError(WriteEventErrorCode error) {
}

Object EventProvider___::EncodeObject(Object& data, EventData*& dataDescriptor, Byte*& dataBuffer, UInt32& totalEventSize) {
  return nullptr;
}

Boolean EventProvider___::WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Array<Object> eventPayload) {
  return Boolean();
}

Boolean EventProvider___::WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Int32 dataCount, IntPtr data) {
  return Boolean();
}

Boolean EventProvider___::WriteEventRaw(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data) {
  return Boolean();
}

UInt32 EventProvider___::EventRegister(EventSource eventSource, Interop::Advapi32::EtwEnableCallback enableCallback) {
  return UInt32();
}

void EventProvider___::EventUnregister(Int64 registrationHandle) {
}

Int32 EventProvider___::SetInformation(Interop::Advapi32::EVENT_INFO_CLASS eventInfoClass, IntPtr data, UInt32 dataSize) {
  return Int32();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventProviderNamespace
