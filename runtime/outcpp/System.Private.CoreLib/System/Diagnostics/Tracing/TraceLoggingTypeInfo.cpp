#include "TraceLoggingTypeInfo-dep.h"

#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/TraceLoggingTypeInfo-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingTypeInfoNamespace {
using namespace System::Collections::Generic;

String TraceLoggingTypeInfo___::get_Name() {
  return name;
}

EventLevel TraceLoggingTypeInfo___::get_Level() {
  return level;
}

EventOpcode TraceLoggingTypeInfo___::get_Opcode() {
  return opcode;
}

EventKeywords TraceLoggingTypeInfo___::get_Keywords() {
  return keywords;
}

EventTags TraceLoggingTypeInfo___::get_Tags() {
  return tags;
}

Type TraceLoggingTypeInfo___::get_DataType() {
  return dataType;
}

Func<Object, PropertyValue> TraceLoggingTypeInfo___::get_PropertyValueFactory() {
  return propertyValueFactory;
}

void TraceLoggingTypeInfo___::ctor(Type dataType) {
  level = (EventLevel)(-1);
  opcode = (EventOpcode)(-1);
}

void TraceLoggingTypeInfo___::ctor(Type dataType, String name, EventLevel level, EventOpcode opcode, EventKeywords keywords, EventTags tags) {
  this->level = (EventLevel)(-1);
  this->opcode = (EventOpcode)(-1);
}

Object TraceLoggingTypeInfo___::GetData(Object value) {
  return value;
}

TraceLoggingTypeInfo TraceLoggingTypeInfo___::GetInstance(Type type, List<Type> recursionCheck) {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::TraceLoggingTypeInfoNamespace
