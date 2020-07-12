#include "EventPayload-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPayloadNamespace {
ICollection<String> EventPayload___::get_Keys() {
  return nullptr;
};

ICollection<Object> EventPayload___::get_Values() {
  return nullptr;
};

Object EventPayload___::get_Item(String key) {
  return nullptr;
};

void EventPayload___::set_Item(String key, Object value) {
};

Int32 EventPayload___::get_Count() {
  return Int32();
};

Boolean EventPayload___::get_IsReadOnly() {
  return Boolean();
};

void EventPayload___::Add(String key, Object value) {
};

void EventPayload___::Add(KeyValuePair<String, Object> payloadEntry) {
};

void EventPayload___::Clear() {
};

Boolean EventPayload___::Contains(KeyValuePair<String, Object> entry) {
  return Boolean();
};

Boolean EventPayload___::ContainsKey(String key) {
  return Boolean();
};

IEnumerator<KeyValuePair<String, Object>> EventPayload___::GetEnumerator() {
  return nullptr;
};

void EventPayload___::CopyTo(Array<KeyValuePair<String, Object>> payloadEntries, Int32 count) {
};

Boolean EventPayload___::Remove(String key) {
  return Boolean();
};

Boolean EventPayload___::Remove(KeyValuePair<String, Object> entry) {
  return Boolean();
};

Boolean EventPayload___::TryGetValue(String key, Object& value) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPayloadNamespace
