#include "EventProvider-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventProvider-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventProviderNamespace {
EventLevel EventProvider___::get_Level() {
  return EventLevel();
};
EventKeywords EventProvider___::get_MatchAnyKeyword() {
  return EventKeywords();
};
void EventProvider___::Register(EventSource eventSource) {
  return void();
};
void EventProvider___::Dispose() {
  return void();
};
void EventProvider___::Dispose(Boolean disposing) {
  return void();
};
void EventProvider___::Finalize() {
  return void();
};
void EventProvider___::EtwEnableCallBack(Guid& sourceId, Int32 controlCode, Byte setLevel, Int64 anyKeyword, Int64 allKeyword, Interop::Advapi32::in::EVENT_FILTER_DESCRIPTOR* filterData, void* callbackContext) {
  return void();
};
void EventProvider___::OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 sessionId, Int32 etwSessionId) {
  return void();
};
Int32 EventProvider___::FindNull(Array<Byte> buffer, Int32 idx) {
  return Int32();
};
List<Tuple<EventProvider::in::SessionInfo, Boolean>> EventProvider___::GetSessions() {
  return nullptr;
};
void EventProvider___::GetSessionInfoCallback(Int32 etwSessionId, Int64 matchAllKeywords, List<SessionInfo>& sessionList) {
  return void();
};
void EventProvider___::GetSessionInfo(SessionInfoCallback action, List<SessionInfo>& sessionList) {
  return void();
};
Int32 EventProvider___::IndexOfSessionInList(List<SessionInfo> sessions, Int32 etwSessionId) {
  return Int32();
};
Boolean EventProvider___::GetDataFromController(Int32 etwSessionId, Interop::Advapi32::in::EVENT_FILTER_DESCRIPTOR* filterData, ControllerCommand& command, Array<Byte>& data, Int32& dataStart) {
  return Boolean();
};
Boolean EventProvider___::IsEnabled() {
  return Boolean();
};
Boolean EventProvider___::IsEnabled(Byte level, Int64 keywords) {
  return Boolean();
};
EventProvider::in::WriteEventErrorCode EventProvider___::GetLastWriteEventError() {
  return EventProvider::in::WriteEventErrorCode();
};
void EventProvider___::SetLastError(WriteEventErrorCode error) {
  return void();
};
Object EventProvider___::EncodeObject(Object& data, EventData*& dataDescriptor, Byte*& dataBuffer, UInt32& totalEventSize) {
  return nullptr;
};
Boolean EventProvider___::WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Array<Object> eventPayload) {
  return Boolean();
};
Boolean EventProvider___::WriteEvent(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* childActivityID, Int32 dataCount, IntPtr data) {
  return Boolean();
};
Boolean EventProvider___::WriteEventRaw(EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data) {
  return Boolean();
};
UInt32 EventProvider___::EventRegister(EventSource eventSource, Interop::Advapi32::in::EtwEnableCallback enableCallback) {
  return UInt32();
};
UInt32 EventProvider___::EventUnregister(Int64 registrationHandle) {
  return UInt32();
};
Int32 EventProvider___::SetInformation(Interop::Advapi32::in::EVENT_INFO_CLASS eventInfoClass, IntPtr data, UInt32 dataSize) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventProviderNamespace