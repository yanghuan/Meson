#include "ManifestBuilder-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ManifestBuilderNamespace {
IList<String> ManifestBuilder___::get_Errors() {
  return nullptr;
};
void ManifestBuilder___::AddOpcode(String name, Int32 value) {
  return void();
};
void ManifestBuilder___::AddTask(String name, Int32 value) {
  return void();
};
void ManifestBuilder___::AddKeyword(String name, UInt64 value) {
  return void();
};
void ManifestBuilder___::AddChannel(String name, Int32 value, EventChannelAttribute channelAttribute) {
  return void();
};
EventChannelType ManifestBuilder___::EventChannelToChannelType(EventChannel channel) {
  return EventChannelType();
};
EventChannelAttribute ManifestBuilder___::GetDefaultChannelAttribute(EventChannel channel) {
  return nullptr;
};
Array<UInt64> ManifestBuilder___::GetChannelData() {
  return Array<UInt64>();
};
void ManifestBuilder___::StartEvent(String eventName, EventAttribute eventAttribute) {
  return void();
};
void ManifestBuilder___::AddEventParameter(Type type, String name) {
  return void();
};
void ManifestBuilder___::EndEvent() {
  return void();
};
UInt64 ManifestBuilder___::GetChannelKeyword(EventChannel channel, UInt64 channelKeyword) {
  return UInt64();
};
Array<Byte> ManifestBuilder___::CreateManifest() {
  return Array<Byte>();
};
void ManifestBuilder___::ManifestError(String msg, Boolean runtimeCritical) {
  return void();
};
String ManifestBuilder___::CreateManifestString() {
  return nullptr;
};
void ManifestBuilder___::WriteNameAndMessageAttribs(StringBuilder stringBuilder, String elementName, String name) {
  return void();
};
void ManifestBuilder___::WriteMessageAttrib(StringBuilder stringBuilder, String elementName, String name, String value) {
  return void();
};
String ManifestBuilder___::GetLocalizedMessage(String key, CultureInfo ci, Boolean etwFormat) {
  return nullptr;
};
List<CultureInfo> ManifestBuilder___::GetSupportedCultures(ResourceManager resources) {
  return nullptr;
};
String ManifestBuilder___::GetLevelName(EventLevel level) {
  return nullptr;
};
String ManifestBuilder___::GetChannelName(EventChannel channel, String eventName, String eventMessage) {
  return nullptr;
};
String ManifestBuilder___::GetTaskName(EventTask task, String eventName) {
  return nullptr;
};
String ManifestBuilder___::GetOpcodeName(EventOpcode opcode, String eventName) {
  return nullptr;
};
String ManifestBuilder___::GetKeywords(UInt64 keywords, String eventName) {
  return nullptr;
};
String ManifestBuilder___::GetTypeName(Type type) {
  return nullptr;
};
void ManifestBuilder___::UpdateStringBuilder(StringBuilder& stringBuilder, String eventMessage, Int32 startIndex, Int32 count) {
  return void();
};
String ManifestBuilder___::TranslateToManifestConvention(String eventMessage, String evtName) {
  return nullptr;
};
Int32 ManifestBuilder___::TranslateIndexToManifestConvention(Int32 idx, String evtName) {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ManifestBuilderNamespace
