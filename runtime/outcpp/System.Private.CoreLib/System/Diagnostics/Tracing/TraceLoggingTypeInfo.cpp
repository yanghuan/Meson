#include "TraceLoggingTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingTypeInfoNamespace {
String TraceLoggingTypeInfo___::get_Name() {
  return nullptr;
};

EventLevel TraceLoggingTypeInfo___::get_Level() {
  return EventLevel::Verbose;
};

EventOpcode TraceLoggingTypeInfo___::get_Opcode() {
  return EventOpcode::Receive;
};

EventKeywords TraceLoggingTypeInfo___::get_Keywords() {
  return EventKeywords::EventLogClassic;
};

EventTags TraceLoggingTypeInfo___::get_Tags() {
  return EventTags::None;
};

Type TraceLoggingTypeInfo___::get_DataType() {
  return nullptr;
};

Func<Object, PropertyValue> TraceLoggingTypeInfo___::get_PropertyValueFactory() {
  return nullptr;
};

void TraceLoggingTypeInfo___::Ctor(Type dataType) {
};

void TraceLoggingTypeInfo___::Ctor(Type dataType, String name, EventLevel level, EventOpcode opcode, EventKeywords keywords, EventTags tags) {
};

Object TraceLoggingTypeInfo___::GetData(Object value) {
  return nullptr;
};

TraceLoggingTypeInfo TraceLoggingTypeInfo___::GetInstance(Type type, List<Type> recursionCheck) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingTypeInfoNamespace
