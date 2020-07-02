#include "EventSource-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventSource-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceNamespace {
IntPtr EventSource___::EventData::get_DataPointer() {
  return IntPtr();
};
void EventSource___::EventData::set_DataPointer(IntPtr value) {
  return void();
};
Int32 EventSource___::EventData::get_Size() {
  return Int32();
};
void EventSource___::EventData::set_Size(Int32 value) {
  return void();
};
void EventSource___::EventData::set_Reserved(Int32 value) {
  return void();
};
void EventSource___::EventData::SetMetadata(Byte* pointer, Int32 size, Int32 reserved) {
  return void();
};
void EventSource___::Sha1ForNonSecretPurposes::Start() {
  return void();
};
void EventSource___::Sha1ForNonSecretPurposes::Append(Byte input) {
  return void();
};
void EventSource___::Sha1ForNonSecretPurposes::Append(Array<Byte> input) {
  return void();
};
void EventSource___::Sha1ForNonSecretPurposes::Finish(Array<Byte> output) {
  return void();
};
void EventSource___::Sha1ForNonSecretPurposes::Drain() {
  return void();
};
void EventSource___::OverideEventProvider___::OnControllerCommand(ControllerCommand command, IDictionary<String, String> arguments, Int32 perEventSourceSessionId, Int32 etwSessionId) {
  return void();
};
String EventSource___::get_Name() {
  return nullptr;
};
Guid EventSource___::get_Guid() {
  return Guid();
};
EventSourceSettings EventSource___::get_Settings() {
  return EventSourceSettings();
};
Exception EventSource___::get_ConstructionException() {
  return nullptr;
};
Guid EventSource___::get_CurrentThreadActivityId() {
  return Guid();
};
Boolean EventSource___::get_IsDisposed() {
  return Boolean();
};
Boolean EventSource___::get_ThrowOnEventWriteErrors() {
  return Boolean();
};
Boolean EventSource___::get_SelfDescribingEvents() {
  return Boolean();
};
Boolean EventSource___::IsEnabled() {
  return Boolean();
};
Boolean EventSource___::IsEnabled(EventLevel level, EventKeywords keywords) {
  return Boolean();
};
Boolean EventSource___::IsEnabled(EventLevel level, EventKeywords keywords, EventChannel channel) {
  return Boolean();
};
Guid EventSource___::GetGuid(Type eventSourceType) {
  return Guid();
};
String EventSource___::GetName(Type eventSourceType) {
  return nullptr;
};
String EventSource___::GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest) {
  return nullptr;
};
String EventSource___::GenerateManifest(Type eventSourceType, String assemblyPathToIncludeInManifest, EventManifestOptions flags) {
  return nullptr;
};
IEnumerable<EventSource> EventSource___::GetSources() {
  return nullptr;
};
void EventSource___::SendCommand(EventSource eventSource, EventCommand command, IDictionary<String, String> commandArguments) {
  return void();
};
String EventSource___::GetTrait(String key) {
  return nullptr;
};
String EventSource___::ToString() {
  return nullptr;
};
void EventSource___::SetCurrentThreadActivityId(Guid activityId) {
  return void();
};
void EventSource___::SetCurrentThreadActivityId(Guid activityId, Guid& oldActivityThatWillContinue) {
  return void();
};
void EventSource___::DefineEventPipeEvents() {
  return void();
};
void EventSource___::GetMetadata(Guid& eventSourceGuid, String& eventSourceName, Array<EventMetadata>& eventData, Array<Byte>& manifestBytes) {
  return void();
};
void EventSource___::OnEventCommand(EventCommandEventArgs command) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int32 arg1) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, Int32 arg2, Int32 arg3) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int64 arg1) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Int64 arg2, Int64 arg3) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, String arg1) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, String arg1, String arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, String arg1, String arg2, String arg3) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, String arg1, Int32 arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, String arg1, Int32 arg2, Int32 arg3) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, String arg1, Int64 arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, String arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int32 arg1, String arg2) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Array<Byte> arg1) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Int64 arg1, Array<Byte> arg2) {
  return void();
};
void EventSource___::WriteEventCore(Int32 eventId, Int32 eventDataCount, EventData* data) {
  return void();
};
void EventSource___::WriteEventWithRelatedActivityIdCore(Int32 eventId, Guid* relatedActivityId, Int32 eventDataCount, EventData* data) {
  return void();
};
void EventSource___::WriteEvent(Int32 eventId, Array<Object> args) {
  return void();
};
void EventSource___::WriteEventWithRelatedActivityId(Int32 eventId, Guid relatedActivityId, Array<Object> args) {
  return void();
};
void EventSource___::Dispose() {
  return void();
};
void EventSource___::Dispose(Boolean disposing) {
  return void();
};
void EventSource___::Finalize() {
  return void();
};
void EventSource___::WriteEventRaw(String eventName, EventDescriptor& eventDescriptor, IntPtr eventHandle, Guid* activityID, Guid* relatedActivityID, Int32 dataCount, IntPtr data) {
  return void();
};
void EventSource___::Initialize(Guid eventSourceGuid, String eventSourceName, Array<String> traits) {
  return void();
};
String EventSource___::GetName(Type eventSourceType, EventManifestOptions flags) {
  return nullptr;
};
Guid EventSource___::GenerateGuidFromName(String name) {
  return Guid();
};
Object EventSource___::DecodeObject(Int32 eventId, Int32 parameterId, EventData*& data) {
  return nullptr;
};
EventDispatcher EventSource___::GetDispatcher(EventListener listener) {
  return nullptr;
};
void EventSource___::WriteEventVarargs(Int32 eventId, Guid* childActivityID, Array<Object> args) {
  return void();
};
Array<Object> EventSource___::SerializeEventArgs(Int32 eventId, Array<Object> args) {
  return Array<Object>();
};
void EventSource___::LogEventArgsMismatches(Array<ParameterInfo> infos, Array<Object> args) {
  return void();
};
void EventSource___::WriteToAllListeners(Int32 eventId, Guid* activityID, Guid* childActivityID, Int32 eventDataCount, EventData* data) {
  return void();
};
void EventSource___::WriteToAllListeners(Int32 eventId, UInt32* osThreadId, DateTime* timeStamp, Guid* activityID, Guid* childActivityID, Array<Object> args) {
  return void();
};
void EventSource___::DispatchToAllListeners(Int32 eventId, Guid* childActivityID, EventWrittenEventArgs eventCallbackArgs) {
  return void();
};
void EventSource___::WriteEventString(EventLevel level, Int64 keywords, String msgString) {
  return void();
};
void EventSource___::WriteStringToAllListeners(String eventName, String msg) {
  return void();
};
Boolean EventSource___::IsEnabledByDefault(Int32 eventNum, Boolean enable, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword) {
  return Boolean();
};
Boolean EventSource___::IsEnabledCommon(Boolean enabled, EventLevel currentLevel, EventKeywords currentMatchAnyKeyword, EventLevel eventLevel, EventKeywords eventKeywords, EventChannel eventChannel) {
  return Boolean();
};
void EventSource___::ThrowEventSourceException(String eventName, Exception innerEx) {
  return void();
};
void EventSource___::ValidateEventOpcodeForTransfer(EventMetadata& eventData, String eventName) {
  return void();
};
EventOpcode EventSource___::GetOpcodeWithDefault(EventOpcode opcode, String eventName) {
  return EventOpcode();
};
Int32 EventSource___::GetParameterCount(EventMetadata eventData) {
  return Int32();
};
Type EventSource___::GetDataType(EventMetadata eventData, Int32 parameterId) {
  return nullptr;
};
void EventSource___::SendCommand(EventListener listener, EventProviderType eventProviderType, Int32 perEventSourceSessionId, Int32 etwSessionId, EventCommand command, Boolean enable, EventLevel level, EventKeywords matchAnyKeyword, IDictionary<String, String> commandArguments) {
  return void();
};
void EventSource___::DoCommand(EventCommandEventArgs commandArgs) {
  return void();
};
Boolean EventSource___::EnableEventForDispatcher(EventDispatcher dispatcher, EventProviderType eventProviderType, Int32 eventId, Boolean value) {
  return Boolean();
};
Boolean EventSource___::AnyEventEnabled() {
  return Boolean();
};
void EventSource___::EnsureDescriptorsInitialized() {
  return void();
};
Boolean EventSource___::SendManifest(Array<Byte> rawManifest) {
  return Boolean();
};
Attribute EventSource___::GetCustomAttributeHelper(MemberInfo member, Type attributeType, EventManifestOptions flags) {
  return nullptr;
};
Boolean EventSource___::AttributeTypeNamesMatch(Type attributeType, Type reflectedAttributeType) {
  return Boolean();
};
Type EventSource___::GetEventSourceBaseType(Type eventSourceType, Boolean allowEventSourceOverride, Boolean reflectionOnly) {
  return nullptr;
};
Array<Byte> EventSource___::CreateManifestAndDescriptors(Type eventSourceType, String eventSourceDllName, EventSource source, EventManifestOptions flags) {
  return Array<Byte>();
};
Boolean EventSource___::RemoveFirstArgIfRelatedActivityId(Array<ParameterInfo>& args) {
  return Boolean();
};
void EventSource___::AddProviderEnumKind(ManifestBuilder manifest, FieldInfo staticField, String providerEnumKind) {
  return void();
};
void EventSource___::AddEventDescriptor(Array<EventMetadata>& eventData, String eventName, EventAttribute eventAttribute, Array<ParameterInfo> eventParameters, Boolean hasRelatedActivityID) {
  return void();
};
void EventSource___::TrimEventDescriptors(Array<EventMetadata>& eventData) {
  return void();
};
void EventSource___::AddListener(EventListener listener) {
  return void();
};
void EventSource___::DebugCheckEvent(Dictionary<String, String>& eventsByName, Array<EventMetadata> eventData, MethodInfo method, EventAttribute eventAttribute, ManifestBuilder manifest, EventManifestOptions options) {
  return void();
};
Int32 EventSource___::GetHelperCallFirstArg(MethodInfo method) {
  return Int32();
};
void EventSource___::ReportOutOfBandMessage(String msg, Boolean flush) {
  return void();
};
EventSourceSettings EventSource___::ValidateSettings(EventSourceSettings settings) {
  return EventSourceSettings();
};
void EventSource___::Write(String eventName) {
  return void();
};
void EventSource___::Write(String eventName, EventSourceOptions options) {
  return void();
};
void EventSource___::WriteMultiMerge(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values) {
  return void();
};
void EventSource___::WriteMultiMergeInner(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, Array<Object> values) {
  return void();
};
void EventSource___::WriteMultiMerge(String eventName, EventSourceOptions& options, TraceLoggingEventTypes eventTypes, Guid* activityID, Guid* childActivityID, EventData* data) {
  return void();
};
void EventSource___::WriteImpl(String eventName, EventSourceOptions& options, Object data, Guid* pActivityId, Guid* pRelatedActivityId, TraceLoggingEventTypes eventTypes) {
  return void();
};
void EventSource___::WriteToAllListeners(String eventName, EventDescriptor& eventDescriptor, EventTags tags, Guid* pActivityId, Guid* pChildActivityId, EventPayload payload) {
  return void();
};
void EventSource___::WriteCleanup(GCHandle* pPins, Int32 cPins) {
  return void();
};
void EventSource___::InitializeProviderMetadata() {
  return void();
};
Int32 EventSource___::AddValueToMetaData(List<Byte> metaData, String value) {
  return Int32();
};
Int32 EventSource___::HexDigit(Char c) {
  return Int32();
};
NameInfo EventSource___::UpdateDescriptor(String name, TraceLoggingEventTypes eventInfo, EventSourceOptions& options, EventDescriptor& descriptor) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventSourceNamespace
