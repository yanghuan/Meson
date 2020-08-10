#include "TraceLoggingEventTypes-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingEventTypesNamespace {
String TraceLoggingEventTypes___::get_Name() {
  return nullptr;
}

EventTags TraceLoggingEventTypes___::get_Tags() {
  return EventTags::None;
}

void TraceLoggingEventTypes___::ctor(String name, EventTags tags, Array<Type> types) {
}

void TraceLoggingEventTypes___::ctor(String name, EventTags tags, Array<TraceLoggingTypeInfo> typeInfos) {
}

void TraceLoggingEventTypes___::ctor(String name, EventTags tags, Array<ParameterInfo> paramInfos) {
}

void TraceLoggingEventTypes___::ctor(EventTags tags, String defaultName, Array<TraceLoggingTypeInfo> typeInfos) {
}

NameInfo TraceLoggingEventTypes___::GetNameInfo(String name, EventTags tags) {
  return nullptr;
}

Array<TraceLoggingTypeInfo> TraceLoggingEventTypes___::MakeArray(Array<ParameterInfo> paramInfos) {
  return Array<TraceLoggingTypeInfo>();
}

Array<TraceLoggingTypeInfo> TraceLoggingEventTypes___::MakeArray(Array<Type> types) {
  return Array<TraceLoggingTypeInfo>();
}

Array<TraceLoggingTypeInfo> TraceLoggingEventTypes___::MakeArray(Array<TraceLoggingTypeInfo> typeInfos) {
  return Array<TraceLoggingTypeInfo>();
}

Array<String> TraceLoggingEventTypes___::MakeParamNameArray(Array<ParameterInfo> paramInfos) {
  return Array<String>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingEventTypesNamespace
